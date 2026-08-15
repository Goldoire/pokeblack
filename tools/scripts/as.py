#!/usr/bin/env python3
"""Assemble one .s with the Makefile's exact MWASFLAGS -- cc.py for assembly.

  python tools/scripts/as.py src/main/msl_mem.s

Object lands at build/<src path>.o, the same convention cc.py uses, so
verify_functions.py picks it up and resolves the module from the path.

Some of the ARM9 is vendor code that was shipped as a library and never had C
source in this repo -- the Metrowerks Standard Library block above 0x02091000 is
the bulk of it (see tools/scripts/msl_sweep.py).  Those functions are written as
assembly, which needs the same "compile it and byte-compare it" loop that C gets.

Flags are the Makefile's MWASFLAGS plus -DSDK_FINALROM, which the retail ARM9 is
built with, and minus -g: with debug info on, mwasmarm adds a file-local
STT_FUNC named `_@DummyFn1` covering the whole .text, and the verifier then
reports one bogus "no address" row per object.  Nothing else about the emitted
code changes.

A function is found by name like everywhere else: declare it
`.global sub_020923F0` with a `.type`/`.size` pair so it lands in the symbol
table as a sized STT_FUNC.  Symbols defined in other translation units must be
declared `.public` or mwasmarm rejects them as unknown identifiers.
"""
import os
import subprocess
import sys

LICENSE = os.path.abspath("tools/mwccarm/license.dat")
DEFAULT_AS = "dsi/1.1"

FLAGS = ("-DSDK_ARM9 -DSDK_CODE_ARM -DSDK_TS -DSDK_FINALROM -proc arm5te "
         "-gccinc -i . -i ./asm -i ./asm/macros -i ./asm/include -i ./include "
         "-I./lib/NitroSDK/TwlSDK/include -DSDK_ASM").split()


def assembler(ver):
    p = os.path.abspath(os.path.join("tools/mwccarm", ver, "mwasmarm.exe"))
    if not os.path.exists(p):
        raise SystemExit(f"no assembler at {ver}")
    return p


def build(src, extra=(), ver=DEFAULT_AS):
    obj = os.path.join("build", os.path.splitext(src)[0] + ".o")
    os.makedirs(os.path.dirname(obj), exist_ok=True)
    env = dict(os.environ, LM_LICENSE_FILE=LICENSE)
    cmd = [assembler(ver), *FLAGS, *extra, "-o", obj, src]
    p = subprocess.run(cmd, env=env, capture_output=True, text=True)
    return p.returncode, obj, (p.stdout or "") + (p.stderr or "")


def main():
    args = sys.argv[1:]
    ver = DEFAULT_AS
    if "--as" in args:
        i = args.index("--as")
        ver = args[i + 1]
        del args[i:i + 2]
    if not args:
        sys.exit(__doc__)
    src = args[0].replace("\\", "/")
    rc, obj, out = build(src, args[1:], ver)
    if out.strip():
        print(out.rstrip())
    if rc:
        sys.exit(f"assemble FAILED: {src}")
    print(f"ok  {obj}")


if __name__ == "__main__":
    main()
