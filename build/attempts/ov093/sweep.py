import io, json, os, subprocess, sys
REPO = r"C:\Users\pranav\decomp\pokeblack\repo"
os.chdir(REPO)
sys.path.insert(0, os.path.join(REPO, "tools", "scripts"))
import verify_functions as V
man = json.load(open("build/reference/manifest.json"))
base = man["ov093"]["ram"]; ref = open("build/reference/ov093.bin", "rb").read()
SRC = "src/ov093/_try.c"; OBJ = "build/src/ov093/_try.o"
body = io.open(sys.argv[1], encoding="utf-8").read()
io.open(SRC, "w", encoding="utf-8", newline="\n").write(body)
ccs = []
for fam in ("dsi", "2.0", "1.2"):
    for d in sorted(os.listdir(os.path.join("tools", "mwccarm", fam))):
        ccs.append(f"{fam}/{d}")
for cc in ccs:
    r = subprocess.run([sys.executable, "tools/scripts/cc.py", SRC, "--thumb", "--cc", cc],
                       capture_output=True, text=True)
    if r.returncode:
        print(f"{cc:16s} COMPILE FAIL"); continue
    obj = V.Obj(OBJ)
    out = []
    for sym in obj.symtab:
        if sym["typ"] != 2 or sym["size"] == 0: continue
        res = V.verify_function(obj, sym, ref, 0, base, "ov093")
        out.append(f"{sym['name']}={res[0]}/{res[1]}")
    print(f"{cc:16s} " + " ".join(out))
os.remove(SRC)
