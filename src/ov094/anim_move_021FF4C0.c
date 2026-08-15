#include "types.h"

typedef struct AnimVec3
{
    s32 x;
    s32 y;
    s32 z;
} AnimVec3;

// One slot per on-screen battle-animation sprite. 14 slots (0xE), which is also
// the length of every per-slot u8 counter row at 0x542/0x550/0x55E/0x56C/0x57A.
typedef struct AnimSprite
{
    /* 0x00 */ u8 pad_00[0x08];
    /* 0x08 */ void *unk08;
    /* 0x0C */ u8 pad_0C[0x5C - 0x0C];
} AnimSprite;

typedef struct AnimMgr
{
    /* 0x000 */ AnimSprite sprites[14];
    /* 0x508 */ u8 pad_508[0x514 - 0x508];
    /* 0x514 */ u32 unk514;
    /* 0x518 */ u32 unk518;
    /* 0x51C */ u32 unk51C;
    /* 0x520 */ u32 unk520;
    /* 0x524 */ u32 unk524;
    /* 0x528 */ u8 pad_528[0x542 - 0x528];
    /* 0x542 */ u8 unk542[14];
    /* 0x550 */ u8 unk550[14];
    /* 0x55E */ u8 unk55E[14];
    /* 0x56C */ u8 unk56C[14];
    /* 0x57A */ u8 unk57A[14];
} AnimMgr;

typedef void (*AnimStepFunc)(void);

void sub_02015C30(void *obj, AnimVec3 *out);
void sub_02015C48(void *obj, AnimVec3 *pos);
void sub_02015C94(void *obj, AnimVec3 *out);
void sub_02015CC4(void *obj, AnimVec3 *out);
void sub_02015CF8(void *obj, AnimVec3 *out);

u32 sub_021F935C(u32 sprId);
void sub_022018A8(AnimMgr *sys, AnimVec3 *vec, u32 sprId);
int sub_022019F4(AnimMgr *sys, u32 sprId);
void sub_0220074C(AnimMgr *sys, u32 sprId, u32 kind, AnimVec3 *from, AnimVec3 *to,
                  u32 a5, u32 a6, u32 a7, AnimStepFunc fn1, AnimStepFunc fn2,
                  int a10, int a11);

// Step callbacks, referenced as Thumb function pointers (low bit set). They are
// spelled as data symbols at <addr>|1 because mwcc emits an *undefined* function
// as STT_NOTYPE, and the verifier only adds the Thumb bit for STT_FUNC.
extern const u8 _02200905[]; // sub_02200904
extern const u8 _02200991[]; // sub_02200990
extern const u8 _022009C9[]; // sub_022009C8
extern const u8 _02200A51[]; // sub_02200A50
extern const u8 _02200A85[]; // sub_02200A84
extern const u8 _02200B11[]; // sub_02200B10
extern const u8 _02200B49[]; // sub_02200B48
extern const u8 _02200BD5[]; // sub_02200BD4
extern const u8 _02200C0D[]; // sub_02200C0C
extern const u8 _02200C99[]; // sub_02200C98

void sub_021FF4C0(AnimMgr *sys, u32 sprId, u32 kind, AnimVec3 *vec, u32 a4, u32 a5, u32 a6)
{
    AnimVec3 base;
    int idx;

    idx = sub_022019F4(sys, sprId);
    if (idx == -1)
    {
        return;
    }
    if (sys->sprites[idx].unk08 == NULL)
    {
        return;
    }

    sub_02015C30(sys->sprites[idx].unk08, &base);

    if (kind == 1)
    {
        if (sprId & 1)
        {
            vec->x = base.x - vec->x;
        }
        else
        {
            vec->x = vec->x + base.x;
        }
        vec->y = vec->y + base.y;
        vec->z = vec->z + base.z;
    }

    if (kind == 5)
    {
        sub_022018A8(sys, vec, sprId);
        kind = 1;
    }

    if (kind == 6)
    {
        sub_022018A8(sys, vec, sprId);
        kind = 0;
    }

    if (kind == 0)
    {
        sub_02015C48(sys->sprites[idx].unk08, vec);
        return;
    }

    sys->unk542[sprId]++;
    sub_0220074C(sys, sprId, kind, &base, vec, a4, a5, a6,
                 (AnimStepFunc)_02200905, (AnimStepFunc)_02200991, 1, sys->unk542[sprId]);
    sys->unk514 |= sub_021F935C(sprId);
}

void sub_021FF5B0(AnimMgr *sys, u32 sprId, u32 kind, AnimVec3 *vec, u32 a4, u32 a5, u32 a6)
{
    AnimVec3 base;
    int idx;

    idx = sub_022019F4(sys, sprId);
    if (idx == -1)
    {
        return;
    }
    if (sys->sprites[idx].unk08 == NULL)
    {
        return;
    }

    sub_02015CC4(sys->sprites[idx].unk08, &base);

    sys->unk550[sprId]++;
    sub_0220074C(sys, sprId, kind, &base, vec, a4, a5, a6,
                 (AnimStepFunc)_022009C9, (AnimStepFunc)_02200A51, 0, sys->unk550[sprId]);
    sys->unk518 |= sub_021F935C(sprId);
}

void sub_021FF630(AnimMgr *sys, u32 sprId, u32 kind, AnimVec3 *vec, u32 a4, u32 a5, u32 a6)
{
    AnimVec3 base;
    int idx;

    idx = sub_022019F4(sys, sprId);
    if (idx == -1)
    {
        return;
    }
    if (sys->sprites[idx].unk08 == NULL)
    {
        return;
    }

    sub_02015C94(sys->sprites[idx].unk08, &base);

    sys->unk55E[sprId]++;
    sub_0220074C(sys, sprId, kind, &base, vec, a4, a5, a6,
                 (AnimStepFunc)_02200A85, (AnimStepFunc)_02200B11, 0, sys->unk55E[sprId]);
    sys->unk520 |= sub_021F935C(sprId);
}

void sub_021FF6B0(AnimMgr *sys, u32 sprId, u32 kind, AnimVec3 *vec, u32 a4, u32 a5, u32 a6)
{
    AnimVec3 base;
    int idx;

    idx = sub_022019F4(sys, sprId);
    if (idx == -1)
    {
        return;
    }
    if (sys->sprites[idx].unk08 == NULL)
    {
        return;
    }

    sub_02015CC4(sys->sprites[idx].unk08, &base);

    sys->unk56C[sprId]++;
    sub_0220074C(sys, sprId, kind, &base, vec, a4, a5, a6,
                 (AnimStepFunc)_02200B49, (AnimStepFunc)_02200BD5, 0, sys->unk56C[sprId]);
    sys->unk524 |= sub_021F935C(sprId);
}

void sub_021FF730(AnimMgr *sys, u32 sprId, u32 kind, AnimVec3 *vec, u32 a4, u32 a5, u32 a6)
{
    AnimVec3 base;
    int idx;

    idx = sub_022019F4(sys, sprId);
    if (idx == -1)
    {
        return;
    }
    if (sys->sprites[idx].unk08 == NULL)
    {
        return;
    }

    sub_02015CF8(sys->sprites[idx].unk08, &base);

    sys->unk57A[sprId]++;
    sub_0220074C(sys, sprId, kind, &base, vec, a4, a5, a6,
                 (AnimStepFunc)_02200C0D, (AnimStepFunc)_02200C99, 1, sys->unk57A[sprId]);
    sys->unk51C |= sub_021F935C(sprId);
}
