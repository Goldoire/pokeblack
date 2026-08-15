#include "types.h"

typedef struct AnimSprite
{
    /* 0x00 */ void *unk00;
    /* 0x04 */ u8 pad_04[0x28 - 0x04];
    /* 0x28 */ void *unk28;
    /* 0x2C */ u32 unk2C;
    /* 0x30 */ u32 unk30;
    /* 0x34 */ u32 unk34;
    /* 0x38 */ u16 unk38;
    /* 0x3A */ u16 unk3A;
    /* 0x3C */ u32 unk3C;
    /* 0x40 */ u32 unk40;
    /* 0x44 */ u32 unk44;
    /* 0x48 */ int unk48;
    /* 0x4C */ u32 unk4C_0 : 1;
               u32 unk4C_1 : 1;
               u32 unk4C_2 : 1;
               u32 unk4C_3 : 5;
               u32 unk4C_8 : 1;
               u32 unk4C_9 : 1;
               u32 unk4C_10 : 22;
    /* 0x50 */ u8 pad_50[0x5C - 0x50];
} AnimSprite;

typedef struct AnimMgr
{
    /* 0x000 */ u32 unk000;
    /* 0x004 */ void *unk004;
    /* 0x008 */ AnimSprite sprites[14];
    /* 0x510 */ u32 unk510_0 : 1;
                u32 unk510_1 : 1;
                u32 unk510_2 : 1;
                u32 unk510_3 : 29;
    /* 0x514 */ u32 unk514;
    /* 0x518 */ u32 unk518;
    /* 0x51C */ u32 unk51C;
    /* 0x520 */ u32 unk520;
    /* 0x524 */ u32 unk524;
    /* 0x528 */ u32 unk528;
    /* 0x52C */ u32 unk52C;
    /* 0x530 */ u32 unk530;
    /* 0x534 */ u32 unk534;
    /* 0x538 */ u32 unk538;
    /* 0x53C */ u32 unk53C;
} AnimMgr;

u32 sub_02015F24(void *obj);
void sub_02015F50(void *obj, u32 a1, u32 a2, s8 a3, u32 a4);
u32 sub_0201600C(void *obj);
void sub_020160D4(void *renderer, void *obj, u32 a2, u32 a3);
void sub_0201624C(void *renderer, void *obj);
u32 sub_02017E1C(void *res, int field, int idx);
int sub_02017EAC(void *res);
u32 sub_02019C90(u16 a0, u16 a1, int a2);
u32 sub_0202D034(u32 a0, u32 a1);

u32 sub_021F935C(int sprId);
int sub_022019F4(AnimMgr *sys, int sprId);

BOOL sub_021FFD9C(AnimMgr *sys, int sprId);

BOOL sub_021FFCB0(AnimMgr *sys, int sprId)
{
    u32 busy;

    busy = 0;
    if (sub_021FFD9C(sys, sprId))
    {
        busy = sub_0201600C(sys->sprites[sub_022019F4(sys, sprId)].unk00);
    }

    if ((sub_021F935C(sprId) & sys->unk514) || (sub_021F935C(sprId) & sys->unk518) ||
        (sub_021F935C(sprId) & sys->unk524) || (sub_021F935C(sprId) & sys->unk520) ||
        (sub_021F935C(sprId) & sys->unk51C) || (sub_021F935C(sprId) & sys->unk528) ||
        (sub_021F935C(sprId) & sys->unk52C) || (sub_021F935C(sprId) & sys->unk530) ||
        sys->unk510_2 || busy != 0)
    {
        return TRUE;
    }

    return FALSE;
}

BOOL sub_021FFD6C(AnimMgr *sys)
{
    int i;

    i = 0;
    while (i < 8)
    {
        if (sub_021FFD9C(sys, i))
        {
            if (sub_021FFCB0(sys, i))
            {
                return TRUE;
            }
        }
        i++;
    }

    return FALSE;
}

BOOL sub_021FFD9C(AnimMgr *sys, int sprId)
{
    if (sub_022019F4(sys, sprId) != -1)
    {
        return TRUE;
    }
    return FALSE;
}

void sub_021FFDB4(AnimMgr *sys, int sprId, u32 a2, u32 a3, s8 a4, u32 a5)
{
    int idx;

    idx = sub_022019F4(sys, sprId);
    if (idx == -1)
    {
        return;
    }
    if (sys->sprites[idx].unk00 == NULL)
    {
        return;
    }

    sub_02015F50(sys->sprites[idx].unk00, a2, a3, a4, a5);
    sys->sprites[idx].unk4C_8 = 1;
}

void sub_021FFDF8(AnimMgr *sys, int sprId, u32 a2, u32 a3)
{
    int idx;

    idx = sub_022019F4(sys, sprId);
    if (idx == -1)
    {
        return;
    }
    if (sys->sprites[idx].unk00 == NULL)
    {
        return;
    }
    sub_020160D4(sys->unk004, sys->sprites[idx].unk00, a2, a3);
}

void sub_021FFE24(AnimMgr *sys, int sprId)
{
    int idx;

    idx = sub_022019F4(sys, sprId);
    if (idx == -1)
    {
        return;
    }
    if (sys->sprites[idx].unk00 == NULL)
    {
        return;
    }
    sub_0201624C(sys->unk004, sys->sprites[idx].unk00);
}

void sub_021FFE48(AnimMgr *sys, int sprId, void *res)
{
    int idx;

    idx = sub_022019F4(sys, sprId);
    if (idx == -1)
    {
        return;
    }
    if (sys->sprites[idx].unk00 == NULL)
    {
        return;
    }

    sys->sprites[idx].unk2C = sub_02017E1C(res, 5, 0);
    sys->sprites[idx].unk30 = sub_02017E1C(res, 0x6F, 0);
    sys->sprites[idx].unk38 =
        (u16)sub_02019C90((u16)sys->sprites[idx].unk2C, (u16)sys->sprites[idx].unk30, 0x26);
    sys->sprites[idx].unk34 = sub_02017E1C(res, 0, 0);
    sys->sprites[idx].unk3C = sub_02017E1C(res, 0x98, 0);

    if (sub_02017EAC(res) == 1)
    {
        sys->sprites[idx].unk40 |= 2;
    }

    sys->sprites[idx].unk3A =
        (u16)sub_0202D034(sub_02017E1C(res, 0xA0, 0), sub_02017E1C(res, 0xA1, 0));
    sys->sprites[idx].unk4C_9 = 1;
}

u16 sub_021FFF0C(AnimMgr *sys, int sprId)
{
    int idx;

    idx = sub_022019F4(sys, sprId);
    if (idx == -1)
    {
        return 0;
    }
    if (sys->sprites[idx].unk00 == NULL)
    {
        return 0;
    }
    return sys->sprites[idx].unk38;
}

u32 sub_021FFF38(AnimMgr *sys, int sprId)
{
    int idx;

    if (sprId == 0xFF)
    {
        return 0;
    }

    idx = sub_022019F4(sys, sprId);
    if (idx == -1)
    {
        return 0;
    }
    if (sys->sprites[idx].unk00 == NULL)
    {
        return 0;
    }
    return sys->sprites[idx].unk40;
}

BOOL sub_021FFF68(AnimMgr *sys, int sprId)
{
    int idx;

    idx = sub_022019F4(sys, sprId);
    if (idx == -1)
    {
        return FALSE;
    }
    if (sys->sprites[idx].unk00 == NULL)
    {
        return FALSE;
    }
    if (sub_02019C90((u16)sys->sprites[idx].unk2C, (u16)sys->sprites[idx].unk30, 0x10))
    {
        return TRUE;
    }
    return FALSE;
}

u32 sub_021FFFAC(AnimMgr *sys, int sprId)
{
    int idx;

    idx = sub_022019F4(sys, sprId);
    if (idx == -1)
    {
        return 0;
    }
    if (sys->sprites[idx].unk00 == NULL)
    {
        return 0;
    }
    return sub_02015F24(sys->sprites[idx].unk00);
}
