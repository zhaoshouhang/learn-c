
#include <stdio.h>

#define MAXLINE 1000 /* 输入行的最大长度 */

int getline(char line[], int maxline);

// 删除每个输入行末尾的空格及制表符,并删除完全是空格的行

int main()
{

    int len;            // 当前行长度
    char line[MAXLINE]; // 当前输入行

    while ((len = getline(line, MAXLINE)) - 1 > 0)
    {
        // 去掉\0 打印长度,和内容
        printf("str length:%d,str: %s\n", len - 1, line);
    }
}

int getline(char s[], int lim)
{

    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    i--;
    for (; i > 0; --i)
    {
        if (s[i] != ' ' && s[i] != '\t')
        {
            break;
        }
    }
    i++;
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
