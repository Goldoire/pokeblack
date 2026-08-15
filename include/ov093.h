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


/*
 * WAVE 3: the BattleSystem / BattleCore blocks below were replaced wholesale
 * by the battle-model worker's src/ov093/battle.h, which is this header's
 * layout with wave-2 evidence folded in -- same names, same grading, nothing
 * renamed or removed. Most of what used to be filler_020, filler_0C4 and
 * filler_24 is now named, because functions that verify N/N OK dereference
 * it. BattleScriptCtx, BattleSystemSlot, BattleQueue and BattleRecord are new.
 *
 * BattleCore::unk_04 is the battle FORMAT. 0x021B8670 switches it 0..3 and
 * answers 1, 2, 3, 1 battlers per side; 0x021B8640 answers 1, 3, 5, 5 target
 * slots. That is single / double / triple / rotation -- exactly gen 5's set,
 * which is a satisfying external check on a purely internal derivation.
 *
 * NAME COLLISION WARNING: `BattleSystemSlot` (0x28, at BattleSystem+0x020) is
 * NOT the same object as `BattleSlotRecord` (0x1C) further down. The names are
 * similar and the types are unrelated.
 *
 * ACTION: src/ov093/*.c include src/ov093/battle.h today. Switch them to
 * "ov093.h" and delete battle.h -- while it exists it wins the quoted-include
 * search and shadows this file.
 */

typedef struct BattleCore BattleCore;

/* ---------------------------------------------------------------------------
 * BattleRecord -- 0x18. 0x021BA6C0 copies one whole with three ldm/stm
 * register pairs, which is a six-word struct assignment and not a memcpy:
 *     core->unk_9C = bsys->unk_3F0;
 * That single statement is what types both ends.
 * ------------------------------------------------------------------------- */
typedef struct BattleRecord {
    u32 unk_00[6];  // +0x00 PROVEN as a 0x18 stride  -- 021BA6C0
} BattleRecord;     // 0x18

/* ---------------------------------------------------------------------------
 * BattleSystemSlot -- 0x28. Four of them at BattleSystem+0x020.
 *
 * 0x021B9F70 indexes them with a literal `* 0x28`, which fixes the stride;
 * BattleSystem+0x0C0 is a separately proven pointer and 0x020 + 4*0x28 lands
 * exactly on it, which fixes the count at four. 0x021BA02C returns the
 * addresses of +0x18 and +0x20, so both are sub-objects rather than scalars.
 * ------------------------------------------------------------------------- */
typedef struct BattleSystemSlot {
    void *unk_00;      // +0x00 PROVEN  -- 021B9F70, 021BA064
    u32 unk_04;        // +0x04 PROVEN  -- 021B9FAC
    u16 unk_08;        // +0x08 PROVEN  -- 021BA020, 021B9FAC
    u16 unk_0A;        // +0x0A PROVEN  -- 021BA004
    u32 unk_0C;        // +0x0C PROVEN  -- 021B9FBC
    u16 unk_10[4];     // +0x10 PROVEN  -- 021B9F84 (bounds-checks the index <4)
    u8 unk_18[0x08];   // +0x18 PROVEN as an address -- 021BA02C
    u8 unk_20[0x08];   // +0x20 PROVEN as an address -- 021BA02C
} BattleSystemSlot;    // 0x28

/* ---------------------------------------------------------------------------
 * BattleQueue -- 0xE8. Two of them at BattleSystem+0x0C8.
 *
 * 0x021B6AAC passes +0x0C8 and +0x1B0 to the same pair of functions with
 * index 0 and 1, which fixes the stride at 0xE8; and 0x0C8 + 2*0xE8 lands
 * exactly on the pointer array at +0x298, which fixes the count at two.
 * ------------------------------------------------------------------------- */
typedef struct BattleQueue {
    u8 filler_00[0x84];  // +0x00 INFERRED
    void *unk_84[4];     // +0x84 PROVEN  -- 021B9940
    u8 filler_94[0x54];  // +0x94 INFERRED
} BattleQueue;           // 0xE8


/* ---------------------------------------------------------------------------
 * BattleScriptCtx -- the context a battle-script opcode handler runs against.
 *
 * The opcode table at 0x021F01B0 is {handler, opcode-id} pairs and every
 * handler has the shape
 *     int op(BattleScriptCtx *ctx, void *a1, u32 *args);   // always returns 1
 * 0x021D36CC and 16 siblings (evidence.py's four accessor runs at 0x021D36CC,
 * 0x021D3894, 0x021D3A20 and 0x021D3C0C) all read +0x04 and hand it to
 * sub_021B9934 as its first argument.
 *
 * sub_021B9934 is byte-for-byte identical to sub_021B9940 -- twelve bytes,
 * `ldr r0,[r0, i*4 + 0x84]`, emitted twice back to back at 0x021B9934 and
 * 0x021B9940 -- and sub_021B9940 is matched N/N OK as
 * `BattleQueue::unk_84[i]`. 0x021B9358 calls sub_021B9934 with BattleSystem+
 * 0xC8 and BattleSystem+0x1B0, exactly as 0x021B92D4 calls sub_021B9940. So
 * +0x04 holds one of BattleSystem::unk_0C8[2].
 * ------------------------------------------------------------------------- */
typedef struct BattleScriptCtx {
    u32 unk_00;                     // +0x00 INFERRED (read 4B by 50 handlers)
    BattleQueue *unk_04;            // +0x04 PROVEN  -- 021D36CC and 23 siblings
    u8 filler_08[0x034 - 0x008];    // +0x08 INFERRED
    void *unk_034;                  // +0x34 INFERRED (021D3B74)
    u8 filler_038[0x054 - 0x038];   // +0x38 INFERRED
    void *unk_054;                  // +0x54 INFERRED (44 handlers read it)
    void *unk_058;                  // +0x58 INFERRED
    u8 filler_05C[0x0AC - 0x05C];   // +0x5C INFERRED
    void *unk_0AC;                  // +0xAC INFERRED (5 handlers)
    u8 filler_0B0[0x134 - 0x0B0];   // +0xB0 INFERRED
    void *unk_134;                  // +0x134 INFERRED
    void *unk_138;                  // +0x138 INFERRED
    void *unk_13C;                  // +0x13C INFERRED (021D3934, as 0x4F << 2)
    void *unk_140;                  // +0x140 INFERRED
    u8 filler_144[0x1A6 - 0x144];   // +0x144 INFERRED
    u8 unk_1A6;                     // +0x1A6 INFERRED
} BattleScriptCtx;                  // >= 0x1A7

/*
 * Sweeping all 92 opcode handlers for constant-offset loads off their first
 * argument gives exactly eleven distinct offsets -- 0x000, 0x004, 0x034,
 * 0x054, 0x058, 0x0AC, 0x134, 0x138, 0x13C, 0x140 and 0x1A6 -- which is why
 * everything between them is filler rather than a guess.
 */

/* ---------------------------------------------------------------------------
 * BattleSystem -- >= 0x474. The object every ov093 entry point takes.
 *
 * The tail bitfield at +0x473 is a bitfield and not a mask: the ROM does the
 * bic/orr write idiom and reads the bits individually.
 *
 * Size is still a LOWER BOUND -- +0x473 remains the highest offset any matched
 * function touches. The object is not allocated anywhere in ov093 (the seven
 * heap allocations in this overlay are 0xCC4, 0x212C, 0xBC0, 0x3B2C, 0x460,
 * 0xC08 and 0xBD0 bytes and none of them writes this shape), so it is built by
 * whichever overlay sets a battle up and hands the pointer in.
 * ------------------------------------------------------------------------- */
typedef struct BattleSystem {
    BattleCore *core;               // +0x000 PROVEN  -- 021B8588 and ~60 more
    void *unk_004;                  // +0x004 INFERRED (read as 4B by 021B6A70)
    void *unk_008;                  // +0x008 PROVEN  -- 021BA238
    void *unk_00C;                  // +0x00C INFERRED
    void *unk_010[4];               // +0x010 PROVEN  -- 021B8548, 021B9B10
    BattleSystemSlot unk_020[4];    // +0x020 PROVEN  -- 021B9F70 and 7 more
    void *unk_0C0;                  // +0x0C0 PROVEN  -- 021B871C
    u8 unk_0C4[4];                  // +0x0C4 PROVEN  -- 021B8564 (|| unk_010)
    BattleQueue unk_0C8[2];         // +0x0C8 PROVEN  -- 021B8F5C, 021B92D4
    void *unk_298[4];               // +0x298 PROVEN  -- 021BA094, 021BA128
    void *unk_2A8[4];               // +0x2A8 PROVEN  -- 021BA094, 021BA178
    void *unk_2B8;                  // +0x2B8 PROVEN  -- 021BA094
    u32 unk_2BC;                    // +0x2BC PROVEN  -- 021BA08C
    u8 filler_2C0[0x2C8 - 0x2C0];   // +0x2C0 INFERRED
    u8 unk_2C8[0x3E0 - 0x2C8];      // +0x2C8 INFERRED (address taken: 021EE644)
    void *unk_3E0[4];               // +0x3E0 PROVEN  -- 021B997C
    BattleRecord unk_3F0;           // +0x3F0 PROVEN  -- 021BA6C0
    u8 filler_408[0x428 - 0x408];   // +0x408 INFERRED
    /*
     * The battler slot table. 0x021B8B9C scans exactly six entries and
     * 0x021B8BEC returns 6 as its not-found sentinel, which is what fixes the
     * length; 0x021B6AAC..0x021B7050 write indices 0..5 individually.
     */
    u8 unk_428[6];                  // +0x428 PROVEN  -- 021B8B9C, 021B8CFC
    u8 filler_42E[0x002];           // +0x42E INFERRED
    u32 unk_430;                    // +0x430 INFERRED (RNG state; 021B919C)
    u32 unk_434;                    // +0x434 PROVEN  -- 021B91E4, clamped 99999
    u32 unk_438;                    // +0x438 INFERRED (021B9244)
    void *unk_43C;                  // +0x43C PROVEN
    u16 unk_440;                    // +0x440 PROVEN  -- 021BA5D0, 021BA5D8
    u16 unk_442;                    // +0x442 PROVEN  -- 021BA5C4
    u32 unk_444;                    // +0x444 PROVEN  -- 021B916C, 021BA618
    u8 unk_448[0x464 - 0x448];      // +0x448 INFERRED (address taken: 021D826C)
    u32 unk_464;                    // +0x464 INFERRED (021B6AAC)
    u16 unk_468;                    // +0x468 PROVEN
    u8 filler_46A[0x001];           // +0x46A INFERRED
    u8 unk_46B;                     // +0x46B INFERRED (021B6AAC)
    u8 unk_46C;                     // +0x46C PROVEN -- the current battler
    u8 unk_46D;                     // +0x46D INFERRED (021B6848)
    u8 unk_46E;                     // +0x46E PROVEN  -- 021B9B10
    u8 filler_46F[0x002];           // +0x46F INFERRED
    u8 unk_471;                     // +0x471 INFERRED (021B73C4)
    u8 filler_472[0x001];           // +0x472 INFERRED
    /* +0x473 PROVEN -- eight single-bit flags in one byte */
    u8 unk_473_0 : 1;
    u8 unk_473_1 : 1;
    u8 unk_473_2 : 1;               // 021B8590
    u8 unk_473_3 : 1;               // 021B91E4, 021B919C
    u8 unk_473_4 : 1;               // 021B9244
    u8 unk_473_5 : 1;
    u8 unk_473_6 : 1;               // 021B919C
    u8 unk_473_7 : 1;
} BattleSystem;                     // >= 0x474

/* ---------------------------------------------------------------------------
 * BattleCore -- >= 0xB4. Hangs off BattleSystem+0x000.
 *
 * unk_00 and unk_04 are the two things that decide the shape of the battle.
 * unk_04 is the FORMAT: 0x021B8670 switches it 0..3 and answers 1, 2, 3, 1
 * battlers per side, and 0x021B8640 answers 1, 3, 5, 5 target slots -- i.e.
 * single / double / triple / rotation, which is exactly Gen 5's set.
 * unk_00 is a second, independent axis, also 0..3, folded to 0,1,2,2 by
 * 0x021B86E4 and separately tested `<= 1` by 0x021B8630.
 * ------------------------------------------------------------------------- */
struct BattleCore {
    u32 unk_00;                  // +0x00 PROVEN  -- 021B86B8, 021B86E4
    u32 unk_04;                  // +0x04 PROVEN  -- 021B8588, 021B8670
    u8 unk_08[0x12];             // +0x08 PROVEN as an address -- 021B8714
    u16 unk_1A;                  // +0x1A PROVEN
    void *unk_1C;                // +0x1C INFERRED (read as 4B by 021B6AAC)
    u8 unk_20;                   // +0x20 PROVEN
    u8 unk_21;                   // +0x21 PROVEN
    u8 unk_22;                   // +0x22 PROVEN
    u8 unk_23;                   // +0x23 PROVEN
    /*
     * Three parallel per-battler tables. 0x021BA648, 0x021BA670 and 0x021BA698
     * index them with the same sub_021BA710() result, and the three runs are
     * back to back, which is what fixes the element counts at four.
     */
    void *unk_24[4];             // +0x24 PROVEN  -- 021BA648
    void *unk_34[4];             // +0x34 PROVEN  -- 021BA670
    u8 unk_44[4];                // +0x44 PROVEN  -- 021BA698, 021B997C
    u8 filler_48[0x58 - 0x48];   // +0x48 INFERRED
    u32 unk_58;                  // +0x58 PROVEN
    u32 unk_5C;                  // +0x5C PROVEN
    void *unk_60;                // +0x60 PROVEN
    void *unk_64;                // +0x64 PROVEN
    void *unk_68;                // +0x68 PROVEN
    u32 unk_6C;                  // +0x6C PROVEN
    u32 unk_70;                  // +0x70 PROVEN
    u8 filler_74[0x7F - 0x74];   // +0x74 INFERRED
    u8 unk_7F;                   // +0x7F PROVEN  -- 021BA1EC
    u8 unk_80;                   // +0x80 PROVEN
    u8 filler_81[0x8C - 0x81];   // +0x81 INFERRED
    u32 unk_8C;                  // +0x8C INFERRED (021BA54C)
    u8 unk_90;                   // +0x90 INFERRED (021B9120)
    u8 filler_91[0x03];          // +0x91 INFERRED
    void *unk_94;                // +0x94 PROVEN  -- 021B90F8, 021BA6C0
    u32 unk_98;                  // +0x98 PROVEN  -- 021BA6C0
    BattleRecord unk_9C;         // +0x9C PROVEN  -- 021BA6C0
};                               // >= 0xB4

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
