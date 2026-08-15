/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_timer.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define OS_StopTimer64              sub_02082658
/* stripped or unplaced: OSi_IsTimerReserved (32B) */
/* stripped or unplaced: OSi_SetTimerReserved (28B) */
/* stripped or unplaced: OSi_UnsetTimerReserved (32B) */
/* stripped or unplaced: OS_StartTimer (32B) */
/* stripped or unplaced: OS_StartTimer32 (120B) */
/* stripped or unplaced: OS_StartTimer48 (192B) */
/* stripped or unplaced: OS_StartTimer64 (148B) */
/* stripped or unplaced: OS_StopTimer (24B) */
/* stripped or unplaced: OS_StopTimerAndUnsetHandler (40B) */
/* stripped or unplaced: OS_StopTimer32 (24B) */
/* stripped or unplaced: OS_StopTimer48 (32B) */
/* stripped or unplaced: OSi_TimerIntr0 (20B) */
/* stripped or unplaced: OSi_TimerIntr1 (20B) */
/* stripped or unplaced: OSi_TimerIntr2 (20B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_timer.c"
