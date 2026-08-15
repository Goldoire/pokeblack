/* lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_vec.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
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
/* not in shard or dead-stripped: VEC_Fx16Subtract (56B) */
/* not in shard or dead-stripped: VEC_Fx16DotProduct (84B) */
/* not in shard or dead-stripped: VEC_MultSubtract (88B) */
/* not in shard or dead-stripped: VEC_Fx16Distance (144B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fx/common/src/fx_vec.c"
