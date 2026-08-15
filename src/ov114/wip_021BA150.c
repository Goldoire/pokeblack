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
            u = (ca == 0);
            v = (cb == 0);
            if (u & v) {
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
