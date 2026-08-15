PRELUDE = '''#include "ov093/battle.h"
void *sub_021B9AEC(BattleQueue *q, u32 a1);
u32 sub_021B9F70(BattleSystem *bsys, u8 a1);
void sub_021B9C50(void *p, u8 a1, u32 a2, u32 a3);
void sub_021EA678(void *a0, u16 a1, u32 *a2);
BOOL sub_021EA710(void *a0);
void sub_021EAA6C(void *a0, u8 a1, u8 a2);
BOOL sub_021EAAD8(void *a0);
'''
HEAD = """int sub_021D31A0(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u8 v0;
    u8 v1;
    u8 f;
    %s msg;

    switch (*state) {
    case 0:
        v0 = (u8)args[0];
        v1 = (u8)args[1];
        sub_021B9C50(sub_021B9AEC(ctx->unk_04, v0), v1, 0, 0);
        sub_021EAA6C(ctx->unk_054, v0, v1);
        (*state)++;
        break;
    case 1:
        if (sub_021EAAD8(ctx->unk_054) != FALSE) {
            v1 = (u8)args[1];
            if (v1 == 1) {
                return 1;
            }
            f = (u8)sub_021B9F70(ctx->unk_00, (u8)args[0]);
%s
            sub_021EA678(ctx->unk_054, %s, args);
            (*state)++;
        }
        break;
    case 2:
        if (sub_021EA710(ctx->unk_054) != FALSE) {
            return 1;
        }
        break;
    }
    return 0;
}"""
TERN = """            if (v1 == 3) {
                msg = f != 0 ? 0x26 : 0x27;
            } else {
                msg = f != 0 ? 0x28 : 0x29;
            }"""
NEST = """            if (v1 == 3) {
                if (f != 0) {
                    msg = 0x26;
                } else {
                    msg = 0x27;
                }
            } else {
                if (f != 0) {
                    msg = 0x28;
                } else {
                    msg = 0x29;
                }
            }"""
VARIANTS = [
    HEAD % ("u16", TERN, "msg"),
    HEAD % ("int", NEST, "msg"),
    HEAD % ("u32", NEST, "(u16)msg"),
    HEAD % ("s16", NEST, "msg"),
    HEAD % ("volatile u16", NEST, "msg"),
]
