#include "types.h"

typedef struct Ov170Sub00 {
    u8 unk00[8];
    void *unk08;
} Ov170Sub00;

typedef struct Ov170Ctx {
    Ov170Sub00 *unk00;
    u8 unk04[0x16 - 0x04];
    u8 unk16;
} Ov170Ctx;

u32 sub_02017E1C(void *a0, u32 a1, u32 a2);
u32 sub_0202136C(u16 a0);
void *sub_0201AB28(void *a0, u32 a1);
u32 sub_021DD694(Ov170Ctx *a0, u32 a1);

u32 sub_021EA8CC(Ov170Ctx *a0)
{
    u32 r;
    void *p;

    r = a0->unk16 - 0x1E;
    if (sub_021DD694(a0, r) == 0) {
        return 1;
    }
    p = sub_0201AB28(a0->unk00->unk08, r);
    r = 0;
    if (sub_0202136C((u16)sub_02017E1C(p, 6, 0)) == 1) {
        r = 2;
    }
    return r;
}
