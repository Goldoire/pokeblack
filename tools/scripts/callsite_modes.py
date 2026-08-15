#!/usr/bin/env python3
"""Derive each function's instruction set from its call sites, not a heuristic.

`triage.py` guesses `mode` from a function's own first bytes (a Thumb `push`
opener, else whichever decode has fewer invalid instructions). That guess is
wrong for small Thumb accessors with no push -- e.g. 0x020058D0 and 0x020057DC
are plain `ldr/str/bx lr` bodies and are classified `arm` -- and it has no
entry at all for any address the claim table missed (0x02030DA8, 0x02035108,
0x02074AC4, ...).

verify_functions.py reads that `mode` to decide whether an interworking call
should link as BL or as BLX(1), so a wrong or missing mode makes every caller
of that function unmatchable no matter how correct the C is.

The call sites are direct evidence and are never ambiguous:

  Thumb caller  BL  pair (lo & 0xF800 == 0xF800) -> callee is Thumb
  Thumb caller  BLX pair (lo & 0xF800 == 0xE800) -> callee is ARM
  ARM   caller  BL  (cond != 0xF)                -> callee is ARM
  ARM   caller  BLX (0xFAxxxxxx / 0xFBxxxxxx)    -> callee is Thumb

Only bytes inside a known function extent are scanned, and only in that
function's recorded mode, so data is not mined for phantom branches. Every
target is voted on; a target whose votes disagree is reported and never
applied.

Targets are restricted to the ARM9 static image (main). Overlays alias each
other in RAM, so an overlay address does not identify a unique function and a
global mode for it would be meaningless.

  python tools/scripts/callsite_modes.py            # report only
  python tools/scripts/callsite_modes.py --json OUT # write the derived map
  python tools/scripts/callsite_modes.py --apply    # merge into triage.json

--apply rewrites build/reference/triage.json: it fixes the `mode` of existing
main entries and appends `{kind: "callsite"}` stubs for addresses the claim
table never had. It touches nothing else, and it is idempotent.
"""
import json
import os
import sys

REF = "build/reference"


def load():
    manifest = json.load(open(os.path.join(REF, "manifest.json")))
    triage = json.load(open(os.path.join(REF, "triage.json")))
    return manifest, triage


def thumb_calls(blob, ram):
    i = 0
    while i + 4 <= len(blob):
        hi = int.from_bytes(blob[i:i + 2], "little")
        lo = int.from_bytes(blob[i + 2:i + 4], "little")
        if (hi & 0xF800) == 0xF000 and (lo & 0xE800) == 0xE800:
            imm = ((hi & 0x7FF) << 12) | ((lo & 0x7FF) << 1)
            if imm & (1 << 22):
                imm -= 1 << 23
            pc = ram + i + 4
            if (lo & 0xF800) == 0xF800:
                yield pc + imm, "thumb"
            else:
                yield ((pc & ~3) + imm) & ~1, "arm"
            i += 4
            continue
        i += 2


def arm_calls(blob, ram):
    for i in range(0, len(blob) - 3, 4):
        w = int.from_bytes(blob[i:i + 4], "little")
        if (w & 0xFE000000) == 0xFA000000:                      # BLX(1)
            imm = w & 0xFFFFFF
            if imm & 0x800000:
                imm -= 1 << 24
            yield ram + i + 8 + imm * 4 + ((w >> 24) & 1) * 2, "thumb"
        elif (w & 0x0F000000) == 0x0B000000 and (w >> 28) != 0xF:  # BL
            imm = w & 0xFFFFFF
            if imm & 0x800000:
                imm -= 1 << 24
            yield ram + i + 8 + imm * 4, "arm"


def derive():
    manifest, triage = load()
    main_lo = manifest["main"]["ram"]
    main_hi = main_lo + len(open(os.path.join(REF, "main.bin"), "rb").read())
    votes = {}
    for module, lst in triage.items():
        if module not in manifest:
            continue
        base = manifest[module]["ram"]
        data = open(os.path.join(REF, module + ".bin"), "rb").read()
        for f in lst:
            if f["kind"] in ("veneer", "data"):
                continue
            off = f["ram"] - base
            if off < 0 or off >= len(data):
                continue
            blob = data[off:off + f["size"]]
            gen = thumb_calls if f["mode"] == "thumb" else arm_calls
            for tgt, mode in gen(blob, f["ram"]):
                if not (main_lo <= tgt < main_hi):
                    continue
                votes.setdefault(tgt, {}).setdefault(mode, 0)
                votes[tgt][mode] += 1
    return manifest, triage, votes


def main():
    manifest, triage, votes = derive()
    known = {f["ram"]: f for f in triage["main"]}
    fix, add, conflict = {}, {}, {}
    for tgt, v in sorted(votes.items()):
        if len(v) > 1:
            conflict[tgt] = v
            continue
        mode = next(iter(v))
        cur = known.get(tgt)
        if cur is None:
            add[tgt] = (mode, v[mode])
        elif cur["mode"] != mode:
            fix[tgt] = (cur["mode"], mode, v[mode], cur["name"], cur["kind"])

    print(f"{len(votes)} call targets in main with direct evidence")
    print(f"{len(fix)} existing triage entries have the WRONG mode")
    print(f"{len(add)} call targets are absent from triage entirely")
    print(f"{len(conflict)} conflicting (not applied)\n")
    if fix:
        print("wrong mode:")
        for a, (was, now, n, nm, kind) in sorted(fix.items()):
            print(f"  {a:#010x} {nm:20s} kind={kind:6s} {was} -> {now}  ({n} call sites)")
    if conflict:
        print("\nconflicting evidence (left alone):")
        for a, v in sorted(conflict.items()):
            print(f"  {a:#010x} {v}")

    if "--json" in sys.argv:
        out = sys.argv[sys.argv.index("--json") + 1]
        json.dump({"fix": {f"{a:#010x}": list(t) for a, t in fix.items()},
                   "add": {f"{a:#010x}": list(t) for a, t in add.items()},
                   "conflict": {f"{a:#010x}": v for a, v in conflict.items()}},
                  open(out, "w"), indent=1)
        print(f"\nwrote {out}")

    if "--apply" in sys.argv:
        for f in triage["main"]:
            if f["ram"] in fix:
                f["mode"] = fix[f["ram"]][1]
        for a, (mode, _n) in sorted(add.items()):
            triage["main"].append({"name": f"sub_{a:08X}", "ram": a, "size": 0,
                                   "mode": mode, "kind": "callsite",
                                   "status": "unclaimed"})
        triage["main"].sort(key=lambda f: f["ram"])
        tmp = os.path.join(REF, "triage.json.tmp")
        json.dump(triage, open(tmp, "w"))
        os.replace(tmp, os.path.join(REF, "triage.json"))
        print(f"\napplied: {len(fix)} modes corrected, {len(add)} entries added")


if __name__ == "__main__":
    main()
