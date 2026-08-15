/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_event.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_DisableInterrupts                 sub_02087988
#define OS_SleepThread                       sub_020857B0
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_WakeupThread                      sub_02085800
#define OS_InitEvent     sub_020882DC
#define OS_WaitEventEx   sub_020882F0
#define OS_SignalEvent   sub_02088398
/* stripped or unplaced: OS_WaitEvent (16B) */
/* stripped or unplaced: OS_ClearAllEvent (12B) */
/* stripped or unplaced: OS_ClearEvent (40B) */
/* stripped or unplaced: OS_PollEvent (16B) */
/* stripped or unplaced: OS_PollEventEx (112B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_event.c"
