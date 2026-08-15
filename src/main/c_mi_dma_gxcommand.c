/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_dma_gxcommand.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MIi_DmaSetParameters                 sub_020A9EA0
#define MI_WaitDma                           sub_02082594
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define MI_SendGXCommandAsync     sub_02082760
#define MIi_FIFOCallback          sub_0208284C
#define MIi_DMACallback           sub_02082900
#define MI_SendGXCommandAsyncFast sub_02082960
#define MIi_DMAFastCallback       sub_02082A1C
/* stripped or unplaced: MI_SendGXCommand (152B) */
/* stripped or unplaced: MI_SendGXCommandFast (104B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_dma_gxcommand.c"
