#ifndef POKEBLACK_OV093_BATTLE_H
#define POKEBLACK_OV093_BATTLE_H

#include "types.h"

// ov093 battle engine core.  PROPOSAL for include/ -- kept file-local until the
// integrator lands it.  Every named offset below is constrained by at least one
// function that verifies byte-exact against the ROM; the constraining address is
// in the trailing comment.  Runs of `u8 pad_*` are offsets nothing has pinned
// yet and must not be read as evidence of anything.

// Copied whole by 0x021BA6C0 as three ldm/stm register pairs, which is the
// six-word struct assignment `core->unk_9C = bsys->unk_3F0`.
typedef struct BattleRecord {
    /* 0x00 */ u32 unk_00[6];
} BattleRecord;                             // 0x18

// *(BattleSystem *)+0x00.  Holds the immutable description of the battle:
// mode, format, the participating parties, and the on-screen furniture.
typedef struct BattleCore {
    // 0..3, and separately tested `<= 1`.  Selects how many human/remote
    // participants there are; 0x021B86E4 folds it to 0,1,2,2.
    /* 0x00 */ u32 mode;                    // 021B86B8, 021B8630, 021B86E4
    // 0..3 = single / double / triple / rotation: 0x021B8670 answers
    // 1,2,3,1 battlers per side and 0x021B8640 answers 1,3,5,5 target slots.
    /* 0x04 */ u32 format;                  // 021B8588, 021B8640, 021B8670, 021B8CB0
    /* 0x08 */ u8 unk_08[0x12];             // 021B8714 returns &unk_08
    /* 0x1A */ u16 unk_1A;                  // 021B86DC
    /* 0x1C */ void *unk_1C;                // 021B6AAC (inferred)
    /* 0x20 */ u8 unk_20;                   // 021B86C0
    /* 0x21 */ u8 unk_21;                   // 021B734C (inferred)
    /* 0x22 */ u8 unk_22;                   // 021B86C8, 021B8F38
    /* 0x23 */ u8 unk_23;                   // 021B9090, 021B90BC
    // 0x021BA648 / 0x021BA670 / 0x021BA698 index all three of these with the
    // same `sub_021BA710(...)` result, and the three runs are back to back,
    // which fixes the element counts at 4.
    /* 0x24 */ void *unk_24[4];             // 021BA648
    /* 0x34 */ void *unk_34[4];             // 021BA670
    /* 0x44 */ u8 unk_44[4];                // 021BA698
    /* 0x48 */ u8 pad_48[0x10];
    /* 0x58 */ u32 unk_58;                  // 021B8748
    /* 0x5C */ u32 unk_5C;                  // 021B85A8
    /* 0x60 */ void *unk_60;                // 021B90E8, 021B9090, 021B90BC
    /* 0x64 */ void *unk_64;                // 021B90F0
    /* 0x68 */ void *unk_68;                // 021B8724, 021B8750
    /* 0x6C */ u32 unk_6C;
    /* 0x70 */ u32 unk_70;                  // 021B8630, 021BA080
    /* 0x74 */ u8 pad_74[0x0B];
    /* 0x7F */ u8 unk_7F;                   // 021BA1EC
    /* 0x80 */ u8 unk_80;                   // 021B85A0
    /* 0x81 */ u8 pad_81[0x0B];
    /* 0x8C */ u32 unk_8C;                  // 021BA54C (inferred)
    /* 0x90 */ u8 unk_90;                   // 021B9120 (inferred)
    /* 0x91 */ u8 pad_91[0x03];
    /* 0x94 */ void *unk_94;                // 021BA6C0, 021B90F8
    /* 0x98 */ u32 unk_98;                  // 021BA6C0
    /* 0x9C */ BattleRecord unk_9C;         // 021BA6C0 -- struct-assigned from
                                            //   BattleSystem+0x3F0 (ldm/stm x3)
} BattleCore;

// Four of these live at BattleSystem+0x20; 0x021B9F70 indexes them with a
// literal `* 0x28` and 0x021B871C reads the pointer that follows the last one,
// which fixes both the stride and the count.
typedef struct BattleSlot {
    /* 0x00 */ void *unk_00;                // 021B9F70, 021BA064
    /* 0x04 */ u32 unk_04;                  // 021B9FAC
    /* 0x08 */ u16 unk_08;                  // 021BA020, 021B9FAC
    /* 0x0A */ u16 unk_0A;                  // 021BA004
    /* 0x0C */ u32 unk_0C;                  // 021B9FBC
    /* 0x10 */ u16 unk_10[4];               // 021B9F84
    /* 0x18 */ u8 unk_18[0x08];             // 021BA02C returns &unk_18
    /* 0x20 */ u8 unk_20[0x08];             // 021BA02C returns &unk_20
} BattleSlot;                               // 0x28

// Two of these live at BattleSystem+0xC8.  0x021B6AAC passes +0xC8 and +0x1B0
// to the same pair of functions with index 0 and 1, which fixes the stride at
// 0xE8, and 0xC8 + 2*0xE8 lands exactly on the pointer array at 0x298.
typedef struct BattleQueue {
    /* 0x00 */ u8 pad_00[0x84];
    /* 0x84 */ void *unk_84[4];             // 021B9940
    /* 0x94 */ u8 pad_94[0x54];
} BattleQueue;                              // 0xE8

typedef struct BattleSystem {
    /* 0x000 */ BattleCore *core;           // 021B8588 and ~60 more
    /* 0x004 */ void *unk_004;              // 021B6A70 (inferred)
    /* 0x008 */ void *unk_008;              // 021BA238 (inferred)
    /* 0x00C */ void *unk_00C;
    /* 0x010 */ void *unk_010[4];           // 021B8548, 021B9B10 -- per battler
    /* 0x020 */ BattleSlot unk_020[4];      // 021B9F70 & co
    /* 0x0C0 */ void *unk_0C0;              // 021B871C
    /* 0x0C4 */ u8 unk_0C4[4];              // 021B8564 -- parallel to unk_010
    /* 0x0C8 */ BattleQueue unk_0C8[2];     // 021B8F5C, 021B6AAC
    /* 0x298 */ void *unk_298[4];           // 021BA094, 021BA128, 021BA178
    /* 0x2A8 */ void *unk_2A8[4];           // 021BA094, 021BA128, 021BA178
    /* 0x2B8 */ void *unk_2B8;              // 021BA094
    /* 0x2BC */ u32 unk_2BC;                // 021BA08C
    /* 0x2C0 */ u8 pad_2C0[0x08];
    /* 0x2C8 */ u8 unk_2C8[0x118];          // 021CD938/021EE644 take &unk_2C8
    /* 0x3E0 */ void *unk_3E0[4];           // 021B997C
    /* 0x3F0 */ BattleRecord unk_3F0;       // 021BA6C0, 021BA9C8, 021D787C
    /* 0x408 */ u8 pad_408[0x20];
    /* 0x428 */ u8 unk_428[6];              // 021B8B9C, 021B8BEC, 021B8CFC
    /* 0x42E */ u8 pad_42E[0x02];
    /* 0x430 */ u32 unk_430;                // 021B919C (inferred)
    // Accumulated and then clamped to 99999 by 0x021B91E4 -- a money or
    // battle-point total.
    /* 0x434 */ u32 unk_434;                // 021B91E4
    /* 0x438 */ u32 unk_438;                // 021B9244 (inferred)
    /* 0x43C */ void *unk_43C;
    /* 0x440 */ u16 unk_440;                // 021BA5D0
    /* 0x442 */ u16 unk_442;                // 021BA5C4
    /* 0x444 */ u32 unk_444;                // 021BA618
    /* 0x448 */ u8 unk_448[0x1C];           // 021D826C takes &unk_448
    /* 0x464 */ u32 unk_464;                // 021B6AAC (inferred)
    /* 0x468 */ u16 unk_468;                // 021B9090, 021B90BC
    /* 0x46A */ u8 pad_46A;
    /* 0x46B */ u8 unk_46B;                 // 021B6AAC (inferred)
    /* 0x46C */ u8 unk_46C;                 // 021B8FF4 -- the current battler
    /* 0x46D */ u8 unk_46D;                 // 021B6848 (inferred)
    /* 0x46E */ u8 unk_46E;                 // 021B9B10
    /* 0x46F */ u8 pad_46F[0x02];
    /* 0x471 */ u8 unk_471;                 // 021B73C4 (inferred)
    /* 0x472 */ u8 pad_472;
    // 0x021B8590 reads this with `lsls #29 / lsrs #31`, which is a one-bit
    // bitfield load and not a shift-and-mask of a plain u8.
    /* 0x473 */ u8 unk_473_0 : 1;           // 021B8590
                u8 unk_473_1 : 1;
                u8 unk_473_2 : 1;
                u8 unk_473_3 : 1;
                u8 unk_473_4 : 1;
                u8 unk_473_5 : 1;
                u8 unk_473_6 : 1;
                u8 unk_473_7 : 1;
} BattleSystem;

#endif // POKEBLACK_OV093_BATTLE_H
