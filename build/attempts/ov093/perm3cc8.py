import io, itertools, json, os, subprocess, sys
REPO = r"C:\Users\pranav\decomp\pokeblack\repo"; os.chdir(REPO)
sys.path.insert(0, "tools/scripts"); import verify_functions as V
man = json.load(open("build/reference/manifest.json")); base = man["ov093"]["ram"]
ref = open("build/reference/ov093.bin", "rb").read()
SRC = "src/ov093/_try.c"; OBJ = "build/src/ov093/_try.o"
decls = {
 'a': "    u16 a = (u16)args[4];",
 'b': "    u16 b = (u16)args[5];",
 'c': "    u8 c = (u8)args[3];",
 'd': "    u8 d = (u8)args[1];",
 'e': "    u8 e = (u8)args[2];",
}
head = '''#include "ov093/battle.h"
void *sub_021B9934(BattleQueue *q, u8 a1);
void sub_021D6848(void *a0, void *a1);
typedef struct S { u16 unk_00; u16 unk_02; u8 unk_04; u8 unk_05; u8 unk_06; } S;
int sub_021D3CC8(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    S s;
    void *p = sub_021B9934(ctx->unk_04, (u8)args[0]);
'''
tail = '''
    s.unk_00 = a;
    s.unk_02 = b;
    s.unk_04 = c;
    s.unk_05 = d;
    s.unk_06 = e;
    sub_021D6848(p, &s);
    return 1;
}
'''
best = (0, None)
for perm in itertools.permutations("abcde"):
    body = head + "\n".join(decls[k] for k in perm) + tail
    io.open(SRC, "w", encoding="utf-8", newline="\n").write(body)
    r = subprocess.run([sys.executable, "tools/scripts/cc.py", SRC, "--thumb"], capture_output=True, text=True)
    if r.returncode: continue
    o = V.Obj(OBJ)
    for s in o.symtab:
        if s["typ"] == 2 and s["size"]:
            res = V.verify_function(o, s, ref, 0, base, "ov093")
            if res and res[0] > best[0]:
                best = (res[0], "".join(perm), res)
            if res and res[0] == res[1]:
                print("MATCH", "".join(perm)); os.remove(SRC); sys.exit()
print("best", best)
os.remove(SRC)
