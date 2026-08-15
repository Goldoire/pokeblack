/*
 * Overlay 16 -- Wi-Fi Connection setup applet, DWC middleware glue.
 *
 * ARM code: compile WITHOUT --thumb, with the repo default compiler
 *     python tools/scripts/cc.py src/ov016/unk_021BD3E4.c
 *
 * The ranges here are non-contiguous: these are the small fan-out and
 * trampoline routines scattered through the overlay's ARM half.
 */
#include "types.h"

void *sub_021D6414(u32 size, u32 align);
void sub_021D6438(void *param0);
void sub_021BD5A8(void);
void sub_021BD674(u32 param0);
void sub_021C3D58(void);
void sub_021C3CA4(void);
void sub_021C4FE0(void);
void sub_021C50A0(void);
void sub_021CB1D4(void);
void sub_021CB294(void);
void sub_021CD68C(void);
void sub_021CD79C(void);
void sub_021CDBB8(void);
void sub_021CDC78(void);
void sub_021C3290(void);
void sub_021C3294(void);
void sub_021D276C(u32 param0);
void sub_021F5F74(void);
void sub_021D656C(void);
void sub_021D75D0(u32 param0);
void sub_021C4BDC(void);
void sub_021C4C18(void);
void sub_021D5790(u32 param0);
void sub_021C0E40(void (*param0)(void));
void sub_021C6A2C(void);
void sub_021C7738(void);
void sub_021C7D00(void);
void sub_021C7D80(void);
void sub_021C80B8(void);
void sub_021BCB9C(void);
void sub_021CB564(void);
void sub_021CB544(void);
s32 sub_021D157C(void);
s32 sub_021D319C(void);
void sub_021D29C8(u32 param0);

/* 0x021CF404 returns the DWC context; unkF4 is a small u8 index. */
typedef struct UnkStruct021CF404 {
    u8 unk00[0xF4];
    u8 unkF4;
} UnkStruct021CF404;

UnkStruct021CF404 *sub_021CF404(void);

/* Overlay .bss.  Defined here rather than declared extern so the verifier
 * does not read the (overlay-aliased) address as a thumb function pointer. */
void *_021DE550;

void sub_021BD3E4(void)
{
    _021DE550 = sub_021D6414(0x10, 4);
}

void sub_021BD404(void)
{
    sub_021BD5A8();
    sub_021D6438(&_021DE550);
}

void sub_021BD6D4(void)
{
    sub_021BD674(sub_021CF404()->unkF4 + 5);
}

void sub_021BD6EC(void)
{
    sub_021BD674(sub_021CF404()->unkF4 + 2);
}

void sub_021C3280(void)
{
    sub_021C3290();
    sub_021C3294();
}

void sub_021C3C94(void)
{
    sub_021C3D58();
    sub_021C3CA4();
}

void sub_021C4DE4(void)
{
    sub_021D656C();
    sub_021D75D0(0);
    sub_021C4BDC();
    sub_021C4C18();
}

void sub_021C4FD0(void)
{
    sub_021C50A0();
    sub_021C4FE0();
}

void sub_021C6A10(void)
{
    sub_021D5790(8);
    sub_021C0E40(sub_021C6A2C);
}

void sub_021C771C(void)
{
    sub_021D5790(8);
    sub_021C0E40(sub_021C7738);
}

void sub_021C7CE4(void)
{
    sub_021C7D00();
    sub_021C7D80();
    sub_021C0E40(sub_021C80B8);
}

void sub_021CB1C4(void)
{
    sub_021CB294();
    sub_021CB1D4();
}

void sub_021CB544(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021CB564);
}

void sub_021CB760(void)
{
    if (sub_021D157C() != 0) {
        return;
    }

    sub_021C0E40(sub_021CB544);
}

void sub_021CD67C(void)
{
    sub_021CD79C();
    sub_021CD68C();
}

void sub_021CDBA8(void)
{
    sub_021CDC78();
    sub_021CDBB8();
}

void sub_021D240C(void)
{
    sub_021D276C(6);
    sub_021F5F74();
}

void sub_021D39A4(void)
{
    if (sub_021D319C() != 0) {
        return;
    }

    sub_021D29C8(10);
}
