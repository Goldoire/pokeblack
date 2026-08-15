#!/usr/bin/env python3
"""Build the function claim table for all modules.

Sources, best first:
  1. asm_dumps/arm9_full.s labels (main module only - disassembler-derived)
  2. prologue heuristics on the reference binaries (all overlays):
     ARM  stmfd sp!,{..,lr} / str lr,[sp,#-4]!   at word alignment
     Thumb push {..,lr}                           at halfword alignment
  3. build/reference/sdk_matches.json - marks functions already claimed by
     the SDK sweep (status matched_sdk, named after the real SDK symbol)

Heuristic entries are claim-table grade: starts are reliable, sizes are the
gap to the next detected start and may span data. Agents refine them while
matching.

Output: build/reference/functions.json  {module: [{name, ram, size, status}]}

Usage: python tools/scripts/index_functions.py
"""
import json
import os
import re
import struct
import sys


def scan_prologues(data: bytes, ram: int):
    starts = set()
    for i in range(0, len(data) - 4, 4):
        w = struct.unpack_from("<I", data, i)[0]
        if (w & 0xFFFF4000) == 0xE92D4000 or w == 0xE52DE004:
            starts.add(i)
    for i in range(0, len(data) - 2, 2):
        h = struct.unpack_from("<H", data, i)[0]
        if (h & 0xFF00) == 0xB500:
            starts.add(i)
    out = []
    ordered = sorted(starts)
    for k, s in enumerate(ordered):
        end = ordered[k + 1] if k + 1 < len(ordered) else len(data)
        out.append(dict(name=f"func_{ram + s:08X}", ram=ram + s,
                        size=end - s, status="unclaimed"))
    return out


LABEL_RE = re.compile(
    r"^\s*(?:non_word_aligned_thumb_func_start|arm_func_start|thumb_func_start)\s+(\w+)\s*$")
ADDR_RE = re.compile(r"^(\w+):\s*[@;]\s*0x([0-9A-Fa-f]{8})")


def parse_arm9_labels(path: str):
    funcs = []
    pending = None
    with open(path, encoding="utf-8", errors="replace") as f:
        for line in f:
            m = LABEL_RE.match(line)
            if m:
                pending = m.group(1)
                continue
            if pending:
                m = ADDR_RE.match(line)
                if m and m.group(1) == pending:
                    funcs.append((pending, int(m.group(2), 16)))
                pending = None
    out = []
    for k, (name, ram) in enumerate(funcs):
        end = funcs[k + 1][1] if k + 1 < len(funcs) else ram
        out.append(dict(name=name, ram=ram, size=max(end - ram, 0),
                        status="unclaimed"))
    return out


def main():
    manifest = json.load(open("build/reference/manifest.json"))
    index = {}

    for mod, info in manifest.items():
        data = open(f"build/reference/{mod}.bin", "rb").read()
        if mod == "main" and os.path.exists("asm_dumps/arm9_full.s"):
            funcs = parse_arm9_labels("asm_dumps/arm9_full.s")
            # the committed dump stops short of the image end; cover the tail
            covered = max((f["ram"] + f["size"] for f in funcs), default=info["ram"])
            tail_off = covered - info["ram"]
            if tail_off < len(data):
                funcs += scan_prologues(data[tail_off:], covered)
        else:
            funcs = scan_prologues(data, info["ram"])
        index[mod] = funcs

    sdk_path = "build/reference/sdk_matches.json"
    claimed = 0
    if os.path.exists(sdk_path):
        for m in json.load(open(sdk_path)):
            for hit in m["hits"]:
                mod, ram = hit["module"], hit["ram"]
                best = None
                for f in index.get(mod, []):
                    if f["ram"] <= ram < f["ram"] + max(f["size"], 4):
                        best = f
                        break
                if best is not None:
                    best.update(name=m["name"], status="matched_sdk",
                                size=m["size"])
                else:
                    index.setdefault(mod, []).append(
                        dict(name=m["name"], ram=ram, size=m["size"],
                             status="matched_sdk"))
                claimed += 1

    for mod in index:
        index[mod].sort(key=lambda f: f["ram"])

    with open("build/reference/functions.json", "w") as f:
        json.dump(index, f, indent=1)

    total = sum(len(v) for v in index.values())
    matched = sum(1 for v in index.values() for f in v if f["status"] == "matched_sdk")
    total_bytes = sum(m["size"] for m in manifest.values())
    matched_bytes = sum(f["size"] for v in index.values() for f in v
                        if f["status"] == "matched_sdk")
    print(f"indexed {total} functions across {len(index)} modules")
    print(f"matched_sdk: {matched} functions / {matched_bytes} bytes "
          f"({100*matched_bytes/total_bytes:.1f}% of all module bytes)")
    return 0


if __name__ == "__main__":
    sys.exit(main())
