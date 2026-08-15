/* lib/TwlSystem/build/libraries/g3d/src/mem.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define NNS_FndAllocFromAllocator            sub_02061330
#define NNS_FndFreeToAllocator               sub_02061344
#define NNS_G3dAnmObjCalcSizeRequired        sub_02069C14

#define NNS_G3dAllocRenderObj    sub_0206E348
#define NNS_G3dFreeRenderObj     sub_0206E358
#define NNS_G3dAllocAnmObj       sub_0206E364
/* not in shard or dead-stripped: NNS_G3dFreeAnmObj (12B) */
/* not in shard or dead-stripped: NNS_G3dAllocRecBufferJnt (24B) */
/* not in shard or dead-stripped: NNS_G3dFreeRecBufferJnt (12B) */
/* not in shard or dead-stripped: NNS_G3dAllocRecBufferMat (24B) */
/* not in shard or dead-stripped: NNS_G3dFreeRecBufferMat (12B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/mem.c"
