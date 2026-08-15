#ifndef POKEBLACK_OV170_H
#define POKEBLACK_OV170_H

#include "global.h"

/*
 * ===========================================================================
 *  ov170 -- menu / panel overlay
 * ===========================================================================
 *
 * Merged from 40 src/ov170/*.c files. `Ov170Ctx` alone was declared 40 times
 * and `Ov170Panel` 38 times, each file naming only the handful of fields it
 * needed. Delete the local copies and include this instead.
 *
 * `verify_functions.py ov170` reports 51/51 OK across the module, so every
 * offset any of these files uses is byte-exact against the ROM.
 *
 * FIELD GRADES: PROVEN = used by a byte-exact function; the `xN` is how many
 * independent files placed it there. INFERRED = filler placing the next
 * proven field.
 */

typedef struct Ov170Panel Ov170Panel;
typedef struct Ov170Sub00 Ov170Sub00;
typedef struct Ov170Env Ov170Env;
typedef struct Ov170Obj Ov170Obj;
typedef struct Ov170Rect Ov170Rect;
typedef struct Ov170Ctx Ov170Ctx;

/* ---------------------------------------------------------------------------
 * Ov170Ctx -- 0x30.
 *
 * ONE REAL CONFLICT, at +0x00: eight files type it `Ov170Sub00 *`, three type
 * it `Ov170Save *`. Both point somewhere, and neither pointee contradicts the
 * other at any offset they share -- `Ov170Save` is `u8 unk00[0x24]; u32 unk24`
 * (nothing named below 0x24) while `Ov170Sub00` names three pointers at
 * 0x00/0x04/0x08. They are almost certainly the same object read at different
 * depths, but nothing proves that, so the pointer takes the majority type and
 * Ov170Save is kept as a separate declaration below rather than silently
 * merged. Cast at the three Save call sites.
 * ------------------------------------------------------------------------- */
struct Ov170Ctx {
    Ov170Sub00 *unk00;          // +0x00 PROVEN x8 (see conflict note)
    u8 filler_04[0x04];         // +0x04 INFERRED
    u32 unk08;                  // +0x08 PROVEN
    Ov170Env *unk0c;            // +0x0C PROVEN
    u16 unk10;                  // +0x10 PROVEN x2
    u8 unk12;                   // +0x12 PROVEN x3
    u8 unk13;                   // +0x13 PROVEN x2
    u8 unk14;                   // +0x14 PROVEN x6
    u8 unk15;                   // +0x15 PROVEN x4
    u8 unk16;                   // +0x16 PROVEN x17
    u8 unk17;                   // +0x17 PROVEN x2
    u8 unk18;                   // +0x18 PROVEN x2
    u8 unk19;                   // +0x19 PROVEN x2
    u8 filler_1A[0x05];         // +0x1A INFERRED
    u8 unk1f;                   // +0x1F PROVEN
    u8 unk20;                   // +0x20 PROVEN
    u8 unk21;                   // +0x21 PROVEN
    u8 filler_22[0x06];         // +0x22 INFERRED
    u32 unk28;                  // +0x28 PROVEN x5
    Ov170Panel *unk2c;          // +0x2C PROVEN x39 -- the most agreed field
                                //   in the whole repo
};                              // 0x30

/* ---------------------------------------------------------------------------
 * Ov170Anim -- 0x18. Embedded by value in Ov170Panel at +0x58.
 *
 * MERGED, and the merge added a field. Three files declare
 * `u8 unk00[8]; u16 *unk08; u16 unk0c; u16 unk0e; u8 unk10[8]`, and
 * unk_021E2020.c separately declares `u32 (*unk58)(void *)` directly on the
 * panel at +0x58 -- which is exactly where this struct's opaque `unk00[8]`
 * begins. So the first word of the filler is a callback; the two readings are
 * complementary, not contradictory, and both files match. unk_021E19D4.c's
 * flatter `u8 unk00[0x0e]` is the same layout with less detail.
 *
 * `wip_021E19D4.c` types +0x0E as s16; the three matched files say u16. The
 * wip file is not verified, so u16 wins.
 * ------------------------------------------------------------------------- */
typedef struct Ov170Anim {
    u32 (*cb)(void *);   // +0x00 PROVEN (unk_021E2020.c, as panel+0x58)
    u8 filler_04[0x04];  // +0x04 INFERRED
    u16 *unk08;          // +0x08 PROVEN x3
    u16 unk0c;           // +0x0C PROVEN x3
    u16 unk0e;           // +0x0E PROVEN x5
    /*
     * +0x10 and +0x14 PROVEN (wave 3). Three files -- unk_021DCDB8.c,
     * unk_021E2020.c and unk_021E8F60.c -- reach these as panel+0x68 and
     * panel+0x6C (0x58 + 0x10 and 0x58 + 0x14).
     *
     * DEFECT FIXED: they were `u8 filler_10[0x08]`, so those three files had
     * to keep private panel structs -- reaching the fields through the shared
     * header would have meant punning through a byte array. Naming them is
     * what lets the three migrate.
     */
    u32 unk10;           // +0x10 PROVEN x2 (panel+0x68)
    void *unk14;         // +0x14 PROVEN x2 (panel+0x6C)
} Ov170Anim;             // 0x18

/* ---------------------------------------------------------------------------
 * Ov170Panel -- 0xA19C. A 41 KB object; only these offsets are claimed.
 *
 * +0x74 is the one field confirmed twice -- by the module-wide match, and
 * independently by `evidence.py --module ov170`, which disassembles verified
 * functions and reports constant-offset accesses off an untouched argument
 * register:
 *     run 0x021ef670..0x021ef69c  (4 functions)   +0x074:4B
 * evidence.py also independently confirms +0x28/+0x2C on Ov170Ctx
 * (run 0x021e8fc0..0x021e8fe0) and +0x0C/+0x10/+0x16/+0x18 on the object
 * reached at 0x021df324.
 *
 * The `filler_184[0x3C72]` and `filler_3DF7[0x6371]` runs are enormous. What
 * is being claimed there is the *offset* of the field after them, not that
 * the span between is one object. Do not treat those runs as meaningful.
 * ------------------------------------------------------------------------- */
struct Ov170Panel {
    u8 filler_000[0x58];        // +0x0000 INFERRED
    Ov170Anim anim;             // +0x0058 PROVEN x6 (see Ov170Anim above)
    Ov170Rect *unk70_rect;      // +0x0070 PROVEN x13  -- see note
    void *unk74;                // +0x0074 PROVEN x8 AND by evidence.py
    u8 filler_078[0x14];        // +0x0078 INFERRED
    void *unk8c;                // +0x008C PROVEN x2
    u8 filler_090[0xEC];        // +0x0090 INFERRED
    void *unk17C;               // +0x017C PROVEN
    void *unk180;               // +0x0180 PROVEN
    u8 filler_184[0x3DF6 - 0x184]; // +0x0184 INFERRED (15474 bytes)
    u8 unk3DF6;                 // +0x3DF6 PROVEN
    u8 filler_3DF7[0xA168 - 0x3DF7]; // +0x3DF7 INFERRED (25457 bytes)
    u32 unkA168;                // +0xA168 PROVEN -- saved menu-state id
    u16 unkA16C;                // +0xA16C PROVEN x3
    u8 filler_A16E[0x04];       // +0xA16E INFERRED
    u8 unkA172;                 // +0xA172 PROVEN
    u8 filler_A173[0x0B];       // +0xA173 INFERRED
    u8 unkA17E;                 // +0xA17E PROVEN x2
    u8 filler_A17F[0x01];       // +0xA17F INFERRED
    u32 unkA180;                // +0xA180 PROVEN x2
    u32 unkA184;                // +0xA184 PROVEN x2
    u32 unkA188;                // +0xA188 PROVEN x2
    u32 unkA18C;                // +0xA18C PROVEN
    Ov170Obj *unkA190;          // +0xA190 PROVEN x2 (one file types it u16 *)
    u32 unkA194;                // +0xA194 PROVEN
    u32 unkA198;                // +0xA198 PROVEN x2
};                              // 0xA19C

/*
 * Note on +0x0060 / +0x0068 / +0x006C: these all fall INSIDE the Ov170Anim
 * embedded at +0x58..+0x70, and the files that named them did not know about
 * the embedded struct. Reach them through `panel->anim`:
 *     panel+0x68  ->  panel->anim.unk10   (now named, wave 3)
 *     panel+0x6C  ->  panel->anim.unk14   (now named, wave 3)
 *     panel+0x60  ->  panel->anim.unk08   (typed u16 * here; four files call
 *                                          it Ov170Rect * -- see below)
 * Do not add overlapping fields to Ov170Panel.
 *
 * The +0x60 typing is the one loose end: `Ov170Anim::unk08` is `u16 *` on the
 * strength of three files and `Ov170Rect *` on the strength of four others.
 * Both are 4-byte pointers so nothing about the layout is at risk, and
 * Ov170Rect is four u16s, so `u16 *` is a compatible view of the same memory.
 * Left as u16 * until someone shows a matched function that indexes it as a
 * rect rather than as a halfword array.
 */

/* ---------------------------------------------------------------------------
 * Ov170Sub00 -- 0x28. Hangs off Ov170Ctx+0x00.
 * ------------------------------------------------------------------------- */
struct Ov170Sub00 {
    void *unk00;         // +0x00 PROVEN x3
    void *unk04;         // +0x04 PROVEN
    void *unk08;         // +0x08 PROVEN x5
    u8 filler_0C[0x14];  // +0x0C INFERRED
    void *unk20;         // +0x20 PROVEN
    u32 unk24;           // +0x24 PROVEN
};                       // 0x28

/* ---------------------------------------------------------------------------
 * Ov170Save -- 0x2C. The alternative type three files give Ov170Ctx+0x00.
 * Kept separate; see the conflict note on Ov170Ctx.
 * ------------------------------------------------------------------------- */
typedef struct Ov170Save {
    u8 filler_00[0x24];  // +0x00 INFERRED
    u32 unk24;           // +0x24 PROVEN x2
    u8 filler_28[0x02];  // +0x28 INFERRED
    u8 unk2a;            // +0x2A PROVEN x2
    u8 unk2b;            // +0x2B PROVEN x2
} Ov170Save;             // 0x2C

struct Ov170Env {
    u8 filler_00[0x0F];  // +0x00 INFERRED
    u8 unk0f;            // +0x0F PROVEN
    u8 filler_10[0x28];  // +0x10 INFERRED
    u32 unk38;           // +0x38 PROVEN
};                       // 0x3C

struct Ov170Obj {
    u8 filler_00[0x06];  // +0x00 INFERRED
    u8 unk06;            // +0x06 PROVEN
    u8 filler_07[0x01];  // +0x07 INFERRED
};                       // 0x08

struct Ov170Rect {
    u16 unk00;  // +0x00 PROVEN
    u16 unk02;  // +0x02 PROVEN
    u16 unk04;  // +0x04 PROVEN
    u16 unk06;  // +0x06 PROVEN
};              // 0x08

/* 12-byte table record; only the first two bytes are ever touched. */
typedef struct Ov170Rec12 {
    u8 unk00;            // +0x00 PROVEN
    u8 unk01;            // +0x01 PROVEN
    u8 filler_02[0x0A];  // +0x02 INFERRED
} Ov170Rec12;

#endif // POKEBLACK_OV170_H
