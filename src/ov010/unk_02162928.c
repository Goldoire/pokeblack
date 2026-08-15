#include "types.h"

struct UnkStruct02162928
{
    u16 unk_00;
};

struct UnkStruct02162928 *sub_021627C8(void *param0);
struct UnkStruct02162928 *sub_02162890(void *param0);
struct UnkStruct02162928 *sub_021628E4(void *param0);

u16 sub_02162928(void *param0)
{
    struct UnkStruct02162928 *p = sub_021627C8(param0);

    if (p != NULL)
    {
        return p->unk_00;
    }

    return 0xFFFF;
}

u16 sub_02162940(void *param0)
{
    struct UnkStruct02162928 *p = sub_02162890(param0);

    if (p != NULL)
    {
        return p->unk_00;
    }

    return 0xFFFF;
}

u16 sub_02162958(void *param0)
{
    struct UnkStruct02162928 *p = sub_021628E4(param0);

    if (p != NULL)
    {
        return p->unk_00;
    }

    return 0xFFFF;
}
