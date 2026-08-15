/* lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_vramExclusive.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C

#define OsCountZeroBits       sub_02087EA0
#define OSi_InitVramExclusive sub_02087EA8
#define OSi_UnlockVram        sub_02087EDC
/* not in shard or dead-stripped: OSi_TryLockVram (192B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_vramExclusive.c"
