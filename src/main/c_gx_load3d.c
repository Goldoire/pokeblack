/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gx_load3d.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MIi_DmaCopy32                        sub_02082244
#define MIi_CpuCopy32                        sub_02082A90
#define MIi_DmaCopy32Async                   sub_02082498
#define MI_WaitDma                           sub_02082594
#define GX_BeginLoadTex        sub_0207F7A0
#define GX_BeginLoadTexPltt    sub_0207FA0C
#define GX_BeginLoadClearImage sub_0207FB2C
/* stripped or unplaced: GX_LoadTexEx (344B) */
/* stripped or unplaced: GX_LoadTex (332B) */
/* stripped or unplaced: GX_EndLoadTex (68B) */
/* stripped or unplaced: GX_LoadTexPlttEx (108B) */
/* stripped or unplaced: GX_LoadTexPltt (112B) */
/* stripped or unplaced: GX_EndLoadTexPltt (60B) */
/* stripped or unplaced: GX_LoadClearImageColor (108B) */
/* stripped or unplaced: GX_LoadClearImageDepth (112B) */
/* stripped or unplaced: GX_EndLoadClearImage (60B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gx_load3d.c"
