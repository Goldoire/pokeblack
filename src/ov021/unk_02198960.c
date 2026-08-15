#include "types.h"

void *sub_0216D6BC(void *ctx, u32 size);
void *sub_0216D6D4(void *ctx);
void sub_0216D674(void *ctx, u16 a);
void sub_0216D7CC(void *ctx);
void sub_0216D548(void *ctx, u32 a);
void sub_0216D550(void *ctx, u32 a);
void *sub_0216D67C(void *ctx);
void *sub_0216D534(void *a);
void *sub_02188CD0(void *a);
void *sub_021BB528(void *a, void *ctx, u32 b, u32 c);
u32 sub_021BB5C8(void *a);
void sub_021AC154(void *a);
void sub_020061E4(u32 a);

typedef struct UnkStruct02198960
{
    s32 unk00;
    s32 unk04;
} UnkStruct02198960;

void sub_02198960(void *ctx, u32 a)
{
    u32 *env = (u32 *)sub_0216D6BC(ctx, 4);
    *env = a;
    sub_0216D7CC(ctx);
}

BOOL sub_02198978(void *ctx)
{
    u32 *env = (u32 *)sub_0216D6D4(ctx);
    if (*env != 0) {
        (*env)--;
        return FALSE;
    }
    sub_0216D7CC(ctx);
    return TRUE;
}

BOOL sub_02198998(void *ctx)
{
    sub_02198960(ctx, 1);
    return TRUE;
}

BOOL sub_021989A4(void *ctx)
{
    sub_02198960(ctx, 2);
    return TRUE;
}

BOOL sub_021989B0(void *ctx)
{
    sub_02198960(ctx, 4);
    return TRUE;
}

BOOL sub_021989BC(void *ctx)
{
    sub_02198960(ctx, 8);
    return TRUE;
}

BOOL sub_021989C8(void *ctx)
{
    sub_02198960(ctx, 15);
    return TRUE;
}

BOOL sub_021989D4(void *ctx)
{
    sub_02198960(ctx, 16);
    return TRUE;
}

BOOL sub_021989E0(void *ctx)
{
    sub_02198960(ctx, 32);
    return TRUE;
}

BOOL sub_021989EC(void *ctx)
{
    UnkStruct02198960 *env = (UnkStruct02198960 *)sub_0216D6BC(ctx, 8);
    env->unk04 = 0x10000;
    sub_0216D674(ctx, 0);
    sub_0216D7CC(ctx);
    return TRUE;
}

BOOL sub_02198A58(void *ctx)
{
    UnkStruct02198960 *env = (UnkStruct02198960 *)sub_0216D6BC(ctx, 8);
    env->unk00 = 0x140000;
    env->unk04 = 0xFFFF0000;
    sub_020061E4(0x676);
    sub_0216D674(ctx, 0);
    sub_0216D7CC(ctx);
    return TRUE;
}

BOOL sub_02198AD4(void *ctx)
{
    sub_0216D548(ctx, 4);
    sub_0216D7CC(ctx);
    return TRUE;
}

BOOL sub_02198AE8(void *ctx)
{
    sub_0216D550(ctx, 4);
    sub_0216D7CC(ctx);
    return TRUE;
}

BOOL sub_02198AFC(void *ctx)
{
    sub_0216D548(ctx, 8);
    sub_0216D7CC(ctx);
    return TRUE;
}

BOOL sub_02198B10(void *ctx)
{
    sub_0216D550(ctx, 8);
    sub_0216D7CC(ctx);
    return TRUE;
}

BOOL sub_02198B24(void *ctx)
{
    sub_0216D548(ctx, 16);
    sub_0216D7CC(ctx);
    return TRUE;
}

BOOL sub_02198B38(void *ctx)
{
    sub_0216D550(ctx, 16);
    sub_0216D7CC(ctx);
    return TRUE;
}

void sub_02198B4C(void *ctx, u32 a, u32 b)
{
    UnkStruct02198960 *env = (UnkStruct02198960 *)sub_0216D6BC(ctx, 8);
    env->unk00 = a;
    env->unk04 = (s32)sub_021BB528(sub_02188CD0(sub_0216D534(sub_0216D67C(ctx))), ctx, a, 1);
    sub_0216D7CC(ctx);
}

BOOL sub_02198B80(void *ctx)
{
    UnkStruct02198960 *env = (UnkStruct02198960 *)sub_0216D6D4(ctx);
    if (sub_021BB5C8((void *)env->unk04) == 1) {
        sub_021AC154((void *)env->unk04);
        sub_0216D7CC(ctx);
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02198BA8(void *ctx)
{
    sub_02198B4C(ctx, 0, 0);
    return FALSE;
}

BOOL sub_02198BB8(void *ctx)
{
    sub_02198B4C(ctx, 0, 0);
    return FALSE;
}

BOOL sub_02198BC8(void *ctx)
{
    sub_02198B4C(ctx, 0, 0);
    return FALSE;
}

BOOL sub_02198BD8(void *ctx)
{
    sub_02198B4C(ctx, 1, 0);
    return FALSE;
}

BOOL sub_02198BE8(void *ctx)
{
    sub_02198B4C(ctx, 2, 0);
    return FALSE;
}

BOOL sub_02198BF8(void *ctx)
{
    sub_02198B4C(ctx, 3, 0);
    return FALSE;
}
