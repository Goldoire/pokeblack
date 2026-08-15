/* lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_mtx44.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MI_Copy48B                           sub_02082B7C
#define FX_InvAsync                          sub_0207C8A0
#define FX_GetDivResultFx64c                 sub_0207C848
#define _ll_sdiv                             sub_0209BE64
#define FX_GetDivResult                      sub_0207C86C

#define MTX_Identity44_  sub_0207BDB4
#define MTX_Copy44To33_  sub_0207BDEC
#define MTX_Concat44     sub_0207BE14
#define MTX_FrustumW     sub_0207C1D0
#define MTX_OrthoW       sub_0207C554
/* not in shard or dead-stripped: MTX_Copy44To43_ (52B) */
/* not in shard or dead-stripped: MTX_TransApply44 (216B) */
/* not in shard or dead-stripped: MTX_Transpose44_ (52B) */
/* not in shard or dead-stripped: MTX_Scale44_ (30B) */
/* not in shard or dead-stripped: MTX_ScaleApply44 (292B) */
/* not in shard or dead-stripped: MTX_RotX44_ (36B) */
/* not in shard or dead-stripped: MTX_RotY44_ (36B) */
/* not in shard or dead-stripped: MTX_RotZ44_ (34B) */
/* not in shard or dead-stripped: MTX_RotAxis44 (376B) */
/* not in shard or dead-stripped: MTX_PerspectiveW (340B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_mtx44.c"
