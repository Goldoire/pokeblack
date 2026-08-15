/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gxstate.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define GX_InitGXState sub_02080CC4

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gxstate.c"
