/* lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_mtx43.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MI_Copy36B                           sub_02082B60
#define MTX_ScaleApply33                     sub_0207AE38
#define MTX_RotAxis33                        sub_0207AF50
#define FX_InvAsync                          sub_0207C8A0
#define FX_GetDivResult                      sub_0207C86C
#define MI_Copy48B                           sub_02082B7C
#define VEC_Normalize                        sub_0207CCA4
#define VEC_CrossProduct                     sub_0207CAE8
#define VEC_DotProduct                       sub_0207CA68

#define MTX_Identity43_  sub_0207B598
#define MTX_Copy43To44_  sub_0207B5C0
#define MTX_Scale43_     sub_0207B5F4
#define MTX_ScaleApply43 sub_0207B60C
#define MTX_RotY43_      sub_0207B640
#define MTX_RotAxis43    sub_0207B65C
#define MTX_Inverse43    sub_0207B67C
#define MTX_Concat43     sub_0207B9F0
#define MTX_MultVec43    sub_0207BC08
#define MTX_LookAt       sub_0207BCA0
/* not in shard or dead-stripped: MTX_Transpose43_ (44B) */
/* not in shard or dead-stripped: MTX_TransApply43 (172B) */
/* not in shard or dead-stripped: MTX_RotX43_ (30B) */
/* not in shard or dead-stripped: MTX_RotZ43_ (26B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_mtx43.c"
