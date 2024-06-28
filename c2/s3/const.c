#include <stdio.h>

#define VAL1 123
#define VAL2 -123333333L
#define VAL3 222U
#define VAL4 1.23f
#define VAL5 '0'
#define VAL6 "0"

#define VAL7 '\65'  // 10进制
#define VAL8 '\x41' // 16进制
#define VAL9 '\101' // 8进制

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
    printf("VAL7:%c\n", VAL7); // windows下为什么显示5?
    printf("VAL8:%c\n", VAL8);
    printf("VAL9:%c\n", VAL9);

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