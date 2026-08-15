/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g3d/src/kernel.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MIi_CpuClear32                       sub_02082A7C
#define GX_BeginLoadTex                      sub_0207F754
#define GX_BeginLoadTexPltt                  sub_0207FA0C
#define NNS_G3dAnmObjCalcSizeRequired sub_02069C14
#define NNS_G3dRenderObjInit          sub_02069D14
#define addLink_                      sub_02069D68
#define NNS_G3dRenderObjAddAnmObj     sub_02069E88
#define removeLink_                   sub_02069F08
#define NNS_G3dRenderObjRemoveAnmObj  sub_02069F7C
#define NNS_G3dTexGetRequiredSize     sub_02069FD0
#define NNS_G3dTex4x4GetRequiredSize  sub_02069FE4
#define NNS_G3dTexSetTexKey           sub_02069FF8
#define NNS_G3dTexLoad                sub_0206A00C
#define NNS_G3dPlttGetRequiredSize    sub_0206A110
#define NNS_G3dPlttSetPlttKey         sub_0206A124
#define NNS_G3dPlttLoad               sub_0206A12C
#define bindMdlTex_Internal_          sub_0206A19C
#define NNS_G3dReleaseMdlPltt         sub_0206A67C
/* stripped or unplaced: NNS_G3dAnmObjInit (152B) */
/* stripped or unplaced: NNS_G3dAnmObjEnableID (56B) */
/* stripped or unplaced: NNS_G3dAnmObjDisableID (56B) */
/* stripped or unplaced: updateHintVec_ (100B) */
/* stripped or unplaced: NNS_G3dRenderObjSetCallBack (20B) */
/* stripped or unplaced: NNS_G3dRenderObjResetCallBack (20B) */
/* stripped or unplaced: NNS_G3dRenderObjSetInitFunc (8B) */
/* stripped or unplaced: NNS_G3dTexReleaseTexKey (80B) */
/* stripped or unplaced: NNS_G3dPlttReleasePlttKey (32B) */
/* stripped or unplaced: releaseMdlTex_Internal_ (184B) */
/* stripped or unplaced: NNS_G3dBindMdlTex (244B) */
/* stripped or unplaced: NNS_G3dBindMdlTexEx (136B) */
/* stripped or unplaced: NNS_G3dForceBindMdlTex (172B) */
/* stripped or unplaced: NNS_G3dReleaseMdlTex (140B) */
/* stripped or unplaced: NNS_G3dReleaseMdlTexEx (80B) */
/* stripped or unplaced: bindMdlPltt_Internal_ (220B) */
/* stripped or unplaced: NNS_G3dBindMdlPltt (252B) */
/* stripped or unplaced: NNS_G3dBindMdlPlttEx (144B) */
/* stripped or unplaced: NNS_G3dForceBindMdlPltt (196B) */
/* stripped or unplaced: NNS_G3dReleaseMdlPlttEx (76B) */
/* stripped or unplaced: NNS_G3dBindMdlSet (176B) */
/* stripped or unplaced: NNS_G3dReleaseMdlSet (148B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/kernel.c"
