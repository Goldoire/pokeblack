/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_pxi.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_Terminate                         sub_0208823C
#define PXI_SendWordByFifo                   sub_02088610

#define OSi_SendToPxi      sub_02084A84
/* not in shard or dead-stripped: OS_IsResetOccurred (16B) */
/* not in shard or dead-stripped: OSi_CommonCallback (48B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_pxi.c"
