#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x74];
    void *unk74;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

u32 sub_0202CDD4(void *a0, u32 a1);
u32 sub_021E066C(Ov170Ctx *a0);
void sub_021ED918(Ov170Ctx *a0, s32 a1);
u32 sub_021EF400(Ov170Ctx *a0);
u32 sub_021EF5C4(void *a0);

u32 sub_021E01B0(Ov170Ctx *a0)
{
    if (sub_021EF400(a0) != 0) {
        return 1;
    }
    return 0;
}

u32 sub_021E01C4(Ov170Ctx *a0)
{
    u32 r;

    r = sub_0202CDD4(a0->unk2c->unk74, 9);
    sub_021ED918(a0, 8);
    return r;
}

u32 sub_021E01E0(Ov170Ctx *a0)
{
    u32 r;

    r = sub_0202CDD4(a0->unk2c->unk74, 9);
    sub_021ED918(a0, -8);
    return r;
}
