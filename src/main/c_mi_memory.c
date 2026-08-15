/* lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_memory.c, as linked into the retail ARM9.
 * Each function is renamed to sub_<realRAM> so verify_functions.py can place
 * it. SDK_FINALROM is what the retail build used: without it the merged .bss
 * of a translation unit comes out in a different order and every static
 * variable offset in the generated code is wrong.
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
/* not in shard or dead-stripped: MIi_CpuSend16 (28B) */
/* not in shard or dead-stripped: MIi_CpuRecv16 (28B) */
/* not in shard or dead-stripped: MIi_CpuPipe16 (28B) */
/* not in shard or dead-stripped: CpuCopy16Reverse (32B) */
/* not in shard or dead-stripped: MIi_CpuMove16 (36B) */
/* not in shard or dead-stripped: MIi_CpuFind16 (48B) */
/* not in shard or dead-stripped: MIi_CpuComp16 (48B) */
/* not in shard or dead-stripped: MIi_CpuRecv32 (24B) */
/* not in shard or dead-stripped: MIi_CpuPipe32 (28B) */
/* not in shard or dead-stripped: CpuCopy32Reverse (32B) */
/* not in shard or dead-stripped: MIi_CpuMove32 (36B) */
/* not in shard or dead-stripped: MIi_CpuFind32 (48B) */
/* not in shard or dead-stripped: MIi_CpuComp32 (64B) */
/* not in shard or dead-stripped: MIi_CpuSendFast (84B) */
/* not in shard or dead-stripped: MIi_CpuRecvFast (84B) */
/* not in shard or dead-stripped: CpuCopyFastReverse (64B) */
/* not in shard or dead-stripped: MIi_CpuMoveFast (36B) */
/* not in shard or dead-stripped: MI_Copy16B (20B) */
/* not in shard or dead-stripped: MI_Copy128B (76B) */
/* not in shard or dead-stripped: MI_CpuFind8 (148B) */
/* not in shard or dead-stripped: MI_Zero32B (14B) */
/* not in shard or dead-stripped: MI_Zero48B (16B) */
/* not in shard or dead-stripped: MI_Zero64B (20B) */

#include "../../lib/NitroSDK/TwlSDK/build/libraries/mi/common/src/mi_memory.c"
