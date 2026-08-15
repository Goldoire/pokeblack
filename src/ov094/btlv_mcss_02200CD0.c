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
    /* 0x04 */ u8 pad_04[0x5C - 0x04];
} AnimSprite;

typedef struct AnimMgr
{
    /* 0x000 */ u32 unk000;
    /* 0x004 */ void *unk004;
    /* 0x008 */ AnimSprite sprites[14];
    /* 0x510 */ u8 pad_510[0x588 - 0x510];
    /* 0x588 */ u8 unk588[14];
    /* 0x596 */ u8 unk596[14];
} AnimMgr;

typedef struct AnimBlinkWork
{
    /* 0x00 */ AnimMgr *sys;
    /* 0x04 */ int sprId;
    /* 0x08 */ u8 pad_08[0x44 - 0x08];
    /* 0x44 */ int unk44;
    /* 0x48 */ int unk48;
    /* 0x4C */ int unk4C;
    /* 0x50 */ int unk50;
} AnimBlinkWork;

typedef struct AnimScaleWork
{
    /* 0x00 */ AnimMgr *sys;
    /* 0x04 */ int sprId;
    /* 0x08 */ AnimVec3 value;
    /* 0x14 */ u8 interp[0x50 - 0x14];
    /* 0x50 */ int unk50;
} AnimScaleWork;

void sub_02015FBC(void *obj, u8 alpha);

void sub_021F89BC(void *task);
int sub_021F9260(void *interp, AnimVec3 *vec);
void sub_021FF260(AnimMgr *sys, int sprId, u32 mode);
BOOL sub_021FFD9C(AnimMgr *sys, int sprId);
int sub_022019F4(AnimMgr *sys, int sprId);

void sub_02200CD0(void *task, AnimBlinkWork *work)
{
    AnimMgr *sys;

    sys = work->sys;
    if (sub_021FFD9C(sys, work->sprId) == 0 ||
        work->unk50 != sys->unk588[work->sprId])
    {
        sub_021F89BC(task);
        return;
    }

    if (work->unk44 == 0)
    {
        work->unk44 = work->unk48;
        sub_021FF260(work->sys, work->sprId, 2);
        work->unk4C--;
        if (work->unk4C == 0)
        {
            sub_021FF260(work->sys, work->sprId, 0);
            sub_021F89BC(task);
        }
    }
    else
    {
        work->unk44--;
    }
}

void sub_02200D68(void *task, AnimScaleWork *work)
{
    AnimMgr *sys;
    int idx;
    int done;

    sys = work->sys;
    idx = sub_022019F4(sys, work->sprId);
    if (idx == -1)
    {
        sub_021F89BC(task);
        return;
    }
    if (sys->sprites[idx].unk00 == NULL)
    {
        sub_021F89BC(task);
        return;
    }
    if (work->unk50 != sys->unk596[work->sprId])
    {
        sub_021F89BC(task);
        return;
    }

    done = sub_021F9260(work->interp, &work->value);
    sub_02015FBC(sys->sprites[idx].unk00, (u8)(work->value.x >> 12));

    if (done == 1)
    {
        sub_021F89BC(task);
    }
}
