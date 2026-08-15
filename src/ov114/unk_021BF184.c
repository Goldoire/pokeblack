#include "types.h"

/*
 * ov114 handle accessors + teardown (0x021BF184..0x021BF5D8).
 *
 * sub_021BEC00 in "mode 0" validates that a handle is still registered and
 * hands the same pointer back, so every entry point here is
 * validate-then-act.  sub_021BEBC8 turns a validated handle into its session
 * record.
 */

typedef struct Ctx Ctx;
typedef struct Mgr Mgr;

typedef struct Sess {
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
} Sess;

typedef struct Conn {
    s32 unk_00;
    s32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    void *unk_10;
    void *unk_14;
    s32 unk_18;
    u8 pad_1C[0x8048 - 0x1C];
    s32 counter;                                /* 0x8048 */
} Conn;

extern int _021D3B20;
extern u8 _021CE544[];

extern Ctx *sub_021BEF08(void);
extern void *sub_021BEF50(Ctx *ctx);
extern Mgr *sub_021BEF58(Ctx *ctx);
extern Conn *sub_021BEC00(Mgr *m, void *key);
extern Sess *sub_021BEBC8(Mgr *m, void *key);
extern int sub_021BEBA8(Mgr *m, void *key);
extern void sub_021BEA64(Conn *c);
extern s32 sub_021BF018(Mgr *m, Conn *c);
extern s32 sub_021BEFE4(Mgr *m, Conn *c);
extern void sub_021BA850(Conn *c);
extern void sub_021B9C1C(void *p, int n);
extern void sub_021BB8B4(Ctx *ctx);
extern s32 sub_021BB97C(Ctx *ctx, void *sock);
extern void sub_021BBA14(Ctx *ctx, s32 fd);
extern void sub_021BBB28(Mgr *m, void *p);
extern int sub_021C1FF8(void *p);
extern int sub_021C204C(void);
extern int sub_021C2270(void);
extern int sub_021C2344(void *p, void *list);
extern int sub_021C2350(void *p);
extern int sub_02059F38(void);
extern void sub_021BFB20(void);

int sub_021BF1B0(Conn *c);
int sub_021BF288(Conn *c);
int sub_021BF3BC(Conn *c);
int sub_021BF488(Conn *c);

int sub_021BF184(Conn *c)
{
    Conn *e = sub_021BEC00(sub_021BEF58(sub_021BEF08()), c);

    if (e == NULL) {
        return -1;
    }
    return sub_021BF1B0(e);
}

int sub_021BF1B0(Conn *c)
{
    Ctx *ctx = sub_021BEF08();
    Mgr *mgr = sub_021BEF58(ctx);

    sub_021BEF50(ctx);
    if (c == NULL) {
        return -1;
    }
    if (c->counter > 0 && c->unk_18 >= 0) {
        sub_021BBA14(ctx, c->unk_18);
        c->unk_18 = -1;
    }
    if (sub_021BF018(mgr, c) > 0) {
        return 0;
    }
    if (c->unk_10 != NULL && *(s32 *)((u8 *)c->unk_10 + 4) == 0) {
        sub_021BB8B4(ctx);
    }
    if (c->unk_14 != NULL) {
        if (c->unk_10 != NULL) {
            sub_021BF288(c);
        }
        sub_021BBB28(mgr, c->unk_14);
    }
    sub_021BEBA8(mgr, c);
    sub_021BA850(c);
    return 0;
}

int sub_021BF288(Conn *c)
{
    Ctx *ctx = sub_021BEF08();
    void *p = sub_021BEF50(ctx);
    Mgr *mgr = sub_021BEF58(ctx);
    Conn *e = sub_021BEC00(mgr, c);
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

int sub_021BF308(Conn *c)
{
    Ctx *ctx = sub_021BEF08();
    Mgr *mgr = sub_021BEF58(ctx);
    Conn *e = sub_021BEC00(mgr, c);
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

int sub_021BF374(Conn *c)
{
    Ctx *ctx = sub_021BEF08();
    Conn *e = sub_021BEC00(sub_021BEF58(ctx), c);
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

int sub_021BF3BC(Conn *c)
{
    Conn *e = sub_021BEC00(sub_021BEF58(sub_021BEF08()), c);

    if (e == NULL) {
        return -1;
    }
    return e->unk_00;
}

int sub_021BF3E4(Conn *c, u32 *o1, u32 *o2)
{
    Ctx *ctx = sub_021BEF08();
    Mgr *mgr = sub_021BEF58(ctx);
    Conn *e = sub_021BEC00(mgr, c);
    Sess *s;

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

int sub_021BF444(Conn *c)
{
    Ctx *ctx = sub_021BEF08();
    Mgr *mgr = sub_021BEF58(ctx);
    Conn *e = sub_021BEC00(mgr, c);
    Sess *s;

    if (e != NULL) {
        s = sub_021BEBC8(mgr, e);
        if (s != NULL) {
            return s->unk_438;
        }
        return 0;
    }
    return 0;
}

int sub_021BF488(Conn *c)
{
    Conn *e = sub_021BEC00(sub_021BEF58(sub_021BEF08()), c);

    if (e != NULL) {
        return e->unk_04;
    }
    return -1;
}

int sub_021BF4B0(Conn *c, u32 *o1, u32 *o2)
{
    Ctx *ctx = sub_021BEF08();
    Mgr *mgr = sub_021BEF58(ctx);
    Conn *e = sub_021BEC00(mgr, c);
    Sess *s;

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
