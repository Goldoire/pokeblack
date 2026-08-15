/* lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_tcm.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define OS_GetDTCMAddress sub_02086CE0
/* not in shard or dead-stripped: OS_EnableITCM (16B) */
/* not in shard or dead-stripped: OS_DisableITCM (16B) */
/* not in shard or dead-stripped: OS_SetITCMParam (12B) */
/* not in shard or dead-stripped: OS_GetITCMParam (12B) */
/* not in shard or dead-stripped: OS_EnableDTCM (16B) */
/* not in shard or dead-stripped: OS_DisableDTCM (16B) */
/* not in shard or dead-stripped: OS_SetDTCMParam (20B) */
/* not in shard or dead-stripped: OS_GetDTCMParam (20B) */
/* not in shard or dead-stripped: OS_SetDTCMAddress (32B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_tcm.c"
