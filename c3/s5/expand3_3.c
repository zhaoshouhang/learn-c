#include <stdio.h>

void expand(char s1[], char s2[])
{
    int i, j;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        if (s1[i] == '-' && i > 0 && s1[i + 1] != '\0')
        {
            int s = s1[i - 1];
            int e = s1[i + 1];
            for (int t = 0; t < e - s + 1; t++)
            {
                s2[j++] = (s + t);
            }
        }
        else
        //todo: not finish
        {
            s2[j++] = '-';
        }
    }
    s2[j++] = '\0';
}

int main()
{
    char s[100];
    expand("a-z", s);
    printf("a-z:%s\n", s);
}