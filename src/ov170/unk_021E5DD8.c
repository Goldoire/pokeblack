#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[4];
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_021DD14C(Ov170Ctx *a0);
void sub_021EBA5C(Ov170Panel *a0, u32 a1);
void sub_021EBC58(Ov170Ctx *a0, u32 a1, u32 a2, u32 a3);
void sub_021EE038(Ov170Ctx *a0, u32 a1, u32 a2, u32 a3);

u32 sub_021E5DD8(Ov170Ctx *a0)
{
    sub_021EBA5C(a0->unk2c, 0x18);
    sub_021DD14C(a0);
    sub_021EBC58(a0, 0, 3, 0x1A);
    sub_021EE038(a0, 0, 1, 1);
    return 0x35;
}
