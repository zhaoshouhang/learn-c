/* 每行一个单词打印其输入 */
#include <stdio.h>

#define IN 0
#define OUT 1

int main()
{
    int c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\n' || c == '\t')
        {
            printf("\n");
        }
        else
        {
            printf("%c", c);
        }
    }
}