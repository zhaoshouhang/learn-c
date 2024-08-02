#include <stdio.h>
#include <string.h>
int strrindex(char s[], char t[])
{
    for (int i = strlen(s) - strlen(t); i > 0; i--)
    {
        int flag = 1;
        int tmp_i = i;
        for (int j = 0; t[j] != '\0'; j++)
        {
            if (t[j] != s[tmp_i++])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            return i;
        }
    }

    return -1;
}
int main()
{
    printf("strrindex:%d\n", strrindex("abc", "bcda"));
}