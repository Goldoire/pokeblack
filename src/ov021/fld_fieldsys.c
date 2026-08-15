/*
 * ov021 / fieldmap.c -- FieldSystem accessor block.
 *
 * Translation unit recovered from the assert __FILE__ string "fieldmap.c" at
 * 0x021DD9C0, referenced from 0x02188030, 0x021880C8 and 0x02189764. The TU
 * spans 0x02187F00..0x0218B754 (the next TU, field_buildmodel.c, starts there).
 *
 * Compiler: tools/mwccarm/dsi/1.1 (repo default), --thumb.
 *
 * Every function here is a one-line accessor, and each one is a *proof* of a
 * FieldSystem field offset -- see src/ov021/fld_fieldsys.h.
 */
#include "types.h"

#include "fld_fieldsys.h"

void *sub_0202C794(void *ovyManager);
void *sub_020120D8(void *ovyManager);
void *sub_02012984(void *a0);
void *sub_020113D8(void *a0);

void *sub_02030734(u32 heapId, u32 size, u32 a2, const char *file, int line);
void sub_020307B0(void *ptr);
void sub_020371AC(u32 a0, u32 a1);
void *sub_020120F4(void *ovyManager);
void *sub_020120F8(void *ovyManager);
void sub_02012110(void *ovyManager, void *a1);
void *sub_02013B38(u16 a0);
void *sub_0202E83C(void *ovyManager);
void *sub_0201407C(u32 heapId, void *a1, void *a2);
void sub_020140B4(void *a0);
const FieldMapMode *sub_02189BA8(u16 a0);

extern const char _021DD9C0[]; /* "fieldmap.c" */

FieldSystem *sub_02188030(void *ovyManager, u32 heapId);
void sub_021880A4(FieldSystem *fieldSystem);
void *sub_02012138(void *ovyManager);

u16 sub_02012AC8(void *a0);
void sub_020306F0(u32 heapId);
void sub_020315D4(void *ovyManager);

/* 0x02187F00 (FieldMap_Init) is banked at build/attempts/ov021/sub_02187F00.c
 * -- 206/208 bytes, one register-allocation window away. */

/* ---- 0x02187FE8: FieldMap exit proc ---- */

BOOL sub_02187FE8(void *ovyManager, void *a1, void *a2, FieldSystem **work)
{
    sub_021880A4(*work);
    sub_02012110(a2, 0);
    sub_020315D4(ovyManager);
    sub_020306F0(0x96);
    sub_020306F0(0x92);
    sub_020306F0(0x93);
    sub_020306F0(0x89);
    sub_020306F0(0x50);
    sub_020306F0(0x70);
    sub_020306F0(0x15);
    return TRUE;
}

/* ---- 0x02188030: FieldSystem_New ---- */

FieldSystem *sub_02188030(void *ovyManager, u32 heapId)
{
    FieldSystem *fieldSystem = sub_02030734(heapId, sizeof(FieldSystem), 1, _021DD9C0, 521);

    fieldSystem->heapId = heapId;
    fieldSystem->unk0C0 = 0;
    fieldSystem->ovyManager = ovyManager;
    fieldSystem->unk008 = sub_020120F4(ovyManager);
    fieldSystem->unk0D0 = sub_02012AC8(sub_020120F8(ovyManager));
    fieldSystem->unk00C = sub_0201407C(heapId, sub_02013B38(fieldSystem->unk0D0),
                                       sub_0202E83C(ovyManager));
    fieldSystem->mode = sub_02189BA8(fieldSystem->unk0D0);
    return fieldSystem;
}

/* ---- 0x021880A4: FieldSystem_Delete ---- */

void sub_021880A4(FieldSystem *fieldSystem)
{
    void *ovyManager = fieldSystem->ovyManager;

    sub_020140B4(fieldSystem->unk00C);
    sub_020307B0(fieldSystem);
    sub_02012110(ovyManager, 0);
    sub_020371AC(0, 0);
}

/*
 * REG_EXMEMCNT bit 15 (main-memory arbitration) is toggled around every call
 * that touches card/VRAM state in this file. Spelled the way the SDK spells it
 * (nitro/hw/ARM9/ioreg_MI.h) so the literal-pool constants line up.
 */
#define reg_MI_EXMEMCNT (*(REGType16v *)0x04000204)

/* ---- 0x02187FD0 ---- */

BOOL sub_02188B58(void *a0, FieldSystem *fieldSystem);

BOOL sub_02187FD0(void *a0, void *a1, void *a2, FieldSystem **work)
{
    if (sub_02188B58(a2, *work) == TRUE) {
        return TRUE;
    }
    return FALSE;
}

/* ---- 0x021888C8 ---- */

void sub_02047CE4(void);
u32 sub_0203630C(void);
void sub_0218E104(void *camera, u16 a1);
s32 sub_02189A80(FieldSystem *fieldSystem);
void sub_02189084(FieldSystem *fieldSystem);
void sub_02189108(void);
void sub_021890AC(FieldSystem *fieldSystem);

void sub_021888C8(FieldSystem *fieldSystem)
{
    sub_02047CE4();
    sub_0218E104(fieldSystem->camera, sub_0203630C());
    fieldSystem->unk100 = sub_02189A80(fieldSystem);
    reg_MI_EXMEMCNT &= ~0x8000;
    sub_02189084(fieldSystem);
    reg_MI_EXMEMCNT |= 0x8000;
}

/* ---- 0x02188910 ---- */

u32 sub_02012E40(void *a0);
void sub_020129F0(void *a0);
void sub_0218CC34(void *g3dMapper);
void sub_021A0E58(void *a0);
void sub_021903E0(void *a0);
void sub_021BC4F0(void *a0);

BOOL sub_02188910(void *ovyManager, FieldSystem *fieldSystem)
{
    if (sub_02012E40(fieldSystem->unk008) != 0) {
        sub_020129F0(sub_020120F4(ovyManager));
        return FALSE;
    }
    reg_MI_EXMEMCNT &= ~0x8000;
    sub_0218CC34(fieldSystem->g3dMapper);
    reg_MI_EXMEMCNT |= 0x8000;
    sub_021A0E58(fieldSystem->unk024);
    if (fieldSystem->unk028 != NULL) {
        sub_021903E0(fieldSystem->unk028);
    }
    if (fieldSystem->unk030 != NULL) {
        sub_021BC4F0(fieldSystem->unk030);
    }
    reg_MI_EXMEMCNT &= ~0x8000;
    sub_021890AC(fieldSystem);
    reg_MI_EXMEMCNT |= 0x8000;
    sub_020129F0(sub_020120F4(ovyManager));
    return FALSE;
}

/* ---- 0x021880C8: FieldMap bring-up ---- */

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
void *sub_02030CBC(u32 a0);
void *sub_021C6D10(u32 a0, u16 heapId);
void *sub_021D317C(u16 heapId);
BOOL sub_02013CC8(u16 a0);
BOOL sub_02013CE0(u16 a0);
void sub_02034AC4(u32 a0);
void sub_02035660(u32 a0);
void sub_02188E50(void);

extern u8 _021D3604[];
extern u8 _021D3688[];

BOOL sub_021880C8(void *a0, FieldSystem *fieldSystem)
{
    u16 heapId = fieldSystem->heapId;
    void *bgConfig;

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
    fieldSystem->unk114 = sub_02030734(heapId, sub_02030CB0(0x20), 0, _021DD9C0, 0x26B);
    fieldSystem->unk110 = sub_02030CBC(0x20);
    fieldSystem->taskManager = sub_021C6D10(10, fieldSystem->heapId);
    fieldSystem->vreq = sub_021D317C(fieldSystem->heapId);
    sub_02034AC4((sub_02013CC8(fieldSystem->unk0D0) == TRUE ||
                  sub_02013CE0(fieldSystem->unk0D0) == TRUE) ? 0x13 : 0x12);
    sub_02035660(0x1E);
    return TRUE;
}

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
                  sub_02013CE0(fieldSystem->unk0D0) == TRUE) ? 0x13 : 0x12);
    return 2;
}

/* ---- 0x02188990: FieldMap teardown ---- */

void sub_021CF480(void *a0);
void sub_021C1C04(void *a0);
void sub_021C1AD0(void *a0);
void sub_0201209C(void *ovyManager, u32 a1, u32 a2);
void sub_021A2EB8(void *a0);
void sub_021BB90C(void *a0);
void sub_020263B0(void *a0, FieldSystem *fieldSystem);
void sub_021BC424(void *a0);
void sub_021BE218(FieldSystem *fieldSystem);
void sub_021BE2E0(void *a0);
void sub_021A9F28(void *a0);
void *sub_021A0D44(void *a0);
void sub_020129B8(void *a0, void *a1);
void sub_021ABDE8(void *a0);
void sub_0217F8EC(void *a0);
void sub_021A1AAC(void *a0);
void sub_021A0448(void *a0);
void sub_021A02F4(void *a0);
void sub_021A0138(void *a0);
void sub_021D33E0(void *a0);
void sub_021BB240(void *a0);
void sub_021AB81C(void *a0);
void sub_021AB624(void *a0);
void sub_0218E0E4(void *a0);
void sub_021895DC(FieldSystem *fieldSystem);
void sub_021892B4(FieldSystem *fieldSystem);
void sub_021A2E90(void *a0);
void sub_0218D05C(void *a0);
void sub_02190728(void *a0);
void sub_021902BC(void *a0);
void sub_020129DC(void *a0, u32 a1);
void sub_021C31FC(void *a0);
void sub_021C7F9C(void *a0);

BOOL sub_02188990(void *ovyManager, FieldSystem *fieldSystem)
{
    sub_021CF480(fieldSystem->unk13C);
    sub_021C1C04(fieldSystem->unk124);
    sub_021C1AD0(fieldSystem->unk120);
    sub_0201209C(ovyManager, 0, 0);
    sub_021A2EB8(fieldSystem->unk08C);
    sub_021BB90C(fieldSystem->unk0BC);
    sub_020263B0(sub_02012138(ovyManager), fieldSystem);
    if (fieldSystem->unk030 != NULL) {
        sub_021BC424(fieldSystem->unk030);
    }
    sub_021BE218(fieldSystem);
    sub_021BE2E0(fieldSystem->unk034);
    sub_021A9F28(fieldSystem->unk090);
    sub_020129B8(sub_020120F4(ovyManager), sub_021A0D44(fieldSystem->unk024));
    sub_021ABDE8(fieldSystem->unk094);
    if (fieldSystem->unk098 != NULL) {
        sub_0217F8EC(fieldSystem->unk098);
        fieldSystem->unk098 = NULL;
    }
    sub_021A1AAC(fieldSystem->unk020);
    fieldSystem->unk020 = NULL;
    sub_021A0448(fieldSystem->unk014);
    sub_021A02F4(fieldSystem->unk01C);
    sub_021A0138(fieldSystem->unk018);
    sub_021D33E0(fieldSystem->unk09C);
    sub_021BB240(fieldSystem->unk03C);
    sub_021AB81C(fieldSystem->unk044);
    sub_021AB624(fieldSystem->unk040);
    sub_0218E0E4(fieldSystem->camera);
    fieldSystem->mode->exit(fieldSystem);
    sub_021895DC(fieldSystem);
    sub_021892B4(fieldSystem);
    sub_021A2E90(fieldSystem->unk08C);
    sub_0218D05C(fieldSystem->g3dMapper);
    if (fieldSystem->unk02C != NULL) {
        sub_02190728(fieldSystem->unk02C);
    }
    if (fieldSystem->unk028 != NULL) {
        sub_021902BC(fieldSystem->unk028);
    }
    sub_020129DC(sub_020120F4(ovyManager), 0);
    sub_02035660(0x3C);
    sub_021C31FC(fieldSystem->unk128);
    sub_021C7F9C(fieldSystem->unk0A0);
    return TRUE;
}

/* ---- accessor run at 0x02188C54..0x02188D5C ---- */

void *sub_02188C54(FieldSystem *fieldSystem)
{
    return fieldSystem->unk028;
}

void *sub_02188C58(FieldSystem *fieldSystem)
{
    return fieldSystem->camera;
}

void *sub_02188C5C(FieldSystem *fieldSystem)
{
    return fieldSystem->unk03C;
}

void *sub_02188C60(FieldSystem *fieldSystem)
{
    return fieldSystem->unk014;
}

void *sub_02188C64(FieldSystem *fieldSystem)
{
    return fieldSystem->unk018;
}

void *sub_02188C68(FieldSystem *fieldSystem)
{
    return fieldSystem->unk01C;
}

void *sub_02188C6C(FieldSystem *fieldSystem)
{
    return fieldSystem->unk020;
}

void *sub_02188C70(FieldSystem *fieldSystem)
{
    return sub_0202C794(fieldSystem->ovyManager);
}

void *sub_02188C7C(FieldSystem *fieldSystem)
{
    return fieldSystem->unk038;
}

void *sub_02188C80(FieldSystem *fieldSystem)
{
    return fieldSystem->ovyManager;
}

u16 sub_02188C84(FieldSystem *fieldSystem)
{
    return fieldSystem->heapId;
}

void *sub_02188C88(FieldSystem *fieldSystem)
{
    return fieldSystem->unk0B4;
}

void *sub_02188C90(FieldSystem *fieldSystem)
{
    return fieldSystem->unk0B8;
}

void *sub_02188C98(FieldSystem *fieldSystem)
{
    return fieldSystem->g3dMapper;
}

u16 sub_02188C9C(FieldSystem *fieldSystem)
{
    return fieldSystem->unk0D8;
}

void *sub_02188CA4(FieldSystem *fieldSystem)
{
    return fieldSystem->unk10C;
}

void sub_02188CAC(FieldSystem *fieldSystem, void *a1)
{
    fieldSystem->unk10C = a1;
}

void *sub_02188CB4(FieldSystem *fieldSystem)
{
    return fieldSystem->unk08C;
}

BOOL sub_02188CBC(FieldSystem *fieldSystem)
{
    if (fieldSystem->unk08C != NULL) {
        return TRUE;
    }
    return FALSE;
}

void *sub_02188CCC(FieldSystem *fieldSystem)
{
    return fieldSystem->unk024;
}

void *sub_02188CD0(FieldSystem *fieldSystem)
{
    return fieldSystem->unk094;
}

void *sub_02188CD8(FieldSystem *fieldSystem)
{
    return fieldSystem->unk130;
}

void *sub_02188CE0(FieldSystem *fieldSystem)
{
    return fieldSystem->unk098;
}

void *sub_02188CE8(FieldSystem *fieldSystem)
{
    return fieldSystem->unk090;
}

int sub_02188CF0(FieldSystem *fieldSystem)
{
    return fieldSystem->mode->id;
}

void *sub_02188D20(FieldSystem *fieldSystem)
{
    return fieldSystem->unk030;
}

void *sub_02188D24(FieldSystem *fieldSystem)
{
    return fieldSystem->unk0BC;
}

void *sub_02188D2C(FieldSystem *fieldSystem)
{
    return fieldSystem->unk034;
}

void *sub_02188D30(FieldSystem *fieldSystem)
{
    return fieldSystem->unk110;
}

void *sub_02188D38(FieldSystem *fieldSystem)
{
    return fieldSystem->taskManager;
}

void sub_02188D40(FieldSystem *fieldSystem, void *a1)
{
    fieldSystem->unk0F0 = a1;
}

void *sub_02188D48(FieldSystem *fieldSystem)
{
    return fieldSystem->unk02C;
}

void sub_02188D4C(FieldSystem *fieldSystem, void *a1)
{
    fieldSystem->unk02C = a1;
}

void *sub_02188D50(FieldSystem *fieldSystem)
{
    return fieldSystem->unk128;
}

void *sub_02188D58(FieldSystem *fieldSystem)
{
    return fieldSystem->unk00C;
}

void sub_02188BD8(FieldSystem *fieldSystem)
{
    fieldSystem->unk0C0 = 2;
    fieldSystem->unk0C4 = 4;
}

BOOL sub_02188BE8(FieldSystem *fieldSystem)
{
    if (fieldSystem->unk0C0 == 1) {
        return TRUE;
    }
    return FALSE;
}

/* ---- accessor run at 0x021899F0..0x02189A80 ---- */

void *sub_021899F0(FieldSystem *fieldSystem)
{
    return fieldSystem->unk12C;
}

void sub_021899F8(FieldSystem *fieldSystem, void *a1)
{
    fieldSystem->unk12C = a1;
}

void *sub_02189A00(FieldSystem *fieldSystem)
{
    return fieldSystem->unk124;
}

void *sub_02189A08(FieldSystem *fieldSystem)
{
    return fieldSystem->unk13C;
}

void *sub_02189A10(FieldSystem *fieldSystem)
{
    return fieldSystem->unk0A0;
}

void *sub_02189A18(FieldSystem *fieldSystem)
{
    return fieldSystem->unk040;
}

void sub_02189A1C(FieldSystem *fieldSystem, void *a1)
{
    fieldSystem->unk138 = a1;
}

void *sub_02189A24(FieldSystem *fieldSystem)
{
    return fieldSystem->unk138;
}

void *sub_02189A2C(FieldSystem *fieldSystem)
{
    return sub_020120D8(fieldSystem->ovyManager);
}

void *sub_02189A38(FieldSystem *fieldSystem)
{
    return sub_020113D8(sub_02012984(fieldSystem->unk008));
}

void *sub_02189A48(FieldSystem *fieldSystem)
{
    return fieldSystem->unk144;
}

void sub_02189A50(FieldSystem *fieldSystem, void *a1)
{
    fieldSystem->unk144 = a1;
}

void sub_02189A58(FieldSystem *fieldSystem, void *a1)
{
    fieldSystem->unk140 = a1;
}

void **sub_02189A60(FieldSystem *fieldSystem)
{
    return &fieldSystem->unk148;
}

void sub_02189A68(FieldSystem *fieldSystem, void *a1)
{
    fieldSystem->unk150 = a1;
}

void *sub_02189A70(FieldSystem *fieldSystem)
{
    return fieldSystem->unk150;
}

s32 sub_02189A78(FieldSystem *fieldSystem)
{
    return fieldSystem->unk100;
}
