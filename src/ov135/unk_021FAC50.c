#include "ov135.h"

void sub_022028C8(void *a0, u32 a1, u32 a2, u32 a3, u32 a4, u32 a5, u16 a6,
                  u32 a7);
void sub_02045334(void *a0);
void sub_0202CEBC(void *a0, u32 a1, void *a2);

void sub_021FAC50(void *a0, void *a1, u32 a2, u32 a3, u16 a4, u32 a5)
{
    sub_022028C8(a1, 0, a2, a3, 0, 0, a4, a5);
    sub_02045334(a1);
    sub_0202CEBC(a0, 0, a1);
}

s32 sub_021FAC84(void)
{
    return -1;
}
