/* lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_main.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_InitMutex                         sub_02086004
#define SND_CommandInit                      sub_020898A8
#define SND_AlarmInit                        sub_02089F88
#define OS_LockMutex                         sub_02086028
#define OS_UnlockMutex                       sub_02086078

#define SND_Init         sub_02089848
/* not in shard or dead-stripped: SNDi_LockMutex (20B) */
/* not in shard or dead-stripped: SNDi_UnlockMutex (20B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_main.c"
