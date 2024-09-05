#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int);
/* 把输入中的下一个整型数据赋值给*pn */
int getint(int *pn)
{
    int c, sign;

    while (isspace(c = getch()))
    {
    }
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c); // 输入的不是一个数字
        return 0;
    }
    sign = (c == '-') ? -1 : 1;

    if (c == '+' || c == '-')
    {
        int nextc = getch();
        if (isdigit(nextc))
        {
            c = nextc;
        }
        else
        {
            ungetch(nextc);
            ungetch(c);
            return 0;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF)
    {
        ungetch(c);
    }
    return c;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch:  too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

int main()
{
    int a;
    int b = getint(&a);

    printf("a = %d,b = %d\n", a, b);
}