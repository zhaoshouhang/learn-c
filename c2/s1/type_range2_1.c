#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{

    printf("signed char range: %d~%d\n", SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char range: %u~%u\n", 0, UCHAR_MAX);

    printf("signed short int  range: %d~%d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short int range: %u~%u\n", 0, USHRT_MAX);

    printf("signed int range: %d~%d\n", INT_MIN, INT_MAX);
    printf("unsigned int range: %u~%u\n", 0, UINT_MAX);

    printf("signed long int range: %ld~%ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long int range: %lu~%lu\n", 0, ULONG_MAX);

    // 如何使用编程进行计算:

    signed char char_min = 1 << (sizeof(signed char) * 8 - 1);
    signed char char_max = ~char_min;

    unsigned char uchar_min = 0;
    unsigned char uchar_max = ~uchar_min;

    printf("signed char range: %d to %d\n", char_min, char_max);
    printf("unsigned char range: %u to %u\n", uchar_min, uchar_max);

    signed short short_min = 1 << (sizeof(signed short) * 8 - 1);
    signed short short_max = ~short_min;

    unsigned short ushort_min = 0;
    unsigned short ushort_max = ~ushort_min;

    printf("signed short range: %d to %d\n", short_min, short_max);
    printf("unsigned short range: %u to %u\n", ushort_min, ushort_max);
    // 其他的 类似 int 和 long 都是这么求值计算
    return 0;
}