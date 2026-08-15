/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_context.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define CP_SaveContext                       sub_020775B8
#define CPi_RestoreContext                   sub_020775F8
#define OS_InitContext sub_02085B9C
#define OS_SaveContext sub_02085C08
/* stripped or unplaced: OS_LoadContext (68B) */
/* stripped or unplaced: OS_DumpContext (4B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_context.c"
