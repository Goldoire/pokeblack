/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_tick.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C

#define OS_InitTick           sub_02086FE8
#define OS_IsTickAvailable    sub_02087058
#define OSi_CountUpTick       sub_02087068
#define OS_GetTick            sub_020870D0
#define OS_GetTickLo          sub_02087170
/* not in shard or dead-stripped: OSi_GetTick_noProfile (96B) */
/* not in shard or dead-stripped: OS_SetTick (112B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_tick.c"
