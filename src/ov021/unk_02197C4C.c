#include "types.h"

u32 sub_0216D520(void *ctx);
u32 sub_0216D528(void *ctx);
void sub_0216D95C(void *ctx, u32 a);
void sub_0219C5D0(void *ctx);
void sub_0219D488(void *ctx);
void *sub_0216D67C(void *ctx);
u32 sub_0216D4D4(void *a, u32 b);
u32 sub_0216DAA0(void *ctx);
void sub_0216D758(void *ctx);
u32 sub_0216D3CC(void *a);
void sub_0216D410(void *a, u16 b);
u32 sub_0216D7C4(void *ctx);
u32 sub_0216D7D4(void *ctx);
u32 sub_0216DB10(void *ctx);
u32 sub_0216DC4C(void *ctx);
u32 sub_0216D55C(void *ctx, u32 a);
BOOL sub_02197F20(void *ctx, u32 a, u32 b);

typedef struct UnkStruct02197DCC
{
    u32 unk00;
    u32 unk04;
    u32 unk08;
    void *unk0C;
    u16 *unk10;
} UnkStruct02197DCC;

extern BOOL (*const _021D4A50[])(UnkStruct02197DCC *);
extern BOOL (*const *const _021D5F58[])(void *);
extern BOOL (*const *const _021D624C[])(void *);

void sub_02197C4C(void *ctx)
{
    if (sub_0216D520(ctx) != 0) {
        sub_0219C5D0(ctx);
    }
    if (sub_0216D528(ctx) != 0) {
        sub_0219D488(ctx);
    }
    sub_0216D95C(ctx, 0);
}

void sub_02197C78(void *ctx)
{
    if (sub_0216D4D4(sub_0216D67C(ctx), 4) == 0) {
        if (sub_0216DAA0(ctx) != 0) {
            sub_0216D758(ctx);
        }
    }
}

BOOL sub_02197C9C(void *ctx)
{
    if (sub_0216DB10(ctx) != 0) {
        if (sub_0216DC4C(ctx) == 0) {
            return TRUE;
        }
    }
    if (sub_0216D55C(ctx, 0x10) != 0) {
        return TRUE;
    }
    return FALSE;
}

void sub_02197DCC(void *a, UnkStruct02197DCC *p)
{
    do {
    } while (_021D4A50[p->unk00](p) == 1);
}

BOOL sub_02197DE8(UnkStruct02197DCC *p)
{
    p->unk08 = 0;
    p->unk00 = 1;
    return TRUE;
}

BOOL sub_02197DF4(UnkStruct02197DCC *p)
{
    if (sub_0216D3CC(p->unk0C) == 0) {
        return FALSE;
    }
    p->unk00 = 2;
    return TRUE;
}

BOOL sub_02197E10(UnkStruct02197DCC *p)
{
    sub_0216D410(p->unk0C, *p->unk10);
    p->unk00 = 3;
    return FALSE;
}

void sub_02197EB4(void *ctx)
{
    u32 v;

    while (TRUE) {
        v = sub_0216D7C4(ctx);
        if (v == 0xFF) {
            break;
        }
        if (sub_02197F20(ctx, v, sub_0216D7D4(ctx)) == 0) {
            break;
        }
    }
}

BOOL sub_02197F20(void *ctx, u32 a, u32 b)
{
    if (sub_0216D55C(ctx, 0x2000) != 0) {
        return _021D624C[a][b](ctx);
    }
    return _021D5F58[a][b](ctx);
}
