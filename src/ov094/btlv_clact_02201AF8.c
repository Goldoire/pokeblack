#include "types.h"

typedef struct AnimVec3
{
    s32 x;
    s32 y;
    s32 z;
} AnimVec3;

typedef struct BtlvClact
{
    /* 0x00 */ u8 pad_00[0x7C];
    /* 0x7C */ u32 unk7C;
} BtlvClact;

typedef void (*ClactStepFunc)(void);

// Thumb function pointers as data symbols: mwcc emits undefined function
// symbols as STT_NOTYPE, which drops the Thumb bit the ROM stores.
extern const u8 _02201FF5[]; // sub_02201FF4
extern const u8 _0220203D[]; // sub_0220203C

void *sub_02201B20(void *sys, int a1, u32 a2, u32 a3, u32 a4, u32 a5, s16 x, s16 y,
                   u32 a8, u32 a9);
void sub_02201E04(BtlvClact *sys, int idx, u32 a2, AnimVec3 *scale, AnimVec3 *pos,
                  u32 a5, u32 a6, u32 a7, ClactStepFunc fn1, ClactStepFunc fn2);

void *sub_02201AF8(void *sys, int a1, u32 kind, s16 x, s16 y, u32 a5, u32 a6)
{
    return sub_02201B20(sys, a1, kind, kind + 1, kind + 2, kind + 3, x, y, a5, a6);
}

void sub_02201D5C(BtlvClact *sys, int idx, u32 a2, AnimVec3 *pos, u32 a4, u32 a5, u32 a6)
{
    AnimVec3 scale;

    scale.x = 0x1000;
    scale.y = 0x1000;
    scale.z = 0x1000;

    sub_02201E04(sys, idx, a2, &scale, pos, a4, a5, a6,
                 (ClactStepFunc)_02201FF5, (ClactStepFunc)_0220203D);

    sys->unk7C |= 1 << idx;
}
