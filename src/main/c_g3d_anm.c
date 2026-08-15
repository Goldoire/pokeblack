/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g3d/src/anm.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define NNSi_G3dAnmCalcNsBca                 sub_0206EB7C
#define MIi_CpuClearFast                     sub_02082AC0
#define MIi_CpuCopy32                        sub_02082A90
#define FX_Div                               sub_0207C770
#define VEC_CrossProduct                     sub_0207CAE8
#define VEC_Normalize                        sub_0207CCA4
#define NNSi_G3dAnmBlendMat sub_0206AF08
#define NNSi_G3dAnmBlendVis sub_0206B3D0
/* stripped or unplaced: blendScaleVec_ (112B) */
/* stripped or unplaced: NNSi_G3dAnmBlendJnt (1008B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/anm.c"
