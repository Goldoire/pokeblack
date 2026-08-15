/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_rom.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define CARDi_WaitForTask                    sub_02076230
#define CARDi_EndTask                        sub_020762A8
#define OS_IsAlarmAvailable                  sub_02087244
#define OS_Sleep                             sub_02085A38
#define MI_CpuCopy8                          sub_02082D44
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_GetDTCMAddress                    sub_02086CE0
#define CARD_CheckEnabled                    sub_02075DB0
#define CARDi_ICInvalidateSmart              sub_02076344
#define CARDi_DCInvalidateSmart              sub_02076360
#define CARDi_ExecuteOldTypeTask             sub_02076170
#define OS_GetBootType                       sub_02087B04
#define CARD_GetOwnRomHeader                 sub_02075DF8
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
/* stripped or unplaced: CARDi_IsTwlRom (48B) */
/* stripped or unplaced: CARDi_StartRomPageTransfer (52B) */
/* stripped or unplaced: CARDi_ReadRomIDCore (88B) */
/* stripped or unplaced: CARD_RefreshRom (72B) */
/* stripped or unplaced: CARDi_ReadRomSyncCore (76B) */
/* stripped or unplaced: CARDi_ReadRom (392B) */
/* stripped or unplaced: CARDi_ReadRomID (72B) */
/* stripped or unplaced: CARDi_InitRom (120B) */
/* stripped or unplaced: CARD_WaitRomAsync (12B) */
/* stripped or unplaced: CARD_TryWaitRomAsync (12B) */
/* stripped or unplaced: CARDi_GetOwnSignature (12B) */
/* stripped or unplaced: CARDi_SetOwnSignature (24B) */
/* stripped or unplaced: CARD_GetCacheFlushFlag (44B) */
/* stripped or unplaced: CARD_SetCacheFlushFlag (28B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_rom.c"
