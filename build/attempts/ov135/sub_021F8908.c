/* sub_021F8908 (ov135, 0x021F8908, 72 bytes) -- WALL.  Best 40/72.
 *
 * RETRIED 2nd wave.  All 24 mwccarm builds swept (--thumb; the five 1.2/*
 * builds need -ipa dropped): every single one gives the identical 26/72 for
 * the `for` spelling, so this is NOT a compiler-build question.
 *
 * SETTLED: with the do/while form below the register allocation is exact --
 * a0 -> r5, n -> r7, i -> r4 -- as are the prologue, both calls, the stack
 * argument slot, the literal pool and the epilogue.
 *
 * TWO differences remain, both inside the loop:
 *  1. Loop lowering.  The ROM enters the loop with an unconditional `b` to a
 *     bottom test (`b .cond` ... `.cond: cmp r4,r7 / blt .body`), i.e. no
 *     inversion at all.  Every `for`/`while`/`goto` spelling makes mwcc
 *     substitute i == 0 into the entry test and emit the specialised guard
 *     `cmp r4,#0 / ble .end` (26/72); every hand-rolled `do { if (i >= n)
 *     break; ... } while (1)` puts the real test at the TOP and an
 *     unconditional `b` at the bottom (40/72).  Neither is the ROM's shape.
 *  2. Argument scheduling in the body.  The ROM stores the 5th argument
 *     (0x48 -> [sp]) first, then loads base, then *a0; mwcc loads base and
 *     the table literal first and stores the stack argument in the middle.
 *
 * Tried: for / while / goto-to-bottom-test / while(1)+break / for(;;)+break /
 * `!(i < n)` / `n > i` / pre-increment; `i = 0` hoisted above both calls
 * (15/72, mwcc then sinks it); all six permutations of the three
 * declarations (no effect at all on any spelling).
 *
 * 3rd wave (worker compiler-hunt).  Not a compiler build: see
 * build/attempts/loop_guard_notes.md.  Two facts about THIS function:
 *  - This TU is settled at -O4,p: src/ov135/unk_021F7F14.c, which brackets
 *    0x021F8908 with sub_021F87E0 and sub_021F89B4, is 17/17 OK at -O4,p and
 *    breaks two functions at -O2.  So the level is not the answer.
 *  - A byte census of every reference binary finds this loop is the ONLY
 *    un-rotated loop entry (`movs rN,#0 ; b <bottom test>`) in the whole ROM,
 *    against 971 rotated+specialised guards.  It is a one-of-one anomaly.
 * For reference, `-O2` (wrong level, but informative) gives 54/72 with the
 * ROM's exact loop shape and exact register allocation -- a0->r5, n->r7,
 * i->r4 -- leaving only the argument scheduling inside the body.  Whatever
 * source construct is missing has to reproduce that at -O4,p.
 */
#include "types.h"

extern const u16 _022030E8[];

s32 sub_021F88D8(u32 a0, u32 *a1);
void *sub_0201F81C(s32 a0, u32 a1);
void sub_0201F878(void *a0, void *a1, u32 a2, u32 a3, u32 a4);

s32 sub_021F8908(void **a0, void *a1, u32 a2)
{
    u32 base;
    s32 n;
    s32 i;

    n = sub_021F88D8(a2, &base);
    *a0 = sub_0201F81C(n, 0x48);
    i = 0;
    do
    {
        if (i >= n)
        {
            break;
        }
        sub_0201F878(*a0, a1, _022030E8[base + i], base + i + 1, 0x48);
        i++;
    } while (1);
    return n;
}
