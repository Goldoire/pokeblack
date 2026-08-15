#include "types.h"

struct UnkStruct0215EA6C
{
    u8 unk_00[8];
    void *unk_08;
    u16 unk_0C;
};

typedef int (*UnkFunc0215EA6C)(void *, void *, struct UnkStruct0215EA6C *);

void *sub_020122C0(void *param0, u32 param1, UnkFunc0215EA6C param2, u32 param3);
void *sub_020124E8(void *param0);
void sub_0215F0E8(void *param0, void *param1, struct UnkStruct0215EA6C *param2);
void *sub_020120F4(void *param0);
void sub_0201296C(void *param0);
int sub_021587B0(void *param0, u32 param1, u32 param2, u32 param3);
int sub_02159058(int param0, u32 param1, u32 param2, u32 param3, u32 param4);

int sub_0215EA94(void *param0, void *param1, struct UnkStruct0215EA6C *param2);
int sub_0215EB18(void *param0, void *param1, struct UnkStruct0215EA6C *param2);
int sub_0215EB88(void *param0, void *param1, struct UnkStruct0215EA6C *param2);
int sub_0215EBF8(void *param0, void *param1, struct UnkStruct0215EA6C *param2);
int sub_0215ECBC(void *param0, void *param1, struct UnkStruct0215EA6C *param2);
int sub_0215EEF8(void *param0, void *param1, struct UnkStruct0215EA6C *param2);
int sub_0215EF60(void *param0, void *param1, struct UnkStruct0215EA6C *param2);
int sub_0215EFF4(void *param0, void *param1, struct UnkStruct0215EA6C *param2);

void *sub_0215EA6C(void *param0, struct UnkStruct0215EA6C *param1)
{
    void *task = sub_020122C0(param1->unk_08, 0, sub_0215EA94, 0x14);

    sub_0215F0E8(sub_020124E8(task), param0, param1);

    return task;
}

void *sub_0215EAF0(void *param0, struct UnkStruct0215EA6C *param1)
{
    void *task = sub_020122C0(param1->unk_08, 0, sub_0215EB18, 0x14);

    sub_0215F0E8(sub_020124E8(task), param0, param1);

    return task;
}

void *sub_0215EB60(void *param0, struct UnkStruct0215EA6C *param1)
{
    void *task = sub_020122C0(param1->unk_08, 0, sub_0215EB88, 0x14);

    sub_0215F0E8(sub_020124E8(task), param0, param1);

    return task;
}

void *sub_0215EBD0(void *param0, struct UnkStruct0215EA6C *param1)
{
    void *task = sub_020122C0(param1->unk_08, 0, sub_0215EBF8, 0x14);

    sub_0215F0E8(sub_020124E8(task), param0, param1);

    return task;
}

void *sub_0215EC94(void *param0, struct UnkStruct0215EA6C *param1)
{
    void *task = sub_020122C0(param1->unk_08, 0, sub_0215ECBC, 0x14);

    sub_0215F0E8(sub_020124E8(task), param0, param1);

    return task;
}

void *sub_0215EED0(void *param0, struct UnkStruct0215EA6C *param1)
{
    void *task = sub_020122C0(param1->unk_08, 0, sub_0215EEF8, 0x14);

    sub_0215F0E8(sub_020124E8(task), param0, param1);

    return task;
}

void *sub_0215EFCC(void *param0, struct UnkStruct0215EA6C *param1)
{
    void *task = sub_020122C0(param1->unk_08, 0, sub_0215EF60, 0x14);

    sub_0215F0E8(sub_020124E8(task), param0, param1);

    return task;
}

void *sub_0215F060(void *param0, struct UnkStruct0215EA6C *param1)
{
    void *task = sub_020122C0(param1->unk_08, 0, sub_0215EFF4, 0x14);

    sub_0215F0E8(sub_020124E8(task), param0, param1);

    return task;
}


int sub_0215EA94(void *param0, void *param1, struct UnkStruct0215EA6C *param2)
{
    u16 v;
    int handle;

    sub_0201296C(sub_020120F4(param2->unk_08));

    v = param2->unk_0C;
    handle = sub_021587B0(param0, 0x2715, 0, 0);

    sub_02159058(handle, v, 0, 0, 0);

    return 0;
}

int sub_0215EB18(void *param0, void *param1, struct UnkStruct0215EA6C *param2)
{
    u16 v;
    int handle;

    sub_0201296C(sub_020120F4(param2->unk_08));

    v = param2->unk_0C;
    handle = sub_021587B0(param0, 0x2713, 0, 0);

    sub_02159058(handle, v, 0, 0, 0);

    return 0;
}

int sub_0215EB88(void *param0, void *param1, struct UnkStruct0215EA6C *param2)
{
    u16 v;
    int handle;

    sub_0201296C(sub_020120F4(param2->unk_08));

    v = param2->unk_0C;
    handle = sub_021587B0(param0, 0x2717, 0, 0);

    sub_02159058(handle, v, 0, 0, 0);

    return 0;
}

int sub_0215EBF8(void *param0, void *param1, struct UnkStruct0215EA6C *param2)
{
    u16 v;
    int handle;

    sub_0201296C(sub_020120F4(param2->unk_08));

    v = param2->unk_0C;
    handle = sub_021587B0(param0, 0x2711, 0, 0);

    sub_02159058(handle, v, 0, 0, 0);

    return 0;
}

int sub_0215EEF8(void *param0, void *param1, struct UnkStruct0215EA6C *param2)
{
    u16 v;
    int handle;

    sub_0201296C(sub_020120F4(param2->unk_08));

    v = param2->unk_0C;
    handle = sub_021587B0(param0, 0x271c, 0, 0);

    sub_02159058(handle, v, 0, 0, 0);

    return 0;
}
