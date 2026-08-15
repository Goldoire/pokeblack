#!/usr/bin/env python3
"""Emit src/ov093 files for the repeated wrapper/table-getter shapes."""
import glob, json, os, re, sys

REPO = r"C:\Users\pranav\decomp\pokeblack\repo"
REF = os.path.join(REPO, "build", "reference")
man = json.load(open(os.path.join(REF, "manifest.json")))
tri = json.load(open(os.path.join(REF, "triage.json")))
mod = "ov093"
base = man[mod]["ram"]
data = open(os.path.join(REF, mod + ".bin"), "rb").read()
end_ram = base + len(data)
GAP = int(sys.argv[1], 0) if len(sys.argv) > 1 else 0x1000
LIMIT = int(sys.argv[2], 0) if len(sys.argv) > 2 else 10**9

taken = set()
for f in glob.glob(os.path.join(REPO, "src", "ov093", "*.c")):
    for m in re.finditer(r"\bsub_([0-9A-F]{8})\b", open(f, encoding="utf-8").read()):
        taken.add(int(m.group(1), 16))

starts = set(f["ram"] for f in tri[mod])
n = len(data)
p = 0
while p + 4 <= n:
    h = int.from_bytes(data[p:p + 2], "little")
    l = int.from_bytes(data[p + 2:p + 4], "little")
    if (h & 0xF800) == 0xF000 and (l & 0xE000) == 0xE000:
        imm = ((h & 0x7FF) << 12) | ((l & 0x7FF) << 1)
        if imm & 0x400000:
            imm -= 0x800000
        pc = base + p + 4
        t = ((pc & ~3) + imm) if (l & 0xF800) == 0xE800 else (pc + imm)
        if base <= (t & 0xFFFFFFFF) < end_ram:
            starts.add(t & 0xFFFFFFFF)
        p += 4
        continue
    p += 2
for off in range(0, n - 3, 4):
    v = int.from_bytes(data[off:off + 4], "little")
    if (v & 1) and base <= (v & ~1) < end_ram:
        starts.add(v & ~1)
S = sorted(starts)


def lit(b, off, h):
    return b[off:off + len(h) // 2].hex() == h


def is_bl(addr):
    o = addr - base
    h = int.from_bytes(data[o:o + 2], "little")
    l = int.from_bytes(data[o + 2:o + 4], "little")
    return (h & 0xF800) == 0xF000 and (l & 0xE000) == 0xE000


def bl_target(addr):
    o = addr - base
    h = int.from_bytes(data[o:o + 2], "little")
    l = int.from_bytes(data[o + 2:o + 4], "little")
    imm = ((h & 0x7FF) << 12) | ((l & 0x7FF) << 1)
    if imm & 0x400000:
        imm -= 0x800000
    pc = addr + 4
    if (l & 0xF800) == 0xE800:
        return ((pc & ~3) + imm) & 0xFFFFFFFF
    return (pc + imm) & 0xFFFFFFFF


rows = []
for i, a in enumerate(S):
    if a in taken:
        continue
    e = S[i + 1] if i + 1 < len(S) else end_ram
    sz = e - a
    b = data[a - base:e - base]
    hx = b.hex()
    nm = f"sub_{a:08X}"
    c = decl = None
    ext = None
    call = None
    call2 = None
    if sz == 12 and hx[2:16] == "21016000487047":
        val = int(hx[0:2], 16)
        lit = int.from_bytes(b[8:12], "little")
        ext = lit
        c = (f"const u8 *{nm}(int *count)\n{{\n    *count = {val};\n"
             f"    return _{lit:08X};\n}}")
    elif sz == 16 and hx[:8] == "18b581b0" and hx[10:16] == "240094" and hx[24:] == "01b018bd":
        v = int(hx[8:10], 16)
        t = bl_target(a + 8)
        call = (t, 5)
        c = (f"void {nm}(void *a0, void *a1, int a2, void *a3)\n{{\n"
             f"    sub_{t:08X}(a0, a1, a2, a3, {v});\n}}")
    elif sz == 24 and hx[:20] == "18b581b09c69002c03d0" and hx[22:28] == "240094" and hx[36:] == "01b018bd0000":
        v = int(hx[20:22], 16)
        t = bl_target(a + 14)
        call = (t, 5)
        c = (f"void {nm}(void *a0, void *a1, int a2, UnkOwner *a3)\n{{\n"
             f"    if (a3->unk_18 != NULL) {{\n"
             f"        sub_{t:08X}(a0, a1, a2, a3, {v});\n    }}\n}}")
    elif sz == 16 and hx[:12] == "08b5081c111c" and hx[14:16] == "22" and hx[18:20] == "23" and hx[28:] == "08bd":
        v2 = int(hx[12:14], 16)
        v3 = int(hx[16:18], 16)
        t = bl_target(a + 10)
        call = (t, 4)
        c = (f"void {nm}(void *a0, void *a1, void *a2)\n{{\n"
             f"    sub_{t:08X}(a1, a2, {v2}, {v3});\n}}")
    elif (sz in (20, 24) and hx[:8] == "10b582b0" and hx[10:16] == "240094"
          and hx[18:24] == "240194" and hx[32:40] == "02b010bd"
          and hx[40:] in ("", "0000", "00000000")):
        v4 = int(hx[8:10], 16)
        v5 = int(hx[16:18], 16)
        t = bl_target(a + 12)
        call = (t, 6)
        c = (f"void {nm}(void *a0, void *a1, int a2, void *a3)\n{{\n"
             f"    sub_{t:08X}(a0, a1, a2, a3, {v4}, {v5});\n}}")
    elif (sz == 24 and hx[:4] == "10b5" and hx[6:12] == "20141c"
          and hx[20:28] == "844203d1" and hx[30:32] == "20" and hx[34:36] == "21"
          and hx[44:] == "10bd"):
        vN = int(hx[4:6], 16)
        vM = int(hx[28:30], 16)
        vK = int(hx[32:34], 16)
        t = bl_target(a + 6)
        t2 = bl_target(a + 18)
        call = (t, 101)
        call2 = (t2, 102)
        c = (f"void {nm}(void *a0, void *a1, int a2)\n{{\n"
             f"    if (a2 == sub_{t:08X}({vN})) {{\n"
             f"        sub_{t2:08X}({vM}, {vK});\n    }}\n}}")
    elif (sz == 24 and hx[:8] == "38b5051c" and hx[10:16] == "20141c"
          and hx[24:36] == "844202d1281c" and hx[44:] == "38bd"):
        vN = int(hx[8:10], 16)
        t = bl_target(a + 8)
        t2 = bl_target(a + 18)
        call = (t, 101)
        call2 = (t2, 103)
        c = (f"void {nm}(void *a0, void *a1, int a2)\n{{\n"
             f"    if (a2 == sub_{t:08X}({vN})) {{\n"
             f"        sub_{t2:08X}(a0);\n    }}\n}}")
    elif sz == 16 and hx[:16] == "08b5081c111c1a1c" and hx[18:20] == "23" and hx[28:] == "08bd":
        vN = int(hx[16:18], 16)
        t = bl_target(a + 10)
        call = (t, 4)
        c = (f"void {nm}(void *a0, void *a1, void *a2, int a3)\n{{\n"
             f"    sub_{t:08X}(a1, a2, a3, {vN});\n}}")
    elif (sz == 20 and hx[:4] == "08b5" and hx[12:20] == "002801d1"
          and hx[22:24] == "20" and hx[24:28] == "08bd" and hx[30:32] == "20"
          and hx[32:] == "08bd0000"):
        vN = int(hx[20:22], 16)
        vM = int(hx[28:30], 16)
        t = bl_target(a + 2)
        call = (t, 105)
        c = (f"int {nm}(void *a0)\n{{\n    if (sub_{t:08X}(a0) == 0) {{\n"
             f"        return {vN};\n    }}\n    return {vM};\n}}")
    elif sz == 20 and hx[:12] == "10b5081c111c" and hx[14:20] == "221c1c" and hx[28:] == "206010bd0000":
        vN = int(hx[12:14], 16)
        t = bl_target(a + 10)
        call = (t, 104)
        c = (f"void {nm}(void *a0, void *a1, void *a2, u32 *a3)\n{{\n"
             f"    *a3 = sub_{t:08X}(a1, a2, {vN});\n}}")
    elif (sz == 36 and lit(b, 0, "f8b5051c") and b[5] == 0x20
          and lit(b, 6, "0e1c141c1f1c") and is_bl(a + 12)
          and lit(b, 16, "844205d1281c311c221c3b1c") and is_bl(a + 28)
          and lit(b, 32, "f8bd0000")):
        vN = b[4]
        t = bl_target(a + 12)
        t2 = bl_target(a + 28)
        call = (t, 101)
        call2 = (t2, 4)
        c = (f"void {nm}(void *a0, void *a1, int a2, int a3)\n{{\n"
             f"    if (a2 == sub_{t:08X}({vN})) {{\n"
             f"        sub_{t2:08X}(a0, a1, a2, a3);\n    }}\n}}")
    elif (sz == 32 and lit(b, 0, "10b5141c216840680906090e") and is_bl(a + 12)
          and lit(b, 16, "61680904090c") and is_bl(a + 22)
          and b[27] == 0x20 and lit(b, 28, "10bd0000")):
        vN = b[26]
        t = bl_target(a + 12)
        t2 = bl_target(a + 22)
        call = (t, 110)
        call2 = (t2, 111)
        c = (f"int {nm}(UnkCtx *a0, void *a1, u32 *a2)\n{{\n"
             f"    sub_{t2:08X}(sub_{t:08X}(a0->unk_04, (u8)a2[0]), (u16)a2[1]);\n"
             f"    return {vN};\n}}")
    elif (sz == 24 and lit(b, 0, "08b5116840680906090e") and is_bl(a + 10)
          and is_bl(a + 14) and b[19] == 0x20 and lit(b, 20, "08bd0000")):
        vN = b[18]
        t = bl_target(a + 10)
        t2 = bl_target(a + 14)
        call = (t, 110)
        call2 = (t2, 112)
        c = (f"int {nm}(UnkCtx *a0, void *a1, u32 *a2)\n{{\n"
             f"    sub_{t2:08X}(sub_{t:08X}(a0->unk_04, (u8)a2[0]));\n"
             f"    return {vN};\n}}")
    elif (sz == 28 and lit(b, 0, "10b5141c216840680906090e") and is_bl(a + 12)
          and lit(b, 16, "6168") and is_bl(a + 18) and b[23] == 0x20
          and lit(b, 24, "10bd0000")):
        vN = b[22]
        t = bl_target(a + 12)
        t2 = bl_target(a + 18)
        call = (t, 110)
        call2 = (t2, 113)
        c = (f"int {nm}(UnkCtx *a0, void *a1, u32 *a2)\n{{\n"
             f"    sub_{t2:08X}(sub_{t:08X}(a0->unk_04, (u8)a2[0]), a2[1]);\n"
             f"    return {vN};\n}}")
    elif (sz == 16 and lit(b, 0, "024b081c111c") and b[7] == 0x22
          and lit(b, 8, "1847c046")):
        vN = b[6]
        t = int.from_bytes(b[12:16], "little") & ~1
        call = (t, 114)
        c = (f"void {nm}(void *a0, void *a1, void *a2)\n{{\n"
             f"    sub_{t:08X}(a1, a2, {vN});\n}}")
    elif (sz == 36 and lit(b, 0, "38b50d1c141c281c211c") and b[11] == 0x22
          and is_bl(a + 12) and lit(b, 16, "280005d0281c211c") is False
          and lit(b, 16, "002805d0281c211c") and b[25] == 0x22 and b[27] == 0x23
          and is_bl(a + 28) and lit(b, 32, "38bd0000")):
        vN = b[10]
        vM = b[24]
        vK = b[26]
        t = bl_target(a + 12)
        t2 = bl_target(a + 28)
        call = (t, 115)
        call2 = (t2, 116)
        c = (f"void {nm}(void *a0, void *a1, void *a2)\n{{\n"
             f"    if (sub_{t:08X}(a1, a2, {vN}) != 0) {{\n"
             f"        sub_{t2:08X}(a1, a2, {vM}, {vK});\n    }}\n}}")
    elif sz == 4 and hx == "70470000":
        c = f"void {nm}(void)\n{{\n}}"
    elif sz == 4 and hx[2:] == "207047":
        c = f"int {nm}(void)\n{{\n    return {int(hx[0:2], 16)};\n}}"
    elif sz == 8 and hx[:4] == "08b5" and hx[12:] == "08bd" and is_bl(a + 2):
        t = bl_target(a + 2)
        call = (t, 4)
        c = (f"void {nm}(void *a0, void *a1, int a2, int a3)\n{{\n"
             f"    sub_{t:08X}(a0, a1, a2, a3);\n}}")
    elif sz == 12 and hx[:4] == "08b5" and hx[6:8] == "23" and hx[16:] == "08bd0000":
        v3 = int(hx[4:6], 16)
        t = bl_target(a + 4)
        call = (t, 4)
        c = (f"void {nm}(void *a0, void *a1, int a2)\n{{\n"
             f"    sub_{t:08X}(a0, a1, a2, {v3});\n}}")
    elif sz == 12 and hx[:4] == "08b5" and hx[6:8] == "22" and hx[10:12] == "23" and hx[20:] == "08bd":
        v2 = int(hx[4:6], 16)
        v3 = int(hx[8:10], 16)
        t = bl_target(a + 6)
        call = (t, 4)
        c = (f"void {nm}(void *a0, void *a1)\n{{\n"
             f"    sub_{t:08X}(a0, a1, {v2}, {v3});\n}}")
    if c:
        rows.append((a, sz, c, ext, call, call2))

rows = rows[:LIMIT]
groups, cur = [], [rows[0]]
for r in rows[1:]:
    if r[0] - (cur[-1][0] + cur[-1][1]) <= GAP:
        cur.append(r)
    else:
        groups.append(cur)
        cur = [r]
groups.append(cur)

ARGS = {4: "void *a0, void *a1, int a2, int a3",
        5: "void *a0, void *a1, int a2, void *a3, int a4",
        6: "void *a0, void *a1, int a2, void *a3, int a4, int a5",
        101: "int a0",
        110: "void *a0, u8 a1",
        111: "u32 a0, u16 a1",
        112: "u32 a0",
        113: "u32 a0, u32 a1",
        114: "void *a0, void *a1, int a2",
        115: "void *a0, void *a1, int a2",
        116: "void *a0, void *a1, int a2, int a3",
        102: "int a0, int a1",
        103: "void *a0",
        105: "void *a0",
        104: "void *a0, void *a1, int a2"}

made = []
for g in groups:
    exts = sorted({r[3] for r in g if r[3] is not None})
    calls = {}
    for r in g:
        if r[4]:
            calls[r[4][0]] = r[4][1]
        if r[5]:
            calls[r[5][0]] = r[5][1]
    need_owner = any("UnkOwner" in r[2] for r in g)
    need_ctx = any("UnkCtx" in r[2] for r in g)
    path = os.path.join(REPO, "src", "ov093", f"unk_{g[0][0]:08X}.c")
    with open(path, "w", encoding="utf-8") as fp:
        fp.write("#include \"types.h\"\n\n")
        fp.write(f"// ov093 {g[0][0]:#010x}..{g[-1][0] + g[-1][1]:#010x}: per-effect wrapper\n"
                 "// shells and count/table getters.\n\n")
        if need_owner:
            fp.write("typedef struct UnkOwner {\n    /* 0x00 */ u8 unk_00[0x18];\n"
                     "    /* 0x18 */ void *unk_18;\n} UnkOwner;\n\n")
        if need_ctx:
            fp.write("typedef struct UnkCtx {\n"
                     "    /* 0x00 */ u32 unk_00;\n"
                     "    /* 0x04 */ void *unk_04;\n"
                     "} UnkCtx;\n\n")
        for e in exts:
            fp.write(f"extern const u8 _{e:08X}[];\n")
        if exts:
            fp.write("\n")
        for t in sorted(calls):
            if t in {r[0] for r in g}:
                continue
            rt = "u32 " if calls[t] in (101, 104, 105, 110, 112, 115) else "void "
            fp.write(f"{rt}sub_{t:08X}({ARGS[calls[t]]});\n")
        fp.write("\n")
        for a, sz, c, ext, call, call2 in g:
            fp.write(c + "\n\n")
    made.append((path, len(g)))
print(f"{len(rows)} functions in {len(made)} files")
for p_, k in made:
    print(f"  {os.path.basename(p_)} {k}")
