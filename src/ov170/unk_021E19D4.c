/* COMPILER: dsi/1.1p1 (any dsi >= 1.1p1 works; the repo default dsi/1.1 does NOT).
 *
 *   python tools/scripts/cc.py src/ov170/unk_021E19D4.c --thumb --cc dsi/1.1p1
 *
 * dsi/1.1 forwards the incremented counter into the negation and drops the
 * `ldrh` reload that the ROM has at 0x021E1A16 / 0x021E1ABA; every dsi build
 * from 1.1p1 on re-loads it, which is what the ROM does.  sub_021E1A28 /
 * sub_021E1ACC match under both builds, so the whole TU is 4/4 on 1.1p1.
 */
#include "types.h"

/* Sub-object living inside the panel at +0x58; +0x0e is a u16 step counter. */
typedef struct Ov170Anim {
    u8 unk00[0x0e];
    u16 unk0e;
    u8 unk10[8];
} Ov170Anim;

typedef struct Ov170Panel {
    u8 unk00[0x58];
    Ov170Anim unk58;
    void *unk70;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

u32 sub_020260E0(void *a0);
void sub_021EDD38(Ov170Ctx *a0, s16 a1);
void sub_021EDF5C(Ov170Ctx *a0);
void sub_021EE008(Ov170Ctx *a0, u32 a1, u32 a2);

u32 sub_021E19D4(Ov170Ctx *a0)
{
    Ov170Panel *p = a0->unk2c;
    Ov170Anim *s = &p->unk58;
    u32 v;

    if (s->unk0e == 5) {
        v = sub_020260E0(p->unk70);
        if (v >= 0x22 && v <= 0x25) {
            sub_021EE008(a0, v - 0x22, 1);
        } else {
            sub_021EE008(a0, 0, 0);
        }
        sub_021EDF5C(a0);
        s->unk0e = 0;
        return 0;
    }
    s->unk0e++;
    sub_021EDD38(a0, -s->unk0e);
    return 1;
}

u32 sub_021E1A28(Ov170Ctx *a0)
{
    Ov170Panel *p = a0->unk2c;
    Ov170Anim *s = &p->unk58;
    u32 v;

    if (s->unk0e == 5) {
        v = sub_020260E0(p->unk70);
        if (v >= 0x22 && v <= 0x25) {
            sub_021EE008(a0, v - 0x22, 1);
        } else {
            sub_021EE008(a0, 0, 0);
        }
        sub_021EDF5C(a0);
        s->unk0e = 0;
        return 0;
    }
    s->unk0e++;
    sub_021EDD38(a0, (s16)s->unk0e);
    return 1;
}

u32 sub_021E1A78(Ov170Ctx *a0)
{
    Ov170Panel *p = a0->unk2c;
    Ov170Anim *s = &p->unk58;
    u32 v;

    if (s->unk0e == 5) {
        v = sub_020260E0(p->unk70);
        if (v >= 1 && v <= 4) {
            sub_021EE008(a0, v - 1, 1);
        } else {
            sub_021EE008(a0, 0, 0);
        }
        sub_021EDF5C(a0);
        s->unk0e = 0;
        return 0;
    }
    s->unk0e++;
    sub_021EDD38(a0, -s->unk0e);
    return 1;
}

u32 sub_021E1ACC(Ov170Ctx *a0)
{
    Ov170Panel *p = a0->unk2c;
    Ov170Anim *s = &p->unk58;
    u32 v;

    if (s->unk0e == 5) {
        v = sub_020260E0(p->unk70);
        if (v >= 1 && v <= 4) {
            sub_021EE008(a0, v - 1, 1);
        } else {
            sub_021EE008(a0, 0, 0);
        }
        sub_021EDF5C(a0);
        s->unk0e = 0;
        return 0;
    }
    s->unk0e++;
    sub_021EDD38(a0, (s16)s->unk0e);
    return 1;
}
