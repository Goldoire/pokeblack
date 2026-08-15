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


/* ---- 0x021880C8: FieldMap bring-up (state row 0 of the 0x021D36B8 table) ----
 *
 * Signature proven by 0x02188B58: every row of that table is called as
 * fn(a0, fieldSystem), and a0 lands unused here.
 */

void sub_020433E0(void *a0);
void sub_02188D5C(FieldSystem *fieldSystem);
void sub_0204A48C(void *a0, void *a1, u32 a2);
void sub_020434DC(u32 a0, u32 a1);
void sub_02043598(u32 a0, u32 a1);
void sub_02045088(u16 heapId);
void sub_0201DD60(void);
void sub_02046440(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4, u16 heapId, void *cb);
void sub_02188EE4(FieldSystem *fieldSystem);
void *sub_0218C9E8(u16 heapId, void *a1);
void *sub_020056A0(void *cb, FieldSystem *fieldSystem, u32 a2);
u32 sub_02030CB0(u32 a0);
void *sub_02030CBC(u32 a0, void *work);
void *sub_021C6D10(u32 a0, u16 heapId);
void *sub_021D317C(u16 heapId);
void sub_02034AC4(u32 a0);
void sub_02035660(u32 a0);
void sub_02188E50(void);
void sub_02189108(void *a0, void *a1);
void *sub_02012984(void *a0);
void *sub_02030734(u16 heapId, u32 size, u32 atEnd, void *file, u32 line);

extern u8 _021DD9C0[]; /* "fieldmap.c" */
extern u8 _021D3604[];
extern u8 _021D3688[];

int sub_021880C8(void *a0, FieldSystem *fieldSystem)
{
    u16 heapId = fieldSystem->heapId;
    void *bgConfig;
    void *work;

    sub_020433E0(_021D3688);
    sub_02188D5C(fieldSystem);
    sub_0204A48C(_021D3604, _021D3688, 0x89);
    sub_020434DC(0x10, 1);
    sub_02043598(0x10, 1);
    sub_02045088(heapId);
    sub_0201DD60();
    sub_02046440(0, 3, 0, 1, 0x1000, fieldSystem->heapId, sub_02188E50);
    sub_02188EE4(fieldSystem);
    bgConfig = sub_02012984(fieldSystem->unk008);
    fieldSystem->g3dMapper = sub_0218C9E8(fieldSystem->heapId, bgConfig);
    fieldSystem->task0AC = sub_020056A0(sub_02189108, fieldSystem, 0);
    work = sub_02030734(heapId, sub_02030CB0(0x20), 0, _021DD9C0, 0x26B);
    fieldSystem->unk114 = work;
    fieldSystem->unk110 = sub_02030CBC(0x20, work);
    fieldSystem->taskManager = sub_021C6D10(10, fieldSystem->heapId);
    fieldSystem->vreq = sub_021D317C(fieldSystem->heapId);
    sub_02034AC4((sub_02013CC8(fieldSystem->unk0D0) == TRUE ||
                  sub_02013CE0(fieldSystem->unk0D0) == TRUE) ? (u32)_00000013 : (u32)_00000012);
    sub_02035660(0x1E);
    return TRUE;
}

/* ---- 0x02187F00: FieldMap_Init (the overlay's OverlayManager init proc) ----
 *
 * Previously banked at 206/208. Two arg-preplacement idioms fixed it, the same
 * one that unblocked 0x021880C8: CW leaves a call result in the register the
 * NEXT call wants it in, so a store that reads `str r1,[r6]` is a value that is
 * also the second argument of the following call.
 */

void sub_0203064C(u32 heapParent, u32 heapId, u32 size);
void sub_02030678(void *a0, u32 size, u32 heapId);
u32 sub_02189BBC(u16 a0);
FieldSystem *sub_02188030(void *a2, u32 heapId);
void *sub_020120F8(void *a0);
u16 sub_02012AC8(void *a0);
FieldSystem **sub_0203159C(void *ovyManager, u32 size, u32 heapId);
void sub_02012110(void *a0, FieldSystem *fieldSystem);
BOOL sub_0201214C(void *a0);
void *sub_02012138(void *a0);
u32 sub_02026454(void *a0);
void sub_02026400(void *a0);

extern u8 _021DE700[];

BOOL sub_02187F00(void *ovyManager, int *state, void *a2)
{
    FieldSystem **work;
    FieldSystem *fieldSystem;
    void *v;
    u32 avail;

    switch (*state) {
    case 0:
        avail = sub_02189BBC(sub_02012AC8(sub_020120F8(a2))) - 0xD000;
        sub_0203064C(1, 0x15, avail);
        sub_0203064C(1, 0x70, 0xD000);
        sub_0203064C(0x15, 0x50, 0xC000);
        sub_02030678(_021DE700, 0x10000, 0x89);
        sub_0203064C(0x89, 0x92, 0x6400);
        sub_0203064C(0x89, 0x93, 0x7400);
        sub_0203064C(0x89, 0x96, 0x500);
        work = sub_0203159C(ovyManager, 4, 0x15);
        fieldSystem = sub_02188030(a2, 0x15);
        *work = fieldSystem;
        sub_02012110(a2, fieldSystem);
        (*state)++;
        break;
    case 1:
        if (sub_0201214C(a2) == 0) {
            v = sub_02012138(a2);
            /* A switch, not `== 1 || == 2`: the latter range-optimises into
             * `subs #1 / cmp #1 / bhi`, the ROM has the two compares. */
            switch (sub_02026454(v)) {
            case 1:
            case 2:
                sub_02026400(v);
                break;
            }
        }
        return TRUE;
    }
    return FALSE;
}
