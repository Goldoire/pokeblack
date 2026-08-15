#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x70];
    void *unk70;
    u8 unk74[0xA16C - 0x74];
    u16 unkA16C;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_020260E4(void *a0, u8 a1);
void sub_021ED55C(Ov170Ctx *a0, u32 a1);
void sub_021EE3E4(Ov170Ctx *a0, u32 a1);

u32 sub_021E6418(Ov170Ctx *a0)
{
    Ov170Panel *p = a0->unk2c;
    u32 v = 0x25;

    if (p->unkA16C != 0) {
        v = 0x24;
    }
    sub_020260E4(p->unk70, (u8)v);
    sub_021EE3E4(a0, v);
    sub_021ED55C(a0, 1);
    return 0x39;
}
