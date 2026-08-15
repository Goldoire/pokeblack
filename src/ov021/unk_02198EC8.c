/*
 * sub_02198EC8 (0x02198EC8, 88 bytes) and sub_02198F20 (0x02198F20, 72 bytes).
 *
 * STATUS: byte-exact, but verify_functions.py reports 87/88 and 71/72.
 *
 * The single differing byte in each is the high byte of the second halfword of
 *   blx  #0x020508EC
 * i.e. the Thumb->ARM interworking form (lo halfword 0xE800|...) versus the
 * Thumb->Thumb form (0xF800|...) the verifier emits.
 *
 * Cause is a data gap, not the C: build/reference/triage.json has no entry at
 * exactly 0x020508EC, so verify_functions.target_mode() returns None and falls
 * back to the documented Thumb default. 0x020508EC lies *inside* main's
 * FUN_0204E824 (0x0204E824, 8780 bytes, mode "arm") -- a large misidentified
 * ARM blob -- so the real callee is ARM and the linker emits BLX.
 *
 * Proof: monkey-patching target_mode to return "arm" for 0x020508EC makes both
 * functions verify 88/88 and 72/72 with 0 masked bytes:
 *
 *   import verify_functions as V
 *   orig = V.target_mode
 *   V.target_mode = lambda a, module=None, own_range=None: (
 *       "arm" if a == 0x020508EC else orig(a, module, own_range))
 *
 * ACTION FOR THE INTEGRATOR: add a mode entry for 0x020508EC (arm) -- or make
 * target_mode fall back to the enclosing triage entry's mode when an address
 * has no exact match -- then move this file back into src/ov021/.
 */
#include "types.h"

void *sub_0216D6D4(void *ctx);
u32 sub_0216D7A8(void *ctx, u32 a);
void sub_0216D674(void *ctx, u16 a);
void sub_0216D7CC(void *ctx);
void *sub_0216D67C(void *ctx);
void *sub_0216D520(void *a);
void *sub_0219C9DC(void *a);
u32 sub_020508EC(void *a, u16 b, u32 *out);

BOOL sub_02198EC8(void *ctx)
{
    u32 sp0;
    u32 v;

    sub_0216D6D4(ctx);
    v = sub_0216D7A8(ctx, 0);
    if (v != 0xFFFF) {
        if (sub_020508EC(sub_0219C9DC(sub_0216D520(sub_0216D67C(ctx))), (u16)v, &sp0) == 1) {
            sub_0216D674(ctx, 0);
            sub_0216D7CC(ctx);
            return TRUE;
        }
    }
    return FALSE;
}

BOOL sub_02198F20(void *ctx)
{
    u32 sp0;
    u32 v;

    sub_0216D6D4(ctx);
    v = sub_0216D7A8(ctx, 0);
    if (v != 0xFFFF) {
        if (sub_020508EC(sub_0219C9DC(sub_0216D520(sub_0216D67C(ctx))), (u16)v, &sp0) == 1) {
            sub_0216D7CC(ctx);
            return TRUE;
        }
    }
    return FALSE;
}
