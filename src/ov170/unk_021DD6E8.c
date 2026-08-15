#include "types.h"

typedef struct Ov170Sub00 {
    void *unk00;
    u8 unk04[4];
    void *unk08;
    u8 unk0c[0x20 - 0x0c];
    void *unk20;
} Ov170Sub00;

typedef struct Ov170Panel {
    u8 unk00[0x17c];
    void *unk17C;
    void *unk180;
} Ov170Panel;

typedef struct Ov170Ctx {
    Ov170Sub00 *unk00;
    u8 unk04[0x14 - 0x04];
    u8 unk14;
    u8 unk15[0x2c - 0x15];
    Ov170Panel *unk2c;
} Ov170Ctx;

void *sub_0200CA1C(void *a0);
void *sub_0200CA38(void *a0);
void *sub_0201AF80(u32 a0, u32 a1);
void sub_0200CFA0(void *a0, void *a1);
void sub_020092AC(void *a0, u16 a1);
void *sub_0201747C(void *a0, u32 a1);
void sub_020179B8(void *a0, u32 a1);
void *sub_02017D30(void *a0);
void sub_02017D70(void *a0, void *a1);
void sub_020185C4(void *a0);
void *sub_0201AB28(void *a0, u32 a1);
void sub_020307B0(void *a0);
u32 sub_021DD25C(Ov170Ctx *a0, u16 a1, u32 a2, u32 a3, u32 a4);

void sub_021DD6E8(Ov170Ctx *a0, void *a1, u32 a2)
{
    void *p;

    sub_020179B8(a1, a2);
    p = sub_0201747C(a1, 0x4C);
    sub_0200CFA0(sub_0200CA1C(a0->unk00->unk00), p);
    sub_020307B0(p);
}

void sub_021DD8A8(Ov170Ctx *a0, u32 a1)
{
    void *p;
    void *q;

    if (a1 >= 0x1E) {
        p = sub_0201AB28(a0->unk00->unk08, a1 - 0x1E);
        q = sub_02017D30(p);
        sub_020185C4(p);
        sub_02017D70(p, q);
    }
}

void sub_021DD908(Ov170Ctx *a0, u32 a1)
{
    u16 r;

    r = sub_021DD25C(a0, (u16)a1, a0->unk14, 5, 0);
    sub_020092AC(a0->unk00->unk20, r);
}

void sub_021DD8D0(Ov170Ctx *a0)
{
    a0->unk2c->unk180 = sub_0201AF80(0x4C, 0);
    a0->unk2c->unk17C = sub_0200CA38(sub_0200CA1C(a0->unk00->unk00));
}

void sub_021DD8F8(Ov170Ctx *a0)
{
    sub_020307B0(a0->unk2c->unk180);
}
