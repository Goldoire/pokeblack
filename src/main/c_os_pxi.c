/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_pxi.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_Terminate                         sub_0208823C
#define PXI_SendWordByFifo                   sub_02088610
#define OSi_SendToPxi      sub_02084A84
/* stripped or unplaced: OS_IsResetOccurred (16B) */
/* stripped or unplaced: OSi_CommonCallback (48B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_pxi.c"
