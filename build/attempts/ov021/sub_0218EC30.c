/*
 * ov021 field_camera.c 0x0218EC30 -- BANKED at 29/36, first diff +0x2.
 *
 * The body is byte-exact. The ONLY difference is the order of the two
 * parameter-save moves in the prologue:
 *     ROM:  adds r4,r1,#0 ; adds r5,r0,#0     (src saved first)
 *     mine: adds r5,r0,#0 ; adds r4,r1,#0     (camera saved first)
 *
 * The sibling 0x0218EC90 has the same prologue and DOES match from
 * `camera->unk048 = *src; camera->unk06C = *src;` -- so a leading pointer
 * store `camera->unk01C = src;` is what flips CW's save order. Tried:
 * the store first / middle / last, a local alias for src, and swapping the
 * two vector copies. "first" is the closest (29/36); "last" reorders the whole
 * body (8/40).
 *
 * Every offset it touches (0x1C, 0x48, 0x6C) is already proven by matched
 * functions in src/ov021/fld_camera.c, so this is a codegen question only.
 */
#include "types.h"
#include <nitro/fx/fx.h>

#include "fld_camera.h"

void sub_0218EC30(FieldCamera *camera, VecFx32 *src)
{
    camera->unk01C = src;
    camera->unk06C = *src;
    camera->unk048 = *src;
}
