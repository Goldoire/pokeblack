/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_mtx33.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define FX_InvAsync                          sub_0207C8A0
#define FX_GetDivResult                      sub_0207C86C
#define MI_Copy36B                           sub_02082B60
#define MTX_Identity33_  sub_0207ADC4
#define MTX_Copy33To44_  sub_0207ADE8
#define MTX_Scale33_     sub_0207AE24
#define MTX_ScaleApply33 sub_0207AE38
#define MTX_RotX33_      sub_0207AF00
#define MTX_RotY33_      sub_0207AF1C
#define MTX_RotZ33_      sub_0207AF38
#define MTX_RotAxis33    sub_0207AF50
#define MTX_Inverse33    sub_0207B0A4
#define MTX_Concat33     sub_0207B388
#define MTX_MultVec33    sub_0207B51C
/* stripped or unplaced: MTX_Copy33To43_ (44B) */
/* stripped or unplaced: MTX_Transpose33_ (28B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_mtx33.c"
