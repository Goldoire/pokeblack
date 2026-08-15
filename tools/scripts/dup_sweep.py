#!/usr/bin/env python3
"""Find already-verified functions duplicated into other modules.

Overlays are separately linked, so a helper used by several of them is
physically copied into each one's image. Every function this project has
already matched is therefore a byte pattern that may occur in modules nobody
has touched -- and unlike a hand match, claiming those costs nothing.

This is sdk_sweep.py's search applied to our own verified corpus instead of to
vendored SDK objects: for every symbol under build/src that verifies N/N, take
its compiled bytes and relocation mask, and look for an identical occurrence
in every reference binary.

  python tools/scripts/dup_sweep.py            # report
  python tools/scripts/dup_sweep.py --json OUT

A hit is a candidate, not a match: the duplicate has to be compiled from the
same source into the right module path before the verifier will credit it.
Report the two numbers separately.
"""
import glob
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from verify_functions import MODULE_RE, Obj, verify_function  # noqa: E402

REF = "build/reference"
MIN_SIZE = 16       # below this, byte coincidence is meaningless


def main():
    manifest = json.load(open(os.path.join(REF, "manifest.json")))
    fns = json.load(open(os.path.join(REF, "functions.json")))
    claimed = {m: {f["ram"]: f for f in lst} for m, lst in fns.items()}
    images = {m: open(os.path.join(REF, m + ".bin"), "rb").read() for m in manifest}

    hits, checked = [], 0
    for path in sorted(glob.glob("build/src/**/*.o", recursive=True)):
        norm = path.replace(os.sep, "/")
        mm = MODULE_RE.search(norm)
        home = mm.group(1) if mm and mm.group(1) in manifest else "main"
        try:
            obj = Obj(path)
        except Exception:
            continue
        for sym in obj.symtab:
            if sym["typ"] != 2 or sym["size"] < MIN_SIZE:
                continue
            r = verify_function(obj, sym, images[home], 0,
                                manifest[home]["ram"], home)
            if not r or r[1] == 0 or r[0] != r[1]:
                continue        # only sweep patterns we know are correct
            checked += 1
            code = bytes(obj.section_bytes(sym["shndx"])
                         [sym["value"]:sym["value"] + sym["size"]])
            mask = set()
            for roff, _t, _s, _a in obj.relocs.get(sym["shndx"], []):
                if sym["value"] <= roff < sym["value"] + sym["size"]:
                    i = roff - sym["value"]
                    mask.update(range(i, i + 4))
            anchor = next((a for a in range(0, len(code) - 8)
                           if not any(a + k in mask for k in range(8))), None)
            if anchor is None:
                continue
            pat = code[anchor:anchor + 8]
            for mod, ref in images.items():
                pos = -1
                while True:
                    pos = ref.find(pat, pos + 1)
                    if pos < 0:
                        break
                    start = pos - anchor
                    if start < 0 or start + len(code) > len(ref):
                        continue
                    win = ref[start:start + len(code)]
                    if not all(code[i] == win[i]
                               for i in range(len(code)) if i not in mask):
                        continue
                    ram = manifest[mod]["ram"] + start
                    if mod == home and ram == manifest[home]["ram"] + r[3]:
                        break   # itself
                    row = claimed.get(mod, {}).get(ram)
                    if row is not None and not row["status"].startswith("unclaimed"):
                        break   # already accounted for
                    hits.append(dict(name=sym["name"], home=home, module=mod,
                                     ram=ram, size=sym["size"],
                                     in_table=row is not None))
                    break

    by_mod = {}
    for h in hits:
        by_mod.setdefault(h["module"], []).append(h)
    print(f"swept {checked} verified functions >= {MIN_SIZE}B")
    print(f"{len(hits)} duplicate placements in {len(by_mod)} modules, "
          f"{sum(h['size'] for h in hits):,} bytes")
    print(f"  of those, {sum(1 for h in hits if h['in_table'])} land on an "
          f"existing claim-table row\n")
    for mod in sorted(by_mod, key=lambda m: -sum(h["size"] for h in by_mod[m]))[:15]:
        v = by_mod[mod]
        print(f"  {mod:8} {len(v):4} placements  {sum(h['size'] for h in v):7,} B"
              f"   e.g. {v[0]['name']} from {v[0]['home']}")
    if "--json" in sys.argv:
        p = sys.argv[sys.argv.index("--json") + 1]
        json.dump(hits, open(p, "w"), indent=1)
        print(f"\nwrote {p}")


if __name__ == "__main__":
    main()
