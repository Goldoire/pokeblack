/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_protectionUnit.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define OS_EnableProtectionUnit  sub_02086CF4
#define OS_DisableProtectionUnit sub_02086D04

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_protectionUnit.c"
