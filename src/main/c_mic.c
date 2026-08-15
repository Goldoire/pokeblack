/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/spi/ARM9/src/mic.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
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
/* stripped or unplaced: MIC_DoSamplingAsync (184B) */
/* stripped or unplaced: MIC_DoSampling (56B) */
/* stripped or unplaced: MIC_AdjustAutoSamplingAsync (112B) */
/* stripped or unplaced: MIC_AdjustAutoSampling (56B) */
/* stripped or unplaced: MicDoSampling (44B) */
/* stripped or unplaced: MicAdjustAutoSampling (124B) */
/* stripped or unplaced: MicWaitBusy (24B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/spi/ARM9/src/mic.c"
