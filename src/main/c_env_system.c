/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/env/common/src/env_system.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define MI_CpuFill8                          sub_02082BCC
#define STD_CopyLString                      sub_0208CB18
#define ENV_PrependResourceSet                 sub_020913BC
/* stripped or unplaced: ENVi_ClearLinkList (44B) */
/* stripped or unplaced: ENVi_SearchBlankLink (48B) */
/* stripped or unplaced: ENV_Init (52B) */
/* stripped or unplaced: ENV_AppendResourceSet (92B) */
/* stripped or unplaced: ENV_InsertResourceSet (116B) */
/* stripped or unplaced: ENV_SetResourceSet (24B) */
/* stripped or unplaced: ENV_GetResourceSetLinkHead (16B) */
/* stripped or unplaced: ENV_GetNextResourceSet (8B) */
/* stripped or unplaced: ENV_SetClass (40B) */
/* stripped or unplaced: ENV_GetClass (12B) */
/* stripped or unplaced: ENVi_CheckIfSameClass (64B) */
/* stripped or unplaced: ENVi_CheckIfSameMember (112B) */
/* stripped or unplaced: ENVi_SearchByMemberNameFromResourceSet (92B) */
/* stripped or unplaced: ENVi_SearchByMemberName (104B) */
/* stripped or unplaced: ENVi_SearchByFullNameFromResourceSet (68B) */
/* stripped or unplaced: ENVi_SearchByFullName (104B) */
/* stripped or unplaced: ENVi_Search (72B) */
/* stripped or unplaced: ENVi_GetPtrAndLength (120B) */
/* stripped or unplaced: ENV_GetType (36B) */
/* stripped or unplaced: ENV_GetSize (32B) */
/* stripped or unplaced: ENV_GetBelongingResourceSet (88B) */
/* stripped or unplaced: ENV_GetU64 (108B) */
/* stripped or unplaced: ENV_InitIter (32B) */
/* stripped or unplaced: ENVi_SetNextSetForIter (28B) */
/* stripped or unplaced: ENV_SearchByClass (152B) */
/* stripped or unplaced: ENV_SearchByMember (152B) */
/* stripped or unplaced: ENV_SearchByType (132B) */
/* stripped or unplaced: ENV_SearchByPartialName (144B) */
/* stripped or unplaced: ENV_SetResourceSetArray (64B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/env/common/src/env_system.c"
