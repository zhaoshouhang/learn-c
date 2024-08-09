#include <stdio.h>

int main()
{
    extern int var; // 声明外部变量

    printf("var:%d\n", var);
}