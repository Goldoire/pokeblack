/* lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_api.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_TryLockCard                       sub_02084E40
#define CARDi_InitRom                        sub_02077344
#define CARD_InitPulledOutCallback           sub_020773E4
#define OS_Terminate                         sub_0208823C
#define OS_UnlockCard                        sub_02084E18
#define CARD_TryWaitBackupAsync              sub_02076B94
#define CARD_WaitBackupAsync                 sub_02076B88

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
#define CARD_UnlockRom              sub_02075E80
#define CARD_LockBackup             sub_02075E9C
#define CARD_UnlockBackup           sub_02075EAC
/* not in shard or dead-stripped: CARD_IsAvailable (28B) */
/* not in shard or dead-stripped: CARD_GetThreadPriority (16B) */
/* not in shard or dead-stripped: CARD_SetThreadPriority (64B) */
/* not in shard or dead-stripped: CARD_GetCacheFlushThreshold (40B) */
/* not in shard or dead-stripped: CARD_SetCacheFlushThreshold (20B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_api.c"
