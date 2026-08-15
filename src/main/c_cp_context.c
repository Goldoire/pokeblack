/* lib/NitroSDK/TwlSDK/build/libraries/cp/common/src/cp_context.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define CP_SaveContext     sub_020775B8
#define CPi_RestoreContext sub_020775F8

#include "../../lib/NitroSDK/TwlSDK/build/libraries/cp/common/src/cp_context.c"
