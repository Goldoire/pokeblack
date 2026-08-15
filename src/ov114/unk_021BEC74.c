#include "types.h"

/*
 * ov114 dispatch + library singleton (0x021BEC74..0x021BF04C).
 *
 * sub_021BEF08 lazily constructs the one library context (0x021CF9C0) and
 * caches it in the manager at 0x021CF984; sub_021BEEC4 walks its five
 * sub-objects and inits each.  The 0x021BEC74/0x021BED04/0x021BED90 trio all
 * pump the per-handle callback with a different opcode.
 */

typedef struct Ctx {
    u8 unk_00[0x28];
    u8 unk_28[0x08];
    u8 unk_30[0x04];
    u8 unk_34[0x1C];
    u8 unk_50[0x04];
} Ctx;

typedef struct Lock {
    u32 inited;
    u8 mutex[0x18];
    u32 queueHead;
    u32 queueTail;
} Lock;

typedef struct Entry Entry;
typedef struct Conn Conn;
typedef struct Handle Handle;

struct Handle {
    u8 pad_00[0x1C];
    int (*cb)(Handle *h, int op, u32 *args);    /* 0x1C */
    u32 unk_20;
    u32 unk_24;
    u32 unk_28;
};

struct Entry {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    void *unk_10;
    void *unk_14;
    u32 unk_18;
    u32 unk_1C;
    Entry *next;                                /* 0x20 */
    u32 unk_24;
    u32 unk_28;
    void *unk_2C;
};

struct Conn {
    u32 unk_00;
    u32 unk_04;
    u8 pad_08[0x1C - 0x08];
    u32 unk_1C;
    u8 pad_20[0x28 - 0x20];
    u32 unk_28;
};

typedef struct Mgr {
    Entry *head;                                /* 0x00 */
    Ctx *ctx;                                   /* 0x04 */
    Lock lock;                                  /* 0x08 */
} Mgr;

typedef struct Mutex {
    u8 os[0x18];
    u32 inited;                                 /* 0x18 */
} Mutex;

typedef struct Pool {
    u8 pad_0000[0x8048];
    s32 counter;                                /* 0x8048 */
} Pool;

extern Mgr _021CF984;
extern Ctx _021CF9C0;

extern Entry *sub_021BEC00(Mgr *m, void *key);
extern Conn *sub_021BEBC8(Mgr *m, void *key);
extern int sub_021BEC48(void);
extern void sub_021BA7DC(void *p);
extern void sub_021BACEC(void *p);
extern void sub_021BB3C0(void *p);
extern void sub_021BBE94(void *p);
extern void sub_021B9B4C(void *m);              /* OS_InitMutex */
extern void sub_021B9B58(void *m);              /* OS_LockMutex */
extern void sub_02086078(void *m);              /* OS_UnlockMutex */

int sub_021BEE4C(Mgr *m, Handle *h, u32 b, u32 c);
int sub_021BEE74(Mgr *m, Handle *h, u32 a, u32 b, u32 c);
void sub_021BEEC4(Ctx *c);
void *sub_021BEF3C(Ctx *c);
void *sub_021BEF40(Ctx *c);
void *sub_021BEF48(Ctx *c);
void *sub_021BEF50(Ctx *c);
void *sub_021BEF58(Ctx *c);
void sub_021BEF98(Mutex *m);
void sub_021BEFCC(void *m);
void sub_021BEFD8(void *m);

int sub_021BEC74(Mgr *m, Handle *h, u32 c, u32 d)
{
    int ret = -1;
    u32 args[4];

    if (sub_021BEC00(m, h) != NULL) {
        if (sub_021BEBC8(m, h) != NULL && h->cb != NULL) {
            args[0] = c;
            args[1] = h->unk_24;
            args[2] = h->unk_28;
            args[3] = d;
            ret = h->cb(h, 1, args);
            sub_021BEE4C(m, h, args[1], args[2]);
        }
    }
    return ret;
}

void sub_021BED04(Mgr *m, Handle *h)
{
    u32 args[3];
    Conn *x;

    if (sub_021BEC00(m, h) == NULL) {
        return;
    }
    x = sub_021BEBC8(m, h);
    if (x == NULL || h->cb == NULL) {
        return;
    }
    args[0] = x->unk_28;
    args[1] = x->unk_1C;
    args[2] = x->unk_04;
    h->cb(h, 2, args);
    sub_021BEE74(m, h, args[0], args[1], args[2]);
}

void sub_021BED90(Mgr *m, Handle *h)
{
    u32 args[3];
    Conn *x;

    if (sub_021BEC00(m, h) == NULL) {
        return;
    }
    x = sub_021BEBC8(m, h);
    if (x == NULL || h->cb == NULL) {
        return;
    }
    args[0] = x->unk_28;
    args[1] = x->unk_1C;
    args[2] = x->unk_04;
    h->cb(h, 3, args);
    sub_021BEE74(m, h, args[0], args[1], args[2]);
}

void sub_021BEE1C(Mgr *m, Handle *h)
{
    if (sub_021BEC00(m, h) != NULL && h->cb != NULL) {
        h->cb(h, 4, NULL);
    }
}

int sub_021BEE4C(Mgr *m, Handle *h, u32 b, u32 c)
{
    Entry *e = sub_021BEC00(m, h);

    if (e == NULL) {
        return -1;
    }
    e->unk_24 = b;
    e->unk_28 = c;
    return 0;
}

int sub_021BEE74(Mgr *m, Handle *h, u32 a, u32 b, u32 c)
{
    Entry *e = sub_021BEC00(m, h);
    Conn *x;

    if (e != NULL) {
        x = sub_021BEBC8(m, e);
        if (x == NULL) {
            return -1;
        }
        x->unk_28 = a;
        x->unk_1C = b;
        x->unk_04 = c;
        return 0;
    }
    return -1;
}

void sub_021BEEC4(Ctx *c)
{
    sub_021BA7DC(sub_021BEF3C(c));
    sub_021BACEC(sub_021BEF40(c));
    sub_021BB3C0(sub_021BEF48(c));
    sub_021BEF98(sub_021BEF58(c));
    sub_021BBE94(sub_021BEF50(c));
}

Ctx *sub_021BEF08(void)
{
    Ctx *c = _021CF984.ctx;

    if (c == NULL) {
        c = &_021CF9C0;
        _021CF984.ctx = c;
        sub_021BEEC4(c);
    }
    return c;
}

void *sub_021BEF3C(Ctx *c)
{
    return c->unk_00;
}

void *sub_021BEF40(Ctx *c)
{
    return c->unk_28;
}

void *sub_021BEF48(Ctx *c)
{
    return c->unk_30;
}

void *sub_021BEF50(Ctx *c)
{
    return c->unk_50;
}

void *sub_021BEF58(Ctx *c)
{
    return c->unk_34;
}

void sub_021BEF60(Entry *e, void *v)
{
    if (e != NULL) {
        e->unk_2C = v;
    }
}

void sub_021BEF6C(void)
{
    if (_021CF984.head != NULL) {
        sub_021BEC48();
    }
    _021CF984.head = NULL;
}

void sub_021BEF98(Mutex *m)
{
    m->inited = 0;
}

void sub_021BEFA4(Mutex *m)
{
    if (m->inited == 0) {
        sub_021B9B4C(m);
        m->inited = 1;
    }
}

void sub_021BEFC8(void)
{
}

void sub_021BEFCC(void *m)
{
    sub_021B9B58(m);
}

void sub_021BEFD8(void *m)
{
    sub_02086078(m);
}

s32 sub_021BEFE4(void *lock, Pool *p)
{
    sub_021BEFCC(lock);
    p->counter++;
    sub_021BEFD8(lock);
    return p->counter;
}

s32 sub_021BF018(void *lock, Pool *p)
{
    sub_021BEFCC(lock);
    p->counter--;
    sub_021BEFD8(lock);
    return p->counter;
}
