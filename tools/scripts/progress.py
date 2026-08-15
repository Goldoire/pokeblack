#!/usr/bin/env python3
"""Report verified progress per module against the claim table.

Truth is the verifier, not bookkeeping: a function counts only if its compiled
bytes are identical to the ROM. This walks every object under build/src, keeps
the symbols that verify N/N, and totals them per module against
build/reference/functions.json.

  python tools/scripts/progress.py            # per-module table
  python tools/scripts/progress.py --json     # machine-readable
  python tools/scripts/progress.py --list     # every verified function

Objects that do not verify are counted separately as "pending" and never
reported as progress.
"""
import glob
import json
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from verify_functions import MODULE_RE, Obj, verify_function  # noqa: E402

REF = "build/reference"


def collect():
    manifest = json.load(open(os.path.join(REF, "manifest.json")))
    refs = {}
    verified = {}   # module -> {ram: (name, size)}
    pending = []
    for path in sorted(glob.glob("build/src/**/*.o", recursive=True)):
        norm = path.replace("\\", "/")
        m = MODULE_RE.search(norm)
        module = m.group(1) if m and m.group(1) in manifest else "main"
        if module not in refs:
            refs[module] = open(os.path.join(REF, module + ".bin"), "rb").read()
        ref = refs[module]
        try:
            obj = Obj(path)
        except Exception:
            continue
        for sym in obj.symtab:
            if sym["typ"] != 2 or sym["size"] == 0:
                continue
            # Only the real-RAM base counts. The verifier also tries the legacy
            # Ghidra base (+0x4000) so it can grade old artifacts, but a short
            # function can match at a bogus address under the wrong base --
            # `bx lr` matches almost anywhere -- and that must never be scored
            # as progress.
            best = verify_function(obj, sym, ref, 0, manifest[module]["ram"], module)
            if best is None:
                continue
            score, total, masked_b, off, _d = best
            if total and score == total:
                verified.setdefault(module, {})[manifest[module]["ram"] + off] = (
                    sym["name"], sym["size"], masked_b)
            else:
                pending.append((module, sym["name"], score, total))
    return verified, pending


def main():
    fns = json.load(open(os.path.join(REF, "functions.json")))
    verified, pending = collect()

    rows = []
    stray = []
    for mod, lst in fns.items():
        n_tot = len(lst)
        b_tot = sum(f["size"] for f in lst)
        sdk = [f for f in lst if f["status"].startswith("matched_sdk")]
        by_ram = {f["ram"]: f["size"] for f in lst}
        v = verified.get(mod, {})
        # A verified symbol only counts if it lands on a claim-table entry --
        # otherwise it is a coincidental byte match at an address nobody
        # claimed, which is not progress against the total.
        for a in sorted(set(v) - set(by_ram)):
            stray.append((mod, v[a][0], a))
        v = {a: t for a, t in v.items() if a in by_ram}
        # A hand-written match and an SDK match at the same address are one
        # function; union by address so nothing is double counted.
        addrs = {f["ram"] for f in sdk} | set(v)
        b_done = sum(by_ram.get(a, 0) for a in addrs)
        rows.append(dict(module=mod, fns=n_tot, bytes=b_tot, done=len(addrs),
                         done_bytes=b_done, hand=len(v), sdk=len(sdk)))

    # Append a history point so the climb can be plotted. One line per run,
    # deduped on the totals so repeated polling does not pad the curve.
    hist_path = os.path.join(REF, "progress_history.jsonl")
    point = dict(t=int(time.time()),
                 fns=sum(r["done"] for r in rows),
                 bytes=sum(r["done_bytes"] for r in rows),
                 hand=sum(r["hand"] for r in rows))
    last = None
    if os.path.exists(hist_path):
        with open(hist_path) as fh:
            for line in fh:
                line = line.strip()
                if line:
                    last = json.loads(line)
    if not last or (last["fns"], last["bytes"]) != (point["fns"], point["bytes"]):
        with open(hist_path, "a") as fh:
            fh.write(json.dumps(point) + "\n")

    if "--json" in sys.argv:
        print(json.dumps(dict(modules=rows, total=point), indent=1))
        return
    if "--list" in sys.argv:
        for mod in sorted(verified):
            for ram, (name, size, mk) in sorted(verified[mod].items()):
                flag = f"  ({mk}B unchecked)" if mk else ""
                print(f"{mod:7s} {ram:#010x} {size:6d}  {name}{flag}")
        return

    rows.sort(key=lambda r: -r["bytes"])
    tf = sum(r["fns"] for r in rows)
    tb = sum(r["bytes"] for r in rows)
    df = sum(r["done"] for r in rows)
    db = sum(r["done_bytes"] for r in rows)
    th = sum(r["hand"] for r in rows)

    print(f"{'module':8}{'fns':>7}{'done':>7}{'hand':>6}{'bytes':>10}{'matched':>10}{'%':>7}")
    for r in rows:
        if not r["done"] and r["bytes"] < 20000:
            continue
        pct = 100.0 * r["done_bytes"] / r["bytes"] if r["bytes"] else 0.0
        print(f"{r['module']:8}{r['fns']:7}{r['done']:7}{r['hand']:6}"
              f"{r['bytes']:10}{r['done_bytes']:10}{pct:6.2f}%")
    print(f"\nTOTAL   {tf:7}{df:7}{th:6}{tb:10}{db:10}{100.0 * db / tb:6.2f}%")
    print(f"  {df} of {tf} functions verified ({th} hand-written, {df - th} SDK)")
    print(f"  {db} of {tb} bytes verified")
    part = [(m, a, t) for m, d in verified.items() for a, t in d.items() if t[2]]
    if part:
        mb = sum(t[2] for _, _, t in part)
        print(f"  caveat: {len(part)} of those functions have {mb} bytes never "
              f"compared -- references to .bss/.data/local symbols whose "
              f"addresses are\n          only fixed at link time. Object-level "
              f"verification cannot close these; only a real link can.")
    if stray:
        print(f"\n{len(stray)} verified symbols off the claim table (not counted):")
        for mod, name, a in stray[:8]:
            print(f"  {mod:7s} {name:40s} {a:#010x}")
    if pending:
        print(f"\n{len(pending)} object symbols NOT verified (not counted):")
        for mod, name, s, t in pending[:12]:
            print(f"  {mod:7s} {name:40s} {s}/{t}")
        if len(pending) > 12:
            print(f"  ... and {len(pending) - 12} more")


if __name__ == "__main__":
    main()
