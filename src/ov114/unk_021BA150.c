#include "types.h"

/*
 * ov114 string helpers (0x021BA1F4..0x021BA2D0): URL-escape sizing.
 *
 * The neighbours sub_021BA150 / sub_021BA2D0 / sub_021BA448 are byte-for-byte
 * correct except for callee-saved register assignment; they are parked in
 * build/attempts/ov114/.
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
