#include <stdio.h>

#define VAL1 123
#define VAL2 -123333333L
#define VAL3 222U
#define VAL4 1.23f
#define VAL5 '0'
#define VAL6 "0"

#define VAL7 65 // 直接表示10进制

// 没有十进制的表示方法
#define VAL8 '\x41' // 16进制
#define VAL9 '\101' // 8进制

#define VAL10 0x41      // 16 进制
#define VAL11 0101      // 8进制
#define VAL12 0b1000001 // 2进制

// 枚举类型,如果不设置 则从0开始,之后的递增+1
enum Boolean
{
    NO = 0,
    YES
};

enum Boolean bool;

const char c1 = '0';
void printConstC1()
{
    printf("func c1:%c", c1);
}

int main()
{
    printf("VAL1:%d\n", VAL1);
    printf("VAL2:%d\n", VAL2);
    printf("VAL3:%u\n", VAL3);
    printf("VAL4:%f\n", VAL4);
    printf("VAL5:%c\n", VAL5);
    printf("VAL6:%s\n", VAL6);
    printf("VAL7:%c\n", VAL7);
    printf("VAL8:%c\n", VAL8);
    printf("VAL9:%c\n", VAL9);
    printf("VAL10:%c\n", VAL10);
    printf("VAL11:%c\n", VAL11);
    printf("VAL12:%c\n", VAL12);

    bool = YES;

    if (bool == NO)
    {
        printf("no\n");
    }
    if (bool == YES)
    {
        printf("yes\n");
    }

    const char c1 = '\65';
    printf("c1:%c\n", c1);

    return 0;
}