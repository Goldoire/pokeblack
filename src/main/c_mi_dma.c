/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_dma.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define MIi_DmaSetParameters       sub_020A9EA0
/* stripped or unplaced: MIi_DmaFill32 (132B) */
/* stripped or unplaced: MIi_DmaCopy32 (164B) */
/* stripped or unplaced: MIi_DmaSend32 (176B) */
/* stripped or unplaced: MIi_DmaRecv32 (164B) */
/* stripped or unplaced: MIi_DmaPipe32 (176B) */
/* stripped or unplaced: MIi_DmaFill16 (132B) */
/* stripped or unplaced: MIi_DmaCopy16 (168B) */
/* stripped or unplaced: MIi_DmaSend16 (176B) */
/* stripped or unplaced: MIi_DmaRecv16 (164B) */
/* stripped or unplaced: MIi_DmaPipe16 (176B) */
/* stripped or unplaced: MIi_DmaFill32Async (264B) */
/* stripped or unplaced: MIi_DmaCopy32Async (252B) */
/* stripped or unplaced: MIi_DmaSend32Async (268B) */
/* stripped or unplaced: MIi_DmaRecv32Async (284B) */
/* stripped or unplaced: MIi_DmaPipe32Async (300B) */
/* stripped or unplaced: MIi_DmaFill16Async (264B) */
/* stripped or unplaced: MIi_DmaCopy16Async (252B) */
/* stripped or unplaced: MIi_DmaSend16Async (268B) */
/* stripped or unplaced: MIi_DmaRecv16Async (284B) */
/* stripped or unplaced: MIi_DmaPipe16Async (300B) */
/* stripped or unplaced: MI_IsDmaBusy (28B) */
/* stripped or unplaced: MI_WaitDma (92B) */
/* stripped or unplaced: MI_StopDma (104B) */
/* stripped or unplaced: MI_StopAllDma (40B) */
/* stripped or unplaced: MI_DmaRestart (28B) */
/* stripped or unplaced: MIi_CheckAnotherAutoDMA (140B) */
/* stripped or unplaced: MIi_CheckDma0SourceAddress (84B) */
/* stripped or unplaced: MIi_SetDmaSrc16 (20B) */
/* stripped or unplaced: MIi_SetDmaSrc32 (20B) */
/* stripped or unplaced: MIi_SetDmaDest16 (20B) */
/* stripped or unplaced: MIi_SetDmaDest32 (20B) */
/* stripped or unplaced: MIi_SetDmaSize16 (40B) */
/* stripped or unplaced: MIi_SetDmaSize32 (40B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_dma.c"
