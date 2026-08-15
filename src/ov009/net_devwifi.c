#include "types.h"

BOOL sub_0215568C(void);
BOOL sub_02156690(BOOL param0);
void sub_02156730(void);
int sub_021562EC(void);
int sub_02156874(void);

BOOL sub_02155234(void)
{
    return sub_0215568C();
}

BOOL sub_02155244(void *param0)
{
    if (sub_02156690(param0 == NULL)) {
        sub_02156730();
        return TRUE;
    }

    return FALSE;
}

BOOL sub_02155294(void)
{
    if (sub_021562EC() == -1) {
        return FALSE;
    }

    return TRUE;
}

BOOL sub_02155338(void)
{
    if (sub_02156874() == 6) {
        return TRUE;
    }

    return FALSE;
}
