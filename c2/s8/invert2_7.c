#include <stdio.h>
// 编写一个函数 invert(x,p,n)，
// 该函数返回对 x 执行下列操作后的结果值:
// 将 x 中从第 p 位开始的 n 个(二进制)位求反(即，1 变成 0，0 变成 1)，
// x 的其余各位保持不变
unsigned invert(unsigned x, int p, int n)
{
    unsigned p1 = x & ~(~0 << (p - n));
    unsigned p3 = x & (~0 << p);

    unsigned p2 = ((~(x >> (p - n))) & ~(~0 << n)) << (p - n);
    return p1 | p2 | p3;
}
int main()
{
    unsigned int a = 0b110011;
    printf("invert(a,4,2):%d\n", invert(a, 4, 2)); // 0b111111 -> 63
}