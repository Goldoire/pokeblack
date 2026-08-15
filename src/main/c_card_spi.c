/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_spi.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_Sleep                             sub_02085A38
#define OS_GetTickLo                         sub_02087170
#define CARDi_CommandBegin             sub_0205A11C
/* stripped or unplaced: CARDi_CommandEnd (128B) */
/* stripped or unplaced: CARDi_CommandReadStatus (92B) */
/* stripped or unplaced: CARDi_CommandCheckBusy (24B) */
/* stripped or unplaced: CARDi_WaitPrevCommand (60B) */
/* stripped or unplaced: CARDi_CommArray (448B) */
/* stripped or unplaced: CARDi_CommReadCore (64B) */
/* stripped or unplaced: CARDi_CommWriteCore (80B) */
/* stripped or unplaced: CARDi_CommVerifyCore (100B) */
/* stripped or unplaced: CARDi_WriteEnable (64B) */
/* stripped or unplaced: CARDi_SendSpiAddressingCommand (148B) */
/* stripped or unplaced: CARDi_InitStatusRegister (84B) */
/* stripped or unplaced: CARDi_ReadBackupCore (112B) */
/* stripped or unplaced: CARDi_ProgramBackupCore (176B) */
/* stripped or unplaced: CARDi_WriteBackupCore (176B) */
/* stripped or unplaced: CARDi_VerifyBackupCore (148B) */
/* stripped or unplaced: CARDi_EraseBackupSectorCore (140B) */
/* stripped or unplaced: CARDi_EraseBackupSubSectorCore (140B) */
/* stripped or unplaced: CARDi_EraseChipCore (88B) */
/* stripped or unplaced: CARDi_SetWriteProtectCore (160B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/card/common/src/card_spi.c"
