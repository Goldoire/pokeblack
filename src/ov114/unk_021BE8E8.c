#include "types.h"

/*
 * ov114 connection-table layer (0x021BE8E8..).
 *
 * A singleton manager at 0x021CF984 owns a singly linked list of entries
 * (next at +0x20) plus a mutex/thread-queue pair; sub_021BEAB8 is the generic
 * lookup and the three thunks below select its search mode.
 */

typedef struct Ov114Sock Ov114Sock;

typedef struct Ov114Lock {
    u32 inited;             /* 0x00 */
    u8 mutex[0x18];         /* 0x04  OSMutex */
    u32 queueHead;          /* 0x1C  OSThreadQueue */
    u32 queueTail;          /* 0x20 */
} Ov114Lock;

typedef struct Ov114Entry {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    Ov114Sock *unk_10;
    Ov114Sock *unk_14;
    u32 unk_18;
    u32 unk_1C;
    struct Ov114Entry *next;     /* 0x20 */
} Ov114Entry;

typedef struct Ov114Mgr {
    Ov114Entry *head;            /* 0x00 */
    void *ctx;              /* 0x04 */
    Ov114Lock lock;              /* 0x08 */
} Ov114Mgr;

struct Ov114Sock {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u8 pad_1C[0x4C - 0x1C];
    u8 unk_4C[0xA8 - 0x4C];
    u32 unk_A8;
    u8 pad_AC[0xC0 - 0xAC];
    u32 unk_C0;
    u32 unk_C4;
    u32 unk_C8;
    u8 pad_CC[0xDC - 0xCC];
    u32 unk_DC;
};

extern Ov114Mgr _021CF984;
extern const char _021CE53C[];

extern Ov114Mgr *sub_021BEF08(void);
extern Ov114Mgr *sub_021BEF58(Ov114Mgr *ctx);
extern void sub_021B9B4C(void *mutex);            /* OS_InitMutex */
extern void sub_020857B0(void *q);                /* OS_SleepThread */
extern void sub_02085800(void *q);                /* OS_WakeupThread */
extern void sub_021BA100(void *dst, const void *src, u32 n);
extern int sub_021BA124(const char *s, int max);
extern void sub_021BA13C(void *p, u32 n);
extern int sub_021BA714(void *p, const char *s);
extern Ov114Entry *sub_021BEAB8(Ov114Mgr *m, void *key, int mode);
Ov114Sock *sub_021BEC10(Ov114Mgr *m, void *key);

int sub_021BE8E8(int id, const char *a, const char *b)
{
    char buf[0x44];
    Ov114Sock *s;
    int la;
    int lb;
    int max;

    s = (Ov114Sock *)sub_021BEC10(sub_021BEF58(sub_021BEF08()), id);
    if (s == NULL || a == NULL || b == NULL) {
        return -1;
    }
    max = 0x21;
    la = sub_021BA124(a, max);
    lb = sub_021BA124(b, max);
    if (la <= 0x20 && lb <= 0x20) {
        sub_021BA13C(buf, 0x41);
        sub_021BA100(buf, a, la);
        sub_021BA100(&buf[la], _021CE53C, 1);
        sub_021BA100(&buf[la + 1], b, lb);
        s->unk_A8 = sub_021BA714(s->unk_4C, buf);
    } else {
        return -1;
    }
    return 0;
}

int sub_021BE9F8(Ov114Sock *s, u32 a, u32 b)
{
    if (s == NULL) {
        return -1;
    }
    s->unk_C8 = 0;
    s->unk_DC = 0;
    s->unk_C0 = a;
    s->unk_C4 = b;
    return 0;
}

int sub_021BE9C8(int id, u32 a, u32 b)
{
    Ov114Mgr *ctx = sub_021BEF08();
    Ov114Sock *s = (Ov114Sock *)sub_021BEC10(sub_021BEF58(ctx), id);

    return sub_021BE9F8(s, a, b);
}

Ov114Lock *sub_021BEA20(void)
{
    Ov114Lock *p = &_021CF984.lock;

    if (_021CF984.lock.inited == 0) {
        sub_021B9B4C(p->mutex);
        p->queueTail = 0;
        p->queueHead = 0;
        p->inited = 1;
    }
    return p;
}

void sub_021BEA64(Ov114Sock *s)
{
    Ov114Lock *p = sub_021BEA20();

    while (s->unk_0C != 0) {
        sub_020857B0(&p->queueHead);
    }
}

void sub_021BEA98(Ov114Sock *s)
{
    Ov114Lock *p = sub_021BEA20();

    s->unk_0C = 0;
    sub_02085800(&p->queueHead);
}

int sub_021BEB88(Ov114Mgr *m, void *key)
{
    return sub_021BEAB8(m, key, 3) ? 0 : -1;
}

int sub_021BEBA8(Ov114Mgr *m, void *key)
{
    return sub_021BEAB8(m, key, 4) ? 0 : -1;
}

Ov114Entry *sub_021BEBE0(Ov114Mgr *m, void *key)
{
    return sub_021BEAB8(m, key, 1);
}

Ov114Entry *sub_021BEBF0(Ov114Mgr *m, void *key)
{
    return sub_021BEAB8(m, key, 2);
}

Ov114Entry *sub_021BEC00(Ov114Mgr *m, void *key)
{
    return sub_021BEAB8(m, key, 0);
}

Ov114Sock *sub_021BEBC8(Ov114Mgr *m, void *key)
{
    Ov114Entry *e = sub_021BEC00(m, key);

    if (e != NULL) {
        return e->unk_14;
    }
    return NULL;
}

Ov114Sock *sub_021BEC10(Ov114Mgr *m, void *key)
{
    Ov114Entry *e = sub_021BEC00(m, key);

    if (e != NULL) {
        return e->unk_10;
    }
    return (Ov114Sock *)key;
}

Ov114Sock *sub_021BEC2C(Ov114Mgr *m, void *key)
{
    Ov114Entry *e = sub_021BEC00(m, key);

    if (e != NULL) {
        return e->unk_14;
    }
    return (Ov114Sock *)key;
}

int sub_021BEC48(void)
{
    int n = 0;
    Ov114Entry *e = _021CF984.head;

    while (e != NULL) {
        e = e->next;
        n++;
    }
    return n;
}
