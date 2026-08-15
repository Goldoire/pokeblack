#include "types.h"

typedef struct AnimVec3
{
    s32 x;
    s32 y;
    s32 z;
} AnimVec3;

// 14 sprite slots of 0x5C bytes starting at +0x008; the manager header keeps the
// 2D/3D renderer handle at +0x004 and per-slot u8 counter rows from +0x542.
typedef struct AnimSprite
{
    /* 0x00 */ void *unk00;
    /* 0x04 */ u8 pad_04[0x28 - 0x04];
    /* 0x28 */ void *unk28;
    /* 0x2C */ u8 pad_2C[0x48 - 0x2C];
    /* 0x48 */ int unk48;
    /* 0x4C */ u32 unk4C_0 : 1;
               u32 unk4C_1 : 1;
               u32 unk4C_2 : 1;
               u32 unk4C_3 : 29;
    /* 0x50 */ u8 pad_50[0x5C - 0x50];
} AnimSprite;

typedef struct AnimMgr
{
    /* 0x000 */ u32 unk000;
    /* 0x004 */ void *unk004;
    /* 0x008 */ AnimSprite sprites[14];
    /* 0x510 */ u8 pad_510[0x514 - 0x510];
    /* 0x514 */ u32 unk514;
    /* 0x518 */ u32 unk518;
    /* 0x51C */ u32 unk51C;
    /* 0x520 */ u32 unk520;
    /* 0x524 */ u32 unk524;
    /* 0x528 */ u8 pad_528[0x534 - 0x528];
    /* 0x534 */ u32 unk534;
    /* 0x538 */ u32 unk538;
    /* 0x53C */ u32 unk53C;
    /* 0x540 */ u8 pad_540[0x542 - 0x540];
    /* 0x542 */ u8 unk542[14];
    /* 0x550 */ u8 unk550[14];
    /* 0x55E */ u8 unk55E[14];
    /* 0x56C */ u8 unk56C[14];
    /* 0x57A */ u8 unk57A[14];
} AnimMgr;

void *sub_020159C8(void *renderer, s32 x, s32 y, s32 z, void *res);
void sub_02015BF0(void *renderer);
void sub_02015C00(void *renderer);
void sub_02015C0C(void *obj);
void sub_02015C1C(void *obj);
void sub_02015C48(void *obj, AnimVec3 *pos);
void sub_02015DB0(void *obj);
void sub_02015DC0(void *obj);
void sub_02015DD4(void *obj);
u32 sub_02015DF8(void *obj);
void sub_02015E04(void *obj);
void sub_02015E28(void *obj);
void sub_02015E4C(void *obj);
void sub_02015E70(void *obj);
u32 sub_02015E94(void *obj);
void sub_02015FF0(void *obj, u32 a1);
void sub_020160C4(void *obj, u32 a1);

void sub_022006A0(void *a0, void *res, int sprId);
void sub_022006B4(AnimMgr *sys, int sprId);
void sub_022018A8(AnimMgr *sys, AnimVec3 *vec, int sprId);
int sub_022019F4(AnimMgr *sys, int sprId);

void sub_021FF088(AnimMgr *sys, void *a1, int sprId)
{
    u8 res[0x24];
    AnimVec3 v;
    int i;

    for (i = 0; i < 14; i++)
    {
        if (sys->sprites[i].unk00 == NULL)
        {
            break;
        }
    }

    if (sprId >= 14)
    {
        return;
    }
    if (i >= 14)
    {
        return;
    }

    sys->sprites[i].unk4C_2 = 1;
    sys->sprites[i].unk48 = sprId;

    sub_022006A0(a1, res, sprId);
    sub_022018A8(sys, &v, sprId);
    sys->sprites[i].unk00 = sub_020159C8(sys->unk004, v.x, v.y, v.z, res);
    sub_022006B4(sys, sprId);
}

void sub_021FF134(AnimMgr *sys, u32 a1, u32 a2)
{
    sys->unk538 = a1;
    sys->unk53C = a2;
}

void sub_021FF144(AnimMgr *sys, int sprId, s32 x, s32 y, s32 z)
{
    AnimVec3 v;
    int idx;

    idx = sub_022019F4(sys, sprId);
    v.x = x;
    v.y = y;
    v.z = z;
    sub_02015C48(sys->sprites[idx].unk00, &v);
}

void sub_021FF16C(AnimMgr *sys)
{
    int i;
    int idx;

    sub_02015BF0(sys->unk004);
    sys->unk534 = 1;

    for (i = 0; i < 14; i++)
    {
        idx = sub_022019F4(sys, i);
        if (idx != -1)
        {
            sys->sprites[idx].unk4C_2 = 1;
            sub_022006B4(sys, i);
        }
    }
}

void sub_021FF1B0(AnimMgr *sys)
{
    int i;
    int idx;

    sub_02015C00(sys->unk004);
    sys->unk534 = 0;

    for (i = 0; i < 14; i++)
    {
        idx = sub_022019F4(sys, i);
        if (idx != -1)
        {
            sys->sprites[idx].unk4C_2 = 0;
            sub_022006B4(sys, i);
        }
    }
}

void sub_021FF1F4(AnimMgr *sys, int sprId)
{
    int idx;

    idx = sub_022019F4(sys, sprId);
    if (idx != -1)
    {
        sys->sprites[idx].unk4C_2 = 1;
        sub_02015C0C(sys->sprites[idx].unk00);
        sub_022006B4(sys, sprId);
    }
}

void sub_021FF228(AnimMgr *sys, int sprId)
{
    int idx;

    idx = sub_022019F4(sys, sprId);
    if (idx != -1)
    {
        sys->sprites[idx].unk4C_2 = 0;
        sub_02015C1C(sys->sprites[idx].unk00);
        sub_022006B4(sys, sprId);
    }
}

void sub_021FF260(AnimMgr *sys, int sprId, u32 mode)
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

    if (mode == 4)
    {
        sub_02015DC0(sys->sprites[idx].unk00);
        sys->sprites[idx].unk4C_0 = 0;
    }

    if (sys->sprites[idx].unk4C_0)
    {
        return;
    }

    if (mode == 2)
    {
        sub_02015DD4(sys->sprites[idx].unk00);
        return;
    }
    if (mode == 1)
    {
        sub_02015DB0(sys->sprites[idx].unk00);
        return;
    }
    if (mode == 3)
    {
        sub_02015DB0(sys->sprites[idx].unk00);
        sys->sprites[idx].unk4C_0 = 1;
        return;
    }
    sub_02015DC0(sys->sprites[idx].unk00);
}

u32 sub_021FF2D8(AnimMgr *sys, int sprId)
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
    return sub_02015DF8(sys->sprites[idx].unk00);
}

void sub_021FF304(AnimMgr *sys, int sprId, u32 mode)
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

    if (mode == 1)
    {
        sub_02015E04(sys->sprites[idx].unk00);
        return;
    }
    if (mode == 2)
    {
        sub_02015E28(sys->sprites[idx].unk00);
        return;
    }
    if (mode == 3)
    {
        sub_02015E70(sys->sprites[idx].unk00);
        return;
    }
    sub_02015E4C(sys->sprites[idx].unk00);
}

u32 sub_021FF348(AnimMgr *sys, int sprId)
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
    return sub_02015E94(sys->sprites[idx].unk00);
}

void sub_021FF470(AnimMgr *sys, int sprId, u32 a2)
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
    sub_02015FF0(sys->sprites[idx].unk00, a2);
}

void sub_021FF498(AnimMgr *sys, int sprId, u32 a2)
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
    sub_020160C4(sys->sprites[idx].unk00, a2);
}
