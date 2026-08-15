#ifndef POKEBLACK_OV021_FLD_CAMERA_H
#define POKEBLACK_OV021_FLD_CAMERA_H

/*
 * FieldCamera -- the overworld camera of ov021 (GameFreak's `field_camera.c`,
 * __FILE__ string at 0x021DDA28; TU spans 0x0218E018..0x0218FF30).
 * FieldSystem+0x10 points at one of these.
 *
 * PROPOSAL for include/. Gen-4 ancestor: pokeheartgold `Camera`.
 *
 * Size is 0x1B0, proven by the allocation at 0x0218E028:
 *     movs r1,#0x1b ; ... ; lsls r1,r1,#4 ; movs r2,#1 ; blx FUN_02030734
 *     (heapId, 0x1B0, 1, "field_camera.c", 128)
 */

typedef struct FieldCamera {
    /* 0x000 */ u16 unk000;   // ctor: = heapId argument
    /* 0x002 */ u16 unk002;
    /* 0x004 */ u32 unk004;
    /* 0x008 */ u32 unk008;
    /* 0x00C */ void *unk00C; // acc 0x0218EC2C; ctor arg 2
    /* 0x010 */ void *unk010; // ctor arg 0; cleared by 0x0218F0D4
    /* 0x014 */ void *unk014; // ctor arg 1
    /* 0x018 */ u32 unk018;   // acc 0x0218EC60 copies unk018 -> unk01C
    /* 0x01C */ u32 unk01C;   // acc 0x0218EC5C (get) / 0x0218EC54, 0x0218E5F4 (clear)
    /* 0x020 */ u32 unk020;   // acc 0x0218E5EC (clear); ctor: = 0
    /* 0x024 */ u32 unk024;   // ctor: = 0
    /* 0x028 */ u32 unk028;   // acc 0x0218F0E8 (via unk0EC); ctor: = 0
    /* 0x02C */ u32 unk02C;   // set to 1 by 0x0218F0C0; ctor: = 0
    /* 0x030 */ u32 unk030;   // ctor: = 0
    /* 0x034 */ u32 unk034;   // ctor: = 0
    /* 0x038 */ u32 unk038;   // ctor: = 0
    /* 0x03C */ u8 filler03C[0x48 - 0x3C];
    /* 0x048 */ u32 unk048;   // ctor: = 0
    /* 0x04C */ u32 unk04C;   // ctor: = 0
    /* 0x050 */ u32 unk050;   // ctor: = 0
    /* 0x054 */ u8 filler054[0x6C - 0x54];
    /* 0x06C */ u32 unk06C;   // ctor: = 0
    /* 0x070 */ u32 unk070;   // ctor: = 0
    /* 0x074 */ u32 unk074;   // ctor: = 0
    /* 0x078 */ u16 unk078;   // acc 0x0218ED2C (get) / 0x0218ED34 (set); ctor: = 0
    /* 0x07A */ u16 unk07A;   // acc 0x0218ED40 (get) / 0x0218ED48 (set); ctor: = 0
    /* 0x07C */ u32 unk07C;   // acc 0x0218ED54 (get) / 0x0218ED58 (set); ctor: = 0x78
    /* 0x080 */ u16 unk080;
    /* 0x082 */ u16 unk082;   // acc 0x0218ED50 returns &unk082
    /* 0x084 */ u16 unk084;   // acc 0x0218ED3C returns &unk084; read as u16 by 0x02189A80
    /* 0x086 */ u16 unk086;
    /* 0x088 */ u8 filler088[0xE9 - 0x88];
    /* 0x0E9 */ u8 unk0E9;    // acc 0x0218F1B4 (get) / 0x0218F1AC (set); ctor: = 1
    /* 0x0EA */ u8 filler0EA[0x1B0 - 0xEA];
} FieldCamera;                // size 0x1B0

#endif // POKEBLACK_OV021_FLD_CAMERA_H
