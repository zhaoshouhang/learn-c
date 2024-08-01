#include <stdio.h>

int main()
{

    // 写个break语句
    int i = 0;
    while (i < 100)
    {
        if (i == 50)
        {
            printf("get 50\n");
            break;
        }
        if (i % 2 == 0)
        {
            printf("even :%d\n", i);
            i++;
            continue;
        }
        printf("odd :%d\n", i);
        i++;
    }
}