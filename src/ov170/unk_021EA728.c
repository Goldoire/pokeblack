#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x60];
    void *unk60;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

extern const u8 _021F140C[];

void *FUN_02030734(u32 a0, u32 a1, u32 a2, const u8 *a3, u32 a4);
void sub_020307B0(void *a0);

void sub_021EA728(Ov170Ctx *a0)
{
    a0->unk2c->unk60 = FUN_02030734(0x4C, 0x1C, 0, _021F140C, 0x228F);
}

void sub_021EA750(Ov170Ctx *a0)
{
    sub_020307B0(a0->unk2c->unk60);
}
