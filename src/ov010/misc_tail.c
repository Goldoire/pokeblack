#include "types.h"

struct UnkStruct021671CC
{
    u8 unk_00[0x14];
    void *unk_14;
    u8 unk_18[4];
    void *unk_1C;
};

void *sub_0215A5E4(void *script);
void *sub_020127A4(void *param0);
void sub_02012AC8(void *param0);
void *sub_02012EBC(void *param0);
void *sub_02008B14(void *param0);
void sub_02008BD0(void *param0);
void sub_02190728(void *param0);
void sub_0201ED04(void *param0);
void sub_02158A90(void *param0, void *param1, u32 param2, u32 param3);

void sub_02159B38(void *script)
{
    sub_02012AC8(sub_020127A4(sub_0215A5E4(script)));
}

void sub_02169138(void *param0)
{
    sub_02008BD0(sub_02008B14(sub_02012EBC(param0)));
}

void sub_021671CC(struct UnkStruct021671CC *p)
{
    sub_02190728(p->unk_14);
    p->unk_14 = NULL;
}

void sub_021671EC(struct UnkStruct021671CC *p)
{
    sub_0201ED04(p->unk_1C);
    p->unk_1C = NULL;
}

void sub_02158AC8(void *param0, void *param1)
{
    sub_02158A90(param0, param1, 4, 1);
}

void sub_02158AD4(void *param0, void *param1)
{
    sub_02158A90(param0, param1, 3, 1);
}
