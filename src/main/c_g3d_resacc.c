/* lib/TwlSystem/build/libraries/g3d/src/binres/res_struct_accessor.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define NNS_G3dGetMdlSet               sub_0206E954
#define NNS_G3dGetTex                  sub_0206E964
/* not in shard or dead-stripped: NNS_G3dGetResDataByName (444B) */
/* not in shard or dead-stripped: NNS_G3dGetResDictIdxByName (356B) */
/* not in shard or dead-stripped: NNS_G3dGetDataBlockHeaderByIdx (32B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/binres/res_struct_accessor.c"
