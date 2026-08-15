/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_irqHandler.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define CP_SaveContext                       sub_020775B8
#define CPi_RestoreContext                   sub_020775F8
#define OS_DisableInterrupts                 sub_02087988
#define OS_SleepThread                       sub_020857B0
#define OS_RestoreInterrupts                 sub_0208799C

#define OS_IrqHandler              sub_020A9F70
#define OS_IrqHandler_ThreadSwitch sub_020A9FC8
/* not in shard or dead-stripped: OS_WaitIrq (124B) */
/* not in shard or dead-stripped: OS_WaitAnyIrq (20B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_irqHandler.c"
