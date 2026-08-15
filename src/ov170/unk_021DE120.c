#include "ov170.h"

/* panel+0x60 is Ov170Anim's `unk08` (the embedded anim runs +0x58..+0x70), so
 * it is reached as `anim.unk08` and cast rather than re-declared on the panel.
 * See the +0x60/+0x68/+0x6C note in include/ov170.h. */

void sub_021DDEFC(Ov170Ctx *a0, Ov170Rect *a1);

void sub_021DE120(Ov170Ctx *a0, u32 a1, u32 a2)
{
    Ov170Rect *r = (Ov170Rect *)a0->unk2c->anim.unk08;

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
