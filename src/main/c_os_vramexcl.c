/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_vramExclusive.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define OsCountZeroBits       sub_02087EA0
#define OSi_InitVramExclusive sub_02087EA8
#define OSi_UnlockVram        sub_02087EDC
/* stripped or unplaced: OSi_TryLockVram (192B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_vramExclusive.c"
