/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g2d/src/g2d_CellTransferManager.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define NNSi_G2dInitializeVRamLocation       sub_02063790
#define NNSi_G2dGetCellTransferState          sub_02066878
#define NNS_G2dSetCellTransferStateRequested  sub_02066ABC
#define NNS_G2dFreeCellTransferStateHandle    sub_02066B38
/* stripped or unplaced: NNSi_G2dInitCellTransferState (156B) */
/* stripped or unplaced: NNS_G2dInitCellTransferStateManager (104B) */
/* stripped or unplaced: NNS_G2dUpdateCellTransferStateManager (236B) */
/* stripped or unplaced: NNS_G2dGetNewCellTransferStateHandle (80B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/g2d_CellTransferManager.c"
