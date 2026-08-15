/* lib/TwlSystem/build/libraries/g3d/src/sbc.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MIi_CpuClearFast                     sub_02082AC0
#define MIi_CpuClear32                       sub_02082A7C
#define NNS_G3dGeBufferOP_N                  sub_0206DDA4
#define MI_Zero36B                           sub_020834A8
#define MTX_Copy43To44_                      sub_0207B5C0
#define MTX_Concat44                         sub_0207BE14
#define VEC_Mag                              sub_0207CBD0
#define MIi_CpuSend32                        sub_02082AA8
#define VEC_Normalize                        sub_0207CCA4
#define VEC_CrossProduct                     sub_0207CAE8
#define G3_MultMtx43                         sub_0207D918
#define G3_MultMtx33                         sub_0207D934
#define G3_LoadMtx43                         sub_0207D8E0

#define NNSi_G3dFuncSbc_NOP                 sub_0206B780
#define NNSi_G3dFuncSbc_RET                 sub_0206B7A8
#define NNSi_G3dFuncSbc_MAT                 sub_0206BEA0
#define NNSi_G3dFuncSbc_SHP_InternalDefault sub_0206BF50
#define NNSi_G3dFuncSbc_SHP                 sub_0206C024
/* not in shard or dead-stripped: G3dDrawInternal_Loop_ (72B) */
/* not in shard or dead-stripped: G3dDrawInternal_ (408B) */
/* not in shard or dead-stripped: updateHintVec_ (100B) */
/* not in shard or dead-stripped: NNS_G3dDraw (224B) */
/* not in shard or dead-stripped: NNSi_G3dFuncSbc_NODE (376B) */
/* not in shard or dead-stripped: NNSi_G3dFuncSbc_MTX (204B) */
/* not in shard or dead-stripped: NNSi_G3dFuncSbc_MAT_InternalDefault (1140B) */
/* not in shard or dead-stripped: NNSi_G3dFuncSbc_NODEDESC (1116B) */
/* not in shard or dead-stripped: NNSi_G3dFuncSbc_BB (748B) */
/* not in shard or dead-stripped: NNSi_G3dFuncSbc_BBY (844B) */
/* not in shard or dead-stripped: NNSi_G3dFuncSbc_NODEMIX (1864B) */
/* not in shard or dead-stripped: NNSi_G3dFuncSbc_CALLDL (220B) */
/* not in shard or dead-stripped: NNSi_G3dFuncSbc_POSSCALE (104B) */
/* not in shard or dead-stripped: NNSi_G3dFuncSbc_ENVMAP (848B) */
/* not in shard or dead-stripped: NNSi_G3dFuncSbc_PRJMAP (948B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/sbc.c"
