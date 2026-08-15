#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0xA190];
    u16 *unkA190;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

extern const u8 _021F140C[];

u16 *FUN_02030734(u32 a0, u32 a1, u32 a2, const u8 *a3, u32 a4);

void sub_021EA808(Ov170Ctx *a0)
{
    u16 *p;

    p = FUN_02030734(0x804C, 4, 0, _021F140C, 0x2305);
    p[0] = 0;
    p[1] = 0;
    a0->unk2c->unkA190 = p;
}
