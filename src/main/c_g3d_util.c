/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g3d/src/util.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MTX_Copy44To43_                      sub_0207BDE0
#define NNS_G3dGeBufferOP_N                  sub_0206DDAC
#define MIi_CpuSend32                        sub_02082AA8
#define G3_LoadMtx43                         sub_0207D8E0
#define G3X_Init                             sub_0207D990
#define NNS_G3dGlbInit                       sub_0206A708
#define NNS_G3dGetTex                        sub_0206E964
#define NNS_G3dTexGetRequiredSize            sub_02069FD0
#define NNS_G3dTex4x4GetRequiredSize         sub_02069FE4
#define NNS_G3dPlttGetRequiredSize           sub_0206A110
#define NNS_G3dTexSetTexKey                  sub_02069FF8
#define NNS_G3dPlttSetPlttKey                sub_0206A124
#define NNS_G3dTexLoad                       sub_0206A00C
#define NNS_G3dPlttLoad                      sub_0206A12C
#define NNS_G3dGetMdlSet                     sub_0206E954
#define FX_InvFx64c                          sub_0207C778
#define NNS_G3dGlbGetViewPort                sub_0206AE9C
#define MTX_MultVec43                        sub_0207BC08
#define FX_InvAsync                          sub_0207C8A0
#define FX_GetDivResultFx64c                 sub_0207C848
#define FX_Div                               sub_0207C770
#define NNS_G3dInit                sub_0206DF14
#define NNS_G3dWorldPosToScrPos    sub_0206DF3C
/* stripped or unplaced: NNS_G3dGetCurrentMtx (140B) */
/* stripped or unplaced: NNS_G3dGetResultMtx (172B) */
/* stripped or unplaced: NNS_G3dSetResultMtx (244B) */
/* stripped or unplaced: NNS_G3dGetSbcCmdLen (64B) */
/* stripped or unplaced: NNS_G3dSearchSbcCmd (72B) */
/* stripped or unplaced: NNS_G3dGetParentNodeID (96B) */
/* stripped or unplaced: NNS_G3dGetChildNodeIDList (104B) */
/* stripped or unplaced: NNS_G3dResDefaultSetup (576B) */
/* stripped or unplaced: NNS_G3dResDefaultRelease (292B) */
/* stripped or unplaced: NNS_G3dLocalOriginToScrPos (308B) */
/* stripped or unplaced: NNS_G3dScrPosToWorldLine (648B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/util.c"
