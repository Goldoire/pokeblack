#!/usr/bin/env python3
"""Slice + disassemble one function out of a reference binary.

Usage:
  python tools/scripts/fn.py <module> <ram_addr> [size]
  python tools/scripts/fn.py main 0x02005230
  python tools/scripts/fn.py ov021 0x021d0f00 64

Module load addresses come from build/reference/manifest.json; the byte slice
is (ram - module.ram) into build/reference/<module>.bin.

Instruction set is auto-detected: a Thumb `push {..,lr}` / `push {..}` opener or
an ARM `stmdb sp!` / `sub sp` opener decides it, and the decode that produces
fewer invalid instructions wins ties.

Branch targets and PC-relative literals are annotated with names from
build/reference/functions.json when they land on a known function.
"""
import json
import os
import re
import sys

sys.path.insert(0, r"C:\Users\pranav\AppData\Local\Programs\Python\Python313\Lib\site-packages")
try:
    import capstone
except ImportError:  # pragma: no cover
    sys.exit("capstone not importable; pip install capstone")

REF = "build/reference"


def load(module):
    manifest = json.load(open(os.path.join(REF, "manifest.json")))
    if module not in manifest:
        sys.exit(f"unknown module {module}")
    data = open(os.path.join(REF, module + ".bin"), "rb").read()
    return manifest[module]["ram"], data


def known_names():
    fns = json.load(open(os.path.join(REF, "functions.json")))
    out = {}
    for mod, lst in fns.items():
        for f in lst:
            out.setdefault(f["ram"], (f["name"], mod, f["status"]))
    return out


def guess_size(data, off, base_ram, fns, module):
    """Next known function start after off, else 0x200 bytes."""
    here = base_ram + off
    nxt = min((f["ram"] for f in fns.get(module, []) if f["ram"] > here), default=None)
    return (nxt - here) if nxt else 0x200


def decode(data, addr, thumb):
    mode = capstone.CS_MODE_THUMB if thumb else capstone.CS_MODE_ARM
    md = capstone.Cs(capstone.CS_ARCH_ARM, mode)
    md.detail = False
    out, pos = [], 0
    while pos < len(data):
        chunk = list(md.disasm(data[pos:], addr + pos, count=1))
        if not chunk:
            step = 2 if thumb else 4
            out.append((addr + pos, data[pos:pos + step], ".word", "?"))
            pos += step
            continue
        i = chunk[0]
        out.append((i.address, bytes(i.bytes), i.mnemonic, i.op_str))
        pos += i.size
    return out


def bad_count(ins):
    return sum(1 for _, _, m, _ in ins if m == ".word")


def main():
    if len(sys.argv) < 3:
        sys.exit(__doc__)
    module = sys.argv[1]
    ram = int(sys.argv[2], 0)
    base, data = load(module)
    fns = json.load(open(os.path.join(REF, "functions.json")))
    names = known_names()
    off = ram - base
    if off < 0 or off >= len(data):
        sys.exit(f"{ram:#x} outside {module} ({base:#x}..{base + len(data):#x})")
    size = int(sys.argv[3], 0) if len(sys.argv) > 3 else guess_size(data, off, base, fns, module)
    size = min(size, len(data) - off)
    blob = data[off:off + size]

    a = decode(blob, ram, True)
    b = decode(blob, ram, False)
    first2 = int.from_bytes(blob[:2], "little")
    thumb = (first2 & 0xFE00) == 0xB400  # push {...}
    if not thumb and bad_count(a) != bad_count(b):
        thumb = bad_count(a) < bad_count(b)
    ins = a if thumb else b

    print(f"{module} {ram:#010x}  file offset {off:#x}  size {size} ({size:#x})  "
          f"mode {'THUMB' if thumb else 'ARM'}")
    ent = names.get(ram)
    if ent:
        print(f"claim table: {ent[0]}  status={ent[2]}")
    print()
    print("bytes:", blob.hex())
    print()
    for addr, raw, mnem, ops in ins:
        note = ""
        m = re.search(r"#?(0x[0-9a-f]+)", ops)
        if mnem.startswith(("b", "bl")) and m:
            t = int(m.group(1), 16)
            if t in names:
                note = f"  ; {names[t][0]} [{names[t][2]}]"
            elif not (ram <= t < ram + size):
                note = "  ; -> outside"
        if "[pc," in ops or "[pc]" in ops:
            pc = (addr + 4) & ~3 if thumb else addr + 8
            # Offsets print as hex ("[pc, #0x10]"), so a decimal-only pattern
            # silently grabs the leading 0 and reports the wrong literal.
            mm = re.search(r"#(-?(?:0x[0-9a-fA-F]+|\d+))", ops.split("[pc")[1])
            if mm:
                lit = pc + int(mm.group(1), 0)
                lo = lit - ram
                if 0 <= lo + 4 <= len(blob):
                    val = int.from_bytes(blob[lo:lo + 4], "little")
                    note = f"  ; ={val:#010x}"
                    if val in names:
                        note += f" {names[val][0]}"
        print(f"  {addr:08x}: {raw.hex():<8}  {mnem:<8} {ops}{note}")


if __name__ == "__main__":
    main()
