// BANKED. ov093 opcode id 34.  ROM is 20 bytes, every C spelling tried is 16:
// CW always fuses the two adjacent arg loads into `ldm r2,{r1,r2}`, while the
// ROM loads args[1] into r3, args[0] into r1 and then moves r3->r2.  Swept all
// 24 mwccarm builds (identical output), -O1/-O2/-O4,s, -opt nopeephole,
// -opt noschedule, volatile args, struct-typed args, byte-pointer casts, u64
// third argument, sequenced locals, inline helper.  Nothing breaks the ldm.
#include "ov093/battle.h"

void sub_021EF9F4(void *a0, u32 a1, u32 a2, u32 a3);

int sub_021D3B74(BattleScriptCtx *ctx, u32 *state, u32 *args)
{
    u32 v1 = args[1];

    sub_021EF9F4(ctx->unk_034, args[0], v1, 0);
    return 1;
}
