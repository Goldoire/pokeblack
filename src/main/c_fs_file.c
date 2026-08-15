/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_file.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define STD_GetStringLength                  sub_0208CC80
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define FS_NormalizePath                     sub_02078078
#define FSi_SendCommand                      sub_02077D80
#define FS_GetArchiveName                    sub_02078530
#define MI_CpuMove                           sub_02083194
#define _u32_div_f                           sub_0209C2B8
#define FSi_GetFileLengthIfProc              sub_0207A530
#define FSi_GetFilePositionIfProc            sub_0207A528
#define MI_CpuFill8                          sub_02082BCC
#define FS_FindArchive                       sub_02077EB8
#define MI_CpuCopy8                          sub_02082D44
#define FS_SetCurrentDirectory               sub_02077F44
#define OS_InitMessageQueue                  sub_02085D94
#define OS_SendMessage                       sub_02085DBC
#define OS_ReceiveMessage                    sub_02085E50
#define STD_ConvertStringUnicodeToSjis       sub_02031754
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
/* stripped or unplaced: FSi_DecrementUnicodePosition (72B) */
/* stripped or unplaced: FSi_DecrementUnicodePositionToSlash (56B) */
/* stripped or unplaced: FS_CancelFile (72B) */
/* stripped or unplaced: FS_CreateFile (116B) */
/* stripped or unplaced: FS_DeleteFile (108B) */
/* stripped or unplaced: FS_RenameFile (156B) */
/* stripped or unplaced: FS_GetPathInfo (116B) */
/* stripped or unplaced: FS_SetPathInfo (116B) */
/* stripped or unplaced: FS_CreateDirectory (116B) */
/* stripped or unplaced: FS_DeleteDirectory (108B) */
/* stripped or unplaced: FS_RenameDirectory (156B) */
/* stripped or unplaced: FSi_GetFullPath (128B) */
/* stripped or unplaced: FSi_ComplementDirectory (292B) */
/* stripped or unplaced: FS_CreateFileAuto (80B) */
/* stripped or unplaced: FS_DeleteFileAuto (12B) */
/* stripped or unplaced: FS_RenameFileAuto (84B) */
/* stripped or unplaced: FS_CreateDirectoryAuto (80B) */
/* stripped or unplaced: FS_DeleteDirectoryAuto (488B) */
/* stripped or unplaced: FS_RenameDirectoryAuto (84B) */
/* stripped or unplaced: FS_GetArchiveResource (96B) */
/* stripped or unplaced: FSi_GetSpaceToCreateDirectoryEntries (184B) */
/* stripped or unplaced: FS_HasEnoughSpaceToCreateFile (132B) */
/* stripped or unplaced: FS_IsArchiveReady (24B) */
/* stripped or unplaced: FS_FlushFile (28B) */
/* stripped or unplaced: FS_SetFileLength (48B) */
/* stripped or unplaced: FS_GetPathName (64B) */
/* stripped or unplaced: FS_GetPathLength (40B) */
/* stripped or unplaced: FS_GetSeekCacheSize (116B) */
/* stripped or unplaced: FS_SetSeekCache (44B) */
/* stripped or unplaced: FS_SeekFile (76B) */
/* stripped or unplaced: FS_ReadFile (88B) */
/* stripped or unplaced: FS_ReadFileAsync (120B) */
/* stripped or unplaced: FS_WriteFileAsync (120B) */
/* stripped or unplaced: FS_OpenDirectory (132B) */
/* stripped or unplaced: FS_CloseDirectory (40B) */
/* stripped or unplaced: FS_ReadDirectory (100B) */
/* stripped or unplaced: FS_SeekDir (104B) */
/* stripped or unplaced: FS_TellDir (24B) */
/* stripped or unplaced: FS_RewindDir (52B) */
/* stripped or unplaced: FSi_CopySafeUnicodeString (356B) */
/* stripped or unplaced: FSi_NormalizePathWtoW (816B) */
/* stripped or unplaced: FS_OpenFileExW (152B) */
/* stripped or unplaced: FS_OpenDirectoryW (152B) */
/* stripped or unplaced: FS_ReadDirectoryW (156B) */
/* stripped or unplaced: FSi_ConvertToDirEntry (152B) */
/* stripped or unplaced: FS_GetLength (12B) */
/* stripped or unplaced: FS_GetPosition (12B) */
/* stripped or unplaced: FS_FindDir (16B) */
/* stripped or unplaced: FS_ReadDir (72B) */
/* stripped or unplaced: FS_ChangeDir (12B) */
/* stripped or unplaced: FS_GetFileInfo (36B) */
/* stripped or unplaced: FSi_GetUnicodeBuffer (228B) */
/* stripped or unplaced: FSi_ReleaseUnicodeBuffer (32B) */
/* stripped or unplaced: FSi_ConvertStringSjisToUnicode (20B) */
/* stripped or unplaced: FSi_ConvertStringUnicodeToSjis (20B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_file.c"
