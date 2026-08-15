/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g2d/src/g2d_Animation.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define FX_Div                               sub_0207C770
#define SetAnimCtrlCurrentFrameImpl_                     sub_02062D08
#define NNS_G2dGetAnimCtrlCurrentElement                 sub_02062D40
#define NNS_G2dSetAnimCtrlCurrentFrame                   sub_02062F00
#define NNS_G2dGetAnimCtrlCurrentFrame                   sub_02062F1C
#define NNS_G2dInitAnimCtrl                              sub_02062F38
#define NNS_G2dInitAnimCallBackFunctor                   sub_02062F78
#define NNS_G2dBindAnimCtrl                              sub_02062FF0
#define NNS_G2dSetAnimCtrlCallBackFunctorAtAnimFrame     sub_02063018
#define NNSi_G2dIsAnimCtrlLoopAnim                       sub_02063030
/* stripped or unplaced: NNSi_G2dCallbackFuncHandling (68B) */
/* stripped or unplaced: SequenceEdgeHandle_ (272B) */
/* stripped or unplaced: NNS_G2dGetAnimCtrlNextElement (84B) */
/* stripped or unplaced: NNS_G2dGetAnimCtrlNormalizedTime (28B) */
/* stripped or unplaced: NNS_G2dTickAnimCtrl (404B) */
/* stripped or unplaced: NNS_G2dSetAnimCtrlCurrentFrameNoResetCurrentTime (12B) */
/* stripped or unplaced: NNS_G2dInitAnimCtrlCallBackFunctor (16B) */
/* stripped or unplaced: NNS_G2dResetAnimCtrlState (88B) */
/* stripped or unplaced: NNS_G2dSetAnimCtrlCallBackFunctor (24B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/g2d_Animation.c"
