/* lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_archive.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
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
/* not in shard or dead-stripped: FSi_GetArchiveChain (16B) */
/* not in shard or dead-stripped: FSi_NextCommand (428B) */
/* not in shard or dead-stripped: FSi_EndArchive (84B) */
/* not in shard or dead-stripped: FS_GetArchiveResultCode (104B) */
/* not in shard or dead-stripped: FS_GetCurrentDirectory (12B) */
/* not in shard or dead-stripped: FS_WaitAsync (164B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_archive.c"
