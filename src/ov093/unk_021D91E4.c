#include "types.h"

// ov093 0x021d91e4..0x021d95ac: per-effect wrapper
// shells and count/table getters.

void sub_021D76BC(int a0, int a1);
u32 sub_021D775C(int a0);
void sub_021D928C(void *a0, void *a1, int a2, int a3);
void sub_021D92CC(void *a0, void *a1, int a2, int a3);
u32 sub_021D9648(void *a0, void *a1, int a2);

void sub_021D91E4(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(3)) {
        sub_021D76BC(81, 1);
    }
}

void sub_021D9214(void *a0, void *a1, void *a2, int a3)
{
    sub_021D928C(a1, a2, a3, 1);
}

void sub_021D9224(void *a0, void *a1, void *a2, int a3)
{
    sub_021D92CC(a1, a2, a3, 201);
}

void sub_021D9240(void *a0, void *a1, void *a2, int a3)
{
    sub_021D928C(a1, a2, a3, 6);
}

void sub_021D9250(void *a0, void *a1, void *a2, int a3)
{
    sub_021D92CC(a1, a2, a3, 207);
}

void sub_021D926C(void *a0, void *a1, void *a2, int a3)
{
    sub_021D928C(a1, a2, a3, 8);
}

void sub_021D927C(void *a0, void *a1, void *a2, int a3)
{
    sub_021D92CC(a1, a2, a3, 198);
}

void sub_021D93D8(void *a0, void *a1, void *a2, u32 *a3)
{
    *a3 = sub_021D9648(a1, a2, 1);
}

void sub_021D9460(void *a0, void *a1, int a2)
{
    if (a2 == sub_021D775C(2)) {
        sub_021D76BC(65, 1);
    }
}

void sub_021D9484(void *a0, void *a1, void *a2, u32 *a3)
{
    *a3 = sub_021D9648(a1, a2, 3);
}

void sub_021D94C4(void *a0, void *a1, void *a2, u32 *a3)
{
    *a3 = sub_021D9648(a1, a2, 5);
}

void sub_021D9504(void *a0, void *a1, void *a2, u32 *a3)
{
    *a3 = sub_021D9648(a1, a2, 4);
}

void sub_021D9544(void *a0, void *a1, void *a2, u32 *a3)
{
    *a3 = sub_021D9648(a1, a2, 6);
}

void sub_021D9598(void *a0, void *a1, void *a2, u32 *a3)
{
    *a3 = sub_021D9648(a1, a2, 7);
}

