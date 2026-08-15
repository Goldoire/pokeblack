/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_tick.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_InitTick           sub_02086FE8
#define OS_IsTickAvailable    sub_02087058
#define OSi_CountUpTick       sub_02087068
#define OS_GetTick            sub_020870D0
#define OS_GetTickLo          sub_02087170
/* stripped or unplaced: OSi_GetTick_noProfile (96B) */
/* stripped or unplaced: OS_SetTick (112B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_tick.c"
