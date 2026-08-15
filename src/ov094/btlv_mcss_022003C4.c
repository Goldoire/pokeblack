#include "types.h"

typedef struct AnimVec3
{
    s32 x;
    s32 y;
    s32 z;
} AnimVec3;

typedef struct AnimSprite
{
    /* 0x00 */ void *unk00;
    /* 0x04 */ u8 pad_04[0x3C - 0x04];
    /* 0x3C */ u32 unk3C;
    /* 0x40 */ u32 unk40;
    /* 0x44 */ u32 unk44;
    /* 0x48 */ int unk48;
    /* 0x4C */ u32 unk4C_0 : 1;
               u32 unk4C_1 : 1;
               u32 unk4C_2 : 1;
               u32 unk4C_3 : 3;
               u32 unk4C_6 : 1;
               u32 unk4C_7 : 1;
               u32 unk4C_8 : 1;
               u32 unk4C_9 : 1;
               u32 unk4C_10 : 1;
               u32 unk4C_11 : 21;
    /* 0x50 */ u8 pad_50[0x5C - 0x50];
} AnimSprite;

typedef struct AnimMgr
{
    /* 0x000 */ u32 unk000;
    /* 0x004 */ void *unk004;
    /* 0x008 */ AnimSprite sprites[14];
} AnimMgr;

// Callback handed to sub_02015F2C; spelled as data because mwcc types an
// undefined function symbol STT_NOTYPE, which loses the Thumb bit.
extern const u8 _02201895[]; // sub_02201894

void sub_02015C30(void *obj, AnimVec3 *out);
void sub_02015C48(void *obj, AnimVec3 *pos);
void sub_02015C60(void *obj, AnimVec3 *out);
void sub_02015C78(void *obj, AnimVec3 *rot);
void sub_02015EA0(void *obj);
void sub_02015F2C(void *obj, int a1, void *cb, int a3);
void sub_02016028(void *obj, int frame);
int sub_020160CC(void *obj);
void sub_02016394(void *obj, int flag);
void sub_02017100(void *res, u32 a1, u32 a2);
u32 sub_02017E1C(void *res, int field, int idx);
void sub_020172AC(void *renderer, u32 a1);

int sub_021F8710(void);
void sub_022018A8(AnimMgr *sys, AnimVec3 *vec, int sprId);
int sub_022019F4(AnimMgr *sys, int sprId);

u32 sub_022003C4(AnimMgr *sys, int sprId)
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
    return sys->sprites[idx].unk3C;
}

void sub_022003EC(AnimMgr *sys, void *res, u32 a2, u32 a3)
{
    u32 flag;

    flag = 1;
    if (a3 & 1)
    {
        flag = 0;
    }

    sub_02017100(res, a2, flag);
    sub_020172AC(sys->unk004, sub_02017E1C(res, 0, 0));
}

BOOL sub_0220041C(AnimMgr *sys, int sprId, int frame)
{
    BOOL ret;
    int idx;

    ret = FALSE;
    idx = sub_022019F4(sys, sprId);
    if (idx == -1)
    {
        return ret;
    }
    if (sys->sprites[idx].unk00 == NULL)
    {
        return ret;
    }

    if (frame < sub_020160CC(sys->sprites[idx].unk00))
    {
        sub_02016028(sys->sprites[idx].unk00, frame);
        ret = TRUE;
        sys->sprites[idx].unk44 = ret;
    }

    return ret;
}

void sub_02200468(AnimMgr *sys, int sprId)
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
    sub_02015F2C(sys->sprites[idx].unk00, idx, (void *)_02201895, 1);
}

u32 sub_02200494(AnimMgr *sys, int sprId)
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
    return sys->sprites[idx].unk44;
}

void sub_022004BC(AnimMgr *sys, int sprId)
{
    AnimVec3 home;
    AnimVec3 pos;
    AnimVec3 rot;
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

    sub_022018A8(sys, &home, sprId);
    sub_02015C30(sys->sprites[idx].unk00, &pos);
    sub_02015C60(sys->sprites[idx].unk00, &rot);

    sys->sprites[idx].unk4C_6 = 0;

    if (home.x != pos.x || home.y != pos.y || home.z != pos.z ||
        rot.x != 0 || rot.y != 0 || rot.z != 0)
    {
        sys->sprites[idx].unk4C_6 = 1;
        rot.x = 0;
        rot.y = 0;
        rot.z = 0;
        sub_02015C48(sys->sprites[idx].unk00, &home);
        sub_02015C78(sys->sprites[idx].unk00, &rot);
        sub_02015EA0(sys->sprites[idx].unk00);
    }
}

BOOL sub_022005C4(AnimMgr *sys, int sprId)
{
    BOOL ret;
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

    if (sys->sprites[idx].unk4C_9)
    {
        ret = TRUE;
    }
    else
    {
        ret = FALSE;
    }
    sys->sprites[idx].unk4C_9 = 0;

    return ret;
}
