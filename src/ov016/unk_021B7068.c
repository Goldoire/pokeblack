/*
 * Overlay 16 -- Wi-Fi Connection setup applet, AP scan-result helpers.
 *
 * !! COMPILER: tools/mwccarm/2.0/sp2p2, NOT the repo default dsi/1.1.
 */
#include "types.h"

void sub_021B8230(void *dst, const void *src, u32 size);
u16 sub_021B8378(void);
u16 sub_021B830C(u16 param0);
s32 sub_021B834C(u16 param0);
s32 sub_021B7F90(void *param0);
s32 sub_021B7FF8(s32 param0, u32 param1, u32 param2, u32 param3, u8 *param4);

extern u8 _021DC300[];

/* 8-byte scan entry: 6 raw bytes followed by a 16-bit tag. */
typedef struct UnkStruct021B7068 {
    u8 unk00[6];
    u16 unk06;
} UnkStruct021B7068;

void sub_021B7068(s32 param0, UnkStruct021B7068 *param1, const void *param2)
{
    s32 i;

    for (i = 0; i < param0; i++) {
        sub_021B8230(&param1[i], param2, 6);
        param1[i].unk06 = sub_021B8378();
        param1[i].unk06 = sub_021B830C(param1[i].unk06);
    }
}

s32 sub_021B782C(u8 *param0, void *param1)
{
    u8 *p = param0 + 6;
    s32 size = sub_021B834C(*(u16 *)(p + 2));

    if (size <= 0) {
        return -1;
    }

    if (p[0] != 0x70) {
        return -1;
    }

    sub_021B8230(param1, p + 6, size);
    return 0;
}

void sub_021B7F64(void *param0, u8 *param1, const u8 *param2, u32 param3)
{
    u32 i;

    for (i = 0; i < param3; i++) {
        u8 v = (u8)sub_021B7F90(param0);
        param1[i] = param2[i] ^ v;
    }
}

u8 sub_021B7FD0(u32 param0, u32 param1)
{
    s32 mask = -1;

    return (u8)(sub_021B7FF8(-1, param0, param1, 0, _021DC300) ^ mask);
}

void sub_021B813C(u8 *param0, s32 param1, u8 *param2)
{
    s32 half = param1 / 2;

    sub_021B8230(param2, param0 + half, half);
    sub_021B8230(param2 + half, param0, half);
    sub_021B8230(param0, param2, param1);
}
