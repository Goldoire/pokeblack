/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_task.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_DisableInterrupts                 sub_02087988
#define OS_WakeupThread                      sub_02085800
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_GetThreadPriority                 sub_02085A30
#define OS_SetThreadPriority                 sub_02085988
#define OS_SleepThread                       sub_020857B0
#define OS_WakeupThreadDirect                sub_02085868
#define CARDi_ExecuteOldTypeTask  sub_02076170
#define CARDi_OldTypeTaskThread   sub_020761E4
#define CARDi_WaitForTask         sub_02076230
#define CARDi_EndTask             sub_020762A8
/* stripped or unplaced: CARDi_InitTaskQueue (32B) */
/* stripped or unplaced: CARDi_InitTask (32B) */
/* stripped or unplaced: CARDi_ProcessTask (208B) */
/* stripped or unplaced: CARDi_ReceiveTask (112B) */
/* stripped or unplaced: CARDi_TaskWorkerProcedure (76B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_task.c"
