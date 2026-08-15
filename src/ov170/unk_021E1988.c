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

typedef struct Ov170Ctx {
    u8 unk00[0x16];
    u8 unk16;
    u8 unk17[0x2c - 0x17];
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_021DEA3C(Ov170Ctx *a0, u32 a1, u32 a2, u32 a3);
u32 sub_021DEAFC(Ov170Ctx *a0);
u32 sub_021EBFEC(Ov170Panel *a0, u32 a1);

u32 sub_021E1988(Ov170Ctx *a0)
{
    Ov170Panel *p = a0->unk2c;
    Ov170Anim *s = &p->unk58;
    u8 old;

    switch (s->unk0c) {
    case 0:
        if (sub_021EBFEC(p, 0xA) != 0) {
            break;
        }
        old = a0->unk16;
        a0->unk16 = (u8)*s->unk08;
        sub_021DEA3C(a0, old, old, 1);
        s->unk0c = 1;
        break;
    case 1:
        if (sub_021DEAFC(a0) == 0) {
            s->unk0c = 0;
            return 0;
        }
        break;
    }
    return 1;
}
