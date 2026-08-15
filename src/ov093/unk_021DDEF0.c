#include "types.h"

// ov093 0x021ddef0..0x021e01d4: per-effect wrapper
// shells and count/table getters.

extern const u8 _021F136C[];
extern const u8 _021F1374[];
extern const u8 _021F137C[];
extern const u8 _021F1384[];
extern const u8 _021F138C[];
extern const u8 _021F1394[];
extern const u8 _021F139C[];
extern const u8 _021F13A4[];
extern const u8 _021F13AC[];
extern const u8 _021F13B4[];
extern const u8 _021F13BC[];
extern const u8 _021F13C4[];
extern const u8 _021F13CC[];
extern const u8 _021F13D4[];
extern const u8 _021F13DC[];
extern const u8 _021F13E4[];
extern const u8 _021F13EC[];
extern const u8 _021F13F4[];
extern const u8 _021F13FC[];
extern const u8 _021F1404[];
extern const u8 _021F140C[];
extern const u8 _021F1414[];
extern const u8 _021F141C[];
extern const u8 _021F1424[];
extern const u8 _021F142C[];
extern const u8 _021F1434[];
extern const u8 _021F143C[];
extern const u8 _021F1444[];
extern const u8 _021F144C[];
extern const u8 _021F1454[];
extern const u8 _021F145C[];
extern const u8 _021F1464[];
extern const u8 _021F146C[];
extern const u8 _021F1474[];
extern const u8 _021F147C[];
extern const u8 _021F1484[];
extern const u8 _021F148C[];
extern const u8 _021F1494[];
extern const u8 _021F149C[];
extern const u8 _021F14A4[];
extern const u8 _021F14AC[];
extern const u8 _021F14B4[];
extern const u8 _021F14BC[];
extern const u8 _021F14C4[];
extern const u8 _021F14CC[];
extern const u8 _021F14D4[];
extern const u8 _021F14DC[];
extern const u8 _021F14E4[];
extern const u8 _021F14EC[];
extern const u8 _021F14F4[];
extern const u8 _021F14FC[];
extern const u8 _021F1504[];
extern const u8 _021F150C[];
extern const u8 _021F1514[];
extern const u8 _021F151C[];
extern const u8 _021F1524[];
extern const u8 _021F152C[];
extern const u8 _021F1534[];
extern const u8 _021F153C[];
extern const u8 _021F1544[];
extern const u8 _021F154C[];
extern const u8 _021F1554[];
extern const u8 _021F155C[];
extern const u8 _021F1564[];
extern const u8 _021F156C[];
extern const u8 _021F1574[];
extern const u8 _021F157C[];
extern const u8 _021F1584[];
extern const u8 _021F158C[];
extern const u8 _021F1594[];
extern const u8 _021F159C[];
extern const u8 _021F15A4[];
extern const u8 _021F15AC[];
extern const u8 _021F15B4[];
extern const u8 _021F15BC[];
extern const u8 _021F15C4[];
extern const u8 _021F15CC[];
extern const u8 _021F15D4[];
extern const u8 _021F15DC[];
extern const u8 _021F15E4[];
extern const u8 _021F15EC[];
extern const u8 _021F15FC[];
extern const u8 _021F160C[];
extern const u8 _021F161C[];
extern const u8 _021F162C[];
extern const u8 _021F163C[];
extern const u8 _021F164C[];
extern const u8 _021F165C[];
extern const u8 _021F166C[];
extern const u8 _021F167C[];
extern const u8 _021F168C[];
extern const u8 _021F169C[];
extern const u8 _021F16AC[];
extern const u8 _021F16BC[];
extern const u8 _021F16DC[];
extern const u8 _021F16EC[];
extern const u8 _021F16FC[];
extern const u8 _021F170C[];
extern const u8 _021F173C[];
extern const u8 _021F174C[];
extern const u8 _021F176C[];
extern const u8 _021F185C[];
extern const u8 _021F1874[];
extern const u8 _021F188C[];
extern const u8 _021F18A4[];
extern const u8 _021F18BC[];
extern const u8 _021F18D4[];
extern const u8 _021F18EC[];
extern const u8 _021F1904[];
extern const u8 _021F191C[];
extern const u8 _021F1934[];
extern const u8 _021F194C[];
extern const u8 _021F1964[];
extern const u8 _021F197C[];
extern const u8 _021F1994[];
extern const u8 _021F19AC[];
extern const u8 _021F19C4[];
extern const u8 _021F19DC[];
extern const u8 _021F19F4[];
extern const u8 _021F1A0C[];
extern const u8 _021F1A24[];
extern const u8 _021F1A3C[];
extern const u8 _021F1A54[];
extern const u8 _021F1A6C[];
extern const u8 _021F1A84[];
extern const u8 _021F1E0C[];
extern const u8 _021F1E3C[];

void sub_021DD19C(void *a0, void *a1, int a2, int a3);
void sub_021DE108(void *a0, void *a1, int a2, void *a3, int a4);
void sub_021DF4E0(void *a0, void *a1, int a2, int a3);
void sub_021DF93C(void *a0, void *a1, int a2, int a3);
void sub_021E01D4(void *a0, void *a1, int a2, void *a3, int a4);
void sub_021E0284(void *a0, void *a1, int a2, void *a3, int a4);

const u8 *sub_021DDEF0(int *count)
{
    *count = 2;
    return _021F15EC;
}

const u8 *sub_021DDF8C(int *count)
{
    *count = 6;
    return _021F1E0C;
}

const u8 *sub_021DE0D0(int *count)
{
    *count = 2;
    return _021F160C;
}

void sub_021DE0DC(void *a0, void *a1, int a2, void *a3)
{
    sub_021DE108(a0, a1, a2, a3, 1);
}

const u8 *sub_021DE0EC(int *count)
{
    *count = 2;
    return _021F162C;
}

void sub_021DE0F8(void *a0, void *a1, int a2, void *a3)
{
    sub_021DE108(a0, a1, a2, a3, 2);
}

const u8 *sub_021DE21C(int *count)
{
    *count = 6;
    return _021F1E3C;
}

const u8 *sub_021DE310(int *count)
{
    *count = 4;
    return _021F1A84;
}

void sub_021DE34C(void *a0, void *a1, int a2)
{
    sub_021DD19C(a0, a1, a2, 38);
}

const u8 *sub_021DE368(int *count)
{
    *count = 1;
    return _021F1564;
}

const u8 *sub_021DE3C8(int *count)
{
    *count = 1;
    return _021F156C;
}

const u8 *sub_021DE3F0(int *count)
{
    *count = 2;
    return _021F163C;
}

const u8 *sub_021DE494(int *count)
{
    *count = 1;
    return _021F1394;
}

const u8 *sub_021DE4B8(int *count)
{
    *count = 2;
    return _021F164C;
}

const u8 *sub_021DE520(int *count)
{
    *count = 2;
    return _021F165C;
}

const u8 *sub_021DE52C(int *count)
{
    *count = 1;
    return _021F1584;
}

const u8 *sub_021DE558(int *count)
{
    *count = 1;
    return _021F158C;
}

const u8 *sub_021DE58C(int *count)
{
    *count = 1;
    return _021F146C;
}

const u8 *sub_021DE5D0(int *count)
{
    *count = 1;
    return _021F13DC;
}

const u8 *sub_021DE614(int *count)
{
    *count = 1;
    return _021F13D4;
}

const u8 *sub_021DE65C(int *count)
{
    *count = 1;
    return _021F1474;
}

const u8 *sub_021DE6C0(int *count)
{
    *count = 1;
    return _021F13E4;
}

const u8 *sub_021DE700(int *count)
{
    *count = 1;
    return _021F148C;
}

const u8 *sub_021DE740(int *count)
{
    *count = 1;
    return _021F13EC;
}

const u8 *sub_021DE790(int *count)
{
    *count = 1;
    return _021F139C;
}

const u8 *sub_021DE7D8(int *count)
{
    *count = 1;
    return _021F1454;
}

const u8 *sub_021DE828(int *count)
{
    *count = 1;
    return _021F14AC;
}

const u8 *sub_021DE86C(int *count)
{
    *count = 2;
    return _021F16AC;
}

const u8 *sub_021DE8F0(int *count)
{
    *count = 1;
    return _021F13A4;
}

const u8 *sub_021DE93C(int *count)
{
    *count = 3;
    return _021F18D4;
}

const u8 *sub_021DE974(int *count)
{
    *count = 3;
    return _021F18EC;
}

const u8 *sub_021DE9AC(int *count)
{
    *count = 3;
    return _021F1904;
}

const u8 *sub_021DEA4C(int *count)
{
    *count = 2;
    return _021F16BC;
}

const u8 *sub_021DEAE8(int *count)
{
    *count = 3;
    return _021F191C;
}

const u8 *sub_021DEBA8(int *count)
{
    *count = 1;
    return _021F150C;
}

const u8 *sub_021DEBE0(int *count)
{
    *count = 2;
    return _021F16DC;
}

const u8 *sub_021DEC64(int *count)
{
    *count = 1;
    return _021F13BC;
}

const u8 *sub_021DED1C(int *count)
{
    *count = 1;
    return _021F1384;
}

const u8 *sub_021DED60(int *count)
{
    *count = 1;
    return _021F152C;
}

const u8 *sub_021DEDEC(int *count)
{
    *count = 1;
    return _021F143C;
}

const u8 *sub_021DEE3C(int *count)
{
    *count = 3;
    return _021F197C;
}

const u8 *sub_021DEEF0(int *count)
{
    *count = 2;
    return _021F16EC;
}

const u8 *sub_021DEFB8(int *count)
{
    *count = 1;
    return _021F14B4;
}

const u8 *sub_021DF0B8(int *count)
{
    *count = 1;
    return _021F154C;
}

const u8 *sub_021DF144(int *count)
{
    *count = 2;
    return _021F16FC;
}

const u8 *sub_021DF240(int *count)
{
    *count = 1;
    return _021F138C;
}

const u8 *sub_021DF24C(int *count)
{
    *count = 1;
    return _021F1434;
}

const u8 *sub_021DF258(int *count)
{
    *count = 1;
    return _021F15A4;
}

const u8 *sub_021DF264(int *count)
{
    *count = 1;
    return _021F1554;
}

const u8 *sub_021DF270(int *count)
{
    *count = 1;
    return _021F15B4;
}

const u8 *sub_021DF27C(int *count)
{
    *count = 1;
    return _021F15C4;
}

const u8 *sub_021DF2A4(int *count)
{
    *count = 1;
    return _021F15CC;
}

const u8 *sub_021DF2B0(int *count)
{
    *count = 1;
    return _021F147C;
}

const u8 *sub_021DF2BC(int *count)
{
    *count = 1;
    return _021F136C;
}

const u8 *sub_021DF2C8(int *count)
{
    *count = 1;
    return _021F15D4;
}

const u8 *sub_021DF2D4(int *count)
{
    *count = 1;
    return _021F13CC;
}

const u8 *sub_021DF2E0(int *count)
{
    *count = 1;
    return _021F1494;
}

const u8 *sub_021DF2EC(int *count)
{
    *count = 1;
    return _021F149C;
}

const u8 *sub_021DF2F8(int *count)
{
    *count = 1;
    return _021F14E4;
}

const u8 *sub_021DF304(int *count)
{
    *count = 1;
    return _021F1594;
}

const u8 *sub_021DF310(int *count)
{
    *count = 1;
    return _021F13F4;
}

const u8 *sub_021DF31C(int *count)
{
    *count = 1;
    return _021F14A4;
}

const u8 *sub_021DF328(int *count)
{
    *count = 1;
    return _021F1574;
}

const u8 *sub_021DF334(int *count)
{
    *count = 1;
    return _021F1374;
}

const u8 *sub_021DF340(int *count)
{
    *count = 1;
    return _021F14D4;
}

const u8 *sub_021DF34C(int *count)
{
    *count = 1;
    return _021F14EC;
}

const u8 *sub_021DF358(int *count)
{
    *count = 1;
    return _021F1424;
}

const u8 *sub_021DF364(int *count)
{
    *count = 1;
    return _021F153C;
}

const u8 *sub_021DF390(int *count)
{
    *count = 2;
    return _021F15FC;
}

const u8 *sub_021DF3F8(int *count)
{
    *count = 2;
    return _021F161C;
}

const u8 *sub_021DF42C(int *count)
{
    *count = 1;
    return _021F1534;
}

const u8 *sub_021DF480(int *count)
{
    *count = 1;
    return _021F145C;
}

void sub_021DF48C(void *a0, void *a1, int a2)
{
    sub_021DF4E0(a0, a1, a2, 3);
}

const u8 *sub_021DF498(int *count)
{
    *count = 1;
    return _021F1464;
}

void sub_021DF4A4(void *a0, void *a1, int a2)
{
    sub_021DF4E0(a0, a1, a2, 4);
}

const u8 *sub_021DF4B0(int *count)
{
    *count = 1;
    return _021F151C;
}

void sub_021DF4BC(void *a0, void *a1, int a2)
{
    sub_021DF4E0(a0, a1, a2, 1);
}

const u8 *sub_021DF4C8(int *count)
{
    *count = 1;
    return _021F1514;
}

void sub_021DF4D4(void *a0, void *a1, int a2)
{
    sub_021DF4E0(a0, a1, a2, 2);
}

const u8 *sub_021DF510(int *count)
{
    *count = 2;
    return _021F167C;
}

const u8 *sub_021DF588(int *count)
{
    *count = 2;
    return _021F168C;
}

const u8 *sub_021DF634(int *count)
{
    *count = 2;
    return _021F169C;
}

const u8 *sub_021DF6EC(int *count)
{
    *count = 1;
    return _021F14F4;
}

void sub_021DF6F8(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 6);
}

const u8 *sub_021DF704(int *count)
{
    *count = 1;
    return _021F13FC;
}

void sub_021DF710(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 4);
}

const u8 *sub_021DF71C(int *count)
{
    *count = 1;
    return _021F13AC;
}

void sub_021DF728(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 5);
}

const u8 *sub_021DF734(int *count)
{
    *count = 1;
    return _021F137C;
}

void sub_021DF740(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 11);
}

const u8 *sub_021DF74C(int *count)
{
    *count = 1;
    return _021F13B4;
}

void sub_021DF758(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 16);
}

const u8 *sub_021DF764(int *count)
{
    *count = 1;
    return _021F142C;
}

void sub_021DF770(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 1);
}

const u8 *sub_021DF77C(int *count)
{
    *count = 1;
    return _021F14C4;
}

void sub_021DF788(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 12);
}

const u8 *sub_021DF794(int *count)
{
    *count = 1;
    return _021F13C4;
}

void sub_021DF7A0(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 8);
}

const u8 *sub_021DF7AC(int *count)
{
    *count = 1;
    return _021F1444;
}

void sub_021DF7B8(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 10);
}

const u8 *sub_021DF7C4(int *count)
{
    *count = 1;
    return _021F144C;
}

void sub_021DF7D0(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 2);
}

const u8 *sub_021DF7DC(int *count)
{
    *count = 2;
    return _021F170C;
}

void sub_021DF7E8(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 3);
}

const u8 *sub_021DF834(int *count)
{
    *count = 1;
    return _021F15AC;
}

void sub_021DF840(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 14);
}

const u8 *sub_021DF84C(int *count)
{
    *count = 1;
    return _021F15BC;
}

void sub_021DF858(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 7);
}

const u8 *sub_021DF864(int *count)
{
    *count = 1;
    return _021F1484;
}

void sub_021DF870(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 13);
}

const u8 *sub_021DF87C(int *count)
{
    *count = 1;
    return _021F15E4;
}

void sub_021DF888(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 9);
}

const u8 *sub_021DF894(int *count)
{
    *count = 1;
    return _021F15DC;
}

void sub_021DF8A0(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 15);
}

const u8 *sub_021DF8AC(int *count)
{
    *count = 1;
    return _021F159C;
}

void sub_021DF8B8(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 0);
}

const u8 *sub_021DF8C4(int *count)
{
    *count = 1;
    return _021F155C;
}

void sub_021DF8D0(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 13);
}

const u8 *sub_021DF8DC(int *count)
{
    *count = 1;
    return _021F1404;
}

void sub_021DF8E8(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 5);
}

const u8 *sub_021DF8F4(int *count)
{
    *count = 1;
    return _021F1544;
}

void sub_021DF900(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 10);
}

const u8 *sub_021DF90C(int *count)
{
    *count = 1;
    return _021F14DC;
}

void sub_021DF918(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 10);
}

const u8 *sub_021DF924(int *count)
{
    *count = 1;
    return _021F1414;
}

void sub_021DF930(void *a0, void *a1, int a2)
{
    sub_021DF93C(a0, a1, a2, 11);
}

const u8 *sub_021DF968(int *count)
{
    *count = 1;
    return _021F141C;
}

const u8 *sub_021DF9BC(int *count)
{
    *count = 1;
    return _021F157C;
}

const u8 *sub_021DFA14(int *count)
{
    *count = 2;
    return _021F166C;
}

const u8 *sub_021DFA54(int *count)
{
    *count = 1;
    return _021F1504;
}

const u8 *sub_021DFA7C(int *count)
{
    *count = 1;
    return _021F14FC;
}

const u8 *sub_021DFAB0(int *count)
{
    *count = 1;
    return _021F140C;
}

const u8 *sub_021DFB40(int *count)
{
    *count = 3;
    return _021F1934;
}

const u8 *sub_021DFBF4(int *count)
{
    *count = 1;
    return _021F14CC;
}

const u8 *sub_021DFCAC(int *count)
{
    *count = 1;
    return _021F14BC;
}

const u8 *sub_021DFCDC(int *count)
{
    *count = 1;
    return _021F1524;
}

const u8 *sub_021DFD14(int *count)
{
    *count = 2;
    return _021F173C;
}

const u8 *sub_021DFD98(int *count)
{
    *count = 2;
    return _021F174C;
}

const u8 *sub_021DFE1C(int *count)
{
    *count = 2;
    return _021F176C;
}

const u8 *sub_021DFEE8(int *count)
{
    *count = 3;
    return _021F1A3C;
}

void sub_021DFEF4(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 9);
}

void sub_021DFF04(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 9);
}

const u8 *sub_021DFF14(int *count)
{
    *count = 3;
    return _021F1A54;
}

void sub_021DFF20(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 10);
}

void sub_021DFF30(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 10);
}

const u8 *sub_021DFF40(int *count)
{
    *count = 3;
    return _021F1874;
}

void sub_021DFF4C(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 12);
}

void sub_021DFF5C(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 12);
}

const u8 *sub_021DFF6C(int *count)
{
    *count = 3;
    return _021F18A4;
}

void sub_021DFF78(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 11);
}

void sub_021DFF88(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 11);
}

const u8 *sub_021DFF98(int *count)
{
    *count = 3;
    return _021F18BC;
}

void sub_021DFFA4(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 14);
}

void sub_021DFFB4(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 14);
}

const u8 *sub_021DFFC4(int *count)
{
    *count = 3;
    return _021F194C;
}

void sub_021DFFD0(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 1);
}

void sub_021DFFE0(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 1);
}

const u8 *sub_021DFFF0(int *count)
{
    *count = 3;
    return _021F1994;
}

void sub_021DFFFC(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 3);
}

void sub_021E000C(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 3);
}

const u8 *sub_021E001C(int *count)
{
    *count = 3;
    return _021F19AC;
}

void sub_021E0028(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 4);
}

void sub_021E0038(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 4);
}

const u8 *sub_021E0048(int *count)
{
    *count = 3;
    return _021F1A24;
}

void sub_021E0054(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 2);
}

void sub_021E0064(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 2);
}

const u8 *sub_021E0074(int *count)
{
    *count = 3;
    return _021F1A6C;
}

void sub_021E0080(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 13);
}

void sub_021E0090(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 13);
}

const u8 *sub_021E00A0(int *count)
{
    *count = 3;
    return _021F185C;
}

void sub_021E00AC(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 6);
}

void sub_021E00BC(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 6);
}

const u8 *sub_021E00CC(int *count)
{
    *count = 3;
    return _021F1964;
}

void sub_021E00D8(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 5);
}

void sub_021E00E8(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 5);
}

const u8 *sub_021E00F8(int *count)
{
    *count = 3;
    return _021F19DC;
}

void sub_021E0104(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 7);
}

void sub_021E0114(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 7);
}

const u8 *sub_021E0124(int *count)
{
    *count = 3;
    return _021F1A0C;
}

void sub_021E0130(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 15);
}

void sub_021E0140(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 15);
}

const u8 *sub_021E0150(int *count)
{
    *count = 3;
    return _021F188C;
}

void sub_021E015C(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 16);
}

void sub_021E016C(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 16);
}

const u8 *sub_021E017C(int *count)
{
    *count = 3;
    return _021F19F4;
}

void sub_021E0188(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 8);
}

void sub_021E0198(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 8);
}

const u8 *sub_021E01A8(int *count)
{
    *count = 3;
    return _021F19C4;
}

void sub_021E01B4(void *a0, void *a1, int a2, void *a3)
{
    sub_021E01D4(a0, a1, a2, a3, 0);
}

void sub_021E01C4(void *a0, void *a1, int a2, void *a3)
{
    sub_021E0284(a0, a1, a2, a3, 0);
}

