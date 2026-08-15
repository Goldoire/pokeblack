/* lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_uncompress.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define MI_UncompressLZ8     sub_020834C0
/* not in shard or dead-stripped: MI_UnpackBits (164B) */
/* not in shard or dead-stripped: MI_UncompressLZ16 (292B) */
/* not in shard or dead-stripped: MI_UncompressHuffman (216B) */
/* not in shard or dead-stripped: MI_UncompressRL8 (108B) */
/* not in shard or dead-stripped: MI_UncompressRL16 (160B) */
/* not in shard or dead-stripped: MI_UncompressRL32 (212B) */
/* not in shard or dead-stripped: MI_UnfilterDiff8 (96B) */
/* not in shard or dead-stripped: MI_UnfilterDiff16 (132B) */
/* not in shard or dead-stripped: MI_UnfilterDiff32 (144B) */
/* not in shard or dead-stripped: MI_FilterDiff8 (112B) */
/* not in shard or dead-stripped: MI_FilterDiff16 (124B) */
/* not in shard or dead-stripped: MI_FilterDiff32 (160B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_uncompress.c"
