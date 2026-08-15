/* lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_file.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define FS_NormalizePath                     sub_02078078
#define FSi_SendCommand                      sub_02077D80
#define FS_GetArchiveName                    sub_02078530
#define MI_CpuMove                           sub_02083194
#define _u32_div_f                           sub_0209C2B8
#define FSi_GetFilePositionIfProc            sub_0207A528
#define MI_CpuFill8                          sub_02082BCC
#define FS_FindArchive                       sub_02077EB8
#define MI_CpuCopy8                          sub_02082D44
#define FS_SetCurrentDirectory               sub_02077F44
#define OS_InitMessageQueue                  sub_02085D94
#define OS_SendMessage                       sub_02085DBC
#define OS_ReceiveMessage                    sub_02085E50

#define FSi_DecrementSjisPosition            sub_020787A0
#define FSi_IncrementSjisPositionToSlash     sub_020787E0
#define FSi_DecrementSjisPositionToSlash     sub_02078834
#define FSi_TrimSjisTrailingSlash            sub_02078868
#define FS_InitFile                          sub_020788AC
#define FS_ConvertPathToFileID               sub_020788D8
#define FS_OpenFileDirect                    sub_02078964
#define FS_OpenFileFast                      sub_020789A4
#define FS_OpenFileEx                        sub_020789FC
#define FS_CloseFile                         sub_02078A80
#define FS_GetFileLength                     sub_02078A94
#define FS_GetFilePosition                   sub_02078AEC
#define FS_WriteFile                         sub_02078BC4
#define FS_OpenFile                          sub_02078C18
/* not in shard or dead-stripped: FSi_DecrementUnicodePosition (72B) */
/* not in shard or dead-stripped: FSi_DecrementUnicodePositionToSlash (56B) */
/* not in shard or dead-stripped: FS_CancelFile (72B) */
/* not in shard or dead-stripped: FS_CreateFile (116B) */
/* not in shard or dead-stripped: FS_DeleteFile (108B) */
/* not in shard or dead-stripped: FS_RenameFile (156B) */
/* not in shard or dead-stripped: FS_GetPathInfo (116B) */
/* not in shard or dead-stripped: FS_SetPathInfo (116B) */
/* not in shard or dead-stripped: FS_CreateDirectory (116B) */
/* not in shard or dead-stripped: FS_DeleteDirectory (108B) */
/* not in shard or dead-stripped: FS_RenameDirectory (156B) */
/* not in shard or dead-stripped: FSi_GetFullPath (128B) */
/* not in shard or dead-stripped: FSi_ComplementDirectory (292B) */
/* not in shard or dead-stripped: FS_CreateFileAuto (80B) */
/* not in shard or dead-stripped: FS_DeleteFileAuto (12B) */
/* not in shard or dead-stripped: FS_RenameFileAuto (84B) */
/* not in shard or dead-stripped: FS_CreateDirectoryAuto (80B) */
/* not in shard or dead-stripped: FS_DeleteDirectoryAuto (488B) */
/* not in shard or dead-stripped: FS_RenameDirectoryAuto (84B) */
/* not in shard or dead-stripped: FS_GetArchiveResource (96B) */
/* not in shard or dead-stripped: FSi_GetSpaceToCreateDirectoryEntries (184B) */
/* not in shard or dead-stripped: FS_HasEnoughSpaceToCreateFile (132B) */
/* not in shard or dead-stripped: FS_IsArchiveReady (24B) */
/* not in shard or dead-stripped: FS_FlushFile (28B) */
/* not in shard or dead-stripped: FS_SetFileLength (48B) */
/* not in shard or dead-stripped: FS_GetPathName (64B) */
/* not in shard or dead-stripped: FS_GetPathLength (40B) */
/* not in shard or dead-stripped: FS_GetSeekCacheSize (116B) */
/* not in shard or dead-stripped: FS_SetSeekCache (44B) */
/* not in shard or dead-stripped: FS_SeekFile (76B) */
/* not in shard or dead-stripped: FS_ReadFile (88B) */
/* not in shard or dead-stripped: FS_ReadFileAsync (120B) */
/* not in shard or dead-stripped: FS_WriteFileAsync (120B) */
/* not in shard or dead-stripped: FS_OpenDirectory (132B) */
/* not in shard or dead-stripped: FS_CloseDirectory (40B) */
/* not in shard or dead-stripped: FS_ReadDirectory (100B) */
/* not in shard or dead-stripped: FS_SeekDir (104B) */
/* not in shard or dead-stripped: FS_TellDir (24B) */
/* not in shard or dead-stripped: FS_RewindDir (52B) */
/* not in shard or dead-stripped: FSi_CopySafeUnicodeString (356B) */
/* not in shard or dead-stripped: FSi_NormalizePathWtoW (816B) */
/* not in shard or dead-stripped: FS_OpenFileExW (152B) */
/* not in shard or dead-stripped: FS_OpenDirectoryW (152B) */
/* not in shard or dead-stripped: FS_ReadDirectoryW (156B) */
/* not in shard or dead-stripped: FSi_ConvertToDirEntry (152B) */
/* not in shard or dead-stripped: FS_GetLength (12B) */
/* not in shard or dead-stripped: FS_GetPosition (12B) */
/* not in shard or dead-stripped: FS_FindDir (16B) */
/* not in shard or dead-stripped: FS_ReadDir (72B) */
/* not in shard or dead-stripped: FS_ChangeDir (12B) */
/* not in shard or dead-stripped: FS_GetFileInfo (36B) */
/* not in shard or dead-stripped: FSi_GetUnicodeBuffer (228B) */
/* not in shard or dead-stripped: FSi_ReleaseUnicodeBuffer (32B) */
/* not in shard or dead-stripped: FSi_ConvertStringSjisToUnicode (20B) */
/* not in shard or dead-stripped: FSi_ConvertStringUnicodeToSjis (20B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_file.c"
