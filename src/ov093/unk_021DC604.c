#include "types.h"

// ov093 0x021dc604..0x021dc624: per-effect wrapper
// shells and count/table getters.

void sub_021D928C(void *a0, void *a1, int a2, int a3);
void sub_021D92CC(void *a0, void *a1, int a2, int a3);

void sub_021DC604(void *a0, void *a1, void *a2, int a3)
{
    sub_021D928C(a1, a2, a3, 2);
}

void sub_021DC614(void *a0, void *a1, void *a2, int a3)
{
    sub_021D92CC(a1, a2, a3, 204);
}

