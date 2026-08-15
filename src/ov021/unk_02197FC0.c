#include "types.h"

void *sub_0216D6BC(void *ctx, u32 size);
void *sub_0216D6D4(void *ctx);
void sub_0216D568(void *ctx, u32 a);
void sub_0216D5E0(void *ctx, u16 a);
void sub_0216D60C(void *ctx, u16 a);
void sub_0216D674(void *ctx, u16 a);
void sub_0216D7CC(void *ctx);
void sub_02163E7C(void *ctx, u16 a);
void sub_02163F10(void *ctx);
void sub_020061E4(u32 a);

typedef struct UnkStruct02197FC0
{
    u16 unk00;
    s16 unk02;
    u32 unk04;
    u32 unk08;
} UnkStruct02197FC0;

typedef struct UnkStruct021984C0
{
    u32 unk00;
    u32 unk04;
    u16 unk08;
    u16 unk0A;
    u8 unk0C;
    s8 unk0D;
    u8 unk0E;
    s8 unk0F;
} UnkStruct021984C0;

void sub_02163FC0(void *ctx, u16 a, u32 b);
void sub_02164010(void *ctx);

BOOL sub_02197F5C(void *ctx)
{
    sub_0216D568(ctx, 0x400);
    return FALSE;
}

void sub_02197F6C(void *ctx, u32 a)
{
    sub_0216D5E0(ctx, (u16)a);
    sub_0216D674(ctx, 0);
    sub_02163F10(ctx);
    sub_0216D7CC(ctx);
}

BOOL sub_02197F90(void *ctx)
{
    sub_02197F6C(ctx, 0);
    return TRUE;
}

BOOL sub_02197F9C(void *ctx)
{
    sub_02197F6C(ctx, 1);
    return TRUE;
}

BOOL sub_02197FA8(void *ctx)
{
    sub_02197F6C(ctx, 2);
    return TRUE;
}

BOOL sub_02197FB4(void *ctx)
{
    sub_02197F6C(ctx, 3);
    return TRUE;
}

void sub_02197FC0(void *ctx, u32 a, u32 b, s16 c, u16 d)
{
    UnkStruct02197FC0 *env = (UnkStruct02197FC0 *)sub_0216D6BC(ctx, 12);
    env->unk00 = d;
    env->unk02 = c;
    env->unk04 = a;
    env->unk08 = b;
    sub_02163E7C(ctx, (u16)a);
    sub_0216D60C(ctx, (u16)a);
    sub_0216D674(ctx, d);
    sub_0216D568(ctx, 0x20);
    sub_0216D7CC(ctx);
}

BOOL sub_0219800C(void *ctx)
{
    UnkStruct02197FC0 *env = (UnkStruct02197FC0 *)sub_0216D6D4(ctx);
    sub_02163FC0(ctx, (u16)env->unk04, env->unk08);
    sub_02164010(ctx);
    env->unk02--;
    if (env->unk02 > 0) {
        return FALSE;
    }
    sub_0216D568(ctx, 0x440);
    sub_02163F10(ctx);
    sub_0216D674(ctx, 0);
    sub_0216D7CC(ctx);
    return FALSE;
}

void sub_02198318(void *ctx, u32 a, s16 b, u16 c)
{
    UnkStruct02197FC0 *env = (UnkStruct02197FC0 *)sub_0216D6BC(ctx, 12);
    env->unk00 = c;
    env->unk02 = b;
    sub_0216D5E0(ctx, (u16)a);
    sub_0216D674(ctx, c);
    sub_02163F10(ctx);
    sub_0216D7CC(ctx);
}

BOOL sub_0219834C(void *ctx)
{
    UnkStruct02197FC0 *env = (UnkStruct02197FC0 *)sub_0216D6D4(ctx);
    env->unk02--;
    if (env->unk02 > 0) {
        return FALSE;
    }
    sub_0216D568(ctx, 0x400);
    sub_0216D674(ctx, 0);
    sub_0216D7CC(ctx);
    return FALSE;
}

void sub_021984C0(void *ctx, u32 a, u32 b, s8 c, u16 d, s16 e, u16 f, u32 g)
{
    UnkStruct021984C0 *env = (UnkStruct021984C0 *)sub_0216D6BC(ctx, 16);
    env->unk0C = a;
    env->unk00 = b;
    env->unk0D = c;
    env->unk0E = d;
    env->unk0F = e;
    env->unk08 = f;
    if (b == 0) {
        sub_02163F10(ctx);
    } else {
        sub_02163E7C(ctx, (u16)a);
    }
    sub_0216D568(ctx, 0xA0);
    sub_0216D60C(ctx, (u16)a);
    sub_0216D674(ctx, d);
    sub_0216D7CC(ctx);
    if (g != 0) {
        sub_020061E4(g);
    }
}

BOOL sub_02198060(void *ctx)
{
    sub_02197FC0(ctx, 0, 0x800, 0x20, 1);
    return TRUE;
}

BOOL sub_02198074(void *ctx)
{
    sub_02197FC0(ctx, 1, 0x800, 0x20, 1);
    return TRUE;
}

BOOL sub_02198088(void *ctx)
{
    sub_02197FC0(ctx, 2, 0x800, 0x20, 1);
    return TRUE;
}

BOOL sub_0219809C(void *ctx)
{
    sub_02197FC0(ctx, 3, 0x800, 0x20, 1);
    return TRUE;
}

BOOL sub_021980B0(void *ctx)
{
    sub_02197FC0(ctx, 0, 0x1000, 0x10, 2);
    return TRUE;
}

BOOL sub_021980C4(void *ctx)
{
    sub_02197FC0(ctx, 1, 0x1000, 0x10, 2);
    return TRUE;
}

BOOL sub_021980DC(void *ctx)
{
    sub_02197FC0(ctx, 2, 0x1000, 0x10, 2);
    return TRUE;
}

BOOL sub_021980F0(void *ctx)
{
    sub_02197FC0(ctx, 3, 0x1000, 0x10, 2);
    return TRUE;
}

BOOL sub_02198104(void *ctx)
{
    sub_02197FC0(ctx, 0, 0x2000, 8, 3);
    return TRUE;
}

BOOL sub_0219811C(void *ctx)
{
    sub_02197FC0(ctx, 1, 0x2000, 8, 3);
    return TRUE;
}

BOOL sub_02198134(void *ctx)
{
    sub_02197FC0(ctx, 2, 0x2000, 8, 3);
    return TRUE;
}

BOOL sub_02198148(void *ctx)
{
    sub_02197FC0(ctx, 3, 0x2000, 8, 3);
    return TRUE;
}

BOOL sub_0219815C(void *ctx)
{
    sub_02197FC0(ctx, 0, 0x4000, 4, 4);
    return TRUE;
}

BOOL sub_02198170(void *ctx)
{
    sub_02197FC0(ctx, 1, 0x4000, 4, 4);
    return TRUE;
}

BOOL sub_02198184(void *ctx)
{
    sub_02197FC0(ctx, 2, 0x4000, 4, 4);
    return TRUE;
}

BOOL sub_02198198(void *ctx)
{
    sub_02197FC0(ctx, 3, 0x4000, 4, 4);
    return TRUE;
}

BOOL sub_021981AC(void *ctx)
{
    sub_02197FC0(ctx, 0, 0x8000, 2, 5);
    return TRUE;
}

BOOL sub_021981C4(void *ctx)
{
    sub_02197FC0(ctx, 1, 0x8000, 2, 5);
    return TRUE;
}

BOOL sub_021981DC(void *ctx)
{
    sub_02197FC0(ctx, 2, 0x8000, 2, 5);
    return TRUE;
}

BOOL sub_021981F0(void *ctx)
{
    sub_02197FC0(ctx, 3, 0x8000, 2, 5);
    return TRUE;
}

BOOL sub_02198208(void *ctx)
{
    sub_02197FC0(ctx, 0, 0x10000, 1, 0);
    return TRUE;
}

BOOL sub_0219821C(void *ctx)
{
    sub_02197FC0(ctx, 1, 0x10000, 1, 0);
    return TRUE;
}

BOOL sub_02198234(void *ctx)
{
    sub_02197FC0(ctx, 2, 0x10000, 1, 0);
    return TRUE;
}

BOOL sub_02198248(void *ctx)
{
    sub_02197FC0(ctx, 3, 0x10000, 1, 0);
    return TRUE;
}

BOOL sub_02198260(void *ctx)
{
    sub_02197FC0(ctx, 0, 0x4000, 4, 10);
    return TRUE;
}

BOOL sub_02198278(void *ctx)
{
    sub_02197FC0(ctx, 1, 0x4000, 4, 10);
    return TRUE;
}

BOOL sub_02198290(void *ctx)
{
    sub_02197FC0(ctx, 2, 0x4000, 4, 10);
    return TRUE;
}

BOOL sub_021982A4(void *ctx)
{
    sub_02197FC0(ctx, 3, 0x4000, 4, 10);
    return TRUE;
}

BOOL sub_021982BC(void *ctx)
{
    sub_02197FC0(ctx, 0, 0x1000, 0x10, 5);
    return TRUE;
}

BOOL sub_021982D4(void *ctx)
{
    sub_02197FC0(ctx, 1, 0x1000, 0x10, 5);
    return TRUE;
}

BOOL sub_021982EC(void *ctx)
{
    sub_02197FC0(ctx, 2, 0x1000, 0x10, 5);
    return TRUE;
}

BOOL sub_02198300(void *ctx)
{
    sub_02197FC0(ctx, 3, 0x1000, 0x10, 5);
    return TRUE;
}

BOOL sub_02198380(void *ctx)
{
    sub_02198318(ctx, 0, 0x20, 1);
    return TRUE;
}

BOOL sub_02198390(void *ctx)
{
    sub_02198318(ctx, 1, 0x20, 1);
    return TRUE;
}

BOOL sub_021983A0(void *ctx)
{
    sub_02198318(ctx, 2, 0x20, 1);
    return TRUE;
}

BOOL sub_021983B0(void *ctx)
{
    sub_02198318(ctx, 3, 0x20, 1);
    return TRUE;
}

BOOL sub_021983C0(void *ctx)
{
    sub_02198318(ctx, 0, 0x10, 2);
    return TRUE;
}

BOOL sub_021983D0(void *ctx)
{
    sub_02198318(ctx, 1, 0x10, 2);
    return TRUE;
}

BOOL sub_021983E0(void *ctx)
{
    sub_02198318(ctx, 2, 0x10, 2);
    return TRUE;
}

BOOL sub_021983F0(void *ctx)
{
    sub_02198318(ctx, 3, 0x10, 2);
    return TRUE;
}

BOOL sub_02198400(void *ctx)
{
    sub_02198318(ctx, 0, 8, 3);
    return TRUE;
}

BOOL sub_02198410(void *ctx)
{
    sub_02198318(ctx, 1, 8, 3);
    return TRUE;
}

BOOL sub_02198420(void *ctx)
{
    sub_02198318(ctx, 2, 8, 3);
    return TRUE;
}

BOOL sub_02198430(void *ctx)
{
    sub_02198318(ctx, 3, 8, 3);
    return TRUE;
}

BOOL sub_02198440(void *ctx)
{
    sub_02198318(ctx, 0, 4, 4);
    return TRUE;
}

BOOL sub_02198450(void *ctx)
{
    sub_02198318(ctx, 1, 4, 4);
    return TRUE;
}

BOOL sub_02198460(void *ctx)
{
    sub_02198318(ctx, 2, 4, 4);
    return TRUE;
}

BOOL sub_02198470(void *ctx)
{
    sub_02198318(ctx, 3, 4, 4);
    return TRUE;
}

BOOL sub_02198480(void *ctx)
{
    sub_02198318(ctx, 0, 2, 5);
    return TRUE;
}

BOOL sub_02198490(void *ctx)
{
    sub_02198318(ctx, 1, 2, 5);
    return TRUE;
}

BOOL sub_021984A0(void *ctx)
{
    sub_02198318(ctx, 2, 2, 5);
    return TRUE;
}

BOOL sub_021984B0(void *ctx)
{
    sub_02198318(ctx, 3, 2, 5);
    return TRUE;
}
