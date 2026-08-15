#include "types.h"

typedef struct UnkStructOv021Env
{
    u32 unk00;
    void *unk04;
} UnkStructOv021Env;

void sub_021B0A88(void *a);
void sub_021B0AB0(void *a);
void sub_021B10A4(void *a);
void sub_021B120C(void *a);
void sub_021B1268(void *a);
void sub_021B13F8(void *a);

BOOL sub_021B0EDC(UnkStructOv021Env *ctx)
{
    sub_021B0A88(ctx);
    return 1;
}

BOOL sub_021B0EE8(UnkStructOv021Env *ctx)
{
    sub_021B0AB0(ctx->unk04);
    return 1;
}

BOOL sub_021B10F4(UnkStructOv021Env *ctx)
{
    sub_021B10A4(ctx->unk04);
    return 1;
}

BOOL sub_021B1234(UnkStructOv021Env *ctx)
{
    sub_021B120C(ctx->unk04);
    return 1;
}

BOOL sub_021B13EC(UnkStructOv021Env *ctx)
{
    sub_021B1268(ctx->unk04);
    return 1;
}

BOOL sub_021B14E8(UnkStructOv021Env *ctx)
{
    sub_021B13F8(ctx->unk04);
    return 1;
}
