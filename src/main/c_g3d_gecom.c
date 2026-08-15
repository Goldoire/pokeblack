/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g3d/src/gecom.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MIi_CpuSend32                        sub_02082AA8
#define MI_SendGXCommandAsyncFast            sub_02082960
#define MI_SendGXCommandAsync                sub_0208270C
#define MIi_CpuCopyFast                      sub_02082B0C
#define NNS_G3dGeSetBuffer     sub_0206DB40
#define NNS_G3dGeReleaseBuffer sub_0206DB60
#define NNS_G3dGeWaitSendDL    sub_0206DBDC
/* stripped or unplaced: NNS_G3dGeIsSendDLBusy (16B) */
/* stripped or unplaced: NNS_G3dGeIsBufferExist (28B) */
/* stripped or unplaced: NNS_G3dGeFlushBuffer (88B) */
/* stripped or unplaced: NNS_G3dGeIsImmOK (68B) */
/* stripped or unplaced: NNS_G3dGeIsBufferOK (48B) */
/* stripped or unplaced: simpleUnlock_ (12B) */
/* stripped or unplaced: NNS_G3dGeUseFastDma (16B) */
/* stripped or unplaced: NNS_G3dGeSendDL (184B) */
/* stripped or unplaced: NNS_G3dGeBufferOP_N (220B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/gecom.c"
