#!/usr/bin/env python3
"""Side-by-side disassembly of a compiled function vs the ROM.

  python cmp.py build/src/ov093/foo.o sub_021B8F38
"""
import json, os, re, struct, sys
sys.path.insert(0, r"C:\Users\pranav\AppData\Local\Programs\Python\Python313\Lib\site-packages")
import capstone

sys.path.insert(0, os.path.abspath("tools/scripts"))
import verify_functions as V

obj_path, name = sys.argv[1], sys.argv[2]
mod = re.search(r"[\\/](ov\d{3})[\\/]", obj_path)
mod = mod.group(1) if mod else "main"
man = json.load(open("build/reference/manifest.json"))
base = man[mod]["ram"]
ref = open(f"build/reference/{mod}.bin", "rb").read()

obj = V.Obj(obj_path)
sym = next(s for s in obj.symtab if s["name"] == name and s["typ"] == 2)
home = V.name_addr(name)
off = home - base
size = sym["size"]

# reproduce relocated bytes exactly like the verifier
sec_idx = sym["shndx"]
code = obj.section_bytes(sec_idx)[sym["value"]:sym["value"] + size]
saved = code[:]
r = V.verify_function(obj, sym, ref, 0, base)
# re-run relocation by hand: easier to just call verify then re-derive
# (verify_function mutates a local copy, so redo it here)
code = obj.section_bytes(sec_idx)[sym["value"]:sym["value"] + size]
for roff, rtype, rsym, radd in obj.relocs.get(sec_idx, []):
    if not (sym["value"] <= roff < sym["value"] + size):
        continue
    target = obj.symtab[rsym]
    t = V.name_addr(target["name"])
    i = roff - sym["value"]
    P = home + i
    if t is None:
        continue
    if rtype == V.R_ARM_THM_PC22:
        if V.target_mode(t) == "arm":
            x = t + radd + 4 - ((P + 4) & ~3)
            hi = 0xF000 | ((x >> 12) & 0x7FF); lo = 0xE800 | ((x >> 1) & 0x7FE)
        else:
            x = t + radd - P
            hi = 0xF000 | ((x >> 12) & 0x7FF); lo = 0xF800 | ((x >> 1) & 0x7FF)
        code[i:i+2] = struct.pack("<H", hi); code[i+2:i+4] = struct.pack("<H", lo)
    elif rtype == V.R_ARM_ABS32:
        val = t + radd
        if target["typ"] == V.STT_FUNC and V.target_mode(t) == "thumb":
            val |= 1
        code[i:i+4] = struct.pack("<I", val & 0xFFFFFFFF)

rom = ref[off:off + size]
md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_THUMB)

def dis(b, addr):
    out, p = [], 0
    while p < len(b):
        c = list(md.disasm(bytes(b[p:]), addr + p, count=1))
        if not c:
            out.append((addr + p, b[p:p+2].hex(), ".word", "?")); p += 2; continue
        i = c[0]; out.append((i.address, bytes(i.bytes).hex(), i.mnemonic, i.op_str)); p += i.size
    return out

a, b = dis(code, home), dis(rom, home)
print(f"{name} @ {home:#x} size {size}")
print(f"{'MINE':<44s} | ROM")
for i in range(max(len(a), len(b))):
    la = f"{a[i][0]:08x}: {a[i][1]:<8} {a[i][2]:<8} {a[i][3]}" if i < len(a) else ""
    lb = f"{b[i][0]:08x}: {b[i][1]:<8} {b[i][2]:<8} {b[i][3]}" if i < len(b) else ""
    mark = "  " if la[10:] == lb[10:] else "->"
    print(f"{mark}{la:<44s} | {lb}")
