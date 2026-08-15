/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g3d/src/mem.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define NNS_FndAllocFromAllocator            sub_02061330
#define NNS_FndFreeToAllocator               sub_02061344
#define NNS_G3dAnmObjCalcSizeRequired        sub_02069C14
#define NNS_G3dAllocRenderObj    sub_0206E348
#define NNS_G3dFreeRenderObj     sub_0206E358
#define NNS_G3dAllocAnmObj       sub_0206E364
/* stripped or unplaced: NNS_G3dFreeAnmObj (12B) */
/* stripped or unplaced: NNS_G3dAllocRecBufferJnt (24B) */
/* stripped or unplaced: NNS_G3dFreeRecBufferJnt (12B) */
/* stripped or unplaced: NNS_G3dAllocRecBufferMat (24B) */
/* stripped or unplaced: NNS_G3dFreeRecBufferMat (12B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/mem.c"
