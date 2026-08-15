#!/usr/bin/env python3
"""Histogram of masked instruction shapes among not-yet-written ov093 functions."""
import glob, json, os, re, sys
from collections import Counter

REPO = r"C:\Users\pranav\decomp\pokeblack\repo"
REF = os.path.join(REPO, "build", "reference")
man = json.load(open(os.path.join(REF, "manifest.json")))
tri = json.load(open(os.path.join(REF, "triage.json")))
mod = "ov093"
base = man[mod]["ram"]
data = open(os.path.join(REF, mod + ".bin"), "rb").read()
end_ram = base + len(data)
MAX = int(sys.argv[1], 0) if len(sys.argv) > 1 else 32

taken = set()
for f in glob.glob(os.path.join(REPO, "src", "ov093", "*.c")):
    for m in re.finditer(r"\bsub_([0-9A-F]{8})\b", open(f, encoding="utf-8").read()):
        taken.add(int(m.group(1), 16))

starts = set(f["ram"] for f in tri[mod])
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
        if base <= (t & 0xFFFFFFFF) < end_ram:
            starts.add(t & 0xFFFFFFFF)
        p += 4
        continue
    p += 2
for off in range(0, n - 3, 4):
    v = int.from_bytes(data[off:off + 4], "little")
    if (v & 1) and base <= (v & ~1) < end_ram:
        starts.add(v & ~1)
S = sorted(starts)

cnt = Counter()
examples = {}
for i, a in enumerate(S):
    if a in taken:
        continue
    e = S[i + 1] if i + 1 < len(S) else end_ram
    sz = e - a
    if sz > MAX or sz < 4:
        continue
    b = bytearray(data[a - base:e - base])
    # mask: BL pairs -> "BL", movs rd,#imm -> imm byte -> "II"
    toks = []
    p2 = 0
    while p2 + 2 <= sz:
        h = int.from_bytes(b[p2:p2 + 2], "little")
        if p2 + 4 <= sz:
            l = int.from_bytes(b[p2 + 2:p2 + 4], "little")
            if (h & 0xF800) == 0xF000 and (l & 0xE000) == 0xE000:
                toks.append("BL")
                p2 += 4
                continue
        if (h & 0xF800) == 0x2000:  # movs rd, #imm8
            toks.append(f"mov{(h >> 8) & 7}#")
            p2 += 2
            continue
        toks.append(f"{h:04x}")
        p2 += 2
    key = (sz, " ".join(toks))
    cnt[key] += 1
    examples.setdefault(key, a)

for key, c in cnt.most_common(28):
    print(f"{c:4d}  n={key[0]:<3} @{examples[key]:#x}  {key[1]}")
