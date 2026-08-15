#include "types.h"

typedef struct BattleAnimSys
{
    /* 0x000 */ u32 unk000;
    /* 0x004 */ u32 unk004;
    /* 0x008 */ void *unk008[32];
    /* 0x088 */ u8 pad_088[0x108 - 0x088];
    /* 0x108 */ u32 unk108[32];
    /* 0x188 */ void *unk188;
    /* 0x18C */ void *unk18C;
    /* 0x190 */ u8 pad_190[0x1E4 - 0x190];
    /* 0x1E4 */ void *unk1E4;
    /* 0x1E8 */ u32 unk1E8;
} BattleAnimSys;

extern BattleAnimSys *_0220AF20;

void sub_02021D50(void *a0);
void sub_0204A648(void);

int sub_021BA1EC(void *a0);
int sub_021BA20C(void *a0);

void sub_021F89BC(void *task);

int sub_021F88F4(void)
{
    int ret;

    ret = 0;
    if (_0220AF20->unk1E4 != NULL)
    {
        ret = sub_021BA1EC(_0220AF20->unk1E4);
    }

    return ret;
}

int sub_021F8914(void)
{
    int ret;

    ret = 0;
    if (_0220AF20->unk1E4 != NULL)
    {
        ret = sub_021BA20C(_0220AF20->unk1E4);
    }

    return ret;
}

void sub_021F8A10(u32 key)
{
    int i;

    for (i = 0; i < 32; i++)
    {
        if (_0220AF20->unk008[i] != NULL)
        {
            if (key == _0220AF20->unk108[i])
            {
                sub_021F89BC(_0220AF20->unk008[i]);
            }
        }
    }
}

int sub_021F8B40(void)
{
    int i;

    for (i = 0; i < 32; i++)
    {
        if (_0220AF20->unk008[i] == NULL)
        {
            break;
        }
    }

    if (i == 32)
    {
        sub_021F89BC(_0220AF20->unk008[0]);
        i = 0;
    }

    return i;
}

void sub_021F8B6C(void)
{
    int i;

    for (i = 0; i < 32; i++)
    {
        if (_0220AF20->unk008[i] != NULL)
        {
            sub_021F89BC(_0220AF20->unk008[i]);
        }
    }
}

void sub_021F8B90(void)
{
    sub_0204A648();
    sub_02021D50(_0220AF20->unk18C);
}
