/* lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_mtx33.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
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
/* not in shard or dead-stripped: MTX_Copy33To43_ (44B) */
/* not in shard or dead-stripped: MTX_Transpose33_ (28B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_mtx33.c"
