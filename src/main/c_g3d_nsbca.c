/* lib/TwlSystem/build/libraries/g3d/src/anm/nsbca.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MIi_CpuClear16                       sub_02082A48
#define MI_Zero36B                           sub_020834A8
#define VEC_Normalize                        sub_0207CCA4

#define NNSi_G3dAnmCalcNsBca    sub_0206EB7C
#define getMdlScale_            sub_0206EC50
#define getMdlRot_              sub_0206ECE0
/* not in shard or dead-stripped: NNSi_G3dAnmObjInitNsBca (124B) */
/* not in shard or dead-stripped: getMdlTrans_ (148B) */
/* not in shard or dead-stripped: getJntSRTAnmResult_ (852B) */
/* not in shard or dead-stripped: getTransData_ (336B) */
/* not in shard or dead-stripped: getTransDataEx_ (340B) */
/* not in shard or dead-stripped: getScaleData_ (468B) */
/* not in shard or dead-stripped: getScaleDataEx_ (384B) */
/* not in shard or dead-stripped: getRotData_ (1028B) */
/* not in shard or dead-stripped: getRotDataEx_ (824B) */
/* not in shard or dead-stripped: getRotDataByIdx_ (360B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/anm/nsbca.c"
