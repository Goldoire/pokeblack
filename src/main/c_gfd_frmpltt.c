/* lib/TwlSystem/build/libraries/gfd/src/VramManager/gfd_FramePlttVramMan.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define NNS_GfdGetFrmPlttVramState      sub_02061808
/* not in shard or dead-stripped: FrmPlttVramDebugDumpCallBack_ (4B) */
/* not in shard or dead-stripped: NNS_GfdDumpFrmPlttVramManager (20B) */
/* not in shard or dead-stripped: NNS_GfdDumpFrmPlttVramManagerEx (32B) */
/* not in shard or dead-stripped: NNS_GfdInitFrmPlttVramManager (76B) */
/* not in shard or dead-stripped: NNS_GfdAllocFrmPlttVram (284B) */
/* not in shard or dead-stripped: NNS_GfdFreeFrmPlttVram (8B) */
/* not in shard or dead-stripped: NNS_GfdSetFrmPlttVramState (28B) */
/* not in shard or dead-stripped: NNS_GfdResetFrmPlttVramState (28B) */

#include "../../lib/TwlSystem/build/libraries/gfd/src/VramManager/gfd_FramePlttVramMan.c"
