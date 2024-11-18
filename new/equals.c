// 使用逻辑和位运算 模拟"==" 的操作
#include <stdio.h>
int equals(int x, int y)
{
    return !(x ^ y);
}

int main()
{
    printf("val:%d\n", equals(0, 0));
}