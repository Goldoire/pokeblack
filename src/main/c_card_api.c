/* lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_api.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_SignalEvent                       sub_02088398
#define OS_SetVAlarm                         sub_020876B8
#define OS_TryLockCard                       sub_02084E38
#define OS_GetBootType                       sub_02087B04
#define MI_CpuCopy8                          sub_02082D44
#define CARDi_InitResourceLock               sub_0207608C
#define OS_CreateThread                      sub_020853C0
#define OS_WakeupThreadDirect                sub_02085868
#define CARDi_InitCommand                    sub_020760B4
#define CARDi_InitRom                        sub_0207733C
#define CARD_InitPulledOutCallback           sub_020773DC
#define CARDi_OldTypeTaskThread              sub_020761E4
#define OS_Terminate                         sub_02088234
#define OS_DisableInterrupts                 sub_02087988
#define OS_SetThreadPriority                 sub_02085988
#define OS_RestoreInterrupts                 sub_0208799C
#define CARDi_LockResource                   sub_02075ED4
#define OS_InitEvent                         sub_020882DC
#define OS_CreateVAlarm                      sub_020876A4
#define OS_WaitEventEx                       sub_020882F0
#define OS_UnlockCard                        sub_02084E10
#define CARDi_UnlockResource                 sub_02075F4C
#define CARD_TryWaitBackupAsync              sub_02076B8C
#define CARD_WaitBackupAsync                 sub_02076B80

#define CARDi_PeekEventListener     sub_02075C38
#define CARDi_LockBusCondition      sub_02075C90
#define CARD_Init                   sub_02075CAC
#define CARD_IsEnabled              sub_02075DA0
#define CARD_CheckEnabled           sub_02075DB0
#define CARD_Enable                 sub_02075DC8
#define CARD_GetResultCode          sub_02075DD8
#define CARD_GetRomHeader           sub_02075DEC
#define CARD_GetOwnRomHeader        sub_02075DF8
#define CARD_LockRom                sub_02075E10
/* CARD_UnlockRom byte-matches here too, but the ROM copy belongs to the
   other translation unit; leave this one unplaced. */
#define CARD_UnlockRom unplaced_CARD_UnlockRom
#define CARD_LockBackup             sub_02075E9C
#define CARD_UnlockBackup           sub_02075EAC
/* not in shard or dead-stripped: CARD_IsAvailable (28B) */
/* not in shard or dead-stripped: CARD_GetThreadPriority (16B) */
/* not in shard or dead-stripped: CARD_SetThreadPriority (64B) */
/* not in shard or dead-stripped: CARD_GetCacheFlushThreshold (40B) */
/* not in shard or dead-stripped: CARD_SetCacheFlushThreshold (20B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_api.c"
