#include "types.h"

typedef struct Ov170Panel {
    u8 unk00[0x74];
    void *unk74;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_021EC688(Ov170Ctx *a0);
void sub_021EC6F4(Ov170Ctx *a0);
void sub_021EF32C(void *a0);
void sub_021EF33C(void *a0);

void sub_021EA75C(Ov170Ctx *a0)
{
    sub_021EF32C(a0->unk2c->unk74);
    sub_021EC688(a0);
}

void sub_021EA770(Ov170Ctx *a0)
{
    sub_021EF33C(a0->unk2c->unk74);
    sub_021EC6F4(a0);
}

void sub_021EA784(Ov170Ctx *a0)
{
    sub_021EC688(a0);
    sub_021EF32C(a0->unk2c->unk74);
}
