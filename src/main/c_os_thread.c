/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_thread.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_SaveContext                       sub_02085C08
#define OS_DisableInterrupts                 sub_02087988
#define OS_InitContext                       sub_02085B9C
#define OS_RestoreInterrupts                 sub_0208799C
#define OSi_UnlockAllMutex                   sub_02086088
#define OS_CancelAlarm                       sub_020873F8
#define OS_CreateAlarm                       sub_02087254
#define OS_EnableInterrupts                  sub_02087974
#define OSi_GetUnusedThreadId               sub_02084FB4
#define OSi_InsertLinkToQueue               sub_02084FCC
#define OSi_RemoveLinkFromQueue             sub_02085044
#define OSi_RemoveSpecifiedLinkFromQueue    sub_02085078
#define OSi_RemoveMutexLinkFromQueue        sub_020850CC
#define OSi_InsertThreadToList              sub_020850FC
#define OSi_RemoveThreadFromList            sub_02085158
#define OSi_RescheduleThread                sub_020851A0
#define OS_InitThread                       sub_02085264
#define OS_IsThreadAvailable                sub_020853B0
#define OS_CreateThread                     sub_020853C0
#define OS_ExitThread                       sub_020854B0
#define OSi_ExitThread_ArgSpecified         sub_020854D0
#define OSi_ExitThread                      sub_02085528
#define OSi_ExitThread_Destroy              sub_02085560
#define OS_DestroyThread                    sub_020855BC
#define OS_KillThread                       sub_02085638
#define OS_KillThreadWithPriority           sub_0208565C
#define OSi_CancelThreadAlarmForSleep       sub_020856F8
#define OS_JoinThread                       sub_02085710
#define OS_IsThreadTerminated               sub_0208574C
#define OS_SleepThreadDirect                sub_02085760
#define OS_SleepThread                      sub_020857B0
#define OS_WakeupThread                     sub_02085800
#define OS_WakeupThreadDirect               sub_02085868
#define OS_SelectThread                     sub_02085890
#define OS_RescheduleThread                 sub_020858BC
#define OS_YieldThread                      sub_020858D8
#define OS_SetThreadPriority                sub_02085988
#define OS_GetThreadPriority                sub_02085A30
#define OS_Sleep                            sub_02085A38
#define OSi_SleepAlarmCallback              sub_02085AD8
#define OS_SetSwitchThreadCallback          sub_02085AF8
#define OSi_IdleThreadProc                  sub_02085B20
#define OS_DisableScheduler                 sub_02085B30
#define OS_EnableScheduler                  sub_02085B60
#define OS_SetThreadDestructor              sub_02085B94
/* stripped or unplaced: OSi_SetSystemCallbackInSwitchThread (16B) */
/* stripped or unplaced: OS_GetThreadStatus (8B) */
/* stripped or unplaced: OS_DumpThreadList (4B) */
/* stripped or unplaced: OS_GetNumberOfThread (60B) */
/* stripped or unplaced: OS_GetStackStatus (92B) */
/* stripped or unplaced: OSi_GetSystemStackPointer (20B) */
/* stripped or unplaced: OSi_GetCurrentStackPointer (8B) */
/* stripped or unplaced: OS_SetThreadStackWarningOffset (28B) */
/* stripped or unplaced: OSi_GetIdleThread (32B) */
/* stripped or unplaced: OS_GetThread (60B) */
/* stripped or unplaced: OS_GetThreadDestructor (8B) */
/* stripped or unplaced: OS_SetThreadParameter (8B) */
/* stripped or unplaced: OS_GetThreadParameter (8B) */
/* stripped or unplaced: OSi_SetSystemErrno (8B) */
/* stripped or unplaced: OSi_GetSystemErrno (8B) */
/* stripped or unplaced: OS_GetErrno (28B) */
/* stripped or unplaced: OS_IsThreadInList (72B) */
/* stripped or unplaced: OS_SetThreadDestructorStack (16B) */
/* stripped or unplaced: OS_GetThreadResource (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_thread.c"
