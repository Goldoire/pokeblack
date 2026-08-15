#ifndef MSL_STDLIB_H
#define MSL_STDLIB_H

/*
 * Minimal <stdlib.h> for the MWCC build. The real Metrowerks MSL is not in
 * the tree; the TwlSystem (NNS) library sources include <stdlib.h> for size_t
 * and NULL only. Declaring the allocation functions here would be wrong -- the
 * game never links MSL malloc -- so they are deliberately absent.
 */

#include <stddef.h>

#endif // MSL_STDLIB_H
