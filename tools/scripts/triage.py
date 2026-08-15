#!/usr/bin/env python3
"""Classify every claim-table function by instruction set and shape.

The claim table was built from a prologue heuristic, so it contains entries
that are not C functions at all: linker-generated interworking veneers, jump
islands, and misidentified data. Workers should not spend attempts on those.

Writes build/reference/triage.json:
  {module: [{name, ram, size, mode, kind}]}

kind is one of:
  veneer   - `ldr pc,[pc,#-4]` + literal, or thumb `ldr r3,[pc]; bx r3` island
  trivial  - <= 8 bytes of real code (getter/setter/`bx lr`)
  thumb    - Thumb C function
  arm      - ARM C function
  data     - decodes as neither; almost certainly not code

Usage: python tools/scripts/triage.py [--summary]
"""
import json
import os
import sys

sys.path.insert(0, r"C:\Users\pranav\AppData\Local\Programs\Python\Python313\Lib\site-packages")
import capstone  # noqa: E402

REF = "build/reference"


def classify(blob):
    if len(blob) < 4:
        return "arm", "data"
    w0 = int.from_bytes(blob[:4], "little")
    if w0 == 0xE51FF004:                      # ldr pc, [pc, #-4]
        return "arm", "veneer"
    # `ldr r3,[pc,#0]; bx r3` is NOT a linker veneer. It is what mwcc emits for
    # a one-line C forwarder that tail-calls with three or fewer arguments --
    # with four it cannot spare r3 and emits push/bl/pop instead. Labelling
    # these "veneer" told workers to skip them, and they are free 8-byte
    # matches. (ov009 established the arity rule.)
    if w0 == 0xE12FFF1E:                      # bare bx lr
        return "arm", "trivial"

    h0 = int.from_bytes(blob[:2], "little")
    thumb = (h0 & 0xFE00) == 0xB400           # push {...}
    if not thumb:
        thumb = (h0 & 0xFF00) == 0xB500
    if not thumb:
        # Fall back to whichever decode has fewer undefined instructions.
        bad = {}
        for name, mode in (("thumb", capstone.CS_MODE_THUMB), ("arm", capstone.CS_MODE_ARM)):
            md = capstone.Cs(capstone.CS_ARCH_ARM, mode)
            step = 2 if name == "thumb" else 4
            n = len(blob) // step
            got = sum(1 for _ in md.disasm(blob, 0))
            bad[name] = n - got
        if bad["thumb"] == bad["arm"]:
            # Both decode cleanly, which is normal for short accessors: four
            # bytes of Thumb are usually also a legal ARM word. Terminators
            # break the tie -- `bx lr` is 7047 in Thumb and e12fff1e in ARM --
            # and failing that the game's dominant mode wins, because calling
            # a Thumb function ARM makes the linker emit BLX and costs a byte
            # in every caller.
            if blob[-4:] == b"\x1e\xff\x2f\xe1":
                thumb = False
            elif blob[-2:] == b"\x70\x47" or b"\x70\x47" in blob:
                thumb = True
            else:
                thumb = True
        else:
            thumb = bad["thumb"] < bad["arm"]
        if min(bad.values()) > len(blob) // 8:
            return ("thumb" if thumb else "arm"), "data"

    mode = "thumb" if thumb else "arm"
    if len(blob) <= 8:
        return mode, "trivial"
    return mode, mode


def main():
    manifest = json.load(open(os.path.join(REF, "manifest.json")))
    fns = json.load(open(os.path.join(REF, "functions.json")))
    out = {}
    counts = {}
    for mod, lst in fns.items():
        if mod not in manifest:
            continue
        data = open(os.path.join(REF, mod + ".bin"), "rb").read()
        base = manifest[mod]["ram"]
        rows = []
        for f in lst:
            off = f["ram"] - base
            size = f["size"] or 8
            if off < 0 or off >= len(data):
                rows.append(dict(f, mode="?", kind="oob"))
                counts["oob"] = counts.get("oob", 0) + 1
                continue
            blob = data[off:off + min(size, len(data) - off)]
            mode, kind = classify(blob)
            # An explicit `status: "data"` in the claim table outranks the byte
            # heuristic. classify() only sees the first `size` bytes, so a
            # rodata block whose leading words happen to be a jump table of
            # odd (Thumb) function pointers decodes as clean Thumb and gets
            # called code -- ov094's 0x02209F30 command table is exactly that.
            # The verifier then stamps Thumb bits into ABS32 words that point
            # into the block. This is the durable place to record the
            # correction: triage.json is regenerated from the claim table, so
            # anything recorded only in triage.json is lost on the next run.
            if f.get("status") == "data":
                kind = "data"
            # An explicit `mode` on the claim-table row overrides the byte
            # heuristic, the same way `status: "data"` overrides `kind`.
            # classify() cannot always win: ov170's sub_021DEFEC is a 12-byte
            # tail-call thunk whose literal makes the ARM decode look cleaner,
            # and a wrong mode there makes every caller encode BLX where the
            # ROM has BL. Recording the correction on the claim-table row is
            # the only form that survives regeneration.
            if f.get("mode") in ("arm", "thumb"):
                mode = f["mode"]
                if kind in ("arm", "thumb"):
                    kind = mode
            rows.append(dict(f, mode=mode, kind=kind))
            counts[kind] = counts.get(kind, 0) + 1
        out[mod] = rows
    with open(os.path.join(REF, "triage.json"), "w") as fh:
        json.dump(out, fh)
    total = sum(counts.values())
    print(f"triaged {total} entries across {len(out)} modules")
    for k in sorted(counts, key=lambda k: -counts[k]):
        print(f"  {k:9s} {counts[k]:6d}  {100.0 * counts[k] / total:5.1f}%")
    real = counts.get("thumb", 0) + counts.get("arm", 0)
    print(f"\nreal C functions to decompile: {real}")


if __name__ == "__main__":
    main()
