#include <stdio.h>

int main()
{
    int a = 1 + 1;
    int b = 1 - 1;
    int c = 2 * 2;
    int d = 4 / 2;
    int e = 4 % 2;

    float var1 = 2.1f;
    double var2 = 2.2;
    // float f = var1 % var2; //% 不能用在float 或者是double类型上

    // 优先级: + - 比 * / % 低
    int v = 1 + 2 * 3 - 4 / 5 + 7 % 6; // 1 + 6 - 0 + 1= 8

    printf("v:%d", v); // 8
}