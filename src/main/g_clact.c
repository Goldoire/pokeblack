/* clact.c -- GameFreak's cell-actor (2D sprite) system.
 * main 0x0204A48C..0x0204E074, ARM.  Compiler: repo default dsi/1.1.
 * Build: python tools/scripts/cc.py src/main/g_clact.c        (no --thumb)
 */
#include "g_clact.h"

void sub_0204B528(GClact *act, const GClactVec2 *pos);
void sub_0204B53C(const GClact *act, GClactVec2 *pos);
void sub_0204B550(GClact *act, s16 v, u32 which);
s16 sub_0204B560(const GClact *act, u32 which);
void sub_0204B95C(GClact *act);
void sub_0204B878(GClact *act, u32 seq);
void sub_0204B8D4(GClact *act, u32 frames);
void sub_0204B49C(GClact *act, s16 v, u32 a2, u32 which);
void sub_0204B84C(GClact *act, u32 v);
void sub_0204B784(GClact *act, GNNSImageProxy *src);
void sub_0204B728(GClact *act, GNNSImagePaletteProxy *src);
void sub_0204B3DC(GClact *act, u32 v);
void sub_0204B270(GClactSet *set);
void sub_0204B59C(GClact *act, s16 v, u32 which);
void sub_0204B5D4(GClact *act, u32 v, u32 which);
void sub_0204B5F4(GClact *act, u16 v);
void sub_0204B570(GClact *act, u32 v);
GClact *sub_0204CFDC(GClactSet *set, const struct GClactInit *init, const struct GClactResHeader *hdr, u32 a3, u16 a4);
void sub_0204B22C(GClactSet *set, u32 a1);
void sub_0204BBC8(GClactSet *set);
void sub_0204BC40(GClactSet *set);
void sub_0204B3B4(GClact *act);
void sub_0204CAE4(GClact *act);
void sub_0204BCF4(struct GClactCoreEntry *p);
u8 sub_0204B838(const GClact *act);

/* ---- GClactSet ------------------------------------------------------- */

void sub_0204B22C(GClactSet *set, u32 a1)
{
    set->unk0E_4 = a1;
}

u8 sub_0204B248(GClactSet *set)
{
    return set->unk0E_4;
}

void sub_0204B258(GClactSet *set, GClactRenderer *a1)
{
    set->renderer = a1;
    set->unk0E_0 = 1;
}

/* ---- GClact position / vectors --------------------------------------- */

void sub_0204B528(GClact *act, const GClactVec2 *pos)
{
    act->pos = *pos;
}

void sub_0204B53C(const GClact *act, GClactVec2 *pos)
{
    *pos = act->pos;
}

void sub_0204B550(GClact *act, s16 v, u32 which)
{
    if (which == 0)
    {
        act->pos.x = v;
    }
    else
    {
        act->pos.y = v;
    }
}

s16 sub_0204B560(const GClact *act, u32 which)
{
    if (which == 0)
    {
        return act->pos.x;
    }
    return act->pos.y;
}

void sub_0204B588(GClact *act, const GClactVec2 *pos)
{
    act->unk10 = *pos;
}

void sub_0204B59C(GClact *act, s16 v, u32 which)
{
    if (which == 0)
    {
        act->unk10.x = v;
    }
    else
    {
        act->unk10.y = v;
    }
}

void sub_0204B5AC(GClact *act, const GClactVec2u32 *v)
{
    act->scale.x = v->x;
    act->scale.y = v->y;
}

void sub_0204B5C0(const GClact *act, GClactVec2u32 *v)
{
    v->x = act->scale.x;
    v->y = act->scale.y;
}

void sub_0204B5D4(GClact *act, u32 v, u32 which)
{
    if (which == 0)
    {
        act->scale.x = v;
    }
    else
    {
        act->scale.y = v;
    }
}

u32 sub_0204B5E4(const GClact *act, u32 which)
{
    if (which == 0)
    {
        return act->scale.x;
    }
    return act->scale.y;
}

void sub_0204B5F4(GClact *act, u16 v)
{
    act->unk58 = v;
}

u16 sub_0204B5FC(const GClact *act)
{
    return act->unk58;
}

u16 sub_0204B7F0(const GClact *act)
{
    return act->unk5C;
}

u16 sub_0204B7F8(const GClact *act)
{
    return act->unk5E;
}

u16 sub_0204B898(const GClact *act)
{
    return act->animSeq;
}

void sub_0204B954(GClact *act, u32 v)
{
    act->animSpeed = v;
}

/* ---- GClact 0x60 bitfields ------------------------------------------- */

u8 sub_0204B838(const GClact *act)
{
    return act->unk60_00;
}

u8 sub_0204B714(const GClact *act)
{
    return act->unk60_0C;
}

void sub_0204B84C(GClact *act, u32 v)
{
    act->unk60_10 = v;
}

u8 sub_0204B864(const GClact *act)
{
    return act->unk60_10;
}

void sub_0204B570(GClact *act, u32 v)
{
    act->unk60_12 = v;
}

u32 sub_0204B6E4(const GClact *act)
{
    return act->unk60_16;
}

void sub_0204B92C(GClact *act, u32 v)
{
    act->unk60_19 = v;
}

u32 sub_0204B944(const GClact *act)
{
    return act->unk60_19;
}

void sub_0204B3DC(GClact *act, u32 v)
{
    act->unk60_1A = v;
}

u32 sub_0204B3F4(const GClact *act)
{
    return act->unk60_1A;
}

void sub_0204B6F4(GClact *act, u32 a1, u32 a2)
{
    act->unk60_0C = a1;
    act->unk60_1F = a2;
}

void sub_0204BA20(GClact *act, u32 v)
{
    if (v == 0)
    {
        act->unk64_00 = 1;
    }
    else
    {
        act->unk64_00 = 0;
    }
}

/* ---- external ------------------------------------------------------- */

extern GClactCore *_02146A74;

void sub_0204CA30(GClactSet *list, GClact *act);
void sub_0204C98C(GClactSet *list, GClact *act);
void sub_0204CAE4(GClact *act);
void sub_0204CF74(GClact *act, u32 a1, GClactVec2 *out);
void sub_0204D104(GClactAnim *anim);
void sub_0204D324(GClactAnim *anim, u32 seq);
void sub_0204D3A0(GClactAnim *anim, u32 a1);
void sub_0204D3C4(GClactAnim *anim, u32 a1);
GClactAnimCtrl *sub_0204D410(GClactAnim *anim);
GClactAnimCtrl *sub_0204D444(GClactAnim *anim);
u32 sub_0204D478(GClactAnim *anim);
void sub_0204D4C4(GClactAnim *anim);
void sub_0204D510(GClactAnim *anim);
u32 sub_0204D768(GClactAnim *anim);
u32 sub_0204D7C4(GClactAnim *anim);
u32 sub_02062F1C(GClactAnimCtrl *ctrl);
void sub_0206380C(GNNSImagePaletteProxy *p, u32 a1);
void sub_020637BC(GNNSImageProxy *p, u32 a1);

/* ---- GClactSet, continued -------------------------------------------- */

void sub_0204B270(GClactSet *set)
{
    set->renderer = &_02146A74->renderer;
    set->unk0E_0 = 0;
}

/* ---- GClact lifecycle ------------------------------------------------ */

void sub_0204B3B4(GClact *act)
{
    sub_0204CA30((GClactSet *)act->list, act);
    sub_0204D104(&act->anim);
    sub_0204CAE4(act);
}

/* ---- GClact position helpers ----------------------------------------- */

void sub_0204B404(GClact *act, const GClactVec2 *pos, u32 a2)
{
    GClactVec2 off;
    GClactVec2 res;

    sub_0204CF74(act, a2, &off);
    res.x = pos->x + off.x;
    res.y = pos->y + off.y;
    sub_0204B528(act, &res);
}

void sub_0204B454(GClact *act, GClactVec2 *pos, u32 a2)
{
    GClactVec2 off;

    sub_0204CF74(act, a2, &off);
    sub_0204B53C(act, pos);
    pos->x = pos->x - off.x;
    pos->y = pos->y - off.y;
}

void sub_0204B49C(GClact *act, s16 v, u32 a2, u32 which)
{
    GClactVec2 off;

    sub_0204CF74(act, a2, &off);
    if (which == 0)
    {
        v = v + off.x;
    }
    else
    {
        v = v + off.y;
    }
    sub_0204B550(act, v, which);
}

s16 sub_0204B4EC(GClact *act, u32 a1, u32 which)
{
    GClactVec2 off;
    s16 v;
    s16 t;

    sub_0204CF74(act, a1, &off);
    v = sub_0204B560(act, which);
    if (which == 0)
    {
        t = off.x;
    }
    else
    {
        t = off.y;
    }
    return v - t;
}

/* ---- GClact 0x60 bitfields, continued -------------------------------- */

void sub_0204B604(GClact *act, u32 which, u32 enable)
{
    u32 mask;

    if (which == 0)
    {
        mask = 1;
    }
    else
    {
        mask = 2;
    }
    if (enable == 0)
    {
        act->unk60_14 &= ~mask;
    }
    else
    {
        act->unk60_14 |= mask;
    }
}

u32 sub_0204B658(const GClact *act, u32 which)
{
    u32 ret = 0;
    u32 v = act->unk60_14;

    if (which == 0)
    {
        if (v & 1)
        {
            ret = 1;
        }
    }
    else
    {
        if (v & 2)
        {
            ret = 1;
        }
    }
    return ret;
}

void sub_0204B688(GClact *act, u32 v)
{
    act->unk60_16 = v;
    if (v == 0)
    {
        if (act->unk60_08 & 8)
        {
            act->unk60_08 ^= 8;
        }
    }
    else
    {
        act->unk60_08 |= 8;
    }
}

void sub_0204B800(GClact *act, u8 v)
{
    act->unk60_00 = v;
    sub_0204CA30((GClactSet *)act->list, act);
    sub_0204C98C((GClactSet *)act->list, act);
}

/* ---- GClact block copies --------------------------------------------- */

void sub_0204B728(GClact *act, GNNSImagePaletteProxy *src)
{
    sub_0206380C(src, 1);
    sub_0206380C(src, 2);
    act->palProxy = *src;
}

void sub_0204B764(const GClact *act, GNNSImagePaletteProxy *dst)
{
    *dst = act->palProxy;
}

void sub_0204B784(GClact *act, GNNSImageProxy *src)
{
    sub_020637BC(src, 1);
    sub_020637BC(src, 2);
    act->imageProxy = *src;
}

void sub_0204B7C8(const GClact *act, GNNSImageProxy *dst)
{
    *dst = act->imageProxy;
}

/* ---- GClact animation ------------------------------------------------ */

void sub_0204B878(GClact *act, u32 seq)
{
    act->animSeq = seq;
    sub_0204D324(&act->anim, seq);
    sub_0204B95C(act);
}

void sub_0204B8A0(GClact *act, u32 seq)
{
    if (seq != act->animSeq)
    {
        sub_0204B878(act, seq);
        sub_0204B95C(act);
    }
}

void sub_0204B8C4(GClact *act, u32 a1)
{
    sub_0204D3A0(&act->anim, a1);
}

/* The `frames` parameter is dead in the retail build -- the body passes
 * FX32_ONE -- but sub_0204CEB4 still loads GClact.animSpeed for it, which is
 * only reproducible if the prototype keeps two parameters. */
void sub_0204B8D4(GClact *act, u32 frames)
{
    sub_0204D4C4(&act->anim);
    sub_0204D3C4(&act->anim, 0x1000);
}

u32 sub_0204B8F4(GClact *act)
{
    return sub_0204D444(&act->anim)->currentTime;
}

u32 sub_0204B908(GClact *act)
{
    return sub_0204D478(&act->anim);
}

u32 sub_0204B918(GClact *act)
{
    return sub_02062F1C(sub_0204D444(&act->anim));
}

void sub_0204B95C(GClact *act)
{
    sub_0204D410(&act->anim)->bActive = 1;
}

void sub_0204B974(GClact *act)
{
    sub_0204D410(&act->anim)->bActive = 0;
}

u32 sub_0204B98C(GClact *act)
{
    return sub_0204D444(&act->anim)->bActive;
}

void sub_0204B9A0(GClact *act)
{
    sub_0204D410(&act->anim)->bActive = 1;
    sub_0204D510(&act->anim);
}

void sub_0204B9C4(GClact *act, u32 mode)
{
    GClactAnimCtrl *ctrl;

    act->unk60_1B = mode;
    ctrl = sub_0204D410(&act->anim);
    if (mode == 0)
    {
        ctrl->bReverse = 0;
        ctrl->overriddenPlayMode = 0;
    }
    else
    {
        ctrl->overriddenPlayMode = mode;
    }
}

u32 sub_0204BA00(GClact *act)
{
    return sub_0204D768(&act->anim);
}

u32 sub_0204BA10(GClact *act)
{
    return sub_0204D7C4(&act->anim);
}

/* ---- GClactCore singleton, list management --------------------------- */

u32 sub_02063800(void *a0, u32 a1);
void sub_02063078(void);
void sub_02063138(GClactCoreEntry *p, u32 a1, u32 a2, u32 a3);
void sub_0206343C(GClactCoreEntry *p);
void sub_02063640(GClactCoreEntry *p);
void sub_0204C944(GClactSet *set);
void sub_0204BD18(GClactCoreEntry *p);
void sub_0204BD3C(GClactCoreEntry *p, u32 a1, u32 a2, u32 a3);
void sub_0204BD64(GClactCoreEntry *p);
void sub_0204BD7C(GClactCoreEntry *p);
u32 sub_0204BB38(void);
void sub_0204BB20(u32 v);

void sub_0204BA7C(void *a0, u16 a1, u32 a2)
{
    _02146A74->unkF0 = sub_02063800(a0, 1) >> 5;
    _02146A74->unkF2 = sub_02063800(a0, 2) >> 5;
    _02146A74->unkF0 += a1;
    _02146A74->unkF2 += a1;
    _02146A74->unkF4 = a2;
}

void sub_0204BAEC(u32 v)
{
    if (_02146A74 != NULL)
    {
        _02146A74->unkF8 = v;
    }
}

u32 sub_0204BB04(void)
{
    if (_02146A74 != NULL)
    {
        return _02146A74->unkF8;
    }
    return 0;
}

void sub_0204BB20(u32 v)
{
    if (_02146A74 != NULL)
    {
        _02146A74->unkFC = v;
    }
}

u32 sub_0204BB38(void)
{
    if (_02146A74 != NULL)
    {
        return _02146A74->unkFC;
    }
    return 0;
}

void sub_0204BB54(void)
{
    if (_02146A74 == NULL)
    {
        return;
    }
    if (sub_0204BB38() == 0)
    {
        return;
    }
    sub_0204BD18(_02146A74->engine);
    sub_0204BB20(0);
}

void sub_0204BB8C(void)
{
    GClactSet *set = _02146A74->head;

    if (set == NULL)
    {
        return;
    }
    do
    {
        sub_0204C944(set);
        set = set->next;
    } while (set != _02146A74->head);
}

void sub_0204BBC8(GClactSet *set)
{
    GClactSet *p;

    if (_02146A74->head == NULL)
    {
        _02146A74->head = set;
        _02146A74->head->next = set;
        _02146A74->head->prev = set;
        return;
    }
    p = _02146A74->head;
    do
    {
        if (p->unk0F > set->unk0F)
        {
            break;
        }
        p = p->next;
    } while (p != _02146A74->head);
    p = p->prev;
    set->prev = p;
    set->next = p->next;
    p->next->prev = set;
    p->next = set;
}

void sub_0204BC40(GClactSet *set)
{
    if (_02146A74->head == set)
    {
        if (set->next == set)
        {
            _02146A74->head = NULL;
        }
        else
        {
            _02146A74->head = set->next;
        }
    }
    set->next->prev = set->prev;
    set->prev->next = set->next;
    set->next = NULL;
    set->prev = NULL;
}

void sub_0204BC94(GClactCoreEntry *p, u32 a1, u32 a2, u32 a3, u8 a4)
{
    sub_02063078();
    sub_0204BD3C(p, a1, a2, 0);
    sub_0204BD3C(p + 1, a3, a4, 1);
}

void sub_0204BCD8(GClactCoreEntry *p)
{
    sub_0204BD18(p);
    sub_0204BCF4(p);
    sub_02063078();
}

void sub_0204BCF4(GClactCoreEntry *p)
{
    int i;

    for (i = 0; i < 2; i++)
    {
        sub_0204BD64(&p[i]);
    }
}

void sub_0204BD18(GClactCoreEntry *p)
{
    int i;

    for (i = 0; i < 2; i++)
    {
        sub_0204BD7C(&p[i]);
    }
}

void sub_0204BD3C(GClactCoreEntry *p, u32 a1, u32 a2, u32 a3)
{
    if (a2 == 0)
    {
        p->unk1C = 0;
        return;
    }
    sub_02063138(p, a1, a2, a3);
    p->unk1C = 1;
}

void sub_0204BD64(GClactCoreEntry *p)
{
    if (p->unk1C == 0)
    {
        return;
    }
    sub_0206343C(p);
}

void sub_0204BD7C(GClactCoreEntry *p)
{
    if (p->unk1C == 0)
    {
        return;
    }
    sub_02063640(p);
}

/* ---- VRAM transfer list (GClactCore.xfer, core+0xE0) ----------------- */

void *FUN_02030734(u32 heapId, u32 size, u32 a2, const char *file, int line);
void ENV_SetResourceSet(void *p);
void MI_CpuFill8(void *dst, u8 val, u32 size);
void DC_FlushRange(const void *addr, u32 size);
void FUN_02034714(const char *file, int line, const char *msg);
extern void (*_020A138C[])(void *src, u32 dst, u32 size);
void sub_0204C788(GClactXferList *list);
void sub_0204C8A4(GClactXfer *e, u32 kind, u32 dst, void *src, u32 size);
void sub_0204C8B8(GClactXfer *e);
void sub_0204CB44(GClact *act, GClactRenderer *renderer);
void sub_0204CEB4(GClact *act);
void NNSi_G2dInitializeVRamLocation(GNNSImageProxy *proxy);
void NNS_G2dInitImagePaletteProxy(GNNSImagePaletteProxy *proxy);

void sub_0204C6E4(GClactXferList *list)
{
    if (list->unk0C == 0)
    {
        return;
    }
    ENV_SetResourceSet(list->buffer);
    list->buffer = NULL;
    sub_0204C788(list);
    list->unk0C = 0;
}

void sub_0204C718(GClactXferList *list, u32 count, u32 heapId)
{
    u32 i;

    list->entries = FUN_02030734(heapId, count * sizeof(GClactXfer), 0, "clact.c", 4987);
    for (i = 0; i < list->count; i++)
    {
        MI_CpuFill8(&list->entries[i], 0, sizeof(GClactXfer));
    }
}

void sub_0204C788(GClactXferList *list)
{
    ENV_SetResourceSet(list->entries);
    list->entries = NULL;
}

void sub_0204C7A4(GClactXferList *list)
{
    u32 i;

    for (i = 0; i < list->count; i++)
    {
        if (list->entries[i].src != NULL)
        {
            sub_0204C8B8(&list->entries[i]);
            MI_CpuFill8(&list->entries[i], 0, sizeof(GClactXfer));
        }
    }
}

GClactXfer *sub_0204C804(GClactXferList *list)
{
    u32 i;

    for (i = 0; i < list->count; i++)
    {
        if (list->entries[i].src == NULL)
        {
            return &list->entries[i];
        }
    }
    return NULL;
}

void sub_0204C8A4(GClactXfer *e, u32 kind, u32 dst, void *src, u32 size)
{
    e->kind = kind;
    e->src = src;
    e->dst = dst;
    e->size = size;
}

void sub_0204C8B8(GClactXfer *e)
{
    DC_FlushRange(e->src, e->size);
    _020A138C[e->kind](e->src, e->dst, e->size);
}

GClact *sub_0204C8E4(GClactSet *set)
{
    int i;

    for (i = 0; i < set->count; i++)
    {
        if (set->actors[i].next == NULL)
        {
            return &set->actors[i];
        }
    }
    FUN_02034714("clact.c", 5204, "0");
    return NULL;
}

/* ---- draw list ------------------------------------------------------- */

void sub_0204C944(GClactSet *set)
{
    GClact *act;

    if (set->unk0E_4 == 0)
    {
        return;
    }
    act = set->drawList;
    if (act == NULL)
    {
        return;
    }
    do
    {
        sub_0204CB44(act, set->renderer);
        sub_0204CEB4(act);
        act = act->next;
    } while (act != set->drawList);
}

void sub_0204CA30(GClactSet *set, GClact *act)
{
    if (set->drawList == act)
    {
        if (act->next == act)
        {
            set->drawList = NULL;
        }
        else
        {
            set->drawList = act->next;
        }
    }
    act->next->prev = act->prev;
    act->prev->next = act->next;
    act->next = NULL;
    act->prev = NULL;
}

GClact *sub_0204CA74(GClact *head, u8 pri)
{
    GClact *p = head;

    do
    {
        if (sub_0204B838(p) > pri)
        {
            return p->prev;
        }
        p = p->next;
    } while (p != head);
    return head->prev;
}

GClact *sub_0204CAAC(GClact *tail, u8 pri)
{
    GClact *p = tail;

    do
    {
        if (sub_0204B838(p) <= pri)
        {
            return p;
        }
        p = p->prev;
    } while (p != tail);
    return tail->next;
}

void sub_0204CAE4(GClact *act)
{
    MI_CpuFill8(act, 0, sizeof(GClact));
    act->animSpeed = 0x1000;
    NNSi_G2dInitializeVRamLocation(&act->imageProxy);
    NNS_G2dInitImagePaletteProxy(&act->palProxy);
    act->scale.x = 0x1000;
    act->scale.y = 0x1000;
    act->unk60_08 |= 1;
    act->unk60_1F = 0;
    act->unk60_12 = 0;
}

/* ---- construction / destruction -------------------------------------- */

void sub_0204B0C8(GClactRenderer *renderer, u32 a1, GClactVec2 *out);
void sub_0204D0C4(struct GClactAnim *anim, const struct GClactResHeader *hdr, u16 a2);
GClact *sub_0204C8E4(GClactSet *set);

GClactSet *sub_0204B100(int count, u8 pri, u32 heapId)
{
    GClactSet *set;
    int i;

    set = FUN_02030734(heapId, sizeof(GClactSet), 0, "clact.c", 1771);
    MI_CpuFill8(set, 0, sizeof(GClactSet));
    set->actors = FUN_02030734(heapId, count * sizeof(GClact), 0, "clact.c", 1775);
    set->count = count;
    set->unk0F = pri;
    for (i = 0; i < count; i++)
    {
        sub_0204CAE4(&set->actors[i]);
    }
    sub_0204B270(set);
    sub_0204B22C(set, 1);
    sub_0204BBC8(set);
    return set;
}

void sub_0204B1CC(GClactSet *set)
{
    int i;

    sub_0204BC40(set);
    for (i = 0; i < set->count; i++)
    {
        if (set->actors[i].next != NULL)
        {
            sub_0204B3B4(&set->actors[i]);
        }
    }
    ENV_SetResourceSet(set->actors);
    ENV_SetResourceSet(set);
}

void sub_0204C98C(GClactSet *set, GClact *act)
{
    u8 pri;
    u8 headPri;
    GClact *p;

    if (set->drawList == NULL)
    {
        set->drawList = act;
        set->drawList->next = act;
        set->drawList->prev = act;
        return;
    }
    pri = sub_0204B838(act);
    headPri = sub_0204B838(set->drawList);
    if (pri < headPri)
    {
        p = set->drawList->prev;
        set->drawList = act;
    }
    else if ((u8)((headPri + sub_0204B838(set->drawList->prev)) / 2) >= pri)
    {
        p = sub_0204CA74(set->drawList, pri);
    }
    else
    {
        p = sub_0204CAAC(set->drawList->prev, pri);
    }
    act->prev = p;
    act->next = p->next;
    p->next->prev = act;
    p->next = act;
}

void sub_0204CEB4(GClact *act)
{
    if (act->unk60_19 == 1)
    {
        sub_0204B8D4(act, act->animSpeed);
    }
}

void sub_0204CED8(GClact *act, const GClactInit *init, u32 a2)
{
    sub_0204B49C(act, init->x, a2, 0);
    sub_0204B49C(act, init->y, a2, 1);
    act->unk60_00 = init->priority;
    sub_0204B84C(act, init->unk07);
    sub_0204B878(act, init->animSeq);
    sub_0204B95C(act);
}

void sub_0204CF40(GClact *act, const GClactResHeader *hdr)
{
    sub_0204B784(act, hdr->imageProxy);
    sub_0204B728(act, hdr->palProxy);
    act->unk5C = hdr->unk00;
    act->unk5E = hdr->unk02;
}

void sub_0204CF74(GClact *act, u32 a1, GClactVec2 *out)
{
    if (a1 == 0xFFFF)
    {
        out->x = 0;
        out->y = 0;
        return;
    }
    sub_0204B0C8(((GClactSet *)act->list)->renderer, a1, out);
}

void sub_0204CFA4(GClactTemplate *t, u16 x, u16 y, u32 a3, u32 a4, u32 a5, u32 a6)
{
    t->x = x;
    t->y = y;
    t->unk04 = a3;
    t->unk08 = a4;
    t->unk0C = a5;
    t->unk10 = a6;
    t->unk14 = 0;
    t->unk18 = 0;
    t->unk1C = 0;
}

GClact *sub_0204CFDC(GClactSet *set, const GClactInit *init, const GClactResHeader *hdr, u32 a3, u16 a4)
{
    GClact *act;

    act = sub_0204C8E4(set);
    act->list = set;
    sub_0204D0C4(&act->anim, hdr, a4);
    sub_0204CED8(act, init, a3);
    sub_0204CF40(act, hdr);
    sub_0204C98C(set, act);
    sub_0204B3DC(act, 1);
    return act;
}

/* ---- renderer camera origin ------------------------------------------ */

void sub_0204BE28(GClactSet *set);
void sub_0204BE38(void);
u32 sub_0204D134(const GClactResHeader *hdr);
extern void (*_020A13D0[])(GClactAnim *anim);
extern void (*_020A13DC[])(GClactAnim *anim, const GClactResHeader *hdr, u16 a2);

void sub_0204B084(GClactSet *set)
{
    sub_0204BE28(set);
    ENV_SetResourceSet(set);
}

void sub_0204B09C(GClactRenderer *r, u32 i, const GClactVec2 *pos)
{
    GClactCamera *cam;
    s32 x;
    s32 y;

    x = pos->x;
    y = pos->y;
    cam = &r->cameras[i];
    cam->x = x << 12;
    cam->y = y << 12;
}

void sub_0204B0C8(GClactRenderer *r, u32 i, GClactVec2 *out)
{
    GClactCamera *cam = &r->cameras[i];

    out->x = (s32)cam->x >> 12;
    out->y = (s32)cam->y >> 12;
}

void sub_0204B0F4(void)
{
    sub_0204BE38();
}

/* ---- animation object ------------------------------------------------ */

GClact *sub_0204D048(GClactSet *set, const GClactInit *init, const GClactResHeader *hdr, u32 a3, u16 a4)
{
    GClact *act;

    act = sub_0204CFDC(set, init, hdr, a3, a4);
    sub_0204B59C(act, init->unk08, 0);
    sub_0204B59C(act, init->unk08, 1);
    sub_0204B5D4(act, init->unk0C, 0);
    sub_0204B5D4(act, init->unk10, 1);
    sub_0204B5F4(act, init->unk14);
    sub_0204B570(act, init->unk16);
    return act;
}

void sub_0204D0C4(GClactAnim *anim, const GClactResHeader *hdr, u16 a2)
{
    anim->type = sub_0204D134(hdr);
    _020A13DC[anim->type](anim, hdr, a2);
}

void sub_0204D104(GClactAnim *anim)
{
    _020A13D0[anim->type](anim);
    MI_CpuFill8(anim, 0, sizeof(GClactAnim));
}
