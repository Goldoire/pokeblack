/* lib/NitroSDK/TwlSDK/build/libraries/spi/ARM9/src/mic.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define PXI_IsCallbackReady                  sub_020885EC
#define PXI_SetFifoRecvCallback              sub_020885A0
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define PXI_SendWordByFifo                   sub_02088610

#define MIC_Init                    sub_0208B24C
#define MIC_StartAutoSamplingAsync  sub_0208B2BC
#define MIC_StartAutoSampling       sub_0208B3EC
#define MIC_StopAutoSamplingAsync   sub_0208B424
#define MIC_StopAutoSampling        sub_0208B480
#define MIC_GetLastSamplingAddress  sub_0208B4B8
#define MicCommonCallback           sub_0208B548
#define MicStartAutoSampling        sub_0208B650
#define MicStopAutoSampling         sub_0208B75C
#define MicGetResultCallback        sub_0208B788
/* not in shard or dead-stripped: MIC_DoSamplingAsync (184B) */
/* not in shard or dead-stripped: MIC_DoSampling (56B) */
/* not in shard or dead-stripped: MIC_AdjustAutoSamplingAsync (112B) */
/* not in shard or dead-stripped: MIC_AdjustAutoSampling (56B) */
/* not in shard or dead-stripped: MicDoSampling (44B) */
/* not in shard or dead-stripped: MicAdjustAutoSampling (124B) */
/* not in shard or dead-stripped: MicWaitBusy (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/spi/ARM9/src/mic.c"
