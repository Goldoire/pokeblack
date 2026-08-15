#include "types.h"

struct UnkStruct021690E0
{
    u8 unk_00[0xC];
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
};

void *sub_02012EBC(void *param0);
struct UnkStruct021690E0 *sub_02008B14(void *param0);

u32 sub_021690E0(void *param0)
{
    return sub_02008B14(sub_02012EBC(param0))->unk_0C;
}

u32 sub_021690F0(void *param0)
{
    return sub_02008B14(sub_02012EBC(param0))->unk_10;
}

u32 sub_02169100(void *param0)
{
    return sub_02008B14(sub_02012EBC(param0))->unk_14;
}

u32 sub_02169110(void *param0)
{
    return sub_02008B14(sub_02012EBC(param0))->unk_18;
}
