/* lib/TwlSystem/build/libraries/g2d/src/load/g2d_NFT_load.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_Terminate                         sub_02088234

/* not in shard or dead-stripped: NNSi_G2dGetUnpackedFont (452B) */
/* not in shard or dead-stripped: NNSi_G2dUnpackNFT (216B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/load/g2d_NFT_load.c"
