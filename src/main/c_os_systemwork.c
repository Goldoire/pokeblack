/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_systemWork.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define OS_GetBootType sub_02087B04
#define OS_GetBootInfo sub_02087B14

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_systemWork.c"
