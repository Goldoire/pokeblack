/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_archive.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_DisableInterrupts                 sub_02087988
#define OS_WakeupThread                      sub_02085800
#define OS_RestoreInterrupts                 sub_0208799C
#define OS_SleepThread                       sub_020857B0
#define FS_InitFile                          sub_020788AC
#define FSi_DecrementSjisPositionToSlash     sub_02078834
#define FSi_TrimSjisTrailingSlash            sub_02078868
#define MI_CpuFill8                          sub_02082BCC
#define FSi_IsEventCommand           sub_02077634
#define FSi_EndCommand               sub_0207765C
#define FSi_WaitForArchiveCompletion sub_02077700
#define FSi_InvokeCommand            sub_02077758
#define FSi_ExecuteAsyncCommand      sub_02077C78
#define FSi_ExecuteSyncCommand       sub_02077CFC
#define FSi_SendCommand              sub_02077D80
#define FS_FindArchive               sub_02077EB8
#define FS_SetCurrentDirectory       sub_02077F44
#define FSi_CopySafeString           sub_02078018
#define FS_NormalizePath             sub_02078078
#define FS_InitArchive               sub_02078360
#define FS_RegisterArchiveName       sub_02078384
#define FS_ReleaseArchiveName        sub_02078484
#define FS_GetArchiveName            sub_02078530
#define FS_MountArchive              sub_02078540
#define FS_UnmountArchive            sub_02078588
#define FS_SuspendArchive            sub_02078648
#define FS_ResumeArchive             sub_020786D8
#define FS_NotifyArchiveAsyncEnd     sub_02078734
/* stripped or unplaced: FSi_GetArchiveChain (16B) */
/* stripped or unplaced: FSi_NextCommand (428B) */
/* stripped or unplaced: FSi_EndArchive (84B) */
/* stripped or unplaced: FS_GetArchiveResultCode (104B) */
/* stripped or unplaced: FS_GetCurrentDirectory (12B) */
/* stripped or unplaced: FS_WaitAsync (164B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_archive.c"
