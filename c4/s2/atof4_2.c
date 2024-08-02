#include <ctype.h>
#include <stdio.h>

double atof(char s[])
{
    double val, power;
    int i, sign;

    for (i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
    {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    // expend 支持科学计数版本
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
        int power_sign;
        power_sign = (s[i] == '-') ? -1 : 1;
        // 跳过+-
        if (!isdigit(s[i]))
        {
            i++;
        }
        int pow;
        double power_num = 1.0;
        for (pow = 0; isdigit(s[i]); i++)
        {
            pow = 10 * pow + (s[i] - '0');
        }
        for (int j = 0; j < pow; j++)
        {
            power_num *= 10.0;
        }
        power_num = (power_sign > 0) ? power_num : 1 / power_num;

        return sign * val / power * power_num;
    }
    return sign * val / power;
}

int main()
{
    printf("val:%g\n", atof("123.22231"));
    printf("val1:%g\n", atof("123.456e-3"));
}