#include "types.h"

void sub_02023FD8(void);
void sub_02022174(void);
void sub_0200F734(void);
void sub_02005BC0(void);
void sub_020065FC(void);
void sub_02026728(void);
void sub_02010DCC(void);
int sub_02008390(void);
void sub_02005C28(int a0);

void sub_020052EC(void)
{
    sub_02023FD8();
    sub_02022174();
    sub_0200F734();
    sub_02005BC0();
    sub_020065FC();
    sub_02026728();
    sub_02010DCC();
}

void sub_0200530C(void)
{
    if (sub_02008390() == 0)
    {
        sub_02005C28(1);
        return;
    }
    sub_02005C28(0);
}
