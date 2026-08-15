/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gxasm.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define GX_SendFifo48B  sub_02080C84
#define GX_SendFifo64B  sub_02080CA8
/* stripped or unplaced: GX_SendFifo128B (44B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/gxasm.c"
