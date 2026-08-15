#!/usr/bin/env python3
"""Persist triage.json's accumulated mode corrections into the claim table.

WHY THIS EXISTS. `triage.json` is derived: `triage.py` rebuilds it from the
claim table by classifying each row's first bytes. Every correction that lives
only in triage.json -- whether a worker patched it in place, or
`callsite_modes.py --apply` derived it -- is destroyed by the next
regeneration. And callsite_modes only derives modes for targets in `main`,
because overlays alias each other in RAM, so overlay-internal corrections do
not come back. One regeneration cost ov016 three verified functions to gain
ov170 one.

`triage.py` honours an explicit `mode` on a claim-table row (the same override
mechanism as `status: "data"`). This script finds every place triage.json
currently disagrees with what triage.py would freshly derive, and writes that
disagreement into the claim table, where it survives.

Run it BEFORE any regeneration. After it, a regeneration is a no-op for modes.

  python tools/scripts/persist_modes.py           # report
  python tools/scripts/persist_modes.py --write   # apply
"""
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import triage  # noqa: E402

REF = "build/reference"


def intra_module_votes(data, base, rows, modes):
    """Callee modes derived from call sites INSIDE one module's own image.

    callsite_modes.py restricts itself to `main` because overlays alias each
    other in RAM, so a bare address does not identify a function. That
    reasoning does not apply here: we are decoding one module's own bytes and
    only accepting targets that land in that same module's image, so the
    callee can only be this module's code. This is the gap that lets
    overlay-internal mode errors survive a regeneration.

    Same discipline as elsewhere: decode only inside a known code extent, and
    only in that extent's own recorded mode, so rodata is not mined for
    phantom branches. A target whose votes disagree is dropped.
    """
    end = base + len(data)
    votes = {}

    def vote(addr, mode):
        if base <= addr < end and not (addr & 1):
            votes.setdefault(addr, set()).add(mode)

    for i, r in enumerate(rows):
        mode = modes.get(r["ram"])
        if mode not in ("arm", "thumb"):
            continue
        lo = r["ram"] - base
        hi = min(lo + (r["size"] or 0),
                 (rows[i + 1]["ram"] - base) if i + 1 < len(rows) else len(data),
                 len(data))
        if hi <= lo:
            continue
        blob = data[lo:hi]
        if mode == "thumb":
            j = 0
            while j + 4 <= len(blob):
                hw, lw = struct.unpack_from("<HH", blob, j)
                if (hw & 0xF800) == 0xF000 and (lw & 0xE800) == 0xE800:
                    imm = ((hw & 0x7FF) << 12) | ((lw & 0x7FF) << 1)
                    if imm & (1 << 22):
                        imm -= 1 << 23
                    pc = r["ram"] + j + 4
                    if (lw & 0xF800) == 0xF800:
                        vote(pc + imm, "thumb")          # BL   -> Thumb callee
                    else:
                        vote(((pc & ~3) + imm) & ~1, "arm")  # BLX -> ARM callee
                    j += 4
                    continue
                j += 2
        else:
            for j in range(0, len(blob) - 3, 4):
                w, = struct.unpack_from("<I", blob, j)
                if (w & 0xFE000000) == 0xFA000000:                       # BLX
                    imm = w & 0xFFFFFF
                    if imm & 0x800000:
                        imm -= 1 << 24
                    vote(r["ram"] + j + 8 + imm * 4 + ((w >> 24) & 1) * 2, "thumb")
                elif (w & 0x0F000000) == 0x0B000000 and (w >> 28) != 0xF:  # BL
                    imm = w & 0xFFFFFF
                    if imm & 0x800000:
                        imm -= 1 << 24
                    vote(r["ram"] + j + 8 + imm * 4, "arm")
    return {a: next(iter(m)) for a, m in votes.items() if len(m) == 1}


def main():
    write = "--write" in sys.argv
    manifest = json.load(open(os.path.join(REF, "manifest.json")))
    fns = json.load(open(os.path.join(REF, "functions.json")))
    tri = json.load(open(os.path.join(REF, "triage.json")))

    persisted, per_mod, conflicts = [], {}, []
    for mod, rows in fns.items():
        if mod not in manifest or mod not in tri:
            continue
        data = open(os.path.join(REF, mod + ".bin"), "rb").read()
        base = manifest[mod]["ram"]
        cur = {}
        for t in tri[mod]:
            # kind "callsite" stubs have no claim row; skip, they are derived
            if t.get("kind") != "callsite":
                cur.setdefault(t["ram"], t.get("mode"))
        for r in rows:
            live = cur.get(r["ram"])
            if live not in ("arm", "thumb"):
                continue
            off = r["ram"] - base
            if off < 0 or off >= len(data):
                continue
            blob = data[off:off + min(r["size"] or 8, len(data) - off)]
            fresh, _kind = triage.classify(blob)
            if fresh != live and r.get("mode") != live:
                r["mode"] = live
                persisted.append((mod, r["ram"], fresh, live, "triage"))
                per_mod[mod] = per_mod.get(mod, 0) + 1

        # Second pass: derive callee modes from this module's OWN call sites.
        rows_sorted = sorted(rows, key=lambda r: r["ram"])
        live_modes = {r["ram"]: (r.get("mode") or cur.get(r["ram"]))
                      for r in rows_sorted}
        derived = intra_module_votes(data, base, rows_sorted, live_modes)
        for r in rows_sorted:
            want = derived.get(r["ram"])
            if want is None:
                continue
            have = r.get("mode") or cur.get(r["ram"])
            if have == want:
                continue
            off = r["ram"] - base
            if off < 0 or off >= len(data):
                continue
            blob = data[off:off + min(r["size"] or 8, len(data) - off)]
            _fresh, kind = triage.classify(blob)
            if kind in ("data", "veneer") or r["status"] == "data":
                continue   # not code; its "mode" is meaningless either way
            if r["status"].startswith("matched"):
                # This function already verifies byte for byte. Its mode is
                # settled by something stronger than a vote, and its callers
                # were encoded against the current value -- flipping it can
                # only break them. Report the disagreement, change nothing.
                conflicts.append((mod, r["ram"], have, want))
                continue
            r["mode"] = want
            persisted.append((mod, r["ram"], have, want, "callsite"))
            per_mod[mod] = per_mod.get(mod, 0) + 1

    print(f"{len(persisted)} mode corrections pinned into the claim table")
    for mod in sorted(per_mod, key=lambda m: -per_mod[m])[:25]:
        print(f"  {mod:8s} {per_mod[mod]}")
    for mod, ram, fresh, live, why in persisted[:15]:
        print(f"    {mod:7s} {ram:#010x}  {fresh:5s} -> {live:5s}  ({why})")
    if len(persisted) > 15:
        print(f"    ... and {len(persisted) - 15} more")
    if conflicts:
        print(f"\n{len(conflicts)} rows left alone: already `matched`, so their")
        print("mode is settled by a byte-exact match, not by a vote:")
        for mod, ram, have, want in conflicts[:10]:
            print(f"    {mod:7s} {ram:#010x}  is {str(have):5s}, call sites say {want}")

    if not write:
        print("\n(dry run; pass --write to apply)")
        return
    json.dump(fns, open(os.path.join(REF, "functions.json"), "w"), indent=1)
    chk = json.load(open(os.path.join(REF, "functions.json")))
    allowed = {"name", "ram", "size", "status", "mode"}
    bad = [r for v in chk.values() for r in v if not set(r) <= allowed]
    print(f"\nwrote functions.json: {sum(len(v) for v in chk.values())} rows, "
          f"schema violations: {len(bad)}")


if __name__ == "__main__":
    main()
