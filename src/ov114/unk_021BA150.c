#include "types.h"

/*
 * ov114 string helpers (0x021BA1F4..0x021BA35C): URL-escape sizing and escape.
 *
 * The neighbours sub_021BA150 and sub_021BA448 are byte-for-byte correct
 * except for callee-saved register assignment; they are parked in
 * build/attempts/ov114/.  All 24 mwccarm builds were swept for both.
 */

int sub_021BA1F4(const char *s)
{
    int len = 0;
    s8 c = *s++;

    while (c != 0) {
        if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') || c == ' ') {
            len += 1;
        } else {
            len += 3;
        }
        c = *s++;
    }
    return len;
}

int sub_021BA25C(const char *s, int n)
{
    int i = 0;
    int len = 0;
    s8 c = *s++;

    if (n > 0) {
        while (i < n) {
            if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
                (c >= 'a' && c <= 'z') || c == ' ') {
                len += 1;
            } else {
                len += 3;
            }
            i++;
            c = *s++;
        }
    }
    return len;
}

/* Both nibbles have to be extracted *before* the '%' is stored.  Writing
 * `lo = c & 0xF;` after `dst[0] = '%';` lets mwcc hoist the high nibble's
 * "then" add above its own cmp (`add r2,r3,#0x30 / cmp / addge`) instead of
 * predicating both arms the way the ROM does -- 132/140. */
int sub_021BA2D0(char *dst, int c)
{
    int hi;
    int lo;

    if (c == ' ') {
        dst[0] = '+';
        return 1;
    }
    if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') ||
        (c >= 'a' && c <= 'z')) {
        dst[0] = (char)c;
        return 1;
    }
    hi = (c >> 4) & 0xF;
    lo = c & 0xF;
    dst[0] = '%';
    hi = (hi < 10) ? hi + '0' : hi + 0x37;
    lo = (lo < 10) ? lo + '0' : lo + 0x37;
    dst[1] = (char)hi;
    dst[2] = (char)lo;
    return 3;
}
