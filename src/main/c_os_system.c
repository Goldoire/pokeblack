/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_system.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_Halt                              sub_020882D0
#define SVC_WaitByLoop                       sub_02004490
#define OS_WaitIrq                           sub_0208459C

#define OS_EnableInterrupts            sub_02087974
#define OS_DisableInterrupts           sub_02087988
#define OS_RestoreInterrupts           sub_0208799C
#define OS_DisableInterrupts_IrqAndFiq sub_020879B4
#define OS_RestoreInterrupts_IrqAndFiq sub_020879C8
#define OS_GetCpsrIrq                  sub_020879E0
#define OS_GetProcMode                 sub_020879EC
#define OS_WaitInterrupt               sub_02087A3C
#define OS_WaitVBlankIntr              sub_02087AE4
/* not in shard or dead-stripped: OS_EnableInterrupts_IrqAndFiq (20B) */
/* not in shard or dead-stripped: OS_SpinWaitCpuCycles (12B) */
/* not in shard or dead-stripped: OS_SpinWaitSysCycles (28B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_system.c"
