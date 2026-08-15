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
    u8 unk70[0xA17E - 0x70];
    u8 unkA17E;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x16];
    u8 unk16;
    u8 unk17[0x2c - 0x17];
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_020061E4(u32 a0);
u32 sub_021DDAE8(Ov170Ctx *a0);
void sub_021DE428(Ov170Ctx *a0, u32 a1, u32 a2);
void sub_021DE66C(Ov170Ctx *a0, u16 *a1);
void sub_021ED544(Ov170Ctx *a0, u32 a1);

u32 sub_021E09E0(Ov170Ctx *a0)
{
    Ov170Anim *s = &a0->unk2c->unk58;

    switch (s->unk0c) {
    case 0:
        sub_021ED544(a0, 7);
        sub_021DE428(a0, a0->unk16, a0->unk2c->unkA17E);
        s->unk0c = 1;
        break;
    case 1:
        if (sub_021DDAE8(a0) == 0) {
            sub_021DE66C(a0, s->unk08);
            sub_021ED544(a0, 6);
            sub_020061E4(0x667);
            s->unk0c = 0;
            return 0;
        }
        break;
    }
    return 1;
}
