#include "types.h"

// These return an enum, not a plain int: CodeWarrior rewrites
//   if (x) return FALSE; return TRUE;
// into the inverted `bne / TRUE / FALSE` shape for integer returns, but leaves
// the source order alone for enum-typed returns, which is what the ROM has.
typedef enum
{
    UnkEnum0215EB4C_0 = 0,
    UnkEnum0215EB4C_1 = 1
} UnkEnum0215EB4C;

int sub_0215F104(void *param0, int param1);

UnkEnum0215EB4C sub_0215EB4C(void *param0)
{
    if (sub_0215F104(param0, 2))
    {
        return UnkEnum0215EB4C_0;
    }

    return UnkEnum0215EB4C_1;
}

UnkEnum0215EB4C sub_0215EBBC(void *param0)
{
    if (sub_0215F104(param0, 3))
    {
        return UnkEnum0215EB4C_0;
    }

    return UnkEnum0215EB4C_1;
}

UnkEnum0215EB4C sub_0215EC2C(void *param0)
{
    if (sub_0215F104(param0, 8))
    {
        return UnkEnum0215EB4C_0;
    }

    return UnkEnum0215EB4C_1;
}

UnkEnum0215EB4C sub_0215EC6C(void *param0)
{
    if (sub_0215F104(param0, 4))
    {
        return UnkEnum0215EB4C_0;
    }

    return UnkEnum0215EB4C_1;
}

UnkEnum0215EB4C sub_0215EC80(void *param0)
{
    if (sub_0215F104(param0, 5))
    {
        return UnkEnum0215EB4C_0;
    }

    return UnkEnum0215EB4C_1;
}

UnkEnum0215EB4C sub_0215ED8C(void *param0)
{
    if (sub_0215F104(param0, 7))
    {
        return UnkEnum0215EB4C_0;
    }

    return UnkEnum0215EB4C_1;
}

UnkEnum0215EB4C sub_0215EE24(void *param0)
{
    if (sub_0215F104(param0, 6))
    {
        return UnkEnum0215EB4C_0;
    }

    return UnkEnum0215EB4C_1;
}

UnkEnum0215EB4C sub_0215EF2C(void *param0)
{
    if (sub_0215F104(param0, 9))
    {
        return UnkEnum0215EB4C_0;
    }

    return UnkEnum0215EB4C_1;
}
