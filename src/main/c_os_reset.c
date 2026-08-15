/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_reset.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define PXI_Init                             sub_02088498
#define PXI_IsCallbackReady                  sub_020885EC
#define PXI_SetFifoRecvCallback              sub_020885A0
#define OS_Terminate                         sub_02088234
#define OS_GetLockID                         sub_02084EB8
#define CARD_LockRom                         sub_02075E10
#define OS_ResetRequestIrqMask               sub_020849C8
#define OSi_SendToPxi                        sub_02084A84

#define OS_InitReset      sub_02087B78
/* not in shard or dead-stripped: OS_ResetSystem (104B) */
/* not in shard or dead-stripped: OSi_DoResetSystem (44B) */
/* not in shard or dead-stripped: OSi_DoBoot (208B) */
/* not in shard or dead-stripped: OSi_CpuClear32 (20B) */
/* not in shard or dead-stripped: OSi_ReloadRomData (192B) */
/* not in shard or dead-stripped: OSi_ReadCardRom32 (212B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_reset.c"
