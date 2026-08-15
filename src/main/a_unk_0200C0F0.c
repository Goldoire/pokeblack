#include "types.h"

/* The 0x34 save block sub_020071CC hands out (sub_0200C0F0).
 *   +0x08 u16
 *   +0x0A u8 bitfield: 6 bits, then two single bits
 *   +0x0C u8[8], indexed unscaled and bulk-cleared by sub_0200C10C
 *   +0x14 u32 bitfield: 28 bits, then 4 bits
 */
typedef struct UnkStruct0200C0F0
{
    /* 0x00 */ u8 unk00[8];
    /* 0x08 */ u16 unk08;
    /* 0x0A */ u8 unk0A_0 : 6;
    /* 0x0A */ u8 unk0A_6 : 1;
    /* 0x0A */ u8 unk0A_7 : 1;
    /* 0x0B */ u8 unk0B;
    /* 0x0C */ u8 unk0C[8];
    /* 0x14 */ u32 unk14_0 : 28;
    /* 0x14 */ u32 unk14_28 : 4;
    /* 0x18 */ u32 unk18;
} UnkStruct0200C0F0;

UnkStruct0200C0F0 *sub_020071CC(void *a0, int a1);
void sub_02082BCC(void *dst, int val, u32 n);

UnkStruct0200C0F0 *sub_0200C0F0(void *a0)
{
    return sub_020071CC(a0, 0x34);
}

void sub_0200C0FC(UnkStruct0200C0F0 *a0, int a1, u8 a2)
{
    a0->unk0C[a1] = a2;
}

u8 sub_0200C104(UnkStruct0200C0F0 *a0, int a1)
{
    return a0->unk0C[a1];
}

void sub_0200C10C(UnkStruct0200C0F0 *a0)
{
    sub_02082BCC(a0->unk0C, 0, 8);
}

void sub_0200C11C(UnkStruct0200C0F0 *a0, u16 a1, u32 a2, u32 a3, int a4)
{
    volatile UnkStruct0200C0F0 *p = a0;

    a0->unk08 = a1;
    p->unk0A_0 = a2;
    p->unk0A_6 = a3;
    p->unk0A_7 = (a4 == 1);
}

void sub_0200C164(const UnkStruct0200C0F0 *a0, u32 *a1, u32 *a2, u32 *a3, u32 *a4)
{
    *a1 = a0->unk08;
    *a2 = a0->unk0A_0;
    *a3 = a0->unk0A_6;
    *a4 = a0->unk0A_7;
}

u32 sub_0200C184(UnkStruct0200C0F0 *a0)
{
    return a0->unk14_0;
}

void sub_0200C18C(UnkStruct0200C0F0 *a0, u32 a1)
{
    a0->unk14_0 = a1;
}

u8 sub_0200C1A4(UnkStruct0200C0F0 *a0)
{
    return a0->unk14_28;
}

void sub_0200C1B0(UnkStruct0200C0F0 *a0, u32 a1)
{
    a0->unk14_28 = a1;
}

u32 sub_0200C1C4(UnkStruct0200C0F0 *a0)
{
    return a0->unk18;
}

u32 sub_0200C1C8(UnkStruct0200C0F0 *a0)
{
    if (a0->unk18 < 0x1869F)
    {
        a0->unk18 = a0->unk18 + 1;
    }
    return a0->unk18;
}
