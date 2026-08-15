/* lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_proc_rom.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define FS_NotifyArchiveAsyncEnd             sub_02078734
#define CARD_LockRom                         sub_02075E10
#define CARD_UnlockRom                       sub_02075E80
#define CARD_Init                            sub_02075CAC
#define FS_InitArchive                       sub_02078360
#define FS_RegisterArchiveName               sub_02078384
#define CARD_GetOwnRomHeader                 sub_02075DF8
#define FS_SetArchiveProc                    sub_0207A5A8
#define FS_LoadArchive                       sub_0207A4B0
#define FS_SetCurrentDirectory               sub_02077F44
#define FS_ReleaseArchiveName                sub_02078484
#define OS_DisableInterrupts                 sub_02087988
#define FS_SuspendArchive                    sub_02078648
#define FS_ResumeArchive                     sub_020786D8
#define OS_RestoreInterrupts                 sub_0208799C
#define FS_LoadArchiveTables                 sub_0207A5C8
#define FS_OpenFileDirect                    sub_02078964

#define FSi_OnRomReadDone         sub_0207A9C8
#define FSi_ReadRomCallback       sub_0207A9EC
#define FSi_EmptyArchiveProc      sub_0207AAE4
#define FSi_ReadDummyCallback     sub_0207AAF8
#define FSi_WriteDummyCallback    sub_0207AB00
#define FSi_OverrideRomArchive    sub_0207AB08
#define FSi_InitRomArchive        sub_0207AB10
#define FS_SetDefaultDMA          sub_0207AC64
#define FS_TryLoadTable           sub_0207ACB4
#define FS_CreateFileFromRom      sub_0207ACD4
/* not in shard or dead-stripped: FSi_IsUnreadableRomOffset (8B) */
/* not in shard or dead-stripped: FSi_RomArchiveProc (112B) */
/* not in shard or dead-stripped: FSi_EndRomArchive (84B) */
/* not in shard or dead-stripped: FS_GetDefaultDMA (16B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/fs/common/src/fs_proc_rom.c"
