/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_init.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_InitVAlarm                        sub_02087578
#define OSi_InitVramExclusive                sub_02087EA8
#define OS_InitThread                        sub_02085264
#define OS_InitReset                         sub_02087B78
#define CARD_Init                            sub_02075CAC

#define OSi_WaitVCount0 sub_02086348
/* not in shard or dead-stripped: OS_Init (12B) */
/* not in shard or dead-stripped: OSi_InitCommon (72B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_init.c"
