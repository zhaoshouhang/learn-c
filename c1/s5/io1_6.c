// 验证getchar()!=EOF 的值是0还是1

#include <stdio.h>

int main()
{
    int c = getchar();
    printf("getchar():%d,getchar()!=EOF:%d", c, c != EOF);
}