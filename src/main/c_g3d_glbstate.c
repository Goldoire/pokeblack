/* lib/TwlSystem/build/libraries/g3d/src/glbstate.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MTX_Identity43_                      sub_0207B598
#define MTX_Identity44_                      sub_0207BDB4
#define MTX_Identity33_                      sub_0207ADC4
#define MTX_Inverse33                        sub_0207B0A4
#define MTX_ScaleApply43                     sub_0207B60C
#define MTX_Inverse43                        sub_0207B67C
#define MI_Copy64B                           sub_02082BA0
#define FX_InvFx64c                          sub_0207C778
#define MTX_Concat43                         sub_0207B9F0
#define MTX_Copy43To44_                      sub_0207B5C0
#define MTX_Concat44                         sub_0207BE14

#define NNS_G3dGlbFlushVP              sub_0206A884
#define NNS_G3dGlbLightVector          sub_0206AA3C
#define NNS_G3dGlbLightColor           sub_0206AA78
#define NNS_G3dGlbMaterialColorDiffAmb sub_0206AA8C
#define NNS_G3dGlbMaterialColorSpecEmi sub_0206AAB0
/* not in shard or dead-stripped: NNS_G3dGlbInit (320B) */
/* not in shard or dead-stripped: NNS_G3dGlbFlushP (48B) */
/* not in shard or dead-stripped: NNS_G3dGlbFlushWVP (236B) */
/* not in shard or dead-stripped: NNS_G3dGlbSetBaseTrans (48B) */
/* not in shard or dead-stripped: NNS_G3dGlbSetBaseScale (48B) */
/* not in shard or dead-stripped: NNS_G3dGlbPolygonAttr (44B) */
/* not in shard or dead-stripped: NNS_G3dGlbGetInvW (104B) */
/* not in shard or dead-stripped: NNS_G3dGlbGetInvV (64B) */
/* not in shard or dead-stripped: mtx_inverse44 (508B) */
/* not in shard or dead-stripped: NNS_G3dGlbGetInvP (64B) */
/* not in shard or dead-stripped: calcSrtCameraMtx_ (100B) */
/* not in shard or dead-stripped: NNS_G3dGlbGetWV (52B) */
/* not in shard or dead-stripped: NNS_G3dGlbGetInvWV (52B) */
/* not in shard or dead-stripped: NNS_G3dGlbGetInvVP (104B) */
/* not in shard or dead-stripped: NNS_G3dGlbGetViewPort (100B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/glbstate.c"
