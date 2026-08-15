#include "types.h"

typedef struct Ov170Anim {
    u8 unk00[8];
    u16 *unk08;
    u16 unk0c;
    u16 unk0e;
    u8 unk10[8];
} Ov170Anim;

typedef struct Ov170Panel {
    u8 unk00[0x58];
    Ov170Anim unk58;
} Ov170Panel;

typedef struct Ov170Sub00 {
    u8 unk00[8];
    void *unk08;
} Ov170Sub00;

typedef struct Ov170Ctx {
    Ov170Sub00 *unk00;
    u8 unk04[0x16 - 0x04];
    u8 unk16;
    u8 unk17[0x2c - 0x17];
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_020061E4(u32 a0);
u32 sub_0201AA18(void *a0);
u32 sub_021DD930(Ov170Ctx *a0);
void sub_021DE158(Ov170Ctx *a0, u32 a1, u32 a2);
void sub_021ED6E4(Ov170Ctx *a0, u32 a1);
void sub_021DE5F8(Ov170Ctx *a0, u32 a1);
void sub_021DE66C(Ov170Ctx *a0, u16 *a1);

u32 sub_021E002C(Ov170Ctx *a0)
{
    Ov170Anim *s = &a0->unk2c->unk58;

    switch 