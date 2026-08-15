#include "types.h"

/* 0x021461E0: +0x04 holds the handle sub_0203D7C8 returns and is tested
 * before being replaced. */
typedef struct UnkStruct021461E0
{
    /* 0x00 */ u32 unk00;
    /* 0x04 */ void *unk04;
} UnkStruct021461E0;

extern UnkStruct021461E0 _021461E0;
extern u8 _020A7240[];
extern u8 _020A7244[];

void sub_02034714(void *a0, int a1, void *a2);
void *sub_0203D7C8(void *a0, u32 a1, void *a2, u32 a3);

void sub_02010794(void *a0)
{
    if (_021461E0.unk04 != NULL)
    {
        sub_02034714(_020A7240, 0, _020A7240);
    }
    _021461E0.unk04 = sub_0203D7C8(a0, 0xA00, _020A7244, 0x1C0);
}
