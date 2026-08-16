#!/usr/bin/env python3
"""Recover real function boundaries across every module of the claim table.

The claim table came from a prologue heuristic, so it systematically fuses
adjacent functions that do not open with a recognisable prologue: 0x0202FBAC
is listed as one 116-byte entry and is really four 36-byte accessors, and
ov093 has entries that are 27 accessors wide. Three things break as a result:

  * a verified function whose address is not a listed start gets no credit,
    because progress.py can only score rows that exist;
  * an SDK sweep hit at such an address cannot be folded in either;
  * every fused row reports a size that is a lie, which distorts the byte
    denominator and sends workers at "small" functions that are not small.

This generalises build/attempts/ov093/recover_starts.py (ov093's work) to all
238 modules, and grades the evidence instead of pooling it:

  verified  a byte-exact hand match at that address   -- certain
  sdk       a byte-exact SDK/NNS sweep placement      -- certain
  callsite  a BL/BLX target                           -- very high
  ptr       an odd (Thumb-flagged) word-aligned pointer into the module's
            code -- high; this is what vtables and command tables look like

The callsite scan follows callsite_modes.py's discipline rather than the
ov093 script's: only bytes inside a known code extent are decoded, and only
in that extent's recorded mode. Scanning a whole module image linearly as
Thumb mines rodata for phantom branches, and a phantom start is not free --
it splits a real function and makes the halves unmatchable.

Guards, in addition:
  * a candidate strictly inside a *verified* function is dropped. We know
    that function's true extent, so anything inside it is a decode artifact.
  * a candidate inside a row marked `status: "data"` is dropped.
  * candidates must land in the module image, 2-byte aligned, and not on an
    existing start.

When a start splits a fused row, the parent is shrunk to end where the child
begins, so the same bytes are never counted twice.

  python tools/scripts/recover_starts.py                 # dry run, per-module
  python tools/scripts/recover_starts.py --write
  python tools/scripts/recover_starts.py --module ov093  # one module
  python tools/scripts/recover_starts.py --tiers verified,sdk,callsite
"""
import bisect
import glob
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from verify_functions import MODULE_RE, Obj, verify_function  # noqa: E402

REF = "build/reference"
ALL_TIERS = ("verified", "sdk", "callsite", "ptr")


# --------------------------------------------------------------------------
# evidence gathering
# --------------------------------------------------------------------------
def verified_starts(manifest):
    """{module: {ram: size}} for every function that verifies N/N OK."""
    out, refs = {}, {}
    for path in sorted(glob.glob("build/src/**/*.o", recursive=True)):
        norm = path.replace("\\", "/")
        m = MODULE_RE.search(norm)
        module = m.group(1) if m and m.group(1) in manifest else "main"
        if module not in refs:
            refs[module] = open(os.path.join(REF, module + ".bin"), "rb").read()
        try:
            obj = Obj(path)
        except Exception:
            continue
        for sym in obj.symtab:
            if sym["typ"] != 2 or sym["size"] == 0:
                continue
            r = verify_function(obj, sym, refs[module], 0, manifest[module]["ram"])
            if r is None:
                continue
            score, total, _masked, off, _d = r
            if total and score == total:
                out.setdefault(module, {})[manifest[module]["ram"] + off] = sym["size"]
    return out


def sdk_starts():
    """{module: {ram: size}} from both SDK sweeps."""
    out = {}
    for name in ("sdk_matches.json", "sdk_matches_thumb.json"):
        p = os.path.join(REF, name)
        if not os.path.exists(p):
            continue
        for e in json.load(open(p)):
            for h in e["hits"]:
                out.setdefault(h["module"], {}).setdefault(h["ram"], e["size"])
    return out


def thumb_bl_targets(blob, ram):
    i = 0
    while i + 4 <= len(blob):
        hi, lo = struct.unpack_from("<HH", blob, i)
        if (hi & 0xF800) == 0xF000 and (lo & 0xE800) == 0xE800:
            imm = ((hi & 0x7FF) << 12) | ((lo & 0x7FF) << 1)
            if imm & (1 << 22):
                imm -= 1 << 23
            pc = ram + i + 4
            yield (pc + imm) if (lo & 0xF800) == 0xF800 else (((pc & ~3) + imm) & ~1)
            i += 4
            continue
        i += 2


def arm_bl_targets(blob, ram):
    for i in range(0, len(blob) - 3, 4):
        w, = struct.unpack_from("<I", blob, i)
        if (w & 0xFE000000) == 0xFA000000:                         # BLX(1)
            imm = w & 0xFFFFFF
            if imm & 0x800000:
                imm -= 1 << 24
            yield ram + i + 8 + imm * 4 + ((w >> 24) & 1) * 2
        elif (w & 0x0F000000) == 0x0B000000 and (w >> 28) != 0xF:  # BL
            imm = w & 0xFFFFFF
            if imm & 0x800000:
                imm -= 1 << 24
            yield ram + i + 8 + imm * 4


# --------------------------------------------------------------------------
def repair_module(mod, rows, data, base, tri_rows, verified, sdk):
    """Return (new_start -> tier, clamped) for one module."""
    end_ram = base + len(data)
    rows = sorted(rows, key=lambda r: r["ram"])
    existing = {r["ram"] for r in rows}
    starts = sorted(existing)

    # rows we must not cut into
    protected = []                      # (lo, hi) of verified functions
    for ram, size in verified.get(mod, {}).items():
        protected.append((ram, ram + size))
    dead = []                           # (lo, hi) of declared data
    for r in rows:
        if r["status"] == "data" and r["size"]:
            dead.append((r["ram"], r["ram"] + r["size"]))
    kind = {t["ram"]: t.get("kind") for t in tri_rows}
    mode = {t["ram"]: t.get("mode") for t in tri_rows}
    for r in rows:
        # `kind: data` from triage is a HEURISTIC, and it fails in one
        # direction that matters here: classify() calls a blob data when more
        # than an eighth of it fails to decode, and any multi-kilobyte fused
        # row trips that on its literal pools alone. So the bigger the fused
        # row -- i.e. the more code it hides -- the more likely it is to be
        # mislabelled, and then skipped by exactly the pass that would break
        # it up. main's 0x02091588 was one 43652-byte "data" row over the
        # whole MSL region, and nothing had ever looked inside it.
        #
        # An explicit `status: "data"` is a declaration and is always honoured.
        # A heuristic `kind: data` is honoured only for small rows, where it is
        # usually right (ov094's 0x02209F30 jump table is 4080 bytes).
        if r["status"] == "data" and r["size"]:
            continue                        # already added above
        if kind.get(r["ram"]) == "data" and r["size"] and r["size"] <= 0x2000:
            dead.append((r["ram"], r["ram"] + r["size"]))
    protected.sort()
    dead.sort()

    def inside(spans, a):
        i = bisect.bisect_right(spans, (a, float("inf"))) - 1
        return i >= 0 and spans[i][0] < a < spans[i][1]

    def in_dead(a):
        i = bisect.bisect_right(dead, (a, float("inf"))) - 1
        return i >= 0 and dead[i][0] <= a < dead[i][1]

    cand = {}   # ram -> tier

    def offer(a, tier):
        if a in existing or a in cand:
            return
        if not (base <= a < end_ram) or (a & 1):
            return
        if inside(protected, a) or in_dead(a):
            return
        cand[a] = tier

    for ram, _sz in sorted(verified.get(mod, {}).items()):
        offer(ram, "verified")
    for ram, _sz in sorted(sdk.get(mod, {}).items()):
        offer(ram, "sdk")

    # callsite: decode only inside known code extents, in their own mode
    for i, r in enumerate(rows):
        k = kind.get(r["ram"])
        if k in ("oob", None) or r["status"] == "data":
            continue
        # Same asymmetry as above: a large heuristic-"data" row is far more
        # likely to be fused code than real rodata, and refusing to decode it
        # is what kept it invisible.
        if k == "data" and (r["size"] or 0) <= 0x2000:
            continue
        lo = r["ram"] - base
        hi = min(lo + (r["size"] or 0),
                 (rows[i + 1]["ram"] - base) if i + 1 < len(rows) else len(data),
                 len(data))
        if hi <= lo:
            continue
        blob = data[lo:hi]
        gen = arm_bl_targets if mode.get(r["ram"]) == "arm" else thumb_bl_targets
        for t in gen(blob, r["ram"]):
            offer(t, "callsite")

    # ptr: an odd word-aligned word pointing into the image is a Thumb
    # function pointer -- vtables, command tables, callback tables.
    for off in range(0, len(data) - 3, 4):
        v, = struct.unpack_from("<I", data, off)
        if v & 1 and base <= (v & ~1) < end_ram:
            offer(v & ~1, "ptr")

    return cand


def main():
    write = "--write" in sys.argv
    only = None
    if "--module" in sys.argv:
        only = sys.argv[sys.argv.index("--module") + 1]
    tiers = ALL_TIERS
    if "--tiers" in sys.argv:
        tiers = tuple(sys.argv[sys.argv.index("--tiers") + 1].split(","))

    manifest = json.load(open(os.path.join(REF, "manifest.json")))
    fns = json.load(open(os.path.join(REF, "functions.json")))
    try:
        tri = json.load(open(os.path.join(REF, "triage.json")))
    except (OSError, ValueError):
        tri = {}

    print("collecting verified functions ...", flush=True)
    verified = verified_starts(manifest)
    sdk = sdk_starts()

    tier_tot = dict.fromkeys(ALL_TIERS, 0)
    added_tot = clamped_tot = 0
    per_mod = []

    for mod in sorted(fns):
        if only and mod != only:
            continue
        if mod not in manifest:
            continue
        data = open(os.path.join(REF, mod + ".bin"), "rb").read()
        base = manifest[mod]["ram"]
        rows = fns[mod]
        cand = repair_module(mod, rows, data, base, tri.get(mod, []), verified, sdk)
        cand = {a: t for a, t in cand.items() if t in tiers}
        if not cand:
            continue
        for t in cand.values():
            tier_tot[t] += 1

        # splice in, shrinking any parent that a new start cuts
        rows.sort(key=lambda r: r["ram"])
        orig = [(r["ram"], r["ram"] + (r["size"] or 0)) for r in rows]
        starts = sorted(r["ram"] for r in rows)
        byram = {r["ram"]: r for r in rows}
        clamped = 0
        for a in sorted(cand):
            i = bisect.bisect_right(starts, a) - 1
            parent = byram[starts[i]] if i >= 0 else None
            cover_end = len(data) + base
            if parent is not None:
                pend = parent["ram"] + (parent["size"] or 0)
                if parent["ram"] < a < pend:
                    parent["size"] = a - parent["ram"]
                    cover_end = pend
                    clamped += 1
                else:
                    j = bisect.bisect_right(starts, a)
                    cover_end = starts[j] if j < len(starts) else cover_end
            row = dict(name="sub_%08X" % a, ram=a, size=0, status="unclaimed")
            rows.append(row)
            byram[a] = row
            bisect.insort(starts, a)
            row["_cover_end"] = cover_end

        # size every new row: to the next start, bounded by its coverage end
        rows.sort(key=lambda r: r["ram"])
        for i, r in enumerate(rows):
            if "_cover_end" not in r:
                continue
            nxt = rows[i + 1]["ram"] if i + 1 < len(rows) else base + len(data)
            r["size"] = max(0, min(nxt, r.pop("_cover_end")) - r["ram"])

        added_tot += len(cand)
        clamped_tot += clamped
        per_mod.append((mod, len(cand), clamped,
                        sum(1 for t in cand.values() if t == "verified"),
                        sum(1 for t in cand.values() if t == "sdk"),
                        sum(1 for t in cand.values() if t == "callsite"),
                        sum(1 for t in cand.values() if t == "ptr")))

    per_mod.sort(key=lambda r: -r[1])
    print(f"\n{'module':8}{'new':>7}{'clamp':>7}{'verif':>7}{'sdk':>6}{'call':>7}{'ptr':>7}")
    for row in per_mod[:30]:
        print(f"{row[0]:8}{row[1]:7}{row[2]:7}{row[3]:7}{row[4]:6}{row[5]:7}{row[6]:7}")
    if len(per_mod) > 30:
        print(f"  ... and {len(per_mod) - 30} more modules")
    print(f"\n{added_tot} new starts, {clamped_tot} fused rows shrunk")
    for t in ALL_TIERS:
        print(f"  {t:9s} {tier_tot[t]}")

    if not write:
        print("\n(dry run; pass --write to apply)")
        return
    for m in fns:
        fns[m].sort(key=lambda r: r["ram"])
    json.dump(fns, open(os.path.join(REF, "functions.json"), "w"), indent=1)
    chk = json.load(open(os.path.join(REF, "functions.json")))
    bad = [r for v in chk.values() for r in v
           if not set(r) <= {"name", "ram", "size", "status", "mode"}]
    print(f"\nwrote functions.json: {len(chk)} modules, "
          f"{sum(len(v) for v in chk.values())} rows, schema violations: {len(bad)}")


if __name__ == "__main__":
    main()
