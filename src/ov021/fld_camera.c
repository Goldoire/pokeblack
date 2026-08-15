/*
 * ov021 / field_camera.c -- FieldCamera accessors.
 *
 * TU recovered from the assert __FILE__ string "field_camera.c" at 0x021DDA28,
 * referenced from 0x0218E018 and 0x0218EEFC. The TU spans 0x0218E018..0x0218FF30.
 *
 * Compiler: tools/mwccarm/dsi/1.1 (repo default), --thumb.
 * Each accessor is a proof of a FieldCamera offset -- see fld_camera.h.
 */
#include "types.h"
#include <nitro/fx/fx.h>

#include "fld_camera.h"

void sub_0218E5EC(FieldCamera *camera)
{
    camera->unk020 = NULL;
}

void sub_0218E5F4(FieldCamera *camera)
{
    camera->unk01C = NULL;
}

void *sub_0218EC2C(FieldCamera *camera)
{
    return camera->unk00C;
}

void sub_0218EC54(FieldCamera *camera)
{
    camera->unk01C = NULL;
}

VecFx32 *sub_0218EC5C(FieldCamera *camera)
{
    return camera->unk01C;
}

void sub_0218EC60(FieldCamera *camera)
{
    camera->unk01C = camera->unk018;
}

u16 sub_0218ED2C(FieldCamera *camera)
{
    return camera->unk078;
}

void sub_0218ED34(FieldCamera *camera, u16 a1)
{
    camera->unk078 = a1;
}

u16 *sub_0218ED3C(FieldCamera *camera)
{
    return &camera->unk084;
}

u16 sub_0218ED40(FieldCamera *camera)
{
    return camera->unk07A;
}

void sub_0218ED48(FieldCamera *camera, u16 a1)
{
    camera->unk07A = a1;
}

u16 *sub_0218ED50(FieldCamera *camera)
{
    return &camera->unk082;
}

u32 sub_0218ED54(FieldCamera *camera)
{
    return camera->unk07C;
}

void sub_0218ED58(FieldCamera *camera, u32 a1)
{
    camera->unk07C = a1;
}

void sub_0218F1AC(FieldCamera *camera, u8 a1)
{
    camera->unk0E9 = a1;
}

u8 sub_0218F1B4(FieldCamera *camera)
{
    return camera->unk0E9;
}

/* ---- 0x0218E018: FieldCamera_New ---- */

void *sub_02030734(u16 heapId, u32 size, u32 atEnd, void *file, u32 line);
void sub_020307B0(void *ptr);
BOOL sub_02048B78(void *a0);
void sub_02048B88(void *a0, s32 *out);
u16 sub_0207D184(s32 a0); /* FX_AtanIdx */
void *sub_020490F4(u32 a0, u16 heapId);
void sub_02049238(void *a0);
void sub_0218E18C(FieldCamera *camera, void *a1);
void sub_0218EEFC(u32 a0, u32 a1, u32 a2, u16 heapId, FieldCamera *camera);
void sub_0218EFD4(FieldCamera *camera);

extern u8 _021DDA28[]; /* "field_camera.c" */

FieldCamera *sub_0218E018(u32 a0, u32 a1, void *a2, void *a3, u16 heapId)
{
    FieldCamera *camera = sub_02030734(heapId, sizeof(FieldCamera), 1, _021DDA28, 128);
    s32 v;

    camera->unk010 = a0;
    camera->mode = a1;
    camera->unk00C = a2;
    camera->unk020 = NULL;
    camera->heapId = heapId;
    camera->unk024.x = 0;
    camera->unk024.y = 0;
    camera->unk024.z = 0;
    camera->unk048.x = 0;
    camera->unk048.y = 0;
    camera->unk048.z = 0;
    camera->unk06C.x = 0;
    camera->unk06C.y = 0;
    camera->unk06C.z = 0;
    camera->unk030.x = 0;
    camera->unk030.y = 0;
    camera->unk030.z = 0;
    camera->unk07A = 0;
    camera->unk078 = 0;
    camera->unk07C = 0x78;
    camera->unk0E9 = 1;
    if (sub_02048B78(a2) == 0) {
        sub_02048B88(a2, &v);
        camera->unk080 = sub_0207D184(v);
    }
    camera->unk004 = sub_020490F4(0x3C, camera->heapId);
    camera->unk008 = sub_020490F4(0x6C, camera->heapId);
    camera->unk0EA = 0xFFFF;
    sub_0218E18C(camera, a3);
    sub_0218EEFC(7, 6, 2, heapId, camera);
    camera->cb = NULL;
    return camera;
}

/* ---- 0x0218E0E4: FieldCamera_Delete ---- */

void sub_0218E0E4(FieldCamera *camera)
{
    sub_02049238(camera->unk004);
    sub_02049238(camera->unk008);
    sub_0218EFD4(camera);
    sub_020307B0(camera);
}

/* ---- 0x0218E104: per-frame entry point ---- */

void sub_0218E58C(FieldCamera *camera, u16 a1);

void sub_0218E104(FieldCamera *camera, u16 a1)
{
    if (camera->cb != NULL) {
        camera->cb(camera, camera->cbArg);
    }
    sub_0218E58C(camera, a1);
}

/* ---- the three mode tables ---- */

typedef void (*FieldCameraModeFunc)(FieldCamera *camera);

extern FieldCameraModeFunc _021DDA00[]; /* mode enter  */
extern FieldCameraModeFunc _021DDA0C[]; /* mode select */
extern void (*_021D3E44[])(FieldCamera *camera, u16 a1); /* mode update */

void sub_0218E124(FieldCamera *camera, u32 mode)
{
    camera->mode = mode;
    _021DDA0C[mode](camera);
}

void sub_0218E13C(FieldCamera *camera, u32 mode)
{
    if (camera->mode == mode) {
        return;
    }
    _021DDA00[mode](camera);
    sub_0218E124(camera, mode);
}

void sub_0218E58C(FieldCamera *camera, u16 a1)
{
    _021D3E44[camera->mode](camera, a1);
}

/* ---- 0x0218E160 / 0x0218E17C ---- */

void sub_0218E160(FieldCamera *camera)
{
    sub_0218E124(camera, 0);
    sub_0218E18C(camera, camera->unk018);
    camera->unk0E9 = 1;
}

void sub_0218E17C(FieldCamera *camera, u32 a1)
{
    camera->unk010 = a1;
    sub_0218E160(camera);
}

/* ---- 0x0218E284 / 0x0218E298: pull the tracked position in ---- */

void sub_0218E284(FieldCamera *camera)
{
    if (camera->unk01C != NULL) {
        camera->unk048 = *camera->unk01C;
    }
}

BOOL sub_0218E298(FieldCamera *camera)
{
    if (camera->unk020 != NULL) {
        camera->unk024 = *camera->unk020;
        return TRUE;
    }
    return FALSE;
}

/* ---- 0x0218E5A0 / 0x0218E5B8 / 0x0218E5D0 / 0x0218E5FC / 0x0218E73C ---- */

void sub_0218E358(FieldCamera *camera);
void sub_0218E404(FieldCamera *camera);
void sub_0218E4B0(FieldCamera *camera);
void sub_0218E540(FieldCamera *camera);

void sub_0218E5A0(FieldCamera *camera)
{
    sub_0218E284(camera);
    sub_0218E358(camera);
    sub_0218E540(camera);
}

void sub_0218E5B8(FieldCamera *camera)
{
    sub_0218E298(camera);
    sub_0218E404(camera);
    sub_0218E540(camera);
}

void sub_0218E5D0(FieldCamera *camera)
{
    sub_0218E284(camera);
    sub_0218E298(camera);
    sub_0218E4B0(camera);
    sub_0218E540(camera);
}

void sub_0218E5FC(FieldCamera *camera)
{
    camera->unk078 = 0;
    camera->unk07A = 0;
    camera->unk07C = 0;
}

/* An if/else-if chain, not a switch: the ROM keeps the mode in a register and
 * compares it twice in source order, which a two-case switch does not do. */
void sub_0218E73C(FieldCamera *camera)
{
    u32 mode = camera->mode;

    if (mode == 0) {
        sub_0218E284(camera);
        sub_0218E358(camera);
    } else if (mode == 1) {
        sub_0218E298(camera);
        sub_0218E404(camera);
    }
}

/* ---- the VecFx32 block at 0x24..0x77: seven vectors, 0x24 0x30 0x3C 0x48
 *      0x54 0x60 0x6C. Every one of these is a whole-struct copy (ldm/stm). ---- */

/* 0x0218EC30 is banked at build/attempts/ov021/sub_0218EC30.c -- 29/36, the two
 * parameter-save moves in the prologue come out in the other order. */

void sub_0218EC90(FieldCamera *camera, const VecFx32 *src)
{
    camera->unk048 = *src;
    camera->unk06C = *src;
}

void sub_0218ECB4(FieldCamera *camera, VecFx32 *dst)
{
    *dst = camera->unk048;
}

void sub_0218ECC4(FieldCamera *camera, VecFx32 *dst)
{
    *dst = camera->unk060;
}

void sub_0218ECD4(FieldCamera *camera, const VecFx32 *src)
{
    camera->unk060 = *src;
}

void sub_0218ECE4(FieldCamera *camera, VecFx32 *dst)
{
    *dst = camera->unk024;
}

void sub_0218ECF4(FieldCamera *camera, const VecFx32 *src)
{
    camera->unk024 = *src;
}

void sub_0218ED04(FieldCamera *camera, const VecFx32 *src)
{
    camera->unk030 = *src;
}

void sub_0218F18C(FieldCamera *camera, VecFx32 *dst)
{
    *dst = camera->unk054;
}

void sub_0218F19C(FieldCamera *camera, VecFx32 *dst)
{
    *dst = camera->unk03C;
}

/* ---- 0x0218ED14 / 0x0218ED20 ---- */

void *sub_02048B20(void *a0);
void *sub_02048B0C(void *a0);

void *sub_0218ED14(FieldCamera *camera)
{
    return sub_02048B20(camera->unk00C);
}

void *sub_0218ED20(FieldCamera *camera)
{
    return sub_02048B0C(camera->unk00C);
}

/* ---- 0x0218F050 / 0x0218F0D4 / 0x0218F0E8 / 0x0218F0F8 ---- */

void sub_0218F050(FieldCamera *camera)
{
    camera->unk024.z = 0;
    camera->unk024.y = 0;
    camera->unk010 = 0;
}

void sub_0218F0D4(FieldCamera *camera)
{
    FieldCamera *p = camera->unk0EC;

    if (p != NULL) {
        p->unk024.z = 0;
        p->unk024.y = 0;
        p->unk010 = 0;
    }
}

fx32 sub_0218F0E8(FieldCamera *camera)
{
    if (camera->unk0EC == NULL) {
        return 0;
    }
    return camera->unk0EC->unk024.y;
}

BOOL sub_0218F0F8(FieldCamera *camera)
{
    if (camera->unk01C == NULL) {
        return FALSE;
    }
    if (camera->unk0EC != NULL) {
        return TRUE;
    }
    return FALSE;
}

/* ---- 0x0218F114 / 0x0218F134: the 0x18-byte entry table at +0x88 ---- */

typedef struct FieldCameraKeySet {
    /* 0x00 */ u32 count;
    /* 0x04 */ u8 data[4 * 0x18];
} FieldCameraKeySet;

void sub_02082D44(const void *src, void *dst, u32 size); /* MI_CpuCopy8 */
void sub_02082BCC(void *dst, u8 value, u32 size);        /* MI_CpuFill8 */

void sub_0218F114(FieldCamera *camera, const FieldCameraKeySet *set)
{
    sub_02082D44(set->data, camera->unk088, set->count * 0x18);
    camera->unk0E8 = set->count;
}

void sub_0218F134(FieldCamera *camera)
{
    sub_02082BCC(camera->unk088, 0, sizeof(camera->unk088));
    camera->unk0E8 = 0;
}

/* ---- 0x0218FDD4: linear interpolation between two fx32s ---- */

s32 sub_0218FDD4(const s32 *from, const s32 *to, s32 total, s32 step)
{
    s32 a = *from;
    s32 b = *to;

    s32 diff;

    if (total == step) {
        return b;
    }
    diff = b - a;
    return a + diff * step / total;
}

/* ---- 0x0218FE40 / 0x0218FE50: the camera callback ---- */

void sub_0218FE40(FieldCamera *camera)
{
    camera->cb = NULL;
    camera->cbArg = NULL;
}

/* ---- 0x0218FF00 / 0x0218FF20 ---- */

int *sub_021901E8(FieldCamera *camera);
void sub_02190110(FieldCamera *camera);
void sub_0219014C(FieldCamera *camera);
void sub_02190000(FieldCamera *camera);

void sub_0218FF00(FieldCamera *camera)
{
    if (*sub_021901E8(camera) == 0) {
        sub_02190110(camera);
    } else {
        sub_0219014C(camera);
    }
}

void sub_0218FF20(FieldCamera *camera)
{
    if (camera->unk00C != NULL) {
        sub_02190000(camera);
    }
}
