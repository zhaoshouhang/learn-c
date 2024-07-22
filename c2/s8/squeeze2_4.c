#include <stdio.h>

// 从字符串s 中删除字符c
void squeeze(char s[], int c)
{
    int i, j;
    for (i = j = 0; s[i] != '\0'; i++)
    {
        if (s[i] != c)
        {
            s[j++] = s[i];
        }
    }
    s[j] = '\0';
}
// 从s1中去掉任何与s2匹配的字符
void squeeze1(char s1[], char s2[])
{
    int i, j;
    for (i = j = 0; s1[i] != '\0'; i++)
    {
        j = i;
        int x;
        int match = 1;

        for (x = 0; s2[x] != '\0'; x++)
        {
            // 原先字符串到结尾,或者是匹配过程中不相同
            if (s1[j] == '\0' || s1[j] != s2[x])
            {
                match = 0;
                break;
            }
            j++;
        }
        // 把字符后面的给挪到前面
        if (match)
        {
            int m = i;
            int n = j;
            while (s1[m] != '\0')
            {
                s1[m++] = s1[n++];
            }
        }
    }
}

int main()
{
    char s[] = "hello";
    squeeze(s, 'h');
    printf("after squeeze:%s\n", s);
    char s1[] = "beiqilangu tmd zhenlan";
    squeeze1(s1, "an");
    printf("after squeeze1:%s\n", s1);
}