#!/usr/bin/env python3
"""Try several candidate bodies for one ov093 function and report byte match.

  python build/attempts/ov093/try.py variants.py

`variants.py` must define PRELUDE (str), NAME (str) and VARIANTS (list of str,
each a complete function definition).  Each variant is compiled on its own into
src/ov093/_try.c and byte-compared against the ROM.
"""
import io, json, os, re, shutil, subprocess, sys

REPO = r"C:\Users\pranav\decomp\pokeblack\repo"
os.chdir(REPO)
sys.path.insert(0, os.path.join(REPO, "tools", "scripts"))
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))

spec = sys.argv[1]
ns = {}
exec(io.open(spec, encoding="utf-8").read(), ns)
PRELUDE, VARIANTS = ns["PRELUDE"], ns["VARIANTS"]
CC = ns.get("CC")

SRC = os.path.join(REPO, "src", "ov093", "_try.c")
OBJ = os.path.join(REPO, "build", "src", "ov093", "_try.o")

import verify_functions as V

man = json.load(open("build/reference/manifest.json"))
base = man["ov093"]["ram"]
ref = open("build/reference/ov093.bin", "rb").read()

for i, body in enumerate(VARIANTS):
    io.open(SRC, "w", encoding="utf-8", newline="\n").write(PRELUDE + "\n" + body + "\n")
    cmd = [sys.executable, "tools/scripts/cc.py", "src/ov093/_try.c", "--thumb"]
    if CC:
        cmd += ["--cc", CC]
    r = subprocess.run(cmd, capture_output=True, text=True)
    if r.returncode:
        print(f"[{i}] COMPILE FAIL\n{r.stdout}{r.stderr}")
        continue
    obj = V.Obj(OBJ)
    for sym in obj.symtab:
        if sym["typ"] != 2 or sym["size"] == 0:
            continue
        res = V.verify_function(obj, sym, ref, 0, base, "ov093")
        print(f"[{i}] {sym['name']}: {res}")

if os.path.exists(SRC):
    os.remove(SRC)
