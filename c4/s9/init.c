#include <stdio.h>

int main()
{
    extern int a;
    static int b;
    int c;
    int d[3];
    char e[] = "hello";
    char f[] = {'w', 'o', 'r', 'l', 'd', '\0'};
    // printf("a:%g\n", a);//报错
    printf("b:%g\n", b);
    printf("c:%g\n", c);
    printf("d:[ ");
    int length = sizeof(d) / sizeof(d[0]);
    for (int i = 0; i < length; i++)
    {
        printf("%d ", d[i]);
    }
    printf("]\n");

    printf("e:%s\n", e);

    printf("f:%s\n", f);
}