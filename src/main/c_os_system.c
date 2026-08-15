/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_system.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_Halt                              sub_020882D0
#define OS_EnableInterrupts            sub_02087974
#define OS_DisableInterrupts           sub_02087988
#define OS_RestoreInterrupts           sub_0208799C
#define OS_DisableInterrupts_IrqAndFiq sub_020879B4
#define OS_RestoreInterrupts_IrqAndFiq sub_020879C8
#define OS_GetCpsrIrq                  sub_020879E0
#define OS_GetProcMode                 sub_020879EC
#define OS_WaitInterrupt               sub_02087A3C
#define OS_WaitVBlankIntr              sub_02087AE4
/* stripped or unplaced: OS_EnableInterrupts_IrqAndFiq (20B) */
/* stripped or unplaced: OS_SpinWaitCpuCycles (12B) */
/* stripped or unplaced: OS_SpinWaitSysCycles (28B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_system.c"
