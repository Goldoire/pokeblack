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
        if (i >= n) break;
        sub_0201F878(*a0, a1, _022030E8[base + i], base + i + 1, 0x48);
        i++;
    } while (1);
    return n;
}
