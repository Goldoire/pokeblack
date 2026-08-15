/* lib/TwlSystem/build/libraries/g2d/src/g2d_MultiCellAnimation.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define NNSi_G2dIsAnimCtrlLoopAnim           sub_02063030
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
/* not in shard or dead-stripped: SetMCDataToMCInstanceImpl_ (620B) */
/* not in shard or dead-stripped: MakeCellAnimToOams_ (200B) */
/* not in shard or dead-stripped: NNS_G2dSetAnimSequenceToMCAnimation (176B) */
/* not in shard or dead-stripped: NNS_G2dInitMCAnimationInstance (348B) */
/* not in shard or dead-stripped: NNS_G2dGetMCNumNodesRequired (96B) */
/* not in shard or dead-stripped: NNS_G2dTickMCAnimation (216B) */
/* not in shard or dead-stripped: NNS_G2dSetMCAnimationCurrentFrame (172B) */
/* not in shard or dead-stripped: NNS_G2dSetMCAnimationCellAnimFrame (148B) */
/* not in shard or dead-stripped: NNS_G2dSetMCAnimationSpeed (168B) */
/* not in shard or dead-stripped: NNS_G2dStartMCCellAnimationAll (156B) */
/* not in shard or dead-stripped: NNS_G2dRestartMCAnimation (168B) */
/* not in shard or dead-stripped: NNS_G2dMakeSimpleMultiCellToOams (384B) */
/* not in shard or dead-stripped: NNS_G2dTraverseMCCellAnims (188B) */
/* not in shard or dead-stripped: NNS_G2dInitMCAnimation (184B) */
/* not in shard or dead-stripped: NNS_G2dInitMCInstance (128B) */
/* not in shard or dead-stripped: NNS_G2dSetMCDataToMCInstance (20B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/g2d_MultiCellAnimation.c"
