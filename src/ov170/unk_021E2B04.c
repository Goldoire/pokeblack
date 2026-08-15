#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x70];
    void *unk70;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x16];
    u8 unk16;
    u8 unk17[0x2c - 0x17];
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_020260E4(void *a0, u8 a1);
void sub_021DD530(Ov170Ctx *a0);
void sub_021EA1E8(Ov170Ctx *a0);
void sub_021EBC58(Ov170Ctx *a0, u32 a1, u32 a2, u32 a3);
void sub_021ED55C(Ov170Ctx *a0, u32 a1);
void sub_021EE038(Ov170Ctx *a0, u32 a1, u32 a2, u32 a3);
void sub_021EE3E4(Ov170Ctx *a0, u32 a1);

u32 sub_021E2B04(Ov170Ctx *a0)
{
    sub_021DD530(a0);
    sub_021EA1E8(a0);
    sub_020260E4(a0->unk2c->unk70, 0x24);
    sub_021EE3E4(a0, 0x24);
    sub_021ED55C(a0, 1);
    sub_021EE038(a0, 0, 0, 1);
    sub_021EBC58(a0, a0->unk16, 1, 0x18);
    return 0x11;
}
