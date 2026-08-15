#include "types.h"

void *sub_0216D6BC(void *ctx, u32 size);
void *sub_0216D6D4(void *ctx);
void sub_0216D568(void *ctx, u32 a);
void sub_0216D570(void *ctx, u32 a);
void sub_0216D674(void *ctx, u16 a);
void sub_0216D7CC(void *ctx);

typedef struct Vec3
{
    s32 x;
    s32 y;
    s32 z;
} Vec3;

void sub_0216D8C0(void *ctx, Vec3 *v);
void *sub_0219BF48(void *ctx);
void sub_0219BF3C(void *ctx, u32 a);
void sub_0219BF54(void *ctx);
void sub_021D04A4(void *a);
u32 sub_021D04C4(void *a);
void sub_021AC154(void *a);

extern s32 *_021DDBD4;

typedef struct UnkStruct02198FB0
{
    u32 unk00;
} UnkStruct02198FB0;

BOOL sub_02198F68(void *ctx)
{
    Vec3 sp0;
    void *p;
    u32 *q;

    sub_0216D6BC(ctx, 4);
    p = sub_0219BF48(ctx);
    if (p != NULL) {
        sub_021D04A4(p);
    }
    q = (u32 *)&sp0;
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    sub_0216D8C0(ctx, &sp0);
    sub_0216D568(ctx, 0xA0);
    sub_0216D570(ctx, 0x8000);
    sub_0216D7CC(ctx);
    return FALSE;
}

BOOL sub_02198FB0(void *ctx)
{
    Vec3 sp0;
    void *p;
    u32 *q;
    UnkStruct02198FB0 *env = (UnkStruct02198FB0 *)sub_0216D6D4(ctx);

    q = (u32 *)&sp0;
    q[0] = 0;
    q[1] = 0;
    q[2] = 0;
    sp0.y = _021DDBD4[env->unk00];
    sub_0216D8C0(ctx, &sp0);
    p = sub_0219BF48(ctx);
    if (p != NULL && sub_021D04C4(p) == 1) {
        sub_021AC154(p);
        sub_0219BF3C(ctx, 0);
    }
    env->unk00 += 2;
    if (env->unk00 < 0x10) {
        return FALSE;
    }
    sp0.y = 0;
    sub_0216D8C0(ctx, &sp0);
    sub_0216D568(ctx, 0x540);
    sub_0219BF54(ctx);
    sub_0216D7CC(ctx);
    return TRUE;
}

/* unk00 must be volatile: the ROM re-loads it after the increment instead of
 * forwarding the stored register (see sub_02199050). */
typedef struct UnkStruct02199034
{
    volatile u16 unk00;
    u16 unk02;
} UnkStruct02199034;

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
