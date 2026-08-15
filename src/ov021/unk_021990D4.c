#include "types.h"

void *sub_0216D6D4(void *ctx);
void sub_0216D568(void *ctx, u32 a);
void sub_0216D674(void *ctx, u16 a);
void sub_0216D7CC(void *ctx);
void sub_02163F10(void *ctx);

typedef struct Vec3
{
    s32 x;
    s32 y;
    s32 z;
} Vec3;

void sub_0216D8C0(void *ctx, Vec3 *v);
void sub_02163F8C(void *ctx, void *a);

typedef struct UnkStruct021990D4
{
    s32 unk00;
    s32 unk04;
} UnkStruct021990D4;

/* ov021 .rodata: { 0, 0, 0, 0, 0, 0x4000, 0x4000, 0x3000, 0x1000, 0 } */
typedef struct UnkTable021D4C1C
{
    s32 v[10];
} UnkTable021D4C1C;

extern const UnkTable021D4C1C _021D4C1C;

BOOL sub_021990D4(void *ctx)
{
    Vec3 sp28;
    UnkTable021D4C1C sp0;
    UnkStruct021990D4 *env;
    s32 i;
    u32 *q;

    q = (u32 *)&sp28;
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    sp0 = _021D4C1C;
    env = (UnkStruct021990D4 *)sub_0216D6D4(ctx);
    i = env->unk00;
    if (i >= 10) {
        i = 9;
    }
    sp28.y = sp0.v[i];
    sub_0216D8C0(ctx, &sp28);
    env->unk00++;
    if (env->unk00 >= 0x14) {
        sub_0216D7CC(ctx);
    }
    return FALSE;
}

BOOL sub_021991F0(void *ctx)
{
    UnkStruct021990D4 *env = (UnkStruct021990D4 *)sub_0216D6D4(ctx);
    sub_02163F8C(ctx, &env->unk04);
    env->unk00--;
    if (env->unk00 > 0) {
        return FALSE;
    }
    sub_0216D568(ctx, 0x440);
    sub_02163F10(ctx);
    sub_0216D674(ctx, 0);
    sub_0216D7CC(ctx);
    return TRUE;
}
