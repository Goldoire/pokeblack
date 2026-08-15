#include "types.h"

void *sub_0216D6BC(void *ctx, u32 size);
void *sub_0216D6D4(void *ctx);
void sub_0216D568(void *ctx, u32 a);
void sub_0216D60C(void *ctx, u16 a);
void sub_0216D674(void *ctx, u16 a);
void sub_0216D7CC(void *ctx);
void sub_02163E7C(void *ctx, u16 a);
void sub_02163F10(void *ctx);
void sub_02163FC0(void *ctx, u16 a, u32 b);
void sub_02164010(void *ctx);

extern u32 _021D4A44[];
extern u32 _021D4A68[];
extern u32 _021D4A80[];
extern u32 _021D4A9C[];

typedef struct UnkStruct02198C08
{
    s16 unk00;
    u16 unk02;
    s16 unk04;
    s16 unk06;
} UnkStruct02198C08;

void sub_02198C08(void *ctx, u32 a, s16 b, u16 c)
{
    UnkStruct02198C08 *env = (UnkStruct02198C08 *)sub_0216D6BC(ctx, 8);
    env->unk00 = a;
    env->unk02 = c;
    env->unk04 = b;
    sub_02163E7C(ctx, (u16)a);
    sub_0216D60C(ctx, (u16)a);
    sub_0216D674(ctx, c);
    sub_0216D568(ctx, 0x20);
    sub_0216D7CC(ctx);
}

BOOL sub_02198C4C(void *ctx, u32 *table)
{
    UnkStruct02198C08 *env = (UnkStruct02198C08 *)sub_0216D6D4(ctx);
    sub_02163FC0(ctx, env->unk00, table[env->unk06]);
    sub_02164010(ctx);
    env->unk06++;
    if (env->unk06 < env->unk04) {
        return FALSE;
    }
    sub_0216D568(ctx, 0x440);
    sub_02163F10(ctx);
    sub_0216D674(ctx, 0);
    sub_0216D7CC(ctx);
    return TRUE;
}

BOOL sub_02198CA4(void *ctx)
{
    sub_02198C08(ctx, 0, 6, 6);
    return TRUE;
}

BOOL sub_02198CB4(void *ctx)
{
    sub_02198C08(ctx, 1, 6, 6);
    return TRUE;
}

BOOL sub_02198CC4(void *ctx)
{
    sub_02198C08(ctx, 2, 6, 6);
    return TRUE;
}

BOOL sub_02198CD4(void *ctx)
{
    sub_02198C08(ctx, 3, 6, 6);
    return TRUE;
}

BOOL sub_02198CE4(void *ctx)
{
    sub_02198C08(ctx, 0, 6, 11);
    return TRUE;
}

BOOL sub_02198CF4(void *ctx)
{
    sub_02198C08(ctx, 1, 6, 11);
    return TRUE;
}

BOOL sub_02198D04(void *ctx)
{
    sub_02198C08(ctx, 2, 6, 11);
    return TRUE;
}

BOOL sub_02198D14(void *ctx)
{
    sub_02198C08(ctx, 3, 6, 11);
    return TRUE;
}

BOOL sub_02198D24(void *ctx)
{
    if (sub_02198C4C(ctx, _021D4A68) == 1) {
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02198D3C(void *ctx)
{
    sub_02198C08(ctx, 0, 3, 7);
    return TRUE;
}

BOOL sub_02198D4C(void *ctx)
{
    sub_02198C08(ctx, 1, 3, 7);
    return TRUE;
}

BOOL sub_02198D5C(void *ctx)
{
    sub_02198C08(ctx, 2, 3, 7);
    return TRUE;
}

BOOL sub_02198D6C(void *ctx)
{
    sub_02198C08(ctx, 3, 3, 7);
    return TRUE;
}

BOOL sub_02198D7C(void *ctx)
{
    if (sub_02198C4C(ctx, _021D4A44) == 1) {
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02198D94(void *ctx)
{
    sub_02198C08(ctx, 0, 7, 8);
    return TRUE;
}

BOOL sub_02198DA4(void *ctx)
{
    sub_02198C08(ctx, 1, 7, 8);
    return TRUE;
}

BOOL sub_02198DB4(void *ctx)
{
    sub_02198C08(ctx, 2, 7, 8);
    return TRUE;
}

BOOL sub_02198DC4(void *ctx)
{
    sub_02198C08(ctx, 3, 7, 8);
    return TRUE;
}

BOOL sub_02198DD4(void *ctx)
{
    if (sub_02198C4C(ctx, _021D4A80) == 1) {
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02198DEC(void *ctx)
{
    sub_02198C08(ctx, 0, 12, 9);
    return TRUE;
}

BOOL sub_02198DFC(void *ctx)
{
    sub_02198C08(ctx, 1, 12, 9);
    return TRUE;
}

BOOL sub_02198E0C(void *ctx)
{
    sub_02198C08(ctx, 2, 12, 9);
    return TRUE;
}

BOOL sub_02198E1C(void *ctx)
{
    sub_02198C08(ctx, 3, 12, 9);
    return TRUE;
}

BOOL sub_02198E2C(void *ctx)
{
    if (sub_02198C4C(ctx, _021D4A9C) == 1) {
        return TRUE;
    }
    return FALSE;
}

BOOL sub_02198E44(void *ctx)
{
    sub_0216D6BC(ctx, 4);
    sub_0216D674(ctx, 10);
    sub_0216D7CC(ctx);
    return FALSE;
}

BOOL sub_02198E60(void *ctx)
{
    sub_0216D6BC(ctx, 4);
    sub_0216D674(ctx, 11);
    sub_0216D7CC(ctx);
    return FALSE;
}

BOOL sub_02198E7C(void *ctx)
{
    sub_0216D6BC(ctx, 4);
    sub_0216D674(ctx, 12);
    sub_0216D7CC(ctx);
    return FALSE;
}

BOOL sub_02198E98(void *ctx)
{
    sub_020061E4(0x7B7);
    return sub_02198E44(ctx);
}

BOOL sub_02198EB0(void *ctx)
{
    sub_020061E4(0x7B7);
    return sub_02198E60(ctx);
}
