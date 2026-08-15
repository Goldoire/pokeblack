/*
 * ov021 fieldmap.c 0x02188AD4 -- FieldMap tear-down, phase 1.
 *
 * Recovered from build/attempts/. The blocker was never codegen: the ROM
 * materialises the argument to sub_02034A5C out of the literal pool where a
 * movs would be shorter, because NitroSDK overlay ids are linker-absolute
 * symbols (FS_OVERLAY_ID(x) is &SDK_OVERLAY_x_ID), not immediates. Spelling
 * them as address-named externs reproduces the relocation exactly.
 * Established independently by the ov009 and ov016 workers.
 */
#include "types.h"
#include "fld_fieldsys.h"

extern u8 _00000012[];
extern u8 _00000013[];

/* ---- 0x02188AD4: FieldMap tear-down, phase 1 ---- */

void sub_02030DA4(void *a0);
void sub_021D31A4(void *vreq);
void sub_021C6D5C(void *taskManager);
void sub_02030EAC(void *task);
void sub_0218CA4C(void *g3dMapper);
void sub_021890C8(FieldSystem *fieldSystem);
void sub_0204A5AC(void);
void sub_020450C8(void);
void sub_02188E38(FieldSystem *fieldSystem);
void sub_02034A5C(u32 a0);

int sub_02188AD4(void *a0, FieldSystem *fieldSystem)
{
    sub_02030DA4(fieldSystem->unk110);
    sub_020307B0(fieldSystem->unk114);
    sub_021D31A4(fieldSystem->vreq);
    fieldSystem->vreq = NULL;
    sub_021C6D5C(fieldSystem->taskManager);
    sub_02030EAC(fieldSystem->task0AC);
    sub_0218CA4C(fieldSystem->g3dMapper);
    sub_021890C8(fieldSystem);
    sub_0204A5AC();
    sub_020450C8();
    sub_02188E38(fieldSystem);
    sub_02034A5C((sub_02013CC8(fieldSystem->unk0D0) == TRUE ||
                  sub_02013CE0(fieldSystem->unk0D0) == TRUE) ? (u32)_00000013 : (u32)_00000012);
    return 2;
}

