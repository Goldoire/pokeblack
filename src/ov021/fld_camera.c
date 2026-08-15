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

#include "fld_camera.h"

void sub_0218E5EC(FieldCamera *camera)
{
    camera->unk020 = 0;
}

void sub_0218E5F4(FieldCamera *camera)
{
    camera->unk01C = 0;
}

void *sub_0218EC2C(FieldCamera *camera)
{
    return camera->unk00C;
}

void sub_0218EC54(FieldCamera *camera)
{
    camera->unk01C = 0;
}

u32 sub_0218EC5C(FieldCamera *camera)
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
