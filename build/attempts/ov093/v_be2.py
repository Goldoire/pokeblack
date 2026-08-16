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

typedef struct BEQ {
    u32 depth;
    BEI *list;
    u32 numUsed;
} BEQ;

extern BEQ _021F3CB0;
extern BEI *_021F3CBC[132];

void sub_021D6F08(void);
void sub_021D7494(BEI *item);
'''

NAME = "probe"

_A = r'''
void sub_021D7040(BEI *item)
{
    if (item == NULL) {
        return;
    }
    if (!item->b29) {
        return;
    }
    if (item->b24) {
        item->b27 = TRUE;
        return;
    }
    if (_021F3CB0.list == item) {
        _021F3CB0.list = item->next;
    }
    if (item->prev != NULL) {
        item->prev->next = item->next;
    }
    if (item->next != NULL) {
        item->next->prev = item->prev;
    }
    sub_021D6F08();
    sub_021D7494(item);
}
'''

_B = _A.replace("if (item == NULL) {\n        return;\n    }\n    if (!item->b29) {\n        return;\n    }\n    if (item->b24) {\n        item->b27 = TRUE;\n        return;\n    }\n",
"""if (item != NULL && item->b29) {
        if (item->b24) {
            item->b27 = TRUE;
            return;
        }
""").replace("    sub_021D7494(item);\n}", "    sub_021D7494(item);\n    }\n}")

_C = r'''
void sub_021D7040(BEI *item)
{
    if (item == NULL) {
        return;
    }
    if (item->b29 == 0) {
        return;
    }
    if (item->b24 != 0) {
        item->b27 = 1;
        return;
    }
    if (item == _021F3CB0.list) {
        _021F3CB0.list = item->next;
    }
    if (item->prev != NULL) {
        item->prev->next = item->next;
    }
    if (item->next != NULL) {
        item->next->prev = item->prev;
    }
    sub_021D6F08();
    sub_021D7494(item);
}
'''

# allocator / free: pins the pool globals
_ALLOC = r'''
BEI *sub_021D7474(void)
{
    if (_021F3CB0.numUsed == 132) {
        return NULL;
    }
    return _021F3CBC[_021F3CB0.numUsed++];
}

void sub_021D7494(BEI *item)
{
    if (_021F3CB0.numUsed != 0) {
        sub_021D74BC(item);
        _021F3CB0.numUsed--;
        _021F3CBC[_021F3CB0.numUsed] = item;
    }
}
'''

VARIANTS = [_A, _B, _C]
