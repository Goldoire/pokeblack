/* lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_cp.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define FX_Div               sub_0207C768
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
/* not in shard or dead-stripped: FX_Inv (16B) */
/* not in shard or dead-stripped: FX_InvFx64c (44B) */
/* not in shard or dead-stripped: FX_SqrtAsyncImm (40B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_cp.c"
