/* lib/TwlSystem/build/libraries/g3d/src/anm.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define NNSi_G3dAnmCalcNsBca                 sub_0206EB7C
#define MIi_CpuClearFast                     sub_02082AC0
#define MIi_CpuCopy32                        sub_02082A90
#define VEC_CrossProduct                     sub_0207CAE8
#define VEC_Normalize                        sub_0207CCA4

#define NNSi_G3dAnmBlendMat sub_0206AF08
#define NNSi_G3dAnmBlendVis sub_0206B3D0
/* not in shard or dead-stripped: blendScaleVec_ (112B) */
/* not in shard or dead-stripped: NNSi_G3dAnmBlendJnt (1008B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/anm.c"
