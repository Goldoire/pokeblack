#include "types.h"

struct UnkStruct02167E88
{
    u8 unk_000[0x724];
    u8 unk_724;
    u8 unk_725[3];
    u16 unk_728;
};

u32 sub_02039338(u32 param0);

void sub_02167E88(u32 param0, u32 param1, u16 *param2, struct UnkStruct02167E88 *param3)
{
    if (param0 != sub_02039338(++param3->unk_724))
    {
        param3->unk_728 = *param2;
    }
}

void sub_02167EAC(u32 param0, u32 param1, u16 *param2, struct UnkStruct02167E88 *param3)
{
    if (param0 != sub_02039338(++param3->unk_724))
    {
        param3->unk_728 = *param2;
    }
}

void sub_02167ED0(u32 param0, u32 param1, u16 *param2, struct UnkStruct02167E88 *param3)
{
    if (param0 != sub_02039338(++param3->unk_724))
    {
        param3->unk_728 = *param2;
    }
}
