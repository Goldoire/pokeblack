/* 103/132. Prologue, the `add pc` jump table, the table's seven halfword
 * entries and every basic-block boundary match the ROM exactly -- the case
 * order below (6, 1, 2, 0|5, 3|4) is what reproduces the table.
 *
 * The one thing that does not match is how the argument constants are
 * materialised. The ROM loads every one of 0x72/9/0xD/0xA/0xB/0xE/0xF from
 * the literal pool at 0x0200F2B8 (`ldr r0,[pc,#..]`), mwcc here emits
 * `movs r0,#imm`. Tried: int and u32 arguments, `(void *)` casts, -O4,s and
 * -O2. Something about the real source forces those constants into the pool.
 *
 * sub_0200F17C (0x0200F17C, 184 bytes) is the same function shape with the
 * same constants and the same jump-table idiom, so whatever cracks this
 * cracks both.
 */
#include "types.h"

void sub_02034A5C(void *a0);
void sub_02034AC4(void *a0);

void sub_0200F234(u32 a0)
{
    switch (a0)
    {
    case 6:
        sub_02034A5C((void *)0x72);
        sub_02034A5C((void *)0x9);
        sub_02034A5C((void *)0xD);
        sub_02034AC4((void *)0xA);
        sub_02034AC4((void *)0xB);
        break;
    case 1:
        sub_02034A5C((void *)0x9);
        sub_02034A5C((void *)0xD);
        sub_02034AC4((void *)0xA);
        sub_02034AC4((void *)0xB);
        break;
    case 2:
        sub_02034A5C((void *)0x9);
        sub_02034A5C((void *)0xD);
        sub_02034AC4((void *)0xA);
        sub_02034AC4((void *)0xB);
        break;
    case 0:
    case 5:
        sub_02034A5C((void *)0xE);
        break;
    case 3:
    case 4:
        sub_02034A5C((void *)0xF);
        break;
    }
}
