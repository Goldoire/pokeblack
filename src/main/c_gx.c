/* lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gx.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define GX_InitGXState                       sub_02080CC4
#define OS_GetLockID                         sub_02084EC0
#define OS_Terminate                         sub_0208823C
#define MIi_DmaFill32                        sub_020821C0
#define MIi_CpuClear32                       sub_02082A7C
#define PMi_SetDispOffCount                  sub_0208C94C
#define MI_WaitDma                           sub_02082594
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C

#define GX_SetVCountEqVal        sub_0207D384
#define GX_DispOff               sub_0207D42C
#define GX_DispOn                sub_0207D46C
#define GX_SetGraphicsMode       sub_0207D4B0
#define GXS_SetGraphicsMode      sub_0207D518
#define GXx_SetMasterBrightness_ sub_0207D534
#define GXx_GetMasterBrightness_ sub_0207D55C
/* not in shard or dead-stripped: GX_Init (328B) */
/* not in shard or dead-stripped: GX_HBlankIntr (48B) */
/* not in shard or dead-stripped: GX_VBlankIntr (48B) */
/* not in shard or dead-stripped: GX_IsDispOn (16B) */
/* not in shard or dead-stripped: GX_SetDefaultDMA (68B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gx.c"
