/* lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gx_load2d.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
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
#define GX_ResetBankForBGExtPltt             sub_0208091C
#define MIi_DmaCopy32Async                   sub_02082498
#define MI_WaitDma                           sub_02082594
#define GX_ResetBankForOBJExtPltt            sub_02080940
#define GX_ResetBankForSubOBJExtPltt         sub_020809F0

#define GX_BeginLoadBGExtPltt   sub_0207F308
#define GX_BeginLoadOBJExtPltt  sub_0207F47C
#define GXS_BeginLoadOBJExtPltt sub_0207F6A8
/* not in shard or dead-stripped: GX_LoadBGPltt (100B) */
/* not in shard or dead-stripped: GXS_LoadBGPltt (92B) */
/* not in shard or dead-stripped: GX_LoadOBJPltt (92B) */
/* not in shard or dead-stripped: GXS_LoadOBJPltt (92B) */
/* not in shard or dead-stripped: GX_LoadOAM (100B) */
/* not in shard or dead-stripped: GXS_LoadOAM (92B) */
/* not in shard or dead-stripped: GX_LoadOBJ (100B) */
/* not in shard or dead-stripped: GXS_LoadOBJ (100B) */
/* not in shard or dead-stripped: GX_LoadBG0Scr (112B) */
/* not in shard or dead-stripped: GXS_LoadBG0Scr (112B) */
/* not in shard or dead-stripped: GX_LoadBG1Scr (112B) */
/* not in shard or dead-stripped: GXS_LoadBG1Scr (112B) */
/* not in shard or dead-stripped: GX_LoadBG2Scr (112B) */
/* not in shard or dead-stripped: GXS_LoadBG2Scr (112B) */
/* not in shard or dead-stripped: GX_LoadBG3Scr (112B) */
/* not in shard or dead-stripped: GXS_LoadBG3Scr (112B) */
/* not in shard or dead-stripped: GX_LoadBG0Char (112B) */
/* not in shard or dead-stripped: GXS_LoadBG0Char (112B) */
/* not in shard or dead-stripped: GX_LoadBG1Char (112B) */
/* not in shard or dead-stripped: GXS_LoadBG1Char (112B) */
/* not in shard or dead-stripped: GX_LoadBG2Char (112B) */
/* not in shard or dead-stripped: GXS_LoadBG2Char (112B) */
/* not in shard or dead-stripped: GX_LoadBG3Char (112B) */
/* not in shard or dead-stripped: GXS_LoadBG3Char (112B) */
/* not in shard or dead-stripped: GX_LoadBGExtPltt (116B) */
/* not in shard or dead-stripped: GX_EndLoadBGExtPltt (64B) */
/* not in shard or dead-stripped: GX_LoadOBJExtPltt (112B) */
/* not in shard or dead-stripped: GX_EndLoadOBJExtPltt (60B) */
/* not in shard or dead-stripped: GXS_BeginLoadBGExtPltt (24B) */
/* not in shard or dead-stripped: GXS_LoadBGExtPltt (104B) */
/* not in shard or dead-stripped: GXS_EndLoadBGExtPltt (56B) */
/* not in shard or dead-stripped: GXS_LoadOBJExtPltt (104B) */
/* not in shard or dead-stripped: GXS_EndLoadOBJExtPltt (56B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gx_load2d.c"
