#include <stdio.h>

#define swap(t, x, y) \
    {                 \
        t temp = x;   \
        x = y;        \
        y = temp;     \
    }

int main()
{
    int x = 1;
    int y = 2;

    swap(int, x, y);

    printf("swap x:%d,y:%d\n", x, y); // x:2 y:1
}