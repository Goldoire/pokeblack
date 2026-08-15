/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_init.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_InitVAlarm                        sub_02087578
#define OSi_InitVramExclusive                sub_02087EA8
#define OS_InitThread                        sub_02085264
#define OS_InitReset                         sub_02087B78
#define CARD_Init                            sub_02075CAC
#define OSi_WaitVCount0 sub_02086348
/* stripped or unplaced: OS_Init (12B) */
/* stripped or unplaced: OSi_InitCommon (72B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_init.c"
