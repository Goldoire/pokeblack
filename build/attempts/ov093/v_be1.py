PRELUDE = r'''
#include "types.h"

typedef struct BEI BEI;

struct BEI {
    BEI *prev;
    BEI *next;
    const void *handlers;
    void *check;
    int type;
    u32 order;
    u32 seq : 16;
    u32 count : 8;
    u32 b24 : 1;
    u32 b25 : 1;
    u32 b26 : 1;
    u32 b27 : 1;
    u32 b28 : 1;
    u32 b29 : 1;
    u32 b30 : 1;
    u32 b31 : 1;
    u32 work[7];
    u16 subID;
    u8 pokeID;
    u8 side;
};
'''

NAME = "probe"

VARIANTS = [
# 0: sub_021D7090
r'''
void sub_021D7090(BEI *item) { item->type = 6; }
BOOL sub_021D7098(BEI *item) { if (item->type == 6) { return TRUE; } return FALSE; }
u16 sub_021D70A8(BEI *item) { return item->subID; }
u8 sub_021D70AC(BEI *item) { return item->side; }
u32 sub_021D70B4(BEI *item, int i) { return item->work[i]; }
void sub_021D70BC(BEI *item) { item->b26 = TRUE; }
void sub_021D70C8(BEI *item) { if (item->b24) { item->b28 = TRUE; } }
void sub_021D70DC(BEI *item, int i, u32 v) { item->work[i] = v; }
''',
]
