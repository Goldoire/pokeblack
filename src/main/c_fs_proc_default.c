/* lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_proc_default.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define FS_ReadFile                          sub_02078B78
#define MI_CpuCopy8                          sub_02082D44
#define FSi_WaitForArchiveCompletion         sub_02077700
#define FSi_IncrementSjisPositionToSlash     sub_020787E0
#define FS_InitFile                          sub_020788AC
#define FS_GetArchiveName                    sub_02078530
#define STD_GetStringLength                  sub_0208CC80
#define FSi_IsUnreadableRomOffset            sub_0207A988
#define MI_CpuFill8                          sub_02082BCC
#define CARD_GetRomHeader                    sub_02075DEC
#define OS_Terminate                         sub_0208823C
#define FS_MountArchive                      sub_02078540
#define FS_UnmountArchive                    sub_02078588
#define FS_OpenFileDirect                    sub_02078964
#define FS_CloseFile                         sub_02078A80
#define FS_SuspendArchive                    sub_02078648
#define FS_ResumeArchive                     sub_020786D8

#define FSi_ReadTable                 sub_02079304
#define FSi_SeekDirDirect             sub_02079364
#define FSi_SeekDirDefault            sub_02079390
#define FSi_ReadDirDefault            sub_0207942C
#define FSi_FindPathDefault           sub_02079558
#define FSi_GetPathDefault            sub_0207976C
#define FSi_OpenFileFastDefault       sub_02079AE8
#define FSi_OpenFileDirectDefault     sub_02079B70
#define FSi_ReadFileDefault           sub_02079B94
#define FSi_WriteFileDefault          sub_02079BC4
#define FSi_IgnoredCommand            sub_02079BF4
#define FSi_TranslateCommand          sub_02079BFC
#define FSi_ROMFAT_ReadFile           sub_02079CCC
#define FSi_ROMFAT_WriteFile          sub_02079D10
#define FSi_ROMFAT_SeekDirectory      sub_02079D54
#define FSi_ROMFAT_ReadDirectory      sub_02079DAC
#define FSi_ROMFAT_FindPath           sub_02079ED4
#define FSi_ROMFAT_GetPath            sub_02079F60
#define FSi_ROMFAT_OpenFileFast       sub_02079FA4
#define FSi_ROMFAT_OpenFileDirect     sub_02079FEC
#define FSi_ROMFAT_CloseFile          sub_0207A040
#define FSi_ROMFAT_Activate           sub_0207A070
#define FSi_ROMFAT_Idle               sub_0207A0A4
#define FSi_ROMFAT_Suspend            sub_0207A0D8
#define FSi_ROMFAT_Resume             sub_0207A10C
#define FSi_ROMFAT_OpenFile           sub_0207A140
#define FSi_ROMFAT_SeekFile           sub_0207A190
#define FSi_ROMFAT_GetFileLength      sub_0207A1FC
#define FSi_ROMFAT_GetFilePosition    sub_0207A218
#define FSi_ROMFAT_Unmount            sub_0207A234
#define FSi_ROMFAT_GetArchiveCaps     sub_0207A264
#define FSi_ROMFAT_OpenDirectory      sub_0207A270
#define FSi_ROMFAT_CloseDirectory     sub_0207A2C8
#define FSi_ROMFAT_GetPathInfo        sub_0207A2E0
#define FSi_ROMFAT_GetArchiveResource sub_0207A40C
#define FSi_SRLArchiveProc            sub_0207AAE4
/* not in shard or dead-stripped: FSi_SeekAndReadSRL (56B) */
/* not in shard or dead-stripped: FSi_ReadSRLCallback (44B) */
/* not in shard or dead-stripped: FSi_MountSRLFile (344B) */
/* not in shard or dead-stripped: FSi_ReadMemCallback (40B) */
/* not in shard or dead-stripped: FSi_WriteMemCallback (44B) */
/* not in shard or dead-stripped: FS_LoadArchive (108B) */
/* not in shard or dead-stripped: FS_UnloadArchive (12B) */
/* not in shard or dead-stripped: FSi_GetFileLengthIfProc (64B) */
/* not in shard or dead-stripped: FSi_GetFilePositionIfProc (64B) */
/* not in shard or dead-stripped: FSi_SeekFileIfProc (100B) */
/* not in shard or dead-stripped: FS_SetArchiveProc (32B) */
/* not in shard or dead-stripped: FS_LoadArchiveTables (320B) */
/* not in shard or dead-stripped: FS_UnloadArchiveTables (132B) */
/* not in shard or dead-stripped: FS_GetArchiveBase (12B) */
/* not in shard or dead-stripped: FS_GetArchiveFAT (12B) */
/* not in shard or dead-stripped: FS_GetArchiveFNT (12B) */
/* not in shard or dead-stripped: FS_GetArchiveOffset (16B) */
/* not in shard or dead-stripped: FS_IsArchiveTableLoaded (20B) */
/* not in shard or dead-stripped: FS_GetFileImageTop (8B) */
/* not in shard or dead-stripped: FS_GetFileImageBottom (8B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_proc_default.c"
