#!/usr/bin/env python3
"""Match Metrowerks Standard Library code against every module of the game.

Same idea as sdk_sweep.py, different vendor library. main 0x020923F0-0x0209D850
is not Game Freak code at all: it is MSL plus the CodeWarrior runtime, linked in
statically. pret's pokeheartgold already carries a hand-matched MSL under
lib/MSL_C -- 39 .s files and 2 .c files -- so if Black links the same MSL build
those bytes are already written and only need locating.

Phase 1 (--compile):
  * assemble lib/MSL_C/asm/*.s from pokeheartgold with THIS repo's mwasmarm.exe,
    using pokeheartgold's MWASFLAGS (its .s files `.include` asm/macros.inc and
    global.inc by paths relative to its own root, so the assembler is run with
    cwd = that root).  Library objects there are built with GLB_DEFINES, i.e.
    -DSDK_ARM9 -DSDK_CODE_ARM -DSDK_FINALROM.
  * compile lib/MSL_C/src/*.c with cc.py's flags plus pokeheartgold's lib/include.
  Objects land in build/msl_sweep/.

Phase 2 (default): byte-search every reference binary for each symbol's exact
body, masking relocation words.  The function sweep is sdk_sweep.sweep() called
verbatim with its output paths repointed; data symbols (ctype tables, the float
constants, the printf format tables) get the same treatment in sweep_data(),
because a chunk of that address range is tables rather than code.

Output: build/reference/msl_matches.json, sdk_matches.json's shape plus a
"kind" field ("func"/"data") and "source" (the pret file the symbol came from):
  [{name, object, source, kind, size, masked, hits: [{module, ram, offset}]}]

--near is a diagnostic, not a result: for every unmatched function it reports
the closest same-length window in main and how many bytes differ.  That is what
answers "is this a different MSL version or a different library entirely".

Usage:
  python tools/scripts/msl_sweep.py --compile   # once
  python tools/scripts/msl_sweep.py             # sweep + write results
  python tools/scripts/msl_sweep.py --near      # why the misses miss
"""
import glob
import json
import os
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sdk_sweep  # noqa: E402  (its sweep() is the matcher; do not duplicate it)
from verify_functions import Obj  # noqa: E402

# pokeheartgold checkout that supplies the MSL sources.  Override with --hg.
HG = os.environ.get("POKEHEARTGOLD", r"C:/Users/pranav/decomp/pokeheartgold")

MWAS = os.path.abspath("tools/mwccarm/dsi/1.1/mwasmarm.exe")
MWCC = os.path.abspath("tools/mwccarm/dsi/1.1/mwccarm.exe")
LICENSE = os.path.abspath("tools/mwccarm/license.dat")

OUT_DIR = "build/msl_sweep"
RESULTS = "build/reference/msl_matches.json"

# pokeheartgold common.mk MWASFLAGS, with DEFINES = GLB_DEFINES (config.mk:39):
# library objects there are ARM + SDK_FINALROM.  Paths are relative because the
# assembler runs with cwd = HG.
AS_FLAGS = ("-DSDK_ARM9 -DSDK_CODE_ARM -DSDK_FINALROM -proc arm5te -g -gccinc "
            "-i . -i ./include -i ./asm/include -i ./files -i ./lib/asm/include "
            "-i ./lib/NitroDWC/asm/include -i ./lib/MSL_C/asm/include "
            "-i ./lib/NitroSDK/asm/include -i ./lib/syscall/asm/include "
            "-i ./asm -i ./files/msgdata -I./lib/include -DSDK_ASM").split()

# cc.py's BASE, plus SDK_FINALROM (WORKER_GUIDE: the retail ARM9 is built with
# it and it reorders a TU's merged .bss) and pokeheartgold's lib/include, which
# is where MSL_C/stdlib.h lives.
CC_FLAGS = ("-DSDK_ARM9 -DSDK_CODE_ARM -DSDK_TS -DSDK_FINALROM -O4,p -sym on "
            "-enum int -lang c99 -Cpp_exceptions off -gccext,on -proc arm946e "
            "-msgstyle gcc -gccinc -ipa file -interworking -inline on,noauto "
            "-char signed").split()

# mwasmarm emits a file-local STT_FUNC alias per function for the DWARF line
# tables; it duplicates a real symbol byte for byte and would double every count.
SKIP_PREFIXES = ("_@DummyFn", "$a", "$t", "$d", ".dwarf")


def _env():
    return dict(os.environ, LM_LICENSE_FILE=LICENSE)


def compile_all():
    os.makedirs(OUT_DIR, exist_ok=True)
    for stale in glob.glob(OUT_DIR + "/*.o"):
        os.remove(stale)
    asm = sorted(glob.glob(os.path.join(HG, "lib/MSL_C/asm/*.s")))
    csrc = sorted(glob.glob(os.path.join(HG, "lib/MSL_C/src/*.c")))
    if not asm and not csrc:
        sys.exit(f"no MSL sources under {HG}/lib/MSL_C -- pass --hg <path>")
    outdir = os.path.abspath(OUT_DIR)
    ok = fail = 0
    for src in asm:
        rel = os.path.relpath(src, HG).replace(os.sep, "/")
        out = os.path.join(outdir, os.path.basename(src)[:-2] + ".o")
        r = subprocess.run([MWAS, *AS_FLAGS, "-o", out, rel],
                           capture_output=True, cwd=HG, env=_env())
        if r.returncode == 0 and os.path.exists(out):
            ok += 1
        else:
            fail += 1
            print(f"  !! {os.path.basename(src)}: "
                  f"{(r.stdout + r.stderr).decode(errors='replace').strip()[:200]}")
            if os.path.exists(out):
                os.remove(out)
    for src in csrc:
        out = os.path.join(outdir, "src__" + os.path.basename(src)[:-2] + ".o")
        r = subprocess.run([MWCC, *CC_FLAGS, "-I" + os.path.join(HG, "lib/include"),
                            "-c", "-o", out, src],
                           capture_output=True, cwd=HG, env=_env())
        if r.returncode == 0 and os.path.exists(out):
            ok += 1
        else:
            fail += 1
            print(f"  !! {os.path.basename(src)}: "
                  f"{(r.stdout + r.stderr).decode(errors='replace').strip()[:200]}")
    print(f"built {ok} MSL objects, {fail} failed, into {OUT_DIR}/")


def _modules():
    manifest = json.load(open("build/reference/manifest.json"))
    return manifest, {n: open(f"build/reference/{n}.bin", "rb").read() for n in manifest}


def _body_and_mask(obj, sym):
    code = bytes(obj.section_bytes(sym["shndx"])[sym["value"]:sym["value"] + sym["size"]])
    mask = set()
    for roff, _rtype, _rsym, _radd in obj.relocs.get(sym["shndx"], []):
        if sym["value"] <= roff < sym["value"] + sym["size"]:
            i = roff - sym["value"]
            mask.update(range(i, i + 4))
    return code, mask


def sweep_data():
    """sdk_sweep's matcher, pointed at STT_OBJECT symbols.

    MSL's footprint in the ARM9 is not all code: __ctype_map, the wctype and
    float tables and printf's dispatch arrays are several kilobytes of the range
    this sweep is meant to attribute, and they relocate the same way.
    """
    manifest, modules = _modules()
    out = []
    for path in sorted(glob.glob(OUT_DIR + "/*.o")):
        try:
            obj = Obj(path)
        except Exception:
            continue
        for sym in obj.symtab:
            if sym["typ"] != 1 or sym["size"] < 16 or sym["shndx"] >= len(obj.sections):
                continue
            if sym["name"].startswith(SKIP_PREFIXES):
                continue
            sec = obj.sections[sym["shndx"]]
            if sec["type"] != 1 or not sec["size"]:       # skip .bss / NOBITS
                continue
            code, mask = _body_and_mask(obj, sym)
            anchor = next((a for a in range(0, max(1, len(code) - 8))
                           if not any(a + k in mask for k in range(8))), None)
            if anchor is None or len(code) < 8:
                continue
            pat = code[anchor:anchor + 8]
            hits = []
            for mod, ref in modules.items():
                pos = -1
                while True:
                    pos = ref.find(pat, pos + 1)
                    if pos < 0:
                        break
                    start = pos - anchor
                    if start < 0 or start + len(code) > len(ref):
                        continue
                    win = ref[start:start + len(code)]
                    if all(code[i] == win[i] for i in range(len(code)) if i not in mask):
                        hits.append(dict(module=mod, offset=start,
                                         ram=manifest[mod]["ram"] + start))
                        break
            if hits:
                out.append(dict(name=sym["name"], object=os.path.basename(path),
                                kind="data", size=sym["size"], masked=len(mask),
                                hits=hits))
    return out


NEAR = 0x2000     # a sibling this close is the same translation unit


def refine(results):
    """Replace each first-hit with the best-corroborated hit, and grade it.

    Two things sdk_sweep does not need but this sweep does.

    (1) It stops at the first occurrence per module.  MSL is full of 16-24 byte
    routines -- `ldr ip,[pc]; mov r1,#0; bx ip` is the whole of atod -- and the
    first occurrence of one of those is frequently not the real one.  rand.c is
    the worked example: srand's twelve comparable bytes occur three times in
    main, and the correct placement is the third, immediately after rand.

    (2) A short generic body needs corroboration before it counts.  A hit is
    graded `strong` when another function from the same pret file lands within
    8 KB of it in the same module with their relative order preserved -- i.e.
    the translation unit as a whole is there -- or when the body is long enough
    and rare enough (>=32 comparable bytes, sole occurrence in that module) to
    stand on its own.  Everything else is `weak` and is not evidence.
    """
    manifest, modules = _modules()
    bodies = {}
    objs = {}
    for r in results:
        path = os.path.join(OUT_DIR, r["object"])
        obj = objs.get(path) or objs.setdefault(path, Obj(path))
        sym = next(s for s in obj.symtab
                   if s["name"] == r["name"] and s["size"] == r["size"]
                   and s["typ"] in (1, 2))
        # Source order within the translation unit.  mwcc with -ipa file emits
        # one .text per function, so sym["value"] is 0 for every one of them and
        # only the section index orders them; the pret .s files put everything
        # in a single .text, where only the value does.  The pair handles both.
        bodies[id(r)] = ((sym["shndx"], sym["value"]), *_body_and_mask(obj, sym))

    # candidates[id(r)][module] = [offset, ...]
    cands = {}
    for r in results:
        _val, code, mask = bodies[id(r)]
        n = len(code)
        per = {}
        for mod, ref in modules.items():
            hitlist = []
            pos = -1
            while True:
                pos = ref.find(code[:4], pos + 1)
                if pos < 0 or pos + n > len(ref):
                    break
                if all(code[i] == ref[pos + i] for i in range(n) if i not in mask):
                    hitlist.append(pos)
            if hitlist:
                per[mod] = hitlist
        cands[id(r)] = per

    by_obj = {}
    for r in results:
        by_obj.setdefault(r["object"], []).append(r)

    for r in results:
        key, code, mask = bodies[id(r)]
        unmasked = len(code) - len(mask)
        hits = []
        for mod, offs in sorted(cands[id(r)].items()):
            best, best_score = offs[0], -1
            for p in offs:
                score = 0
                for other in by_obj[r["object"]]:
                    if other is r:
                        continue
                    after = bodies[id(other)][0] > key
                    for q in cands[id(other)].get(mod, []):
                        if q != p and abs(q - p) <= NEAR and (q > p) == after:
                            score += 1
                            break
                if score > best_score:
                    best, best_score = p, score
            conf = "strong" if (best_score > 0 or
                                (len(offs) == 1 and unmasked >= 32)) else "weak"
            hits.append(dict(module=mod, offset=best,
                             ram=manifest[mod]["ram"] + best,
                             occurrences=len(offs), confidence=conf))
        r["hits"] = hits
        r["unmasked"] = unmasked
        r["confidence"] = ("strong" if any(h["confidence"] == "strong" for h in hits)
                           else "weak")
    return results


def sweep():
    # Reuse sdk_sweep's function matcher verbatim -- same anchor + relocation
    # mask -- by repointing its input/output paths.
    sdk_sweep.OUT_DIR = OUT_DIR
    sdk_sweep.RESULTS = RESULTS
    sdk_sweep.sweep()
    funcs = [r for r in json.load(open(RESULTS))
             if not r["name"].startswith(SKIP_PREFIXES)]
    for r in funcs:
        r["kind"] = "func"
    results = refine(funcs + sweep_data())
    for r in results:
        stem = r["object"][:-2]
        r["source"] = ("lib/MSL_C/src/" + stem[5:] + ".c" if stem.startswith("src__")
                       else "lib/MSL_C/asm/" + stem + ".s")
    results.sort(key=lambda r: (r["source"], r["name"]))
    with open(RESULTS, "w") as f:
        json.dump(results, f, indent=1)

    strong = [r for r in results if r["confidence"] == "strong"]
    nf = sum(1 for r in strong if r["kind"] == "func")
    nd = len(strong) - nf
    print(f"\nMSL: {len(results)} symbols matched somewhere, {len(strong)} of them "
          f"corroborated ({nf} functions + {nd} data objects); "
          f"{len(results) - len(strong)} weak (short generic bodies, no sibling)")

    def main_hit(r):
        return next((h for h in r["hits"]
                     if h["module"] == "main" and h["confidence"] == "strong"), None)

    in_main = [(main_hit(r), r) for r in strong if main_hit(r)]
    lo, hi = 0x020923F0, 0x0209D850
    span = sum(r["size"] for h, r in in_main if lo <= h["ram"] < hi)
    print(f"  {len(in_main)} in main, {sum(r['size'] for _h, r in in_main)} bytes; "
          f"{span} of them inside {lo:#x}-{hi:#x} "
          f"({100.0 * span / (hi - lo):.1f}% of that range)")
    for h, r in sorted(in_main, key=lambda x: x[0]["ram"]):
        extra = sum(1 for x in r["hits"]
                    if x["module"] != "main" and x["confidence"] == "strong")
        print(f"  {h['ram']:#010x}  {r['size']:6d}  {r['kind']:4s}  {r['name'][:34]:34s} "
              f"{r['source']}" + (f"  (+{extra} overlays)" if extra else ""))
    weak = [r for r in results if r["confidence"] == "weak"]
    if weak:
        print("  weak, not counted: " + ", ".join(sorted(r["name"][:24] for r in weak)))


def near():
    """For each unmatched function, the best same-length window in main.

    A handful of bytes off across the board means Black links a different build
    of the same library; nothing under half the bytes matching means the routine
    simply is not there.
    """
    manifest, modules = _modules()
    ref = modules["main"]
    base = manifest["main"]["ram"]
    matched = set()
    if os.path.exists(RESULTS):
        matched = {r["name"] for r in json.load(open(RESULTS))}
    rows = []
    for path in sorted(glob.glob(OUT_DIR + "/*.o")):
        try:
            obj = Obj(path)
        except Exception:
            continue
        for sym in obj.symtab:
            if sym["typ"] != 2 or sym["size"] < 16 or sym["shndx"] >= len(obj.sections):
                continue
            if sym["name"].startswith(SKIP_PREFIXES) or sym["name"] in matched:
                continue
            code, mask = _body_and_mask(obj, sym)
            n = len(code)
            cmpi = [i for i in range(n) if i not in mask]
            # Anchor on the first instruction: a prologue is distinctive enough
            # to find the candidate, and everything after it is the diff.
            head = code[:4]
            best = (n, None)
            pos = -1
            while True:
                pos = ref.find(head, pos + 1)
                if pos < 0 or pos + n > len(ref):
                    break
                d = sum(1 for i in cmpi if code[i] != ref[pos + i])
                if d < best[0]:
                    best = (d, pos)
            rows.append((sym["name"], n, best[0], best[1], os.path.basename(path)))
    rows.sort(key=lambda r: (r[2] / max(1, r[1])))
    print(f"{'function':34s} {'size':>5s} {'diff':>5s} {'%same':>6s}  best window")
    for name, n, d, pos, obj in rows:
        where = f"{base + pos:#010x}" if pos is not None else "-"
        print(f"{name:34s} {n:5d} {d:5d} {100.0 * (n - d) / n:5.1f}%  {where}  {obj}")
    close = sum(1 for r in rows if r[1] and r[2] / r[1] < 0.15)
    print(f"\n{len(rows)} unmatched functions; {close} are >85% identical to a "
          f"window in main (same library, different build)")


def tu_map():
    """Where each pret MSL translation unit sits in main, exact match or not.

    The exact-match count understates the attribution badly.  Black links a
    slightly different build, so most functions land a few bytes off -- but a
    function that is 90% identical to a window in main, sitting next to another
    function from the same pret file in the same order, is the same function.
    Clustering those gives the address extent each MSL .c file occupies, which
    is the honest answer to "how much of this region is not Game Freak code".
    """
    manifest, modules = _modules()
    ref = modules["main"]
    base = manifest["main"]["ram"]
    total_span = total_bytes = 0
    print(f"{'pret file':32s} {'extent in main':>23s} {'funcs':>11s}  bytes")
    for path in sorted(glob.glob(OUT_DIR + "/*.o")):
        try:
            obj = Obj(path)
        except Exception:
            continue
        syms = [s for s in obj.symtab
                if s["typ"] == 2 and s["size"] >= 16 and s["shndx"] < len(obj.sections)
                and not s["name"].startswith(SKIP_PREFIXES)]
        syms.sort(key=lambda s: (s["shndx"], s["value"]))
        placed = []
        for s in syms:
            code, mask = _body_and_mask(obj, s)
            n = len(code)
            cmpi = [i for i in range(n) if i not in mask]
            best, pos = (n, None), -1
            while True:
                pos = ref.find(code[:4], pos + 1)
                if pos < 0 or pos + n > len(ref):
                    break
                d = sum(1 for i in cmpi if code[i] != ref[pos + i])
                if d < best[0]:
                    best = (d, pos)
            if best[1] is not None and best[0] <= 0.25 * len(cmpi):
                placed.append((base + best[1], n, best[0], s["name"]))
        # keep only functions with a same-file neighbour nearby: one lone 80%
        # window is a coincidence, two in a row is a translation unit
        keep = [p for p in placed
                if any(q is not p and abs(q[0] - p[0]) <= NEAR * 4 for q in placed)]
        if len(keep) < 2:
            continue
        lo = min(p[0] for p in keep)
        hi = max(p[0] + p[1] for p in keep)
        exact = sum(1 for p in keep if p[2] == 0)
        total_span += hi - lo
        total_bytes += sum(p[1] for p in keep)
        print(f"{os.path.basename(path)[:-2]:32s} {lo:#010x}-{hi:#010x} "
              f"{exact:4d}/{len(keep):<3d} exact {sum(p[1] for p in keep):6d}")
    print(f"\n{total_bytes} bytes of main sit in positively identified MSL "
          f"translation units, spanning {total_span} bytes of address space")


if __name__ == "__main__":
    argv = sys.argv[1:]
    if "--hg" in argv:
        HG = argv[argv.index("--hg") + 1]
    if "--compile" in argv:
        compile_all()
    elif "--near" in argv:
        near()
    elif "--map" in argv:
        tu_map()
    else:
        sweep()
