/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_proc_mem.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define FS_GetArchiveName                    sub_02078530
#define STD_GetStringLength                  sub_0208CC80
#define STD_TSPrintf                         sub_0208D7E8
#define OS_DisableInterrupts                 sub_02087988
#define FS_InitArchive                       sub_02078360
#define FS_SetArchiveProc                    sub_0207A5A8
#define FS_LoadArchive                       sub_0207A4B0
#define OS_Terminate                         sub_0208823C
#define OS_RestoreInterrupts                 sub_0208799C
#define FS_OpenFileDirect                    sub_02078964
#define FS_InitFile                          sub_020788AC
#define FSi_MemArchiveProc       sub_0207A7C4
#define FSi_InitMemArchive       sub_0207A890
#define FS_CreateFileFromMemory  sub_0207A940
/* stripped or unplaced: FS_OpenTopLevelDirectory (64B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_proc_mem.c"
