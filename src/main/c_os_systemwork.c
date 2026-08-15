/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_systemWork.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define OS_GetBootType sub_02087B04
#define OS_GetBootInfo sub_02087B14

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_systemWork.c"
