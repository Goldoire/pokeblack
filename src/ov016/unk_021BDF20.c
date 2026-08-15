/*
 * Overlay 16 -- Wi-Fi Connection setup applet, DWC middleware glue (ARM).
 *
 * Each translation unit of the DWC utility hands its next step to
 * sub_021C0E40; the guards in front of those calls bail out when the
 * preceding query fails.  These routines are a few instructions each and
 * are scattered across the overlay, so they are collected in one file.
 *
 * ARM: compile WITHOUT --thumb, with the repo default compiler.
 */
#include "types.h"

void sub_021C1B90(void);
void sub_021C1D4C(void);
void sub_021C204C(void);
void sub_021C2088(void);
void sub_021C2168(void);
void sub_021C22FC(void);
void sub_021C231C(void);
void sub_021C23FC(void);
void sub_021C2428(void);
void sub_021C24AC(void);
void sub_021C2528(void);
void sub_021C2888(void);
void sub_021C28C4(void);
void sub_021C2948(void);
void sub_021C2D3C(void);
void sub_021C2F14(void);
void sub_021C315C(void);
void sub_021C3250(void);
void sub_021C3490(void);
void sub_021C34BC(void);
void sub_021C3540(void);
void sub_021C35BC(void);
void sub_021C36B4(void);
void sub_021C36F0(void);
void sub_021C3774(void);
void sub_021C3954(void);
void sub_021C3980(void);
void sub_021C3A48(void);
void sub_021C3C64(void);
void sub_021C3EC4(void);
void sub_021C3F00(void);
void sub_021C3FD4(void);
void sub_021C429C(void);
void sub_021C42C0(void);
void sub_021C4614(void);
void sub_021C4640(void);
void sub_021C4E00(void);
void sub_021C4E2C(void);
void sub_021C4FAC(void);
void sub_021C5590(void);
void sub_021C5B24(void);
void sub_021C6534(void);
void sub_021C6560(void);
void sub_021C684C(void);
void sub_021C7018(void);
void sub_021C73A0(void);
void sub_021C7C74(void);
void sub_021C80F4(void);
void sub_021C8130(void);
void sub_021C81B4(void);
void sub_021C8760(void);
void sub_021C8EA8(void);
void sub_021CA5D0(void);
void sub_021CA930(void);
void sub_021CA95C(void);
void sub_021CA980(void);
void sub_021CA9DC(void);
void sub_021CAA08(void);
void sub_021CABF8(void);
void sub_021CAD5C(void);
void sub_021CAD88(void);
void sub_021CADAC(void);
void sub_021CAE08(void);
void sub_021CAE34(void);
void sub_021CB05C(void);
void sub_021CB088(void);
void sub_021CB1A0(void);
void sub_021CB498(void);
void sub_021CB4BC(void);
void sub_021CB518(void);
void sub_021CB734(void);
void sub_021CB93C(void);
void sub_021CBAF4(void);
void sub_021CBC44(void);
void sub_021CBC70(void);
void sub_021CBFA8(void);
void sub_021CC8A0(void);
void sub_021CCC4C(void);
void sub_021CCE58(void);
void sub_021CD3B8(void);
void sub_021CD434(void);
void sub_021CD658(void);
void sub_021CDB84(void);
void sub_021CDE0C(void);
void sub_021CDE48(void);
void sub_021CDF10(void);
void sub_021CE1EC(void);
void sub_021CE218(void);
void sub_021CE2D4(void);
void sub_021CE564(void);
void sub_021CE590(void);
void sub_02085A38();
void sub_02087A04();
void sub_0208BEA4();
void sub_0208F654();
void sub_0208FDEC();
void sub_021BC820();
void sub_021BCAE4();
s32 sub_021BCB14();
void sub_021BCB84();
void sub_021BCB9C();
void sub_021BD264();
void sub_021BD29C();
void sub_021BD674();
void sub_021BD6D4();
void sub_021BD744();
s32 sub_021BDC54();
s32 sub_021BF6E0();
void sub_021C0E40();
s32 sub_021C11B8();
void sub_021C11D4();
void sub_021C1BB4();
void sub_021C1D6C();
void sub_021C20AC();
void sub_021C2188();
void sub_021C2340();
void sub_021C23C0();
void sub_021C244C();
void sub_021C24CC();
void sub_021C2590();
void sub_021C28E8();
void sub_021C2968();
void sub_021C2D60();
void sub_021C2F34();
void sub_021C3194();
void sub_021C3214();
void sub_021C3280();
void sub_021C3358();
void sub_021C34E0();
void sub_021C3560();
void sub_021C3714();
void sub_021C3794();
void sub_021C39A4();
void sub_021C3A68();
void sub_021C3C94();
void sub_021C3DC8();
void sub_021C3F30();
void sub_021C3FF4();
void sub_021C42E0();
void sub_021C4660();
void sub_021C4C60();
void sub_021C4FD0();
void sub_021C55B4();
void sub_021C5B44();
void sub_021C686C();
void sub_021C7044();
void sub_021C73C0();
void sub_021C7CA0();
void sub_021C8154();
void sub_021C81D4();
void sub_021C8794();
void sub_021C8EC8();
void sub_021CA5F0();
void sub_021CA684();
void sub_021CA768();
void sub_021CA76C();
void sub_021CA770();
void sub_021CA9A0();
void sub_021CA9D8();
void sub_021CAA28();
void sub_021CAB68();
void sub_021CAC24();
void sub_021CADCC();
void sub_021CAE04();
void sub_021CAE54();
void sub_021CAF78();
void sub_021CB1C4();
void sub_021CB4DC();
void sub_021CB514();
void sub_021CB544();
void sub_021CB6A4();
void sub_021CB760();
void sub_021CB960();
void sub_021CBB14();
void sub_021CBFD8();
void sub_021CCC70();
void sub_021CCE78();
void sub_021CD3EC();
void sub_021CD400();
void sub_021CD404();
void sub_021CD408();
void sub_021CD458();
void sub_021CD67C();
void sub_021CDBA8();
void sub_021CDE6C();
void sub_021CDF30();
void sub_021CE23C();
void sub_021CE2F4();
void sub_021CE9B8();
void sub_021CE9D0();
void sub_021CF8D8();
void sub_021CFC20();
void sub_021CFFAC();
void sub_021D0014();
s32 sub_021D0684();
void sub_021D1524();
s32 sub_021D1568();
s32 sub_021D157C();
void sub_021D29C8();
void sub_021D2FEC();
void sub_021D3068();
void sub_021D3108();
void sub_021D3250();
void sub_021D38C8();
void sub_021D45A4();
void sub_021D45E0();
s32 sub_021D5580();
void sub_021D5790();
void sub_021D6824();
void sub_021D75D0();

void sub_021C1B90(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021C1BB4);
}

void sub_021C1D4C(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021C1D6C);
}

void sub_021C204C(void)
{
    if (sub_021D5580(1) != 0) {
        return;
    }

    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021BD264(3);
    sub_021C0E40(sub_021C2088);
}

void sub_021C2088(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021C20AC);
}

void sub_021C2168(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021C2188);
}

void sub_021C22FC(void)
{
    if (sub_021D157C() != 0) {
        return;
    }

    sub_021C0E40(sub_021C2168);
}

void sub_021C231C(void)
{
    sub_021C2340();
    sub_021BD29C(25);
    sub_021CFC20();
    sub_021C0E40(sub_021C23C0);
}

void sub_021C23FC(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021BD264(5);
    sub_021C0E40(sub_021C2428);
}

void sub_021C2428(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021C244C);
}

void sub_021C24AC(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021C24CC);
}

void sub_021C2528(void)
{
    if (sub_021D5580(1) != 0) {
        return;
    }

    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_02087A04(8388608);
    sub_0208BEA4();
}

void sub_021C2888(void)
{
    if (sub_021D5580(1) != 0) {
        return;
    }

    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021BD264(2);
    sub_021C0E40(sub_021C28C4);
}

void sub_021C28C4(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021C28E8);
}

void sub_021C2948(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021C2968);
}

void sub_021C2D3C(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021C2D60);
}

void sub_021C2F14(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021C2F34);
}

void sub_021C315C(void)
{
    sub_021C3194();
    sub_021BD29C(30);
    sub_021BC820(0);
    sub_021BD744(1);
    sub_021CFFAC(11);
    sub_021C0E40(sub_021C3214);
}

void sub_021C3250(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021C11D4(sub_021C3358);
    sub_021C0E40(sub_021C3280);
}

void sub_021C3490(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021BD264(5);
    sub_021C0E40(sub_021C34BC);
}

void sub_021C34BC(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021C34E0);
}

void sub_021C3540(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021C3560);
}

void sub_021C35BC(void)
{
    if (sub_021D5580(1) != 0) {
        return;
    }

    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_02087A04(8388608);
    sub_0208BEA4();
}

void sub_021C36B4(void)
{
    if (sub_021D5580(1) != 0) {
        return;
    }

    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021BD264(4);
    sub_021C0E40(sub_021C36F0);
}

void sub_021C36F0(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021C3714);
}

void sub_021C3774(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021C3794);
}

void sub_021C3954(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021BD264(3);
    sub_021C0E40(sub_021C3980);
}

void sub_021C3980(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021C39A4);
}

void sub_021C3A48(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021C3A68);
}

void sub_021C3C64(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    if (sub_021C11B8() == 0) {
        return;
    }

    sub_021C0E40(sub_021C3C94);
}

void sub_021C3EC4(void)
{
    if (sub_021D5580(1) != 0) {
        return;
    }

    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021BD264(3);
    sub_021C0E40(sub_021C3F00);
}

void sub_021C3F00(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    if (sub_021C11B8() == 0) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021C3F30);
}

void sub_021C3FD4(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021C3FF4);
}

void sub_021C429C(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021C0E40(sub_021C42C0);
}

void sub_021C42C0(void)
{
    if (sub_021D1568() == -2) {
        return;
    }

    sub_021C0E40(sub_021C42E0);
}

void sub_021C4614(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021BD264(1);
    sub_021C0E40(sub_021C4640);
}

void sub_021C4640(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021C0E40(sub_021C4660);
}

void sub_021C4E00(void)
{
    if (sub_021D1568() != 0) {
        return;
    }

    sub_021CFFAC(6);
    sub_021D1524();
    sub_021C0E40(sub_021C4E2C);
}

void sub_021C4E2C(void)
{
    if (sub_021D157C() != 0) {
        return;
    }

    sub_021C0E40(sub_021C4C60);
}

void sub_021C4FAC(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021C0E40(sub_021C4FD0);
}

void sub_021C5590(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021C55B4);
}

void sub_021C5B24(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021C5B44);
}

void sub_021C6534(void)
{
    if (sub_021D1568() != 0) {
        return;
    }

    sub_021CFFAC(6);
    sub_021D1524();
    sub_021C0E40(sub_021C6560);
}

void sub_021C6560(void)
{
    if (sub_021D157C() != 0) {
        return;
    }

    sub_021BCB84();
    sub_021CE9B8();
    sub_021C0E40(sub_021C55B4);
}

void sub_021C684C(void)
{
    if (sub_021BDC54() == 255) {
        return;
    }

    sub_021C0E40(sub_021C686C);
}

void sub_021C7018(void)
{
    if (sub_021D1568() != 0) {
        return;
    }

    sub_021CFFAC(6);
    sub_021D1524();
    sub_021C0E40(sub_021C7044);
}

void sub_021C73A0(void)
{
    if (sub_021BF6E0() == 31) {
        return;
    }

    sub_021C0E40(sub_021C73C0);
}

void sub_021C7C74(void)
{
    if (sub_021D1568() != 0) {
        return;
    }

    sub_021CFFAC(6);
    sub_021D1524();
    sub_021C0E40(sub_021C7CA0);
}

void sub_021C80F4(void)
{
    if (sub_021D5580(1) != 0) {
        return;
    }

    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021BD264(4);
    sub_021C0E40(sub_021C8130);
}

void sub_021C8130(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021C8154);
}

void sub_021C81B4(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021C81D4);
}

void sub_021C8760(void)
{
    if (sub_021D5580(1) != 0) {
        return;
    }

    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021C0E40(sub_021C8794);
}

void sub_021C8EA8(void)
{
    sub_021CE9D0();
    sub_021D5790(8);
    sub_021C0E40(sub_021C8EC8);
}

void sub_021CA5D0(void)
{
    sub_021CA5F0();
    sub_021BD6D4();
    sub_021CF8D8();
    sub_021C0E40(sub_021CA684);
}

void sub_021CA930(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021BD264(1);
    sub_021C0E40(sub_021CA95C);
}

void sub_021CA95C(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021CA980);
}

void sub_021CA980(void)
{
    sub_02085A38(10);
    sub_021CAB68();
    sub_021CA9A0();
    sub_021CA9D8();
    sub_021CA9DC();
}

void sub_021CA9DC(void)
{
    if (sub_021BCB14() != 0) {
        return;
    }

    sub_021D0014();
    sub_021CFFAC(7);
    sub_021C0E40(sub_021CAA08);
}

void sub_021CAA08(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021CAA28);
}

void sub_021CABF8(void)
{
    if (sub_021D1568() != 0) {
        return;
    }

    sub_021CFFAC(6);
    sub_021D1524();
    sub_021C0E40(sub_021CAC24);
}

void sub_021CAD5C(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021BD264(1);
    sub_021C0E40(sub_021CAD88);
}

void sub_021CAD88(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021CADAC);
}

void sub_021CADAC(void)
{
    sub_02085A38(10);
    sub_021CAF78();
    sub_021CADCC();
    sub_021CAE04();
    sub_021CAE08();
}

void sub_021CAE08(void)
{
    if (sub_021BCB14() != 0) {
        return;
    }

    sub_021D0014();
    sub_021CFFAC(7);
    sub_021C0E40(sub_021CAE34);
}

void sub_021CAE34(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021CAE54);
}

void sub_021CB05C(void)
{
    if (sub_021D1568() != 0) {
        return;
    }

    sub_021CFFAC(6);
    sub_021D1524();
    sub_021C0E40(sub_021CB088);
}

void sub_021CB088(void)
{
    if (sub_021D157C() != 0) {
        return;
    }

    sub_021C0E40(sub_021CAE34);
}

void sub_021CB1A0(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021C0E40(sub_021CB1C4);
}

void sub_021CB498(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021CB4BC);
}

void sub_021CB4BC(void)
{
    sub_02085A38(10);
    sub_021CB6A4();
    sub_021CB4DC();
    sub_021CB514();
    sub_021CB518();
}

void sub_021CB518(void)
{
    if (sub_021BCB14() != 0) {
        return;
    }

    sub_021D0014();
    sub_021CFFAC(7);
    sub_021C0E40(sub_021CB544);
}

void sub_021CB734(void)
{
    if (sub_021D1568() != 0) {
        return;
    }

    sub_021CFFAC(6);
    sub_021D1524();
    sub_021C0E40(sub_021CB760);
}

void sub_021CB93C(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021CB960);
}

void sub_021CBAF4(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021CBB14);
}

void sub_021CBC44(void)
{
    if (sub_021D1568() != 0) {
        return;
    }

    sub_021CFFAC(6);
    sub_021D1524();
    sub_021C0E40(sub_021CBC70);
}

void sub_021CBC70(void)
{
    if (sub_021D157C() != 0) {
        return;
    }

    sub_021C0E40(sub_021CBAF4);
}

void sub_021CBFA8(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    if (sub_021D0684() == 1) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021CBFD8);
}

void sub_021CC8A0(void)
{
    if (sub_021D157C() != 0) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021CBFD8);
}

void sub_021CCC4C(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021CCC70);
}

void sub_021CCE58(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021CCE78);
}

void sub_021CD3B8(void)
{
    if (sub_021D5580(1) != 0) {
        return;
    }

    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021C0E40(sub_021CD3EC);
}

void sub_021CD434(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021C0E40(sub_021CD458);
}

void sub_021CD658(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021C0E40(sub_021CD67C);
}

void sub_021CDB84(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021C0E40(sub_021CDBA8);
}

void sub_021CDE0C(void)
{
    if (sub_021D5580(1) != 0) {
        return;
    }

    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021BD264(6);
    sub_021C0E40(sub_021CDE48);
}

void sub_021CDE48(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021CDE6C);
}

void sub_021CDF10(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021CDF30);
}

void sub_021CE1EC(void)
{
    if (sub_021D5580(0) != 0) {
        return;
    }

    sub_021BD264(2);
    sub_021C0E40(sub_021CE218);
}

void sub_021CE218(void)
{
    if (sub_021BCB14() == -2) {
        return;
    }

    sub_021BCB84();
    sub_021C0E40(sub_021CE23C);
}

void sub_021CE2D4(void)
{
    sub_021BCB9C();
    sub_021D5790(8);
    sub_021C0E40(sub_021CE2F4);
}

void sub_021CE564(void)
{
    if (sub_021D1568() != 0) {
        return;
    }

    sub_021CFFAC(6);
    sub_021D1524();
    sub_021C0E40(sub_021CE590);
}

void sub_021CE590(void)
{
    if (sub_021D157C() != 0) {
        return;
    }

    sub_021C0E40(sub_021CE2D4);
}
