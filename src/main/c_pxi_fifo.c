/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/pxi/common/src/pxi_fifo.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_DisableInterrupts                 sub_02087988
#define OS_ResetRequestIrqMask               sub_020849D0
#define OS_SetIrqFunction                    sub_0208477C
#define OS_EnableIrqMask                     sub_02084970
#define OS_RestoreInterrupts                 sub_0208799C
#define PXI_InitFifo                 sub_020884A4
#define PXI_SetFifoRecvCallback      sub_020885A0
#define PXI_IsCallbackReady          sub_020885EC
#define PXI_SendWordByFifo           sub_02088610
#define PXIi_HandlerRecvFifoNotEmpty sub_02088688
/* stripped or unplaced: PXI_SetFifoSendCallback (72B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/pxi/common/src/pxi_fifo.c"
