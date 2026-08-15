#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x74];
    void *unk74;
    u8 unk78[0xA198 - 0x78];
    u32 unkA198;
} Ov170Panel;

typedef struct Ov170Save {
    u8 unk00[0x24];
    u32 unk24;
    u8 unk28[2];
    u8 unk2a;
    u8 unk2b;
} Ov170Save;

typedef struct Ov170Ctx {
    Ov170Save *unk00;
    u8 unk04[0x10 - 0x04];
    u16 unk10;
    u8 unk12;
    u8 unk13;
    u8 unk14;
    u8 unk15;
    u8 unk16;
    u8 unk17[0x28 - 0x17];
    u32 unk28;
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_021E22B8(Ov170Ctx *a0);
u32 sub_021E8F50(Ov170Ctx *a0, u32 a1);
u32 sub_021E95F8(Ov170Ctx *a0);
u32 sub_021E96E8(Ov170Ctx *a0);
u32 sub_021E9848(Ov170Ctx *a0);
void sub_021EBB64(Ov170Ctx *a0, u32 a1, u32 a2);
void sub_021EBC58(Ov170Ctx *a0, u32 a1, u32 a2, u32 a3);

u32 sub_021E78F4(Ov170Ctx *a0)
{
    sub_021EBC58(a0, a0->unk16, 1, 0x18);
    return 0x4B;
}

void sub_021E7D04(Ov170Ctx *a0)
{
    switch (a0->unk00->unk24) {
    case 2:
        a0->unk2c->unkA198 = sub_021E95F8(a0);
        break;
    case 3:
        a0->unk2c->unkA198 = sub_021E96E8(a0);
        break;
    case 4:
        a0->unk2c->unkA198 = sub_021E9848(a0);
        break;
    }
    sub_021E22B8(a0);
}

void sub_021E7D3C(Ov170Ctx *a0)
{
    sub_021EBB64(a0, a0->unk10, 0x18);
    if (a0->unk00->unk24 == 3) {
        a0->unk28 = 0x3C;
    } else {
        a0->unk28 = 0xE;
    }
    sub_021E8F50(a0, 6);
}
