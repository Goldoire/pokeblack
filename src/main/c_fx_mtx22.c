/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_mtx22.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define FX_InvAsync                          sub_0207C8A0
#define FX_GetDivResult                      sub_0207C86C
#define MTX_Identity22_  sub_0207AD40
#define MTX_Scale22_     sub_0207AD58
#define MTX_Rot22_       sub_0207AD64
#define MTX_ScaleApply22 sub_0207AD70
/* stripped or unplaced: MTX_Transpose22_ (24B) */
/* stripped or unplaced: MTX_Inverse22 (220B) */
/* stripped or unplaced: MTX_Concat22 (176B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_mtx22.c"
