#!/usr/bin/env python3
"""Disassemble a range of the ROM and re-emit it as mwasmarm-assemblable .s.

  python tools/scripts/mkasm.py ov114 0x021c86b8 0x021ca734
  python tools/scripts/mkasm.py ov114 --all
  python tools/scripts/mkasm.py ov009 0x02160000 0x02170000 --chunk 24

About 565 KB of this ROM is Nintendo DWC plus the GameSpy SDK (ov009, ov016,
ov114).  It is vendored middleware, there is no source for it in-tree, and a
previous agent proved that borrowing another project's copy does not work.  The
standard decomp answer for a blob like that is to match it as *assembly*: you
disassemble the ROM's own bytes and reassemble them, so it matches by
construction rather than by luck.  pret does exactly this for 39 MSL files;
src/main/msl_*.s in this repo are the hand-written equivalent.

This script automates that loop:

  slice bytes -> capstone disassemble -> rewrite into mwasmarm syntax ->
  assemble with tools/scripts/as.py -> byte-compare every function against
  build/reference/<module>.bin with the same relocation logic
  verify_functions.py uses -> drop whatever did not reproduce -> re-emit.

WHAT IT IS AND IS NOT.  A function matched this way advances "the ROM
reproduces byte-exactly".  It does NOT advance "the game is understood" -- there
is no C, no types and no names.  Generated files are called
src/<module>/asm_<startaddr>.s so the two can never be confused in a report.

Design notes, i.e. the parts that took the iterations:

* Instruction set comes from build/reference/triage.json and is authoritative.
  Files never mix modes: an ARM run and a Thumb run get separate files, so a
  call that stays inside a file is always same-mode and the assembler can
  resolve it locally.

* Everything outside the current file is referenced as `.public sub_<REALRAM>`
  so mwasmarm emits a relocation and verify_functions.py resolves it -- that is
  what reproduces the linker's interworking (ARM->Thumb BL becomes BLX).
  Anything inside the file is a plain label, whose displacement is correct
  because functions are emitted contiguously at their exact ROM sizes.

* Literal pools are the thing that breaks a naive disassembler: capstone
  happily decodes pool words as instructions.  Pool addresses are collected
  module-wide from every PC-relative load (a pool word is frequently loaded by
  the *next* function), and a data run continues from a known pool word to the
  end of the function or the next branch target.

* PC-relative loads are emitted in their raw `ldr r0, [pc, #0x90]` form rather
  than as `ldr r0, label`.  mwasmarm encodes that immediate verbatim, so the
  word comes back identical even when the pool lives outside the function.

* mwasmarm wants pre-UAL mnemonics: no ARM `push`/`pop`, and the condition goes
  between the operation and its suffix (`ldrneb`, `ldmeqia`, `andeqs`), which
  is the opposite of what capstone prints.

A function that does not reproduce byte-for-byte is emitted as a `.byte` blob
with NO symbol on it: the bytes stay in the file so the surrounding functions
keep their layout, but the verifier never sees it and it is never counted as a
match.  --byte-symbols turns those into real (data) symbols; the summary always
reports them on their own line because they are data, not code.
"""
import argparse
import importlib.util
import json
import os
import re
import struct
import sys

sys.path.insert(0, r"C:\Users\pranav\AppData\Local\Programs\Python\Python313\Lib\site-packages")
try:
    import capstone
    from capstone import arm as cs_arm
except ImportError:  # pragma: no cover
    sys.exit("capstone not importable; pip install capstone")

HERE = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, HERE)
import verify_functions as vf  # noqa: E402

_spec = importlib.util.spec_from_file_location("as_", os.path.join(HERE, "as.py"))
as_ = importlib.util.module_from_spec(_spec)
_spec.loader.exec_module(as_)

REF = "build/reference"


# --------------------------------------------------------------------------
# mnemonic rewriting
# --------------------------------------------------------------------------

CC = {
    cs_arm.ARM_CC_EQ: "eq", cs_arm.ARM_CC_NE: "ne", cs_arm.ARM_CC_HS: "hs",
    cs_arm.ARM_CC_LO: "lo", cs_arm.ARM_CC_MI: "mi", cs_arm.ARM_CC_PL: "pl",
    cs_arm.ARM_CC_VS: "vs", cs_arm.ARM_CC_VC: "vc", cs_arm.ARM_CC_HI: "hi",
    cs_arm.ARM_CC_LS: "ls", cs_arm.ARM_CC_GE: "ge", cs_arm.ARM_CC_LT: "lt",
    cs_arm.ARM_CC_GT: "gt", cs_arm.ARM_CC_LE: "le",
}

# operation -> suffixes that must follow the condition code
MEM_SUF = ("sbt", "sht", "bt", "ht", "sb", "sh", "b", "h", "d", "t")
BLK_SUF = ("ia", "ib", "da", "db", "fd", "fa", "ed", "ea")
DATAPROC = {
    "and", "eor", "sub", "rsb", "add", "adc", "sbc", "rsc", "orr", "mov",
    "bic", "mvn", "mul", "mla", "smull", "umull", "smlal", "umlal", "lsl",
    "lsr", "asr", "ror", "rrx", "neg",
}


def split_cc(insn):
    """(base mnemonic, condition or None) from what capstone printed."""
    m = insn.mnemonic
    cc = CC.get(insn.cc)
    if cc and m.endswith(cc) and len(m) > len(cc):
        return m[:-len(cc)], cc
    return m, None


def weave(base, cc):
    """Put the condition where mwasmarm wants it: op + cond + suffix."""
    if not cc:
        return base
    if base.startswith(("ldr", "str")):
        for s in MEM_SUF:
            if base == "ldr" + s or base == "str" + s:
                return base[:3] + cc + s
        if base in ("ldr", "str"):
            return base + cc
    if base.startswith(("ldm", "stm")):
        for s in BLK_SUF:
            if base == "ldm" + s or base == "stm" + s:
                return base[:3] + cc + s
        if base in ("ldm", "stm"):
            return base + cc + "ia"
    if base.endswith("s") and base[:-1] in DATAPROC:
        return base[:-1] + cc + "s"
    return base + cc


BRANCH_OPS = {"b", "bl", "blx", "bx"}


class Unsupported(Exception):
    pass


def render(insn, thumb, symfor):
    """Text for one instruction, or raise Unsupported.

    `symfor(addr)` returns the name to use for a branch target.
    """
    base, cc = split_cc(insn)
    ops = insn.op_str

    # ARM has no push/pop; mwasmarm rejects them outright.
    if not thumb and base in ("push", "pop"):
        base, ops = ("stmdb" if base == "push" else "ldmia"), "sp!, " + ops
        return weave(base[:3], cc) + base[3:] + " " + ops if cc else base + " " + ops

    if base == "nop":
        raise Unsupported("nop")

    if base == "adr":
        # capstone prints the resolved address; mwasmarm wants the raw form.
        w = int.from_bytes(insn.bytes, "little")
        if thumb:
            return "add %s, pc, #%#x" % (insn.reg_name(insn.operands[0].reg),
                                         (w & 0xFF) * 4)
        rd = insn.reg_name(insn.operands[0].reg)
        imm = w & 0xFFF
        rot = (imm >> 8) * 2
        val = ((imm & 0xFF) >> rot) | ((imm & 0xFF) << (32 - rot)) & 0xFFFFFFFF \
            if rot else (imm & 0xFF)
        op = "add" if (w >> 21) & 0xF == 0x4 else "sub"
        return "%s%s %s, pc, #%#x" % (op, cc or "", rd, val)

    if base in BRANCH_OPS and insn.operands and \
            insn.operands[0].type == cs_arm.ARM_OP_IMM:
        return weave(base, cc) + " " + symfor(insn.operands[0].imm)

    return (weave(base, cc) + " " + ops).rstrip()


def pcrel(insn, thumb):
    """(literal address, byte width) for a PC-relative load, else None."""
    for op in insn.operands:
        if op.type == cs_arm.ARM_OP_MEM and op.mem.base == cs_arm.ARM_REG_PC \
                and op.mem.index == 0:
            pc = ((insn.address + 4) & ~3) if thumb else insn.address + 8
            n = 8 if insn.mnemonic.startswith(("ldrd", "strd")) else 4
            if insn.mnemonic.startswith(("vldr", "vstr", "fldd", "fstd")):
                n = 8
            return pc + op.mem.disp, n
    return None


TERMINATORS = ("b", "bx", "bxj")


def terminates(insn, thumb):
    """True if control cannot fall through this instruction."""
    base, cc = split_cc(insn)
    if cc:
        return False
    if base in TERMINATORS:
        return True
    if base in ("pop", "ldm", "ldmia", "ldmib", "ldmda", "ldmdb", "ldmfd"):
        return "pc" in insn.op_str
    if base in ("mov", "ldr") and insn.op_str.startswith("pc,"):
        return True
    return False


# --------------------------------------------------------------------------
# decoding
# --------------------------------------------------------------------------

class Disasm:
    def __init__(self):
        self.md = {}
        for thumb in (False, True):
            m = capstone.Cs(capstone.CS_ARCH_ARM,
                            capstone.CS_MODE_THUMB if thumb else capstone.CS_MODE_ARM)
            m.detail = True
            self.md[thumb] = m

    def one(self, data, addr, thumb):
        return next(self.md[thumb].disasm(data, addr, count=1), None)


def scan_pools(dis, ref, base, funcs):
    """Module-wide set of literal-pool addresses -> width.

    A pool word is very often loaded by a *different* function than the one it
    sits in (CodeWarrior parks the pool at the end of whichever function was
    being emitted), so this has to be collected across the whole module before
    any function is rendered.
    """
    pools = {}
    for f in funcs:
        thumb = f["mode"] == "thumb"
        off, n = f["ram"] - base, f["size"]
        pos = 0
        while pos < n:
            insn = dis.one(ref[off + pos:off + n], f["ram"] + pos, thumb)
            if insn is None:
                pos += 2 if thumb else 4
                continue
            hit = pcrel(insn, thumb)
            if hit:
                pools[hit[0]] = max(pools.get(hit[0], 0), hit[1])
            pos += insn.size
    return pools


def decode(dis, ref, base, f, pools):
    """[(kind, addr, raw, insn_or_None)] covering exactly [ram, ram+size)."""
    thumb = f["mode"] == "thumb"
    start, n = f["ram"], f["size"]
    off = start - base

    # pass 1: branch targets that land inside the function
    targets = set()
    pos = 0
    while pos < n:
        insn = dis.one(ref[off + pos:off + n], start + pos, thumb)
        if insn is None:
            pos += 2 if thumb else 4
            continue
        b, _ = split_cc(insn)
        if b in BRANCH_OPS and insn.operands and \
                insn.operands[0].type == cs_arm.ARM_OP_IMM:
            t = insn.operands[0].imm
            if start <= t < start + n:
                targets.add(t)
        pos += insn.size

    items, pos, in_data = [], 0, False
    while pos < n:
        a = start + pos
        if a in targets:
            in_data = False
        width = pools.get(a)
        if width and not in_data:
            in_data = True
        if in_data:
            w = width or 4
            w = min(w, n - pos)
            if (a % 4) or w < 4:
                items.append(("bytes", a, ref[off + pos:off + pos + w], None))
            else:
                for k in range(0, w, 4):
                    items.append(("word", a + k, ref[off + pos + k:off + pos + k + 4], None))
            pos += w
            continue
        insn = dis.one(ref[off + pos:off + n], a, thumb)
        if insn is None:
            step = min(2 if thumb else 4, n - pos)
            items.append(("bytes", a, ref[off + pos:off + pos + step], None))
            pos += step
            continue
        items.append(("insn", a, bytes(insn.bytes), insn))
        if terminates(insn, thumb) and (a + insn.size) not in targets \
                and (a + insn.size) in pools:
            in_data = True
        pos += insn.size
    return items, targets


# --------------------------------------------------------------------------
# emission
# --------------------------------------------------------------------------

HEADER = """; {name} -- {module} {lo:#010x}..{hi:#010x}, generated by tools/scripts/mkasm.py.
;
; Vendored middleware (Nintendo DWC / GameSpy SDK).  There is no C source for it
; in this tree, so it is matched the way pret matches MSL: the ROM's own bytes
; are disassembled and reassembled.  Every function below reproduces its
; reference bytes exactly; this buys byte-exactness, NOT understanding.
;
; Assemble: python tools/scripts/as.py {path}
"""


def hexbytes(b):
    return ", ".join("0x%02X" % x for x in b)


def emit(module, path, funcs, decoded, blob_set, byte_symbols):
    """Write one .s.  `decoded` maps ram -> (items, targets)."""
    defined = {f["ram"] for f in funcs}
    externs = {}
    body = []

    def symfor_factory(fstart, fend):
        def symfor(t):
            if fstart <= t < fend:
                return "_%08X" % t
            if t in defined and t not in blob_set:
                return "sub_%08X" % t
            nm = "sub_%08X" % t
            externs[nm] = t
            return nm
        return symfor

    lo = funcs[0]["ram"]
    hi = funcs[-1]["ram"] + funcs[-1]["size"]
    for f in funcs:
        start, size = f["ram"], f["size"]
        items, targets = decoded[start]
        name = "sub_%08X" % start
        body.append("")
        if start in blob_set:
            body.append("; %s -- could not be reassembled as instructions;" % name)
            body.append("; emitted as data so the file keeps its layout.%s"
                        % ("" if byte_symbols else "  Not a match: no symbol."))
            if byte_symbols:
                body.append("\t.global %s" % name)
                body.append("\t.type %s, @object" % name)
            body.append("%s:" % name)
            raw = b"".join(i[2] for i in items)
            for k in range(0, len(raw), 16):
                body.append("\t.byte " + hexbytes(raw[k:k + 16]))
            if byte_symbols:
                body.append("\t.size %s, . - %s" % (name, name))
            continue
        body.append("\t.global %s" % name)
        body.append("\t.type %s, @function" % name)
        body.append("%s:" % name)
        symfor = symfor_factory(start, start + size)
        for kind, a, raw, insn in items:
            if a in targets:
                body.append("_%08X:" % a)
            if kind == "insn":
                body.append("\t" + render(insn, f["mode"] == "thumb", symfor))
            elif kind == "word":
                body.append("\t.word 0x%08X" % int.from_bytes(raw, "little"))
            else:
                body.append("\t.byte " + hexbytes(raw))
        body.append("\t.size %s, . - %s" % (name, name))

    out = [HEADER.format(name=os.path.basename(path), module=module,
                         lo=lo, hi=hi, path=path.replace("\\", "/"))]
    if externs:
        out.append("")
        for nm in sorted(externs):
            out.append("\t.public %s" % nm)
    out.append("")
    out.append("\t.text")
    out.append("\t.%s" % funcs[0]["mode"])
    out.append("\t.balign 4, 0")
    out.extend(body)
    out.append("")
    os.makedirs(os.path.dirname(path), exist_ok=True)
    with open(path, "w", newline="\n") as fh:
        fh.write("\n".join(out))


# --------------------------------------------------------------------------
# checking -- mirrors verify_functions.verify_function, but keeps every diff
# --------------------------------------------------------------------------

def relocated(obj, sym, base_fix, module):
    sec_idx = sym["shndx"]
    fstart, fsize = sym["value"], sym["size"]
    code = obj.section_bytes(sec_idx)[fstart:fstart + fsize]
    home = vf.name_addr(sym["name"])
    if home is None:
        return None
    home += base_fix
    masked = set()
    for roff, rtype, rsym, radd in obj.relocs.get(sec_idx, []):
        if not (fstart <= roff < fstart + fsize):
            continue
        target = obj.symtab[rsym]
        t = vf.name_addr(target["name"])
        if t is not None:
            t += base_fix
        i = roff - fstart
        P = home + i
        if rtype in (vf.R_ARM_PC24, vf.R_ARM_CALL, vf.R_ARM_JUMP24):
            if t is None:
                masked.update(range(i, i + 4))
                continue
            word, = struct.unpack("<I", code[i:i + 4])
            if rtype != vf.R_ARM_JUMP24 and vf.target_mode(t, module) == "thumb":
                x = t + radd - P
                word = 0xFA000000 | ((x & 2) << 23) | ((x >> 2) & 0xFFFFFF)
            else:
                word = (word & 0xFF000000) | (((t + radd - P) >> 2) & 0xFFFFFF)
            code[i:i + 4] = struct.pack("<I", word)
        elif rtype == vf.R_ARM_ABS32:
            if t is None:
                masked.update(range(i, i + 4))
                continue
            code[i:i + 4] = struct.pack("<I", (t + radd) & 0xFFFFFFFF)
        elif rtype == vf.R_ARM_THM_PC22:
            if t is None:
                masked.update(range(i, i + 4))
                continue
            if vf.target_mode(t, module) == "arm":
                x = t + radd + 4 - ((P + 4) & ~3)
                hi, lo = 0xF000 | ((x >> 12) & 0x7FF), 0xE800 | ((x >> 1) & 0x7FE)
            else:
                x = t + radd - P
                hi, lo = 0xF000 | ((x >> 12) & 0x7FF), 0xF800 | ((x >> 1) & 0x7FF)
            code[i:i + 2] = struct.pack("<H", hi)
            code[i + 2:i + 4] = struct.pack("<H", lo)
        else:
            masked.update(range(i, i + 4))
    return home, code, masked


def check(objpath, ref, region_ram, module):
    """{ram: (ok, nbytes, masked, first_diff)} for every function symbol."""
    obj = vf.Obj(objpath)
    out = {}
    for sym in obj.symtab:
        if sym["typ"] != vf.STT_FUNC or sym["size"] == 0:
            continue
        r = relocated(obj, sym, 0, module)
        if r is None:
            continue
        home, code, masked = r
        off = home - region_ram
        orig = ref[off:off + len(code)]
        diffs = [i for i in range(len(code)) if i not in masked and code[i] != orig[i]]
        out[home] = (not diffs, len(code), len(masked), diffs[0] if diffs else None)
    return out


# --------------------------------------------------------------------------
# driver
# --------------------------------------------------------------------------

SKIP_KINDS = {"data"}


def pick(triage, module, lo, hi, include_claimed=False):
    out = []
    for f in triage[module]:
        if not (lo <= f["ram"] < hi) or not f["size"]:
            continue
        if f["kind"] in SKIP_KINDS:
            continue
        if not include_claimed and f["status"] != "unclaimed":
            continue
        out.append(f)
    out.sort(key=lambda f: f["ram"])
    return out


def runs(funcs, chunk):
    """Split into contiguous same-mode groups of at most `chunk` functions."""
    groups, cur = [], []
    for f in funcs:
        if cur and (f["ram"] != cur[-1]["ram"] + cur[-1]["size"]
                    or f["mode"] != cur[-1]["mode"] or len(cur) >= chunk):
            groups.append(cur)
            cur = []
        cur.append(f)
    if cur:
        groups.append(cur)
    return groups


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("module")
    ap.add_argument("lo", nargs="?", default=None)
    ap.add_argument("hi", nargs="?", default=None)
    ap.add_argument("--chunk", type=int, default=32)
    ap.add_argument("--byte-symbols", action="store_true")
    ap.add_argument("--passes", type=int, default=2)
    ap.add_argument("--keep-failures", action="store_true",
                    help="leave files whose functions all failed on disk")
    ap.add_argument("-v", "--verbose", action="store_true")
    a = ap.parse_args()

    manifest = json.load(open(os.path.join(REF, "manifest.json")))
    triage = json.load(open(os.path.join(REF, "triage.json")))
    module = a.module
    base = manifest[module]["ram"]
    ref = open(os.path.join(REF, module + ".bin"), "rb").read()
    lo = int(a.lo, 0) if a.lo else base
    hi = int(a.hi, 0) if a.hi else base + len(ref)

    funcs = pick(triage, module, lo, hi)
    if not funcs:
        sys.exit("nothing selected")
    dis = Disasm()
    pools = scan_pools(dis, ref, base, triage[module])

    total_fn = total_bytes = 0
    blob_fn = blob_bytes = 0
    masked_total = 0
    failures = []
    for group in runs(funcs, a.chunk):
        path = "src/%s/asm_%08X.s" % (module, group[0]["ram"])
        decoded = {}
        for f in group:
            try:
                decoded[f["ram"]] = decode(dis, ref, base, f, pools)
            except Exception as e:  # pragma: no cover
                decoded[f["ram"]] = (None, None)
                failures.append((f["ram"], "decode: %s" % e))
        blobs = {f["ram"] for f in group if decoded[f["ram"]][0] is None}
        for r in blobs:
            decoded[r] = ([("bytes", r, ref[r - base:r - base + next(
                f["size"] for f in group if f["ram"] == r)], None)], set())

        res = {}
        for _ in range(a.passes):
            try:
                emit(module, path, group, decoded, blobs, a.byte_symbols)
            except Unsupported as e:
                # one instruction the renderer cannot express -- find which
                # function and blob just that one
                bad = _blame(module, path, group, decoded, blobs, a.byte_symbols)
                if bad is None:
                    failures.append((group[0]["ram"], "render: %s" % e))
                    break
                blobs.add(bad)
                continue
            rc, obj, out = as_.build(path)
            if rc:
                bad = _blame_asm(module, path, group, decoded, blobs, a.byte_symbols)
                if bad is None:
                    failures.append((group[0]["ram"], "assembler rejected file"))
                    if a.verbose:
                        print(out)
                    break
                blobs |= bad
                continue
            res = check(obj, ref, base, module)
            newblobs = {f["ram"] for f in group
                        if f["ram"] not in blobs and not res.get(f["ram"], (False,))[0]}
            if not newblobs:
                break
            blobs |= newblobs
        else:
            emit(module, path, group, decoded, blobs, a.byte_symbols)
            rc, obj, out = as_.build(path)
            res = check(obj, ref, base, module) if not rc else {}

        good = [f for f in group if f["ram"] not in blobs and res.get(f["ram"], (False,))[0]]
        bad = [f for f in group if f not in good]
        total_fn += len(good)
        total_bytes += sum(f["size"] for f in good)
        blob_fn += len(bad)
        blob_bytes += sum(f["size"] for f in bad)
        masked_total += sum(res[f["ram"]][2] for f in good if f["ram"] in res)
        if not good and not a.keep_failures:
            if os.path.exists(path):
                os.remove(path)
            o = os.path.join("build", os.path.splitext(path)[0] + ".o")
            if os.path.exists(o):
                os.remove(o)
        print("%-28s %3d/%-3d fn  %6d/%-6d bytes" %
              (path, len(good), len(group), sum(f["size"] for f in good),
               sum(f["size"] for f in group)))
        if a.verbose:
            for f in bad:
                d = res.get(f["ram"])
                print("    fail %08X size %5d %s" %
                      (f["ram"], f["size"],
                       ("first diff +%#x" % d[3]) if d and d[3] is not None else "blob"))

    print()
    print("%s: %d functions / %d bytes assembly-matched" % (module, total_fn, total_bytes))
    print("%s: %d functions / %d bytes NOT matched (byte fallback%s)" %
          (module, blob_fn, blob_bytes,
           ", symbols emitted" if a.byte_symbols else ", no symbol, not counted"))
    if masked_total:
        print("%d relocation bytes masked by the verifier inside matched functions"
              % masked_total)
    for r, why in failures:
        print("  !! %08X %s" % (r, why))


def _blame(module, path, group, decoded, blobs, bs):
    """Which single function makes emit() raise?"""
    for f in group:
        if f["ram"] in blobs:
            continue
        try:
            emit(module, path + ".probe", [f], {f["ram"]: decoded[f["ram"]]},
                 blobs, bs)
        except Unsupported:
            os.path.exists(path + ".probe") and os.remove(path + ".probe")
            return f["ram"]
    if os.path.exists(path + ".probe"):
        os.remove(path + ".probe")
    return None


def _blame_asm(module, path, group, decoded, blobs, bs):
    """Which functions does mwasmarm reject?  Bisect by emitting one at a time."""
    bad = set()
    probe = path + ".probe.s"
    for f in group:
        if f["ram"] in blobs:
            continue
        try:
            emit(module, probe, [f], {f["ram"]: decoded[f["ram"]]}, blobs, bs)
        except Unsupported:
            bad.add(f["ram"])
            continue
        rc, obj, out = as_.build(probe)
        if rc:
            bad.add(f["ram"])
    for p in (probe, os.path.join("build", os.path.splitext(probe)[0] + ".o")):
        if os.path.exists(p):
            os.remove(p)
    return bad or None


if __name__ == "__main__":
    main()
