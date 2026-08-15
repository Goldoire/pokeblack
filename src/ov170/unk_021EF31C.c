#include "types.h"

/* Local placeholder for the object reached through +0x2c / +0x74.  Replace with
 * the shared type once the integrator lands one. */
typedef struct Ov170Panel {
    u8 unk00[0x74];
    void *unk74;
} Ov170Panel;

typedef struct Ov170Ctx {
    u8 unk00[0x2c];
    Ov170Panel *unk2c;
} Ov170Ctx;

void sub_0202CA3C(void *a0, u32 a1, s32 a2, s32 a3, u32 a4);
void sub_0202CAC4(void *a0, u32 a1, u32 a2);
void sub_0202CAE4(void *a0, u32 a1, u32 a2, u32 a3, u32 a4);
void sub_0202CB4C(void *a0, u32 a1, s32 a2, s32 a3);
void sub_0202CC70(void *a0, u32 a1);
void sub_0202CD64(void *a0, u32 a1, s32 a2, s32 a3, u8 a4);
u32 sub_0202CDD4(void *a0, u32 a1);
void sub_0202CF98(void *a0, u32 a1, s8 *a2, s8 *a3);
u32 sub_0204162C(u32 a0);
void sub_021EC8E4(Ov170Ctx *a0);
void sub_021ED8A4(Ov170Ctx *a0);

void sub_021EF31C(void *a0, u32 a1, u32 a2)
{
    sub_0202CAE4(a0, a1, 0x74, a2, 1);
}

void sub_021EF32C(void *a0)
{
    sub_0202CB4C(a0, 8, 2, 6);
}

void sub_021EF33C(void *a0)
{
    sub_0202CB4C(a0, 8, 0x15, 6);
}

void sub_021EF34C(void *a0)
{
    sub_0202CB4C(a0, 8, 2, 0x18);
}

void sub_021EF35C(void *a0)
{
    sub_0202CB4C(a0, 8, 0x15, 0x18);
}

void sub_021EF36C(void *a0)
{
    s8 v[2];

    sub_0202CF98(a0, 8, &v[1], &v[0]);
    if (v[0] != 6) {
        sub_0202CD64(a0, 8, 0, -1, (u8)(v[0] - 6));
    }
}

void sub_021EF3A0(void *a0)
{
    s8 v[2];

    sub_0202CF98(a0, 8, &v[1], &v[0]);
    if (v[0] != 0x18) {
        sub_0202CD64(a0, 8, 0, 1, (u8)(0x18 - v[0]));
    }
}

void sub_021EF3D8(void *a0)
{
    sub_0202CD64(a0, 8, 1, 0, 0x13);
}

void sub_021EF3EC(void *a0)
{
    sub_0202CD64(a0, 8, -1, 0, 0x13);
}

u32 sub_021EF400(Ov170Ctx *a0)
{
    s8 v[4];
    u32 moved;
    u32 ret;

    sub_0202CF98(a0->unk2c->unk74, 8, &v[3], &v[2]);
    moved = sub_0202CDD4(a0->unk2c->unk74, 8);
    sub_0202CF98(a0->unk2c->unk74, 8, &v[1], &v[0]);
    if (v[3] != v[1] || v[2] != v[0]) {
        sub_021EC8E4(a0);
    }
    ret = 0;
    if (moved != 0) {
        ret = 1;
    }
    return ret;
}

u32 sub_021EF45C(void *a0)
{
    s8 v[2];

    sub_0202CF98(a0, 8, &v[1], &v[0]);
    if (v[1] == 0x15 && v[0] == 6) {
        return 1;
    }
    return 0;
}

u32 sub_021EF480(void *a0)
{
    s8 v[2];

    sub_0202CF98(a0, 8, &v[1], &v[0]);
    if (v[1] == 2 && v[0] == 6) {
        return 1;
    }
    return 0;
}

u32 sub_021EF4A4(void *a0)
{
    s8 v[2];

    sub_0202CF98(a0, 8, &v[1], &v[0]);
    if (v[0] == 6) {
        return 1;
    }
    return 0;
}

void sub_021EF4C0(void *a0)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        sub_0202CB4C(a0, i, 0x20, (s8)(i * 3 + 2));
    }
}

void sub_021EF4E4(void *a0)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        sub_0202CB4C(a0, i, 0x15, (s8)(i * 3 + 2));
    }
}

void sub_021EF508(void *a0)
{
    u32 i;

    for (i = 0; i < 6; i++) {
        sub_0202CC70(a0, i);
        sub_0202CB4C(a0, i, 0x20, (s8)(i * 3 + 2));
    }
}

void sub_021EF534(void *a0)
{
    s8 v[2];
    u16 i;

    sub_0202CF98(a0, 0, &v[1], &v[0]);
    if (v[1] == 0x15) {
        return;
    }
    for (i = 0; i < 6; i++) {
        sub_0202CD64(a0, i, -1, 0, (u8)(v[1] - 0x15));
    }
}

void sub_021EF57C(void *a0)
{
    s8 v[2];
    u16 i;

    sub_0202CF98(a0, 0, &v[1], &v[0]);
    if (v[1] == 0x20) {
        return;
    }
    for (i = 0; i < 6; i++) {
        sub_0202CD64(a0, i, 1, 0, (u8)(0x20 - v[1]));
    }
}

u32 sub_021EF5C4(void *a0)
{
    u32 i;
    u32 ret = 0;

    for (i = 0; i < 6; i++) {
        if (sub_0202CDD4(a0, i) == 1) {
            ret = 1;
        }
    }
    return ret;
}

u32 sub_021EF5E8(void *a0)
{
    s8 v[2];
    u32 ret = 0;

    sub_0202CF98(a0, 0, &v[1], &v[0]);
    if (v[1] != 0x20) {
        ret = 1;
    }
    return ret;
}

u32 sub_021EF60C(void *a0)
{
    s8 v[2];
    u32 ret = 0;

    sub_0202CF98(a0, 0, &v[1], &v[0]);
    if (v[1] == 0x15) {
        ret = 1;
    }
    return ret;
}

void sub_021EF630(Ov170Ctx *a0)
{
    u32 v;

    v = sub_0204162C(0);
    sub_0202CA3C(a0->unk2c->unk74, 6, 0, 0x20, 3);
    sub_0202CAC4(a0->unk2c->unk74, 6, v + 0x540);
}

void sub_021EF660(void *a0)
{
    sub_0202CB4C(a0, 6, 0, 0x15);
}

void sub_021EF670(Ov170Panel *a0)
{
    sub_0202CB4C(a0->unk74, 0xA, 0, 0x15);
}

void sub_021EF680(Ov170Panel *a0)
{
    sub_0202CC70(a0->unk74, 0xA);
}

void sub_021EF68C(Ov170Panel *a0)
{
    sub_0202CB4C(a0->unk74, 0xB, 0, 0x15);
}

void sub_021EF69C(Ov170Panel *a0)
{
    sub_0202CC70(a0->unk74, 0xB);
}

void sub_021EF6A8(void *a0)
{
    sub_0202CB4C(a0, 7, 0x15, 0x18);
    sub_0202CD64(a0, 7, 0, -1, 0x13);
}

void sub_021EF6CC(void *a0)
{
    sub_0202CD64(a0, 7, 0, 1, 0x13);
}

u32 sub_021EF6E0(Ov170Ctx *a0)
{
    s8 v[4];
    u32 moved;

    sub_0202CF98(a0->unk2c->unk74, 7, &v[3], &v[2]);
    moved = sub_0202CDD4(a0->unk2c->unk74, 7);
    sub_0202CF98(a0->unk2c->unk74, 7, &v[1], &v[0]);
    if (v[3] != v[1] || v[2] != v[0]) {
        sub_021ED8A4(a0);
    }
    return moved;
}

void sub_021EF738(void *a0)
{
    sub_0202CB4C(a0, 9, 0x20, 0);
    sub_0202CD64(a0, 9, -1, 0, 0xB);
}

void sub_021EF75C(void *a0)
{
    sub_0202CD64(a0, 9, 1, 0, 0xB);
}
