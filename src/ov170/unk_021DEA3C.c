#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0xA17E];
    u8 unkA17E;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_021DE8B4(Ov170Ctx *a0, u32 a1, u32 a2, u32 a3, u32 a4);

void sub_021DEA3C(Ov170Ctx *a0, u32 a1, u32 a2, u32 a3)
{
    sub_021DE8B4(a0, a1, a2, a3, 1);
}

void sub_021DEA4C(Ov170Ctx *a0, u32 a1, u32 a2)
{
    sub_021DE8B4(a0, a0->unk2c->unkA17E, a1, a2, 0);
}
