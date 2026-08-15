/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_reset.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define PXI_IsCallbackReady                  sub_020885EC
#define PXI_SetFifoRecvCallback              sub_020885A0
#define OS_Terminate                         sub_0208823C
#define OS_GetLockID                         sub_02084EC0
#define CARD_LockRom                         sub_02075E10
#define OS_ResetRequestIrqMask               sub_020849D0
#define OSi_SendToPxi                        sub_02084A84
#define OS_InitReset      sub_02087B78
/* stripped or unplaced: OS_ResetSystem (104B) */
/* stripped or unplaced: OSi_DoResetSystem (44B) */
/* stripped or unplaced: OSi_DoBoot (208B) */
/* stripped or unplaced: OSi_CpuClear32 (20B) */
/* stripped or unplaced: OSi_ReloadRomData (192B) */
/* stripped or unplaced: OSi_ReadCardRom32 (212B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_reset.c"
