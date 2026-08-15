/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_mutex.c, as linked into the retail ARM9.
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
#define OSi_RemoveMutexLinkFromQueue         sub_020850CC
#define OS_WakeupThread                      sub_02085800

#define OS_InitMutex            sub_02086004
#define OS_LockMutex            sub_02086028
#define OS_UnlockMutex          sub_02086078
#define OSi_UnlockAllMutex      sub_02086088
#define OS_TryLockMutex         sub_020860D0
#define OSi_UnlockMutexCore     sub_02086164
#define OSi_EnqueueTail         sub_0208623C
#define OSi_DequeueItem         sub_02086260
/* not in shard or dead-stripped: OS_LockMutexR (80B) */
/* not in shard or dead-stripped: OS_LockMutexW (80B) */
/* not in shard or dead-stripped: OS_TryLockMutexR (124B) */
/* not in shard or dead-stripped: OS_TryLockMutexW (148B) */
/* not in shard or dead-stripped: OS_UnlockMutexR (16B) */
/* not in shard or dead-stripped: OS_UnlockMutexW (16B) */
/* not in shard or dead-stripped: OS_UnlockMutexRW (16B) */
/* not in shard or dead-stripped: OS_LockMutexFromRToW (80B) */
/* not in shard or dead-stripped: OS_TryLockMutexFromRToW (68B) */
/* not in shard or dead-stripped: OS_LockMutexFromWToR (80B) */
/* not in shard or dead-stripped: OS_TryLockMutexFromWToR (68B) */
/* not in shard or dead-stripped: OSi_DequeueHead (36B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_mutex.c"
