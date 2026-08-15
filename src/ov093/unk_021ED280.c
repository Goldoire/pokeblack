#include "types.h"

// ov093 0x021ed280..0x021ed590: per-effect wrapper
// shells and count/table getters.

u32 sub_021F7EB4(void *a0);
u32 sub_021F8180(void *a0);

int sub_021ED280(void *a0)
{
    if (sub_021F7EB4(a0) == 0) {
        return 1;
    }
    return 0;
}

int sub_021ED2BC(void *a0)
{
    if (sub_021F7EB4(a0) == 0) {
        return 1;
    }
    return 0;
}

int sub_021ED304(void *a0)
{
    if (sub_021F7EB4(a0) == 0) {
        return 1;
    }
    return 0;
}

int sub_021ED4D0(void *a0)
{
    if (sub_021F8180(a0) == 0) {
        return 1;
    }
    return 0;
}

int sub_021ED57C(void *a0)
{
    if (sub_021F7EB4(a0) == 0) {
        return 1;
    }
    return 0;
}

