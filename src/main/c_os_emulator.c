/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_emulator.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_GetBootType                       sub_02087B04
#define OSi_DetectDeviceType     sub_02085D0C
#define OS_IsRunOnEmulator       sub_02085D24
/* stripped or unplaced: OS_GetConsoleType (52B) */
/* stripped or unplaced: OS_GetRunningConsoleType (132B) */
/* stripped or unplaced: OSi_DetectEmulator (44B) */
/* stripped or unplaced: OSi_DetectPlatform (272B) */
/* stripped or unplaced: OSi_DetectDebugger (12B) */
/* stripped or unplaced: OS_IsRunOnDebugger (24B) */
/* stripped or unplaced: OSi_IsRunOnTwl (8B) */
/* stripped or unplaced: OSi_IsNitroModeOnTwl (68B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_emulator.c"
