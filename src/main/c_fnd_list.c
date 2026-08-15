/* lib/TwlSystem/build/libraries/fnd/src/list.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
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
/* not in shard or dead-stripped: NNS_FndGetNthListObject (72B) */

#include "../../lib/TwlSystem/build/libraries/fnd/src/list.c"
