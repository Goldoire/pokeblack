/* lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_rom.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define CARDi_CheckPulledOutCore             sub_02077520
#define OS_DisableIrqMask                    sub_020849A0
#define OS_ResetRequestIrqMask               sub_020849D0
#define OS_SetIrqFunction                    sub_0208477C
#define OS_EnableIrqMask                     sub_02084970
#define OS_Terminate                         sub_0208823C
#define OS_GetLockID                         sub_02084EC0

#define CARDi_SetRomOp             sub_02076BBC
#define CARDi_ReadRomStatusCore    sub_02076D38
#define CARDi_RefreshRom           sub_02076DA0
#define CARDi_RefreshRomCore       sub_02076E00
#define CARDi_ReadRomWithCPU       sub_02076E4C
#define CARDi_DmaReadPageCallback  sub_02076F68
#define CARDi_ReadRomWithDMA       sub_02077008
#define CARDi_DmaReadDone          sub_02077084
#define CARDi_IsRomDmaAvailable    sub_020770B4
/* not in shard or dead-stripped: CARDi_IsTwlRom (48B) */
/* not in shard or dead-stripped: CARDi_StartRomPageTransfer (52B) */
/* not in shard or dead-stripped: CARDi_ReadRomIDCore (88B) */
/* not in shard or dead-stripped: CARD_RefreshRom (72B) */
/* not in shard or dead-stripped: CARDi_ReadRomSyncCore (76B) */
/* not in shard or dead-stripped: CARDi_ReadRom (392B) */
/* not in shard or dead-stripped: CARDi_ReadRomID (72B) */
/* not in shard or dead-stripped: CARDi_InitRom (120B) */
/* not in shard or dead-stripped: CARD_WaitRomAsync (12B) */
/* not in shard or dead-stripped: CARD_TryWaitRomAsync (12B) */
/* not in shard or dead-stripped: CARDi_GetOwnSignature (12B) */
/* not in shard or dead-stripped: CARDi_SetOwnSignature (24B) */
/* not in shard or dead-stripped: CARD_GetCacheFlushFlag (44B) */
/* not in shard or dead-stripped: CARD_SetCacheFlushFlag (28B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_rom.c"
