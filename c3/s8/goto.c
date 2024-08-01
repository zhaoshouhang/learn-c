#include <stdio.h>

void find(char s1[], char s2[])
{
    int i;
    for (i = 0; s1[i] != '\0'; i++)
    {
        for (int j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                goto found;
            }
        }
    }
found:
{
    printf("echo:");
    printf("first same char:%c\n", s1[i]);
}
}

int main()
{
    find("abcdef", "ttttgtkiojga");
}