#include <stdio.h>

#define LOWER 0   /* 下限 */
#define UPPER 300 /* 上限 */
#define STEP 20   /* 步长 */
/* 打印华氏温度与摄氏温度对照 */

int main()
{

    for (int fahr = LOWER; fahr <= UPPER; fahr = fahr + STEP)
    {
        printf("%3d %6.1f\n", fahr, (5.0 / 9.0) * (fahr - 32.0));
    }
}