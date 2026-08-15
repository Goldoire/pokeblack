/* lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_context.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define CP_SaveContext                       sub_020775B8
#define CPi_RestoreContext                   sub_020775F8

#define OS_InitContext sub_02085B9C
#define OS_SaveContext sub_02085C08
#define OS_LoadContext sub_02085C54
/* not in shard or dead-stripped: OS_DumpContext (4B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/os/common/src/os_context.c"
