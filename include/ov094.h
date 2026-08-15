#ifndef POKEBLACK_OV094_H
#define POKEBLACK_OV094_H

#include "global.h"
#include "gf_fwd.h"

/*
 * ===========================================================================
 *  ov094 -- battle animation script commands
 * ===========================================================================
 *
 * Merged from the four src/ov094/anim_scrcmd_*.c files. Delete the local
 * copies and include this instead.
 *
 * CONFIDENCE: HIGH for the PROVEN offsets. `verify_functions.py
 * ov094/anim_scrcmd` reports 26/26 OK, so every displacement these files emit
 * is byte-exact against the ROM.
 *
 * A command is  BOOL cmd(ScriptContext *ctx, void *data)  where `data` is
 * ctx->data; the VM itself lives in main (sub_0201134C is ScriptReadWord), so
 * ScriptContext is registered opaque in gf_fwd.h rather than here.
 */

/* ---------------------------------------------------------------------------
 * BattleAnimScript -- 0x240. Declared in all four files.
 *
 * CONFLICT RESOLVED, and it was only a typing difference, not an offset one:
 * three files spelled +0x008..+0x237 as one flat `u8 pad_008[0x238 - 0x008]`,
 * while anim_scrcmd_021FB6F4.c split it as `pad_008[0xCC-0x08]` followed by
 * `void *unk0CC[(0x238 - 0x0CC) / 4]` because that file actually indexes the
 * pointer table. Every named offset agrees across all four. The split version
 * wins: it is strictly more informative and lays out identically.
 *
 * evidence.py reports 0 proven accesses for these functions (its liveness
 * heuristic loses arg1 across the ScriptReadWord calls); the 26/26 match is
 * the evidence.
 * ------------------------------------------------------------------------- */
typedef struct BattleAnimScript {
    u32 unk000;                          // +0x000 PROVEN (|= 0x20 in sub_021FB574)
    u32 unk004;                          // +0x004 PROVEN
    u8 pad_008[0x0CC - 0x008];           // +0x008 INFERRED (filler)
    void *unk0CC[(0x238 - 0x0CC) / 4];   // +0x0CC PROVEN as an indexed pointer
                                         //   table (anim_scrcmd_021FB6F4.c)
    u16 unk238;                          // +0x238 INFERRED -- see note
    u16 unk23A;                          // +0x23A INFERRED -- see note
    u32 unk23C;                          // +0x23C PROVEN (all four files)
} BattleAnimScript;

/*
 * Note on +0x238/+0x23A: nothing in the matched code touches either. Only
 * their combined 4 bytes are load-bearing, because that is what places
 * unk23C at 0x23C. The split into two u16s is a guess and is flagged as such;
 * do not build on it.
 */

/* ---------------------------------------------------------------------------
 * AnimVec3 -- 0x0C.
 *
 * CONFLICT RESOLVED, and upgraded: anim_scrcmd_021FACAC.c and
 * anim_scrcmd_021FB6F4.c both declared `AnimVec3 { s32 x, y, z; }` (identical,
 * safe merge), while anim_scrcmd_021FB034.c declared the same shape under the
 * name `UnkVec3` with u32 members.
 *
 * s32 is correct, and we can do better than assert it: 021FB6F4 passes one of
 * these to sub_0206DF3C, which is NNS_G3dWorldPosToScrPos(const VecFx32 *,
 * int *, int *). So this type IS the SDK's VecFx32 -- fx32 is s32 -- and
 * aliasing it makes the layout verified by construction instead of by
 * agreement between two workers.
 *
 * ACTION FOR THE WORKER ON anim_scrcmd_021FB034.c: `UnkVec3` -> `AnimVec3`.
 * ------------------------------------------------------------------------- */
typedef VecFx32 AnimVec3;

/* ---------------------------------------------------------------------------
 * AnimPoint16 -- 4 bytes. Single-file (anim_scrcmd_021FB6F4.c), folded in.
 * ------------------------------------------------------------------------- */
typedef struct AnimPoint16 {
    u16 x; // +0x00
    u16 y; // +0x02
} AnimPoint16;

/* ---------------------------------------------------------------------------
 * AnimParamsA18 -- 0x3C. Single-file (anim_scrcmd_021FACAC.c), folded in.
 * The parameter block handed to sub_021FFA18; only the fields the command
 * fills in are named, the rest pads out to the 0x3C the caller reserves.
 * ------------------------------------------------------------------------- */
typedef struct AnimParamsA18 {
    u32 unk00;              // +0x00
    void *unk04;            // +0x04
    u32 unk08;              // +0x08
    u32 unk0C;              // +0x0C
    u32 unk10;              // +0x10
    u32 unk14;              // +0x14
    s32 unk18;              // +0x18
    s32 unk1C;              // +0x1C
    s32 unk20;              // +0x20
    u32 unk24;              // +0x24
    u8 pad_28[0x3C - 0x28]; // +0x28 INFERRED (filler to the reserved 0x3C)
} AnimParamsA18;

#endif // POKEBLACK_OV094_H
