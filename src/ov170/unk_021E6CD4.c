#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x70];
    void *unk70;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

u32 sub_020260F0(void *a0);
void sub_021DD14C(Ov170Ctx *a0);
void sub_021EBA70(Ov170Panel *a0, u32 a1);
void sub_021EC000(Ov170Panel *a0, u32 a1, u32 a2);

u32 sub_021E6CD4(Ov170Ctx *a0)
{
    sub_021EBA70(a0->unk2c, 0x18);
    sub_021DD14C(a0);
    if (sub_020260F0(a0->unk2c->unk70) == 1) {
        sub_021EC000(a0->unk2c, 4, 1);
    }
    return 0x40;
}
