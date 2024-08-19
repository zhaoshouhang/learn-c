#include <stdio.h>

int main()
{

    int a = 1;
    {
        int a = 2;
        printf("inner a:%d\n", a); // 2
        a = 3;
    }
    printf("outer a:%d\n", a); // 1
}