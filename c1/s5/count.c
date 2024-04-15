// 统计计数
#include <stdio.h>

int main()
{
    // version 1
    //  long nc;
    //  nc = 0;
    //  while (getchar() != EOF)
    //      ++nc;
    //  printf("count:%ld\n", nc);

    // version 2
    double nc;
    for (nc = 0; getchar() != EOF; ++nc)
        ;
    printf("count:%.0f\n", nc);
}
