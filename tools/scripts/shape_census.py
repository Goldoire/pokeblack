#!/usr/bin/env python3
"""Census of repeated function shapes among the unmatched.

Three agents independently wrote pattern generators and between them produced
roughly 930 verified functions -- ov093's wrapper_gen (17 shapes, ~690
matches), ov016's ARM fan-out generator (97), ov021's template scanner (146).
Each was written for one module and thrown away. This measures how much of the
REMAINING work is the same kind of thing, repo-wide, so the swarm can decide
whether a shared generator is worth building.

A function is reduced to a shape by masking out everything a template would
parameterise: immediates, register fields in data-processing ops, branch
displacements, and literal-pool words. Functions sharing a shape are the same
code with different constants -- write one template, emit them all.

  python tools/scripts/shape_census.py [--mode thumb|arm] [--max-size 96]
"""
import collections
import json
import os
import sys

REF = "build/reference"


def shape_thumb(blob):
    """Mask Thumb immediate and register fields, keeping opcode structure."""
    out = bytearray()
    i = 0
    while i + 1 < len(blob):
        h = int.from_bytes(blob[i:i + 2], "little")
        top = h >> 12
        if top in (0xD, 0xE):                 # conditional / unconditional b
            h &= 0xFF00
        elif top == 0xF:                      # bl/blx halves
            h &= 0xF800
        elif top in (0x2, 0x3):               # mov/cmp/add/sub immediate
            h &= 0xFF00
        elif top in (0x4,):                   # hi-reg ops, ldr literal
            h &= 0xFF00
        elif top in (0x6, 0x7, 0x8, 0x9):     # ldr/str immediate offset
            h &= 0xF800
        elif top in (0x0, 0x1):               # shifts / add-sub
            h &= 0xFF00
        i += 2
        out += h.to_bytes(2, "little")
    return bytes(out)


def shape_arm(blob):
    out = bytearray()
    for i in range(0, len(blob) - 3, 4):
        w = int.from_bytes(blob[i:i + 4], "little")
        if (w >> 25) & 7 == 5:                # branch
            w &= 0xFF000000
        else:
            w &= 0xFFF0F000                   # drop immediate + one reg field
        out += w.to_bytes(4, "little")
    return bytes(out)


def main():
    argv = sys.argv[1:]
    want = argv[argv.index("--mode") + 1] if "--mode" in argv else None
    maxsz = int(argv[argv.index("--max-size") + 1]) if "--max-size" in argv else 96

    manifest = json.load(open(os.path.join(REF, "manifest.json")))
    triage = json.load(open(os.path.join(REF, "triage.json")))

    groups = collections.defaultdict(list)
    total = 0
    for mod, lst in triage.items():
        if mod not in manifest:
            continue
        data = open(os.path.join(REF, mod + ".bin"), "rb").read()
        base = manifest[mod]["ram"]
        for f in lst:
            if not f["status"].startswith("unclaimed"):
                continue
            if f["kind"] not in ("thumb", "arm"):
                continue
            if want and f["kind"] != want:
                continue
            size = f["size"]
            if not (8 <= size <= maxsz):
                continue
            off = f["ram"] - base
            if off < 0 or off + size > len(data):
                continue
            blob = data[off:off + size]
            key = (f["kind"], size,
                   shape_thumb(blob) if f["kind"] == "thumb" else shape_arm(blob))
            groups[key].append((mod, f["ram"]))
            total += 1

    big = sorted((g for g in groups.values() if len(g) >= 4), key=len, reverse=True)
    covered = sum(len(g) for g in big)
    cov_bytes = 0
    for key, g in groups.items():
        if len(g) >= 4:
            cov_bytes += key[1] * len(g)

    print(f"unmatched functions {8}..{maxsz}B considered: {total:,}")
    print(f"shapes with >= 4 instances: {len(big):,}")
    print(f"functions in those shapes : {covered:,} ({100.0*covered/total:.1f}%)"
          f"  {cov_bytes:,} bytes\n")
    print(f"{'n':>5} {'size':>5}  modules spanned   example")
    for g in big[:20]:
        mods = len({m for m, _ in g})
        m, ram = g[0]
        sz = next(k[1] for k, v in groups.items() if v is g)
        print(f"{len(g):5} {sz:5}  {mods:3} modules       {m} {ram:#010x}")


if __name__ == "__main__":
    main()
