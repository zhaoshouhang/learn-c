#include <stdio.h>

void lower(char s[])
{
    for (int i = 0; s[i] != '\0'; i++)
    {
        s[i] = (s[i] >= 65 && s[i] <= 97) ? (s[i] + 32) : s[i];
    }
}
int main()
{
    char s[] = "ABC";
    lower(s);
    printf("%s\n", s);
}