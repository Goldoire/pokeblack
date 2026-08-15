/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/g3c.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MI_Copy64B                           sub_02082BA0
#define MI_Copy48B                           sub_02082B7C
#define MI_Copy36B                           sub_02082B60
#define MIi_CpuCopy32                        sub_02082A90
#define G3C_Direct1              sub_02075E80
/* stripped or unplaced: G3CS_Direct0 (36B) */
/* stripped or unplaced: G3CS_Direct1 (28B) */
/* stripped or unplaced: G3CS_Direct2 (40B) */
/* stripped or unplaced: G3CS_Direct3 (52B) */
/* stripped or unplaced: G3CS_DirectN (68B) */
/* stripped or unplaced: G3CS_LoadMtx44 (44B) */
/* stripped or unplaced: G3CS_LoadMtx43 (44B) */
/* stripped or unplaced: G3CS_MultMtx44 (44B) */
/* stripped or unplaced: G3CS_MultMtx43 (44B) */
/* stripped or unplaced: G3CS_MultMtx33 (44B) */
/* stripped or unplaced: G3CS_MultTransMtx33 (68B) */
/* stripped or unplaced: G3C_Direct0 (28B) */
/* stripped or unplaced: G3C_Direct2 (28B) */
/* stripped or unplaced: G3C_Direct3 (44B) */
/* stripped or unplaced: G3C_DirectN (32B) */
/* stripped or unplaced: G3C_UpdateGXDLInfo (72B) */
/* stripped or unplaced: G3C_Nop (36B) */
/* stripped or unplaced: G3C_MtxMode (36B) */
/* stripped or unplaced: G3C_PushMtx (32B) */
/* stripped or unplaced: G3C_PopMtx (36B) */
/* stripped or unplaced: G3C_StoreMtx (36B) */
/* stripped or unplaced: G3C_RestoreMtx (36B) */
/* stripped or unplaced: G3C_Identity (32B) */
/* stripped or unplaced: G3C_LoadMtx44 (28B) */
/* stripped or unplaced: G3C_LoadMtx43 (28B) */
/* stripped or unplaced: G3C_MultMtx44 (28B) */
/* stripped or unplaced: G3C_MultMtx43 (28B) */
/* stripped or unplaced: G3C_MultMtx33 (28B) */
/* stripped or unplaced: G3C_MultTransMtx33 (28B) */
/* stripped or unplaced: G3C_Scale (56B) */
/* stripped or unplaced: G3C_Translate (56B) */
/* stripped or unplaced: G3C_Color (36B) */
/* stripped or unplaced: G3C_Normal (68B) */
/* stripped or unplaced: G3C_TexCoord (68B) */
/* stripped or unplaced: G3C_Vtx (60B) */
/* stripped or unplaced: G3C_Vtx10 (68B) */
/* stripped or unplaced: G3C_VtxXY (52B) */
/* stripped or unplaced: G3C_VtxXZ (52B) */
/* stripped or unplaced: G3C_VtxYZ (52B) */
/* stripped or unplaced: G3C_VtxDiff (60B) */
/* stripped or unplaced: G3C_PolygonAttr (64B) */
/* stripped or unplaced: G3C_TexImageParam (84B) */
/* stripped or unplaced: G3C_TexPlttBase (56B) */
/* stripped or unplaced: G3C_MaterialColorDiffAmb (56B) */
/* stripped or unplaced: G3C_MaterialColorSpecEmi (56B) */
/* stripped or unplaced: G3C_LightVector (76B) */
/* stripped or unplaced: G3C_LightColor (36B) */
/* stripped or unplaced: G3C_Shininess (44B) */
/* stripped or unplaced: G3C_Begin (36B) */
/* stripped or unplaced: G3C_End (32B) */
/* stripped or unplaced: G3C_SwapBuffers (36B) */
/* stripped or unplaced: G3C_ViewPort (48B) */
/* stripped or unplaced: G3C_BoxTest (48B) */
/* stripped or unplaced: G3C_PositionTest (60B) */
/* stripped or unplaced: G3C_VectorTest (68B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/g3c.c"
