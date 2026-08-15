#include "types.h"

// Header word of the 0x1F8-byte record pool zeroed by sub_021CC8C8: a 10-bit
// count in the low bits plus four flag bits at 28..31.
typedef struct UnkPool021CC8C8 {
    /* 0x00 */ u32 unk_00_0 : 10;
               u32 unk_00_10 : 18;
               u32 unk_00_28 : 1;
               u32 unk_00_29 : 1;
               u32 unk_00_30 : 1;
               u32 unk_00_31 : 1;
    /* 0x04 */ u8 unk_04[0x1F4];
} UnkPool021CC8C8;

void sub_02082BCC(void *dst, u8 value, u32 size);

void sub_021CC8B0(u32 *p, int a1, u32 a2)
{
    p[a1] = a2;
}

u32 sub_021CC8B8(u32 *p, int a1)
{
    return p[a1];
}

u32 sub_021CC8C0(u32 *p, int a1)
{
    return p[a1];
}

void sub_021CC8C8(UnkPool021CC8C8 *p)
{
    *(u32 *)p = 0;
    sub_02082BCC(p->unk_04, 0, sizeof(p->unk_04));
}

void sub_021CC95C(u32 *p, u32 a1)
{
    *p = a1;
}

u16 sub_021CC960(UnkPool021CC8C8 *p)
{
    return p->unk_00_0;
}

u32 sub_021CC96C(UnkPool021CC8C8 *p)
{
    return p->unk_00_30;
}

u32 sub_021CC99C(UnkPool021CC8C8 *p)
{
    return p->unk_00_28;
}

u32 sub_021CC9A4(UnkPool021CC8C8 *p)
{
    return p->unk_00_29;
}
