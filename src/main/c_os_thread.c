/* TwlSDK os_thread.c as linked into the ARM9 at 0x02084FB4..0x02085B9C.
 *
 * Every function is renamed to sub_<realRAM> so verify_functions.py can find
 * its home; the original SDK name is kept in the macro on the left. Functions
 * the linker dead-stripped are left with their SDK names (they report
 * "no address" and are not claimed).
 */
/* The retail ARM9 was built with SDK_FINALROM. Evidence: with it off, the
 * merged .bss of this translation unit comes out in the order
 * CurrentThreadPtr / StackForDestructor / RescheduleCount / ... and every
 * static-variable immediate offset is wrong; with it on the order becomes
 * SystemCallbackInSwitchThread(+0) / RescheduleCount(+4) / CurrentThreadPtr(+8)
 * / IsThreadInitialized(+0xc) / SystemStackBuffer(+0x10) / StackForDestructor
 * (+0x14) / ThreadIdCount(+0x18) / ThreadInfo(+0x1c), which is exactly what the
 * ROM encodes, and all 37 functions in the file go byte-exact.
 * This TU's .bss lands at 0x02150FD0.
 */
#define SDK_FINALROM

/* Callees outside this translation unit, named so the verifier checks the
 * branch words instead of masking them. Addresses from the claim table. */
#define OS_SaveContext                   sub_02085C08
#define OS_DisableInterrupts             sub_02087988
#define OS_InitContext                   sub_02085B9C
#define OS_RestoreInterrupts             sub_0208799C
#define OSi_UnlockAllMutex               sub_02086088
#define OS_CancelAlarm                   sub_020873F8
#define OS_CreateAlarm                   sub_02087254
#define OS_EnableInterrupts              sub_02087974

#define OSi_GetUnusedThreadId            sub_02084FB4
#define OSi_InsertLinkToQueue            sub_02084FCC
#define OSi_RemoveLinkFromQueue          sub_02085044
#define OSi_RemoveSpecifiedLinkFromQueue sub_02085078
#define OSi_RemoveMutexLinkFromQueue     sub_020850CC
#define OSi_InsertThreadToList           sub_020850FC
#define OSi_RemoveThreadFromList         sub_02085158
#define OSi_RescheduleThread             sub_020851A0
#define OS_InitThread                    sub_02085264
#define OS_IsThreadAvailable             sub_020853B0
#define OS_CreateThread                  sub_020853C0
#define OS_ExitThread                    sub_020854B0
#define OSi_ExitThread_ArgSpecified      sub_020854D0
#define OSi_ExitThread                   sub_02085528
#define OSi_ExitThread_Destroy           sub_02085560
#define OS_DestroyThread                 sub_020855BC
#define OS_KillThread                    sub_02085638
#define OS_KillThreadWithPriority        sub_0208565C
#define OSi_CancelThreadAlarmForSleep    sub_020856F8
#define OS_JoinThread                    sub_02085710
#define OS_IsThreadTerminated            sub_0208574C
#define OS_SleepThreadDirect             sub_02085760
#define OS_SleepThread                   sub_020857B0
#define OS_WakeupThread                  sub_02085800
#define OS_WakeupThreadDirect            sub_02085868
#define OS_SelectThread                  sub_02085890
#define OS_RescheduleThread              sub_020858BC
#define OS_YieldThread                   sub_020858D8
#define OS_SetThreadPriority             sub_02085988
#define OS_GetThreadPriority             sub_02085A30
#define OS_Sleep                         sub_02085A38
#define OSi_SleepAlarmCallback           sub_02085AD8
#define OS_SetSwitchThreadCallback       sub_02085AF8
#define OSi_IdleThreadProc               sub_02085B20
#define OS_DisableScheduler              sub_02085B30
#define OS_EnableScheduler               sub_02085B60
#define OS_SetThreadDestructor           sub_02085B94

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_thread.c"
