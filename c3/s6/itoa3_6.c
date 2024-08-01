#include <stdio.h>
#include <string.h>
#include <limits.h>

void reverse(char *str)
{
    int length = strlen(str);
    int i, j;
    char temp;

    for (i = 0, j = length - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}
void itoa_new(int n, char s[], unsigned w)
{

    int i, sign;

    sign = n;
    // 有符号整数，负数的范围通常比正数多一个,所以传入负数后,再取反,直接就溢出了,还是负数
    // 需要额外处理负数
    if (n == INT_MIN)
    {
        n = INT_MAX;
    }
    else if (n < 0)
    {
        n = -n;
    }
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign == INT_MIN)
    {
        s[0]++;
    }
    if (sign < 0)
    {
        s[i++] = '-';
    }
    while (i < w)
    {
        s[i++] = ' ';
    }

    s[i] = '\0';
    reverse(s);
}
int main()
{
    char s[100];
    itoa_new(-1, s, 3);
    printf("itoa:%s\n", s);
}
