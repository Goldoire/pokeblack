/* lib/NitroSDK/TwlSDK/build/libraries/pxi/common/src/pxi_fifo.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_DisableInterrupts                 sub_02087988
#define OS_ResetRequestIrqMask               sub_020849C8
#define OS_SetIrqFunction                    sub_02084774
#define OS_EnableIrqMask                     sub_02084968
#define OS_RestoreInterrupts                 sub_0208799C

#define PXI_InitFifo                 sub_020884A4
#define PXI_SetFifoRecvCallback      sub_020885A0
#define PXI_IsCallbackReady          sub_020885EC
#define PXI_SendWordByFifo           sub_02088610
#define PXIi_HandlerRecvFifoNotEmpty sub_02088688
/* not in shard or dead-stripped: PXI_SetFifoSendCallback (72B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/pxi/common/src/pxi_fifo.c"
