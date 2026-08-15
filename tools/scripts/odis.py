#!/usr/bin/env python3
"""Disassemble one function out of a compiled object, beside the ROM bytes.

Usage: python tools/scripts/odis.py build/src/ov021/foo.o sub_02188B58 [ov021]

Relocations are left unapplied (call targets read as bl #0); everything else
lines up with what verify_functions.py compares.
"""
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, r"C:\Users\pranav\AppData\Local\Programs\Python\Python313\Lib\site-packages")
import capstone
from verify_functions import Obj, name_addr


def main():
    path, fname = sys.argv[1], sys.argv[2]
    module = sys.argv[3] if len(sys.argv) > 3 else None
    obj = Obj(path)
    sym = next(s for s in obj.symtab if s["name"] == fname)
    body = bytes(obj.section_bytes(sym["shndx"])[sym["value"]:sym["value"] + sym["size"]])
    home = name_addr(fname)

    ref = None
    if module:
        manifest = json.load(open("build/reference/manifest.json"))
        ram = manifest[module]["ram"]
        full = open("build/reference/%s.bin" % module, "rb").read()
        ref = full[home - ram:home - ram + max(sym["size"], 0) + 32]

    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)
    mine = list(md.disasm(body, home))
    theirs = list(capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)
                  .disasm(ref, home)) if ref else []
    print("== %s  mine %d bytes / rom-window %d" % (fname, sym["size"], len(ref or b"")))
    print("%-46s | %s" % ("MINE", "ROM"))
    for i in range(max(len(mine), len(theirs))):
        a = mine[i] if i < len(mine) else None
        b = theirs[i] if i < len(theirs) else None
        sa = "%08x: %-9s %-7s %s" % (a.address, body[a.address - home:a.address - home + a.size].hex(),
                                     a.mnemonic, a.op_str) if a else ""
        sb = "%08x: %-9s %-7s %s" % (b.address, ref[b.address - home:b.address - home + b.size].hex(),
                                     b.mnemonic, b.op_str) if b else ""
        print("%-46s %s %s" % (sa, " " if sa[10:] == sb[10:] else "*", sb))


if __name__ == "__main__":
    main()
