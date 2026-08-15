/* lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/g3_util.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MTX_FrustumW                         sub_0207C554
#define G3_LoadMtx44                         sub_0207D8C4
#define MTX_OrthoW                           sub_0207C554
#define MTX_LookAt                           sub_0207BCA0
#define G3_LoadMtx43                         sub_0207D8E0
#define MI_Copy32B                           sub_02082B44

#define G3i_FrustumW_            sub_0207D760
#define G3i_LookAt_              sub_0207D7C4
#define G3_RotX                  sub_0207D810
#define G3_RotY                  sub_0207D84C
#define G3_RotZ                  sub_0207D888
/* not in shard or dead-stripped: G3i_PerspectiveW_ (92B) */
/* not in shard or dead-stripped: G3i_OrthoW_ (100B) */
/* not in shard or dead-stripped: G3_LoadTexMtxTexCoord (184B) */
/* not in shard or dead-stripped: G3xx_LoadTexMtxTexCoord_ (124B) */
/* not in shard or dead-stripped: G3BS_LoadTexMtxTexCoord (52B) */
/* not in shard or dead-stripped: G3CS_LoadTexMtxTexCoord (160B) */
/* not in shard or dead-stripped: G3_LoadTexMtxEnv (220B) */
/* not in shard or dead-stripped: G3BS_LoadTexMtxEnv (280B) */
/* not in shard or dead-stripped: G3CS_LoadTexMtxEnv (388B) */
/* not in shard or dead-stripped: G3B_LoadTexMtxTexCoord (36B) */
/* not in shard or dead-stripped: G3C_LoadTexMtxTexCoord (32B) */
/* not in shard or dead-stripped: G3B_LoadTexMtxEnv (36B) */
/* not in shard or dead-stripped: G3C_LoadTexMtxEnv (32B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/g3_util.c"
