#!/usr/bin/env python3
"""Byte-check data objects against the ROM, the way verify_functions.py does code.

verify_functions.py filters on STT_FUNC, so a `.data`/`.rodata` definition is
invisible to it: you can write the bytes, compile them, and nothing in the repo
will tell you whether they are right. That is a capability gap, not just a
missing number -- MSL's `__lower_mapC`, `__files`, `_loc_coll_C` and friends are
*located* in build/reference/msl_matches.json and unprovable in-repo.

This is the same judge for STT_OBJECT symbols. Everything that matters is
shared with verify_functions -- the ELF reader, the name -> address rule, the
relocation model, the masking discipline -- so the two cannot drift on the part
that is hard to get right.

Name a data object for its address and it is checked:

    extern const u8 _020A60DC[512];
    const u8 _020A60DC[512] = { ... };

Two differences from the code path, both deliberate:

  * A symbol in a SHT_NOBITS section (.bss) is reported as UNPROVABLE, never
    as a pass. .bss has no bytes in the object OR in the ROM image -- there is
    nothing to compare, and calling that "verified" would be a lie. `errno` at
    0x02153FAC is the live example.
  * Only R_ARM_ABS32 is applied. Data does not branch, so a PC-relative
    relocation in a data section means the symbol is not what it claims to be;
    those bytes are masked and counted as unchecked rather than guessed at.

This does NOT feed progress.py. "Functions verified" is the project's headline
metric and its meaning should not change because data started counting; data
totals are reported separately, here.

=============================================================================
 THE TRAP. Read this before you claim a single byte with this tool.
=============================================================================
For CODE, a match means something because the C is an independent derivation:
you wrote a function, the compiler chose the encoding, and the ROM agreed. The
compiler is the thing you cannot fake.

For DATA there is no compiler in the loop. If you read a byte table out of
build/reference/main.bin and paste it into a `const u8 _020A60DC[512]`, this
tool will report 512/512 OK and you will have proved exactly nothing -- you
compared the ROM to itself. That is not a match, it is a transcription, and
counting it as progress corrupts the only number this project has.

A data object is only genuinely matched when its definition comes from
somewhere else: real library source (MSL, SDK, NNS), a generator that derives
the table from its inputs (`__lower_mapC` is computable from the ctype rules),
or a structure whose field values follow from other verified code. If you
cannot say where the bytes came from other than "the ROM", do not claim it.

The honest use for a transcribed table is as a *placeholder that stays
correct*: it lets the code around it link and verify, and this tool tells you
if a later edit breaks it. Mark such objects in the claim table as
`transcribed:<who>`, never `matched:`.
=============================================================================

  python tools/scripts/verify_data.py                 # every object
  python tools/scripts/verify_data.py ov016           # path substring filter
  python tools/scripts/verify_data.py --list          # per-symbol detail
"""
import glob
import json
import os
import struct
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from verify_functions import (MODULE_RE, Obj, R_ARM_ABS32, STT_FUNC,  # noqa: E402
                              name_addr, target_mode)

REF = "build/reference"
STT_OBJECT = 1
SHT_NOBITS = 8


def verify_object(obj, sym, ref, region_ram, module=None):
    """(score, total, masked, offset, diffs) or None if not checkable here."""
    sec = obj.sections[sym["shndx"]]
    if sec["type"] == SHT_NOBITS:
        return "bss"
    home = name_addr(sym["name"])
    if home is None:
        return None
    off = home - region_ram
    size = sym["size"]
    if off < 0 or off + size > len(ref):
        return None
    data = obj.section_bytes(sym["shndx"])[sym["value"]:sym["value"] + size]
    if len(data) < size:
        return None
    own_range = (region_ram, region_ram + len(ref))

    masked = set()
    for roff, rtype, rsym, radd in obj.relocs.get(sym["shndx"], []):
        if not (sym["value"] <= roff < sym["value"] + size):
            continue
        i = roff - sym["value"]
        target = obj.symtab[rsym]
        t_addr = name_addr(target["name"])
        if rtype != R_ARM_ABS32 or t_addr is None:
            masked.update(range(i, min(i + 4, size)))
            continue
        val = t_addr + radd
        # A pointer to a Thumb function carries bit 0, exactly as in code.
        if target["typ"] == STT_FUNC and \
                target_mode(t_addr, module, own_range) == "thumb":
            val |= 1
        data[i:i + 4] = struct.pack("<I", val & 0xFFFFFFFF)

    orig = ref[off:off + size]
    diffs = [i for i in range(size) if i not in masked and data[i] != orig[i]]
    total = size - len(masked)
    return (total - len(diffs), total, len(masked), off, diffs[:4])


def main():
    show = "--list" in sys.argv
    filters = [a for a in sys.argv[1:] if not a.startswith("--")]
    manifest = json.load(open(os.path.join(REF, "manifest.json")))
    refs = {}

    rows, bss, per_mod = [], [], {}
    for path in sorted(glob.glob("build/src/**/*.o", recursive=True)):
        norm = path.replace("\\", "/")
        if filters and not any(f.replace("\\", "/") in norm for f in filters):
            continue
        m = MODULE_RE.search(norm)
        module = m.group(1) if m and m.group(1) in manifest else "main"
        if module not in refs:
            refs[module] = open(os.path.join(REF, module + ".bin"), "rb").read()
        try:
            obj = Obj(path)
        except Exception as e:
            print(f"!! {path}: {e}")
            continue
        for sym in obj.symtab:
            if sym["typ"] != STT_OBJECT or sym["size"] == 0:
                continue
            if name_addr(sym["name"]) is None:
                continue
            r = verify_object(obj, sym, refs[module], manifest[module]["ram"], module)
            if r is None:
                continue
            if r == "bss":
                bss.append((module, sym["name"], sym["size"]))
                continue
            score, total, masked, off, diffs = r
            ok = total and score == total
            rows.append((module, sym["name"], sym["size"], score, total, masked, ok))
            if ok:
                d = per_mod.setdefault(module, [0, 0])
                d[0] += 1
                d[1] += sym["size"]

    if show or filters:
        print(f"{'symbol':34}{'module':8}{'size':>7}{'match':>12}{'masked':>8}")
        for module, name, size, score, total, masked, ok in rows:
            flag = "OK" if ok else "  "
            print(f"{name[:33]:34}{module:8}{size:7}"
                  f"{score:6}/{total:<5}{flag}{masked:6}")

    good = sum(1 for r in rows if r[6])
    gbytes = sum(r[2] for r in rows if r[6])
    print(f"\n{good} of {len(rows)} data objects verified, {gbytes} bytes")
    for mod in sorted(per_mod):
        print(f"  {mod:8s} {per_mod[mod][0]:4d} objects  {per_mod[mod][1]:6d} bytes")
    if bss:
        print(f"\n{len(bss)} UNPROVABLE (.bss -- no bytes to compare, in the "
              f"object or in the ROM):")
        for module, name, size in bss[:10]:
            print(f"  {module:7s} {name:32s} {size}")
    bad = [r for r in rows if not r[6]]
    if bad:
        print(f"\n{len(bad)} not matching:")
        for module, name, size, score, total, masked, _ in bad[:10]:
            print(f"  {module:7s} {name:32s} {score}/{total}")


if __name__ == "__main__":
    main()
