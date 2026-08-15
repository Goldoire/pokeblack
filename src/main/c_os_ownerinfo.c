/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_ownerInfo.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MI_CpuCopy8                          sub_02082D44
#define MIi_CpuCopy16                        sub_02082A60

#define OS_GetMacAddress         sub_02087C6C
#define OS_GetOwnerInfo          sub_02087C88
#define OS_GetOwnerRtcOffset     sub_02087D08
/* not in shard or dead-stripped: OS_GetFavoriteColorTable (12B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_ownerInfo.c"
