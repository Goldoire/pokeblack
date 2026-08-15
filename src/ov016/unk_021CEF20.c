/*
 * Overlay 16 -- Wi-Fi Connection setup applet, DWC middleware glue (ARM).
 *
 * ARM: compile WITHOUT --thumb, with the repo default compiler.
 *
 * Globals in the overlay's .bss whose address aliases a *function* in another
 * overlay are reached through an anchor one word earlier; the relocation
 * addend still produces the ROM's pool word.
 */
#include "types.h"

void sub_02060C94(void *param0);
void sub_02090E50(u32 param0, u32 param1, u32 param2, u32 param3, u32 param4);
void sub_021D29C8(u32 param0);
void sub_021D2A44(void);
void sub_02088234(void);
void *sub_021D6414(u32 size, u32 align);
void *sub_021D6F18(void);
void sub_021D52D4(u32 param0, u32 param1, void *param2);

/* 0x021DE684 */
extern u8 *_021DE680[];
/* 0x021DE640 */
extern void *_021DE640;

typedef struct UnkStruct021D5F14 UnkStruct021D5F14;

typedef struct UnkVtable021D5F14 {
    u32 unk00;
    void (*unk04)(UnkStruct021D5F14 *param0, u32 param1);
} UnkVtable021D5F14;

struct UnkStruct021D5F14 {
    u32 unk00[5];
    const UnkVtable021D5F14 *unk14;
};

typedef struct UnkStruct021D3178 {
    u16 unk00;
    u16 unk02;
} UnkStruct021D3178;

void sub_021CEF20(void)
{
    if (_021DE640 != NULL) {
        return;
    }

    _021DE640 = sub_021D6414(0x1E60, 0x20);
}

void sub_021D3178(UnkStruct021D3178 *param0)
{
    if (param0->unk02 != 0) {
        sub_021D2A44();
        return;
    }

    sub_021D29C8(1);
}

void sub_021D34C0(u32 param0, u32 param1)
{
    sub_02090E50(param0, 3, 0x11, param1, 30);
}

void sub_021D36B0(UnkStruct021D3178 *param0)
{
    if (param0->unk02 != 8) {
        return;
    }

    sub_021D29C8(9);
    sub_02088234();
}

void *sub_021D5368(u32 param0, u32 param1)
{
    void *ptr = sub_021D6F18();

    sub_021D52D4(param0, param1, ptr);
    return ptr;
}

void sub_021D5F14(UnkStruct021D5F14 *param0, u32 param1)
{
    param0->unk14->unk04(param0, param1);
}

void sub_021D63A8(void)
{
    void **pp = (void **)(_021DE680 + 1);

    sub_02060C94(*pp);
    *pp = NULL;
}
