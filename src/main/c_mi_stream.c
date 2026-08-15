/* lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_stream.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* not in shard or dead-stripped: MI_GetReadStreamFromMemoryCallbacks (12B) */
/* not in shard or dead-stripped: MIi_InitReadStreamFromMemory (60B) */
/* not in shard or dead-stripped: MIi_TerminateReadStreamFromMemory (8B) */
/* not in shard or dead-stripped: MIi_ReadByteStreamFromMemory (8B) */
/* not in shard or dead-stripped: MIi_ReadShortStreamFromMemory (8B) */
/* not in shard or dead-stripped: MIi_ReadWordStreamFromMemory (8B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_stream.c"
