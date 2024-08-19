#include <stdio.h>
extern int b;
extern int a;

extern void printb();
extern void printa();
extern void test_print();
// 使用gcc main.c static.c 进行编译
int main()
{
    printa();
    printb();
    // 编译报错,static 变量不能被外部引用
    //  printf("%d\n", a); // undefined reference to `a'
    printf("%d\n", b);
    // 编译报错,static修饰的函数也不能被外部使用
    //  test_print();
}