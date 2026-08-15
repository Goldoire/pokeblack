#include "types.h"

// Posts a message into the queue at *_02146940 + 4 when the sender id is
// enabled. Each id has its own small builder just below it in the ROM.

struct UnkMsg02165000
{
    u8 unk_00[0x30];
    u16 unk_30;
    u16 unk_32;
    u16 unk_34;
};

void sub_020270AC(u32 param0, void *dest);
void sub_0202744C(struct UnkMsg02165000 *msg);

extern u8 *_02146940;
extern u8 _02171CA0[];

int sub_02027060(int id);
void sub_02026FB8(void *msg);
void sub_0216544C(struct UnkMsg02165000 *msg, u32 param1);
void sub_02165490(struct UnkMsg02165000 *msg, u32 param1);
void sub_021654D4(struct UnkMsg02165000 *msg, u32 param1);
void sub_02165518(struct UnkMsg02165000 *msg, u32 param1);
void sub_02165794(struct UnkMsg02165000 *msg, u32 param1);

void sub_021650BC(void *msg, u32 param1);
void sub_021650F4(void *msg, u32 param1);
void sub_0216512C(void *msg, u32 param1);
void sub_02165164(void *msg, u32 param1);
void sub_0216519C(void *msg, u32 param1);
void sub_021651D4(void *msg, u32 param1);
void sub_0216520C(void *msg, u32 param1);
void sub_02165244(void *msg, u32 param1);
void sub_0216527C(void *msg, u32 param1);
void sub_021652B4(void *msg, u32 param1);
void sub_021652EC(void *msg, u32 param1);
void sub_02165334(void *msg, u32 param1);
void sub_02165368(void *msg);
void sub_021653B4(void *msg, u32 param1);
void sub_021653E8(void *msg);
void sub_02165418(void *msg);




void sub_0216555C(void *msg, u32 param1);
void sub_02165590(void *msg);
void sub_021655C4(void *msg, u32 param1);
void sub_021655F8(void *msg);
void sub_02165628(void *msg);
void sub_0216565C(void *msg, u32 param1);
void sub_02165690(void *msg);
void sub_021656C4(void *msg);
void sub_021656F8(void *msg, u32 param1);
void sub_02165730(void *msg);
void sub_02165760(void *msg);

void sub_021657D8(void *msg, u32 param1);
void sub_0216586C(void *msg, u32 param1);

void sub_02165094(u32 param0)
{
    if (sub_02027060(0x2))
    {
        sub_021650BC(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_021650CC(u32 param0)
{
    if (sub_02027060(0x3))
    {
        sub_021650F4(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_02165104(u32 param0)
{
    if (sub_02027060(0x4))
    {
        sub_0216512C(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_0216513C(u32 param0)
{
    if (sub_02027060(0x5))
    {
        sub_02165164(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_02165174(u32 param0)
{
    if (sub_02027060(0x6))
    {
        sub_0216519C(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_021651AC(u32 param0)
{
    if (sub_02027060(0x7))
    {
        sub_021651D4(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_021651E4(u32 param0)
{
    if (sub_02027060(0x8))
    {
        sub_0216520C(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_0216521C(u32 param0)
{
    if (sub_02027060(0x9))
    {
        sub_02165244(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_02165254(u32 param0)
{
    if (sub_02027060(0xa))
    {
        sub_0216527C(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_0216528C(u32 param0)
{
    if (sub_02027060(0xb))
    {
        sub_021652B4(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_021652C4(u32 param0)
{
    if (sub_02027060(0x12))
    {
        sub_021652EC(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_0216530C(u32 param0)
{
    if (sub_02027060(0x13))
    {
        sub_02165334(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_02165344(void)
{
    if (sub_02027060(0x15))
    {
        sub_02165368(_02146940 + 4);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_02165374(u32 param0)
{
    u32 i;

    if (sub_02027060(0x16))
    {
        for (i = 0; i < 5; i++)
        {
            if (param0 == _02171CA0[i])
            {
                sub_021653B4(_02146940 + 4, param0);
                sub_02026FB8(_02146940 + 4);
                return;
            }
        }
    }
}

void sub_021653C4(void)
{
    if (sub_02027060(0x17))
    {
        sub_021653E8(_02146940 + 4);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_021653F4(void)
{
    if (sub_02027060(0x1e))
    {
        sub_02165418(_02146940 + 4);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_02165424(u32 param0)
{
    if (sub_02027060(0x1f))
    {
        sub_0216544C(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_02165468(u32 param0)
{
    if (sub_02027060(0x20))
    {
        sub_02165490(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_021654AC(u32 param0)
{
    if (sub_02027060(0x21))
    {
        sub_021654D4(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_021654F0(u32 param0)
{
    if (sub_02027060(0x22))
    {
        sub_02165518(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_02165534(u32 param0)
{
    if (sub_02027060(0x24))
    {
        sub_0216555C(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_0216556C(void)
{
    if (sub_02027060(0x25))
    {
        sub_02165590(_02146940 + 4);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_0216559C(u32 param0)
{
    if (sub_02027060(0x26))
    {
        sub_021655C4(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_021655D4(void)
{
    if (sub_02027060(0x27))
    {
        sub_021655F8(_02146940 + 4);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_02165604(void)
{
    if (sub_02027060(0x28))
    {
        sub_02165628(_02146940 + 4);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_02165634(u32 param0)
{
    if (sub_02027060(0x29))
    {
        sub_0216565C(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_0216566C(void)
{
    if (sub_02027060(0x2a))
    {
        sub_02165690(_02146940 + 4);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_021656A0(void)
{
    if (sub_02027060(0x2b))
    {
        sub_021656C4(_02146940 + 4);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_021656D0(u32 param0)
{
    if (sub_02027060(0x2c))
    {
        sub_021656F8(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_0216570C(void)
{
    if (sub_02027060(0x2d))
    {
        sub_02165730(_02146940 + 4);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_0216573C(void)
{
    if (sub_02027060(0x2e))
    {
        sub_02165760(_02146940 + 4);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_0216576C(u32 param0)
{
    if (sub_02027060(0x2f))
    {
        sub_02165794(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_021657B0(u32 param0)
{
    if (sub_02027060(0x30))
    {
        sub_021657D8(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}

void sub_02165844(u32 param0)
{
    if (sub_02027060(0x31))
    {
        sub_0216586C(_02146940 + 4, param0);
        sub_02026FB8(_02146940 + 4);
    }
}


void sub_0216544C(struct UnkMsg02165000 *msg, u32 param1)
{
    msg->unk_30 = 0x1f;
    sub_020270AC(param1, &msg->unk_34);
    sub_0202744C(msg);
}

void sub_02165490(struct UnkMsg02165000 *msg, u32 param1)
{
    msg->unk_30 = 0x20;
    sub_020270AC(param1, &msg->unk_34);
    sub_0202744C(msg);
}

void sub_021654D4(struct UnkMsg02165000 *msg, u32 param1)
{
    msg->unk_30 = 0x21;
    sub_020270AC(param1, &msg->unk_34);
    sub_0202744C(msg);
}

void sub_02165518(struct UnkMsg02165000 *msg, u32 param1)
{
    msg->unk_30 = 0x22;
    sub_020270AC(param1, &msg->unk_34);
    sub_0202744C(msg);
}

void sub_02165794(struct UnkMsg02165000 *msg, u32 param1)
{
    msg->unk_30 = 0x2f;
    sub_020270AC(param1, &msg->unk_34);
    sub_0202744C(msg);
}
