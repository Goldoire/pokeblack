#include "types.h"

/*
 * ov114 handle accessors + teardown (0x021BF184..0x021BF5D8).
 *
 * sub_021BEC00 in "mode 0" validates that a handle is still registered and
 * hands the same pointer back, so every entry point here is
 * validate-then-act.  sub_021BEBC8 turns a validated handle into its session
 * record.
 */

typedef struct Ov114Ctx Ov114Ctx;
typedef struct Ov114Mgr Ov114Mgr;

typedef struct Ov114Sess {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    volatile s32 unk_0C;
    u8 pad_10[0x1C - 0x10];
    u32 unk_1C;
    u8 pad_20[0x28 - 0x20];
    u32 unk_28;
    u8 pad_2C[0x438 - 0x2C];
    int unk_438;
} Ov114Sess;

typedef struct Ov114Buffer {
    s32 unk_00;
    s32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    void *unk_10;
    void *unk_14;
    s32 unk_18;
    u8 pad_1C[0x8048 - 0x1C];
    s32 counter;                                /* 0x8048 */
} Ov114Buffer;

extern int _021D3B20;
extern u8 _021CE544[];

extern Ov114Ctx *sub_021BEF08(void);
extern void *sub_021BEF50(Ov114Ctx *ctx);
extern Ov114Mgr *sub_021BEF58(Ov114Ctx *ctx);
extern Ov114Buffer *sub_021BEC00(Ov114Mgr *m, void *key);
extern Ov114Sess *sub_021BEBC8(Ov114Mgr *m, void *key);
extern int sub_021BEBA8(Ov114Mgr *m, void *key);
extern void sub_021BEA64(Ov114Buffer *c);
extern s32 sub_021BEFE4(Ov114Mgr *m, Ov114Buffer *c);
extern void sub_021B9C1C(void *p, int n);
extern s32 sub_021BB97C(Ov114Ctx *ctx, void *sock);
extern void sub_021BBA14(Ov114Ctx *ctx, s32 fd);
extern int sub_021C1FF8(void *p);
extern int sub_021C204C(void);
extern int sub_021C2270(void);
extern int sub_021C2344(void *p, void *list);
extern int sub_021C2350(void *p);
extern int sub_02059F38(void);
extern void sub_021BFB20(void);

extern int sub_021BF1B0(Ov114Buffer *c);   /* banked: build/attempts/ov114/sub_021BF1B0.c */
int sub_021BF288(Ov114Buffer *c);
int sub_021BF3BC(Ov114Buffer *c);
int sub_021BF488(Ov114Buffer *c);

int sub_021BF184(Ov114Buffer *c)
{
    Ov114Buffer *e = sub_021BEC00(sub_021BEF58(sub_021BEF08()), c);

    if (e == NULL) {
        return -1;
    }
    return sub_021BF1B0(e);
}

int sub_021BF288(Ov114Buffer *c)
{
    Ov114Ctx *ctx = sub_021BEF08();
    void *p = sub_021BEF50(ctx);
    Ov114Mgr *mgr = sub_021BEF58(ctx);
    Ov114Buffer *e = sub_021BEC00(mgr, c);
    int st;

    if (e == NULL) {
        return -1;
    }
    st = sub_021BF3BC(c);
    sub_021B9C1C(p, 1);
    if (st != -1 && st != 0) {
        if (sub_021BF488(c) == 0xF) {
            sub_021BEA64(e);
        }
    }
    return 0;
}

int sub_021BF308(Ov114Buffer *c)
{
    Ov114Ctx *ctx = sub_021BEF08();
    Ov114Mgr *mgr = sub_021BEF58(ctx);
    Ov114Buffer *e = sub_021BEC00(mgr, c);
    void *sock;
    s32 fd;

    if (e == NULL) {
        return -1;
    }
    sock = e->unk_10;
    if (sock == NULL) {
        return -1;
    }
    fd = sub_021BB97C(ctx, sock);
    e->unk_18 = fd;
    if (fd >= 0) {
        e->unk_00 = 1;
        sub_021BEFE4(mgr, e);
    }
    return 0;
}

int sub_021BF374(Ov114Buffer *c)
{
    Ov114Ctx *ctx = sub_021BEF08();
    Ov114Buffer *e = sub_021BEC00(sub_021BEF58(ctx), c);
    s32 v;

    if (e == NULL) {
        return -1;
    }
    v = e->unk_18;
    if (v < 0) {
        return -1;
    }
    sub_021BBA14(ctx, v);
    return 0;
}

int sub_021BF3BC(Ov114Buffer *c)
{
    Ov114Buffer *e = sub_021BEC00(sub_021BEF58(sub_021BEF08()), c);

    if (e == NULL) {
        return -1;
    }
    return e->unk_00;
}

int sub_021BF3E4(Ov114Buffer *c, u32 *o1, u32 *o2)
{
    Ov114Ctx *ctx = sub_021BEF08();
    Ov114Mgr *mgr = sub_021BEF58(ctx);
    Ov114Buffer *e = sub_021BEC00(mgr, c);
    Ov114Sess *s;

    if (e != NULL) {
        s = sub_021BEBC8(mgr, e);
        if (s == NULL) {
            return -1;
        }
        *o1 = s->unk_28;
        *o2 = s->unk_1C;
        return s->unk_04;
    }
    return -1;
}

int sub_021BF444(Ov114Buffer *c)
{
    Ov114Ctx *ctx = sub_021BEF08();
    Ov114Mgr *mgr = sub_021BEF58(ctx);
    Ov114Buffer *e = sub_021BEC00(mgr, c);
    Ov114Sess *s;

    if (e != NULL) {
        s = sub_021BEBC8(mgr, e);
        if (s != NULL) {
            return s->unk_438;
        }
        return 0;
    }
    return 0;
}

int sub_021BF488(Ov114Buffer *c)
{
    Ov114Buffer *e = sub_021BEC00(sub_021BEF58(sub_021BEF08()), c);

    if (e != NULL) {
        return e->unk_04;
    }
    return -1;
}

int sub_021BF4B0(Ov114Buffer *c, u32 *o1, u32 *o2)
{
    Ov114Ctx *ctx = sub_021BEF08();
    Ov114Mgr *mgr = sub_021BEF58(ctx);
    Ov114Buffer *e = sub_021BEC00(mgr, c);
    Ov114Sess *s;

    if (e != NULL) {
        s = sub_021BEBC8(mgr, e);
        if (s != NULL) {
            *o1 = s->unk_08;
            if (s->unk_0C == -1) {
                *o2 = 0;
            } else {
                *o2 = s->unk_0C;
            }
            return 0;
        }
        return -1;
    }
    return -1;
}

BOOL sub_021BF520(void *p)
{
    return sub_021C2344(p, _021CE544) == 1;
}

BOOL sub_021BF540(void *p)
{
    return sub_021C2350(p) == 1;
}

BOOL sub_021BF558(void *p)
{
    sub_021C1FF8(p);
    _021D3B20++;
    return TRUE;
}

BOOL sub_021BF57C(void)
{
    if (_021D3B20 <= 0) {
        return TRUE;
    }
    sub_021C204C();
    if (--_021D3B20 == 0) {
        sub_021BFB20();
    }
    return TRUE;
}

BOOL sub_021BF5B8(void)
{
    if (sub_02059F38() != 0) {
        return FALSE;
    }
    sub_021C2270();
    return TRUE;
}
