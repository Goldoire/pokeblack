/* lib/NitroSDK/TwlSDK/build/libraries/env/common/src/env_system.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define MI_CpuFill8                          sub_02082BCC
#define STD_CopyLString                      sub_0208CB10

#define ENV_PrependResourceSet                 sub_020913BC
/* not in shard or dead-stripped: ENVi_ClearLinkList (44B) */
/* not in shard or dead-stripped: ENVi_SearchBlankLink (48B) */
/* not in shard or dead-stripped: ENV_Init (52B) */
/* not in shard or dead-stripped: ENV_AppendResourceSet (92B) */
/* not in shard or dead-stripped: ENV_InsertResourceSet (116B) */
/* not in shard or dead-stripped: ENV_SetResourceSet (24B) */
/* not in shard or dead-stripped: ENV_GetResourceSetLinkHead (16B) */
/* not in shard or dead-stripped: ENV_GetNextResourceSet (8B) */
/* not in shard or dead-stripped: ENV_SetClass (40B) */
/* not in shard or dead-stripped: ENV_GetClass (12B) */
/* not in shard or dead-stripped: ENVi_CheckIfSameClass (64B) */
/* not in shard or dead-stripped: ENVi_CheckIfSameMember (112B) */
/* not in shard or dead-stripped: ENVi_SearchByMemberNameFromResourceSet (92B) */
/* not in shard or dead-stripped: ENVi_SearchByMemberName (104B) */
/* not in shard or dead-stripped: ENVi_SearchByFullNameFromResourceSet (68B) */
/* not in shard or dead-stripped: ENVi_SearchByFullName (104B) */
/* not in shard or dead-stripped: ENVi_Search (72B) */
/* not in shard or dead-stripped: ENVi_GetPtrAndLength (120B) */
/* not in shard or dead-stripped: ENV_GetType (36B) */
/* not in shard or dead-stripped: ENV_GetSize (32B) */
/* not in shard or dead-stripped: ENV_GetBelongingResourceSet (88B) */
/* not in shard or dead-stripped: ENV_GetU64 (108B) */
/* not in shard or dead-stripped: ENV_InitIter (32B) */
/* not in shard or dead-stripped: ENVi_SetNextSetForIter (28B) */
/* not in shard or dead-stripped: ENV_SearchByClass (152B) */
/* not in shard or dead-stripped: ENV_SearchByMember (152B) */
/* not in shard or dead-stripped: ENV_SearchByType (132B) */
/* not in shard or dead-stripped: ENV_SearchByPartialName (144B) */
/* not in shard or dead-stripped: ENV_SetResourceSetArray (64B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/env/common/src/env_system.c"
