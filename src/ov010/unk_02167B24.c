// WALL (tooling, not codegen): sub_02167B24 / sub_02167B34, 16 bytes each.
//
// The C below is almost certainly right -- 14/16, and the only differing word
// is the second call. 0x0203D594 and 0x0203D5A0 are ARM long-branch veneers in
// main ("ldr ip,[pc,#0]; bx ip"), so the ROM encodes the call as Thumb BLX.
// build/reference/triage.json has no entry at either address, so
// verify_functions.py falls back to its Thumb default and emits BL. Add ARM
// entries for those two addresses (or teach the verifier to sniff the target
// bytes) and these should pass unchanged.
//
#include "types.h"

void *sub_020399A8(void *param0);
void sub_0203D594(void *param0, void *param1);
void sub_0203D5A0(void *param0, void *param1);

void sub_02167B24(void *p)
{
    sub_0203D594(sub_020399A8(p), p);
}

void sub_02167B34(void *p)
{
    sub_0203D5A0(sub_020399A8(p), p);
}
