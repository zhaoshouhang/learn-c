#include <stdio.h>

void itoa(int n, char s[])
{

    if (n < 0)
    {
        n = -n;
        s[0] = '-';
    }

    if (n / 10)
    {
        itoa(n / 10, s);
    }
    int i;
    for (i = 0; s[i] != '\0'; i++)
    {
        ;
    }
    s[i] = n % 10 + '0';
    s[i + 1] = '\0';
}

int main()
{
    // 需要初始化一下,不然会打出未定义的数据
    char s[100] = {0};
    int a = -43672;
    printf("num:%d\n", a);
    itoa(a, s);
    printf("itoa:%s\n", s);
}
