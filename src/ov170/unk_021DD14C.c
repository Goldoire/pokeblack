#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x74];
    void *unk74;
} Ov170Panel;

typedef struct Ov170Sub00 {
    void *unk00;
    void *unk04;
    void *unk08;
} Ov170Sub00;

typedef struct Ov170Ctx {
    Ov170Sub00 *unk00;
    u8 unk04[0x14 - 0x04];
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1a[0x1f - 0x1a];
    u8 unk1f;
    u8 unk20;
    u8 unk21;
    u8 unk22[0x2c - 0x22];
    Ov170Panel *unk2c;
} Ov170Ctx;

typedef struct Ov170Pos {
    u8 unk00[2];
    u16 unk02;
    u16 unk04;
} Ov170Pos;

void sub_02017E64(void *a0, u32 a1, u32 a2);
void sub_020075B0(void *a0, u32 a1, u32 a2, u32 a3);
u32 sub_020185F4(void *a0);
u32 sub_0201AA18(void *a0);
void *sub_0201AB28(void *a0, u32 a1);
void sub_02007664(void *a0, u32 a1, u32 a2);
void sub_0201A9C8(void *a0, u32 a1);
void sub_021EDAB0(Ov170Ctx *a0, u32 a1);
void sub_021DEC98(Ov170Ctx *a0, u32 a1, u32 a2);
u32 sub_021DEDCC(Ov170Ctx *a0, u32 a1);
void sub_021EB85C(Ov170Ctx *a0, u32 a1);
void sub_021EBFA8(Ov170Panel *a0, u32 a1, u32 a2);
void sub_021EC35C(Ov170Ctx *a0, u32 a1);
void sub_021ED904(Ov170Ctx *a0);
void sub_021ED9B4(Ov170Panel *a0);
void sub_021EDF5C(Ov170Ctx *a0);
void sub_021EF738(void *a0);
void sub_0201AB8C(void *a0, u32 a1, u32 a2, u32 a3);
s8 sub_021DEB14(Ov170Ctx *a0, s8 a1);
void *sub_021DD2D0(void *a0, u32 a1, u32 a2);
void sub_021EDECC(Ov170Ctx *a0, u32 a1);
void sub_021EE008(Ov170Ctx *a0, u32 a1, u32 a2);
void sub_021EE038(Ov170Ctx *a0, u32 a1, u32 a2, u32 a3);
void sub_021EF660(void *a0);

void sub_021DD14C(Ov170Ctx *a0)
{
    sub_021EE038(a0, a0->unk1f, a0->unk20, a0->unk21);
    sub_021EF660(a0->unk2c->unk74);
}

void sub_021DD16C(Ov170Ctx *a0, u32 a1)
{
    if (a1 == 0) {
        if (a0->unk14 == 0) {
            a0->unk14 = a0->unk15 - 1;
        } else {
            a0->unk14 = a0->unk14 - 1;
        }
        sub_021EBFA8(a0->unk2c, 0, 2);
    } else {
        if (a0->unk14 == a0->unk15 - 1) {
            a0->unk14 = 0;
        } else {
            a0->unk14 = a0->unk14 + 1;
        }
        sub_021EBFA8(a0->unk2c, 1, 4);
    }
    sub_021EC35C(a0, a0->unk14);
    sub_021DEC98(a0, sub_021DEDCC(a0, a0->unk14), a1);
}

void sub_021DD314(Ov170Ctx *a0, u32 a1, u32 a2)
{
    if (a2 < 0x1E) {
        sub_02007664(a0->unk00->unk04, a1, a2);
    } else {
        sub_0201A9C8(a0->unk00->unk08, a2 - 0x1E);
    }
}

void sub_021DD1C4(Ov170Ctx *a0, u32 a1)
{
    a0->unk19 = sub_021DEB14(a0, (s8)a1);
    sub_021EDECC(a0, a1);
    sub_021EE008(a0, 0, 0);
}

void sub_021DD1E8(Ov170Ctx *a0)
{
    sub_021ED904(a0);
    sub_021ED9B4(a0->unk2c);
    sub_021EDF5C(a0);
    sub_021EB85C(a0, 0);
    sub_021EF738(a0->unk2c->unk74);
}

u32 sub_021DD210(Ov170Ctx *a0, u32 a1, u32 a2)
{
    s32 d;

    d = a1 - a2;
    if (d < 0) {
        d = -d;
    }
    if (a1 > a2) {
        if ((u32)d >= ((u32)a0->unk15 >> 1)) {
            return 1;
        }
        return 0;
    }
    if ((u32)d < ((u32)a0->unk15 >> 1)) {
        return 1;
    }
    return 0;
}

void sub_021DD2B4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4)
{
    void *p;

    p = sub_021DD2D0(a0, a2, a1);
    if (p != NULL) {
        sub_02017E64(p, a3, a4);
    }
}

void sub_021DD414(Ov170Ctx *a0, const Ov170Pos *a1)
{
    sub_0201AB8C(a0->unk00->unk08, a1->unk04 - 0x1E, a1->unk02 - 0x1E, 0x4C);
}

void sub_021DD3DC(Ov170Ctx *a0, const Ov170Pos *a1)
{
    void *p;
    u32 v;

    p = sub_0201AB28(a0->unk00->unk08, a1->unk04 - 0x1E);
    v = sub_020185F4(p);
    sub_020075B0(a0->unk00->unk04, a0->unk14, a1->unk02, v);
    sub_021DD314(a0, a0->unk14, a1->unk04);
    sub_021EDAB0(a0, a0->unk14);
}

void sub_021DD42C(Ov170Ctx *a0, const Ov170Pos *a1)
{
    u32 i;

    i = a1->unk04 - 0x1E;
    while (i < sub_0201AA18(a0->unk00->unk08) - 1) {
        sub_0201AB8C(a0->unk00->unk08, i, i + 1, 0x4C);
        i++;
    }
}
