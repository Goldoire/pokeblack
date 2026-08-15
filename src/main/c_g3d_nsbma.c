/* lib/TwlSystem/build/libraries/g3d/src/anm/nsbma.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MIi_CpuClear16                       sub_02082A48

#define GetMatColAnmuAlphaValue_ sub_02070274
/* not in shard or dead-stripped: GetMatColAnmValue_ (352B) */
/* not in shard or dead-stripped: NNSi_G3dAnmObjInitNsBma (204B) */
/* not in shard or dead-stripped: NNSi_G3dAnmCalcNsBma (268B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/anm/nsbma.c"
