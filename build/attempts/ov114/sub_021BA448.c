/*
 * ov114 sub_021BA448 -- ATTEMPT ONLY (148/156 bytes), does not match.
 * Belongs in src/ov114/unk_021BA150.c (ARM, no --thumb).
 *
 * RETRIED 2nd wave, up from 125/156.  TWO of the three original differences
 * are now fixed:
 *   1. `seen = 1;` must be written BEFORE the `if (prev > val) return -1;`
 *      check, not after it.  The ROM schedules `mov r3, ip` between the `cmp`
 *      and the predicated return, which is only reachable from that order.
 *   2. Declaring `i` first (i, val, seen, prev, c) puts val in r4, i in lr and
 *      c in r5, all matching.
 *
 * The one remaining difference is 8 bytes: `seen` and the hoisted constant 1
 * are in swapped registers.
 *     ROM   seen -> r3, const 1 -> ip   (and r3 doubles as the mla temp)
 *     mwcc  seen -> ip, const 1 -> r3   (and ip doubles as the mla temp)
 * Everything else -- the guard, the rotated loop, the `cmpne`, the mla/sub
 * pair, the predicated returns -- is byte-identical.
 *
 * Tried and rejected: all 120 permutations of the five declarations crossed
 * with seen typed int / BOOL / u8 / s32 (the sweep was cut short at ~half but
 * nothing above 148 appeared); `seen++` instead of `seen = 1`.
 * All 24 mwccarm builds were swept on the sibling sub_021BA150 with no
 * variation inside the dsi family, so a build sweep here is not promising.
 */
#include "types.h"

int sub_021BA448(const char *s, int n)
{
    int i;
    int val;
    int seen;
    int prev;
    s8 c;

    if (n > 10) {
        return -1;
    }
    val = 0;
    seen = 0;
    for (i = 0; i < n; i++) {
        c = s[i];
        if (seen != 0 && (c == ' ' || c == 0)) {
            break;
        }
        if (seen == 0 && c == ' ') {
            continue;
        }
        if (c < '0' || c > '9') {
            return -1;
        }
        prev = val;
        val = val * 10 + c - '0';
        seen = 1;
        if (prev > val) {
            return -1;
        }
    }
    return val;
}
