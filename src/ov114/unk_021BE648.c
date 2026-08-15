#include "types.h"

/*
 * ov114 public socket/HTTP API layer (0x021BE648..).
 *
 * Every entry point grabs the library singleton with sub_021BEF08(), pulls a
 * sub-object out of it with one of the tiny +offset accessors, and forwards to
 * the worker in the 0x021BA000 block.  Local struct until the integrator has a
 * shared one.
 */

typedef struct Ctx Ctx;

typedef struct Sock {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u32 unk_10;
    u32 unk_14;
    u32 unk_18;
    u8 pad_1C[0x34 - 0x1C];
    u32 unk_34;
    u8 pad_38[0xD0 - 0x38];
    u32 unk_D0;
    u8 pad_D4[0x24C - 0xD4];
    u32 unk_24C;
    u32 unk_250;
} Sock;

extern Ctx *sub_021BEF08(void);
extern void *sub_021BEF3C(Ctx *ctx);
extern void *sub_021BEF58(Ctx *ctx);
extern Sock *sub_021BEC10(void *list, int id);
extern Sock *sub_021BEC2C(void *list, int id);
extern BOOL sub_021BA88C(Ctx *ctx, int a, int b, int c);
extern void sub_021BA988(Ctx *ctx, void *cb);
extern void sub_021BAA14(Ctx *ctx);
extern BOOL sub_021BAC38(Sock *s, void *f, int b, int c);
extern BOOL sub_021BAC58(Sock *s, void *f, int b, int c);
extern int sub_021BBCF0(Sock *s, int b, int c);
extern int sub_021BBDFC(void *f, Sock *s, int b);

int sub_021BE648(int a, int b, int c)
{
    return sub_021BA88C(sub_021BEF08(), a, b, c) ? 0 : -1;
}

void sub_021BE680(void *cb)
{
    sub_021BA988(sub_021BEF08(), cb);
}

void sub_021BE698(void)
{
    sub_021BA988(sub_021BEF08(), NULL);
}

void sub_021BE6AC(void)
{
    sub_021BAA14(sub_021BEF08());
}

int sub_021BE6EC(Sock *s, int b, int c)
{
    void *f = sub_021BEF3C(sub_021BEF08());

    if (s == NULL) {
        return -1;
    }
    if (s->unk_04 != 0) {
        return -1;
    }
    return sub_021BAC38(s, f, b, c) ? 0 : -1;
}

int sub_021BE6BC(int id, int b, int c)
{
    Ctx *ctx = sub_021BEF08();
    Sock *s = sub_021BEC10(sub_021BEF58(ctx), id);

    return sub_021BE6EC(s, b, c);
}

int sub_021BE748(int id, int b, int c)
{
    Ctx *ctx = sub_021BEF08();
    void *f = sub_021BEF3C(ctx);
    Sock *s = sub_021BEC10(sub_021BEF58(ctx), id);

    return sub_021BAC58(s, f, b, c) ? 0 : -1;
}

int sub_021BE79C(int id, int b, int c)
{
    Ctx *ctx = sub_021BEF08();
    Sock *s = sub_021BEC10(sub_021BEF58(ctx), id);

    if (s == NULL) {
        return -1;
    }
    if (s->unk_04 != 0) {
        return -1;
    }
    if (s->unk_34 != 0) {
        return -1;
    }
    s->unk_10 = 1;
    s->unk_24C = b;
    s->unk_250 = c;
    return 0;
}

int sub_021BE7FC(int id, int b, int c)
{
    Ctx *ctx = sub_021BEF08();
    Sock *s = sub_021BEC2C(sub_021BEF58(ctx), id);

    if (s == NULL) {
        return -1;
    }
    return sub_021BBCF0(s, b, c);
}

int sub_021BE838(int id, int b)
{
    Ctx *ctx = sub_021BEF08();
    void *f = sub_021BEF3C(ctx);
    Sock *s = sub_021BEC2C(sub_021BEF58(ctx), id);

    if (s == NULL) {
        return -1;
    }
    return sub_021BBDFC(f, s, b);
}

int sub_021BE880(int id)
{
    Ctx *ctx = sub_021BEF08();
    Sock *s = sub_021BEC2C(sub_021BEF58(ctx), id);

    if (s == NULL) {
        return -1;
    }
    if (s->unk_14 != 0) {
        return s->unk_18;
    }
    return -1;
}

int sub_021BE8B8(int id, int v)
{
    Ctx *ctx = sub_021BEF08();
    Sock *s = sub_021BEC10(sub_021BEF58(ctx), id);

    if (s == NULL) {
        return -1;
    }
    s->unk_D0 = v;
    return 0;
}
