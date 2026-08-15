/*
 * sub_02197EDC (0x02197EDC, 66 bytes).
 *
 * STATUS: byte-exact, but verify_functions.py reports 65/66.
 *
 * The one differing byte is the high byte of the second halfword of
 *   bl  #0x0216D57C
 * The ROM has the Thumb->Thumb form (lo 0xF800|...); the verifier emits the
 * Thumb->ARM BLX form (lo 0xE800|...).
 *
 * Cause is an overlay ALIAS in build/reference/triage.json, not the C.
 * ov009 and ov010 both load at 0x02155160. triage has:
 *     ov009  func_0216D57C  mode=arm  kind=arm  size=2268  (a misidentified blob)
 * and no ov010 entry at that address. ov021 is neither module, so
 * target_mode() falls through to the global map and picks ov009's "arm".
 * The real callee is ov010's Thumb routine -- its neighbours sub_0216D570 /
 * sub_0216D55C are already matched as ov010/unk_0216D410, all Thumb.
 *
 * Proof: forcing target_mode to return "thumb" for 0x0216D57C gives 66/66
 * with 0 masked bytes.
 *
 * ACTION FOR THE INTEGRATOR: the ov009 entry at 0x0216D57C is a bad triage
 * row (a 2268-byte "arm" blob covering real ov010 Thumb code). Either drop it,
 * or teach target_mode to prefer a mode agreed on by the modules that are
 * actually resident. Then move this function back into
 * src/ov021/unk_02197C4C.c.
 */
#include "types.h"

u32 sub_0216D7C4(void *ctx);
u32 sub_0216D57C(void *ctx, u32 a);
void sub_0216D570(void *ctx, u32 a);
void sub_0216D7C0(void *ctx, u32 a);
void sub_0216D7C8(void *ctx, u32 a);
void sub_02197EB4(void *ctx);

BOOL sub_02197EDC(void *ctx)
{
    if (sub_0216D7C4(ctx) != 0xFF) {
        sub_02197EB4(ctx);
        if (sub_0216D57C(ctx, 0x400) == 0) {
            return FALSE;
        }
    }
    sub_0216D570(ctx, 0x400);
    sub_0216D7C0(ctx, 0xFF);
    sub_0216D7C8(ctx, 0);
    return TRUE;
}
