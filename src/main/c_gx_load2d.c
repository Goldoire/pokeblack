/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gx_load2d.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MIi_DmaCopy16                        sub_020822E8
#define MIi_CpuCopy16                        sub_02082A60
#define MIi_DmaCopy32                        sub_02082244
#define MIi_CpuCopy32                        sub_02082A90
#define G2_GetBG0ScrPtr                      sub_0207DF60
#define G2S_GetBG0ScrPtr                     sub_0207DF94
#define G2_GetBG1ScrPtr                      sub_0207DFB4
#define G2S_GetBG1ScrPtr                     sub_0207DFE8
#define G2_GetBG2ScrPtr                      sub_0207E008
#define G2S_GetBG2ScrPtr                     sub_0207E08C
#define G2_GetBG3ScrPtr                      sub_0207E100
#define G2S_GetBG3ScrPtr                     sub_0207E184
#define G2_GetBG0CharPtr                     sub_0207E1F8
#define G2S_GetBG0CharPtr                    sub_0207E22C
#define G2_GetBG1CharPtr                     sub_0207E24C
#define G2S_GetBG1CharPtr                    sub_0207E280
#define G2_GetBG2CharPtr                     sub_0207E2A0
#define G2S_GetBG2CharPtr                    sub_0207E2F0
#define G2_GetBG3CharPtr                     sub_0207E330
#define G2S_GetBG3CharPtr                    sub_0207E388
#define GX_ResetBankForBGExtPltt             sub_02080924
#define MIi_DmaCopy32Async                   sub_02082498
#define MI_WaitDma                           sub_02082594
#define GX_ResetBankForOBJExtPltt            sub_02080948
#define GX_ResetBankForSubBGExtPltt          sub_0203135C
#define GX_ResetBankForSubOBJExtPltt         sub_020809F8
#define GX_BeginLoadBGExtPltt   sub_0207F308
#define GX_BeginLoadOBJExtPltt  sub_0207F47C
#define GXS_BeginLoadOBJExtPltt sub_0207F6A8
/* stripped or unplaced: GX_LoadBGPltt (100B) */
/* stripped or unplaced: GXS_LoadBGPltt (92B) */
/* stripped or unplaced: GX_LoadOBJPltt (92B) */
/* stripped or unplaced: GXS_LoadOBJPltt (92B) */
/* stripped or unplaced: GX_LoadOAM (100B) */
/* stripped or unplaced: GXS_LoadOAM (92B) */
/* stripped or unplaced: GX_LoadOBJ (100B) */
/* stripped or unplaced: GXS_LoadOBJ (100B) */
/* stripped or unplaced: GX_LoadBG0Scr (112B) */
/* stripped or unplaced: GXS_LoadBG0Scr (112B) */
/* stripped or unplaced: GX_LoadBG1Scr (112B) */
/* stripped or unplaced: GXS_LoadBG1Scr (112B) */
/* stripped or unplaced: GX_LoadBG2Scr (112B) */
/* stripped or unplaced: GXS_LoadBG2Scr (112B) */
/* stripped or unplaced: GX_LoadBG3Scr (112B) */
/* stripped or unplaced: GXS_LoadBG3Scr (112B) */
/* stripped or unplaced: GX_LoadBG0Char (112B) */
/* stripped or unplaced: GXS_LoadBG0Char (112B) */
/* stripped or unplaced: GX_LoadBG1Char (112B) */
/* stripped or unplaced: GXS_LoadBG1Char (112B) */
/* stripped or unplaced: GX_LoadBG2Char (112B) */
/* stripped or unplaced: GXS_LoadBG2Char (112B) */
/* stripped or unplaced: GX_LoadBG3Char (112B) */
/* stripped or unplaced: GXS_LoadBG3Char (112B) */
/* stripped or unplaced: GX_LoadBGExtPltt (116B) */
/* stripped or unplaced: GX_EndLoadBGExtPltt (64B) */
/* stripped or unplaced: GX_LoadOBJExtPltt (112B) */
/* stripped or unplaced: GX_EndLoadOBJExtPltt (60B) */
/* stripped or unplaced: GXS_BeginLoadBGExtPltt (24B) */
/* stripped or unplaced: GXS_LoadBGExtPltt (104B) */
/* stripped or unplaced: GXS_EndLoadBGExtPltt (56B) */
/* stripped or unplaced: GXS_LoadOBJExtPltt (104B) */
/* stripped or unplaced: GXS_EndLoadOBJExtPltt (56B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gx_load2d.c"
