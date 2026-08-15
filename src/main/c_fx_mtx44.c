/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_mtx44.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MI_Copy48B                           sub_02082B7C
#define FX_InvAsync                          sub_0207C8A0
#define FX_GetDivResultFx64c                 sub_0207C848
#define _ll_sdiv                             sub_0209BE64
#define FX_Div                               sub_0207C770
#define FX_GetDivResult                      sub_0207C86C
#define MTX_Identity44_  sub_0207BDB4
#define MTX_Copy44To33_  sub_0207BDEC
#define MTX_Concat44     sub_0207BE14
#define MTX_FrustumW     sub_0207C1D0
#define MTX_OrthoW       sub_0207C554
/* stripped or unplaced: MTX_Copy44To43_ (52B) */
/* stripped or unplaced: MTX_TransApply44 (216B) */
/* stripped or unplaced: MTX_Transpose44_ (52B) */
/* stripped or unplaced: MTX_Scale44_ (30B) */
/* stripped or unplaced: MTX_ScaleApply44 (292B) */
/* stripped or unplaced: MTX_RotX44_ (36B) */
/* stripped or unplaced: MTX_RotY44_ (36B) */
/* stripped or unplaced: MTX_RotZ44_ (34B) */
/* stripped or unplaced: MTX_RotAxis44 (376B) */
/* stripped or unplaced: MTX_PerspectiveW (340B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_mtx44.c"
