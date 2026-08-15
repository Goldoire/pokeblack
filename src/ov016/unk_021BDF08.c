/*
 * Overlay 16 -- Wi-Fi Connection setup applet.
 *
 * The DWC middleware in this overlay is ARM, and each of its translation
 * units ends in a small fan-out routine that calls the unit's own entry
 * points in order.  They are collected here because each one is only a
 * handful of bytes; the address ranges are non-contiguous.
 *
 * !! ARM, not thumb: compile WITHOUT --thumb.
 */
#include "types.h"

void sub_021BDF20(void);
void sub_021BE0D8(void);
void sub_021BE3E4(void);
void sub_021BE618(void);
void sub_021BF988(void);
void sub_021BFB38(void);
void sub_021BFCF8(void);
void sub_021BFF14(void);
void sub_021C1BC8(void);
void sub_021C1CF8(void);
void sub_021C1CFC(void);
void sub_021C20C0(void);
void sub_021C20FC(void);
void sub_021C2100(void);
void sub_021C2460(void);
void sub_021C2480(void);
void sub_021C2484(void);
void sub_021C28FC(void);
void sub_021C291C(void);
void sub_021C2920(void);
void sub_021C2D74(void);
void sub_021C2E68(void);
void sub_021C2E6C(void);
void sub_021C34F4(void);
void sub_021C3514(void);
void sub_021C3518(void);
void sub_021C3728(void);
void sub_021C3748(void);
void sub_021C374C(void);
void sub_021C39B8(void);
void sub_021C39F4(void);
void sub_021C39F8(void);
void sub_021C3F44(void);
void sub_021C3F80(void);
void sub_021C3F84(void);
void sub_021C4674(void);
void sub_021C46AC(void);
void sub_021C46B0(void);
void sub_021C55C8(void);
void sub_021C57E4(void);
void sub_021C5A10(void);
void sub_021C687C(void);
void sub_021C6A0C(void);
void sub_021C73D0(void);
void sub_021C7718(void);
void sub_021C8168(void);
void sub_021C8188(void);
void sub_021C818C(void);
void sub_021C87A4(void);
void sub_021C8C88(void);
void sub_021CB978(void);
void sub_021CBAA0(void);
void sub_021CBAC4(void);
void sub_021CBAC8(void);
void sub_021CBFEC(void);
void sub_021CC0E4(void);
void sub_021CC0E8(void);
void sub_021CCC84(void);
void sub_021CCE00(void);
void sub_021CCE04(void);
void sub_021CDE80(void);
void sub_021CDEBC(void);
void sub_021CDEC0(void);
void sub_021CE250(void);
void sub_021CE288(void);
void sub_021CE28C(void);
void sub_021D657C(void);
void sub_021D668C(void);

void sub_021BDF08(void)
{
    sub_021BDF20();
    sub_021BE0D8();
    sub_021BE3E4();
    sub_021BE618();
}

void sub_021BF970(void)
{
    sub_021BF988();
    sub_021BFB38();
    sub_021BFCF8();
    sub_021BFF14();
}

void sub_021C1BB4(void)
{
    sub_021C1BC8();
    sub_021C1CF8();
    sub_021C1CFC();
}

void sub_021C20AC(void)
{
    sub_021C20C0();
    sub_021C20FC();
    sub_021C2100();
}

void sub_021C244C(void)
{
    sub_021C2460();
    sub_021C2480();
    sub_021C2484();
}

void sub_021C28E8(void)
{
    sub_021C28FC();
    sub_021C291C();
    sub_021C2920();
}

void sub_021C2D60(void)
{
    sub_021C2D74();
    sub_021C2E68();
    sub_021C2E6C();
}

void sub_021C34E0(void)
{
    sub_021C34F4();
    sub_021C3514();
    sub_021C3518();
}

void sub_021C3714(void)
{
    sub_021C3728();
    sub_021C3748();
    sub_021C374C();
}

void sub_021C39A4(void)
{
    sub_021C39B8();
    sub_021C39F4();
    sub_021C39F8();
}

void sub_021C3F30(void)
{
    sub_021C3F44();
    sub_021C3F80();
    sub_021C3F84();
}

void sub_021C4660(void)
{
    sub_021C4674();
    sub_021C46AC();
    sub_021C46B0();
}

void sub_021C55B4(void)
{
    sub_021C55C8();
    sub_021C57E4();
    sub_021C5A10();
}

void sub_021C686C(void)
{
    sub_021C687C();
    sub_021C6A0C();
}

void sub_021C73C0(void)
{
    sub_021C73D0();
    sub_021C7718();
}

void sub_021C8154(void)
{
    sub_021C8168();
    sub_021C8188();
    sub_021C818C();
}

void sub_021C8794(void)
{
    sub_021C87A4();
    sub_021C8C88();
}

void sub_021CB960(void)
{
    sub_021CBAA0();
    sub_021CBAC4();
    sub_021CBAC8();
    sub_021CB978();
}

void sub_021CBFD8(void)
{
    sub_021CBFEC();
    sub_021CC0E4();
    sub_021CC0E8();
}

void sub_021CCC70(void)
{
    sub_021CCC84();
    sub_021CCE00();
    sub_021CCE04();
}

void sub_021CDE6C(void)
{
    sub_021CDE80();
    sub_021CDEBC();
    sub_021CDEC0();
}

void sub_021CE23C(void)
{
    sub_021CE250();
    sub_021CE288();
    sub_021CE28C();
}

void sub_021D656C(void)
{
    sub_021D657C();
    sub_021D668C();
}
