// 统计空格,换行和制表符
#include <stdio.h>

int main()
{
    int c, nl, ns, nt;
    nl = 0;
    ns = 0;
    nt = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\n')
            ++nl;
        if (c == '\t')
            ++nt;
        if (c == ' ')
            ++ns;
    }

    printf("count_line('\\n'):%d\n", nl);
    printf("count_t('\\t'):%d\n", nt);
    printf("count_s(' '):%d\n", ns);
}
