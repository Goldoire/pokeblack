/* lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_spi.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
 */
#define SDK_FINALROM

/* callees outside this file */
#define OS_GetTickLo                         sub_02087170

#define CARDi_CommandBegin             sub_0205A11C
/* not in shard or dead-stripped: CARDi_CommandEnd (128B) */
/* not in shard or dead-stripped: CARDi_CommandReadStatus (92B) */
/* not in shard or dead-stripped: CARDi_CommandCheckBusy (24B) */
/* not in shard or dead-stripped: CARDi_WaitPrevCommand (60B) */
/* not in shard or dead-stripped: CARDi_CommArray (448B) */
/* not in shard or dead-stripped: CARDi_CommReadCore (64B) */
/* not in shard or dead-stripped: CARDi_CommWriteCore (80B) */
/* not in shard or dead-stripped: CARDi_CommVerifyCore (100B) */
/* not in shard or dead-stripped: CARDi_WriteEnable (64B) */
/* not in shard or dead-stripped: CARDi_SendSpiAddressingCommand (148B) */
/* not in shard or dead-stripped: CARDi_InitStatusRegister (84B) */
/* not in shard or dead-stripped: CARDi_ReadBackupCore (112B) */
/* not in shard or dead-stripped: CARDi_ProgramBackupCore (176B) */
/* not in shard or dead-stripped: CARDi_WriteBackupCore (176B) */
/* not in shard or dead-stripped: CARDi_VerifyBackupCore (148B) */
/* not in shard or dead-stripped: CARDi_EraseBackupSectorCore (140B) */
/* not in shard or dead-stripped: CARDi_EraseBackupSubSectorCore (140B) */
/* not in shard or dead-stripped: CARDi_EraseChipCore (88B) */
/* not in shard or dead-stripped: CARDi_SetWriteProtectCore (160B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_spi.c"
