#include <stdio.h>

int main()
{
    printf("2 > 1 || 1 < 2 && 1 > 2\n");
    if (2 > 1 || 1 < 2 && 1 > 2) // true
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    printf("(2 > 1 || 1 < 2) && 1 > 2\n");
    if ((2 > 1 || 1 < 2) && 1 > 2) // false
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }
    //
    if (!2)
    {
        printf("!2:true\n");
    }
    else
    {
        printf("!2:false\n");
    }

    if (!0)
    {
        printf("!0:true\n");
    }
    else
    {
        printf("!0:false\n");
    }

    printf("1 > '0':%d\n", 1 > '0');
    printf("'1' > '0':%d\n", '1' > '0');
    printf("0 > '0':%d\n", 0 > '0');
    printf("'0' > '0':%d\n", '0' > '0');
}