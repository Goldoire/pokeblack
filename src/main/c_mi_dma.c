/* lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_dma.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_Terminate                         sub_0208823C

#define MIi_DmaSetParameters       sub_020A9EA0
/* not in shard or dead-stripped: MIi_DmaFill32 (132B) */
/* not in shard or dead-stripped: MIi_DmaCopy32 (164B) */
/* not in shard or dead-stripped: MIi_DmaSend32 (176B) */
/* not in shard or dead-stripped: MIi_DmaRecv32 (164B) */
/* not in shard or dead-stripped: MIi_DmaPipe32 (176B) */
/* not in shard or dead-stripped: MIi_DmaFill16 (132B) */
/* not in shard or dead-stripped: MIi_DmaCopy16 (168B) */
/* not in shard or dead-stripped: MIi_DmaSend16 (176B) */
/* not in shard or dead-stripped: MIi_DmaRecv16 (164B) */
/* not in shard or dead-stripped: MIi_DmaPipe16 (176B) */
/* not in shard or dead-stripped: MIi_DmaFill32Async (264B) */
/* not in shard or dead-stripped: MIi_DmaCopy32Async (252B) */
/* not in shard or dead-stripped: MIi_DmaSend32Async (268B) */
/* not in shard or dead-stripped: MIi_DmaRecv32Async (284B) */
/* not in shard or dead-stripped: MIi_DmaPipe32Async (300B) */
/* not in shard or dead-stripped: MIi_DmaFill16Async (264B) */
/* not in shard or dead-stripped: MIi_DmaCopy16Async (252B) */
/* not in shard or dead-stripped: MIi_DmaSend16Async (268B) */
/* not in shard or dead-stripped: MIi_DmaRecv16Async (284B) */
/* not in shard or dead-stripped: MIi_DmaPipe16Async (300B) */
/* not in shard or dead-stripped: MI_IsDmaBusy (28B) */
/* not in shard or dead-stripped: MI_WaitDma (92B) */
/* not in shard or dead-stripped: MI_StopDma (104B) */
/* not in shard or dead-stripped: MI_StopAllDma (40B) */
/* not in shard or dead-stripped: MI_DmaRestart (28B) */
/* not in shard or dead-stripped: MIi_CheckAnotherAutoDMA (140B) */
/* not in shard or dead-stripped: MIi_CheckDma0SourceAddress (84B) */
/* not in shard or dead-stripped: MIi_SetDmaSrc16 (20B) */
/* not in shard or dead-stripped: MIi_SetDmaSrc32 (20B) */
/* not in shard or dead-stripped: MIi_SetDmaDest16 (20B) */
/* not in shard or dead-stripped: MIi_SetDmaDest32 (20B) */
/* not in shard or dead-stripped: MIi_SetDmaSize16 (40B) */
/* not in shard or dead-stripped: MIi_SetDmaSize32 (40B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_dma.c"
