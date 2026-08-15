/* lib/TwlSystem/build/libraries/g2d/src/g2d_PaletteTable.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* not in shard or dead-stripped: NNS_G2dInitializePaletteTable (36B) */
/* not in shard or dead-stripped: NNS_G2dSetPaletteTableValue (12B) */
/* not in shard or dead-stripped: NNS_G2dGetPaletteTableValue (12B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/g2d_PaletteTable.c"
