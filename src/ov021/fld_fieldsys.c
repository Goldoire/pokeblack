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
/* 0x021880C8 and 0x02188AD4 are banked at
 * build/attempts/ov021/sub_021880C8_sub_02188AD4.c -- both are one shared
 * literal-pool-vs-MOVS idiom away from byte-exact. */
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
    sub_021A0E58(fieldSystem->subScreen);
    if (fieldSystem->unk028 != NULL) {
        sub_021903E0(fieldSystem->unk028);
    }
    if (fieldSystem->placeName != NULL) {
        sub_021BC4F0(fieldSystem->placeName);
    }
    reg_MI_EXMEMCNT &= ~0x8000;
    sub_021890AC(fieldSystem);
    reg_MI_EXMEMCNT |= 0x8000;
    sub_020129F0(sub_020120F4(ovyManager));
    return FALSE;
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
    sub_021CF480(fieldSystem->encEff);
    sub_021C1C04(fieldSystem->ci3d);
    sub_021C1AD0(fieldSystem->particle);
    sub_0201209C(ovyManager, 0, 0);
    sub_021A2EB8(fieldSystem->unk08C);
    sub_021BB90C(fieldSystem->fieldmapFunc);
    sub_020263B0(sub_02012138(ovyManager), fieldSystem);
    if (fieldSystem->placeName != NULL) {
        sub_021BC424(fieldSystem->placeName);
    }
    sub_021BE218(fieldSystem);
    sub_021BE2E0(fieldSystem->expObj);
    sub_021A9F28(fieldSystem->encount);
    sub_020129B8(sub_020120F4(ovyManager), sub_021A0D44(fieldSystem->subScreen));
    sub_021ABDE8(fieldSystem->fieldEffect);
    if (fieldSystem->unk098 != NULL) {
        sub_0217F8EC(fieldSystem->unk098);
        fieldSystem->unk098 = NULL;
    }
    sub_021A1AAC(fieldSystem->weather);
    fieldSystem->weather = NULL;
    sub_021A0448(fieldSystem->light);
    sub_021A02F4(fieldSystem->zoneFog);
    sub_021A0138(fieldSystem->fog);
    sub_021D33E0(fieldSystem->palaceSys);
    sub_021BB240(fieldSystem->nogridMapper);
    sub_021AB81C(fieldSystem->sceneAreaLoader);
    sub_021AB624(fieldSystem->sceneArea);
    sub_0218E0E4(fieldSystem->camera);
    fieldSystem->mode->exit(fieldSystem);
    sub_021895DC(fieldSystem);
    sub_021892B4(fieldSystem);
    sub_021A2E90(fieldSystem->unk08C);
    sub_0218D05C(fieldSystem->g3dMapper);
    if (fieldSystem->msgBg != NULL) {
        sub_02190728(fieldSystem->msgBg);
    }
    if (fieldSystem->unk028 != NULL) {
        sub_021902BC(fieldSystem->unk028);
    }
    sub_020129DC(sub_020120F4(ovyManager), 0);
    sub_02035660(0x3C);
    sub_021C31FC(fieldSystem->sodateya);
    sub_021C7F9C(fieldSystem->mapEff);
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
    return fieldSystem->nogridMapper;
}

void *sub_02188C60(FieldSystem *fieldSystem)
{
    return fieldSystem->light;
}

void *sub_02188C64(FieldSystem *fieldSystem)
{
    return fieldSystem->fog;
}

void *sub_02188C68(FieldSystem *fieldSystem)
{
    return fieldSystem->zoneFog;
}

void *sub_02188C6C(FieldSystem *fieldSystem)
{
    return fieldSystem->weather;
}

void *sub_02188C70(FieldSystem *fieldSystem)
{
    return sub_0202C794(fieldSystem->ovyManager);
}

void *sub_02188C7C(FieldSystem *fieldSystem)
{
    return fieldSystem->mapObjMan;
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
    return fieldSystem->subScreen;
}

void *sub_02188CD0(FieldSystem *fieldSystem)
{
    return fieldSystem->fieldEffect;
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
    return fieldSystem->encount;
}

int sub_02188CF0(FieldSystem *fieldSystem)
{
    return fieldSystem->mode->id;
}

void *sub_02188D20(FieldSystem *fieldSystem)
{
    return fieldSystem->placeName;
}

void *sub_02188D24(FieldSystem *fieldSystem)
{
    return fieldSystem->fieldmapFunc;
}

void *sub_02188D2C(FieldSystem *fieldSystem)
{
    return fieldSystem->expObj;
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
    return fieldSystem->msgBg;
}

void sub_02188D4C(FieldSystem *fieldSystem, void *a1)
{
    fieldSystem->msgBg = a1;
}

void *sub_02188D50(FieldSystem *fieldSystem)
{
    return fieldSystem->sodateya;
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
    return fieldSystem->ci3d;
}

void *sub_02189A08(FieldSystem *fieldSystem)
{
    return fieldSystem->encEff;
}

void *sub_02189A10(FieldSystem *fieldSystem)
{
    return fieldSystem->mapEff;
}

void *sub_02189A18(FieldSystem *fieldSystem)
{
    return fieldSystem->sceneArea;
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

/* ---- 0x02188B58: the FieldMap state machine ----
 *
 * fieldmap.c's own .rodata table at 0x021D36B8: six rows of two
 * `int (*)(void *)` slots, indexed [fieldSystem->unk0C4][fieldSystem->unk0C9].
 * The rows are the field-map lifecycle, and every entry is a proc in this TU:
 *   0  0x021880C8 0x021880C8   (init A)
 *   1  0x021881D8 0x021881D8   (init B)
 *   2  0x021885E8 0x021885E8   (init C)
 *   3  0x02188758 0x02188910   (main loop / vblank half)
 *   4  0x02188990 0x02188990   (teardown phase 0)
 *   5  0x02188AD4 0x02188AD4   (teardown phase 1, src/ov021/fld_mapctl.c)
 * Return 0 = stay (toggle the half), 1 = advance the row, 2 = finished.
 */
typedef int (*FieldMapStateFunc)(void *a0, FieldSystem *fieldSystem);

extern FieldMapStateFunc _021D36B8[][2];

BOOL sub_02188B58(void *a0, FieldSystem *fieldSystem)
{
    int result = 0;
    FieldMapStateFunc fn;

    fieldSystem->unk0CC++;
    fn = _021D36B8[fieldSystem->unk0C4][fieldSystem->unk0C9];
    if (fn != NULL) {
        result = fn(a0, fieldSystem);
    }

    switch (result) {
    case 0:
        fieldSystem->unk0C9 = (fieldSystem->unk0C9 == 0);
        break;
    case 1:
        fieldSystem->unk0C4++;
        fieldSystem->unk0C8 = 0;
        fieldSystem->unk0C9 = 0;
        break;
    case 2:
        return TRUE;
    }
    return FALSE;
}

/* ---- 0x02188CFC: map-kind lookup, with one kind deferred to the rail code ---- */

extern u8 _021D35A8[];
u32 sub_021A6DC0(void *a0);

u32 sub_02188CFC(FieldSystem *fieldSystem)
{
    u32 kind = _021D35A8[fieldSystem->mode->id];

    if (kind == 2) {
        kind = sub_021A6DC0(fieldSystem->unk10C);
    }
    return kind;
}

/* ---- 0x02188DA0 ---- */

extern u8 _021D35F4[];
void *sub_0203FC28(void *a0);

void *sub_02188DA0(void)
{
    return sub_0203FC28(_021D35F4);
}

/* ---- 0x02189140 ---- */

/* Four arguments: that is why CW cannot spare r3 for a tail call here and
 * emits push/bl/pop where a one-argument forwarder would `bx r3`. */


/* The 0/1 argument is an ENUM, not an int. With an int CW canonicalises the
 * ternary to bne/1/0; the ROM keeps source order (beq-block = 0), and only an
 * enum (or a pointer) return type makes CW preserve it. */
typedef enum FieldSysSel {
    FIELDSYS_SEL_0 = 0,
    FIELDSYS_SEL_1 = 1
} FieldSysSel;

void sub_02061CA4(FieldSysSel a0, u32 a1, u32 a2, u32 a3);

void sub_02189140(void *a0, u32 a1, u32 a2, u32 a3)
{
    sub_02061CA4(a0 == NULL ? FIELDSYS_SEL_0 : FIELDSYS_SEL_1, a1, a2, a3);
}

/* ---- 0x021895BC / 0x021895D0 ---- */

void *sub_020127A4(void *a0);
void sub_02012AC4(void *a0, u16 a1);
void sub_021895E8(FieldSystem *fieldSystem, u32 a1, u16 heapId);

void sub_021895BC(void *a0, u32 a1)
{
    sub_02012AC4(sub_020127A4(a0), a1);
}

void sub_021895D0(FieldSystem *fieldSystem, u32 a1)
{
    sub_021895E8(fieldSystem, a1, fieldSystem->heapId);
}

/* ---- 0x02189758 / 0x02189764: the {id, buffer} pair at FieldSystem+0x118 ---- */

void sub_02189758(FieldSysBuf *buf)
{
    buf->id = -1;
    buf->data = NULL;
}

void *sub_02189764(FieldSystem *fieldSystem, int id, u16 heapId, u32 size)
{
    FieldSysBuf *buf = &fieldSystem->buf118;
    void *p;

    if (id == -1) {
        return NULL;
    }
    if (buf->id != -1) {
        return NULL;
    }
    buf->id = id;
    p = sub_02030734(heapId, size, 1, _021DD9C0, 0xD7C);
    buf->data = p;
    return p;
}

/* ---- 0x02189998 ---- */

void sub_0207DD24(u32 a0, u32 a1, u32 a2, u32 a3, u32 a4);
void sub_021C1AEC(void);
void sub_021C1C4C(void *ci3d);

void sub_02189998(FieldSystem *fieldSystem)
{
    sub_0207DD24(0, 0, 0x7FFF, 0, 0);
    sub_021C1AEC();
    sub_021C1C4C(fieldSystem->ci3d);
}

/* ---- 0x02189ACC / 0x02189AE8 / 0x02189B04: zone predicates ---- */

BOOL sub_02013BA8(u16 zoneId);
BOOL sub_02013CE0(u16 zoneId);

u32 sub_02189ACC(u16 zoneId)
{
    if (sub_02013BA8(zoneId) == TRUE) {
        return 0x1EE;
    }
    return 0x136;
}

BOOL sub_02189AE8(u16 zoneId)
{
    if (zoneId == 0x3F) {
        return FALSE;
    }
    if (sub_02013CE0(zoneId) == TRUE) {
        return FALSE;
    }
    return TRUE;
}

BOOL sub_02189B04(u16 zoneId)
{
    if (zoneId == 0x3F) {
        return TRUE;
    }
    if (zoneId == 0x8C) {
        return TRUE;
    }
    if (zoneId == 0x8D) {
        return TRUE;
    }
    if (zoneId == 0x8E) {
        return TRUE;
    }
    return FALSE;
}

/* ---- 0x0218A728 / 0x0218A76C ---- */

void *sub_02012F2C(void *a0);
void sub_02008DF0(void *a0, u32 a1);
BOOL sub_0218A8BC(void *a0);
void sub_0218A784(void *a0, u32 a1);

void sub_0218A728(void *a0)
{
    sub_02008DF0(sub_02012F2C(a0), 0);
}

void sub_0218A76C(void *a0)
{
    if (sub_0218A8BC(a0) == 0) {
        sub_0218A784(a0, 9);
    }
}
