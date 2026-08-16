#ifndef POKEBLACK_OV093_BATTLE_H
#define POKEBLACK_OV093_BATTLE_H

#include "types.h"

/*
 * ===========================================================================
 *  PROPOSAL: replacement for the BattleSystem / BattleCore blocks of
 *  include/ov093.h  (worker: battle-model)
 * ===========================================================================
 *
 * This is include/ov093.h's layout with the wave-2 evidence folded in. Every
 * name the integrator already chose is kept byte-for-byte; nothing is renamed
 * and nothing is removed. What changes is that most of `filler_0C4`,
 * `filler_020` and `filler_24` is now named, because functions that verify
 * N/N OK dereference them.
 *
 * It is kept file-local (and the .c files in src/ov093 include THIS, not
 * include/ov093.h) only so the two definitions cannot collide in one
 * translation unit. Drop it into include/ov093.h and delete this file.
 *
 * FIELD GRADES, same convention as include/ov093.h: PROVEN = a function that
 * verifies N/N OK emits that displacement. INFERRED = filler that exists only
 * to place the next proven field, or an access seen in the ROM that no matched
 * function pins yet. Trailing addresses are the constraining functions.
 *
 * Three new types are introduced. NOTE: `BattleSystemSlot` (0x28, at
 * BattleSystem+0x020) is a different object from include/ov093.h's existing
 * `BattleSlotRecord` (0x1C) -- they are unrelated despite the similar name.
 */

typedef struct BattleCore BattleCore;
typedef struct BattleSystem BattleSystem;

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
 * The opcode table at 0x021F00E0..0x021F03C0 is 92 {handler, opcode-id} pairs,
 * ids 1..93 with no duplicates, and every handler has the shape
 *
 *     int op(BattleScriptCtx *ctx, u32 *state, const u32 *args);
 *
 * The SECOND parameter is not an object: it is a pointer to the script's
 * per-command step counter.  A one-shot opcode ignores it and returns 1; a
 * multi-frame opcode switches on *state, bumps it between phases, returns 0
 * for "call me again next frame" and 1 only when it is finished.  0x021D3630,
 * 0x021D3688 and 58 more are matched N/N OK on that reading.
 *
 * `args` is const in the five handlers that push a stack argument
 * (0x021D3A40, 0x021D3B28, 0x021D2FD8, 0x021D3CC8): only the const qualifier
 * lets CW prove the next argument load cannot alias the outgoing-argument
 * store, which is what the ROM's instruction order requires.  It is harmless
 * everywhere else.
 *
 * WHAT THE OBJECT IS.  0x021D3C44 answers it: when args[0] equals the byte at
 * +0x1A6 it calls sub_021CD9F4(ctx, ...), and otherwise it calls
 * sub_021B9B10(ctx->unk_00, args[0], ...) -- and sub_021B9B10 (matched, in
 * src/ov093/unk_021B9AC8.c) is exactly `sub_021CD9F4(bsys->unk_010[a1], a2)`.
 * So a BattleScriptCtx IS one of BattleSystem::unk_010[4]: the per-battler
 * controller.  +0x000 is its BattleSystem back-pointer and +0x1A6 is its own
 * battler index -- "if this command is addressed to me, run it here, else hand
 * it to the controller that owns that battler".
 * ------------------------------------------------------------------------- */
typedef struct BattleScriptCtx {
    BattleSystem *unk_00;           // +0x00 PROVEN  -- 021D3630, 021D3688, 021D3C44
    BattleQueue *unk_04;            // +0x04 PROVEN  -- 021D36CC and 30 siblings
    u8 filler_08[0x034 - 0x008];    // +0x08 INFERRED
    /*
     * The 0x021EFxxx object: sub_021EF9C0/9C8/9F4/FA94/FAD8/FB34/FC78 all take
     * it as their first argument and nothing else in ov093 does.
     */
    void *unk_034;                  // +0x34 PROVEN  -- 021D3B74, 021D3B88, 021D3D1C
    u8 filler_038[0x054 - 0x038];   // +0x38 INFERRED
    /*
     * The battle view / message controller (the 0x021EAxxx family, ov094's
     * btlv_effect).  Roughly forty of the ninety-two opcodes are "hand it a
     * job in phase 0, poll it in phase 1".
     */
    void *unk_054;                  // +0x54 PROVEN  -- 021D3688 and ~40 more
    /*
     * NOT a pointer -- an embedded object.  0x021D1BD0, 0x021D1CF4, 0x021D3138
     * and 0x021D2A20 form `ctx + 0x58` and pass it to sub_021EAF18 /
     * sub_021EAF50 (append a token / a value) and then to sub_021EA614 (show
     * the assembled string), so it is the text-format buffer.  Its extent is
     * bounded above by the next proven offset, +0xAC.
     */
    u8 unk_058[0x0AC - 0x058];      // +0x58 PROVEN as an address -- 021D1BD0
    void *unk_0AC;                  // +0xAC INFERRED (5 handlers)
    u8 filler_0B0[0x134 - 0x0B0];   // +0xB0 INFERRED
    u32 unk_134;                    // +0x134 PROVEN  -- 021D215C (as 0x4D << 2)
    u32 unk_138;                    // +0x138 PROVEN  -- 021D3934
    u32 unk_13C;                    // +0x13C PROVEN  -- 021D3934 (as 0x4F << 2)
    u32 unk_140;                    // +0x140 PROVEN  -- 021D3934
    u8 filler_144[0x1A6 - 0x144];   // +0x144 INFERRED
    u8 unk_1A6;                     // +0x1A6 PROVEN  -- 021D3C44, 021D1CF4
} BattleScriptCtx;                  // >= 0x1A7

/*
 * Sweeping all 92 opcode handlers for constant-offset loads off their first
 * argument gives exactly eleven distinct offsets -- 0x000, 0x004, 0x034,
 * 0x054, 0x058, 0x0AC, 0x134, 0x138, 0x13C, 0x140 and 0x1A6.  All eleven are
 * now dereferenced by at least one function that verifies N/N OK except
 * +0x0AC, so everything between them is still filler rather than a guess.
 *
 * ---------------------------------------------------------------------------
 * OPCODE MAP.  id -> handler, and what the handler demonstrably does.  Names
 * are deliberately left as addresses (the verifier resolves a function by its
 * sub_<ram> spelling), so this table is the naming proposal, not a rename.
 *
 *   1  021D3688  start an actor animation on unk_054, wait for it (EA788/798)
 *   2..4   021D36CC/36EC/377C   per-battler setters (5F90 / 5FA4 / 5FB8)
 *   5..11  021D370C..37FC      per-battler setters, 2-3 byte arguments
 *   12 021D381C  eight-slot bulk setter: 5EA8(p, i, args[i]) for i = 1..7
 *   13..19 021D3894..3934      per-battler setters; 19 reorders the queue from
 *                              ctx->unk_138/13C/140 then 63EC + 6580
 *   20 021D3D2C  5970          21 021D3988  66B0      22 021D3D50  67D8
 *   23 021D39A8  double loop over args[0] battler slots x args[1] entries
 *   24..33 021D3A20..3B5C      per-battler setters
 *   34 021D3B74  EF9F4(ctx->unk_034, args[0], {args[1]} by value, 0)
 *   35..37 021D3B88..3B9C      unk_034 setters
 *   38..47 021D3BC0..3D1C      per-battler setters and message forwarding; 42
 *                              is the "is this my battler" fork, 46 builds a
 *                              7-byte parameter block on the stack
 *   48..53 021D1FB4..21D4      print / animate on unk_054, then wait
 *   54 021D2234  8D8C -> 8E70 -> 021F81D0, one-shot
 *   55 021D1CF4  three-phase: build a name string into unk_058 with one of
 *                three prefixes (8CE8 / 9F70 / own battler), show it, then
 *                EA488 and EA4C4
 *   56 021D2424, 62 021D23B8   EA7C8 / EA7D8 then EA7E8 wait
 *   57 021D2278  three-phase print with a 0201BD28 allocation
 *   58 021D2320  EA40C/EA428 then 646C
 *   59 021D2374, 66 021D2580, 68 021D2628, 53 021D21D4  EA384/EA3A0 family
 *   60 021D1BD0  format a string via 1C40 + EAF18/EAF50 and show it
 *   61 021D1CAC  EA458/EA478
 *   63 021D29CC  add args[1..6] to six mon fields (_021EFF88), clamped to 255
 *   64 021D2490  three-phase: EF9C0, a sound from _021EFFAE[i].unk_02, then
 *                the paired message id _021EFFAE[i].unk_00
 *   65 021D2510  map args[0] in 1..4 to message ids 0x59/0x5A/0x5C/0x5B
 *   67 021D3D1C  EFC78(ctx->unk_034, 0, 0)
 *   69 021D266C  swap two battler slots and tell the view (EA904/EA950)
 *   70 021D2A20  fourteen-phase send-out sequence, owns _021F3B64
 *   71 021D2FD8  five-phase faint/return sequence
 *   72 021D3138  021F7D44 then a 0x43 message
 *   73 021D31A0  9C50 + EAA6C, then one of four messages 0x26..0x29
 *   74 021D324C  four-phase actor swap (EA768/778/7A8/7B8 + 66D0)
 *   75 021D32E0  seven-phase two-battler swap, owns _021F3B64+4
 *   76 021D344C  6C2C then EA868/EA878
 *   77 021D34B0  021F7998(args[0]) then wait
 *   78 021D34E8  EA3B8/EA3D4 gated on 3558(args[1])
 *   79 021D3568  EA3E8/EA3F8 on a pair of battlers
 *   80 021D35C8  66D8 then EA888/EA8A4
 *   81 021D2700  four-phase double swap (the two halves are the same code)
 *   82 021D2814  021F7E94 then wait
 *   83 021D284C  021F7EA4 with a 021F88BC bracket
 *   84 021D28AC  6C50 then EA8B4/EA8D4
 *   85 021D2930  EA1B8/EA1F0 with a 7AD4 lookup
 *   86 021D2990  021F878C(args[0]), one-shot
 *   87 021D25C4  EA838/EA850
 *   88 021D3630  like id 1 but EA768/EA778 with flag 1
 *   89 021D1F58, 91 021D1EB4  print with an extra 020061E4 sound at the end
 *   92 021D1E6C, 93 021D1F10  plain print-and-wait (EA678 / EA694)
 * ------------------------------------------------------------------------- */

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
struct BattleSystem {
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
};                                  // >= 0x474

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
 * Unchanged from include/ov093.h, repeated here only so this header is
 * self-contained while it lives outside include/.
 * ------------------------------------------------------------------------- */
typedef struct BattleOrderList {
    void *entries[6];    // +0x00 PROVEN
    u8 count;            // +0x18 PROVEN
    u8 filler_19[0x03];  // +0x19 INFERRED (alignment)
} BattleOrderList;       // 0x1C

typedef struct BattleSlotRecord {
    u8 unk_00[0x1C];  // +0x00 PROVEN as a 0x1C stride
} BattleSlotRecord;

typedef struct BattleSlotOwner {
    u32 unk_00;                // +0x00 PROVEN
    BattleSlotRecord items[1]; // +0x04 PROVEN -- flexible; indexed past [0]
} BattleSlotOwner;

#endif // POKEBLACK_OV093_BATTLE_H
