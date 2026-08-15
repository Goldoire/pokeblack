/* lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_dma_card.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MIi_CheckAnotherAutoDMA              sub_02082680
#define MIi_CheckDma0SourceAddress           sub_0208270C
#define MIi_DmaSetParameters                 sub_01FF8020

#define MIi_CardDmaCopy32 sub_020835A0

#include "../../lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_dma_card.c"
