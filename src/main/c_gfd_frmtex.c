/* lib/TwlSystem/build/libraries/gfd/src/VramManager/gfd_FrameTexVramMan.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define NNSi_GfdSetTexNrmSearchArray   sub_02061390
/* not in shard or dead-stripped: DefaultDebugDumpFunc_ (52B) */
/* not in shard or dead-stripped: NNS_GfdDumpFrmTexVramManager (44B) */
/* not in shard or dead-stripped: NNS_GfdDumpFrmTexVramManagerEx (120B) */
/* not in shard or dead-stripped: NNS_GfdInitFrmTexVramManager (128B) */
/* not in shard or dead-stripped: NNS_GfdResetFrmTexVramState (128B) */
/* not in shard or dead-stripped: NNS_GfdAllocFrmTexVram (360B) */
/* not in shard or dead-stripped: NNS_GfdFreeFrmTexVram (8B) */
/* not in shard or dead-stripped: NNS_GfdGetFrmTexVramState (68B) */
/* not in shard or dead-stripped: NNS_GfdSetFrmTexVramState (64B) */

#include "../../lib/TwlSystem/build/libraries/gfd/src/VramManager/gfd_FrameTexVramMan.c"
