/* lib/TwlSystem/build/libraries/g2d/src/g2d_SRTControl.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MIi_CpuClear16                       sub_02082A48
#define MTX_Identity22_                      sub_0207AD40
#define MTX_Rot22_                           sub_0207AD64
#define MTX_ScaleApply22                     sub_0207AD70

#define NNSi_G2dSrtcInitControl           sub_02064140
#define NNSi_G2dSrtcSetInitialValue       sub_02064150
/* not in shard or dead-stripped: NNSi_G2dSrtcSetTrans (32B) */
/* not in shard or dead-stripped: NNSi_G2dSrtcSetSRTRotZ (28B) */
/* not in shard or dead-stripped: NNSi_G2dSrtcSetSRTScale (28B) */
/* not in shard or dead-stripped: NNSi_G2dSrtcBuildMatrixFromSRT_2D (88B) */
/* not in shard or dead-stripped: NNSi_G2dSrtcBuildMatrixFromSRT_3D (80B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/g2d_SRTControl.c"
