/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_terminate_proc.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_DisableInterrupts                 sub_02087988
#define OS_Halt                  sub_020882D0
/* stripped or unplaced: OS_Terminate (48B) */
/* stripped or unplaced: OSi_TerminateCore (16B) */
/* stripped or unplaced: OSi_SetTerminateCallback (16B) */
/* stripped or unplaced: OS_Exit (20B) */
/* stripped or unplaced: OS_FExit (16B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_terminate_proc.c"
