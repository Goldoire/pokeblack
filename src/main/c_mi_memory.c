/* TwlSDK/TwlSystem lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_memory.c
 * Renamed to sub_<realRAM> per function so verify_functions.py can
 * place them. The retail ARM9 is built with SDK_FINALROM.
 */
#define SDK_FINALROM

#define MIi_CpuClear16     sub_02082A48
#define MIi_CpuCopy16      sub_02082A60
#define MIi_CpuClear32     sub_02082A7C
#define MIi_CpuCopy32      sub_02082A90
#define MIi_CpuSend32      sub_02082AA8
#define MIi_CpuClearFast   sub_02082AC0
#define MIi_CpuCopyFast    sub_02082B0C
#define MI_Copy32B         sub_02082B44
#define MI_Copy36B         sub_02082B60
#define MI_Copy48B         sub_02082B7C
#define MI_Copy64B         sub_02082BA0
#define MI_CpuFill8        sub_02082BCC
#define MI_CpuFill         sub_02082C60
#define MI_CpuCopy8        sub_02082D44
#define MI_CpuComp8        sub_02082E74
#define MI_CpuCopy         sub_02082EA4
#define MI_CpuMove         sub_02083194
#define MI_Zero36B         sub_020834A8
/* stripped or unplaced: MIi_CpuSend16 (28B) */
/* stripped or unplaced: MIi_CpuRecv16 (28B) */
/* stripped or unplaced: MIi_CpuPipe16 (28B) */
/* stripped or unplaced: CpuCopy16Reverse (32B) */
/* stripped or unplaced: MIi_CpuMove16 (36B) */
/* stripped or unplaced: MIi_CpuFind16 (48B) */
/* stripped or unplaced: MIi_CpuComp16 (48B) */
/* stripped or unplaced: MIi_CpuRecv32 (24B) */
/* stripped or unplaced: MIi_CpuPipe32 (28B) */
/* stripped or unplaced: CpuCopy32Reverse (32B) */
/* stripped or unplaced: MIi_CpuMove32 (36B) */
/* stripped or unplaced: MIi_CpuFind32 (48B) */
/* stripped or unplaced: MIi_CpuComp32 (64B) */
/* stripped or unplaced: MIi_CpuSendFast (84B) */
/* stripped or unplaced: MIi_CpuRecvFast (84B) */
/* stripped or unplaced: CpuCopyFastReverse (64B) */
/* stripped or unplaced: MIi_CpuMoveFast (36B) */
/* stripped or unplaced: MI_Copy16B (20B) */
/* stripped or unplaced: MI_Copy128B (76B) */
/* stripped or unplaced: MI_CpuFind8 (148B) */
/* stripped or unplaced: MI_Zero32B (14B) */
/* stripped or unplaced: MI_Zero48B (16B) */
/* stripped or unplaced: MI_Zero64B (20B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_memory.c"
