#include <stdio.h>
// 打印输入中单词长度直方图
// length:count
// 1: 10
// 2: 12
// 3: 30
// ...:...
int main()
{
    int c;
    int nword[100];

    for (int i = 0; i < 100; i++)
    {
        nword[i] = 0;
    }
    int cur_word_length = 0;

    while ((c = getchar()) != EOF)
    {

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        {
            ++cur_word_length;
        }
        else
        {
            if (cur_word_length > 0)
                ++nword[cur_word_length];
            cur_word_length = 0;
        }
    }
    printf("length:count\n");
    for (int i = 0; i < 100; i++)
    {
        if (nword[i] != 0)
        {
            printf(" %5d:%d\n", i, nword[i]);
        }
    }
}