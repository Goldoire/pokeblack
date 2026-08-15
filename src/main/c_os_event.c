/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_event.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_DisableInterrupts                 sub_02087988
#define OS_SleepThread                       sub_020857B0
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_WakeupThread                      sub_02085800

#define OS_InitEvent     sub_020882DC
#define OS_WaitEventEx   sub_020882F0
#define OS_SignalEvent   sub_02088398
/* not in shard or dead-stripped: OS_WaitEvent (16B) */
/* not in shard or dead-stripped: OS_ClearAllEvent (12B) */
/* not in shard or dead-stripped: OS_ClearEvent (40B) */
/* not in shard or dead-stripped: OS_PollEvent (16B) */
/* not in shard or dead-stripped: OS_PollEventEx (112B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_event.c"
