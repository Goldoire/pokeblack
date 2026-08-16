#!/usr/bin/env python3
"""Semantic-equivalence check for NON-MATCHING decompilation.

verify_functions.py answers "are these bytes identical" -- the right question
for a matching decomp, and the wrong bar for a PC port, where the C only has to
behave the same. But dropping byte-exactness drops the oracle with it, and C
that merely looks plausible is how a port ends up subtly, silently wrong.

This is the weaker oracle that replaces it. It compiles a function, disassembles
both it and the ROM's version, and compares the things that must agree for the
code to mean the same thing, while ignoring the things a port does not care
about (register allocation, instruction scheduling, literal-pool placement):

  calls      the sequence of call targets, in order
  memory     the set of (base-register-relative) load/store offsets and widths
  constants  the multiset of immediate values used
  shape      counts of branches, returns and loop back-edges

Agreement on all four is strong evidence of equivalence. It is NOT proof --
that is what byte-exactness was -- so a PASS here means "no discrepancy found",
and every function still wants a human or reviewing agent to read the diff.

  python tools/scripts/equiv.py <module> <ram> <object-or-source>
  python tools/scripts/equiv.py ov021 0x02188c54 build/src/ov021/fld_fieldsys.o
"""
import json
import os
import re
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, r"C:\Users\pranav\AppData\Local\Programs\Python\Python313\Lib\site-packages")
import capstone  # noqa: E402

from verify_functions import Obj, name_addr, target_mode  # noqa: E402

REF = "build/reference"
LOADSTORE = re.compile(r"^(ldr|str)(b|h|sb|sh)?$")
MEMOP = re.compile(r"\[(\w+)(?:,\s*#(-?(?:0x)?[0-9a-fA-F]+))?\]")


def disasm(blob, addr, thumb):
    md = capstone.Cs(capstone.CS_ARCH_ARM,
                     capstone.CS_MODE_THUMB if thumb else capstone.CS_MODE_ARM)
    md.detail = False
    return [(i.address, i.mnemonic, i.op_str) for i in md.disasm(blob, addr)]


def trim(ins):
    """Drop everything after the last return.

    A function's size includes its literal pool, and capstone happily decodes
    those data words as instructions -- inventing calls, constants and branches
    that exist in one version and not the other purely because the two put
    their pools in different places. Nothing after the final return is code.
    """
    last = -1
    for i, (_a, mnem, ops) in enumerate(ins):
        m = mnem.split(".")[0]
        if (m == "pop" and "pc" in ops) or (m == "bx" and "lr" in ops) or m == "pc":
            last = i
        elif m in ("ldm", "ldmia") and "pc" in ops:
            last = i
    return ins[:last + 1] if last >= 0 else ins


def profile(ins, base, relocs=None):
    """Reduce a function to what must be preserved for semantic equivalence.

    `relocs` maps a function-relative offset to a resolved target address. An
    unlinked object's branches carry a zero displacement, so decoding them
    yields the next instruction rather than the callee -- the relocation is the
    only place the real target exists.
    """
    ins = trim(ins)
    calls, mem, consts = [], set(), []
    branches = rets = backedges = 0
    for addr, mnem, ops in ins:
        m = mnem.split(".")[0]
        if m in ("bl", "blx"):
            if relocs is not None:
                t = relocs.get(addr - base)
                if t is not None:
                    calls.append(t)
                continue
            t = re.search(r"#?(0x[0-9a-f]+)", ops)
            if t:
                calls.append(int(t.group(1), 16))
            continue
        elif m.startswith("b") and m not in ("bic",):
            branches += 1
            t = re.search(r"#?(0x[0-9a-f]+)", ops)
            if t and int(t.group(1), 16) < addr:
                backedges += 1
        if "pc" in ops and m == "pop":
            rets += 1
        if m == "bx" and "lr" in ops:
            rets += 1
        base_m = LOADSTORE.match(m)
        if base_m:
            mm = MEMOP.search(ops)
            if mm:
                off = int(mm.group(2), 0) if mm.group(2) else 0
                mem.add((mm.group(1), off, base_m.group(2) or "w"))
        if m.startswith("b") and m not in ("bic",):
            continue                  # branch displacements are not constants
        for c in re.findall(r"#(-?(?:0x)?[0-9a-fA-F]+)", ops):
            try:
                v = int(c, 0)
            except ValueError:
                continue
            if abs(v) > 1:            # 0/1 are noise
                consts.append(v)
    return dict(calls=calls, mem=mem, consts=sorted(consts),
                branches=branches, rets=rets, backedges=backedges)


def report(name, rom, mine):
    ok = True
    print(f"  {name}")
    if rom["calls"] != mine["calls"]:
        ok = False
        print(f"    CALLS differ")
        print(f"      rom : {[hex(c) for c in rom['calls']]}")
        print(f"      mine: {[hex(c) for c in mine['calls']]}")
    only_rom = rom["mem"] - mine["mem"]
    only_mine = mine["mem"] - rom["mem"]
    if only_rom or only_mine:
        ok = False
        print(f"    MEMORY ACCESS differs")
        if only_rom:
            print(f"      only in rom : {sorted(only_rom)}")
        if only_mine:
            print(f"      only in mine: {sorted(only_mine)}")
    if rom["consts"] != mine["consts"]:
        ok = False
        a, b = set(rom["consts"]), set(mine["consts"])
        print(f"    CONSTANTS differ  missing={sorted(a - b)} extra={sorted(b - a)}")
    for k in ("branches", "rets", "backedges"):
        if rom[k] != mine[k]:
            ok = False
            print(f"    {k.upper()}: rom {rom[k]} vs mine {mine[k]}")
    print("    no discrepancy found" if ok else "    NOT EQUIVALENT")
    return ok


def check(module, ram, obj, sym, data, base, tri, quiet=False):
    row = tri.get(ram)
    if not row or not row.get("size"):
        return None
    thumb = row["mode"] == "thumb"
    rom_ins = disasm(data[ram - base: ram - base + row["size"]], ram, thumb)
    code = bytes(obj.section_bytes(sym["shndx"])
                 [sym["value"]:sym["value"] + sym["size"]])
    relmap = {}
    for roff, _rt, rsym, _ra in obj.relocs.get(sym["shndx"], []):
        if sym["value"] <= roff < sym["value"] + sym["size"]:
            t = name_addr(obj.symtab[rsym]["name"])
            if t is not None:
                relmap[roff - sym["value"]] = t
    r = profile(rom_ins, ram)
    m = profile(disasm(code, ram, thumb), ram, relmap)
    if quiet:
        return (r["calls"] == m["calls"] and r["mem"] == m["mem"]
                and r["consts"] == m["consts"]
                and all(r[k] == m[k] for k in ("branches", "rets", "backedges")))
    print(f"{module} {ram:#010x}  rom {row['size']}B  mine {sym['size']}B")
    return report(sym["name"], r, m)


def batch(module):
    """Run the check over every function this repo already has an object for."""
    import glob
    man = json.load(open(os.path.join(REF, "manifest.json")))
    tri = {f["ram"]: f for f in json.load(open(os.path.join(REF, "triage.json")))[module]}
    data = open(os.path.join(REF, module + ".bin"), "rb").read()
    base = man[module]["ram"]
    pat = f"build/src/{module}/**/*.o" if module != "main" else "build/src/main/**/*.o"
    ok = flag = skip = 0
    flagged = []
    for path in sorted(glob.glob(pat, recursive=True)):
        try:
            obj = Obj(path)
        except Exception:
            continue
        for sym in obj.symtab:
            if sym["typ"] != 2 or not sym["size"]:
                continue
            ram = name_addr(sym["name"])
            if ram is None:
                continue
            r = check(module, ram, obj, sym, data, base, tri, quiet=True)
            if r is None:
                skip += 1
            elif r:
                ok += 1
            else:
                flag += 1
                flagged.append((sym["name"], path))
    tot = ok + flag
    print(f"{module}: {ok}/{tot} agree, {flag} flagged, {skip} skipped (no triage row)")
    for n, p in flagged[:12]:
        print(f"  flagged {n}  ({p})")
    return flag


def main():
    if len(sys.argv) >= 3 and sys.argv[1] == "--all":
        return 0 if batch(sys.argv[2]) == 0 else 1
    if len(sys.argv) < 4:
        sys.exit(__doc__)
    module, ram, objpath = sys.argv[1], int(sys.argv[2], 0), sys.argv[3]
    man = json.load(open(os.path.join(REF, "manifest.json")))
    tri = {f["ram"]: f for f in json.load(open(os.path.join(REF, "triage.json")))[module]}
    data = open(os.path.join(REF, module + ".bin"), "rb").read()
    base = man[module]["ram"]

    row = tri.get(ram)
    if not row:
        sys.exit(f"{ram:#x} not in triage for {module}")
    thumb = row["mode"] == "thumb"
    size = row["size"]
    rom_ins = disasm(data[ram - base: ram - base + size], ram, thumb)

    obj = Obj(objpath)
    sym = next((s for s in obj.symtab
                if s["typ"] == 2 and name_addr(s["name"]) == ram), None)
    if sym is None:
        sys.exit(f"no function symbol for {ram:#x} in {objpath}")
    code = bytes(obj.section_bytes(sym["shndx"])
                 [sym["value"]:sym["value"] + sym["size"]])
    # resolve this object's call sites through its relocations
    relmap = {}
    for roff, rtype, rsym, radd in obj.relocs.get(sym["shndx"], []):
        if sym["value"] <= roff < sym["value"] + sym["size"]:
            t = name_addr(obj.symtab[rsym]["name"])
            if t is not None:
                relmap[roff - sym["value"]] = t
    mine_ins = disasm(code, ram, thumb)

    print(f"{module} {ram:#010x}  rom {size}B / {len(rom_ins)} insns   "
          f"mine {sym['size']}B / {len(mine_ins)} insns")
    ok = report(sym["name"], profile(rom_ins, ram),
                profile(mine_ins, ram, relmap))
    return 0 if ok else 1


if __name__ == "__main__":
    sys.exit(main())
