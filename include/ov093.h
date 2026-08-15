#ifndef POKEBLACK_OV093_H
#define POKEBLACK_OV093_H

#include "global.h"

/*
 * ===========================================================================
 *  ov093 -- battle engine core
 * ===========================================================================
 *
 * Merged from src/ov093/unk_021B8548.c (45 functions, all N/N OK) and
 * src/ov093/unk_021B9AC8.c (16 functions, all N/N OK). Delete the local
 * copies and include this instead.
 *
 * FIELD GRADES: PROVEN = used by a function that verifies N/N OK, so the
 * compiler emitted that displacement and the ROM agreed. INFERRED = filler
 * that exists only to place the next proven field.
 *
 * ov093 is the largest unfinished module (252 KB) and this struct is its
 * spine. It is also the module where the claim table was most wrong: it
 * listed 2143 function starts and the recovery pass found 1487 more.
 */

typedef struct BattleCore BattleCore;

/* ---------------------------------------------------------------------------
 * BattleSystem -- >= 0x474. The object every ov093 entry point takes.
 *
 * Only one disagreement between the two files, at +0x000: unk_021B8548.c
 * types it `BattleCore *core`, unk_021B9AC8.c `void *core`. The typed form
 * wins -- unk_021B8548.c is the file that actually dereferences the core
 * object, so it is the one with information; `void *` was the other file's
 * shrug, and it still compiles against this.
 *
 * The tail bitfield at +0x473 is a bitfield and not a mask: the ROM does the
 * bic/orr write idiom and reads the bits individually. See WORKER_GUIDE.md,
 * "lsls #29 / lsrs #31 after ldrb is a u8 x:1 bitfield read".
 *
 * Size is a LOWER BOUND. +0x473 is the highest offset any matched function
 * touches; the object is certainly larger.
 * ------------------------------------------------------------------------- */
typedef struct BattleSystem {
    BattleCore *core;              // +0x000 PROVEN
    u8 filler_004[0x010 - 0x004];  // +0x004 INFERRED
    void *unk_010[4];              // +0x010 PROVEN x2 -- 4-slot pointer table
    u8 filler_020[0x0C0 - 0x020];  // +0x020 INFERRED
    void *unk_0C0;                 // +0x0C0 PROVEN
    u8 filler_0C4[0x43C - 0x0C4];  // +0x0C4 INFERRED (888 bytes, unexamined)
    void *unk_43C;                 // +0x43C PROVEN
    u8 filler_440[0x468 - 0x440];  // +0x440 INFERRED
    u16 unk_468;                   // +0x468 PROVEN
    u8 filler_46A[0x002];          // +0x46A INFERRED
    u8 unk_46C;                    // +0x46C PROVEN
    u8 filler_46D[0x006];          // +0x46D INFERRED
    /* +0x473 PROVEN -- eight single-bit flags in one byte */
    u8 unk_473_0 : 1;
    u8 unk_473_1 : 1;
    u8 unk_473_2 : 1;
    u8 unk_473_3 : 1;
    u8 unk_473_4 : 1;
    u8 unk_473_5 : 1;
    u8 unk_473_6 : 1;
    u8 unk_473_7 : 1;
} BattleSystem;                    // >= 0x474

/* ---------------------------------------------------------------------------
 * BattleCore -- >= 0x81. Hangs off BattleSystem+0x000.
 * Single declaration (unk_021B8548.c); no conflict to resolve.
 * ------------------------------------------------------------------------- */
struct BattleCore {
    u32 unk_00;                  // +0x00 PROVEN
    u32 unk_04;                  // +0x04 PROVEN
    u8 filler_08[0x12];          // +0x08 INFERRED
    u16 unk_1A;                  // +0x1A PROVEN
    u8 filler_1C[0x04];          // +0x1C INFERRED
    u8 unk_20;                   // +0x20 PROVEN
    u8 unk_21;                   // +0x21 PROVEN
    u8 unk_22;                   // +0x22 PROVEN
    u8 unk_23;                   // +0x23 PROVEN
    u8 filler_24[0x34];          // +0x24 INFERRED
    u32 unk_58;                  // +0x58 PROVEN
    u32 unk_5C;                  // +0x5C PROVEN
    void *unk_60;                // +0x60 PROVEN
    void *unk_64;                // +0x64 PROVEN
    void *unk_68;                // +0x68 PROVEN
    u32 unk_6C;                  // +0x6C PROVEN
    u32 unk_70;                  // +0x70 PROVEN
    u8 filler_74[0x0C];          // +0x74 INFERRED
    u8 unk_80;                   // +0x80 PROVEN
};                               // >= 0x81

/* ---------------------------------------------------------------------------
 * BattleOrderList -- 0x1C. Six pointer slots and a one-byte length at +0x18.
 *
 * sub_021B9C24 rotates a slot to the end, which is how a finished entry is
 * retired without disturbing the order of the rest -- and that rotation is
 * what pins both the 6-slot extent and the count byte's offset.
 *
 * `evidence.py --module ov093` confirms the count independently:
 *     run 0x021b9b40..0x021b9c24  (6 functions)   +0x018:1B
 * six byte-exact functions accessing exactly +0x18 at exactly one byte.
 * (Worker name: UnkList021B9B40.)
 * ------------------------------------------------------------------------- */
typedef struct BattleOrderList {
    void *entries[6];    // +0x00 PROVEN
    u8 count;            // +0x18 PROVEN by match AND by evidence.py
    u8 filler_19[0x03];  // +0x19 INFERRED (alignment)
} BattleOrderList;       // 0x1C

/* ---------------------------------------------------------------------------
 * A 0x1C-byte record array living at +0x04 of its owner
 * (sub_021B9AEC / sub_021B9AF8 index it). Worker names: UnkItem021B9AEC,
 * UnkOwner021B9AEC.
 * ------------------------------------------------------------------------- */
typedef struct BattleSlotRecord {
    u8 unk_00[0x1C];  // +0x00 PROVEN as a 0x1C stride; contents unexamined
} BattleSlotRecord;

typedef struct BattleSlotOwner {
    u32 unk_00;                // +0x00 PROVEN
    BattleSlotRecord items[1]; // +0x04 PROVEN -- flexible; indexed past [0]
} BattleSlotOwner;

/*
 * evidence.py --module ov093 also reports four accessor runs that all read
 * +0x004 as 4 bytes off their first argument:
 *     0x021d36cc..0x021d36ec   0x021d3894..0x021d3918
 *     0x021d3a20..0x021d3b5c   0x021d3c0c..0x021d3c2c
 * 17 byte-exact functions in total. That is a fifth object in this module
 * with a pointer or handle at +0x04, not yet named -- whoever claims that
 * address range should send the layout.
 */

#endif // POKEBLACK_OV093_H
