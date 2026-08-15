/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/spi/ARM9/src/pm.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

/* callees outside this TU, from the claim table */
#define OS_GetProcMode                       sub_020879EC
#define OS_GetCpsrIrq                        sub_020879E0
#define PXIi_HandlerRecvFifoNotEmpty         sub_02088688
#define PXI_IsCallbackReady                  sub_020885EC
#define PXI_SetFifoRecvCallback              sub_020885A0
#define OS_DisableInterrupts                 sub_02087988
#define OS_RestoreInterrupts                 sub_0208799C
#define PXI_SendWordByFifo                   sub_02088610
#define MI_WaitDma                           sub_02082594
#define MI_StopDma                           sub_020825F0
#define OS_IsTickAvailable                   sub_02087058
#define OS_GetBootType                       sub_02087B04
#define GX_DispOff                           sub_0207D42C
#define PMi_WaitBusy                    sub_0208B7BC
#define PMi_DummyCallback               sub_0208B840
#define PMi_CallCallbackAndUnlock       sub_0208B84C
#define PMi_WaitVBlank                  sub_0208B87C
#define PMi_TryToSendPxiDataTillSuccess sub_0208BAF4
#define PMi_SendSleepStart              sub_0208BBB8
#define PM_SendUtilityCommandAsync      sub_0208BC44
#define PM_SendUtilityCommand           sub_0208BC8C
#define PMi_SetLEDAsync                 sub_0208BCC4
#define PMi_SetLED                      sub_0208BD28
#define PM_SetBackLightAsync            sub_0208BD50
#define PM_SetBackLight                 sub_0208BDD8
#define PMi_ForceToPowerOff             sub_0208BE58
#define PMi_SetAmp                      sub_0208BF08
#define PM_SetAmpGain                   sub_0208BF38
#define PM_GetBattery                   sub_0208BF6C
#define PM_GetBackLight                 sub_0208BFD0
#define PM_GetAmp                       sub_0208C030
#define PMi_SendPxiData                 sub_0208C080
#define PM_SetLCDPower                  sub_0208C64C
#define PM_GetLCDPower                  sub_0208C688
#define PMi_SendLEDPatternCommand       sub_0208C6A4
#define PM_GetLEDPattern                sub_0208C6C0
#define PMi_InsertList                  sub_0208C6FC
#define PMi_DeleteList                  sub_0208C788
#define PMi_ExecuteList                 sub_0208C7E0
#define PM_AppendPreSleepCallback       sub_0208C828
#define PMi_InsertPreSleepCallbackEx    sub_0208C848
#define PMi_InsertPostSleepCallbackEx   sub_0208C878
#define PMi_LCDOnAvoidReset             sub_0208C89C
/* stripped or unplaced: PM_Init (148B) */
/* stripped or unplaced: PMi_CommonCallback (136B) */
/* stripped or unplaced: PMi_TryToSendPxiData (132B) */
/* stripped or unplaced: PMi_SetSoundPowerAsync (72B) */
/* stripped or unplaced: PMi_SetSoundPower (40B) */
/* stripped or unplaced: PMi_SetSoundVolumeAsync (72B) */
/* stripped or unplaced: PMi_SetSoundVolume (40B) */
/* stripped or unplaced: PM_ForceToPowerOffAsync (44B) */
/* stripped or unplaced: PM_ForceToPowerOff (60B) */
/* stripped or unplaced: PM_SetAmpAsync (36B) */
/* stripped or unplaced: PM_SetAmp (24B) */
/* stripped or unplaced: PM_SetAmpGainAsync (36B) */
/* stripped or unplaced: PMi_GetSoundPower (80B) */
/* stripped or unplaced: PMi_GetSoundVolume (80B) */
/* stripped or unplaced: PM_GetAmpGain (60B) */
/* stripped or unplaced: PMi_PreSleepForDma (148B) */
/* stripped or unplaced: PM_GoSleepMode (748B) */
/* stripped or unplaced: PMi_SetLCDPower (504B) */
/* stripped or unplaced: PMi_GetLCDOffCount (16B) */
/* stripped or unplaced: PMi_SendLEDPatternCommandAsync (36B) */
/* stripped or unplaced: PM_GetLEDPatternAsync (44B) */
/* stripped or unplaced: PMi_ClearList (4B) */
/* stripped or unplaced: PM_PrependPreSleepCallback (32B) */
/* stripped or unplaced: PM_AppendPostSleepCallback (32B) */
/* stripped or unplaced: PM_PrependPostSleepCallback (32B) */
/* stripped or unplaced: PM_InsertPreSleepCallback (12B) */
/* stripped or unplaced: PM_InsertPostSleepCallback (12B) */
/* stripped or unplaced: PM_DeletePreSleepCallback (24B) */
/* stripped or unplaced: PM_DeletePostSleepCallback (24B) */
/* stripped or unplaced: PM_ClearPreSleepCallback (20B) */
/* stripped or unplaced: PM_ClearPostSleepCallback (20B) */
/* stripped or unplaced: PMi_SetDispOffCount (28B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/spi/ARM9/src/pm.c"
