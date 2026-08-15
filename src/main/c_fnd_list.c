/* TwlSDK/TwlSystem lib/TwlSystem/build/libraries/fnd/src/list.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define NNS_FndInitList          sub_02060468
#define SetFirstObject           sub_02060480
#define NNS_FndAppendListObject  sub_020604AC
#define NNS_FndPrependListObject sub_02060500
#define NNS_FndInsertListObject  sub_02060550
#define NNS_FndRemoveListObject  sub_020605B4
#define NNS_FndGetNextListObject sub_02060614
#define NNS_FndGetPrevListObject sub_0206062C
/* stripped or unplaced: NNS_FndGetNthListObject (72B) */

#include "../../lib/TwlSystem/build/libraries/fnd/src/list.c"
