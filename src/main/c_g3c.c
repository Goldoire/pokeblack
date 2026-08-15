/* lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/g3c.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MI_Copy64B                           sub_02082BA0
#define MI_Copy48B                           sub_02082B7C
#define MI_Copy36B                           sub_02082B60
#define MIi_CpuCopy32                        sub_02082A90

#define G3C_Direct1              sub_02075E80
/* not in shard or dead-stripped: G3CS_Direct0 (36B) */
/* not in shard or dead-stripped: G3CS_Direct1 (28B) */
/* not in shard or dead-stripped: G3CS_Direct2 (40B) */
/* not in shard or dead-stripped: G3CS_Direct3 (52B) */
/* not in shard or dead-stripped: G3CS_DirectN (68B) */
/* not in shard or dead-stripped: G3CS_LoadMtx44 (44B) */
/* not in shard or dead-stripped: G3CS_LoadMtx43 (44B) */
/* not in shard or dead-stripped: G3CS_MultMtx44 (44B) */
/* not in shard or dead-stripped: G3CS_MultMtx43 (44B) */
/* not in shard or dead-stripped: G3CS_MultMtx33 (44B) */
/* not in shard or dead-stripped: G3CS_MultTransMtx33 (68B) */
/* not in shard or dead-stripped: G3C_Direct0 (28B) */
/* not in shard or dead-stripped: G3C_Direct2 (28B) */
/* not in shard or dead-stripped: G3C_Direct3 (44B) */
/* not in shard or dead-stripped: G3C_DirectN (32B) */
/* not in shard or dead-stripped: G3C_UpdateGXDLInfo (72B) */
/* not in shard or dead-stripped: G3C_Nop (36B) */
/* not in shard or dead-stripped: G3C_MtxMode (36B) */
/* not in shard or dead-stripped: G3C_PushMtx (32B) */
/* not in shard or dead-stripped: G3C_PopMtx (36B) */
/* not in shard or dead-stripped: G3C_StoreMtx (36B) */
/* not in shard or dead-stripped: G3C_RestoreMtx (36B) */
/* not in shard or dead-stripped: G3C_Identity (32B) */
/* not in shard or dead-stripped: G3C_LoadMtx44 (28B) */
/* not in shard or dead-stripped: G3C_LoadMtx43 (28B) */
/* not in shard or dead-stripped: G3C_MultMtx44 (28B) */
/* not in shard or dead-stripped: G3C_MultMtx43 (28B) */
/* not in shard or dead-stripped: G3C_MultMtx33 (28B) */
/* not in shard or dead-stripped: G3C_MultTransMtx33 (28B) */
/* not in shard or dead-stripped: G3C_Scale (56B) */
/* not in shard or dead-stripped: G3C_Translate (56B) */
/* not in shard or dead-stripped: G3C_Color (36B) */
/* not in shard or dead-stripped: G3C_Normal (68B) */
/* not in shard or dead-stripped: G3C_TexCoord (68B) */
/* not in shard or dead-stripped: G3C_Vtx (60B) */
/* not in shard or dead-stripped: G3C_Vtx10 (68B) */
/* not in shard or dead-stripped: G3C_VtxXY (52B) */
/* not in shard or dead-stripped: G3C_VtxXZ (52B) */
/* not in shard or dead-stripped: G3C_VtxYZ (52B) */
/* not in shard or dead-stripped: G3C_VtxDiff (60B) */
/* not in shard or dead-stripped: G3C_PolygonAttr (64B) */
/* not in shard or dead-stripped: G3C_TexImageParam (84B) */
/* not in shard or dead-stripped: G3C_TexPlttBase (56B) */
/* not in shard or dead-stripped: G3C_MaterialColorDiffAmb (56B) */
/* not in shard or dead-stripped: G3C_MaterialColorSpecEmi (56B) */
/* not in shard or dead-stripped: G3C_LightVector (76B) */
/* not in shard or dead-stripped: G3C_LightColor (36B) */
/* not in shard or dead-stripped: G3C_Shininess (44B) */
/* not in shard or dead-stripped: G3C_Begin (36B) */
/* not in shard or dead-stripped: G3C_End (32B) */
/* not in shard or dead-stripped: G3C_SwapBuffers (36B) */
/* not in shard or dead-stripped: G3C_ViewPort (48B) */
/* not in shard or dead-stripped: G3C_BoxTest (48B) */
/* not in shard or dead-stripped: G3C_PositionTest (60B) */
/* not in shard or dead-stripped: G3C_VectorTest (68B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/gx/ARM9/src/g3c.c"
