/*
 * ov114 sub_021BA150 -- ATTEMPT ONLY (136/164 bytes), does not match.
 * Belongs in src/ov114/unk_021BA150.c (ARM, no --thumb).
 *
 * RETRIED 2nd wave.  All 24 mwccarm builds swept (1.2/* need -ipa dropped):
 * every dsi build gives the identical 136/164, 2.0/* gives 47/168, 1.2/*
 * gives 34/160.  This is NOT a compiler-build question.  -O4,s / -O3,p / -O2
 * and the -opt sub-switches are all far worse.
 *
 * The only difference is which register pair holds which pair of locals:
 *     ROM   ca -> sb, cb -> r8,  u -> r6, v -> r7
 *     mwcc  ca -> r7, cb -> r6,  u -> r8, v -> sb
 * The relative order inside each pair is right in both; the two PAIRS are
 * swapped, i.e. the ROM ranks the boolean temps above the characters and mwcc
 * ranks the characters above the temps.  Every instruction, immediate,
 * predicate and branch offset is otherwise identical, including the four
 * hoisted copies of the constant 1 in r5/lr/ip/r3.
 *
 * Tried and rejected (all give exactly 136/164): all 24 permutations of the
 * four declarations; temps declared inside the loop body; four temps instead
 * of two (mwcc coalesces); a `static inline` fold helper, by value and by
 * pointer; BOOL and `register` temps; v-before-u assignment order; `for`
 * instead of `while`; `*a` + separate `a++`; an extra use of u at the final
 * `ca != cb` test.
 * Rejected because they change the instruction stream, not just registers:
 * inlining the range tests as `(cb >= 'A') & (cb <= 'Z')` without temps
 * (108 bytes, mwcc predicates differently), `&&` instead of `&` (108 bytes,
 * short-circuits), and computing the NUL test through u/v (172-176 bytes).
 *
 * Needed: whatever makes mwcc rank the two boolean temps ahead of the two
 * character locals in the callee-saved assignment order.
 */
#include "types.h"

int sub_021BA150(const char *a, const char *b, int n)
{
    int u;
    int v;
    int cb;
    int ca;

    while (n > 0) {
        ca = *a++;
        cb = *b++;
        if (ca == 0 || cb == 0) {
            if (ca == 0 && cb == 0) {
                n = 0;
                break;
            }
        }
        u = (cb >= 'A');
        v = (cb <= 'Z');
        if (u & v) {
            cb += 0x20;
        }
        u = (ca >= 'A');
        v = (ca <= 'Z');
        if (u & v) {
            ca += 0x20;
        }
        if (ca != cb) {
            break;
        }
        n--;
    }
    return n;
}
