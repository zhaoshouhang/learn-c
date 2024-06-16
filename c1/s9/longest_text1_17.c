
#include <stdio.h>

#define MAXLINE 1000 /* 输入行的最大长度 */

int getline(char line[], int maxline);

int main()
{

    int len;            // 当前行长度
    int max;            // 目前最长行的长度
    char line[MAXLINE]; // 当前输入行

    char longest[MAXLINE]; // 保存最长行

    max = 0;
    while ((len = getline(line, MAXLINE)) - 1 > 80)
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

    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
