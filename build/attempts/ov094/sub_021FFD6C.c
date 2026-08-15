/* ov094 sub_021FFD6C -- WALL.  44 of the ROM's 48 bytes, and the 44 are
 * byte-identical; the compile is simply 4 bytes SHORT.
 * Belongs in src/ov094/btlv_mcss_021FFCB0.c (same TU as sub_021FFCB0 and
 * sub_021FFD9C, which both match).
 *
 * RETRIED 2nd wave.  All 24 mwccarm builds swept (--thumb, 1.2/* with -ipa
 * dropped) plus -O1/-O2/-O3/-O4/-O4,s, -opt speed/nocse/noloopinvariants/
 * nostrengthreduction/nodeadcode/noloopunroll, -lang c89, -gccext off,
 * -sym off, -enum min, -char unsigned.  Every single combination produces the
 * same 44-byte body.  This is NOT a compiler-build or flag question in the
 * tools we have.
 *
 * THE WHOLE DIFFERENCE is the loop entry test.  The ROM emits it
 * *unspecialised*, against the counter register:
 *      movs r4,#0 / adds r5,r0,#0 / cmp r4,#8 / bge .end
 * Every mwccarm build propagates i == 0 into that test, proves 0 < 8, and
 * deletes the guard outright -- which also lets it schedule the parameter
 * copy `adds r5,r0,#0` ahead of `movs r4,#0`.  Both differences have the one
 * cause.
 *
 * 3rd wave (worker compiler-hunt): the "missing compiler build" reading of
 * this is WRONG and is now closed.  See build/attempts/loop_guard_notes.md.
 * Short version: ov094 func_02206E28 contains one guarded and one unguarded
 * constant-count loop in the SAME function, and a census of every reference
 * binary finds 1698 folded guards against 12 unfolded ones -- the ROM's
 * compiler folds `0 < N` exactly as every mwccarm build does.  This TU is
 * settled at -O4,p (btlv_mcss_021FFCB0.c is 10/10 at -O4,p and breaks at -O1
 * and -O2), and -opt sub-keywords and every opt_* pragma are provably no-ops
 * at any level.  The remaining unknown is a SOURCE spelling that makes the
 * counter's initial value opaque to propagation while still materialising as
 * `movs r4,#0`.  Reduce on main 0x02010DF4 (28 vs 32 bytes, no parameters),
 * not on this function.
 *
 * Tried: for / while / `int i = 0` initializer / hand-written
 * `if (i < 8) do {...} while (i < 8)` / `continue` form / `&&`-fused body /
 * u32 counter / a local copy of the parameter / a goto loop (that one is
 * 48 bytes but puts the only test at the top with an unconditional `b` at the
 * bottom, 7/48).
 */
#include "types.h"

typedef struct AnimMgr AnimMgr;

BOOL sub_021FFD9C(AnimMgr *sys, int sprId);
BOOL sub_021FFCB0(AnimMgr *sys, int sprId);

BOOL sub_021FFD6C(AnimMgr *sys)
{
    int i;

    for (i = 0; i < 8; i++)
    {
        if (sub_021FFD9C(sys, i))
        {
            if (sub_021FFCB0(sys, i))
            {
                return TRUE;
            }
        }
    }

    return FALSE;
}
