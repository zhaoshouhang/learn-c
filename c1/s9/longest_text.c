
#include <stdio.h>

#define MAXLINE 1000 /* 输入行的最大长度 */

int getline(char line[], int maxline);

void copy(char to[], char from[]);

main()
{
    int len;                // 当前行长度
    int max;                // 目前最长行的长度
    char line[MAXLINE];     // 当前输入行
    char longtest[MAXLINE]; // 保存最长行

    max = 0;
    while ((len - getline(line, MAXLINE)) > 0)
    {
        if (len > max)
        {
            max = len;
            copy(longtest, line);
        }
    }
    if (max > 0)
    {
        printf("%s", longtest);
    }
}

int getline(char s[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
// 把 from 复制给to, 假设to 足够大
void copy(char to[], char from[])
{
    int i;

    i = 0;

    while ((to[i] = from[i]) != '\0')
    {
        ++i;
    }
}