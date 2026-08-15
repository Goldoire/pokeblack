/* lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_protectionUnit.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define OS_EnableProtectionUnit  sub_02086CF4
#define OS_DisableProtectionUnit sub_02086D04

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_protectionUnit.c"
