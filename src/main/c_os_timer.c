/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_timer.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define OS_StopTimer64              sub_02082658
/* not in shard or dead-stripped: OSi_IsTimerReserved (32B) */
/* not in shard or dead-stripped: OSi_SetTimerReserved (28B) */
/* not in shard or dead-stripped: OSi_UnsetTimerReserved (32B) */
/* not in shard or dead-stripped: OS_StartTimer (32B) */
/* not in shard or dead-stripped: OS_StartTimer32 (120B) */
/* not in shard or dead-stripped: OS_StartTimer48 (192B) */
/* not in shard or dead-stripped: OS_StartTimer64 (148B) */
/* not in shard or dead-stripped: OS_StopTimer (24B) */
/* not in shard or dead-stripped: OS_StopTimerAndUnsetHandler (40B) */
/* not in shard or dead-stripped: OS_StopTimer32 (24B) */
/* not in shard or dead-stripped: OS_StopTimer48 (32B) */
/* not in shard or dead-stripped: OSi_TimerIntr0 (20B) */
/* not in shard or dead-stripped: OSi_TimerIntr1 (20B) */
/* not in shard or dead-stripped: OSi_TimerIntr2 (20B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_timer.c"
