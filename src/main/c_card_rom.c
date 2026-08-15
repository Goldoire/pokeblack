/* lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_rom.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define CARDi_WaitForTask                    sub_02076230
#define CARDi_CheckPulledOutCore             sub_02077518
#define CARDi_EndTask                        sub_020762A8
#define OS_IsAlarmAvailable                  sub_02087244
#define OS_Sleep                             sub_02085A38
#define MI_CpuCopy8                          sub_02082D44
#define OS_DisableIrqMask                    sub_02084998
#define OS_ResetRequestIrqMask               sub_020849C8
#define OS_DisableInterrupts                 sub_02087988
#define OS_SetIrqFunction                    sub_02084774
#define OS_EnableIrqMask                     sub_02084968
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_GetDTCMAddress                    sub_02086CE0
#define CARD_CheckEnabled                    sub_02075DB0
#define CARDi_GetAccessLevel                 sub_02075FCC
#define OS_Terminate                         sub_02088234
#define CARDi_GetDmaInterface                sub_020762F4
#define CARDi_ICInvalidateSmart              sub_02076344
#define CARDi_DCInvalidateSmart              sub_02076360
#define CARDi_ExecuteOldTypeTask             sub_02076170
#define OS_GetBootType                       sub_02087B04
#define CARD_GetOwnRomHeader                 sub_02075DF8
#define OS_GetLockID                         sub_02084EB8
#define CARD_LockRom                         sub_02075E10
#define CARD_UnlockRom                       sub_02075E80
#define CARDi_WaitAsync                      sub_02076050
#define CARDi_TryWaitAsync                   sub_02076070

#define CARDi_SetRomOp             sub_02076BBC
#define CARDi_ReadRomStatusCore    sub_02076D38
#define CARDi_RefreshRom           sub_02076DA0
#define CARDi_RefreshRomCore       sub_02076E00
#define CARDi_ReadRomWithCPU       sub_02076E4C
#define CARDi_DmaReadPageCallback  sub_02076F68
#define CARDi_ReadRomWithDMA       sub_02077008
#define CARDi_DmaReadDone          sub_02077084
#define CARDi_IsRomDmaAvailable    sub_020770B4
#define CARDi_ReadRomSyncCore      sub_02077168
#define CARDi_ReadRom              sub_020771B4
#define CARD_WaitRomAsync          sub_020773C4
/* not in shard or dead-stripped: CARDi_IsTwlRom (48B) */
/* not in shard or dead-stripped: CARDi_StartRomPageTransfer (52B) */
/* not in shard or dead-stripped: CARDi_ReadRomIDCore (88B) */
/* not in shard or dead-stripped: CARD_RefreshRom (72B) */
/* not in shard or dead-stripped: CARDi_ReadRomID (72B) */
/* not in shard or dead-stripped: CARDi_InitRom (120B) */
/* not in shard or dead-stripped: CARD_TryWaitRomAsync (12B) */
/* not in shard or dead-stripped: CARDi_GetOwnSignature (12B) */
/* not in shard or dead-stripped: CARDi_SetOwnSignature (24B) */
/* not in shard or dead-stripped: CARD_GetCacheFlushFlag (44B) */
/* not in shard or dead-stripped: CARD_SetCacheFlushFlag (28B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_rom.c"
