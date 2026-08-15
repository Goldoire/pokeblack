#include "types.h"

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
