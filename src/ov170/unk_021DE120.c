#include "types.h"

typedef struct Ov170Rect {
    u16 unk00;
    u16 unk02;
    u16 unk04;
    u16 unk06;
} Ov170Rect;

typedef struct Ov170Panel {
    u8 unk00[0x60];
    Ov170Rect *unk60;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_021DDEFC(Ov170Ctx *a0, Ov170Rect *a1);

void sub_021DE120(Ov170Ctx *a0, u32 a1, u32 a2)
{
    Ov170Rect *r = a0->unk2c->unk60;

    r[0].unk00 = 0x24;
    r[0].unk02 = a2;
    r[0].unk04 = a1;
    r[0].unk06 = 1;
    sub_021DDEFC(a0, &r[0]);
    r[3].unk00 = a2;
    r[3].unk02 = a1;
    r[3].unk04 = a2;
    r[3].unk06 = 1;
    sub_021DDEFC(a0, &r[3]);
}
