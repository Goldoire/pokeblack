#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x70];
    void *unk70;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x16];
    u8 unk16;
    u8 unk17[0x2c - 0x17];
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_020260E4(void *a0, u8 a1);
void sub_021DD14C(Ov170Ctx *a0);
void sub_021EBA5C(Ov170Panel *a0, u32 a1);
void sub_021ED508(Ov170Ctx *a0, u32 a1, u32 a2);
void sub_021ED55C(Ov170Ctx *a0, u32 a1);
void sub_021EE3E4(Ov170Ctx *a0, u32 a1);
void sub_021EF670(Ov170Panel *a0);
void sub_021EF68C(Ov170Panel *a0);

u32 sub_021E63B0(Ov170Ctx *a0)
{
    u32 r;

    sub_021EBA5C(a0->unk2c, 0x18);
    sub_021DD14C(a0);
    if (a0->unk16 < 0x1E) {
        sub_020260E4(a0->unk2c->unk70, a0->unk16);
        sub_021EE3E4(a0, a0->unk16);
        sub_021EF670(a0->unk2c);
        r = 0x39;
    } else {
        sub_020260E4(a0->unk2c->unk70, (u8)(a0->unk16 - 0x1E));
        sub_021EE3E4(a0, a0->unk16 - 0x1E);
        sub_021EF68C(a0->unk2c);
        r = 0x46;
    }
    sub_021ED55C(a0, 1);
    sub_021ED508(a0, 0xE, 1);
    return r;
}
