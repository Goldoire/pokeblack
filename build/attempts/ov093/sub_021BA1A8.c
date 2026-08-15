// sub_021BA1A8 (ov093, 0x021BA1A8, 12 bytes) -- 11/12, ONE byte off.
// sub_021BA080 (ov093, 0x021BA080, 12 bytes) -- 11/12, ONE byte off.
//
// Both are Thumb tail calls through the literal pool:
//     ldr r0,[r0] ; ldr r3,=<target>|1 ; ... ; bx r3
// and mwcc reproduces every instruction.  The single mismatching byte is bit 0
// of the literal-pool word: the ROM stores the target with the Thumb bit set,
// the verifier emits it clear.
//
// Cause is the claim table, not the C.  verify_functions._exact_func() only
// accepts an address that triage recorded as a function start, and neither
// 0x02013158 nor 0x0202E7DC is in build/reference/triage.json at all -- the
// nearest main entries below them (0x02013144, 0x0202E7C4) are zero-size
// "callsite" rows, so they establish no extent either.  Add either address as
// a real thumb function row and these match with no source change.
//
// Verified-except-for-that code (drop back into src/ov093/):

BOOL sub_02013158(BattleCore *core, int a1);
void *sub_0202E7DC(u32 a0);

BOOL sub_021BA1A8(BattleSystem *bsys, int a1)
{
    return sub_02013158(bsys->core, a1);
}

void *sub_021BA080(BattleSystem *bsys)
{
    return sub_0202E7DC(bsys->core->unk_70);
}
