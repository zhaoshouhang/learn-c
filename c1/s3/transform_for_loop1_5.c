#include <stdio.h>

/* 打印华氏温度与摄氏温度对照 */

int main()
{
    
    for (int fahr = 300; fahr >= 0; fahr=fahr-20)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
    
}