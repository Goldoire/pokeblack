/* 62/72. Everything matches except the setup of the first call's second
 * argument: the ROM spills a2 to its stack home and reloads it
 *     str r2,[sp] ; adds r0,r1,r0 ; ldr r1,[sp]
 * while mwcc here keeps it in a register and copies
 *     adds r0,r1,r0 ; adds r1,r2,#0 ; str r2,[sp]
 * Same instruction count, pure register-allocation choice. Tried: local
 * copies of the handle slot and of the table entry, `void **`/`u32`
 * parameter types, pointer arithmetic instead of &arr[i]. All identical.
 */
#include "types.h"

/* _0209D950 is a table of 0x18-byte descriptors indexed by the second
 * argument; a0 carries a parallel array of handles at +0x14. */
typedef struct UnkStruct0209D950
{
    u8 unk00[0x18];
} UnkStruct0209D950;

typedef struct UnkStruct0200725C
{
    /* 0x00 */ u8 unk00[0x14];
    /* 0x14 */ void *unk14[1];
} UnkStruct0200725C;

extern UnkStruct0209D950 _0209D950[];

void *sub_0203192C(UnkStruct0209D950 *a0, void *a1);
int sub_02008784(void *a0, int a1);
void **sub_020087D4(void *a0, int a1);
int sub_02031DC0(void *a0, void *a1, void *a2);

int sub_0200725C(UnkStruct0200725C *a0, int a1, void *a2)
{
    a0->unk14[a1] = sub_0203192C(&_0209D950[a1], a2);
    if (sub_02008784(a0, a1) == 0)
    {
        return 0;
    }
    return sub_02031DC0(a0->unk14[a1], a2, *sub_020087D4(a0, a1));
}
