#include "types.h"

// ov093 0x021daab4..0x021ddcc4: per-effect wrapper
// shells and count/table getters.

typedef struct UnkOwner {
    /* 0x00 */ u8 unk_00[0x18];
    /* 0x18 */ void *unk_18;
} UnkOwner;

extern const u8 _021F05B0[];
extern const u8 _021F05C8[];
extern const u8 _021F05D0[];
extern const u8 _021F05E0[];
extern const u8 _021F05E8[];
extern const u8 _021F05F0[];
extern const u8 _021F05F8[];
extern const u8 _021F0620[];
extern const u8 _021F0628[];
extern const u8 _021F0630[];
extern const u8 _021F0658[];
extern const u8 _021F0660[];
extern const u8 _021F0678[];
extern const u8 _021F0680[];
extern const u8 _021F0688[];
extern const u8 _021F0690[];
extern const u8 _021F06C0[];
extern const u8 _021F06C8[];
extern const u8 _021F06D0[];
extern const u8 _021F06D8[];
extern const u8 _021F06E0[];
extern const u8 _021F06E8[];
extern const u8 _021F06F0[];
extern const u8 _021F06F8[];
extern const u8 _021F0700[];
extern const u8 _021F0708[];
extern const u8 _021F0718[];
extern const u8 _021F0728[];
extern const u8 _021F0730[];
extern const u8 _021F0750[];
extern const u8 _021F0760[];
extern const u8 _021F0768[];
extern const u8 _021F0770[];
extern const u8 _021F0778[];
extern const u8 _021F0780[];
extern const u8 _021F0788[];
extern const u8 _021F0790[];
extern const u8 _021F0798[];
extern const u8 _021F07A0[];
extern const u8 _021F07A8[];
extern const u8 _021F07D0[];
extern const u8 _021F07E8[];
extern const u8 _021F08B0[];
extern const u8 _021F0920[];
extern const u8 _021F0940[];
extern const u8 _021F0950[];
extern const u8 _021F0960[];
extern const u8 _021F0990[];
extern const u8 _021F0A00[];
extern const u8 _021F0A10[];
extern const u8 _021F0A28[];
extern const u8 _021F0A58[];
extern const u8 _021F0A70[];
extern const u8 _021F0AA0[];
extern const u8 _021F0AB8[];
extern const u8 _021F0AD0[];
extern const u8 _021F0AE8[];
extern const u8 _021F0B30[];
extern const u8 _021F0B48[];
extern const u8 _021F0B60[];
extern const u8 _021F0B94[];
extern const u8 _021F0BD4[];
extern const u8 _021F0C24[];
extern const u8 _021F0D14[];
extern const u8 _021F0D9C[];
extern const u8 _021F0DD4[];
extern const u8 _021F16CC[];
extern const u8 _021F171C[];
extern const u8 _021F172C[];
extern const u8 _021F175C[];
extern const u8 _021F177C[];
extern const u8 _021F178C[];
extern const u8 _021F179C[];
extern const u8 _021F17AC[];
extern const u8 _021F17BC[];
extern const u8 _021F17CC[];
extern const u8 _021F17DC[];
extern const u8 _021F17EC[];
extern const u8 _021F17FC[];
extern const u8 _021F180C[];
extern const u8 _021F181C[];
extern const u8 _021F182C[];
extern const u8 _021F183C[];
extern const u8 _021F184C[];
extern const u8 _021F1AA4[];
extern const u8 _021F1AC4[];
extern const u8 _021F1AEC[];
extern const u8 _021F1B14[];
extern const u8 _021F1B3C[];
extern const u8 _021F1B64[];
extern const u8 _021F1B8C[];
extern const u8 _021F1BB4[];
extern const u8 _021F1BDC[];
extern const u8 _021F1C04[];
extern const u8 _021F1C2C[];
extern const u8 _021F1C54[];
extern const u8 _021F1C7C[];
extern const u8 _021F1CA4[];
extern const u8 _021F1CCC[];
extern const u8 _021F1CF4[];
extern const u8 _021F1D1C[];
extern const u8 _021F1D44[];
extern const u8 _021F1D6C[];
extern const u8 _021F1D94[];
extern const u8 _021F1DBC[];
extern const u8 _021F1DE4[];
extern const u8 _021F1E6C[];

void sub_021DD158(void *a0, void *a1, int a2, int a3);
void sub_021DD19C(void *a0, void *a1, int a2, int a3);
void sub_021DD39C(void *a0, void *a1, int a2, void *a3, int a4);
void sub_021DD7B8(void *a0, void *a1, int a2, void *a3, int a4);
void sub_021DD9E8(void *a0, void *a1, int a2, int a3);

const u8 *sub_021DAAB4(int *count)
{
    *count = 3;
    return _021F0B30;
}

const u8 *sub_021DAAE0(int *count)
{
    *count = 1;
    return _021F0730;
}

const u8 *sub_021DAB0C(int *count)
{
    *count = 1;
    return _021F07A0;
}

const u8 *sub_021DAB18(int *count)
{
    *count = 1;
    return _021F0798;
}

const u8 *sub_021DAB6C(int *count)
{
    *count = 1;
    return _021F0790;
}

const u8 *sub_021DABE8(int *count)
{
    *count = 1;
    return _021F0788;
}

const u8 *sub_021DAC84(int *count)
{
    *count = 3;
    return _021F0A10;
}

const u8 *sub_021DAD20(int *count)
{
    *count = 1;
    return _021F0660;
}

const u8 *sub_021DADF8(int *count)
{
    *count = 4;
    return _021F0B94;
}

const u8 *sub_021DAED8(int *count)
{
    *count = 5;
    return _021F0BD4;
}

const u8 *sub_021DB000(int *count)
{
    *count = 3;
    return _021F0A28;
}

const u8 *sub_021DB0D0(int *count)
{
    *count = 1;
    return _021F07E8;
}

const u8 *sub_021DB128(int *count)
{
    *count = 2;
    return _021F08B0;
}

const u8 *sub_021DB248(int *count)
{
    *count = 5;
    return _021F0C24;
}

const u8 *sub_021DB404(int *count)
{
    *count = 9;
    return _021F0DD4;
}

const u8 *sub_021DB410(int *count)
{
    *count = 3;
    return _021F0A58;
}

const u8 *sub_021DB454(int *count)
{
    *count = 3;
    return _021F0A70;
}

const u8 *sub_021DB5B4(int *count)
{
    *count = 1;
    return _021F05F0;
}

const u8 *sub_021DB644(int *count)
{
    *count = 2;
    return _021F0920;
}

const u8 *sub_021DB7DC(int *count)
{
    *count = 7;
    return _021F0D9C;
}

const u8 *sub_021DB8D0(int *count)
{
    *count = 3;
    return _021F0AA0;
}

const u8 *sub_021DB8DC(int *count)
{
    *count = 3;
    return _021F0AB8;
}

const u8 *sub_021DB9AC(int *count)
{
    *count = 1;
    return _021F06F8;
}

const u8 *sub_021DB9D0(int *count)
{
    *count = 1;
    return _021F06F0;
}

const u8 *sub_021DBA00(int *count)
{
    *count = 1;
    return _021F06E8;
}

const u8 *sub_021DBA74(int *count)
{
    *count = 1;
    return _021F06E0;
}

const u8 *sub_021DBAE4(int *count)
{
    *count = 1;
    return _021F06D8;
}

const u8 *sub_021DBB58(int *count)
{
    *count = 2;
    return _021F0960;
}

const u8 *sub_021DBBCC(int *count)
{
    *count = 1;
    return _021F06C8;
}

const u8 *sub_021DBCE0(int *count)
{
    *count = 1;
    return _021F06C0;
}

const u8 *sub_021DBE60(int *count)
{
    *count = 1;
    return _021F0718;
}

const u8 *sub_021DBF1C(int *count)
{
    *count = 1;
    return _021F07D0;
}

const u8 *sub_021DBFC8(int *count)
{
    *count = 5;
    return _021F0D14;
}

const u8 *sub_021DC0B0(int *count)
{
    *count = 1;
    return _021F0688;
}

const u8 *sub_021DC0F8(int *count)
{
    *count = 1;
    return _021F07A8;
}

const u8 *sub_021DC130(int *count)
{
    *count = 1;
    return _021F0690;
}

const u8 *sub_021DC164(int *count)
{
    *count = 1;
    return _021F0780;
}

const u8 *sub_021DC20C(int *count)
{
    *count = 1;
    return _021F0778;
}

const u8 *sub_021DC250(int *count)
{
    *count = 1;
    return _021F0768;
}

const u8 *sub_021DC294(int *count)
{
    *count = 1;
    return _021F0620;
}

const u8 *sub_021DC320(int *count)
{
    *count = 1;
    return _021F05E8;
}

const u8 *sub_021DC498(int *count)
{
    *count = 1;
    return _021F0658;
}

const u8 *sub_021DC4C8(int *count)
{
    *count = 1;
    return _021F05F8;
}

const u8 *sub_021DC5EC(int *count)
{
    *count = 1;
    return _021F0700;
}

const u8 *sub_021DC5F8(int *count)
{
    *count = 2;
    return _021F0940;
}

const u8 *sub_021DC624(int *count)
{
    *count = 2;
    return _021F0950;
}

const u8 *sub_021DC658(int *count)
{
    *count = 1;
    return _021F06D0;
}

const u8 *sub_021DC694(int *count)
{
    *count = 1;
    return _021F0628;
}

const u8 *sub_021DC6EC(int *count)
{
    *count = 2;
    return _021F0990;
}

const u8 *sub_021DC814(int *count)
{
    *count = 3;
    return _021F0B48;
}

const u8 *sub_021DC87C(int *count)
{
    *count = 2;
    return _021F0A00;
}

const u8 *sub_021DC888(int *count)
{
    *count = 1;
    return _021F0770;
}

const u8 *sub_021DC8FC(int *count)
{
    *count = 1;
    return _021F05D0;
}

const u8 *sub_021DC954(int *count)
{
    *count = 1;
    return _021F05B0;
}

const u8 *sub_021DC9BC(int *count)
{
    *count = 1;
    return _021F0678;
}

const u8 *sub_021DCA8C(int *count)
{
    *count = 1;
    return _021F05C8;
}

const u8 *sub_021DCACC(int *count)
{
    *count = 1;
    return _021F0630;
}

const u8 *sub_021DCB2C(int *count)
{
    *count = 3;
    return _021F0AD0;
}

const u8 *sub_021DCBD0(int *count)
{
    *count = 1;
    return _021F0728;
}

const u8 *sub_021DCBDC(int *count)
{
    *count = 1;
    return _021F0680;
}

const u8 *sub_021DCC04(int *count)
{
    *count = 1;
    return _021F05E0;
}

const u8 *sub_021DCC50(int *count)
{
    *count = 1;
    return _021F0708;
}

const u8 *sub_021DCD14(int *count)
{
    *count = 3;
    return _021F0AE8;
}

const u8 *sub_021DCDB8(int *count)
{
    *count = 1;
    return _021F0750;
}

const u8 *sub_021DCDC4(int *count)
{
    *count = 3;
    return _021F0B60;
}

const u8 *sub_021DCE90(int *count)
{
    *count = 1;
    return _021F0760;
}

void sub_021DD05C(void *a0, void *a1, int a2)
{
    sub_021DD158(a0, a1, a2, 1);
}

void sub_021DD068(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 1);
}

const u8 *sub_021DD074(int *count)
{
    *count = 5;
    return _021F1AC4;
}

void sub_021DD080(void *a0, void *a1, int a2)
{
    sub_021DD158(a0, a1, a2, 2);
}

void sub_021DD08C(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 2);
}

const u8 *sub_021DD098(int *count)
{
    *count = 5;
    return _021F1AEC;
}

void sub_021DD0A4(void *a0, void *a1, int a2)
{
    sub_021DD158(a0, a1, a2, 4);
}

void sub_021DD0B0(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 4);
}

const u8 *sub_021DD0BC(int *count)
{
    *count = 5;
    return _021F1DE4;
}

void sub_021DD0C8(void *a0, void *a1, int a2)
{
    sub_021DD158(a0, a1, a2, 3);
}

void sub_021DD0D4(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 3);
}

const u8 *sub_021DD0E0(int *count)
{
    *count = 5;
    return _021F1B14;
}

void sub_021DD0EC(void *a0, void *a1, int a2)
{
    sub_021DD158(a0, a1, a2, 6);
}

void sub_021DD0F8(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 6);
}

const u8 *sub_021DD104(int *count)
{
    *count = 5;
    return _021F1B3C;
}

void sub_021DD110(void *a0, void *a1, int a2)
{
    sub_021DD158(a0, a1, a2, 5);
}

void sub_021DD11C(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 5);
}

const u8 *sub_021DD128(int *count)
{
    *count = 5;
    return _021F1B64;
}

void sub_021DD134(void *a0, void *a1, int a2)
{
    sub_021DD158(a0, a1, a2, 37);
}

void sub_021DD140(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 37);
}

const u8 *sub_021DD14C(int *count)
{
    *count = 5;
    return _021F1B8C;
}

const u8 *sub_021DD234(int *count)
{
    *count = 7;
    return _021F1E6C;
}

void sub_021DD320(void *a0, void *a1, int a2, UnkOwner *a3)
{
    if (a3->unk_18 != NULL) {
        sub_021DD39C(a0, a1, a2, a3, 1);
    }
}

const u8 *sub_021DD474(int *count)
{
    *count = 5;
    return _021F1BB4;
}

const u8 *sub_021DD570(int *count)
{
    *count = 4;
    return _021F1AA4;
}

const u8 *sub_021DD57C(int *count)
{
    *count = 5;
    return _021F1BDC;
}

const u8 *sub_021DD608(int *count)
{
    *count = 5;
    return _021F1C04;
}

void sub_021DD614(void *a0, void *a1, int a2, void *a3)
{
    sub_021DD7B8(a0, a1, a2, a3, 0);
}

void sub_021DD624(void *a0, void *a1, int a2, UnkOwner *a3)
{
    if (a3->unk_18 != NULL) {
        sub_021DD7B8(a0, a1, a2, a3, 0);
    }
}

const u8 *sub_021DD63C(int *count)
{
    *count = 5;
    return _021F1C2C;
}

void sub_021DD648(void *a0, void *a1, int a2, void *a3)
{
    sub_021DD7B8(a0, a1, a2, a3, 1);
}

void sub_021DD658(void *a0, void *a1, int a2, UnkOwner *a3)
{
    if (a3->unk_18 != NULL) {
        sub_021DD7B8(a0, a1, a2, a3, 1);
    }
}

const u8 *sub_021DD670(int *count)
{
    *count = 5;
    return _021F1C54;
}

void sub_021DD67C(void *a0, void *a1, int a2, void *a3)
{
    sub_021DD7B8(a0, a1, a2, a3, 2);
}

void sub_021DD68C(void *a0, void *a1, int a2, UnkOwner *a3)
{
    if (a3->unk_18 != NULL) {
        sub_021DD7B8(a0, a1, a2, a3, 2);
    }
}

const u8 *sub_021DD6A4(int *count)
{
    *count = 5;
    return _021F1C7C;
}

void sub_021DD6B0(void *a0, void *a1, int a2, void *a3)
{
    sub_021DD7B8(a0, a1, a2, a3, 3);
}

void sub_021DD6C0(void *a0, void *a1, int a2, UnkOwner *a3)
{
    if (a3->unk_18 != NULL) {
        sub_021DD7B8(a0, a1, a2, a3, 3);
    }
}

const u8 *sub_021DD6D8(int *count)
{
    *count = 5;
    return _021F1CA4;
}

void sub_021DD6E4(void *a0, void *a1, int a2, void *a3)
{
    sub_021DD7B8(a0, a1, a2, a3, 4);
}

void sub_021DD6F4(void *a0, void *a1, int a2, UnkOwner *a3)
{
    if (a3->unk_18 != NULL) {
        sub_021DD7B8(a0, a1, a2, a3, 4);
    }
}

const u8 *sub_021DD870(int *count)
{
    *count = 5;
    return _021F1CCC;
}

void sub_021DD87C(void *a0, void *a1, void *a2)
{
    sub_021DD9E8(a1, a2, 1, 1);
}

const u8 *sub_021DD88C(int *count)
{
    *count = 5;
    return _021F1CF4;
}

void sub_021DD898(void *a0, void *a1, void *a2)
{
    sub_021DD9E8(a1, a2, 2, 1);
}

const u8 *sub_021DD8A8(int *count)
{
    *count = 5;
    return _021F1D1C;
}

void sub_021DD8B4(void *a0, void *a1, void *a2)
{
    sub_021DD9E8(a1, a2, 5, 1);
}

const u8 *sub_021DD8C4(int *count)
{
    *count = 5;
    return _021F1D44;
}

void sub_021DD8D0(void *a0, void *a1, void *a2)
{
    sub_021DD9E8(a1, a2, 3, 1);
}

const u8 *sub_021DD8E0(int *count)
{
    *count = 5;
    return _021F1D6C;
}

void sub_021DD8EC(void *a0, void *a1, void *a2)
{
    sub_021DD9E8(a1, a2, 4, 1);
}

const u8 *sub_021DD8FC(int *count)
{
    *count = 5;
    return _021F1D94;
}

const u8 *sub_021DD980(int *count)
{
    *count = 5;
    return _021F1DBC;
}

const u8 *sub_021DDA1C(int *count)
{
    *count = 2;
    return _021F16CC;
}

const u8 *sub_021DDAB8(int *count)
{
    *count = 2;
    return _021F175C;
}

const u8 *sub_021DDAD8(int *count)
{
    *count = 2;
    return _021F177C;
}

const u8 *sub_021DDAF8(int *count)
{
    *count = 2;
    return _021F178C;
}

const u8 *sub_021DDB18(int *count)
{
    *count = 2;
    return _021F179C;
}

const u8 *sub_021DDB38(int *count)
{
    *count = 2;
    return _021F17AC;
}

const u8 *sub_021DDB58(int *count)
{
    *count = 2;
    return _021F171C;
}

const u8 *sub_021DDB78(int *count)
{
    *count = 2;
    return _021F17BC;
}

const u8 *sub_021DDB98(int *count)
{
    *count = 2;
    return _021F17CC;
}

const u8 *sub_021DDBB8(int *count)
{
    *count = 2;
    return _021F17DC;
}

const u8 *sub_021DDBD8(int *count)
{
    *count = 2;
    return _021F172C;
}

const u8 *sub_021DDBF8(int *count)
{
    *count = 2;
    return _021F17EC;
}

const u8 *sub_021DDC18(int *count)
{
    *count = 2;
    return _021F17FC;
}

const u8 *sub_021DDC38(int *count)
{
    *count = 2;
    return _021F180C;
}

const u8 *sub_021DDC58(int *count)
{
    *count = 2;
    return _021F181C;
}

const u8 *sub_021DDC78(int *count)
{
    *count = 2;
    return _021F182C;
}

const u8 *sub_021DDC98(int *count)
{
    *count = 2;
    return _021F183C;
}

const u8 *sub_021DDCB8(int *count)
{
    *count = 2;
    return _021F184C;
}

