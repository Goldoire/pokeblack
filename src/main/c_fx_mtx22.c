/* lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_mtx22.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define FX_InvAsync                          sub_0207C8A0
#define FX_GetDivResult                      sub_0207C86C

#define MTX_Identity22_  sub_0207AD40
#define MTX_Scale22_     sub_0207AD58
#define MTX_Rot22_       sub_0207AD64
#define MTX_ScaleApply22 sub_0207AD70
/* not in shard or dead-stripped: MTX_Transpose22_ (24B) */
/* not in shard or dead-stripped: MTX_Inverse22 (220B) */
/* not in shard or dead-stripped: MTX_Concat22 (176B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_mtx22.c"
