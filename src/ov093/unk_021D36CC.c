#include "types.h"

// ov093 0x021d36cc..0x021d3d70: per-effect wrapper
// shells and count/table getters.

typedef struct UnkCtx {
    /* 0x00 */ u32 unk_00;
    /* 0x04 */ void *unk_04;
} UnkCtx;

u32 sub_021B9934(void *a0, u8 a1);
void sub_021D5B44(u32 a0, u16 a1);
void sub_021D5EFC(u32 a0);
void sub_021D5F08(u32 a0);
void sub_021D5F38(u32 a0, u32 a1);
void sub_021D5F90(u32 a0, u16 a1);
void sub_021D5FA4(u32 a0, u16 a1);
void sub_021D5FB8(u32 a0);
void sub_021D5FC0(u32 a0, u32 a1);
void sub_021D5FE4(u32 a0, u32 a1);
void sub_021D6008(u32 a0, u32 a1);
void sub_021D61F0(u32 a0);
void sub_021D6238(u32 a0, u32 a1);
void sub_021D6440(u32 a0, u32 a1);
void sub_021D64F0(u32 a0);
void sub_021D66B0(u32 a0, u16 a1);
void sub_021D66D0(u32 a0, u32 a1);
void sub_021D6730(u32 a0, u16 a1);
void sub_021D6738(u32 a0);
void sub_021D67D8(u32 a0, u16 a1);
void sub_021D6D5C(u32 a0, u16 a1);
void sub_021D6D70(u32 a0);

int sub_021D36CC(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D5F90(sub_021B9934(a0->unk_04, (u8)a2[0]), (u16)a2[1]);
    return 1;
}

int sub_021D36EC(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D5FA4(sub_021B9934(a0->unk_04, (u8)a2[0]), (u16)a2[1]);
    return 1;
}

int sub_021D377C(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D5FB8(sub_021B9934(a0->unk_04, (u8)a2[0]));
    return 1;
}

int sub_021D3894(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D5EFC(sub_021B9934(a0->unk_04, (u8)a2[0]));
    return 1;
}

int sub_021D38AC(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D5F08(sub_021B9934(a0->unk_04, (u8)a2[0]));
    return 1;
}

int sub_021D38C4(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D5F38(sub_021B9934(a0->unk_04, (u8)a2[0]), a2[1]);
    return 1;
}

int sub_021D3900(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D61F0(sub_021B9934(a0->unk_04, (u8)a2[0]));
    return 1;
}

int sub_021D3918(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D6238(sub_021B9934(a0->unk_04, (u8)a2[0]), a2[1]);
    return 1;
}

int sub_021D3988(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D66B0(sub_021B9934(a0->unk_04, (u8)a2[0]), (u16)a2[1]);
    return 1;
}

int sub_021D3A20(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D6730(sub_021B9934(a0->unk_04, (u8)a2[0]), (u16)a2[1]);
    return 1;
}

int sub_021D3A7C(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D5FE4(sub_021B9934(a0->unk_04, (u8)a2[0]), a2[1]);
    return 1;
}

int sub_021D3A98(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D6008(sub_021B9934(a0->unk_04, (u8)a2[0]), a2[1]);
    return 1;
}

int sub_021D3AB4(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D5FC0(sub_021B9934(a0->unk_04, (u8)a2[0]), a2[1]);
    return 1;
}

int sub_021D3AD0(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D6440(sub_021B9934(a0->unk_04, (u8)a2[0]), a2[1]);
    return 1;
}

int sub_021D3AEC(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D66D0(sub_021B9934(a0->unk_04, (u8)a2[0]), a2[1]);
    return 1;
}

int sub_021D3B08(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D5B44(sub_021B9934(a0->unk_04, (u8)a2[0]), (u16)a2[1]);
    return 1;
}

int sub_021D3B5C(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D64F0(sub_021B9934(a0->unk_04, (u8)a2[0]));
    return 1;
}

int sub_021D3C0C(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D6D5C(sub_021B9934(a0->unk_04, (u8)a2[0]), (u16)a2[1]);
    return 1;
}

int sub_021D3C2C(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D6D70(sub_021B9934(a0->unk_04, (u8)a2[0]));
    return 1;
}

int sub_021D3C90(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D6738(sub_021B9934(a0->unk_04, (u8)a2[0]));
    return 1;
}

int sub_021D3D50(UnkCtx *a0, void *a1, u32 *a2)
{
    sub_021D67D8(sub_021B9934(a0->unk_04, (u8)a2[0]), (u16)a2[1]);
    return 1;
}

