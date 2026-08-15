/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_tcm.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define OS_GetDTCMAddress sub_02086CE0
/* stripped or unplaced: OS_EnableITCM (16B) */
/* stripped or unplaced: OS_DisableITCM (16B) */
/* stripped or unplaced: OS_SetITCMParam (12B) */
/* stripped or unplaced: OS_GetITCMParam (12B) */
/* stripped or unplaced: OS_EnableDTCM (16B) */
/* stripped or unplaced: OS_DisableDTCM (16B) */
/* stripped or unplaced: OS_SetDTCMParam (20B) */
/* stripped or unplaced: OS_GetDTCMParam (20B) */
/* stripped or unplaced: OS_SetDTCMAddress (32B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/ARM9/src/os_tcm.c"
