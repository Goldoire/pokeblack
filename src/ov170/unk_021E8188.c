#include "types.h"

typedef struct Ov170Obj {
    u8 unk00[6];
    u8 unk06;
} Ov170Obj;

typedef struct Ov170Panel {
    u8 unk00[0xA190];
    Ov170Obj *unkA190;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_021DE7B4(Ov170Ctx *a0);
void sub_021DE7C8(Ov170Ctx *a0);
u32 sub_021E8F50(Ov170Ctx *a0, u32 a1);
void sub_021ECA24(Ov170Obj *a0);
u32 sub_021EC994(Ov170Obj *a0);

u32 sub_021E8188(Ov170Ctx *a0)
{
    sub_021DE7C8(a0);
    if (sub_021EC994(a0->unk2c->unkA190) == 0) {
        if (a0->unk2c->unkA190->unk06 != 0) {
            return sub_021E8F50(a0, 0x5C);
        }
        sub_021ECA24(a0->unk2c->unkA190);
        sub_021DE7B4(a0);
        return sub_021E8F50(a0, 0x5B);
    }
    return 0x5A;
}
