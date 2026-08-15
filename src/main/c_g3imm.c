/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/g3imm.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define GX_SendFifo64B                       sub_02080CA8
#define GX_SendFifo48B                       sub_02080C64
#define MI_Copy36B                           sub_02082B60
#define G3_LoadMtx44      sub_0207D8C4
#define G3_LoadMtx43      sub_0207D8E0
#define G3_MultMtx44      sub_0207D8FC
#define G3_MultMtx43      sub_0207D918
#define G3_MultMtx33      sub_0207D934
#define G3_MultTransMtx33 sub_0207D950
/* stripped or unplaced: G3_Shininess (28B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/g3imm.c"
