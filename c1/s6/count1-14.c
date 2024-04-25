#include <stdio.h>
// 练习 1-14 打印输入中各个字符出现频度的直方图
// a:1
// b:2
// A:3
// C:4
// ...:...
int main()
{
    int c;
    int nchar[127];

    for (int i = 0; i < 127; i++)
    {
        nchar[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            ++nchar[c];
        }
    }
    printf("char:count\n");
    for (int i = 0; i < 127; i++)
    {
        if (nchar[i] != 0)
        {
            printf(" %3c:%d\n", i, nchar[i]);
        }
    }
}