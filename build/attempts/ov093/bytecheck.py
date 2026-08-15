#!/usr/bin/env python3
"""Independent byte check for ov093, using the repo's documented naming rule.

WORKER_GUIDE.md: "Unknown callees are sub_<realRAM>, data is _<realRAM>".
tools/scripts/verify_functions.py currently ignores that distinction: for an
undefined symbol it infers "this is a function" from
    target["shndx"] == 0 and tmode(t_addr) is not None
and tmode() falls back to _enclosing(), i.e. the mode of whatever over-long
triage extent happens to contain the address.  ov093's dispatch tables
(0x021F0000..) sit inside such an extent, so every `extern const u8 _021Fxxxx[]`
is treated as a Thumb function pointer and gets bit 0 set -- one byte wrong in
each of the 529 table-getter functions.

Suggested one-line fix in verify_functions.py's R_ARM_ABS32 branch: never set
bit 0 for a target whose name matches ^_[0-9A-Fa-f]{8}$ (the data spelling).
This script applies exactly that rule and nothing else.
"""
import glob, json, os, re, struct, sys
sys.path.insert(0, os.path.abspath("tools/scripts"))
import verify_functions as V

man = json.load(open("build/reference/manifest.json"))
ref = open("build/reference/ov093.bin", "rb").read()
base = man["ov093"]["ram"]
DATA_NAME = re.compile(r"^_[0-9A-Fa-f]{8}$")

ok = bad = tot = 0
for p in sorted(glob.glob("build/src/ov093/*.o")):
    o = V.Obj(p)
    for sym in o.symtab:
        if sym["typ"] != 2 or sym["size"] == 0:
            continue
        home = V.name_addr(sym["name"])
        if home is None:
            continue
        off, n = home - base, sym["size"]
        code = o.section_bytes(sym["shndx"])[sym["value"]:sym["value"] + n]
        for roff, rtype, rsym, radd in o.relocs.get(sym["shndx"], []):
            if not (sym["value"] <= roff < sym["value"] + n):
                continue
            tgt = o.symtab[rsym]
            t = V.name_addr(tgt["name"])
            if t is None:
                continue
            i, P = roff - sym["value"], home + (roff - sym["value"])
            if rtype == V.R_ARM_THM_PC22:
                if V.target_mode(t, "ov093") == "arm":
                    x = t + radd + 4 - ((P + 4) & ~3)
                    hi, lo = 0xF000 | ((x >> 12) & 0x7FF), 0xE800 | ((x >> 1) & 0x7FE)
                else:
                    x = t + radd - P
                    hi, lo = 0xF000 | ((x >> 12) & 0x7FF), 0xF800 | ((x >> 1) & 0x7FF)
                code[i:i+2] = struct.pack("<H", hi)
                code[i+2:i+4] = struct.pack("<H", lo)
            elif rtype == V.R_ARM_ABS32:
                val = t + radd
                if not DATA_NAME.match(tgt["name"]) and V.target_mode(t, "ov093") == "thumb":
                    val |= 1
                code[i:i+4] = struct.pack("<I", val & 0xFFFFFFFF)
        if bytes(code) == ref[off:off + n]:
            ok += 1
            tot += n
        else:
            bad += 1
print(f"byte-exact: {ok}  bytes: {tot}  not exact: {bad}")
