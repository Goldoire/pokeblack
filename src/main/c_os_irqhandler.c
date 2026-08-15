/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_irqHandler.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define CP_SaveContext                       sub_020775B8
#define CPi_RestoreContext                   sub_020775F8
#define OS_DisableInterrupts                 sub_02087988
#define OS_SleepThread                       sub_020857B0
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_IrqHandler              sub_020A9F70
#define OS_IrqHandler_ThreadSwitch sub_020A9FC8
/* stripped or unplaced: OS_WaitIrq (124B) */
/* stripped or unplaced: OS_WaitAnyIrq (20B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_irqHandler.c"
