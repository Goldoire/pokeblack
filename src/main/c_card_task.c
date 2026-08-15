/* lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_task.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_DisableInterrupts                 sub_02087988
#define OS_WakeupThread                      sub_02085800
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_SetThreadPriority                 sub_02085988
#define OS_WakeupThreadDirect                sub_02085868

#define CARDi_ExecuteOldTypeTask  sub_02076170
#define CARDi_OldTypeTaskThread   sub_020761E4
#define CARDi_WaitForTask         sub_02076230
#define CARDi_EndTask             sub_020762A8
/* not in shard or dead-stripped: CARDi_InitTaskQueue (32B) */
/* not in shard or dead-stripped: CARDi_InitTask (32B) */
/* not in shard or dead-stripped: CARDi_ProcessTask (208B) */
/* not in shard or dead-stripped: CARDi_ReceiveTask (112B) */
/* not in shard or dead-stripped: CARDi_TaskWorkerProcedure (76B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_task.c"
