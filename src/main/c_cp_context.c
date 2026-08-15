/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/cp/common/src/cp_context.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define CP_SaveContext     sub_020775B8
#define CPi_RestoreContext sub_020775F8

#include "../../lib/NitroSDK/TwlSDK/build/libraries/cp/common/src/cp_context.c"
