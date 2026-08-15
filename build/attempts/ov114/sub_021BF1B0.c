/*
 * ov114 sub_021BF1B0 -- 196/216 bytes, ATTEMPT ONLY, does not match.
 * Belongs in src/ov114/unk_021BF184.c (which already declares it extern).
 *
 * RETRIED 2nd wave.  Every one of the 24 mwccarm builds was swept (the five
 * 1.2/* builds need -ipa dropped; they compile but score 21%).  Every dsi and
 * 2.0 build produces the identical 192/216, so this is NOT a compiler-build
 * question -- unlike ov170/unk_021E19D4.c, which the sweep did fix.
 *
 * PROGRESS: declaring `Ov114Mgr *mgr;` BEFORE `Ov114Ctx *ctx;` moves mgr into
 * r4 and takes it from 192 to 196.  The one remaining difference is that the
 * parameter and ctx are swapped:
 *     ROM   c -> r5, ctx -> r6, mgr -> r4
 *     mwcc  c -> r6, ctx -> r5, mgr -> r4
 * i.e. mwcc gives the parameter the highest callee-saved register and the ROM
 * gives it the middle one.  The r0-vs-r1 choice at 0x021BF220 follows from
 * that and is not independent.
 *
 * Tried and rejected (all still put the parameter in r6): declaration-order
 * permutations of {mgr, ctx}, copying the parameter into a local declared
 * first / second / third, an extra unused local between them, assigning the
 * discarded sub_021BEF50 result, a comma/assignment expression for ctx,
 * C99 mid-block declarations, and an inner scope for ctx.
 *
 * Types are now the promoted ones from include/ov114.h: the 0x804C object is
 * Ov114Buffer (unk_021B9D8C.c's `Node` and unk_021BEC74.c's `Pool` are the
 * same type).  Retyping did not change codegen.
 */
#include "types.h"

typedef struct Ov114Ctx Ov114Ctx;
typedef struct Ov114Mgr Ov114Mgr;

typedef struct Ov114Buffer {
    s32 unk_00;
    s32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    void *unk_10;
    void *unk_14;
    s32 unk_18;
    u8 pad_1C[0x8048 - 0x1C];
    s32 counter;
} Ov114Buffer;

extern Ov114Ctx *sub_021BEF08(void);
extern void *sub_021BEF50(Ov114Ctx *ctx);
extern Ov114Mgr *sub_021BEF58(Ov114Ctx *ctx);
extern int sub_021BEBA8(Ov114Mgr *m, void *key);
extern s32 sub_021BF018(Ov114Mgr *m, Ov114Buffer *c);
extern void sub_021BA850(Ov114Buffer *c);
extern void sub_021BB8B4(Ov114Ctx *ctx);
extern void sub_021BBA14(Ov114Ctx *ctx, s32 fd);
extern void sub_021BBB28(Ov114Mgr *m, void *p);
extern int sub_021BF288(Ov114Buffer *c);

int sub_021BF1B0(Ov114Buffer *c)
{
    Ov114Mgr *mgr;
    Ov114Ctx *ctx;

    ctx = sub_021BEF08();
    mgr = sub_021BEF58(ctx);
    sub_021BEF50(ctx);
    if (c == NULL) {
        return -1;
    }
    if (c->counter > 0 && c->unk_18 >= 0) {
        sub_021BBA14(ctx, c->unk_18);
        c->unk_18 = -1;
    }
    if (sub_021BF018(mgr, c) > 0) {
        return 0;
    }
    if (c->unk_10 != NULL && *(s32 *)((u8 *)c->unk_10 + 4) == 0) {
        sub_021BB8B4(ctx);
    }
    if (c->unk_14 != NULL) {
        if (c->unk_10 != NULL) {
            sub_021BF288(c);
        }
        sub_021BBB28(mgr, c->unk_14);
    }
    sub_021BEBA8(mgr, c);
    sub_021BA850(c);
    return 0;
}
