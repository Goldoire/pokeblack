#!/usr/bin/env python3
"""Template-driven generator for the repeated small-function shapes.

Three agents wrote one-off pattern generators (ov093 wrapper_gen, ov016's ARM
fan-out, ov021's template scanner) and threw each away.  This is the shared
version: one registry of shapes, one scanner that runs over every module in
build/reference/manifest.json, and -- the part the one-offs skipped -- a
verification gate.  Nothing reaches src/ that has not been compiled and
byte-compared against the ROM, so the output is matches, not candidates.

  python tools/scripts/shapegen.py                 # scan + emit + verify all
  python tools/scripts/shapegen.py --module ov021  # one module
  python tools/scripts/shapegen.py --dry-run       # census only, write nothing
  python tools/scripts/shapegen.py --template fwd3 # one shape

Adding a shape
--------------
Append a Shape to SHAPES.  `pat` is a list of one entry per Thumb halfword,
built from the instruction helpers below; `BL` and `LIT` each cover two
halfwords.  `emit(g)` returns the C body.  `g` resolves branch targets, literal
words, immediates and struct offsets, and registers whatever prototypes and
typedefs the body needs.

The rule the constraint document states and this file enforces: a shape only
belongs here if plausible C reproduces it.  Byte-exact-by-luck constructions
(inline asm, hand-laid literal pools, casts chosen to hit an encoding) are not
decompilation and are rejected in review, so they are not worth generating.
"""
import argparse
import collections
import glob
import json
import os
import re
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import cc as ccmod                                   # noqa: E402
import verify_functions as vf                        # noqa: E402

REF = "build/reference"
GAP = 0x600          # bytes of untouched ROM that end a file's contiguous run
MAX_PER_FILE = 48

# ---------------------------------------------------------------- pattern DSL

def H(v, m=0xFFFF):
    return ("h", v, m)


def LDRW(rd, rn):        # ldr rd,[rn,#imm5*4]
    return ("h", 0x6800 | (rn << 3) | rd, 0xF83F)


def STRW(rd, rn):        # str rd,[rn,#imm5*4]
    return ("h", 0x6000 | (rn << 3) | rd, 0xF83F)


def LDRB(rd, rn):
    return ("h", 0x7800 | (rn << 3) | rd, 0xF83F)


def LDRH(rd, rn):
    return ("h", 0x8800 | (rn << 3) | rd, 0xF83F)


def MOVI(rd):            # movs rd,#imm8
    return ("h", 0x2000 | (rd << 8), 0xFF00)


def CMPI(rd):            # cmp rd,#imm8
    return ("h", 0x2800 | (rd << 8), 0xFF00)


def ADDI(rd):            # adds rd,#imm8
    return ("h", 0x3000 | (rd << 8), 0xFF00)


def LDRPC(rd):           # ldr rd,[pc,#imm8*4]
    return ("h", 0x4800 | (rd << 8), 0xF800)


def MOV(rd, rn):         # adds rd,rn,#0  (CW's register move)
    return ("h", 0x1C00 | (rn << 3) | rd, 0xFFFF)


def ADDIMM3(rd, rn):     # adds rd,rn,#imm3
    return ("h", 0x1C00 | (rn << 3) | rd, 0xFE3F)


def BEQ():
    return ("h", 0xD000, 0xFF00)


def BNE():
    return ("h", 0xD100, 0xFF00)


BL = ("bl",)
LIT = ("lit",)
PAD = ("h", 0x0000, 0xFFFF)


def pat_size(pat):
    n = 0
    for t in pat:
        n += 4 if t[0] in ("bl", "lit") else 2
    return n


def pat_match(pat, blob):
    """True if blob (already the right length) satisfies pat."""
    i = 0
    for t in pat:
        if t[0] == "h":
            h = int.from_bytes(blob[i:i + 2], "little")
            if (h & t[2]) != t[1]:
                return False
            i += 2
        elif t[0] == "bl":
            hi = int.from_bytes(blob[i:i + 2], "little")
            lo = int.from_bytes(blob[i + 2:i + 4], "little")
            if (hi & 0xF800) != 0xF000 or (lo & 0xE000) != 0xE000:
                return False
            i += 4
        else:                                   # literal pool word
            i += 4
    return True


# ------------------------------------------------------------- emission scope

CTYPES = {"u8": "u8", "u16": "u16", "u32": "u32", "s32": "s32",
          "ptr": "void *", "vec3": "Vec3"}


class Scope:
    """Per-file accumulator for prototypes, typedefs and extern data."""

    def __init__(self):
        self.protos = {}      # addr -> prototype text
        self.structs = {}     # typename -> definition
        self.externs = {}     # addr -> declaration
        self.need_vec3 = False

    def call(self, addr, ret="void", args="void"):
        nm = "sub_%08X" % addr
        proto = "%s %s(%s);" % (ret, nm, args)
        old = self.protos.get(addr)
        if old is not None and old != proto:
            raise Conflict(addr)
        self.protos[addr] = proto
        return nm

    def data(self, addr, decl="extern const u8 %s[];"):
        nm = "_%08X" % addr
        text = decl % nm
        old = self.externs.get(addr)
        if old is not None and old != text:
            raise Conflict(addr)
        self.externs[addr] = text
        return nm

    def obj(self, off, ct):
        """A struct type with one field of C type `ct` at byte offset `off`."""
        if ct == "vec3":
            self.need_vec3 = True
        tag = "GenObj%s_%02X" % (ct.capitalize(), off)
        field = "unk_%02X" % off
        if tag not in self.structs:
            body = ""
            if off:
                body += "    u8 unk_00[%#x];\n" % off
            body += "    %s %s;\n" % (CTYPES[ct], field)
            self.structs[tag] = "typedef struct %s {\n%s} %s;\n" % (tag, body, tag)
        return tag, field


class Conflict(Exception):
    pass


class G:
    """What an emitter sees: one matched instance."""

    def __init__(self, mod, addr, blob, pat, scope):
        self.mod, self.addr, self.b, self.pat, self.s = mod, addr, blob, pat, scope
        self.name = "sub_%08X" % addr
        self.hoff = []
        o = 0
        for t in pat:
            self.hoff.append(o)
            o += 4 if t[0] in ("bl", "lit") else 2

    def hw(self, i):
        o = self.hoff[i]
        return int.from_bytes(self.b[o:o + 2], "little")

    def imm8(self, i):
        return self.hw(i) & 0xFF

    def off5(self, i, scale=4):
        return ((self.hw(i) >> 6) & 0x1F) * scale

    def imm3(self, i):
        return (self.hw(i) >> 6) & 7

    def bl(self, i):
        o = self.hoff[i]
        hi = int.from_bytes(self.b[o:o + 2], "little")
        lo = int.from_bytes(self.b[o + 2:o + 4], "little")
        imm = ((hi & 0x7FF) << 12) | ((lo & 0x7FF) << 1)
        if imm & 0x400000:
            imm -= 0x800000
        pc = self.addr + o + 4
        if (lo & 0xF800) == 0xE800:              # blx(1) -> ARM callee
            return ((pc & ~3) + imm) & 0xFFFFFFFF
        return (pc + imm) & 0xFFFFFFFF

    def pcrel(self, i):
        """Word loaded by the `ldr rd,[pc,#imm]` at halfword index i."""
        o = self.hoff[i]
        imm = (self.hw(i) & 0xFF) * 4
        a = ((self.addr + o + 4) & ~3) + imm
        p = a - self.addr
        if p < 0 or p + 4 > len(self.b):
            return None
        return int.from_bytes(self.b[p:p + 4], "little")


# ------------------------------------------------------------------- registry

class Shape:
    def __init__(self, key, pat, emit, note="", tail=0):
        self.key, self.pat, self.emit, self.note = key, pat, emit, note
        self.size = pat_size(pat) + tail
        self.body = pat_size(pat)


SHAPES = []


def shape(key, pat, note="", tail=0):
    def deco(fn):
        SHAPES.append(Shape(key, pat, fn, note, tail))
        return fn
    return deco


# --- forwarders -------------------------------------------------------------
# `return f(...)` from a frameless function with <=3 arguments tail-calls as
# `ldr r3,=target|1; bx r3`.  The literal pool word is part of the function.

@shape("fwd_a0_k1_k2", [LDRPC(3), MOVI(1), MOVI(2), H(0x4718), LIT],
       "T(a0, K1, K2) tail call")
def _f1(g):
    t = g.pcrel(0)
    fn = g.s.call(t & ~1, "void", "void *a0, u32 a1, u32 a2")
    return ("void %s(void *a0)\n{\n    %s(a0, %d, %d);\n}"
            % (g.name, fn, g.imm8(1), g.imm8(2)))


@shape("fwd_a0_k1", [LDRPC(3), MOVI(1), H(0x4718), PAD, LIT],
       "T(a0, K1) tail call")
def _f2(g):
    t = g.pcrel(0)
    fn = g.s.call(t & ~1, "void", "void *a0, u32 a1")
    return ("void %s(void *a0)\n{\n    %s(a0, %d);\n}"
            % (g.name, fn, g.imm8(1)))


@shape("fwd_field_a0", [LDRW(0, 0), LDRPC(3), H(0x4718), PAD, LIT],
       "T(a0->unk_XX) tail call")
def _f3(g):
    t = g.pcrel(1)
    tag, field = g.s.obj(g.off5(0), "ptr")
    fn = g.s.call(t & ~1, "void", "void *a0")
    return ("void %s(%s *a0)\n{\n    %s(a0->%s);\n}"
            % (g.name, tag, fn, field))


# --- predicates -------------------------------------------------------------
# CW canonicalises an int-returning `if (c) return TRUE; return FALSE;` to
# bne/1/0 with the TRUE arm first, which is exactly this layout.

@shape("pred_arg_eq", [CMPI(0), BNE(), MOVI(0), H(0x4770), MOVI(0), H(0x4770)],
       "return a0 == K")
def _p1(g):
    if g.imm8(2) != 1 or g.imm8(4) != 0:
        return None
    return ("BOOL %s(u32 a0)\n{\n    if (a0 == %d) {\n        return TRUE;\n"
            "    }\n    return FALSE;\n}" % (g.name, g.imm8(0)))


@shape("pred_field_eq",
       [LDRW(0, 0), CMPI(0), BNE(), MOVI(0), H(0x4770), MOVI(0), H(0x4770)],
       "return a0->unk_XX == K", tail=2)
def _p2(g):
    if g.imm8(3) != 1 or g.imm8(5) != 0:
        return None
    tag, field = g.s.obj(g.off5(0), "u32")
    return ("BOOL %s(%s *a0)\n{\n    if (a0->%s == %d) {\n        return TRUE;\n"
            "    }\n    return FALSE;\n}" % (g.name, tag, field, g.imm8(1)))


@shape("pred_field_ne0",
       [LDRW(0, 0), CMPI(0), BEQ(), MOVI(0), H(0x4770), MOVI(0), H(0x4770)],
       "return a0->unk_XX != 0", tail=2)
def _p3(g):
    if g.imm8(1) != 0 or g.imm8(3) != 1 or g.imm8(5) != 0:
        return None
    tag, field = g.s.obj(g.off5(0), "u32")
    return ("BOOL %s(%s *a0)\n{\n    if (a0->%s != 0) {\n        return TRUE;\n"
            "    }\n    return FALSE;\n}" % (g.name, tag, field))


@shape("pred_call_eq",
       [H(0xB508), BL, CMPI(0), BNE(), MOVI(0), H(0xBD08), MOVI(0), H(0xBD08)],
       "return f(a0) == K", tail=2)
def _p4(g):
    if g.imm8(4) != 1 or g.imm8(6) != 0:
        return None
    fn = g.s.call(g.bl(1), "u32", "void *a0")
    return ("BOOL %s(void *a0)\n{\n    if (%s(a0) == %d) {\n        return TRUE;\n"
            "    }\n    return FALSE;\n}" % (g.name, fn, g.imm8(2)))


@shape("ret_call_k",
       [H(0xB508), BL, CMPI(0), BEQ(), MOVI(0), H(0xBD08), MOVI(0), H(0xBD08)],
       "if (f(a0)) return K; return 0;", tail=2)
def _p5(g):
    if g.imm8(2) != 0 or g.imm8(6) != 0:
        return None
    fn = g.s.call(g.bl(1), "u32", "void *a0")
    return ("u32 %s(void *a0)\n{\n    if (%s(a0) != 0) {\n        return %d;\n"
            "    }\n    return 0;\n}" % (g.name, fn, g.imm8(4)))


# --- call sequences ---------------------------------------------------------

@shape("two_calls", [H(0xB508), BL, BL, H(0xBD08)], "g(f(a0))")
def _c1(g):
    a, b = g.bl(1), g.bl(2)
    f1 = g.s.call(a, "u32", "void *a0")
    f2 = g.s.call(b, "void", "u32 a0")
    return "void %s(void *a0)\n{\n    %s(%s(a0));\n}" % (g.name, f2, f1)


@shape("call_then_call_same",
       [H(0xB510), MOV(4, 0), BL, MOV(0, 4), BL, H(0xBD10)], "f(a0); g(a0);")
def _c2(g):
    f1 = g.s.call(g.bl(2), "void", "void *a0")
    f2 = g.s.call(g.bl(4), "void", "void *a0")
    if f1 == f2:
        return None
    return ("void %s(void *a0)\n{\n    %s(a0);\n    %s(a0);\n}"
            % (g.name, f1, f2))


@shape("call_a1_then_a1p",
       [H(0xB510), MOV(4, 1), MOV(0, 4), BL, ADDIMM3(0, 4), BL, H(0xBD10)],
       "f(a1); g(&a1->unk_N);", tail=2)
def _c3(g):
    d = g.imm3(4)
    if d == 0:
        return None
    f1 = g.s.call(g.bl(3), "void", "void *a0")
    f2 = g.s.call(g.bl(5), "void", "void *a0")
    tag, field = g.s.obj(d, "u32")
    return ("void %s(void *a0, %s *a1)\n{\n    (void)a0;\n    %s(a1);\n"
            "    %s(&a1->%s);\n}" % (g.name, tag, f1, f2, field))


@shape("call_a0p_then_a0",
       [H(0xB510), MOV(4, 0), ADDIMM3(0, 4), BL, MOV(0, 4), BL, H(0xBD10)],
       "f(&a0->unk_N); g(a0);", tail=2)
def _c4(g):
    d = g.imm3(2)
    if d == 0:
        return None
    f1 = g.s.call(g.bl(3), "void", "void *a0")
    f2 = g.s.call(g.bl(5), "void", "void *a0")
    tag, field = g.s.obj(d, "u32")
    return ("void %s(%s *a0)\n{\n    %s(&a0->%s);\n    %s(a0);\n}"
            % (g.name, tag, f1, field, f2))


@shape("free_field",
       [H(0xB510), MOV(4, 0), LDRW(0, 4), CMPI(0), BEQ(), BL, MOVI(0),
        STRW(0, 4), H(0xBD10)], "if (p->f) { free(p->f); p->f = NULL; }")
def _c5(g):
    if g.imm8(3) != 0 or g.imm8(6) != 0 or g.off5(2) != g.off5(7):
        return None
    fn = g.s.call(g.bl(5), "void", "void *a0")
    tag, field = g.s.obj(g.off5(2), "ptr")
    return ("void %s(%s *a0)\n{\n    if (a0->%s != NULL) {\n        %s(a0->%s);\n"
            "        a0->%s = NULL;\n    }\n}"
            % (g.name, tag, field, fn, field, field))


@shape("call4_r3", [H(0xB508), MOV(3, 2), MOVI(2), BL, H(0xBD08)],
       "f(a0, a1, K, a2) -- 4 args, so push/bl/pop")
def _c6(g):
    fn = g.s.call(g.bl(3), "void", "void *a0, void *a1, u32 a2, u32 a3")
    return ("void %s(void *a0, void *a1, u32 a2)\n{\n    %s(a0, a1, %d, a2);\n}"
            % (g.name, fn, g.imm8(2)))


@shape("call_ret_field",
       [H(0xB510), MOVI(2), MOV(4, 1), BL, ADDI(4), LDRW(0, 4), H(0xBD10)],
       "f(a0, a1, K); return a1->unk_BIG;")
def _c7(g):
    if g.off5(5) != 0:
        return None
    off = g.imm8(4)
    fn = g.s.call(g.bl(3), "void", "void *a0, void *a1, u32 a2")
    tag, field = g.s.obj(off, "u32")
    return ("u32 %s(void *a0, %s *a1)\n{\n    %s(a0, a1, %d);\n    return a1->%s;\n}"
            % (g.name, tag, fn, g.imm8(1), field))


@shape("deref_call", [H(0xB508), BL, LDRW(0, 0), H(0xBD08)], "return *f(...)")
def _c8(g):
    if g.off5(2) != 0:
        return None
    fn = g.s.call(g.bl(1), "u32 *", "void *a0")
    return "u32 %s(void *a0)\n{\n    return *%s(a0);\n}" % (g.name, fn)


@shape("deref_call_h", [H(0xB508), BL, LDRH(0, 0), H(0xBD08)], "return *(u16*)f(...)")
def _c9(g):
    if g.off5(2) != 0:
        return None
    fn = g.s.call(g.bl(1), "u16 *", "void *a0")
    return "u16 %s(void *a0)\n{\n    return *%s(a0);\n}" % (g.name, fn)


@shape("call_ret_k", [H(0xB508), BL, MOVI(0), H(0xBD08)], "f(...); return K;")
def _c10(g):
    fn = g.s.call(g.bl(1), "void", "void *a0")
    return ("u32 %s(void *a0)\n{\n    %s(a0);\n    return %d;\n}"
            % (g.name, fn, g.imm8(2)))


# --- data movement ----------------------------------------------------------

@shape("copy_vec3",
       [MOV(2, 0), ADDI(2), MOV(3, 1), H(0xCA03), H(0xC303), LDRW(0, 2),
        STRW(0, 3), H(0x4770)], "*b = a->unk_XX (12-byte struct assignment)")
def _d1(g):
    if g.off5(5) != 0 or g.off5(6) != 0:
        return None
    tag, field = g.s.obj(g.imm8(1), "vec3")
    return ("void %s(%s *a0, Vec3 *a1)\n{\n    *a1 = a0->%s;\n}"
            % (g.name, tag, field))


@shape("store_far", [MOVI(1), MOVI(2), H(0x0089), STRW(2, 0), H(0x4770)],
       "((u32 *)a0)[K] = V", tail=2)
def _d2(g):
    if g.off5(3) != 0:
        return None
    idx = g.imm8(0)
    tag, field = g.s.obj(idx * 4, "u32")
    return ("void %s(%s *a0)\n{\n    a0->%s = %d;\n}"
            % (g.name, tag, field, g.imm8(1)))


# ------------------------------------------------------------------- scanning

def load(mod, manifest):
    return open(os.path.join(REF, mod + ".bin"), "rb").read()


VENEER = bytes.fromhex("7847c04600c09fe51cff2fe1")


def src_taken():
    """Every sub_XXXXXXXX that already appears anywhere under src/."""
    taken = set()
    for f in glob.glob("src/**/*.c", recursive=True) + glob.glob("src/**/*.h",
                                                                 recursive=True):
        try:
            txt = open(f, encoding="utf-8", errors="replace").read()
        except OSError:
            continue
        for m in re.finditer(r"\bsub_([0-9A-Fa-f]{8})\b", txt):
            taken.add(int(m.group(1), 16))
        for m in re.finditer(r"\bfunc_([0-9A-Fa-f]{8})\b", txt):
            taken.add(int(m.group(1), 16))
    return taken


def candidates(mod, data, base, tri):
    """Addresses worth testing: triage rows plus mined call/pointer targets."""
    starts = set()
    blocked = []
    for f in tri.get(mod, []):
        if f["status"].startswith("unclaimed"):
            if f["kind"] != "data":
                starts.add(f["ram"])
        else:
            blocked.append((f["ram"], f["ram"] + max(f["size"], 2)))
    end = base + len(data)
    n = len(data)
    p = 0
    while p + 4 <= n:
        hi = int.from_bytes(data[p:p + 2], "little")
        lo = int.from_bytes(data[p + 2:p + 4], "little")
        if (hi & 0xF800) == 0xF000 and (lo & 0xE000) == 0xE000:
            imm = ((hi & 0x7FF) << 12) | ((lo & 0x7FF) << 1)
            if imm & 0x400000:
                imm -= 0x800000
            pc = base + p + 4
            t = ((pc & ~3) + imm) if (lo & 0xF800) == 0xE800 else (pc + imm)
            if base <= (t & 0xFFFFFFFF) < end:
                starts.add(t & 0xFFFFFFFF)
            p += 4
            continue
        p += 2
    for off in range(0, n - 3, 4):
        v = int.from_bytes(data[off:off + 4], "little")
        if (v & 1) and base <= (v & ~1) < end:
            starts.add(v & ~1)
    blocked.sort()
    return sorted(starts), blocked


def overlaps(blocked, lo, hi):
    import bisect
    i = bisect.bisect_right(blocked, (lo, 1 << 62)) - 1
    for j in (i, i + 1):
        if 0 <= j < len(blocked):
            a, b = blocked[j]
            if lo < b and a < hi:
                return True
    return False


def scan(mods, manifest, tri, taken, only=None):
    """-> {module: [(addr, shape, blob)]}, sorted, non-overlapping."""
    out = {}
    for mod in mods:
        path = os.path.join(REF, mod + ".bin")
        if not os.path.exists(path):
            continue
        data = load(mod, manifest)
        base = manifest[mod]["ram"]
        starts, blocked = candidates(mod, data, base, tri)
        hits = []
        for a in starts:
            if a in taken or (a - base) % 2:
                continue
            o = a - base
            if data[o:o + 12] == VENEER:
                continue
            for sh in SHAPES:
                if only and sh.key not in only:
                    continue
                if o + sh.size > len(data):
                    continue
                if not pat_match(sh.pat, data[o:o + sh.body]):
                    continue
                if sh.size > sh.body and any(data[o + sh.body:o + sh.size]):
                    continue                       # tail must be real padding
                if overlaps(blocked, a, a + sh.size):
                    continue
                hits.append((a, sh, data[o:o + sh.size]))
                break
        hits.sort()
        keep, last = [], -1
        for a, sh, blob in hits:
            if a < last:
                continue
            keep.append((a, sh, blob))
            last = a + sh.size
        if keep:
            out[mod] = keep
    return out


# ------------------------------------------------------------------- emission

HEADER = """#include "types.h"

/*
 * Generated by tools/scripts/shapegen.py -- repeated small-function shapes.
 * Compiler: %s (-thumb).  Every function below is byte-verified against the
 * ROM; the generator drops anything that does not match.
 * Shapes here: %s
 */
"""

VEC3 = """
typedef struct Vec3 {
    s32 x;
    s32 y;
    s32 z;
} Vec3;
"""


def render(mod, items):
    """items = [(addr, shape, blob)] -> (text, [addrs], [dropped]) or raise."""
    scope = Scope()
    bodies, addrs, dropped = [], [], []
    for a, sh, blob in items:
        g = G(mod, a, blob, sh.pat, scope)
        save = (dict(scope.protos), dict(scope.externs), dict(scope.structs),
                scope.need_vec3)
        try:
            body = sh.emit(g)
        except Conflict:
            scope.protos, scope.externs, scope.structs, scope.need_vec3 = (
                save[0], save[1], save[2], save[3])
            dropped.append((a, "prototype conflict"))
            continue
        if not body:
            scope.protos, scope.externs, scope.structs, scope.need_vec3 = (
                save[0], save[1], save[2], save[3])
            dropped.append((a, "emitter declined"))
            continue
        bodies.append("/* %s */\n%s\n" % (sh.key, body))
        addrs.append(a)
    if not bodies:
        return None, [], dropped
    keys = sorted({sh.key for _, sh, _ in items})
    txt = HEADER % (ccmod.DEFAULT_CC, ", ".join(keys))
    if scope.need_vec3:
        txt += VEC3
    if scope.structs:
        txt += "\n" + "\n".join(scope.structs[k] for k in sorted(scope.structs))
    own = set(addrs)
    decls = [v for k, v in sorted(scope.protos.items()) if k not in own]
    decls += [v for k, v in sorted(scope.externs.items())]
    if decls:
        txt += "\n" + "\n".join(decls) + "\n"
    txt += "\n" + "\n".join(bodies)
    return txt, addrs, dropped


def verify_obj(objpath, module, manifest):
    """-> {name: (score, total)} for every STT_FUNC in the object."""
    ref = open(os.path.join(REF, module + ".bin"), "rb").read()
    region = manifest[module]["ram"]
    obj = vf.Obj(objpath)
    res = {}
    for sym in obj.symtab:
        if sym["typ"] != 2 or sym["size"] == 0:
            continue
        best = None
        for fix in (0x4000, 0):
            r = vf.verify_function(obj, sym, ref, fix, region, module)
            if r and (best is None or r[0] > best[0]):
                best = r
        res[sym["name"]] = (best[0], best[1]) if best else (0, 1)
    return res


def build_file(mod, items, manifest, log):
    """Write / compile / verify / prune until every function in the file is OK."""
    srcdir = os.path.join("src", mod)
    os.makedirs(srcdir, exist_ok=True)
    path = os.path.join(srcdir, "gen_%08X.c" % items[0][0]).replace("\\", "/")
    cur = list(items)
    failed = []
    for _round in range(4):
        txt, addrs, dropped = render(mod, cur)
        failed += [(a, why) for a, why in dropped]
        if not txt:
            break
        open(path, "w", encoding="utf-8", newline="\n").write(txt)
        rc, obj, out = ccmod.build(path, thumb=True)
        if rc:
            log.append("  %s: COMPILE FAILED\n%s" % (path, out.strip()[:800]))
            cur = []
            break
        res = verify_obj(obj, mod, manifest)
        bad = []
        for a in list(addrs):
            nm = "sub_%08X" % a
            sc, tot = res.get(nm, (0, 1))
            if sc != tot:
                bad.append((a, "%d/%d" % (sc, tot)))
        if not bad:
            return path, addrs, failed
        failed += bad
        badset = {a for a, _ in bad}
        cur = [it for it in cur if it[0] not in badset]
        if not cur:
            break
    for p in (path, os.path.join("build", os.path.splitext(path)[0] + ".o")):
        if os.path.exists(p):
            os.remove(p)
    return None, [], failed


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--module", action="append")
    ap.add_argument("--template", action="append")
    ap.add_argument("--dry-run", action="store_true")
    ap.add_argument("--min", type=int, default=1,
                    help="skip shapes with fewer than this many instances")
    a = ap.parse_args()

    manifest = json.load(open(os.path.join(REF, "manifest.json")))
    tri = json.load(open(os.path.join(REF, "triage.json")))
    mods = a.module or sorted(manifest)
    taken = src_taken()
    only = set(a.template) if a.template else None

    found = scan(mods, manifest, tri, taken, only)
    census = collections.Counter()
    for mod, items in found.items():
        for _, sh, _ in items:
            census[sh.key] += 1
    print("candidates by shape:")
    for k, n in census.most_common():
        print("  %-22s %4d" % (k, n))
    print("  %-22s %4d in %d modules"
          % ("TOTAL", sum(census.values()), len(found)))
    if a.dry_run:
        return 0

    log = []
    ok_fns, ok_bytes = 0, 0
    per_shape = collections.Counter()
    per_shape_b = collections.Counter()
    per_mod = collections.Counter()
    nfiles = 0
    fails = collections.Counter()
    for mod in sorted(found):
        items = found[mod]
        runs, cur = [], []
        for it in items:
            if cur and (it[0] - (cur[-1][0] + cur[-1][1].size) > GAP
                        or len(cur) >= MAX_PER_FILE):
                runs.append(cur)
                cur = []
            cur.append(it)
        if cur:
            runs.append(cur)
        for run in runs:
            path, addrs, failed = build_file(mod, run, manifest, log)
            for aa, why in failed:
                sh = next((s for x, s, _ in run if x == aa), None)
                fails[(sh.key if sh else "?", why.split()[0])] += 1
            if not addrs:
                continue
            nfiles += 1
            byaddr = {x: s for x, s, _ in run}
            for x in addrs:
                ok_fns += 1
                ok_bytes += byaddr[x].size
                per_shape[byaddr[x].key] += 1
                per_shape_b[byaddr[x].key] += byaddr[x].size
                per_mod[mod] += 1
            print("  %-34s %3d fn" % (path, len(addrs)))

    print("\nVERIFIED %d functions / %d bytes in %d files" % (ok_fns, ok_bytes, nfiles))
    print("\nby shape:")
    for k, n in per_shape.most_common():
        print("  %-22s %4d  %6d B" % (k, n, per_shape_b[k]))
    print("\nby module:")
    for k, n in per_mod.most_common():
        print("  %-8s %4d" % (k, n))
    if fails:
        print("\nrejected (not written):")
        for (k, why), n in fails.most_common(25):
            print("  %-22s %-16s %4d" % (k, why, n))
    for line in log:
        print(line)
    return 0


if __name__ == "__main__":
    sys.exit(main())
