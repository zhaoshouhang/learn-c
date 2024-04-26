#include <stdio.h>

/* 打印华氏温度与摄氏温度对照 */
// 函数版本

float transform(float fahr);

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    while (fahr <= upper)
    {
        celsius = transform(fahr);
        printf("%3.0f %6.1f\n", fahr, celsius);
        fahr = fahr + step;
    }
}

float transform(float fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}