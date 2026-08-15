#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x6c];
    void *unk6c;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

void *sub_02021518(u32 a0);
void sub_02021540(void *a0);
void sub_0202155C(void *a0, u32 a1, u32 a2, u32 a3);
void sub_020215A0(void *a0, u32 a1);

void sub_021DCDB8(Ov170Ctx *a0)
{
    a0->unk2c->unk6c = sub_02021518(0x4C);
    sub_0202155C(a0->unk2c->unk6c, 0, 0x200, 0x4C);
}

void sub_021DCDD8(Ov170Ctx *a0)
{
    sub_020215A0(a0->unk2c->unk6c, 0);
    sub_02021540(a0->unk2c->unk6c);
}
