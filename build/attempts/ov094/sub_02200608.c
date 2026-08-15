/* ov094 sub_02200608 -- WALL.  68 of the ROM's 72 bytes, and every one of the
 * 68 is byte-identical; the compile is 4 bytes SHORT.
 *
 * RETRIED 2nd wave.  The BODY IS NOW SOLVED -- the previous attempt left it as
 * a comment.  The store is a bitfield write:
 *     sys->sprites[idx].unk4C_10 = sub_021FF348(sys, i);
 * where sprites[] starts at AnimMgr+0x08 with stride 0x5C and the bitfield
 * word is at sprite+0x4C, bit 10.  That reproduces the ROM's
 *     lsls r0,#0x1f / movs r1,#0x5c / muls / ldr / ldr =0xfffffbff /
 *     lsrs r0,#0x15 / ands / orrs / str
 * exactly, including the hoisted `r6 = sys + 0x54` base.  A shift-and-mask
 * spelling does not; the bitfield is required (see WORKER_GUIDE matching lore).
 *
 * The only remaining difference is the same one as the sibling
 * build/attempts/ov094/sub_021FFD6C.c: the ROM keeps an unspecialised loop
 * entry test
 *     movs r4,#0 / adds r5,r0,#0 / cmp r4,#8 / bge .end
 * and every one of the 24 mwccarm builds folds `0 < 8` and deletes it.  See
 * that file's header for the full list of builds, flags and loop spellings
 * that were swept.
 *
 * 3rd wave: this is NOT a missing compiler build -- see
 * build/attempts/loop_guard_notes.md for the disproof and for the reduced
 * test case (main 0x02010DF4) that anyone attacking this should use instead.
 * Note the ROM hoists `r6 = sys + 0x54` into the loop PREHEADER, between the
 * guard and the body; that is LICM, so this is level>=3 output that kept a
 * guard, not low-optimisation output.
 */
#include "types.h"

typedef struct AnimSprite {
    u8 pad_00[0x4C];
    u32 unk4C_00 : 10;
    u32 unk4C_10 : 1;   /* the bit this function writes */
    u32 unk4C_11 : 21;
    u8 pad_50[0x5C - 0x50];
} AnimSprite;

typedef struct AnimMgr {
    u32 unk000;
    void *unk004;
    AnimSprite sprites[14];
} AnimMgr;

BOOL sub_021FFD9C(AnimMgr *sys, int sprId);
u32 sub_021FF348(AnimMgr *sys, int sprId);
int sub_022019F4(AnimMgr *sys, int sprId);

void sub_02200608(AnimMgr *sys)
{
    int i;
    int idx;

    for (i = 0; i < 8; i++)
    {
        if (sub_021FFD9C(sys, i))
        {
            idx = sub_022019F4(sys, i);
            sys->sprites[idx].unk4C_10 = sub_021FF348(sys, i);
        }
    }
}
