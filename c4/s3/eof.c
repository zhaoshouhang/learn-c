#include <stdio.h>
// 必须在单独一行使用 c +z 回车才行
int main()
{
    int c;

    printf("Enter text (Ctrl + D to end on Unix/Linux/macOS, Ctrl + Z then Enter on Windows):\n");

    while ((c = getchar()) != EOF)
    {
        putchar(c);
    }

    printf("\nEOF detected.\n");
    return 0;
}
