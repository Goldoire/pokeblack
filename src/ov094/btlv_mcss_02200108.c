#include "types.h"

// 0x24-byte sprite resource header: the same block sub_021FF088 builds on the
// stack via sub_022006A0 and hands to sub_020159C8.
typedef struct AnimSprRes
{
    /* 0x00 */ u32 unk00;
    /* 0x04 */ s32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ s32 unk0C;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ u32 unk20;
} AnimSprRes;

typedef struct AnimSprXform
{
    /* 0x00 */ u32 unk00;
    /* 0x04 */ u32 unk04;
    /* 0x08 */ u32 unk08;
    /* 0x0C */ u16 unk0C;
    /* 0x0E */ u16 unk0E;
} AnimSprXform;

typedef struct AnimSprite
{
    /* 0x00 */ void *unk00;
    /* 0x04 */ AnimSprRes res;
    /* 0x28 */ void *unk28;
    /* 0x2C */ AnimSprXform xf;
    /* 0x3C */ u32 unk3C;
    /* 0x40 */ u32 unk40;
    /* 0x44 */ u32 unk44;
    /* 0x48 */ int unk48;
    /* 0x4C */ u32 unk4C;
    /* 0x50 */ u8 pad_50[0x5C - 0x50];
} AnimSprite;

typedef struct AnimMgr
{
    /* 0x000 */ u32 unk000;
    /* 0x004 */ void *unk004;
    /* 0x008 */ AnimSprite sprites[14];
} AnimMgr;

void sub_02014CF8(void *renderer, void *obj, AnimSprRes *res);
void sub_02016078(void *renderer, void *obj, u32 a2);
void sub_020172AC(void *renderer, u32 a1);

int sub_022019F4(AnimMgr *sys, int sprId);

void sub_02200108(AnimMgr *sys, int sprId, u32 a2)
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

    sub_020172AC(sys->unk004, sys->sprites[idx].xf.unk08);
    sub_02016078(sys->unk004, sys->sprites[idx].unk00, a2);
}

void sub_02200140(AnimMgr *sys, int srcId, int dstId)
{
    int src;
    int dst;

    src = sub_022019F4(sys, srcId);
    dst = sub_022019F4(sys, dstId);

    sys->sprites[dst].res.unk00 = sys->sprites[src].res.unk00;
    sys->sprites[dst].res.unk08 = sys->sprites[src].res.unk08;

    if (srcId & 1)
    {
        sys->sprites[dst].res.unk04 = sys->sprites[src].res.unk04 + 9;
        sys->sprites[dst].res.unk0C = sys->sprites[src].res.unk0C + 9;
        sys->sprites[dst].res.unk10 = sys->sprites[src].res.unk10 + 9;
        sys->sprites[dst].res.unk14 = sys->sprites[src].res.unk14 + 9;
        sys->sprites[dst].res.unk18 = sys->sprites[src].res.unk18 + 9;
        sys->sprites[dst].res.unk1C = sys->sprites[src].res.unk1C + 9;
    }
    else
    {
        sys->sprites[dst].res.unk04 = sys->sprites[src].res.unk04 - 9;
        sys->sprites[dst].res.unk0C = sys->sprites[src].res.unk0C - 9;
        sys->sprites[dst].res.unk10 = sys->sprites[src].res.unk10 - 9;
        sys->sprites[dst].res.unk14 = sys->sprites[src].res.unk14 - 9;
        sys->sprites[dst].res.unk18 = sys->sprites[src].res.unk18 - 9;
        sys->sprites[dst].res.unk1C = sys->sprites[src].res.unk1C - 9;
    }

    sys->sprites[dst].xf = sys->sprites[src].xf;

    sub_02014CF8(sys->unk004, sys->sprites[dst].unk00, &sys->sprites[dst].res);
}

void sub_022001DC(AnimMgr *sys, int sprId, AnimSprRes *res)
{
    int idx;

    idx = sub_022019F4(sys, sprId);

    sys->sprites[idx].res = *res;

    sub_020172AC(sys->unk004, sys->sprites[idx].xf.unk08);
    sub_02014CF8(sys->unk004, sys->sprites[idx].unk00, &sys->sprites[idx].res);
}
