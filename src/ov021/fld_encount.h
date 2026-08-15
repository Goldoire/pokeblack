#ifndef POKEBLACK_OV021_FLD_ENCOUNT_H
#define POKEBLACK_OV021_FLD_ENCOUNT_H

/*
 * ov021 / field_encount.c -- wild-encounter driver.
 *
 * PROPOSAL for include/. Every offset below is byte-proven; the constraining
 * function address is on the field.  __FILE__ string "field_encount.c" is at
 * 0x021DDFA4; the TU spans 0x021A9ED8..0x021AA77C.
 *
 * Gen-4 ancestor: pokeheartgold's `FieldEncounter` (src/field_encounter.c).
 * The shape is recognisable, the offsets are not the same.
 */

typedef struct FieldSystem FieldSystem;

/*
 * Size 0x14, PROVEN by the allocation in FieldEncount_New (0x021A9ED8):
 *     movs r1,#0x14 ; movs r2,#1 ; ldr r3,=0x021DDFA4 ; str #0x62,[sp]
 *     blx sub_02030734 (heapId, 0x14, 1, "field_encount.c", 98)
 */
typedef struct FieldEncount {
    /* 0x00 */ FieldSystem *fieldSystem; // PROVEN 0x021A9ED8 (the ctor argument)
    /* 0x04 */ void *ovyManager;         // PROVEN 0x021A9ED8 = sub_02188C80(fieldSystem)
    /* 0x08 */ void *saveData;           // PROVEN 0x021A9ED8 = sub_020120F4(ovyManager);
                                         // sub_02012A38 / sub_02012844 take it
    /* 0x0C */ u8 *rates;                // PROVEN 0x021A9ED8 = sub_0216255C(sub_02012844(saveData));
                                         // indexed [0..6] as bytes by sub_021AA3E0
    /* 0x10 */ void *unk10;              // PROVEN 0x021A9ED8 = sub_021AA77C(heapId);
                                         // torn down by 0x021A9F28
} FieldEncount;                          // size 0x14

/*
 * The 12-byte "has the player moved" step counter that lives in the save file
 * (sub_02012A38 hands it out).  Size 12 PROVEN by the MI_CpuFill8(p, 0, 12) in
 * 0x021AA6F8; every field offset is proven by 0x021AA6F8 / 0x021AA728.
 */
typedef struct FieldEncountStep {
    /* 0x00 */ u16 x;      // PROVEN 0x021AA6F8/0x021AA728 = sub_0216D83C(player)
    /* 0x02 */ u16 y;      // PROVEN 0x021AA6F8/0x021AA728 = sub_0216D854(player)
    /* 0x04 */ u16 z;      // PROVEN 0x021AA6F8/0x021AA728 = sub_0216D86C(player)
    /* 0x06 */ u16 moved;  // PROVEN 0x021AA728 (halfword, set to 1 once the
                           // position differs; gates the counter)
    /* 0x08 */ u32 steps;  // PROVEN 0x021AA728 (word, saturates at 0xA000)
} FieldEncountStep;        // size 0x0C

#endif // POKEBLACK_OV021_FLD_ENCOUNT_H
