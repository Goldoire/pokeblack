#include "types.h"

extern const u8 _021F1AC4[];
extern const u8 _021F1AEC[];
extern const u8 _021F1DE4[];
extern const u8 _021F1B14[];
extern const u8 _021F1B3C[];
extern const u8 _021F1B64[];
extern const u8 _021F1B8C[];

void sub_021DD158(void *a0, void *a1, int a2, int a3);
void sub_021DD19C(void *a0, void *a1, int a2, int a3);

void sub_021DD05C(void *a0, void *a1, int a2)
{
    sub_021DD158(a0, a1, a2, 1);
}

void sub_021DD068(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 1);
}

const u8 *sub_021DD074(int *count)
{
    *count = 5;
    return _021F1AC4;
}

void sub_021DD080(void *a0, void *a1, int a2)
{
    sub_021DD158(a0, a1, a2, 2);
}

void sub_021DD08C(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 2);
}

const u8 *sub_021DD098(int *count)
{
    *count = 5;
    return _021F1AEC;
}

void sub_021DD0A4(void *a0, void *a1, int a2)
{
    sub_021DD158(a0, a1, a2, 4);
}

void sub_021DD0B0(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 4);
}

const u8 *sub_021DD0BC(int *count)
{
    *count = 5;
    return _021F1DE4;
}

void sub_021DD0C8(void *a0, void *a1, int a2)
{
    sub_021DD158(a0, a1, a2, 3);
}

void sub_021DD0D4(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 3);
}

const u8 *sub_021DD0E0(int *count)
{
    *count = 5;
    return _021F1B14;
}

void sub_021DD0EC(void *a0, void *a1, int a2)
{
    sub_021DD158(a0, a1, a2, 6);
}

void sub_021DD0F8(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 6);
}

const u8 *sub_021DD104(int *count)
{
    *count = 5;
    return _021F1B3C;
}

void sub_021DD110(void *a0, void *a1, int a2)
{
    sub_021DD158(a0, a1, a2, 5);
}

void sub_021DD11C(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 5);
}

const u8 *sub_021DD128(int *count)
{
    *count = 5;
    return _021F1B64;
}

void sub_021DD134(void *a0, void *a1, int a2)
{
    sub_021DD158(a0, a1, a2, 0x25);
}

void sub_021DD140(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 0x25);
}

const u8 *sub_021DD14C(int *count)
{
    *count = 5;
    return _021F1B8C;
}
