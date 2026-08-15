/* lib/TwlSystem/build/libraries/g2d/src/g2d_Softsprite.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define G3_RotX                              sub_0207D810
#define G3_RotY                              sub_0207D84C
#define G3_RotZ                              sub_0207D888
#define G3_MultMtx43                         sub_0207D918
#define G3i_OrthoW_                          sub_0207D760
#define G3i_LookAt_                          sub_0207D7C4

#define NNS_G2dSetSpriteAttrEnable                sub_0205A11C
/* not in shard or dead-stripped: DrawSprite_ (860B) */
/* not in shard or dead-stripped: SetAffine43 (84B) */
/* not in shard or dead-stripped: SetBaseMtx_ (52B) */
/* not in shard or dead-stripped: DrawOneQuad_ (180B) */
/* not in shard or dead-stripped: DrawOneQuadCenter_ (188B) */
/* not in shard or dead-stripped: NNS_G2dSetupSoftwareSpriteMaterial (44B) */
/* not in shard or dead-stripped: NNS_G2dSetupSoftwareSpriteCamera (180B) */
/* not in shard or dead-stripped: NNS_G2dIsSpriteAttrEnable (20B) */
/* not in shard or dead-stripped: NNS_G2dSetSpriteCurrentPolygonID (16B) */
/* not in shard or dead-stripped: NNS_G2dSetSpriteDefaultAttr (52B) */
/* not in shard or dead-stripped: NNS_G2dGetSpriteDefaultAttr (12B) */
/* not in shard or dead-stripped: NNS_G2dDrawSpriteSimpleFast (24B) */
/* not in shard or dead-stripped: NNS_G2dDrawSpriteBasicFast (24B) */
/* not in shard or dead-stripped: NNS_G2dDrawSpriteExtendedFast (20B) */
/* not in shard or dead-stripped: NNS_G2dDrawSpriteFast (104B) */
/* not in shard or dead-stripped: NNSi_G2dDrawSpriteFast (236B) */
/* not in shard or dead-stripped: NNSi_G2dDrawSpriteWithMtxFast (108B) */
/* not in shard or dead-stripped: NNSi_G2dDrawSpriteWithMtxDoubleAffineFast (108B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/g2d_Softsprite.c"
