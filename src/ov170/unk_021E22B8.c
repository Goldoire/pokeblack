#include "ov170.h"

/* panel+0x60 lives inside the Ov170Anim embedded at +0x58; reached as
 * `anim.unk08`.  Ov170Ctx+0x00 takes the majority `Ov170Sub00 *` type in the
 * shared header, so the Save reading is a cast here -- see the conflict note
 * on Ov170Ctx in include/ov170.h. */

u32 sub_0201C6B4(void *a0);
u32 sub_021E8F60(Ov170Ctx *a0, u32 a1);
void sub_020307B0(void *a0);
void sub_021EBC58(Ov170Ctx *a0, u32 a1, u32 a2, u32 a3);
void sub_021EBCB4(Ov170Ctx *a0, u32 a1, u32 a2);

u32 sub_021E22B8(Ov170Ctx *a0)
{
    if (sub_0201C6B4(a0->unk2c->unk8c) == 0) {
        return 0xC;
    }
    return sub_021E8F60(a0, a0->unk2c->unkA198);
}

u32 sub_021E22E0(Ov170Ctx *a0)
{
    sub_020307B0(a0->unk2c->anim.unk08);
    if (a0->unk2c->unkA172 == 1) {
        if (((Ov170Save *)a0->unk00)->unk24 == 3) {
            if (a0->unk2c->unkA16C == 0) {
                sub_021EBCB4(a0, 0, 0x18);
            } else {
                sub_021EBCB4(a0, 1, 0x18);
            }
        } else {
            sub_021EBC58(a0, a0->unk16, 1, 0x18);
        }
        a0->unk2c->unkA172 = 0;
    }
    return a0->unk28;
}
