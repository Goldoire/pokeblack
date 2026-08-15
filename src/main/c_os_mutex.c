/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_mutex.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
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
/* stripped or unplaced: OS_LockMutexR (80B) */
/* stripped or unplaced: OS_LockMutexW (80B) */
/* stripped or unplaced: OS_TryLockMutexR (124B) */
/* stripped or unplaced: OS_TryLockMutexW (148B) */
/* stripped or unplaced: OS_UnlockMutexR (16B) */
/* stripped or unplaced: OS_UnlockMutexW (16B) */
/* stripped or unplaced: OS_UnlockMutexRW (16B) */
/* stripped or unplaced: OS_LockMutexFromRToW (80B) */
/* stripped or unplaced: OS_TryLockMutexFromRToW (68B) */
/* stripped or unplaced: OS_LockMutexFromWToR (80B) */
/* stripped or unplaced: OS_TryLockMutexFromWToR (68B) */
/* stripped or unplaced: OSi_DequeueHead (36B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_mutex.c"
