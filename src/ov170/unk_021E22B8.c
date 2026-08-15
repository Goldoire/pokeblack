#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x60];
    void *unk60;
    u8 unk64[0x8c - 0x64];
    void *unk8c;
    u8 unk90[0xA16C - 0x90];
    u16 unkA16C;
    u8 unkA16E[0xA172 - 0xA16E];
    u8 unkA172;
    u8 unkA173[0xA198 - 0xA173];
    u32 unkA198;
} Ov170Panel;

typedef struct Ov170Save {
    u8 unk00[0x24];
    u32 unk24;
} Ov170Save;

typedef struct Ov170Ctx {
    Ov170Save *unk00;
    u8 unk04[0x16 - 0x04];
    u8 unk16;
    u8 unk17[0x28 - 0x17];
    u32 unk28;
    Ov170Panel *unk2c;
} Ov170Ctx;

u32 sub_0201C6B4(void *a0);
u32 sub_021E8F60(Ov170Ctx *a0, u32 a1);
void sub_020307B0(void *a0);
void sub_021EBC58(Ov170Ctx *a0, u32 a1, u32 a2, u32 a3);
void sub_021EBCB4(Ov170Ctx *a0, u32 a1, u32 a2);

u32 sub_021E22B8(Ov170Ctx *a0)
{
    if (sub_0201C6B4(a0->unk2c->unk8c) == 0) {
        return 0xC;
    }
    return sub_021E8F60(a0, a0->unk2c->unkA198);
}

u32 sub_021E22E0(Ov170Ctx *a0)
{
    sub_020307B0(a0->unk2c->unk60);
    if (a0->unk2c->unkA172 == 1) {
        if (a0->unk00->unk24 == 3) {
            if (a0->unk2c->unkA16C == 0) {
                sub_021EBCB4(a0, 0, 0x18);
            } else {
                sub_021EBCB4(a0, 1, 0x18);
            }
        } else {
            sub_021EBC58(a0, a0->unk16, 1, 0x18);
        }
        a0->unk2c->unkA172 = 0;
    }
    return a0->unk28;
}
