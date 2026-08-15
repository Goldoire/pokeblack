/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_ownerInfo.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MI_CpuCopy8                          sub_02082D44
#define MIi_CpuCopy16                        sub_02082A60
#define OS_GetMacAddress         sub_02087C6C
#define OS_GetOwnerInfo          sub_02087C88
#define OS_GetOwnerRtcOffset     sub_02087D08
/* stripped or unplaced: OS_GetFavoriteColorTable (12B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_ownerInfo.c"
