#include "ov170.h"

/* panel+0x60 lives inside the Ov170Anim embedded at +0x58; reached as
 * `anim.unk08`.  See the +0x60/+0x68/+0x6C note in include/ov170.h. */

/* See src/ov170/unk_021EE3CC.c: rodata inside the 0x021EF770 blob that triage
 * still calls a Thumb function cannot be referenced by symbol without the
 * verifier ORing in a Thumb bit, so spell the table as an absolute address. */
extern const u8 _021F140C[];

void *FUN_02030734(u32 a0, u32 a1, u32 a2, const u8 *a3, u32 a4);
void sub_020307B0(void *a0);

void sub_021EA1C0(Ov170Ctx *a0)
{
    a0->unk2c->anim.unk08 =
        (u16 *)FUN_02030734(0x4C, 0xB8, 1, _021F140C, 0x2130);
}

void sub_021EA1E8(Ov170Ctx *a0)
{
    sub_020307B0(a0->unk2c->anim.unk08);
}
