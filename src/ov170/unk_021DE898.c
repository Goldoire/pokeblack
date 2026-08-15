#include "types.h"

typedef struct Ov170Sub00 {
    void *unk00;
    u8 unk04[4];
    void *unk08;
    u8 unk0c[0x24 - 0x0c];
    u32 unk24;
} Ov170Sub00;

typedef struct Ov170Ctx {
    Ov170Sub00 *unk00;
} Ov170Ctx;

void sub_02007C34(void *a0, void *a1);
void *sub_02012F98(void *a0);

void sub_021DE898(Ov170Ctx *a0)
{
    Ov170Sub00 *s = a0->unk00;

    if (s->unk24 == 4 || s->unk24 == 5) {
        return;
    }
    sub_02007C34(sub_02012F98(s->unk00), s->unk08);
}
