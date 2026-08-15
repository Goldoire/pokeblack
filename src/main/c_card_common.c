/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_common.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_DisableInterrupts                 sub_02087988
#define OS_SleepThread                       sub_020857B0
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_WakeupThread                      sub_02085800
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
/* stripped or unplaced: CARDi_GetAccessLevel (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_common.c"
