#include <stdio.h>
#include <string.h>
#include <math.h>

// 把16进制数转换给整数值

int htoi(char s[])
{
    if (strlen(s) < 3)
    {
        printf("len < 3\n");
        return -1;
    }
    if (s[0] != '0' || (s[1] != 'X' && s[1] != 'x'))
    {
        printf("should start with 0x or 0X\n");
        return -1;
    }
    int it = 0;
    int sum = 0;
    for (int i = strlen(s); i > 2; i--)
    {
        char v = s[i - 1];
        if (!((v >= '0' && v <= '9') || (v >= 'a' || v <= 'f') || (v >= 'A' || v <= 'F')))
        {
            printf("should in 0-9 a-f A-F\n");
            return -1;
        }
        int val;
        if (v >= '0' && v <= '9')
        {
            val = v - 48;
        }
        if (v >= 'a' && v <= 'f')
        {
            val = v - 97 + 10;
        }

        if (v >= 'A' && v <= 'F')
        {
            val = v - 65 + 10;
        }
        sum += val * pow(16, it++);
    };
    return sum;
}

int main()
{
    printf("0x14->%d\n", htoi("0x14"));
    printf("0xf->%d\n", htoi("0xf"));
    printf("0x1f->%d", htoi("0x1f"));
}