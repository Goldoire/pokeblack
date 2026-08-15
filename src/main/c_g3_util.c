/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/g3_util.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MTX_FrustumW                         sub_0207C1D0
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
/* stripped or unplaced: G3i_PerspectiveW_ (92B) */
/* stripped or unplaced: G3i_OrthoW_ (100B) */
/* stripped or unplaced: G3_LoadTexMtxTexCoord (184B) */
/* stripped or unplaced: G3xx_LoadTexMtxTexCoord_ (124B) */
/* stripped or unplaced: G3BS_LoadTexMtxTexCoord (52B) */
/* stripped or unplaced: G3CS_LoadTexMtxTexCoord (160B) */
/* stripped or unplaced: G3_LoadTexMtxEnv (220B) */
/* stripped or unplaced: G3BS_LoadTexMtxEnv (280B) */
/* stripped or unplaced: G3CS_LoadTexMtxEnv (388B) */
/* stripped or unplaced: G3B_LoadTexMtxTexCoord (36B) */
/* stripped or unplaced: G3C_LoadTexMtxTexCoord (32B) */
/* stripped or unplaced: G3B_LoadTexMtxEnv (36B) */
/* stripped or unplaced: G3C_LoadTexMtxEnv (32B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/g3_util.c"
