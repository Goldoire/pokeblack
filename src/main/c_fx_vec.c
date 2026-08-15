/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_vec.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define VEC_Add              sub_0207C9D0
#define VEC_Subtract         sub_0207CA00
#define VEC_Fx16Add          sub_0207CA30
#define VEC_DotProduct       sub_0207CA68
#define VEC_CrossProduct     sub_0207CAE8
#define VEC_Fx16CrossProduct sub_0207CB68
#define VEC_Mag              sub_0207CBD0
#define VEC_Fx16Mag          sub_0207CC30
#define VEC_Normalize        sub_0207CCA4
#define VEC_Fx16Normalize    sub_0207CDB8
#define VEC_MultAdd          sub_0207CEE4
#define VEC_Distance         sub_0207CF3C
/* stripped or unplaced: VEC_Fx16Subtract (56B) */
/* stripped or unplaced: VEC_Fx16DotProduct (84B) */
/* stripped or unplaced: VEC_MultSubtract (88B) */
/* stripped or unplaced: VEC_Fx16Distance (144B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_vec.c"
