#include "types.h"

void *sub_0216D6BC(void *ctx, u32 size);
void *sub_0216D6D4(void *ctx);
u32 sub_0216D7A8(void *ctx, u32 a);
void sub_0216D674(void *ctx, u16 a);
void sub_0216D7CC(void *ctx);
void *sub_0216D67C(void *ctx);
void *sub_0216D520(void *a);
void *sub_0219C9DC(void *a);
u32 sub_020508EC(void *a, u16 b, u32 *out);

typedef struct UnkStruct02199034
{
    u16 unk00;
    u16 unk02;
} UnkStruct02199034;

BOOL sub_02198EC8(void *ctx)
{
    u32 sp0;
    u32 v;

    sub_0216D6D4(ctx);
    v = sub_0216D7A8(ctx, 0);
    if (v == 0xFFFF) {
        return FALSE;
    }
    if (sub_020508EC(sub_0219C9DC(sub_0216D520(sub_0216D67C(ctx))), (u16)v, &sp0) == 1) {
        sub_0216D674(ctx, 0);
        sub_0216D7CC(ctx);
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02198F20(void *ctx)
{
    u32 sp0;
    u32 v;

    sub_0216D6D4(ctx);
    v = sub_0216D7A8(ctx, 0);
    if (v == 0xFFFF) {
        return FALSE;
    }
    if (sub_020508EC(sub_0219C9DC(sub_0216D520(sub_0216D67C(ctx))), (u16)v, &sp0) == 1) {
        sub_0216D7CC(ctx);
        return TRUE;
    }
    return FALSE;
}

void sub_02199034(void *ctx, u16 a, s16 b)
{
    UnkStruct02199034 *env = (UnkStruct02199034 *)sub_0216D6BC(ctx, 4);
    env->unk02 = b;
    sub_0216D674(ctx, a);
}

BOOL sub_02199050(void *ctx)
{
    UnkStruct02199034 *env = (UnkStruct02199034 *)sub_0216D6D4(ctx);
    env->unk00++;
    if (env->unk00 >= env->unk02) {
        sub_0216D7CC(ctx);
    }
    return FALSE;
}

BOOL sub_02199070(void *ctx)
{
    sub_02199034(ctx, 1, 0x28);
    sub_0216D7CC(ctx);
    return FALSE;
}

BOOL sub_02199088(void *ctx)
{
    sub_02199034(ctx, 2, 0x28);
    sub_0216D7CC(ctx);
    return FALSE;
}

BOOL sub_021990A0(void *ctx)
{
    sub_02199034(ctx, 0, 0xC);
    sub_0216D7CC(ctx);
    return FALSE;
}

BOOL sub_021990B8(void *ctx)
{
    sub_0216D6BC(ctx, 4);
    sub_0216D674(ctx, 1);
    sub_0216D7CC(ctx);
    return TRUE;
}
