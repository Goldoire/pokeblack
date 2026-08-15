#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x70];
    void *unk70;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

u32 sub_020260E0(void *a0);
void sub_021EE008(Ov170Ctx *a0, u32 a1, u32 a2);

u32 sub_021E8A58(Ov170Ctx *a0)
{
    sub_021EE008(a0, sub_020260E0(a0->unk2c->unk70) - 1, 1);
    return 0x61;
}
