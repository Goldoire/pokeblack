#include "types.h"

/*
 * ov114 worker-thread plumbing (0x021B9B64..0x021B9D8C).
 *
 * A Ov114Worker is an OSMessageQueue (+0x00) with its 3-slot backing array
 * (+0x20) and the OSThread that services it (+0x2C).  sub_021B9C60 is the
 * thread entry thunk.
 */

typedef struct Ov114Worker {
    u8 queue[0x20];                             /* 0x00  OSMessageQueue */
    void *msgbuf[3];                            /* 0x20 */
    u8 thread[0xB4];                            /* 0x2C  OSThread */
} Ov114Worker;

typedef struct Ov114Obj {
    u8 pad_00[0xAC];
    void *unk_AC;                               /* 0xAC */
} Ov114Obj;

typedef struct Ov114ThreadInfo {
    u32 unk_00;
    void *current;                              /* 0x04 */
} Ov114ThreadInfo;

extern Ov114ThreadInfo _02150FEC;
extern u8 _021CF964[];

extern BOOL sub_02085D94(void *q, void *buf, s32 n);       /* OS_InitMessageQueue */
extern BOOL sub_020853C0(void *t, void *fn, void *arg, void *sp, u32 size, u32 prio);
extern void sub_02085868(void *t);                         /* OS_WakeupThreadDirect */
extern void sub_02085710(void *t);                         /* OS_JoinThread */
extern BOOL sub_02085DBC(void *q, void *msg, s32 block);   /* OS_SendMessage */
extern BOOL sub_02085E50(void *q, void *msg, s32 block);   /* OS_ReceiveMessage */
extern void sub_02085A38(u32 ms);                          /* OS_Sleep */
extern void sub_02088168(void *buf);                       /* OS_GetLowEntropyData */
extern void sub_02088234(void *t);
extern void sub_02162248(void *buf, u32 n);
extern int sub_0215F4DC(int h, void *out, int a, int b);
extern int sub_0215F644(void *h);
extern int sub_0215F428(int a, int b, int c);
extern void sub_0215EBB4(void);
extern void sub_021BA850(void *p);
extern int sub_021BBEB8(Ov114Worker *w);
extern void sub_021BBEA0(Ov114Worker *w);
extern void sub_021BE4D4(void);

void sub_021B9C60(void);
BOOL sub_021B9C08(Ov114Worker *w);

BOOL sub_021B9B64(Ov114Worker *w, u32 prio, void *stack)
{
    if (sub_021BBEB8(w) == 0) {
        sub_02085D94(w->queue, w->msgbuf, 3);
        sub_021BBEA0(w);
    }
    sub_020853C0(w->thread, (void *)sub_021B9C60, NULL,
                 (u8 *)stack + 0x2000, 0x2000, prio);
    sub_02085868(w->thread);
    return TRUE;
}

void sub_021B9BD4(Ov114Worker *w, Ov114Obj *o)
{
    *(u32 *)((u8 *)o + 0x18) = 1;
    sub_021B9C08(w);
    sub_02085710(w->thread);
}

void sub_021B9BF4(Ov114Worker *w)
{
    void *msg;

    sub_02085E50(w, &msg, 1);
}

BOOL sub_021B9C08(Ov114Worker *w)
{
    return sub_02085DBC(w, NULL, 0);
}

void sub_021B9C1C(Ov114Worker *w, int flag)
{
    void *th = w->thread;
    void *cur = _02150FEC.current;

    if (cur == NULL) {
        return;
    }
    if ((flag == 0 && cur != th) || (flag != 0 && cur == th)) {
        sub_02088234(th);
    }
}

void sub_021B9C60(void)
{
    sub_021BE4D4();
}

u32 sub_021B9C6C(u32 x)
{
    if (x & 0x8000) {
        x &= ~0x8000;
    }
    return x;
}

int sub_021B9C78(void)
{
    return 0;
}

void sub_021B9C80(void)
{
    sub_02088168(_021CF964);
    sub_02162248(_021CF964, 0x20);
}

int sub_021B9CA4(int h)
{
    int v;
    int ret = 0;

    if (h == -1) {
        ret = -1;
    } else if (sub_0215F4DC(h, &v, 1, 4) != -6) {
        ret = -1;
    }
    return ret;
}

int sub_021B9CE4(void)
{
    return sub_0215F428(2, 1, 0);
}

int sub_021B9CFC(int unused, Ov114Obj *o, void *h)
{
    int rc = sub_0215F644(h);
    int elapsed;

    if (rc == 0 || rc == -0x1A) {
        elapsed = 0;
        while ((rc = sub_0215F644(h)) == -0x1A && elapsed <= 10000) {
            sub_02085A38(500);
            sub_0215EBB4();
            elapsed += 500;
        }
    }
    if (rc != -0x1A && o != NULL && o->unk_AC != NULL) {
        sub_021BA850(o->unk_AC);
        o->unk_AC = NULL;
    }
    return rc;
}
