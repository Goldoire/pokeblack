#!/usr/bin/env python3
"""Byte-verify compiled functions against the decompressed ARM9.

For every object file under build/src, this locates each global function
symbol, applies its relocations (resolving address-encoding names like
sub_02085760 / FUN_0200421A / _020A9E94), and compares the resulting bytes
with build/arm9_decompressed.bin at the function's home offset.

The repo mixes two address bases: some names encode the Ghidra file base
(0x02000000 = file offset 0) and some encode real RAM (0x02004000 = file
offset 0). Branch displacements cancel the base, so only the function's own
placement is ambiguous; both candidate offsets are tried and the better one
reported.

Relocation words that reference symbols whose address cannot be derived from
the name (e.g. local .rodata) are masked out of the comparison and counted
separately.

Objects are matched to modules by path: build/src/ov093/*.o verifies against
overlay 93, anything else against the ARM9 (build/reference/manifest.json
defines every module's load address and reference binary).

Usage: python tools/scripts/verify_functions.py [--ref-dir build/reference]
"""
import bisect
import glob
import json
import os
import re
import struct
import sys

GHIDRA_BASE = 0x02000000
RAM_BASE = 0x02004000  # ARM9 load address; overlays use their manifest ram

ADDR_NAME = re.compile(r"^(?:sub|FUN|DAT)_([0-9A-Fa-f]{8})$|^_([0-9A-Fa-f]{8})$")

R_ARM_PC24 = 1
R_ARM_ABS32 = 2
R_ARM_THM_PC22 = 10
R_ARM_CALL = 28
R_ARM_JUMP24 = 29


class Obj:
    def __init__(self, path):
        self.path = path
        d = open(path, "rb").read()
        self.data = d
        assert d[:4] == b"\x7fELF", path
        shoff, = struct.unpack("<I", d[32:36])
        shentsize, shnum, shstrndx = struct.unpack("<3H", d[46:52])
        self.sections = []
        for i in range(shnum):
            f = struct.unpack("<10I", d[shoff + i * shentsize : shoff + i * shentsize + 40])
            self.sections.append(dict(name=f[0], type=f[1], flags=f[2], addr=f[3],
                                      offset=f[4], size=f[5], link=f[6], info=f[7]))
        strt = self.sections[shstrndx]
        def sname(s):
            o = strt["offset"] + s["name"]
            return d[o : d.index(b"\0", o)].decode()
        for s in self.sections:
            s["sname"] = sname(s)
        self.symtab = []
        sym_sec = next(s for s in self.sections if s["type"] == 2)
        symstr = self.sections[sym_sec["link"]]
        count = sym_sec["size"] // 16
        for i in range(count):
            o = sym_sec["offset"] + i * 16
            name_off, value, size, info, other, shndx = struct.unpack("<3I2BH", d[o : o + 16])
            no = symstr["offset"] + name_off
            nm = d[no : d.index(b"\0", no)].decode()
            self.symtab.append(dict(name=nm, value=value, size=size,
                                    bind=info >> 4, typ=info & 0xF, shndx=shndx))
        self.relocs = {}  # target section index -> list of (offset, type, symidx, addend)
        for s in self.sections:
            if s["type"] == 4:  # RELA
                lst = self.relocs.setdefault(s["info"], [])
                for i in range(s["size"] // 12):
                    o = s["offset"] + i * 12
                    off, inf, add = struct.unpack("<IIi", d[o : o + 12])
                    lst.append((off, inf & 0xFF, inf >> 8, add))

    def section_bytes(self, idx):
        s = self.sections[idx]
        return bytearray(self.data[s["offset"] : s["offset"] + s["size"]])


_NAMED = None


def _named():
    """name -> real RAM, for symbols whose name does not encode an address.

    Without this a call to a friendly name (`Heap_Alloc`) cannot be resolved,
    so its relocation word is masked -- and masked bytes are removed from both
    the score and the total, which means the function can report N/N OK with
    that call never compared at all. Reading symbols.txt and the claim table
    closes that hole: the target resolves, the word is checked like any other.
    """
    global _NAMED
    if _NAMED is not None:
        return _NAMED
    # CodeWarrior's runtime helpers: mwcc emits the call to a named symbol, so
    # without these the branch word is masked and goes unchecked. `x / 100`
    # compiling to a call is common enough that this was the largest remaining
    # source of masked bytes. Addresses read off real ROM call sites, and the
    # routine at 0x0209C0A4 is visibly the divide (eor/and #0x80000000 sign
    # handling, rsblt absolute value).
    # 0x0209C0A4 is the signed routine (eor/and #0x80000000 sign handling,
    # rsblt to absolute value). 0x0209C2B0 is the unsigned one: a div-by-zero
    # check falling into a core that uses lo/lsr and never touches the sign
    # bit. These are compiler-generated calls, so they cannot be renamed from
    # C -- the mapping has to be right here.
    _NAMED = {
        "_s32_div_f": 0x0209C0A4,
        "_u32_div_f": 0x0209C2B0,
        "_ll_shl": 0x0209C074,      # 64-bit shift helper; the ribbon bitfields
                                    # in poke_tool.c are the heavy user
    }
    try:
        for line in open("symbols.txt", encoding="utf-8", errors="replace"):
            line = line.split(";")[0].strip()
            if not line:
                continue
            parts = line.split()
            if len(parts) >= 2 and re.fullmatch(r"[0-9A-Fa-f]{8}", parts[0]):
                _NAMED.setdefault(parts[1], int(parts[0], 16))
    except OSError:
        pass
    try:
        for lst in json.load(open("build/reference/functions.json")).values():
            for f in lst:
                _NAMED.setdefault(f["name"], f["ram"])
    except (OSError, ValueError):
        pass
    return _NAMED


def name_addr(nm):
    m = ADDR_NAME.match(nm)
    if m:
        return int(m.group(1) or m.group(2), 16)
    return _named().get(nm)


STT_FUNC = 2

# ram -> "arm"/"thumb", from tools/scripts/triage.py. Interworking calls are
# encoded differently depending on the callee's instruction set, so the
# verifier has to know which mode each target is in to reproduce what the
# linker would emit. Absent the triage file every target is assumed Thumb,
# which is what the vast majority of game code is.
_MODES = None
_MODES_BY_MODULE = None
_EXTENTS = {}       # module -> sorted [(start, end, mode)]
_VENEER = None      # ram -> mode, probed from the reference bytes


_BSS = None


def _bss_of(module):
    global _BSS
    if _BSS is None:
        try:
            _BSS = {m: v.get("bss", 0) or 0
                    for m, v in json.load(open("build/reference/manifest.json")).items()}
        except (OSError, ValueError):
            _BSS = {}
    return _BSS.get(module, 0)


def _exact_func(addr, module=None):
    """Mode of a function that starts exactly at `addr`, else None.

    Deliberately stricter than target_mode: used for deciding whether an ABS32
    word is a function pointer (bit 0 set for Thumb) rather than data. Only an
    exact start is evidence -- data lands inside function extents all the time.
    """
    _load_modes()
    if module:
        m = _MODES_BY_MODULE.get(module, {}).get(addr)
        if m is not None:
            return m
    hit = _MODES.get(addr)
    return hit[0] if hit else None


def _enclosing(module, addr):
    """Mode of the triaged function whose extent contains `addr`, if any.

    Triage sizes are prologue-heuristic *estimates*, so an extent routinely
    runs past the real end of its function and over whatever follows. When a
    Thumb extent has an ARM veneer inside it at or before `addr`, the Thumb
    function demonstrably ended at that veneer and the extent is not evidence
    about `addr` at all -- say nothing rather than claim Thumb. (ov114:
    func_021BBE32 is triaged as 274 Thumb bytes but the ARM veneer at
    0x021BBE94 and the ARM accessors behind it live inside that span.)
    """
    ext = _EXTENTS.get(module)
    if not ext:
        return None
    i = bisect.bisect_right(ext, (addr, float("inf"), "")) - 1
    if i < 0 or not (ext[i][0] <= addr < ext[i][1]):
        return None
    start, _end, mode = ext[i]
    if mode == "thumb":
        vs = _veneer_addrs(module)
        j = bisect.bisect_right(vs, addr) - 1
        if j >= 0 and vs[j] >= start:
            return None
    return mode


def _veneers(module):
    """{ram: "arm"} for every long-branch veneer in `module`'s image."""
    _veneer_mode(-1, module)
    return _VENEER.get(module, {})


_VEN_SORTED = {}


def _veneer_addrs(module):
    if module not in _VEN_SORTED:
        _VEN_SORTED[module] = sorted(_veneers(module))
    return _VEN_SORTED[module]


def _veneer_mode(addr, module="main"):
    """Classify long-branch veneers straight from the reference bytes.

    The linker emits these between functions, so they have no claim-table entry
    and no triage entry -- but overlays call them constantly, and getting their
    instruction set wrong costs one byte in every caller. The two forms are
    unambiguous, so reading them is safer than guessing.

    Overlays need this at least as much as main: triage sizes overreach, so an
    ARM veneer parked after a Thumb function gets swallowed by that function's
    extent and _enclosing() would call it Thumb. ov114 is the worked example --
    0x021B9B4C/0x021B9B58 are `ldr ip,[pc]; bx ip` thunks to OS_InitMutex and
    OS_LockMutex sitting inside triage's 100-byte func_021B9B00. Reading the
    bytes settles it; the extent heuristic must not outrank that.
    """
    global _VENEER
    if _VENEER is None:
        _VENEER = {}
    if module in _VENEER:
        return _VENEER[module].get(addr)
    found = {}
    _VENEER[module] = found
    try:
        manifest = json.load(open("build/reference/manifest.json"))
        data = open(f"build/reference/{module}.bin", "rb").read()
    except (OSError, ValueError):
        return None
    if module not in manifest:
        return None
    base = manifest[module]["ram"]
    for off in range(0, len(data) - 8, 4):
        w = int.from_bytes(data[off:off + 4], "little")
        if w == 0xE51FF004:                             # ldr pc, [pc, #-4]
            found[base + off] = "arm"
        elif data[off:off + 4] == b"\x00\xc0\x9f\xe5" and \
                data[off + 4:off + 8] == b"\x1c\xff\x2f\xe1":
            found[base + off] = "arm"                   # ldr ip,[pc]; bx ip
    return found.get(addr)


def _load_modes():
    global _MODES, _MODES_BY_MODULE
    if _MODES is not None:
        return
    _MODES, _MODES_BY_MODULE = {}, {}
    try:
        tri = json.load(open("build/reference/triage.json"))
    except (OSError, ValueError):
        return
    for mod, lst in tri.items():
        per = _MODES_BY_MODULE.setdefault(mod, {})
        _EXTENTS[mod] = ext = []
        for f in lst:
            if f.get("kind") != "data" and f.get("size"):
                ext.append((f["ram"], f["ram"] + f["size"], f["mode"]))
            # kind == "data" means triage decided this entry is not a function
            # at all, so its recorded mode is a decode artifact, not evidence.
            # 0x02027060 is a live example: triage calls it 652 bytes of ARM
            # data, the bytes are Thumb, and every call site in the ROM is a
            # Thumb BL. Leaving such entries out of the map falls back to the
            # documented Thumb default instead of forcing a bogus BLX.
            if f.get("kind") == "data":
                continue
            per[f["ram"]] = f["mode"]
            # Overlays alias in RAM, so the same address can carry two modes.
            # Prefer the smaller entry: a genuine function start beats a
            # multi-kilobyte blob that triage merged or misidentified.
            prev = _MODES.get(f["ram"])
            if prev is None or f.get("size", 1 << 30) < prev[1]:
                _MODES[f["ram"]] = (f["mode"], f.get("size", 1 << 30))
    for mod in _EXTENTS:
        _EXTENTS[mod].sort()


def target_mode(addr, module=None, own_range=None):
    """Instruction set of the function at `addr`.

    Overlays alias each other in RAM (ov009 and ov010 both load at 0x02155160),
    so a single global address -> mode map lets one overlay's ARM function
    shadow another's Thumb function at the same address, and the interworking
    call is then encoded wrongly. Resolution order:

      1. the mode recorded for `module` itself;
      2. nothing, if `addr` lies inside `module`'s own image -- an address in
         the module's image can only be that module's code, so another
         overlay's entry for it is an alias and must not be consulted. Falling
         through returns None, i.e. the documented Thumb default, which is what
         triage-undetected accessors are;
      3. the global map, for genuine cross-module targets (main, and callees
         in a permanently resident region).
    """
    _load_modes()
    if _MODES is None:
        return None
    if module:
        m = _MODES_BY_MODULE.get(module, {}).get(addr)
        if m is not None:
            return m
        # Read the bytes before trusting a triaged extent: a veneer that a
        # neighbouring function's overreaching size swallowed is still a veneer.
        m = _veneer_mode(addr, module)
        if m is not None:
            return m
        m = _enclosing(module, addr)
        if m is not None:
            return m
        if own_range and own_range[0] <= addr < own_range[1]:
            return None
    hit = _MODES.get(addr)
    if hit is not None:
        return hit[0]
    # A call can land partway into a known function: a secondary entry point,
    # or a start the claim table merged into its neighbour. The instruction set
    # is the enclosing function's, not the Thumb default.
    m = _enclosing("main", addr)
    if m is not None:
        return m
    return _veneer_mode(addr)


def verify_function(obj, sym, ref, base_fix, region_ram=RAM_BASE, module=None):
    """Returns (score, total, masked, offset, diffs) for one base convention.

    base_fix is added to every name-derived address to translate the repo's
    naming into real RAM; the function's file offset is ram - region_ram.
    """
    sec_idx = sym["shndx"]
    sec = obj.sections[sec_idx]
    fstart, fsize = sym["value"], sym["size"]
    code = obj.section_bytes(sec_idx)[fstart : fstart + fsize]
    home_ram = name_addr(sym["name"])
    if home_ram is None:
        return None
    home_ram += base_fix
    off = home_ram - region_ram
    if off < 0 or off + fsize > len(ref):
        return None
    # A module owns its BSS as well as its image. Without the bss extent a
    # .bss data symbol falls through to the global map, hits some other
    # overlay's function at the same RAM address, and gets stamped with the
    # Thumb bit as if it were a function pointer.
    own_range = (region_ram, region_ram + len(ref) + _bss_of(module))

    def tmode(a):
        return target_mode(a, module, own_range)

    masked = set()
    for roff, rtype, rsym, radd in obj.relocs.get(sec_idx, []):
        if not (fstart <= roff < fstart + fsize):
            continue
        target = obj.symtab[rsym]
        t_addr = name_addr(target["name"])
        if t_addr is not None:
            t_addr += base_fix
        i = roff - fstart
        P = home_ram + i
        word, = struct.unpack("<I", code[i : i + 4]) if rtype != R_ARM_THM_PC22 else (0,)
        if rtype in (R_ARM_PC24, R_ARM_CALL, R_ARM_JUMP24):
            if t_addr is None:
                masked.update(range(i, i + 4))
                continue
            if rtype != R_ARM_JUMP24 and tmode(t_addr) == "thumb":
                # ARM -> Thumb call: the linker rewrites BL as BLX(1), whose
                # cond field is 0xFA|H and whose immediate carries bit 1 of the
                # displacement in the H bit.
                x = t_addr + radd - P
                word = 0xFA000000 | ((x & 2) << 23) | ((x >> 2) & 0xFFFFFF)
            else:
                x = (t_addr + radd - P) >> 2
                word = (word & 0xFF000000) | (x & 0xFFFFFF)
            code[i : i + 4] = struct.pack("<I", word)
        elif rtype == R_ARM_ABS32:
            if t_addr is None:
                masked.update(range(i, i + 4))
                continue
            # A Thumb function's address has bit 0 set when taken as a pointer
            # (callbacks, jump tables); the ROM stores it that way.
            # An extern declared only as a prototype lands in the symbol table
            # as STT_NOTYPE/SHN_UNDEF, so its type says nothing -- for those,
            # a triage entry at the target address is the evidence that it is
            # a function, and every callback passed across files looks like
            # this.
            #
            # The evidence must be an EXACT function start, never an enclosing
            # extent. mwcc emits extern data as STT_NOTYPE/SHN_UNDEF too, and a
            # data address frequently lands inside some function's extent -- so
            # accepting an enclosing match ORs bit 0 into correct data literals
            # and breaks every file using the `_<realRAM>` data convention.
            # _020AA194 is a live example.
            # WORKER_GUIDE spells data `_<realRAM>` and code `sub_<realRAM>`,
            # so the name itself settles it: a `_`-spelled target is data and
            # never takes the Thumb bit, whatever any heuristic infers. ov093's
            # dispatch tables are the case that needs this -- they hold odd
            # function pointers, which is exactly what makes a byte heuristic
            # call the region Thumb code.
            val = t_addr + radd
            is_data_name = re.fullmatch(r"_[0-9A-Fa-f]{8}", target["name"])
            is_func = not is_data_name and (
                target["typ"] == STT_FUNC or target["shndx"] == 0)
            if is_func:
                # The name already settled code-vs-data, so the only open
                # question is the instruction set. Exact row, then enclosing
                # function, then the documented Thumb default -- a tail call
                # to a Thumb function the claim table never listed is common
                # (0x02013158 and 0x0202E7DC are live examples: reached only
                # by `ldr r3,=fn|1; bx r3`, so callsite mining never sees
                # them either).
                m = _exact_func(t_addr, module) or _enclosing(module, t_addr) \
                    or _enclosing("main", t_addr) or "thumb"
                if m == "thumb":
                    val |= 1
            code[i : i + 4] = struct.pack("<I", val & 0xFFFFFFFF)
        elif rtype == R_ARM_THM_PC22:
            if t_addr is None:
                masked.update(range(i, i + 4))
                continue
            if tmode(t_addr) == "arm":
                # Thumb -> ARM call: linker rewrites BL as BLX(1). The base PC
                # is word-aligned and the low bit of the halfword is always 0.
                x = t_addr + radd + 4 - ((P + 4) & ~3)
                hi = 0xF000 | ((x >> 12) & 0x7FF)
                lo = 0xE800 | ((x >> 1) & 0x7FE)
            else:
                x = t_addr + radd - P
                hi = 0xF000 | ((x >> 12) & 0x7FF)
                lo = 0xF800 | ((x >> 1) & 0x7FF)
            code[i : i + 2] = struct.pack("<H", hi)
            code[i + 2 : i + 4] = struct.pack("<H", lo)
        else:
            masked.update(range(i, i + 4))
    orig = ref[off : off + fsize]
    diffs = [i for i in range(fsize) if i not in masked and code[i] != orig[i]]
    total = fsize - len(masked)
    return (total - len(diffs), total, len(masked), off, diffs[:4])


MODULE_RE = re.compile(r"[\\/](ov\d{3})[\\/]")


def main():
    ref_dir = "build/reference"
    if "--ref-dir" in sys.argv:
        ref_dir = sys.argv[sys.argv.index("--ref-dir") + 1]
    manifest = json.load(open(os.path.join(ref_dir, "manifest.json")))
    refs = {}

    def get_ref(module):
        if module not in refs:
            refs[module] = open(os.path.join(ref_dir, module + ".bin"), "rb").read()
        return refs[module]

    # Optional path filters: any remaining bare argument is a substring that an
    # object's path must contain. `verify_functions.py ov021` checks only that
    # overlay's objects; with no filter every object under build/src is checked.
    filters = [a for i, a in enumerate(sys.argv[1:], 1)
               if not a.startswith("--") and sys.argv[i - 1] != "--ref-dir"]

    rows = []
    for path in sorted(glob.glob("build/src/**/*.o", recursive=True)):
        norm = path.replace("\\", "/")
        if filters and not any(f.replace("\\", "/") in norm for f in filters):
            continue
        m = MODULE_RE.search(path)
        module = m.group(1) if m and (m.group(1) in manifest) else "main"
        region_ram = manifest[module]["ram"]
        ref = get_ref(module)
        try:
            obj = Obj(path)
        except Exception as e:
            print(f"!! {path}: {e}")
            continue
        for sym in obj.symtab:
            if sym["typ"] != 2 or sym["size"] == 0:  # STT_FUNC
                continue
            best = None
            for fix, tag in ((0x4000, "ghidra"), (0, "ram")):
                r = verify_function(obj, sym, ref, fix, region_ram, module)
                if r and (best is None or r[0] > best[0][0]):
                    best = (r, tag)
            if best is None:
                rows.append((sym["name"], path, None))
            else:
                rows.append((sym["name"], path, best))
    full, partial, nohome = 0, 0, 0
    print(f"{'function':44s} {'file offset':>10s} {'match':>12s}  base  notes")
    for name, path, best in rows:
        if best is None:
            nohome += 1
            print(f"{name:44s} {'-':>10s} {'no address':>12s}")
            continue
        (score, total, masked, off, diffs), tag = best
        pct = 100.0 * score / total if total else 0.0
        note = f"masked {masked}B" if masked else ""
        if score == total:
            full += 1
            status = f"{total}/{total} OK"
        else:
            partial += 1
            status = f"{score}/{total} {pct:.0f}%"
            note += f" first diff +{diffs[0]:#x}" if diffs else ""
        print(f"{name:44s} {off:>#10x} {status:>12s}  {tag:6s}{note}")
    print(f"\n{full} matching, {partial} not matching, {nohome} without a derivable address")
    return 0 if partial == 0 and nohome == 0 else 1


if __name__ == "__main__":
    sys.exit(main())
