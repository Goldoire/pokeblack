#ifndef MSL_STDDEF_H
#define MSL_STDDEF_H

/*
 * Minimal <stddef.h> for the MWCC build. The real Metrowerks MSL is not in
 * the tree; NNS (nnsys/fnd/list.h) and a few SDK headers need only these.
 * Nothing here affects code generation of game code -- it exists so that
 * <nnsys.h> can be included at all.
 */

#ifndef MSL_SIZE_T_DEFINED
#define MSL_SIZE_T_DEFINED
typedef __typeof__(sizeof(0)) size_t;
#endif

#ifndef MSL_PTRDIFF_T_DEFINED
#define MSL_PTRDIFF_T_DEFINED
typedef long ptrdiff_t;
#endif

#ifndef MSL_WCHAR_T_DEFINED
#define MSL_WCHAR_T_DEFINED
#ifndef __cplusplus
typedef unsigned short wchar_t;
#endif
#endif

#ifndef NULL
#define NULL ((void *)0)
#endif

#ifndef offsetof
#define offsetof(type, member) ((size_t) & (((type *)0)->member))
#endif

#endif // MSL_STDDEF_H
