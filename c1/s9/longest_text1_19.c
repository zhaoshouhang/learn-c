#include <stdio.h>

#define MAXLINE 1000 /* 输入行的最大长度 */

int getline(char line[], int maxline);

void reverse(char to[], char from[], int fromLength);

int main()
{

    int len;            // 当前行长度
    char line[MAXLINE]; // 当前输入行

    while ((len = getline(line, MAXLINE)) > 0)
    {
        char re[len];

        reverse(re, line, len);
        // 这里改成了所有的输入都打印
        //  去掉\0 打印长度,和内容
        printf("reverse str: %s\n", re);
    }
}

void reverse(char to[], char from[], int fromLength)
{
    int j = 0;
    for (int i = fromLength - 1; i >= 0; i--)
    {
        to[j++] = from[i];
    }
    to[j] = '\0';
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