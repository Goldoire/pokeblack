/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_swap.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define MI_SwapWord sub_020834B8
/* stripped or unplaced: MI_SwapByte (8B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_swap.c"
