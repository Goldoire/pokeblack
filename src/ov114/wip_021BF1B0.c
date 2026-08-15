#include "types.h"

typedef struct Ov114Ctx Ov114Ctx;
typedef struct Ov114Mgr Ov114Mgr;

typedef struct Ov114Buffer {
    s32 unk_00;
    s32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    void *unk_10;
    void *unk_14;
    s32 unk_18;
    u8 pad_1C[0x8048 - 0x1C];
    s32 counter;
} Ov114Buffer;

extern Ov114Ctx *sub_021BEF08(void);
extern void *sub_021BEF50(Ov114Ctx *ctx);
extern Ov114Mgr *sub_021BEF58(Ov114Ctx *ctx);
extern int sub_021BEBA8(Ov114Mgr *m, void *key);
extern s32 sub_021BF018(Ov114Mgr *m, Ov114Buffer *c);
extern void sub_021BA850(Ov114Buffer *c);
extern void sub_021BB8B4(Ov114Ctx *ctx);
extern void sub_021BBA14(Ov114Ctx *ctx, s32 fd);
extern void sub_021BBB28(Ov114Mgr *m, void *p);
extern int sub_021BF288(Ov114Buffer *c);

int sub_021BF1B0(Ov114Buffer *c)
{
    Ov114Ctx *ctx;
    Ov114Mgr *mgr;

    ctx = sub_021BEF08();
    sub_021BEF50(ctx);
    mgr = sub_021BEF58(ctx);
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
