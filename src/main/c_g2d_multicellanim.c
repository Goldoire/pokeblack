/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g2d/src/g2d_MultiCellAnimation.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define NNSi_G2dIsAnimCtrlLoopAnim           sub_02063030
#define _u32_div_f                           sub_0209C2B8
#define NNS_G2dTickCellAnimation             sub_0206436C
#define NNS_G2dGetMultiCellDataByIdx         sub_020629F0
#define NNS_G2dBindAnimCtrl                  sub_02062FF0
#define NNS_G2dGetAnimCtrlCurrentElement     sub_02062D40
#define NNSi_G2dSrtcInitControl              sub_02064140
#define NNS_G2dInitAnimCtrl                  sub_02062F38
#define NNS_G2dSetAnimCtrlCurrentFrame       sub_02062F00
#define NNS_G2dSetCellAnimationCurrentFrame  sub_0206438C
#define GetMCBankNumCellAnimRequired_       sub_02064648
#define NNS_G2dGetMCWorkAreaSize            sub_020648B4
#define NNS_G2dGetMCBankNumNodesRequired    sub_020648E0
#define NNS_G2dTickMCInstance               sub_02064934
#define NNS_G2dResetMCCellAnimationAll      sub_02064C10
#define NNS_G2dTraverseMCNodes              sub_02064D70
/* stripped or unplaced: SetMCDataToMCInstanceImpl_ (620B) */
/* stripped or unplaced: MakeCellAnimToOams_ (200B) */
/* stripped or unplaced: NNS_G2dSetAnimSequenceToMCAnimation (176B) */
/* stripped or unplaced: NNS_G2dInitMCAnimationInstance (348B) */
/* stripped or unplaced: NNS_G2dGetMCNumNodesRequired (96B) */
/* stripped or unplaced: NNS_G2dTickMCAnimation (216B) */
/* stripped or unplaced: NNS_G2dSetMCAnimationCurrentFrame (172B) */
/* stripped or unplaced: NNS_G2dSetMCAnimationCellAnimFrame (148B) */
/* stripped or unplaced: NNS_G2dSetMCAnimationSpeed (168B) */
/* stripped or unplaced: NNS_G2dStartMCCellAnimationAll (156B) */
/* stripped or unplaced: NNS_G2dRestartMCAnimation (168B) */
/* stripped or unplaced: NNS_G2dMakeSimpleMultiCellToOams (384B) */
/* stripped or unplaced: NNS_G2dTraverseMCCellAnims (188B) */
/* stripped or unplaced: NNS_G2dInitMCAnimation (184B) */
/* stripped or unplaced: NNS_G2dInitMCInstance (128B) */
/* stripped or unplaced: NNS_G2dSetMCDataToMCInstance (20B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/g2d_MultiCellAnimation.c"
