/* lib/TwlSystem/build/libraries/g3d/src/kernel.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MIi_CpuClear32                       sub_02082A7C
#define GX_BeginLoadTex                      sub_0207F7A0
#define GX_LoadTex                           sub_0207F804
#define GX_EndLoadTex                        sub_0207F9BC
#define GX_BeginLoadTexPltt                  sub_0207FA0C
#define GX_LoadTexPltt                       sub_0207FA48
#define GX_EndLoadTexPltt                    sub_0207FAE4
#define FX_Div                               sub_0207C770

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
/* not in shard or dead-stripped: NNS_G3dAnmObjInit (152B) */
/* not in shard or dead-stripped: NNS_G3dAnmObjEnableID (56B) */
/* not in shard or dead-stripped: NNS_G3dAnmObjDisableID (56B) */
/* not in shard or dead-stripped: updateHintVec_ (100B) */
/* not in shard or dead-stripped: NNS_G3dRenderObjSetCallBack (20B) */
/* not in shard or dead-stripped: NNS_G3dRenderObjResetCallBack (20B) */
/* not in shard or dead-stripped: NNS_G3dRenderObjSetInitFunc (8B) */
/* not in shard or dead-stripped: NNS_G3dTexReleaseTexKey (80B) */
/* not in shard or dead-stripped: NNS_G3dPlttReleasePlttKey (32B) */
/* not in shard or dead-stripped: releaseMdlTex_Internal_ (184B) */
/* not in shard or dead-stripped: NNS_G3dBindMdlTex (244B) */
/* not in shard or dead-stripped: NNS_G3dBindMdlTexEx (136B) */
/* not in shard or dead-stripped: NNS_G3dForceBindMdlTex (172B) */
/* not in shard or dead-stripped: NNS_G3dReleaseMdlTex (140B) */
/* not in shard or dead-stripped: NNS_G3dReleaseMdlTexEx (80B) */
/* not in shard or dead-stripped: bindMdlPltt_Internal_ (220B) */
/* not in shard or dead-stripped: NNS_G3dBindMdlPltt (252B) */
/* not in shard or dead-stripped: NNS_G3dBindMdlPlttEx (144B) */
/* not in shard or dead-stripped: NNS_G3dForceBindMdlPltt (196B) */
/* not in shard or dead-stripped: NNS_G3dReleaseMdlPlttEx (76B) */
/* not in shard or dead-stripped: NNS_G3dBindMdlSet (176B) */
/* not in shard or dead-stripped: NNS_G3dReleaseMdlSet (148B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/kernel.c"
