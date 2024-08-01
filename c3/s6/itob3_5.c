#include <stdio.h>
#include <limits.h>
#include <strings.h>
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
void itob(int n, char s[], unsigned b)
{

    int i, sign;

    sign = n;
    unsigned num;
    if (n == INT_MIN)
    {
        num = (unsigned)INT_MAX + 1;
    }
    else
    {
        num = n < 0 ? -n : n;
    }
    i = 0;
    do
    {
        int digit = num % b;
        s[i++] = digit < 10 ? (digit + '0') : (digit - 10 + 'A');
    } while ((num /= b) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[100];
    itob(INT_MIN, s, 10);
    printf("itob:%s\n", s);
}