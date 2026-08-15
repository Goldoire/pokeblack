#include "types.h"

typedef struct Ov170Env {
    u8 unk00[0x0f];
    u8 unk0f;
    u8 unk10[0x38 - 0x10];
    u32 unk38;
} Ov170Env;

typedef struct Ov170Panel {
    u8 unk00[0xA180];
    u32 unkA180;
    u32 unkA184;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x0c];
    Ov170Env *unk0c;
    u16 unk10;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk19;
    u8 unk1a[0x2c - 0x1a];
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_020307B0(Ov170Env *a0);
void sub_021DF040(Ov170Ctx *a0);
u32 sub_021DF1BC(void *a0, u32 a1, u32 *a2);
void sub_021EC000(void *a0, u32 a1, u32 a2);
void sub_021ED6E4(Ov170Ctx *a0, u32 a1);
u32 sub_021EF224(u32 a0, u32 a1);

void sub_021DF0BC(Ov170Ctx *a0)
{
    sub_021DF040(a0);
    sub_021ED6E4(a0, 0);
    a0->unk16 = 0xFF;
}

void sub_021DF128(void *a0)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        sub_021EC000(a0, i + 0x13, 0);
    }
}

u32 sub_021DF228(void *a0, u32 a1, u32 *a2)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        if (sub_021DF1BC(a0, a1, &a2[i]) == 1) {
            return i + 0x1E;
        }
    }
    return 0xFF;
}

u32 sub_021DF254(Ov170Ctx *a0)
{
    u32 r;
    u32 t;

    r = sub_021EF224(a0->unk2c->unkA180, a0->unk2c->unkA184);
    if (r != 0xFF) {
        t = r - 0x24 + a0->unk19;
        if (t >= a0->unk15) {
            t -= a0->unk15;
        }
        if (t == a0->unk14) {
            r = 0xFF;
        }
    }
    return r;
}

u32 sub_021DF324(Ov170Ctx *a0)
{
    u8 v;

    if (a0->unk18 == 0) {
        v = a0->unk0c->unk0f;
        if (a0->unk16 >= 0x1E) {
            v += 0x1E;
        }
        a0->unk16 = v;
    }
    sub_020307B0(a0->unk0c);
    return 0;
}

u32 sub_021DF378(Ov170Ctx *a0)
{
    a0->unk10 = (u16)a0->unk0c->unk38;
    sub_020307B0(a0->unk0c);
    return 0;
}
