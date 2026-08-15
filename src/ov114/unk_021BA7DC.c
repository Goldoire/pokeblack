#include "types.h"

/*
 * ov114 allocator hooks (0x021BA7DC..0x021BAC58).
 *
 * The first sub-object of the library context (returned by sub_021BEF3C, i.e.
 * ctx+0) is the allocator record: alloc callback at +0x00, free callback at
 * +0x04.  sub_021BA820/sub_021BA850 are the malloc/free the rest of the
 * overlay calls.
 */

typedef void *(*AllocFn)(u32 size, u32 align);
typedef void (*FreeFn)(void *p);

typedef struct Ov114Alloc {
    AllocFn alloc;                              /* 0x00 */
    FreeFn free;                                /* 0x04 */
    u32 unk_08;
    s32 unk_0C;
    void *unk_10;
    void *unk_14;
    u32 unk_18;
    u32 unk_1C;
    u32 unk_20;
} Ov114Alloc;

typedef struct Ov114Sock {
    u32 unk_00;
    u32 unk_04;
    u8 pad_08[0x30 - 0x08];
    u8 unk_30[4];                               /* 0x30 */
} Ov114Sock;

extern Ov114Alloc *sub_021BEF08(void);
extern BOOL sub_021BAA1C(void *p, void *a, void *b, void *c);

void sub_021BA874(Ov114Alloc *a, void *v);
void sub_021BA87C(Ov114Alloc *a, void *v);

void sub_021BA7DC(Ov114Alloc *a)
{
    a->alloc = NULL;
    a->free = NULL;
    a->unk_08 = 0;
    a->unk_0C = -1;
    sub_021BA87C(a, NULL);
    sub_021BA874(a, NULL);
    a->unk_18 = 0;
    a->unk_1C = 0;
    a->unk_20 = 0;
}

void *sub_021BA820(u32 size, u32 align)
{
    Ov114Alloc *a = sub_021BEF08();
    AllocFn fn = a->alloc;

    if (fn == NULL) {
        return NULL;
    }
    return fn(size, align);
}

void sub_021BA850(void *p)
{
    Ov114Alloc *a = sub_021BEF08();
    FreeFn fn = a->free;

    if (fn == NULL) {
        return;
    }
    fn(p);
}

void sub_021BA874(Ov114Alloc *a, void *v)
{
    a->unk_14 = v;
}

void sub_021BA87C(Ov114Alloc *a, void *v)
{
    a->unk_10 = v;
}

void *sub_021BA884(Ov114Alloc *a)
{
    return a->unk_10;
}

BOOL sub_021BAC38(Ov114Sock *s, void *a, void *b, void *c)
{
    if (s->unk_04 != 0) {
        return 0;
    }
    return sub_021BAA1C(s->unk_30, a, b, c);
}
