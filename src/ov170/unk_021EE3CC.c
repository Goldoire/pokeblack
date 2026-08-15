#include "types.h"

/* File-local placeholders; replace once the integrator publishes real types.
 * Offsets constrained by:
 *   ctx+0x2c   -> panel pointer (every function here)
 *   panel+0x70 -> list-menu object (sub_02025D14 / sub_0202616C / sub_020260E4)
 *   panel+0x74 -> slide/window object (see src/ov170/unk_021EF31C.c)
 *   panel+0xA168 -> u32, saved menu-state id (sub_021EECB0)
 */
typedef struct Ov170Panel {
    u8 unk00[0x70];
    void *unk70;
    void *unk74;
    u8 unk78[0xA168 - 0x78];
    u32 unkA168;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

/* 12-byte records; only the first two bytes are touched from this file. */
typedef struct Ov170Rec12 {
    u8 unk00;
    u8 unk01;
    u8 unk02[10];
} Ov170Rec12;

extern const u8 _021F0188[];
extern const Ov170Rec12 _021F0370[];
extern const Ov170Rec12 _021F0DCC[];

void sub_02025D14(void *a0);
void sub_020260E4(void *a0, u8 a1);
u8 *sub_0202616C(void *a0, u32 a1);
void sub_021EC08C(Ov170Panel *a0, u32 a1, u32 a2, u32 a3, u32 a4);
void sub_021ECC1C(Ov170Ctx *a0);
void sub_021EEFA4(Ov170Panel *a0, u32 a1, u32 a2, u32 a3, u32 a4);

void sub_021EE408(Ov170Ctx *a0, u32 a1);
void sub_021EE754(Ov170Ctx *a0, u32 a1);

void sub_021EE3CC(Ov170Ctx *a0)
{
    if (a0->unk2c->unk70 != NULL) {
        sub_02025D14(a0->unk2c->unk70);
        a0->unk2c->unk70 = NULL;
    }
}

void sub_021EE3E4(Ov170Ctx *a0, u32 a1)
{
    u8 *p;

    p = sub_0202616C(a0->unk2c->unk70, a1);
    sub_021EC08C(a0->unk2c, 4, p[0], p[1], 0);
}

void sub_021EE408(Ov170Ctx *a0, u32 a1)
{
    sub_021EE3E4(a0, a1);
    sub_021ECC1C(a0);
}

void sub_021EE454(Ov170Ctx *a0, u32 a1)
{
    sub_020260E4(a0->unk2c->unk70, (u8)a1);
    sub_021EE408(a0, a1);
}

void sub_021EE470(void)
{
}

void sub_021EE510(Ov170Ctx *a0, u32 a1)
{
    if (a1 != 6 && a1 != 7) {
        sub_021EE408(a0, a1);
    }
}

void sub_021EE520(Ov170Ctx *a0, u32 a1)
{
    u8 *p;

    p = sub_0202616C(a0->unk2c->unk70, a1);
    sub_021EEFA4(a0->unk2c, 0x54, 0x10, p[0], p[1]);
}

void sub_021EE544(Ov170Ctx *a0, u32 a1)
{
    const Ov170Rec12 *e;
    const u8 *hdr;

    hdr = _021F0188;
    if (a1 < 0x1E) {
        e = &_021F0DCC[a1];
    } else {
        e = &_021F0370[a1 - 0x1E];
    }
    sub_021EEFA4(a0->unk2c, e->unk00, e->unk01, hdr[0], hdr[1]);
}

void sub_021EE64C(Ov170Ctx *a0, u32 a1)
{
    if (a1 != 0x21 && a1 != 0x22) {
        sub_021EE408(a0, a1);
    }
}

void sub_021EE744(Ov170Ctx *a0, u32 a1)
{
    if (a1 != 0x22 && a1 != 0x23) {
        sub_021EE408(a0, a1);
    }
}

void sub_021EE7F4(Ov170Ctx *a0, u32 a1)
{
    if (a1 == 0x1F || a1 == 0x20) {
        sub_020260E4(a0->unk2c->unk70, 0x1E);
        a1 = 0x1E;
    } else if (a1 == 0x21 || a1 == 0x26 || a1 == 0x28 || a1 == 0x29 || a1 == 0x2A) {
        sub_020260E4(a0->unk2c->unk70, (u8)a0->unk2c->unkA168);
        a1 = a0->unk2c->unkA168;
    } else {
        sub_021EE408(a0, a1);
    }
    sub_021EE754(a0, a1);
    a0->unk2c->unkA168 = a1;
}

void sub_021EE95C(Ov170Ctx *a0, u32 a1)
{
    if (a1 != 7 && a1 != 8) {
        sub_021EE408(a0, a1);
    }
}

void sub_021EE9F4(Ov170Ctx *a0, u32 a1)
{
    if (a1 == 0x25 || a1 == 0x26) {
        sub_020260E4(a0->unk2c->unk70, 0x24);
        a1 = 0x24;
    } else if (a1 == 0x28 || a1 == 0x29 || a1 == 0x2A) {
        sub_020260E4(a0->unk2c->unk70, (u8)a0->unk2c->unkA168);
        a1 = a0->unk2c->unkA168;
    } else {
        sub_021EE408(a0, a1);
    }
    sub_021EE754(a0, a1);
    a0->unk2c->unkA168 = a1;
}

void sub_021EEB30(Ov170Ctx *a0, u32 a1)
{
    if (a1 != 0x22 && a1 != 0x23) {
        sub_021EE408(a0, a1);
    }
}

void sub_021EEBF4(Ov170Ctx *a0, u32 a1)
{
    if (a1 != 7 && a1 != 8) {
        sub_021EE408(a0, a1);
    }
}

void sub_021EEC1C(Ov170Ctx *a0, u32 a1)
{
    sub_020260E4(a0->unk2c->unk70, (u8)a1);
    sub_021EE408(a0, a1);
}

void sub_021EEC50(Ov170Ctx *a0, u32 a1)
{
    sub_020260E4(a0->unk2c->unk70, (u8)a1);
    sub_021EE408(a0, a1);
}

void sub_021EECB0(Ov170Ctx *a0, u32 a1)
{
    u32 v;

    if (a1 == 0 || a1 == 5 || a1 == 6) {
        sub_020260E4(a0->unk2c->unk70, (u8)a0->unk2c->unkA168);
        v = a0->unk2c->unkA168;
    } else {
        sub_021EE408(a0, a1);
        v = a1;
    }
    a0->unk2c->unkA168 = v;
}

void sub_021EEDD0(Ov170Ctx *a0, u32 a1)
{
    if (a1 != 0x22 && a1 != 0x23) {
        sub_021EE408(a0, a1);
    }
}

void sub_021EEE94(Ov170Ctx *a0, u32 a1)
{
    if (a1 != 7 && a1 != 8) {
        sub_021EE408(a0, a1);
    }
}

void sub_021EEF68(Ov170Ctx *a0, u32 a1)
{
    if (a1 != 0x21) {
        sub_021EE408(a0, a1);
    }
}

void sub_021EEF74(Ov170Panel *a0, u32 a1, u32 a2)
{
    u8 *p1;
    u8 *p2;

    p1 = sub_0202616C(a0->unk70, a1);
    p2 = sub_0202616C(a0->unk70, a2);
    sub_021EEFA4(a0, p1[0], p1[1], p2[0], p2[1]);
}
