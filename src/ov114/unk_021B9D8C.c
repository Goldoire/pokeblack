#include "types.h"

/*
 * ov114 socket transport shims (0x021B9D8C..0x021BA150).
 *
 * The list node ("Ov114Buffer") carries a 0x8000-byte receive buffer at +0x40 with
 * its cursor/count at +0x8040/+0x8044 and the refcount sub_021BEFE4 bumps at
 * +0x8048.  The Ov114Sock hanging off node->unk_10 owns the SSL block (+0xAC).
 * Error codes: -1001 generic, -1002 "connection was reset", -0x38 = EWOULDBLOCK.
 */

typedef struct Ov114Mgr Ov114Mgr;

typedef struct Ov114SockAddr {
    u8 len;                                     /* 0x00 */
    u8 family;                                  /* 0x01 */
    u16 port;                                   /* 0x02 */
    u32 addr;                                   /* 0x04 */
} Ov114SockAddr;

typedef struct Ov114HostEnt {
    u8 pad_00[0x0A];
    s16 h_length;                               /* 0x0A */
    u8 **h_addr_list;                           /* 0x0C */
} Ov114HostEnt;

typedef struct Ov114Ssl {
    u8 pad_000[0x800];
    u32 unk_800;                                /* 0x800 */
    u8 pad_804[0x810 - 0x804];
    void *unk_810;                              /* 0x810 */
    u32 unk_814;                                /* 0x814 */
    u32 unk_818;                                /* 0x818 */
    u8 pad_81C[0x830 - 0x81C];
} Ov114Ssl;

typedef struct Ov114Sock {
    u32 unk_00;
    u32 unk_04;
    u32 unk_08;
    u32 unk_0C;
    u8 pad_10[0x28 - 0x10];
    u32 unk_28;
    u8 pad_2C[0xAC - 0x2C];
    Ov114Ssl *unk_AC;                                /* 0xAC */
    u8 pad_B0[0xC0 - 0xB0];
    u32 unk_C0;                                 /* 0xC0 */
    u32 unk_C4;                                 /* 0xC4 */
    u8 pad_C8[0xD8 - 0xC8];
    u32 unk_D8;                                 /* 0xD8 */
} Ov114Sock;

typedef struct Ov114Buffer {
    u8 pad_00[0x40];
    u8 data[0x8000];                            /* 0x40 */
    u32 off;                                    /* 0x8040 */
    u32 avail;                                  /* 0x8044 */
    s32 refcount;                               /* 0x8048 */
} Ov114Buffer;

extern u32 sub_02082D44(const void *src, void *dst, u32 n);   /* MI_CpuCopy8 */
extern u32 sub_02082BCC(void *dst, u32 val, u32 n);           /* MI_CpuFill8 */
extern void *sub_021BA820(u32 size, u32 align);
extern int sub_0215F480(int fd, const Ov114SockAddr *sa);
extern int sub_0215F4DC(int fd, void *buf, u32 len, int flags);
extern int sub_0215F590(int fd, const void *buf, u32 len, int flags);
extern void sub_0215F638(int fd, int how);
extern Ov114HostEnt *sub_0215F650(const char *name);
extern int sub_0215FAD0(const char *name, u32 *out, int flags);
extern int sub_0215FC80(int fd, Ov114Ssl *ssl);
extern void sub_021B9C80(void);
extern u32 sub_021B9C6C(u32 x);
extern int sub_021B9C78(void);
extern void sub_021BEFCC(void *lock);
extern void sub_021BEFD8(void *lock);
extern Ov114Buffer *sub_021BEBE0(Ov114Mgr *m, void *key);

int sub_021B9E3C(int a, int b, Ov114Sock *s, int fd);
int sub_021B9ECC(Ov114Buffer *n, int fd, void *dst, int len, int flags);
void sub_021BA100(void *dst, const void *src, u32 n);
void sub_021BA13C(void *p, u32 n);
int sub_021BA014(int fd, const void *buf, int len, int flags);

int sub_021B9D8C(int a, int b, Ov114Sock *s, int fd, u32 ip, u32 port)
{
    Ov114SockAddr sa;
    u16 p = (u16)port;
    int rc;

    sa.len = 8;
    sa.family = 2;
    sa.port = (u16)(((p >> 8) & 0xFF) | ((p << 8) & 0xFF00));
    sa.addr = ip;
    if (s->unk_08 != 0 && s->unk_0C == 0) {
        rc = sub_021B9E3C(a, b, s, fd);
        if (rc < 0) {
            return rc;
        }
    }
    if (sub_0215F480(fd, &sa) < 0) {
        if (s->unk_00 != 0) {
            return -1002;
        }
        return -1001;
    }
    return 0;
}

int sub_021B9E3C(int a, int b, Ov114Sock *s, int fd)
{
    Ov114Ssl *ssl = s->unk_AC;

    if (ssl == NULL) {
        ssl = sub_021BA820(0x830, 4);
        s->unk_AC = ssl;
        sub_021BA13C(ssl, 0x830);
    }
    ssl->unk_814 = s->unk_C0;
    ssl->unk_818 = s->unk_C4;
    ssl->unk_800 = s->unk_28;
    if (s->unk_D8 != 0) {
        ssl->unk_810 = (void *)sub_021B9C78;
    } else {
        ssl->unk_810 = (void *)sub_021B9C6C;
    }
    if (sub_0215FC80(fd, ssl) < 0) {
        return -1001;
    }
    sub_021B9C80();
    return 0;
}

int sub_021B9ECC(Ov114Buffer *n, int fd, void *dst, int len, int flags)
{
    u8 *buf = n->data;
    int got = 0;
    int rc;

    if (len > 0) {
        if (n->avail == 0) {
            rc = sub_0215F4DC(fd, buf, 0x8000, flags);
            if (rc <= 0) {
                return rc;
            }
            n->avail = rc;
            n->off = 0;
        }
        rc = n->avail;
        if (rc != 0) {
            if ((u32)len <= (u32)rc) {
                rc = len;
            }
            sub_021BA100(dst, &buf[n->off], rc);
            n->avail -= rc;
            if (n->avail != 0) {
                n->off += rc;
            } else {
                sub_021BA13C(buf, 0x8000);
                n->off = 0;
            }
            got = rc;
        }
    }
    return got;
}

int sub_021B9F94(Ov114Mgr *m, Ov114Sock *s, int fd, void *dst, int len, int flags)
{
    Ov114Buffer *n = sub_021BEBE0(m, s);
    int rc;

    if (n != NULL) {
        rc = sub_021B9ECC(n, fd, dst, len, flags);
    } else {
        return -1001;
    }
    if (rc >= 0) {
        return rc;
    }
    if (s->unk_00 != 0) {
        return -1002;
    }
    if (rc == -0x38) {
        return 0;
    }
    return -1001;
}

int sub_021BA014(int fd, const void *buf, int len, int flags)
{
    return sub_0215F590(fd, buf, len, flags);
}

int sub_021BA020(Ov114Sock *s, int fd, const void *buf, int len, int flags)
{
    int rc = sub_021BA014(fd, buf, len, flags);

    if (rc >= 0) {
        return rc;
    }
    if (s->unk_00 != 0) {
        return -1002;
    }
    if (rc == -0x38) {
        return 0;
    }
    return -1001;
}

void sub_021BA068(void *lock, void *unused, int fd)
{
    sub_021BEFCC(lock);
    if (fd >= 0) {
        sub_0215F638(fd, 2);
    }
    sub_021BEFD8(lock);
}

u32 sub_021BA098(void *unused, const char *name)
{
    u32 addr = 0;
    u32 tmp;
    Ov114HostEnt *he;

    if (sub_0215FAD0(name, &tmp, 0) != 0) {
        addr = tmp;
    } else {
        he = sub_0215F650(name);
        if (he != NULL && he->h_length > 0) {
            sub_021BA100(&addr, he->h_addr_list[0], 4);
        }
    }
    return addr;
}

void sub_021BA100(void *dst, const void *src, u32 n)
{
    sub_02082D44(src, dst, n);
}

void sub_021BA13C(void *p, u32 n)
{
    sub_02082BCC(p, 0, n);
}
