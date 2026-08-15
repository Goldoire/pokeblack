/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_protectionRegion.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define OS_SetProtectionRegionParam                     sub_02086D14
#define OS_SetProtectionRegion0                         sub_02086D30
#define OS_SetProtectionRegion1                         sub_02086D38
#define OS_SetProtectionRegion2                         sub_02086D40
#define OS_SetProtectionRegion3                         sub_02086D48
#define OS_SetProtectionRegion4                         sub_02086D50
#define OS_SetProtectionRegion5                         sub_02086D58
#define OS_SetProtectionRegion6                         sub_02086D60
#define OS_SetProtectionRegion7                         sub_02086D68
#define OS_GetProtectionRegion0                         sub_02086D70
#define OS_GetProtectionRegion1                         sub_02086D78
#define OS_GetProtectionRegion2                         sub_02086D80
#define OS_GetProtectionRegion3                         sub_02086D88
#define OS_GetProtectionRegion4                         sub_02086D90
#define OS_GetProtectionRegion5                         sub_02086D98
#define OS_GetProtectionRegion6                         sub_02086DA0
#define OS_GetProtectionRegion7                         sub_02086DA8
#define OS_SetProtectionRegionEx                        sub_02086DB0
/* stripped or unplaced: OS_EnableICacheForProtectionRegion (16B) */
/* stripped or unplaced: OS_DisableICacheForProtectionRegion (16B) */
/* stripped or unplaced: OS_GetICacheEnableFlagsForProtectionRegion (8B) */
/* stripped or unplaced: OS_SetIPermissionsForProtectionRegion (20B) */
/* stripped or unplaced: OS_GetIPermissionsForProtectionRegion (8B) */
/* stripped or unplaced: OS_EnableDCacheForProtectionRegion (16B) */
/* stripped or unplaced: OS_DisableDCacheForProtectionRegion (16B) */
/* stripped or unplaced: OS_GetDCacheEnableFlagsForProtectionRegion (8B) */
/* stripped or unplaced: OS_SetDPermissionsForProtectionRegion (20B) */
/* stripped or unplaced: OS_GetDPermissionsForProtectionRegion (8B) */
/* stripped or unplaced: OS_EnableWriteBufferForProtectionRegion (16B) */
/* stripped or unplaced: OS_DisableWriteBufferForProtectionRegion (16B) */
/* stripped or unplaced: OS_GetWriteBufferEnableFlagsForProtectionRegion (8B) */
/* stripped or unplaced: OS_GetProtectionRegionParam (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_protectionRegion.c"
