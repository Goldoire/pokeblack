#include "types.h"

int sub_021BA448(const char *s, int n)
{
    s32 seen;
    int i;
    s8 c;
    int val;
    int prev;

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
