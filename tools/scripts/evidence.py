#!/usr/bin/env python3
"""Harvest struct evidence out of already-verified functions.

Every byte-exact accessor is a proof: `ldr r0,[r0,#0x14]` in a function that
verifies N/N says field 0x14 of whatever the first argument points at is four
bytes wide and is read. Hundreds of those proofs are currently scattered across
one-function files where nothing can use them. This collects them.

Two passes:

  proven   -- disassemble each verified function out of its reference binary
              and record every load/store at a constant offset from an
              untouched incoming argument register. This is ground truth: the
              function matched the ROM byte for byte.
  declared -- scrape `typedef struct UnkStruct...` blocks out of src/**/*.c.
              These are worker interpretations. Where two files declare the
              same struct they are flagged, because that is the duplicate the
              integrator has to reconcile.

  python tools/scripts/evidence.py                 # summary
  python tools/scripts/evidence.py --module ov021  # one module, offset detail
  python tools/scripts/evidence.py --dupes         # only conflicting declarations
  python tools/scripts/evidence.py --json out.json

Output groups accessors into contiguous address runs: a run of adjacent small
functions is almost always the accessor set of one struct, which is the unit
worth naming.
"""
import collections
import glob
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
sys.path.insert(0, r"C:\Users\pranav\AppData\Local\Programs\Python\Python313\Lib\site-packages")
import capstone  # noqa: E402

import progress  # noqa: E402

REF = "build/reference"
ARGS = {"r0": 0, "r1": 1, "r2": 2, "r3": 3}
WIDTH = {"ldr": 4, "str": 4, "ldrh": 2, "strh": 2, "ldrsh": 2,
         "ldrb": 1, "strb": 1, "ldrsb": 1}
MEMOP = re.compile(r"^\[(r\d+|sl|fp|ip|sp), #(-?(?:0x)?[0-9a-fA-F]+)\]$")


def proven_accesses(blob, ram, thumb):
    """Loads/stores at a constant offset from an argument register that has
    not been overwritten since function entry. Crude liveness, but accessors
    are short and it does not guess: a register is dropped the moment anything
    writes to it."""
    md = capstone.Cs(capstone.CS_ARCH_ARM,
                     capstone.CS_MODE_THUMB if thumb else capstone.CS_MODE_ARM)
    md.detail = True
    live = dict(ARGS)          # reg name -> argument index, while still intact
    out = []
    for ins in md.disasm(blob, ram):
        mnem = ins.mnemonic.split(".")[0]
        base = WIDTH.get(mnem)
        ops = ins.op_str.split(", ", 1)
        if base and len(ops) == 2:
            m = MEMOP.match(ops[1])
            if m and m.group(1) in live:
                off = int(m.group(2), 0)
                if off >= 0:
                    out.append(dict(arg=live[m.group(1)], off=off, width=base,
                                    store=mnem.startswith("str"), at=ins.address))
        # Anything written invalidates that register as an argument.
        try:
            _, regs_written = ins.regs_access()
        except Exception:
            regs_written = []
        for r in regs_written:
            nm = ins.reg_name(r)
            live.pop(nm, None)
        if mnem in ("bl", "blx", "bx"):
            live.clear()        # after a call the argument regs are gone
    return out


def scrape_declared():
    """typedef struct <Name> { ... } from worker sources, with the fields."""
    decls = collections.defaultdict(list)   # name -> [(path, [(type,field)])]
    pat = re.compile(
        r"typedef\s+struct\s+(\w+)\s*\{(.*?)\}\s*\w*\s*;", re.S)
    field = re.compile(r"^\s*((?:const\s+)?[A-Za-z_]\w*\s*\**)\s*(\w+)\s*(\[[^\]]*\])?\s*;")
    for path in glob.glob("src/**/*.c", recursive=True):
        norm = path.replace("\\", "/")
        if norm.count("/") < 2:
            continue            # legacy top-level src/*.c is not ground truth
        try:
            text = open(path, encoding="utf-8", errors="replace").read()
        except OSError:
            continue
        for m in pat.finditer(text):
            name, body = m.group(1), m.group(2)
            fields = []
            for line in body.splitlines():
                fm = field.match(line)
                if fm:
                    fields.append((fm.group(1).strip(), fm.group(2)))
            decls[name].append((norm, fields))
    return decls


def runs(addrs, gap=0x60):
    """Group sorted addresses into contiguous clusters."""
    out, cur = [], []
    for a in addrs:
        if cur and a - cur[-1] > gap:
            out.append(cur)
            cur = []
        cur.append(a)
    if cur:
        out.append(cur)
    return out


def main():
    argv = sys.argv[1:]
    only = None
    if "--module" in argv:
        only = argv[argv.index("--module") + 1]
    manifest = json.load(open(os.path.join(REF, "manifest.json")))
    triage = json.load(open(os.path.join(REF, "triage.json")))
    modes = {m: {f["ram"]: f["mode"] for f in lst} for m, lst in triage.items()}
    sizes = {m: {f["ram"]: f["size"] for f in lst} for m, lst in triage.items()}

    verified, _ = progress.collect()
    refs = {}
    ev = collections.defaultdict(list)      # module -> [(ram, accesses)]
    for mod, hits in verified.items():
        if only and mod != only:
            continue
        if mod not in refs:
            refs[mod] = open(os.path.join(REF, mod + ".bin"), "rb").read()
        data, base = refs[mod], manifest[mod]["ram"]
        for ram in sorted(hits):
            size = sizes.get(mod, {}).get(ram) or hits[ram][1]
            off = ram - base
            if off < 0 or off + size > len(data) or not size:
                continue
            thumb = modes.get(mod, {}).get(ram, "thumb") == "thumb"
            acc = proven_accesses(data[off:off + size], ram, thumb)
            if acc:
                ev[mod].append((ram, hits[ram][0], acc))

    decls = scrape_declared()
    dupes = {n: v for n, v in decls.items() if len(v) > 1}

    if "--json" in argv:
        out = argv[argv.index("--json") + 1]
        with open(out, "w") as fh:
            json.dump(dict(
                proven={m: [dict(ram=r, name=n, acc=a) for r, n, a in v]
                        for m, v in ev.items()},
                declared={n: [dict(file=f, fields=fl) for f, fl in v]
                          for n, v in decls.items()}), fh, indent=1)
        print(f"wrote {out}")
        return

    if "--dupes" in argv:
        if not dupes:
            print("no struct name is declared in more than one file")
            return
        print(f"{len(dupes)} struct names declared in more than one file:\n")
        for n, v in sorted(dupes.items()):
            print(f"  {n}")
            for path, fields in v:
                sig = ", ".join(f"{t} {f}" for t, f in fields[:6])
                print(f"    {path}  [{len(fields)} fields] {sig}")
            print()
        return

    total_acc = sum(len(a) for v in ev.values() for _, _, a in v)
    print(f"{total_acc} proven field accesses across "
          f"{sum(len(v) for v in ev.values())} verified functions\n")

    for mod in sorted(ev, key=lambda m: -len(ev[m])):
        by_addr = {r: a for r, _, a in ev[mod]}
        clusters = runs(sorted(by_addr))
        offs = collections.Counter()
        for a in by_addr.values():
            for x in a:
                if x["arg"] == 0:
                    offs[(x["off"], x["width"])] += 1
        print(f"{mod:7s} {len(by_addr):4d} fns  {len(clusters):3d} accessor runs  "
              f"{len(offs):3d} distinct arg0 field offsets")
        if only:
            for c in clusters:
                if len(c) < 2:
                    continue
                fields = {}
                for a in c:
                    for x in by_addr[a]:
                        if x["arg"] == 0:
                            cur = fields.get(x["off"])
                            fields[x["off"]] = max(cur or 0, x["width"])
                if not fields:
                    continue
                print(f"\n  run {c[0]:#010x}..{c[-1]:#010x}  ({len(c)} functions)")
                line = "  ".join(f"+{o:#05x}:{w}B" for o, w in sorted(fields.items()))
                print(f"    {line}")

    print()
    if dupes:
        print(f"{len(dupes)} struct names declared in more than one file "
              f"(run --dupes): {', '.join(sorted(dupes)[:6])}"
              f"{' ...' if len(dupes) > 6 else ''}")
    else:
        print("no duplicate struct declarations")
    print(f"{len(decls)} distinct struct names declared across worker sources")


if __name__ == "__main__":
    main()
