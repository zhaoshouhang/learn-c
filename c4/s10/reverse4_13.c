#include <stdio.h>

void reverse(char to[], char from[], int fromLength)
{
    // 边界情况
    if (fromLength == 0)
    {
        to = "";
        return;
    }

    if (fromLength > 1)
    {
        reverse(to, from, fromLength - 1);
    }
    int i;
    for (i = 0; from[i] != '\0'; i++)
    {
        ;
    }
    to[fromLength - 1] = from[i - fromLength];
    to[fromLength] = '\0';
}
int main()
{
    char to[3] = {0};
    char from[] = "abc";
    reverse(to, from, 3);
    printf("to:%s\n", to);
}