#!/usr/bin/env python3
"""Recover real function boundaries in an overlay.

Starts = claim-table entries + every BL/BLX target inside the module (scanned
from the module itself) + every ABS32-looking pointer into the module found in
its own data.  End = next start.  Then print small ones, optionally only those
with no calls.
"""
import json, os, sys

REF = r"C:\Users\pranav\decomp\pokeblack\repo\build\reference"
manifest = json.load(open(os.path.join(REF, "manifest.json")))
tri = json.load(open(os.path.join(REF, "triage.json")))

mod = sys.argv[1]
maxsize = int(sys.argv[2]) if len(sys.argv) > 2 else 24
maxcalls = int(sys.argv[3]) if len(sys.argv) > 3 else 0
lo = int(sys.argv[4], 0) if len(sys.argv) > 4 else 0
hi = int(sys.argv[5], 0) if len(sys.argv) > 5 else 0xFFFFFFFF

base = manifest[mod]["ram"]
data = open(os.path.join(REF, mod + ".bin"), "rb").read()
end_ram = base + len(data)

starts = set(f["ram"] for f in tri[mod])

# every Thumb BL/BLX target that lands inside this module
n = len(data)
p = 0
while p + 4 <= n:
    h = int.from_bytes(data[p:p + 2], "little")
    l = int.from_bytes(data[p + 2:p + 4], "little")
    if (h & 0xF800) == 0xF000 and (l & 0xE000) == 0xE000:
        imm = ((h & 0x7FF) << 12) | ((l & 0x7FF) << 1)
        if imm & 0x400000:
            imm -= 0x800000
        pc = base + p + 4
        t = ((pc & ~3) + imm) if (l & 0xF800) == 0xE800 else (pc + imm)
        t &= 0xFFFFFFFF
        if base <= t < end_ram:
            starts.add(t)
        p += 4
        continue
    p += 2

# word-aligned pointers into the module (jump tables, callback tables, literals)
for off in range(0, n - 3, 4):
    v = int.from_bytes(data[off:off + 4], "little")
    if base <= (v & ~1) < end_ram and (v & 1):
        starts.add(v & ~1)

s = sorted(starts)
rows = []
for i, a in enumerate(s):
    b = s[i + 1] if i + 1 < len(s) else end_ram
    sz = b - a
    if sz > maxsize or not (lo <= a < hi):
        continue
    off = a - base
    calls = 0
    p = 0
    while p + 4 <= sz:
        h = int.from_bytes(data[off + p:off + p + 2], "little")
        l = int.from_bytes(data[off + p + 2:off + p + 4], "little")
        if (h & 0xF800) == 0xF000 and (l & 0xE000) == 0xE000:
            calls += 1
            p += 4
            continue
        p += 2
    if calls <= maxcalls:
        rows.append((a, sz, calls, data[off:off + sz].hex()))
print(f"{len(rows)} candidates (of {len(s)} recovered starts)")
for a, sz, calls, hx in rows:
    print(f"{a:#010x} n={sz:<4} c={calls} {hx}")
