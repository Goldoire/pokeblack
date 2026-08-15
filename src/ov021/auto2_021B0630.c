#include "types.h"

typedef struct UnkStructOv021Env
{
    u32 unk00;
    void *unk04;
} UnkStructOv021Env;

void sub_021B0480(void *a);

BOOL sub_021B0630(UnkStructOv021Env *ctx)
{
    sub_021B0480(ctx->unk04);
    return 1;
}
