/* lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_proc_mem.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define FS_GetArchiveName                    sub_02078530
#define STD_GetStringLength                  sub_0208CC78
#define STD_TSPrintf                         sub_0208D7E0
#define OS_DisableInterrupts                 sub_02087988
#define FS_InitArchive                       sub_02078360
#define FS_SetArchiveProc                    sub_0207A5A8
#define FS_LoadArchive                       sub_0207A4B0
#define OS_Terminate                         sub_02088234
#define OS_RestoreInterrupts                 sub_0208799C
#define FS_OpenFileDirect                    sub_02078964
#define FS_InitFile                          sub_020788AC

#define FSi_MemArchiveProc       sub_0207A7C4
#define FSi_InitMemArchive       sub_0207A890
#define FS_CreateFileFromMemory  sub_0207A940
/* not in shard or dead-stripped: FS_OpenTopLevelDirectory (64B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_proc_mem.c"
