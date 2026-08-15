#!/usr/bin/env python3
"""Reconcile the claim table's `status` field with what the verifier confirms.

Truth is verify_functions.py and nothing else:

  * an address that verifies N/N OK -> status "matched:<owner>", where <owner>
    is the source file that produced it (module/basename), so the claim table
    points at the C that matches;
  * a verified address with no row -> a row is appended. (recover_starts.py
    normally gets there first; this is the backstop.) The parent row it was
    fused into is shrunk to end where the new row begins, so the same bytes
    are never counted twice;
  * a row already marked "matched:*" that no longer verifies -> demoted to
    "unclaimed" and reported loudly. Never leave a lie in the table;
  * "matched_sdk", "claimed:*" and "data" rows are left alone unless they
    verify.

Nothing is ever marked matched on the strength of bookkeeping.

  python tools/scripts/reconcile.py            # report only
  python tools/scripts/reconcile.py --write    # apply
"""
import bisect
import glob
import json
import os
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from verify_functions import MODULE_RE, Obj, verify_function  # noqa: E402

REF = "build/reference"
FUNCS = os.path.join(REF, "functions.json")


def owner_of(obj_path):
    """build/src/ov021/unk_02197FC0.o -> ov021/unk_02197FC0"""
    norm = obj_path.replace("\\", "/")
    rel = norm[len("build/src/"):] if norm.startswith("build/src/") else norm
    return os.path.splitext(rel)[0]


def collect():
    manifest = json.load(open(os.path.join(REF, "manifest.json")))
    refs = {}
    verified = {}  # module -> {ram: (name, size, owner)}
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
            # Real-RAM base only. The legacy Ghidra base (+0x4000) can make a
            # short function "match" at a bogus address -- `bx lr` matches
            # almost anywhere -- and that must never become a claim.
            r = verify_function(obj, sym, refs[module], 0, manifest[module]["ram"])
            if r is None:
                continue
            score, total, _masked, off, _d = r
            if total and score == total:
                ram = manifest[module]["ram"] + off
                verified.setdefault(module, {})[ram] = (
                    sym["name"], sym["size"], owner_of(path))
    return verified


def main():
    write = "--write" in sys.argv
    fns = json.load(open(FUNCS))
    verified = collect()

    promoted, added, demoted, already, clamped = [], [], [], [], []

    for module, hits in sorted(verified.items()):
        rows = fns.setdefault(module, [])
        by_ram = {}
        for row in rows:
            by_ram.setdefault(row["ram"], row)
        starts = sorted(by_ram)
        for ram, (name, size, owner) in sorted(hits.items()):
            row = by_ram.get(ram)
            status = f"matched:{owner}"
            if row is None:
                i = bisect.bisect_right(starts, ram) - 1
                if i >= 0:
                    parent = by_ram[starts[i]]
                    end = parent["ram"] + parent["size"]
                    if parent["ram"] < ram < end:
                        clamped.append((module, parent["ram"], parent["size"],
                                        ram - parent["ram"]))
                        parent["size"] = ram - parent["ram"]
                rows.append(dict(name=name, ram=ram, size=size, status=status))
                by_ram[ram] = rows[-1]
                bisect.insort(starts, ram)
                added.append((module, ram, size, owner))
            elif row["status"].startswith("matched_sdk"):
                already.append((module, ram, owner))
            elif row["status"] != status:
                row["status"] = status
                promoted.append((module, ram, row["size"], owner))
        rows.sort(key=lambda r: r["ram"])

    for module, rows in fns.items():
        live = verified.get(module, {})
        for row in rows:
            if row["status"].startswith("matched:") and row["ram"] not in live:
                demoted.append((module, row["ram"], row["status"]))
                row["status"] = "unclaimed"

    tot_v = sum(len(h) for h in verified.values())
    print(f"verifier confirms {tot_v} functions across {len(verified)} modules")
    print(f"  promoted unclaimed -> matched  : {len(promoted)}")
    print(f"  appended (missing from table)  : {len(added)}")
    print(f"  already matched_sdk at same ram: {len(already)}")
    print(f"  demoted (no longer verifying)  : {len(demoted)}")
    print(f"  fused parent rows clamped      : {len(clamped)}")
    for module, ram, size, owner in added[:20]:
        print(f"    + {module:6s} {ram:#010x} {size:5d}  {owner}")
    for module, ram, status in demoted[:20]:
        print(f"    - {module:6s} {ram:#010x} was {status}")

    if not write:
        print("\n(dry run; pass --write to apply)")
        return
    json.dump(fns, open(FUNCS, "w"), indent=1)
    chk = json.load(open(FUNCS))
    bad = [r for v in chk.values() for r in v
           if not set(r) <= {"name", "ram", "size", "status", "mode"}]
    print(f"\nwrote {FUNCS}: {len(chk)} modules, "
          f"{sum(len(v) for v in chk.values())} rows, schema violations: {len(bad)}")


if __name__ == "__main__":
    main()
