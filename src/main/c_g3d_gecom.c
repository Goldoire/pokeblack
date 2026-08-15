/* lib/TwlSystem/build/libraries/g3d/src/gecom.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MIi_CpuSend32                        sub_02082AA8
#define MI_SendGXCommandAsyncFast            sub_02082960
#define MI_SendGXCommandAsync                sub_0208270C
#define MIi_CpuCopyFast                      sub_02082B0C

#define NNS_G3dGeSetBuffer     sub_0206DB40
#define NNS_G3dGeReleaseBuffer sub_0206DB60
#define NNS_G3dGeWaitSendDL    sub_0206DBDC
/* not in shard or dead-stripped: NNS_G3dGeIsSendDLBusy (16B) */
/* not in shard or dead-stripped: NNS_G3dGeIsBufferExist (28B) */
/* not in shard or dead-stripped: NNS_G3dGeFlushBuffer (88B) */
/* not in shard or dead-stripped: NNS_G3dGeIsImmOK (68B) */
/* not in shard or dead-stripped: NNS_G3dGeIsBufferOK (48B) */
/* not in shard or dead-stripped: simpleUnlock_ (12B) */
/* not in shard or dead-stripped: NNS_G3dGeUseFastDma (16B) */
/* not in shard or dead-stripped: NNS_G3dGeSendDL (184B) */
/* not in shard or dead-stripped: NNS_G3dGeBufferOP_N (220B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/gecom.c"
