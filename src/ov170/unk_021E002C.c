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

    switch (s->unk0c) {
    case 0:
        sub_021DE5F8(a0, a0->unk16);
        s->unk0c++;
        /* fallthrough */
    case 1:
        if (sub_021DD930(a0) == 0) {
            sub_021DE66C(a0, s->unk08);
            s->unk0c = 0;
            return 0;
        }
        break;
    }
    return 1;
}

/* The `+ 0x1E` has to be folded into the initialiser of `n`, not written at the
 * call site: with `sub_021DE158(a0, a0->unk16, n + 0x1E)` mwcc schedules
 * `adds r0,r5,#0` ahead of `adds r2,#0x1e` and the two argument-setup
 * instructions come out swapped (88/92). */
u32 sub_021E0068(Ov170Ctx *a0)
{
    Ov170Anim *s = &a0->unk2c->unk58;
    u32 n;

    switch (s->unk0c) {
    case 0:
        n = sub_0201AA18(a0->unk00->unk08) + 0x1E;
        sub_021DE158(a0, a0->unk16, n);
        sub_021ED6E4(a0, 0);
        s->unk0c++;
        break;
    case 1:
        if (sub_021DD930(a0) == 0) {
            sub_021DE66C(a0, s->unk08);
            sub_020061E4(0x667);
            s->unk0c = 0;
            return 0;
        }
        break;
    }
    return 1;
}
