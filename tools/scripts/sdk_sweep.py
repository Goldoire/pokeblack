#!/usr/bin/env python3
"""Match compiled TwlSDK library functions against every module of the game.

Phase 1 (--compile): compile every SDK library source under
  lib/NitroSDK/TwlSDK/build/libraries/**/src/*.c
with the game's exact MWCFLAGS into build/sdk_sweep/. Failures are skipped
(ARM7-only files, tool-only files, etc).

Phase 2 (default): for every function >=16 bytes in those objects, search all
reference binaries (build/reference/*.bin) for a byte-identical occurrence,
masking relocation words. A function may match in several modules (the SDK is
statically linked into overlays too); every hit is recorded.

Output: build/reference/sdk_matches.json
  [{name, object, size, masked, hits: [{module, ram, offset}]}]

Usage:
  python tools/scripts/sdk_sweep.py --compile   # once, or after flag changes
  python tools/scripts/sdk_sweep.py             # sweep + write results
"""
import glob
import json
import os
import struct
import subprocess
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from verify_functions import Obj  # noqa: E402

MWCC = os.path.abspath("tools/mwccarm/dsi/1.1/mwccarm.exe")
MWCFLAGS = ("-DSDK_ARM9 -DSDK_CODE_ARM -DSDK_TS -O4,p -sym on -enum int -lang c99 "
            "-Cpp_exceptions off -gccext,on -proc arm946e -msgstyle gcc -gccinc "
            "-i ./src -i ./include -i ./include/msl "
            "-I./lib/NitroSDK/TwlSDK/include "
            "-I./lib/TwlSystem/include "
            # NNS libraries include their own private headers by bare name;
            # without these only 48 of 86 NNS sources compile.
            "-I./lib/TwlSystem/build/libraries/fnd/include "
            "-I./lib/TwlSystem/build/libraries/g2d/include "
            "-I./lib/TwlSystem/build/libraries/g3d/include "
            "-I./lib/TwlSystem/build/libraries/snd/include "
            "-I./lib/TwlSystem/build/libraries/gfd/include "
            "-I./lib/TwlSystem/build/libraries/mcs/include "
            "-ipa file -interworking -inline on,noauto -char signed").split()

# Game code (and the SDK as linked into overlays) is largely Thumb. --thumb
# recompiles the sweep with -thumb / SDK_CODE_THUMB into a separate output dir
# so both instruction sets can be swept without clobbering each other.
THUMB_FLAGS = [("-DSDK_CODE_THUMB" if f == "-DSDK_CODE_ARM" else f)
               for f in MWCFLAGS] + ["-thumb"]
OUT_DIR = "build/sdk_sweep"
RESULTS = "build/reference/sdk_matches.json"

# (root to strip for output naming, glob under it)
SOURCE_ROOTS = [
    ("lib/NitroSDK/TwlSDK/build/libraries", "lib/NitroSDK/TwlSDK/build/libraries/**/src/**/*.c"),
    ("lib/TwlSystem/build/libraries", "lib/TwlSystem/build/libraries/**/src/**/*.c"),
]


def compile_all(thumb=False):
    flags = THUMB_FLAGS if thumb else MWCFLAGS
    os.makedirs(OUT_DIR, exist_ok=True)
    env = dict(os.environ)
    env["LM_LICENSE_FILE"] = os.path.abspath("tools/mwccarm/license.dat")
    ok = fail = total = 0
    for root, pattern in SOURCE_ROOTS:
        srcs = glob.glob(pattern, recursive=True)
        total += len(srcs)
        prefix = "nns__" if "TwlSystem" in root else ""
        for src in sorted(srcs):
            rel = os.path.relpath(src, root)
            out = os.path.join(OUT_DIR,
                               prefix + rel.replace(os.sep, "__").replace("/", "__")[:-2] + ".o")
            r = subprocess.run([MWCC, *flags, "-c", "-o", out, src],
                               capture_output=True, env=env)
            if r.returncode == 0 and os.path.exists(out):
                ok += 1
            else:
                fail += 1
                if os.path.exists(out):
                    os.remove(out)
    print(f"compiled {ok}, skipped {fail} of {total} SDK/NNS sources")


def sweep():
    manifest = json.load(open("build/reference/manifest.json"))
    modules = {name: open(f"build/reference/{name}.bin", "rb").read() for name in manifest}
    results = []
    n_funcs = 0
    for path in sorted(glob.glob(OUT_DIR + "/*.o")):
        try:
            obj = Obj(path)
        except Exception:
            continue
        for sym in obj.symtab:
            if sym["typ"] != 2 or sym["size"] < 16 or sym["shndx"] >= len(obj.sections):
                continue
            n_funcs += 1
            code = bytes(obj.section_bytes(sym["shndx"])[sym["value"]:sym["value"] + sym["size"]])
            mask = set()
            for roff, rtype, rsym, radd in obj.relocs.get(sym["shndx"], []):
                if sym["value"] <= roff < sym["value"] + sym["size"]:
                    i = roff - sym["value"]
                    mask.update(range(i, i + 4))
            anchor = None
            for a in range(0, len(code) - 8):
                if not any(a + k in mask for k in range(8)):
                    anchor = a
                    break
            if anchor is None:
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
                        break  # first hit per module is enough
            if hits:
                results.append(dict(name=sym["name"], object=os.path.basename(path),
                                    size=sym["size"], masked=len(mask), hits=hits))
    with open(RESULTS, "w") as f:
        json.dump(results, f, indent=1)
    uniq = len(results)
    total_hits = sum(len(r["hits"]) for r in results)
    matched_bytes = sum(r["size"] * len(r["hits"]) for r in results)
    in_main = sum(1 for r in results if any(h["module"] == "main" for h in r["hits"]))
    print(f"swept {n_funcs} SDK functions: {uniq} matched somewhere "
          f"({in_main} in main), {total_hits} total placements, "
          f"{matched_bytes} bytes claimed")


if __name__ == "__main__":
    thumb = "--thumb" in sys.argv
    if thumb:
        OUT_DIR = "build/sdk_sweep_thumb"
        RESULTS = "build/reference/sdk_matches_thumb.json"
    if "--compile" in sys.argv:
        compile_all(thumb)
    else:
        sweep()
