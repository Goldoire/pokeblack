/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_cp.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define FX_DivFx64c          sub_0207C788
#define FX_Sqrt              sub_0207C7B4
#define FX_InvSqrt           sub_0207C7E8
#define FX_GetDivResultFx64c sub_0207C848
#define FX_GetDivResult      sub_0207C86C
#define FX_InvAsync          sub_0207C8A0
#define FX_SqrtAsync         sub_0207C8D0
#define FX_GetSqrtResult     sub_0207C904
#define FX_DivAsync          sub_0207C930
#define FX_DivS32            sub_0207C958
#define FX_ModS32            sub_0207C994
/* stripped or unplaced: FX_Div (16B) */
/* stripped or unplaced: FX_Inv (16B) */
/* stripped or unplaced: FX_InvFx64c (44B) */
/* stripped or unplaced: FX_SqrtAsyncImm (40B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_cp.c"
