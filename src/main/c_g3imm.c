/* lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/g3imm.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define GX_SendFifo64B                       sub_02080CA8
#define GX_SendFifo48B                       sub_02080C84
#define MI_Copy36B                           sub_02082B60

#define G3_LoadMtx44      sub_0207D8C4
#define G3_LoadMtx43      sub_0207D8E0
#define G3_MultMtx44      sub_0207D8FC
#define G3_MultMtx43      sub_0207D918
#define G3_MultMtx33      sub_0207D934
#define G3_MultTransMtx33 sub_0207D950
/* not in shard or dead-stripped: G3_Shininess (28B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/g3imm.c"
