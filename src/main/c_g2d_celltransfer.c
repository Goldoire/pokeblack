/* lib/TwlSystem/build/libraries/g2d/src/g2d_CellTransferManager.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define NNSi_G2dInitializeVRamLocation       sub_02063790

#define NNSi_G2dGetCellTransferState          sub_02066878
#define NNS_G2dSetCellTransferStateRequested  sub_02066ABC
#define NNS_G2dFreeCellTransferStateHandle    sub_02066B38
/* not in shard or dead-stripped: NNSi_G2dInitCellTransferState (156B) */
/* not in shard or dead-stripped: NNS_G2dInitCellTransferStateManager (104B) */
/* not in shard or dead-stripped: NNS_G2dUpdateCellTransferStateManager (236B) */
/* not in shard or dead-stripped: NNS_G2dGetNewCellTransferStateHandle (80B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/g2d_CellTransferManager.c"
