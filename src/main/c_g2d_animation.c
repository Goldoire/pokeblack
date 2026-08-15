/* lib/TwlSystem/build/libraries/g2d/src/g2d_Animation.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
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
/* not in shard or dead-stripped: NNSi_G2dCallbackFuncHandling (68B) */
/* not in shard or dead-stripped: SequenceEdgeHandle_ (272B) */
/* not in shard or dead-stripped: NNS_G2dGetAnimCtrlNextElement (84B) */
/* not in shard or dead-stripped: NNS_G2dGetAnimCtrlNormalizedTime (28B) */
/* not in shard or dead-stripped: NNS_G2dTickAnimCtrl (404B) */
/* not in shard or dead-stripped: NNS_G2dSetAnimCtrlCurrentFrameNoResetCurrentTime (12B) */
/* not in shard or dead-stripped: NNS_G2dInitAnimCtrlCallBackFunctor (16B) */
/* not in shard or dead-stripped: NNS_G2dResetAnimCtrlState (88B) */
/* not in shard or dead-stripped: NNS_G2dSetAnimCtrlCallBackFunctor (24B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/g2d_Animation.c"
