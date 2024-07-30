#include <stdio.h>

int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x >>= 1)
    {
        if (x & 01)
        {
            b++;
        }
    }
    return b;
}

int bitcount_new(unsigned x)
{
    int b;
    while (x != 0)
    {
        x &= (x - 1);
        b++;
    }
    return b;
}
int main()
{

    printf("bitcount(0b11111):%d\n", bitcount(0b11111));
    printf("bitcount_new(0b111):%d\n", bitcount_new(0b111));
}