#!/usr/bin/env python3
"""Compile one source file with the game's exact MWCFLAGS.

  python tools/scripts/cc.py src/main/heap.c
  python tools/scripts/cc.py src/ov021/field.c
  python tools/scripts/cc.py src/ov016/glue.c --thumb --cc 2.0/sp2p2

Object lands at build/<src path>.o, which is the path convention
verify_functions.py uses to pick the reference module (build/src/ovNNN/... ->
that overlay, anything else -> main). Prints the compiler's diagnostics and
exits non-zero on failure.

Flags are the Makefile's MWCFLAGS verbatim; do not edit one without editing the
other. -DSDK_CODE_THUMB / -thumb are NOT default: pass --thumb for Thumb code.
"""
import os
import subprocess
import sys

LICENSE = os.path.abspath("tools/mwccarm/license.dat")

# The ROM was not built with one compiler. dsi/1.x hoists a global's address
# into a callee-saved register across a call; 2.0/* and 1.2/* re-materialise
# the literal-pool load each time -- and the ROM does both, in different
# regions. No single build matches everything (all 24 in tools/mwccarm were
# swept). Pick per translation unit and record the choice in the file header.
#
#   dsi/1.1     repo default: SDK/NNS library code, DWC middleware
#   2.0/sp2p2   Game Freak Thumb glue in ov016 (0x021B6CF0 onward)
DEFAULT_CC = "dsi/1.1"


def compiler(ver):
    p = os.path.abspath(os.path.join("tools/mwccarm", ver, "mwccarm.exe"))
    if not os.path.exists(p):
        avail = sorted(os.path.relpath(os.path.dirname(x), "tools/mwccarm")
                       for x in __import__("glob").glob("tools/mwccarm/*/*/mwccarm.exe"))
        raise SystemExit(f"no compiler at {ver}; available: {', '.join(avail)}")
    return p

BASE = ("-DSDK_ARM9 -DSDK_CODE_ARM -DSDK_TS -O4,p -sym on -enum int -lang c99 "
        "-Cpp_exceptions off -gccext,on -proc arm946e -msgstyle gcc -gccinc "
        "-i ./src -i ./include -i ./include/msl "
        "-I./lib/NitroSDK/TwlSDK/include -I./lib/TwlSystem/include "
        "-ipa file -interworking -inline on,noauto -char signed").split()

# Thumb variant: the game's overlay/game code is largely Thumb. -DSDK_CODE_THUMB
# swaps the SDK's inline asm/attribute selection to match.
THUMB = ["-thumb"]
THUMB_DEFS = ("-DSDK_ARM9 -DSDK_CODE_THUMB -DSDK_TS").split()


def build(src, thumb=False, extra=(), ver=DEFAULT_CC):
    if thumb:
        flags = THUMB_DEFS + BASE[3:] + THUMB
    else:
        flags = list(BASE)
    flags += list(extra)
    obj = os.path.join("build", os.path.splitext(src)[0] + ".o")
    os.makedirs(os.path.dirname(obj), exist_ok=True)
    env = dict(os.environ, LM_LICENSE_FILE=LICENSE)
    cmd = [compiler(ver)] + flags + ["-c", "-o", obj, src]
    p = subprocess.run(cmd, env=env, capture_output=True, text=True)
    out = (p.stdout or "") + (p.stderr or "")
    return p.returncode, obj, out


def main():
    args = [a for a in sys.argv[1:]]
    thumb = "--thumb" in args
    args = [a for a in args if a != "--thumb"]
    ver = DEFAULT_CC
    if "--cc" in args:
        i = args.index("--cc")
        ver = args[i + 1]
        del args[i:i + 2]
    if not args:
        sys.exit(__doc__)
    src = args[0].replace("\\", "/")
    extra = args[1:]
    rc, obj, out = build(src, thumb, extra, ver)
    if out.strip():
        print(out.rstrip())
    if rc:
        sys.exit(f"compile FAILED: {src}")
    print(f"ok  {obj}" + ("" if ver == DEFAULT_CC else f"  [{ver}]"))


if __name__ == "__main__":
    main()
