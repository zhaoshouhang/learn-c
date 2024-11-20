// 打印16进制内容
#include <stdio.h>
#include <string.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, size_t len)
{
    size_t i;
    for (i = 0; i < len; i++)
    {
        printf(" %.2x", start[i]);
    }
    printf("\n");
}

void show_int(int x)
{
    show_bytes((byte_pointer)&x, sizeof(int));
}
void show_float(float x)
{
    show_bytes((byte_pointer)&x, sizeof(float));
}
void show_pointer(void *x)
{
    show_bytes((byte_pointer)&x, sizeof(void *));
}

int func1(unsigned word)
{
    return (int)((word << 24) >> 24);
}
int func2(unsigned word)
{
    return ((int)word << 24) >> 24;
}
int main()
{
    int val = 0x87654321;
    byte_pointer valp = (byte_pointer)&val;
    // show_bytes(valp, 1);
    // show_bytes(valp, 2);
    // show_bytes(valp, 3);
    char *str = "12345";
    show_bytes((byte_pointer)str, 6);
    const char *s = "abcdef";
    show_bytes((byte_pointer)s, strlen(s));

    unsigned int a = -1;

    printf("%u\n", a);
    show_bytes((byte_pointer)(&a), sizeof(int));
    printf("=========位移运算======\n");
    printf("0x00000076:func1:%x\n", func1(0x00000076));
    printf("0x00000076:func2:%x\n", func2(0x00000076));
    printf("0x87654321:func1:%x\n", func1(0x87654321));
    printf("0x87654321:func2:%x\n", func2(0x87654321));
    printf("0x000000C9:func1:%x\n", func1(0x000000C9));
    printf("0x000000C9:func2:%x\n", func2(0x000000C9));
    printf("0xEDCBA987:func1:%x\n", func1(0xEDCBA987));
    printf("0xEDCBA987:func2:%x\n", func2(0xEDCBA987));
}
