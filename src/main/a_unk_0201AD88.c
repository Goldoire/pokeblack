#include "types.h"

/* _0214652C is a lazily created singleton (sub_0201AD88 allocates it once via
 * sub_020490F4 and every function here reloads it from the global). */
extern void *_0214652C;

void *sub_020490F4(int a0, void *a1);
void *sub_0201AFD4(void *a0, void *a1);
void *sub_02049578(void *a0, void *a1);
void *sub_0204960C(void *a0, void *a1);
void sub_020495F4(void *a0, int a1, void *a2);
void sub_02048F4C(void *a0, int a1, void *a2);

void sub_0201AD88(void *a0)
{
    if (_0214652C == NULL)
    {
        _0214652C = sub_020490F4(0x10, a0);
    }
}

void sub_0201ADA4(void *a0, void *a1, void *a2)
{
    sub_0204960C(_0214652C, sub_02049578(_0214652C, sub_0201AFD4(a0, a1)));
    sub_020495F4(_0214652C, 0x3C, a2);
}

void sub_0201ADD0(void *a0, void *a1, void *a2)
{
    sub_02048F4C(a2, 0x12, sub_0201AFD4(a0, a1));
}
