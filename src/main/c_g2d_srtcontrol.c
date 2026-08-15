/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g2d/src/g2d_SRTControl.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MIi_CpuClear16                       sub_02082A48
#define MTX_Identity22_                      sub_0207AD40
#define MTX_Rot22_                           sub_0207AD64
#define MTX_ScaleApply22                     sub_0207AD70
#define NNSi_G2dSrtcInitControl           sub_02064140
#define NNSi_G2dSrtcSetInitialValue       sub_02064150
/* stripped or unplaced: NNSi_G2dSrtcSetTrans (32B) */
/* stripped or unplaced: NNSi_G2dSrtcSetSRTRotZ (28B) */
/* stripped or unplaced: NNSi_G2dSrtcSetSRTScale (28B) */
/* stripped or unplaced: NNSi_G2dSrtcBuildMatrixFromSRT_2D (88B) */
/* stripped or unplaced: NNSi_G2dSrtcBuildMatrixFromSRT_3D (80B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/g2d_SRTControl.c"
