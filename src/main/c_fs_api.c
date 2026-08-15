/* lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_api.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define FSi_InitOverlay                      sub_02078C48

#define FS_Init        sub_0207AD04
/* not in shard or dead-stripped: FS_IsAvailable (16B) */
/* not in shard or dead-stripped: FS_End (60B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_api.c"
