
#include <stdio.h>
// 这里的a 只能在static.c中使用,在其他文件中不能使用
static int a = 1;

int b = 2;

void printa(void);
void printb(void);

static void test_print()
{
    printa();
    printb();
}
void printa()
{
    printf("%d\n", a);
}

void printb()
{

    printf("%d\n", b);
}