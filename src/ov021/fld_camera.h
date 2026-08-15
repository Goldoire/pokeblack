#ifndef POKEBLACK_OV021_FLD_CAMERA_H
#define POKEBLACK_OV021_FLD_CAMERA_H

/*
 * FieldCamera -- the overworld camera of ov021 (GameFreak's `field_camera.c`,
 * __FILE__ string at 0x021DDA28; TU spans 0x0218E018..0x0218FF30).
 * FieldSystem+0x10 points at one of these.
 *
 * PROPOSAL for include/. Gen-4 ancestor: pokeheartgold `Camera`.
 *
 * Size is 0x1B0, PROVEN by the allocation at 0x0218E028:
 *     movs r1,#0x1b ; lsls r1,r1,#4 ; movs r2,#1 ; blx sub_02030734
 *     (heapId, 0x1B0, 1, "field_camera.c", 128)
 *
 * The camera has three interchangeable MODES, selected by unk014 and dispatched
 * through three parallel tables of function pointers indexed by it:
 *   0x021DDA00  enter  (0x0218E13C)
 *   0x021DDA0C  set    (0x0218E124)
 *   0x021D3E44  update (0x0218E58C)
 * 0x021DDA00 and 0x021DDA0C are 3 entries each (0x0C bytes apart), so there are
 * exactly three modes.
 */

typedef struct FieldCamera {
    /* 0x000 */ u16 heapId;   // PROVEN 0x0218E018 (the 5th, stack-passed ctor
                              // argument); re-read by 0x0218E018 for sub_020490F4
    /* 0x002 */ u16 unk002;
    /* 0x004 */ void *unk004; // PROVEN 0x0218E018 = sub_020490F4(0x3C, heapId);
                              // released by sub_02049238 in 0x0218E0E4
    /* 0x008 */ void *unk008; // PROVEN 0x0218E018 = sub_020490F4(0x6C, heapId);
                              // released by sub_02049238 in 0x0218E0E4
    /* 0x00C */ void *unk00C; // PROVEN 0x0218E018 (ctor arg 3); acc 0x0218EC2C
    /* 0x010 */ u32 unk010;   // PROVEN 0x0218E018 (ctor arg 1); set by 0x0218E17C
    /* 0x014 */ u32 mode;     // PROVEN 0x0218E018 (ctor arg 2), 0x0218E124 (set),
                              // 0x0218E13C, 0x0218E58C, 0x0218E73C -- the mode index
    /* 0x018 */ VecFx32 *unk018; // PROVEN 0x0218EC60 (copied into unk01C),
                              // 0x0218E160 (2nd arg of sub_0218E18C)
    /* 0x01C */ VecFx32 *unk01C; // PROVEN 0x0218E284 (deref'd, 12-byte copy into
                              // unk048); acc 0x0218EC5C, cleared 0x0218EC54/0x0218E5F4
    /* 0x020 */ VecFx32 *unk020; // PROVEN 0x0218E298 (deref'd, 12-byte copy into
                              // unk024); ctor NULLs it; cleared by 0x0218E5EC
    /* 0x024 */ VecFx32 unk024;  // PROVEN 0x0218E018 (three words zeroed),
                              // 0x0218E298 (whole-struct copy target)
    /* 0x030 */ VecFx32 unk030;  // PROVEN 0x0218E018 (three words zeroed)
    /* 0x03C */ VecFx32 unk03C;  // PROVEN 0x0218F19C (whole-struct copy out)
    /* 0x048 */ VecFx32 unk048;  // PROVEN 0x0218E018 (zeroed), 0x0218E284/0x0218EC30/
                              // 0x0218EC90 (copy in), 0x0218ECB4 (copy out)
    /* 0x054 */ VecFx32 unk054;  // PROVEN 0x0218F18C (whole-struct copy out)
    /* 0x060 */ VecFx32 unk060;  // PROVEN 0x0218ECC4 (out) / 0x0218ECD4 (in)
    /* 0x06C */ VecFx32 unk06C;  // PROVEN 0x0218E018 (zeroed), 0x0218EC30/0x0218EC90 (in)
    /* 0x078 */ u16 unk078;   // PROVEN 0x0218E018, 0x0218E5FC (zeroed);
                              // acc 0x0218ED2C (get) / 0x0218ED34 (set)
    /* 0x07A */ u16 unk07A;   // PROVEN 0x0218E018, 0x0218E5FC (zeroed);
                              // acc 0x0218ED40 (get) / 0x0218ED48 (set)
    /* 0x07C */ u32 unk07C;   // PROVEN 0x0218E018 (= 0x78), 0x0218E5FC (zeroed);
                              // acc 0x0218ED54 (get) / 0x0218ED58 (set)
    /* 0x080 */ u16 unk080;   // PROVEN 0x0218E018 = sub_0207D184(...) (FX_AtanIdx)
    /* 0x082 */ u16 unk082;   // acc 0x0218ED50 returns &unk082
    /* 0x084 */ u16 unk084;   // acc 0x0218ED3C returns &unk084; read as u16 by 0x02189A80
    /* 0x086 */ u16 unk086;
    /* 0x088 */ u8 unk088[4 * 0x18]; // PROVEN 0x0218F114 (MI_CpuCopy8 of count*0x18
                              // bytes to here) and 0x0218F134 (MI_CpuFill8 of 0x60):
                              // four 0x18-byte entries
    /* 0x0E8 */ u8 unk0E8;    // PROVEN 0x0218F114 / 0x0218F134 -- how many of unk088
    /* 0x0E9 */ u8 unk0E9;    // PROVEN 0x0218E018 (= 1), 0x0218E160 (= 1);
                              // acc 0x0218F1B4 (get) / 0x0218F1AC (set)
    /* 0x0EA */ u16 unk0EA;   // PROVEN 0x0218E018 (= 0xFFFF, from the literal pool)
    /* 0x0EC */ struct FieldCamera *unk0EC; // PROVEN 0x0218F0D4 / 0x0218F0E8 /
                              // 0x0218F0F8: nullable, and the fields reached through
                              // it (+0x10, +0x28, +0x2C) are FieldCamera's own
    /* 0x0F0 */ u8 filler0F0[0x18C - 0xF0];
    /* 0x18C */ void *unk18C; // PROVEN 0x0218FE50 (nullable)
    /* 0x190 */ u8 filler190[0x1A8 - 0x190];
    /* 0x1A8 */ void *cbArg;  // PROVEN 0x0218E104 (the callback's 2nd argument)
    /* 0x1AC */ void (*cb)(struct FieldCamera *camera, void *arg);
                              // PROVEN 0x0218E018 (NULLed) / 0x0218E104 (called)
} FieldCamera;                // size 0x1B0

#endif // POKEBLACK_OV021_FLD_CAMERA_H
