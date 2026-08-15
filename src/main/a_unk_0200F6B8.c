#include "types.h"

/* 0x0214617C: 0x64 bytes (both functions below MI_CpuFill8 it with that
 * length); the first three words hold the handles sub_02030734 returns. */
typedef struct UnkStruct0214617C
{
    /* 0x00 */ void *unk00;
    /* 0x04 */ void *unk04;
    /* 0x08 */ void *unk08;
    /* 0x0C */ u8 unk0C[0x58];
} UnkStruct0214617C;

extern UnkStruct0214617C _0214617C;
extern u8 _020A7234[];

void sub_0203064C(int a0, int a1, u32 a2);
void sub_02082BCC(void *dst, int val, u32 size);
void *sub_02030734(u16 a0, u32 a1, u32 a2, void *a3, u32 a4);

void sub_0200F6B8(void)
{
    sub_0203064C(1, 8, 0x4920);
    sub_02082BCC(&_0214617C, 0, 0x64);
}

void sub_0200F6D8(int a0)
{
    sub_02082BCC(&_0214617C, 0, 0x64);
    _0214617C.unk00 = sub_02030734((u16)a0, 0x4000, 0, _020A7234, 0xBB);
    _0214617C.unk04 = sub_02030734((u16)a0, 0x800, 0, _020A7234, 0xBC);
    _0214617C.unk08 = sub_02030734((u16)a0, 0x20, 0, _020A7234, 0xBD);
}
