/* lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_common.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_DisableInterrupts                 sub_02087988
#define OS_Terminate                         sub_0208823C
#define OS_SleepThread                       sub_020857B0
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_WakeupThread                      sub_02085800
#define OS_GetBootType                       sub_02087B04
#define CARDi_WaitForTask                    sub_02076230
#define MIi_CpuClearFast                     sub_02082AC0
#define DC_FlushRange                        sub_020862F0
#define PXI_SetFifoRecvCallback              sub_020885A0

#define CARDi_LockResource     sub_02075ED4
#define CARDi_UnlockResource   sub_02075F4C
#define CARDi_WaitAsync        sub_02076050
#define CARDi_TryWaitAsync     sub_02076070
#define CARDi_InitResourceLock sub_0207608C
#define CARDi_InitCommand      sub_020760B4
/* not in shard or dead-stripped: CARDi_GetAccessLevel (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_common.c"
