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
    /* 0x510 */ u8 pad_510[0x542 - 0x510];
    /* 0x542 */ u8 unk542[14];
    /* 0x550 */ u8 unk550[14];
    /* 0x55E */ u8 unk55E[14];
    /* 0x56C */ u8 unk56C[14];
    /* 0x57A */ u8 unk57A[14];
} AnimMgr;

// Per-move task work, built by sub_0220074C. 0x14 is the interpolator state fed
// to sub_021F9260 (which returns 1 on the final step); 0x50 snapshots the
// per-slot sequence counter so a stale task cancels itself.
typedef struct AnimMoveWork
{
    /* 0x00 */ AnimMgr *sys;
    /* 0x04 */ int sprId;
    /* 0x08 */ u8 pad_08[0x14 - 0x08];
    /* 0x14 */ u8 interp[0x50 - 0x14];
    /* 0x50 */ int unk50;
} AnimMoveWork;

void sub_02015C30(void *obj, AnimVec3 *out);
void sub_02015C48(void *obj, AnimVec3 *pos);
void sub_02015C94(void *obj, AnimVec3 *out);
void sub_02015CAC(void *obj, AnimVec3 *pos);
void sub_02015CC4(void *obj, AnimVec3 *out);
void sub_02015CDC(void *obj, AnimVec3 *pos);
void sub_02015CF8(void *obj, AnimVec3 *out);
void sub_02015D14(void *obj, AnimVec3 *pos);
void sub_02015D4C(void *obj, AnimVec3 *out);
void sub_02015D64(void *obj, AnimVec3 *pos);

void sub_021F89BC(void *task);
int sub_021F9260(void *interp, AnimVec3 *vec);
int sub_022019F4(AnimMgr *sys, int sprId);

void sub_02200904(void *task, AnimMoveWork *work)
{
    AnimVec3 v;
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
    if (work->unk50 != sys->unk542[work->sprId])
    {
        sub_021F89BC(task);
        return;
    }

    sub_02015C30(sys->sprites[idx].unk00, &v);
    done = sub_021F9260(work->interp, &v);
    sub_02015C48(sys->sprites[idx].unk00, &v);

    if (done == 1)
    {
        sub_021F89BC(task);
    }
}

void sub_022009C8(void *task, AnimMoveWork *work)
{
    AnimVec3 v;
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
    if (work->unk50 != sys->unk550[work->sprId])
    {
        sub_021F89BC(task);
        return;
    }

    sub_02015CC4(sys->sprites[idx].unk00, &v);
    done = sub_021F9260(work->interp, &v);
    sub_02015CDC(sys->sprites[idx].unk00, &v);

    if (done == 1)
    {
        sub_021F89BC(task);
    }
}

void sub_02200A84(void *task, AnimMoveWork *work)
{
    AnimVec3 v;
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
    if (work->unk50 != sys->unk55E[work->sprId])
    {
        sub_021F89BC(task);
        return;
    }

    sub_02015C94(sys->sprites[idx].unk00, &v);
    done = sub_021F9260(work->interp, &v);
    sub_02015CAC(sys->sprites[idx].unk00, &v);

    if (done == 1)
    {
        sub_021F89BC(task);
    }
}

void sub_02200B48(void *task, AnimMoveWork *work)
{
    AnimVec3 v;
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
    if (work->unk50 != sys->unk56C[work->sprId])
    {
        sub_021F89BC(task);
        return;
    }

    sub_02015D4C(sys->sprites[idx].unk00, &v);
    done = sub_021F9260(work->interp, &v);
    sub_02015D64(sys->sprites[idx].unk00, &v);

    if (done == 1)
    {
        sub_021F89BC(task);
    }
}

void sub_02200C0C(void *task, AnimMoveWork *work)
{
    AnimVec3 v;
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
    if (work->unk50 != sys->unk57A[work->sprId])
    {
        sub_021F89BC(task);
        return;
    }

    sub_02015CF8(sys->sprites[idx].unk00, &v);
    done = sub_021F9260(work->interp, &v);
    sub_02015D14(sys->sprites[idx].unk00, &v);

    if (done == 1)
    {
        sub_021F89BC(task);
    }
}
