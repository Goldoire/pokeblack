/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/g2d/src/g2d_Softsprite.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define G3_RotX                              sub_0207D810
#define G3_RotY                              sub_0207D84C
#define G3_RotZ                              sub_0207D888
#define G3_MultMtx43                         sub_0207D918
#define G3i_OrthoW_                          sub_0207D760
#define G3i_LookAt_                          sub_0207D7C4
#define NNS_G2dSetSpriteAttrEnable                sub_0205A11C
/* stripped or unplaced: DrawSprite_ (860B) */
/* stripped or unplaced: SetAffine43 (84B) */
/* stripped or unplaced: SetBaseMtx_ (52B) */
/* stripped or unplaced: DrawOneQuad_ (180B) */
/* stripped or unplaced: DrawOneQuadCenter_ (188B) */
/* stripped or unplaced: NNS_G2dSetupSoftwareSpriteMaterial (44B) */
/* stripped or unplaced: NNS_G2dSetupSoftwareSpriteCamera (180B) */
/* stripped or unplaced: NNS_G2dIsSpriteAttrEnable (20B) */
/* stripped or unplaced: NNS_G2dSetSpriteCurrentPolygonID (16B) */
/* stripped or unplaced: NNS_G2dSetSpriteDefaultAttr (52B) */
/* stripped or unplaced: NNS_G2dGetSpriteDefaultAttr (12B) */
/* stripped or unplaced: NNS_G2dDrawSpriteSimpleFast (24B) */
/* stripped or unplaced: NNS_G2dDrawSpriteBasicFast (24B) */
/* stripped or unplaced: NNS_G2dDrawSpriteExtendedFast (20B) */
/* stripped or unplaced: NNS_G2dDrawSpriteFast (104B) */
/* stripped or unplaced: NNSi_G2dDrawSpriteFast (236B) */
/* stripped or unplaced: NNSi_G2dDrawSpriteWithMtxFast (108B) */
/* stripped or unplaced: NNSi_G2dDrawSpriteWithMtxDoubleAffineFast (108B) */

#include "../../lib/TwlSystem/build/libraries/g2d/src/g2d_Softsprite.c"
