#!/usr/bin/env python3
"""Recover GameFreak's original translation-unit boundaries from rodata.

The debug allocator and GF_ASSERT both take __FILE__:

    sub_02030734(heapId, size, atEnd, "clact.c", line)
    sub_02034714("fieldmap.c", line, "<stringified condition>")

so every TU that asserts or allocates leaves its own filename in rodata, and
the literal-pool word referencing that string sits inside the referencing
function. Because the string table and the code that references it are both
emitted in link order, the span [first reference, next TU's first reference)
bounds each translation unit.

This reconstructs the module's link order and file layout -- the single most
useful orientation step before decompiling an unfamiliar overlay. Three wave-1
agents derived it independently; this is the shared implementation.

  python tools/scripts/tu_map.py ov021
  python tools/scripts/tu_map.py main --json build/reference/main_tu_map.json

Caveats worth keeping in mind: a TU that never asserts is invisible and gets
absorbed into its predecessor's span, so a span with a very high function count
probably holds several files.
"""
import json
import os
import re
import struct
import sys

REF = "build/reference"
NAME = re.compile(rb"[ -~]{2,60}\.c\x00")


def main():
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    module = sys.argv[1]
    manifest = json.load(open(os.path.join(REF, "manifest.json")))
    if module not in manifest:
        sys.exit(f"unknown module {module}")
    data = open(os.path.join(REF, module + ".bin"), "rb").read()
    base = manifest[module]["ram"]

    # 1. every "<something>.c\0" string in the image
    strings = {}
    for m in NAME.finditer(data):
        s = m.group()[:-1].decode("ascii", "replace")
        if "/" in s or "\\" in s:
            s = re.split(r"[/\\]", s)[-1]
        strings[base + m.start()] = s
    if not strings:
        sys.exit(f"{module}: no .c strings in rodata; this trick does not apply")

    # 2. every word-aligned literal that points at one of them
    refs = {}
    for off in range(0, len(data) - 3, 4):
        w, = struct.unpack_from("<I", data, off)
        if w in strings:
            refs.setdefault(w, []).append(base + off)

    try:
        fns = json.load(open(os.path.join(REF, "functions.json")))[module]
    except (OSError, KeyError, ValueError):
        fns = []
    starts = sorted(f["ram"] for f in fns)

    def snap(addr):
        """A reference sits in the literal pool of the function that asserts,
        which is at the END of that function -- so the raw address misfiles
        every function ahead of the pool into the previous TU. pokeparty.c is
        the case that exposed it: its first reference is inside Party_New's
        own pool, which pushed Party_GetSize and Party_New into the preceding
        file. Snap back to the enclosing function start."""
        prev = None
        for s in starts:
            if s > addr:
                break
            prev = s
        return prev if prev is not None else addr

    found = sorted((snap(min(v)), addr) for addr, v in refs.items())
    rows = []
    for i, (first, saddr) in enumerate(found):
        end = found[i + 1][0] if i + 1 < len(found) else base + len(data)
        n = sum(1 for s in starts if first <= s < end)
        rows.append(dict(file=strings[saddr], start=first, end=end,
                         fns=n, bytes=end - first,
                         refs=len(refs[saddr])))

    out = dict(module=module, files=len(rows), rows=rows)
    if "--json" in sys.argv:
        p = sys.argv[sys.argv.index("--json") + 1]
    else:
        p = os.path.join(REF, f"{module}_tu_map.json")
    with open(p, "w") as fh:
        json.dump(out, fh, indent=1)

    print(f"{module}: {len(strings)} .c strings, {len(rows)} resolved to a span")
    print(f"{'file':32}{'start':>12}{'end':>12}{'fns':>6}{'bytes':>9}")
    for r in sorted(rows, key=lambda r: -r["bytes"])[:24]:
        print(f"{r['file'][:31]:32}{r['start']:#12x}{r['end']:#12x}"
              f"{r['fns']:6}{r['bytes']:9}")
    print(f"\nwrote {p}")


if __name__ == "__main__":
    main()
