/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_emulator.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define SVC_WaitByLoop                       sub_02004490
#define OS_GetBootType                       sub_02087B04

#define OSi_DetectDeviceType     sub_02085D0C
#define OS_IsRunOnEmulator       sub_02085D24
/* not in shard or dead-stripped: OS_GetConsoleType (52B) */
/* not in shard or dead-stripped: OS_GetRunningConsoleType (132B) */
/* not in shard or dead-stripped: OSi_DetectEmulator (44B) */
/* not in shard or dead-stripped: OSi_DetectPlatform (272B) */
/* not in shard or dead-stripped: OSi_DetectDebugger (12B) */
/* not in shard or dead-stripped: OS_IsRunOnDebugger (24B) */
/* not in shard or dead-stripped: OSi_IsRunOnTwl (8B) */
/* not in shard or dead-stripped: OSi_IsNitroModeOnTwl (68B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_emulator.c"
