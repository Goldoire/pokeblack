#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0xA16C];
    u16 unkA16C;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x16];
    u8 unk16;
    u8 unk17[0x28 - 0x17];
    u32 unk28;
    Ov170Panel *unk2c;
} Ov170Ctx;

u32 sub_021E8F50(Ov170Ctx *a0, u32 a1);
void sub_021EA878(Ov170Ctx *a0, u32 a1);
void sub_021EBCB4(Ov170Ctx *a0, u32 a1, u32 a2);
u32 sub_021EBFEC(Ov170Panel *a0, u32 a1);
void sub_021EC000(Ov170Panel *a0, u32 a1, u32 a2);
void sub_021ECB20(Ov170Ctx *a0, u32 a1, u32 a2);
void sub_021ED108(Ov170Panel *a0, u32 a1);
void sub_021ED888(Ov170Panel *a0, u32 a1);

u32 sub_021E62FC(Ov170Ctx *a0)
{
    if (sub_021EBFEC(a0->unk2c, 0xA) == 1) {
        return 0x3B;
    }
    sub_021EA878(a0, 0);
    sub_021ED108(a0->unk2c, 0);
    sub_021EC000(a0->unk2c, 0xA, 0);
    sub_021EBCB4(a0, 3, 0x18);
    if (a0->unk16 < 0x1E) {
        sub_021ECB20(a0, 0x81, 1);
        sub_021ED888(a0->unk2c, 1);
    } else {
        sub_021ECB20(a0, 0x82, 1);
    }
    a0->unk2c->unkA16C = 0;
    a0->unk28 = 0x3D;
    return sub_021E8F50(a0, 6);
}
