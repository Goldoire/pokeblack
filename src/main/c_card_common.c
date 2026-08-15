/* lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_common.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_Terminate                         sub_0208823C

#define CARDi_LockResource     sub_02075ED4
#define CARDi_UnlockResource   sub_02075F4C
#define CARDi_WaitAsync        sub_02076050
#define CARDi_TryWaitAsync     sub_02076070
#define CARDi_InitResourceLock sub_0207608C
#define CARDi_InitCommand      sub_020760B4
/* not in shard or dead-stripped: CARDi_GetAccessLevel (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_common.c"
