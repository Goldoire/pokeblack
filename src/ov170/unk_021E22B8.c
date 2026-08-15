#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x8c];
    void *unk8c;
    u8 unk90[0xA198 - 0x90];
    u32 unkA198;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

u32 sub_0201C6B4(void *a0);
u32 sub_021E8F60(Ov170Ctx *a0, u32 a1);

u32 sub_021E22B8(Ov170Ctx *a0)
{
    if (sub_0201C6B4(a0->unk2c->unk8c) == 0) {
        return 0xC;
    }
    return sub_021E8F60(a0, a0->unk2c->unkA198);
}
