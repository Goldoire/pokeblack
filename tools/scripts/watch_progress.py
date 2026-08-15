#!/usr/bin/env python3
"""Live verified-progress tracker. Re-verifies and redraws on an interval.

  python tools/scripts/watch_progress.py            # every 15s
  python tools/scripts/watch_progress.py 5          # every 5s
  python tools/scripts/watch_progress.py 5 --top 20

A full re-verify of every object costs about 0.1s, so polling fast is cheap
and does not compete with the compilers.

Shows the overall byte percentage, the climb since this watcher started, and
the modules that are actually moving. Every number comes from re-running the
byte verifier, so nothing here can drift from the ROM.

Ctrl-C to stop.
"""
import json
import os
import sys
import time

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import progress  # noqa: E402

REF = "build/reference"
BAR = 44


def snapshot():
    fns = json.load(open(os.path.join(REF, "functions.json")))
    verified, pending = progress.collect()
    rows = []
    for mod, lst in fns.items():
        by_ram = {f["ram"]: f["size"] for f in lst}
        sdk = {f["ram"] for f in lst if f["status"].startswith("matched_sdk")}
        v = {a for a in verified.get(mod, {}) if a in by_ram}
        addrs = sdk | v
        rows.append(dict(module=mod, fns=len(lst), bytes=sum(by_ram.values()),
                         done=len(addrs), done_bytes=sum(by_ram[a] for a in addrs),
                         hand=len(v)))
    return rows, len(pending)


def _unicode_ok():
    """This console is not guaranteed to be UTF-8 -- it is cp932 on the dev
    box -- so fall back to ASCII rather than dying on an encode error."""
    try:
        sys.stdout.reconfigure(encoding="utf-8")
        return True
    except Exception:
        pass
    try:
        "█".encode(sys.stdout.encoding or "ascii")
        return True
    except (UnicodeEncodeError, LookupError):
        return False


UNI = _unicode_ok()
FILL, HALF, EMPTY = ("█", "▌", "·") if UNI else ("#", "=", ".")


def bar(frac, width=BAR):
    full = int(frac * width)
    part = frac * width - full
    tip = "" if part < 0.34 else (HALF if part < 0.67 else FILL)
    return (FILL * full + tip).ljust(width, EMPTY)


def main():
    args = [a for a in sys.argv[1:]]
    top = 12
    if "--top" in args:
        i = args.index("--top")
        top = int(args[i + 1])
        del args[i:i + 2]
    interval = int(args[0]) if args else 15

    start = None
    t0 = time.time()
    while True:
        rows, pending = snapshot()
        tb = sum(r["bytes"] for r in rows)
        db = sum(r["done_bytes"] for r in rows)
        tf = sum(r["fns"] for r in rows)
        df = sum(r["done"] for r in rows)
        th = sum(r["hand"] for r in rows)
        if start is None:
            start = (df, db, th)

        os.system("cls" if os.name == "nt" else "clear")
        el = int(time.time() - t0)
        print(f"  pokeblack — verified against ROM        "
              f"elapsed {el // 3600:d}h{el % 3600 // 60:02d}m   every {interval}s")
        print()
        print(f"  {bar(db / tb)}  {100.0 * db / tb:6.3f}%")
        print()
        print(f"  bytes      {db:>9,} / {tb:,}      +{db - start[1]:,} this session")
        print(f"  functions  {df:>9,} / {tf:,}      +{df - start[0]:,} this session")
        print(f"  hand-written {th:>7,}                    "
              f"+{th - start[2]:,} this session")
        if el > 60 and db > start[1]:
            rate = (db - start[1]) / (el / 3600.0)
            print(f"  rate       {rate:>9,.0f} bytes/hour")
        print()

        movers = sorted((r for r in rows if r["hand"]), key=lambda r: -r["hand"])
        if movers:
            print(f"  {'module':8}{'hand':>6}{'done':>7}{'/ fns':>8}"
                  f"{'bytes':>11}{'':>3}%")
            for r in movers[:top]:
                pct = 100.0 * r["done_bytes"] / r["bytes"] if r["bytes"] else 0
                print(f"  {r['module']:8}{r['hand']:6}{r['done']:7}{r['fns']:8}"
                      f"{r['done_bytes']:11,}  {pct:6.2f}%")
        else:
            print("  no hand-written matches yet")
        if pending:
            print(f"\n  {pending} unverified objects (not counted)")
        sys.stdout.flush()
        time.sleep(interval)


if __name__ == "__main__":
    try:
        main()
    except KeyboardInterrupt:
        print()
