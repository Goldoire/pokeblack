#include "types.h"

/* A 4-byte record allocated by sub_020082EC; the first halfword is a bitfield
 * and every accessor from 0x02008374 to 0x0200840C reads or writes one field
 * of it (bit 0-3, 4-5, 6, 7, 8, and sub_02008320 also initialises bits 9
 * and 10). */
typedef struct UnkStruct020082EC
{
    u16 unk00_0 : 4;
    u16 unk00_4 : 2;
    u16 unk00_6 : 1;
    u16 unk00_7 : 1;
    u16 unk00_8 : 1;
    u16 unk00_9 : 1;
    u16 unk00_A : 1;
    u16 unk00_B : 5;
    u16 unk02;
} UnkStruct020082EC;

extern u8 _0209DD64[];
extern u8 _020A70A0[];

void sub_020362A4(void *a0);
void *sub_02030734(u16 a0, u32 a1, u32 a2, void *a3, u32 a4);
void sub_02082D44(void *dst, const void *src, u32 n);
void sub_02082BCC(void *dst, int val, u32 n);
void sub_020461D4(u8 a0);
void sub_02008320(UnkStruct020082EC *a0);

void sub_020082DC(void)
{
    sub_020362A4(_0209DD64);
}

UnkStruct020082EC *sub_020082EC(int a0)
{
    UnkStruct020082EC *p;

    p = (UnkStruct020082EC *)sub_02030734((u16)a0, 4, 0, _020A70A0, 0x4D);
    sub_02008320(p);
    return p;
}

void sub_02008314(void *dst, const void *src)
{
    sub_02082D44(dst, src, 4);
}

void sub_02008320(UnkStruct020082EC *a0)
{
    volatile UnkStruct020082EC *p = a0;

    sub_02082BCC(a0, 0, 4);
    p->unk00_0 = 1;
    p->unk00_4 = 0;
    p->unk00_6 = 0;
    p->unk00_7 = 0;
    p->unk00_8 = 0;
    p->unk00_9 = 1;
    p->unk00_A = 0;
}

u16 sub_02008374(UnkStruct020082EC *a0)
{
    return a0->unk00_0;
}

void sub_0200837C(UnkStruct020082EC *a0, u32 a1)
{
    a0->unk00_0 = a1;
}

u16 sub_02008390(UnkStruct020082EC *a0)
{
    return a0->unk00_4;
}

void sub_02008398(UnkStruct020082EC *a0, u32 a1)
{
    a0->unk00_4 = a1;
}

u16 sub_020083AC(UnkStruct020082EC *a0)
{
    return a0->unk00_7;
}

void sub_020083B4(UnkStruct020082EC *a0, u32 a1)
{
    a0->unk00_7 = a1;
}

u16 sub_020083C8(UnkStruct020082EC *a0)
{
    return a0->unk00_6;
}

void sub_020083D0(UnkStruct020082EC *a0, u32 a1)
{
    a0->unk00_6 = a1;
}

u16 sub_020083E4(UnkStruct020082EC *a0)
{
    return a0->unk00_8;
}

void sub_020083EC(UnkStruct020082EC *a0, u32 a1)
{
    a0->unk00_8 = a1;
    sub_020461D4((u8)a0->unk00_8);
}
