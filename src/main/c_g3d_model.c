/* lib/TwlSystem/build/libraries/g3d/src/model.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

#define NNS_G3dMdlSetMdlLightEnableFlag    sub_0206E394
#define NNS_G3dMdlSetMdlPolygonMode        sub_0206E40C
#define NNS_G3dMdlSetMdlCullMode           sub_0206E484
#define NNS_G3dMdlSetMdlPolygonID          sub_0206E4FC
#define NNS_G3dMdlSetMdlAlpha              sub_0206E574
#define NNS_G3dMdlSetMdlDiffAll            sub_0206E5EC
/* not in shard or dead-stripped: NNSi_G3dModifyMatFlag (168B) */
/* not in shard or dead-stripped: NNSi_G3dModifyPolygonAttrMask (168B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlDiff (128B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlAmb (128B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlSpec (128B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlEmi (128B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlFogEnableFlag (124B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlDepthTestCond (124B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdl1Dot (124B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlFarClip (124B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlXLDepthUpdate (124B) */
/* not in shard or dead-stripped: NNS_G3dMdlGetMdlDiff (124B) */
/* not in shard or dead-stripped: NNS_G3dMdlGetMdlAmb (128B) */
/* not in shard or dead-stripped: NNS_G3dMdlGetMdlSpec (124B) */
/* not in shard or dead-stripped: NNS_G3dMdlGetMdlEmi (128B) */
/* not in shard or dead-stripped: NNS_G3dMdlGetMdlLightEnableFlag (108B) */
/* not in shard or dead-stripped: NNS_G3dMdlGetMdlPolygonMode (112B) */
/* not in shard or dead-stripped: NNS_G3dMdlGetMdlCullMode (112B) */
/* not in shard or dead-stripped: NNS_G3dMdlGetMdlPolygonID (112B) */
/* not in shard or dead-stripped: NNS_G3dMdlGetMdlAlpha (112B) */
/* not in shard or dead-stripped: NNS_G3dMdlGetMdlFogEnableFlag (108B) */
/* not in shard or dead-stripped: NNS_G3dMdlGetMdlDepthTestCond (108B) */
/* not in shard or dead-stripped: NNS_G3dMdlGetMdl1Dot (108B) */
/* not in shard or dead-stripped: NNS_G3dMdlGetMdlFarClip (108B) */
/* not in shard or dead-stripped: NNS_G3dMdlGetMdlXLDepthUpdate (108B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlAmbAll (64B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlSpecAll (64B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlEmiAll (64B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlLightEnableFlagAll (64B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlPolygonModeAll (64B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlCullModeAll (64B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlPolygonIDAll (64B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlAlphaAll (64B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlFogEnableFlagAll (64B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlDepthTestCondAll (64B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdl1DotAll (64B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlFarClipAll (64B) */
/* not in shard or dead-stripped: NNS_G3dMdlSetMdlXLDepthUpdateAll (64B) */

#include "../../lib/TwlSystem/build/libraries/g3d/src/model.c"
