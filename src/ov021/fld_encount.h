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

/*
 * The context block the wild-mon roll is handed. Filled field-by-field by
 * 0x021AA304, which is the only proof of the layout (the allocation is in the
 * caller's frame, so no size is proven -- >= 0x0E, and the caller reserves
 * 0x10 of stack for it).
 */
typedef struct FieldEncountInfo {
    /* 0x00 */ u32 unk00;        // PROVEN 0x021AA304 = sub_02013ED8(zoneId)
    /* 0x04 */ u32 unk04;        // PROVEN 0x021AA304 =
                                 //   sub_021AB580(sub_021AB0F0(sub_021A30C8(player)))
    /* 0x08 */ u8 weatherClass;  // PROVEN 0x021AA304 = sub_021AA69C(fieldSystem)
    /* 0x09 */ u8 unk09;         // PROVEN 0x021AA304 = sub_02012984(a1)
    /* 0x0A */ u16 zoneId;       // PROVEN 0x021AA304 = sub_02188C9C(fieldSystem)
    /* 0x0C */ u8 hour;          // PROVEN 0x021AA304 (RTCTime.hour, truncated)
    /* 0x0D */ u8 minute;        // PROVEN 0x021AA304 (RTCTime.minute, truncated)
} FieldEncountInfo;

/* NitroSDK RTCTime, as sub_0203F4CC fills it (three words, hour/minute/second). */
typedef struct RTCTime {
    /* 0x00 */ s32 hour;
    /* 0x04 */ s32 minute;
    /* 0x08 */ s32 second;
} RTCTime;

#endif // POKEBLACK_OV021_FLD_ENCOUNT_H
