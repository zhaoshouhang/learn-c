#include <stdio.h>

// 编写一个函数 setbits(x,p,n,y)，
//  该函数返回对 x 执行下列操作后的结果值:
// 将 x 中从第 p 位开始的 n 个(二进制)位设置为 y 中最右边 n 位的值，
// x 的其余各位保持不变。
// x 是 0b110011 p=4 n=2 y = 0b11 => 0b111111 = 63
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    // 分三部分操作
    // 1.拿出x的最后的位数
    unsigned int p1 = x & ~(~0 << (p - n));

    // 2.拿出中间的位数
    //  先取出 y中的最右边的n位
    unsigned int t = y & ~(~0 << n);
    // 再往左位移 p - n 个位置
    unsigned int p2 = t << (p - n);

    // 3 拿出最左侧的位数
    unsigned p3 = x & (~0 << p);

    return p1 | p2 | p3;
}

int main()
{
    unsigned a = 0b110011;
    printf("setbits(a,4,2,3):%d\n", setbits(51, 4, 2, 3));
}