#include <stdio.h>

int power(int, int);

int main()
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }
}
int power(int a, int b)
{
    int i, p;
    p = 1;
    for (i = 1; i <= b; i++)
    {
        p = p * a;
    }
    return p;
}
