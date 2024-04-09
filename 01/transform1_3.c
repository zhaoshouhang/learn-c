#include <stdio.h>

/* 打印华氏温度与摄氏温度对照 */

int main()
{
    float fahr, celsius;
    int lower, upper, step;

    lower = -20;
    upper = 150;
    step = 20;

    celsius = lower;

    printf("%3s  %6s\n", "摄氏", "华氏");

    while (celsius <= upper)
    {
        fahr = celsius / 5.0 * 9.0 + 32.0;
        printf("%3.0f %6.1f\n", celsius, fahr);
        celsius = celsius + step;
    }
}