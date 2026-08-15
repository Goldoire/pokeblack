/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_main.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_InitMutex                         sub_02086004
#define SND_CommandInit                      sub_020898A8
#define SND_AlarmInit                        sub_02089F88
#define OS_LockMutex                         sub_02086028
#define OS_UnlockMutex                       sub_02086078
#define SND_Init         sub_02089848
/* stripped or unplaced: SNDi_LockMutex (20B) */
/* stripped or unplaced: SNDi_UnlockMutex (20B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_main.c"
