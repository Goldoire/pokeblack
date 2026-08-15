#include "types.h"
#include "fld_fieldsys.h"
void sub_02030DA4(void *a0);
void sub_020307B0(void *ptr);
void sub_021D31A4(void *vreq);
void sub_021C6D5C(void *taskManager);
void sub_02030EAC(void *task);
void sub_0218CA4C(void *g3dMapper);
void sub_021890C8(FieldSystem *fieldSystem);
void sub_0204A5AC(void);
void sub_020450C8(void);
void sub_02188E38(FieldSystem *fieldSystem);
void sub_02034A5C(void *a0);
BOOL sub_02013CC8(u16 a0);
BOOL sub_02013CE0(u16 a0);

int sub_02188AD4(void *a0, FieldSystem *fieldSystem)
{
    sub_02030DA4(fieldSystem->unk110);
    sub_020307B0(fieldSystem->unk114);
    sub_021D31A4(fieldSystem->vreq);
    fieldSystem->vreq = NULL;
    sub_021C6D5C(fieldSystem->taskManager);
    sub_02030EAC(fieldSystem->task0AC);
    sub_0218CA4C(fieldSystem->g3dMapper);
    sub_021890C8(fieldSystem);
    sub_0204A5AC();
    sub_020450C8();
    sub_02188E38(fieldSystem);
    sub_02034A5C((sub_02013CC8(fieldSystem->unk0D0) == TRUE ||
                  sub_02013CE0(fieldSystem->unk0D0) == TRUE) ? (void *)0x13 : (void *)0x12);
    return 2;
}
