/* lib/NitroSDK/TwlSDK/build/libraries/math/common/src/qsort.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define MATH_QSort sub_02081BE4

#include "../../lib/NitroSDK/TwlSDK/build/libraries/math/common/src/qsort.c"
