#include <stdio.h>
//  编写一个函数 rightrot(x，n)，
// 该函数返回将 x 循环右移(即从最右端移出的位将从最左端移入)
// n(二进制)位后所得到的值。
unsigned rightrot(unsigned x, int n)
{
    unsigned b = sizeof(unsigned int) * 8;
    // 防止n大于x的位数
    n = n % b;
    unsigned p1 = (x & ~(~0 << n)) << (b - n);
    unsigned p2 = x >> n;
    return p1 | p2;
}
int main()
{
    unsigned a = 0b1;
    unsigned bit_len = sizeof(unsigned) * 8;
    printf("sizeof(unsigned) bit len:%d\n", bit_len);
    printf("func(a,1):%u\n", rightrot(a, 1));
    printf("func(a,bit_len):%u\n", rightrot(a, bit_len));
}