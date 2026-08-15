/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_entropy.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_GetTickLo                         sub_02087170
#define OS_GetLowEntropyData sub_02088168

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_entropy.c"
