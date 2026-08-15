/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_command.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define SNDi_InitSharedWork                  sub_0208A1D0
#define OS_DisableInterrupts                 sub_02087988
#define SNDi_GetFinishedCommandTag           sub_0208A1AC
#define OS_RestoreInterrupts                 sub_0208799C
#define DC_FlushRange                        sub_020862F0
#define PXI_SendWordByFifo                   sub_02088610
#define SNDi_CallAlarmHandler                sub_0208A010
#define PXI_SetFifoRecvCallback              sub_020885A0
#define PXI_IsCallbackReady                  sub_020885EC
#define OS_IsRunOnEmulator                   sub_02085D24
#define SND_CommandInit          sub_020898A8
#define SND_RecvCommandReply     sub_02089978
#define SND_AllocCommand         sub_02089A78
#define SND_PushCommand          sub_02089B00
#define SND_FlushCommand         sub_02089B38
#define SND_WaitForCommandProc   sub_02089CD4
#define SND_GetCurrentCommandTag sub_02089D40
#define SND_IsFinishedCommandTag sub_02089D6C
#define SND_CountFreeCommand     sub_02089DBC
#define SND_CountReservedCommand sub_02089DF8
#define SND_CountWaitingCommand  sub_02089E34
#define PxiFifoCallback          sub_02089E50
#define InitPXI                  sub_02089E74
#define RequestCommandProc       sub_02089ED8
#define AllocCommand             sub_02089F00
#define IsCommandAvailable       sub_02089F48
/* stripped or unplaced: SND_WaitForFreeCommand (116B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/snd/common/src/snd_command.c"
