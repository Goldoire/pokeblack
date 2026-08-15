/* lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_dma_gxcommand.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MIi_DmaSetParameters                 sub_020A9EA0
#define MI_WaitDma                           sub_02082594
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C

#define MI_SendGXCommandAsync     sub_02082760
#define MIi_FIFOCallback          sub_0208284C
#define MIi_DMACallback           sub_02082900
#define MI_SendGXCommandAsyncFast sub_02082960
#define MIi_DMAFastCallback       sub_02082A1C
/* not in shard or dead-stripped: MI_SendGXCommand (152B) */
/* not in shard or dead-stripped: MI_SendGXCommandFast (104B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_dma_gxcommand.c"
