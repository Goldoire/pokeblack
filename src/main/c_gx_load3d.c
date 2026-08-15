/* lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gx_load3d.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MIi_DmaCopy32                        sub_02082244
#define MIi_CpuCopy32                        sub_02082A90
#define MIi_DmaCopy32Async                   sub_02082498
#define GX_ResetBankForTex                   sub_0208096C
#define MI_WaitDma                           sub_02082594
#define GX_ResetBankForTexPltt               sub_02080980
#define GX_ResetBankForClearImage            sub_02080994

#define GX_BeginLoadTex        sub_0207F7A0
#define GX_BeginLoadTexPltt    sub_0207FA0C
#define GX_BeginLoadClearImage sub_0207FB2C
/* not in shard or dead-stripped: GX_LoadTexEx (344B) */
/* not in shard or dead-stripped: GX_LoadTex (332B) */
/* not in shard or dead-stripped: GX_EndLoadTex (68B) */
/* not in shard or dead-stripped: GX_LoadTexPlttEx (108B) */
/* not in shard or dead-stripped: GX_LoadTexPltt (112B) */
/* not in shard or dead-stripped: GX_EndLoadTexPltt (60B) */
/* not in shard or dead-stripped: GX_LoadClearImageColor (108B) */
/* not in shard or dead-stripped: GX_LoadClearImageDepth (112B) */
/* not in shard or dead-stripped: GX_EndLoadClearImage (60B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gx_load3d.c"
