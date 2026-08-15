/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_entropy.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_GetTickLo                         sub_02087170

#define OS_GetLowEntropyData sub_02088168

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_entropy.c"
