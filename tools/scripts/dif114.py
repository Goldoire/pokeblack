#!/usr/bin/env python3
"""Side-by-side instruction diff of a compiled object against the reference.

  python tools/scripts/dif114.py build/src/ov114/foo.o ov114 [symbol-substring]
"""
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from verify_functions import Obj, verify_function, name_addr, target_mode  # noqa
from verify_functions import R_ARM_PC24, R_ARM_ABS32, R_ARM_THM_PC22, R_ARM_CALL, R_ARM_JUMP24  # noqa

import fn as fnmod


def relocated(obj, sym, base_fix=0, module=None, own_range=None):
    sec_idx = sym["shndx"]
    fstart, fsize = sym["value"], sym["size"]
    code = obj.section_bytes(sec_idx)[fstart:fstart + fsize]
    home_ram = name_addr(sym["name"]) + base_fix
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
        word, = struct.unpack("<I", code[i:i + 4]) if rtype != R_ARM_THM_PC22 else (0,)
        if rtype in (R_ARM_PC24, R_ARM_CALL, R_ARM_JUMP24):
            if t_addr is None:
                masked.update(range(i, i + 4)); continue
            if rtype != R_ARM_JUMP24 and target_mode(t_addr, module, own_range) == "thumb":
                x = t_addr + radd - P
                word = 0xFA000000 | ((x & 2) << 23) | ((x >> 2) & 0xFFFFFF)
            else:
                x = (t_addr + radd - P) >> 2
                word = (word & 0xFF000000) | (x & 0xFFFFFF)
            code[i:i + 4] = struct.pack("<I", word)
        elif rtype == R_ARM_ABS32:
            if t_addr is None:
                masked.update(range(i, i + 4)); continue
            val = t_addr + radd
            if target["typ"] == 2 and target_mode(t_addr, module, own_range) == "thumb":
                val |= 1
            code[i:i + 4] = struct.pack("<I", val & 0xFFFFFFFF)
        else:
            masked.update(range(i, i + 4))
    return code, masked, home_ram


def main():
    objpath, module = sys.argv[1], sys.argv[2]
    want = sys.argv[3] if len(sys.argv) > 3 else ""
    manifest = json.load(open("build/reference/manifest.json"))
    base = manifest[module]["ram"]
    ref = open(f"build/reference/{module}.bin", "rb").read()
    obj = Obj(objpath)
    for sym in obj.symtab:
        if sym["typ"] != 2 or sym["size"] == 0:
            continue
        if want and want not in sym["name"]:
            continue
        code, masked, home = relocated(obj, sym, 0, module, (base, base+len(ref)))
        off = home - base
        orig = ref[off:off + sym["size"]]
        bad = [i for i in range(len(code)) if i not in masked and code[i] != orig[i]]
        print(f"=== {sym['name']} @ {home:#x} size {sym['size']} "
              f"({len(bad)} diff bytes)")
        for i in range(0, len(code), 4):
            mw, = struct.unpack("<I", bytes(code[i:i + 4]))
            rw, = struct.unpack("<I", orig[i:i + 4])
            mark = "   " if mw == rw else ">> "
            if any(j in masked for j in range(i, i + 4)):
                mark = " ~ "
            md = fnmod.disasm_arm(mw, home + i) if hasattr(fnmod, "disasm_arm") else ""
            print(f"{mark}{home+i:#010x}  mine {mw:08x}  rom {rw:08x}")
        print()


main()
