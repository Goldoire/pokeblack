#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0xA194];
    u32 unkA194;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_021E8FE8(Ov170Ctx *a0, u32 a1);
void sub_021EA984(Ov170Ctx *a0);
void sub_021EBADC(Ov170Ctx *a0, u32 a1);
void sub_021EC000(Ov170Panel *a0, u32 a1, u32 a2);
void sub_021ED508(Ov170Ctx *a0, u32 a1, u32 a2);

void sub_021E8F20(Ov170Ctx *a0)
{
    sub_021EC000(a0->unk2c, 4, 0);
    sub_021ED508(a0, 0xE, 0);
    sub_021EBADC(a0, 0x18);
    sub_021EA984(a0);
    sub_021E8FE8(a0, 4);
}

u32 sub_021E8F50(Ov170Ctx *a0, u32 a1)
{
    a0->unk2c->unkA194 = 0;
    return a1;
}
