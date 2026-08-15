/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_atanidx.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define FX_Div                               sub_0207C770
#define FX_Atan2Idx sub_0207CFB8
/* stripped or unplaced: FX_AtanIdx (184B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_atanidx.c"
