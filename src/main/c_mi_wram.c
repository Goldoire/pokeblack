/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_wram.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define MI_SetWramBank sub_020821B0
/* stripped or unplaced: MI_GetWramBank (8B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_wram.c"
