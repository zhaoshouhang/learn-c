#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'

// 4-5 define
#define SIN '1'
#define EXP '2'
#define POW '3'

int getop(char[]);
void push(double);
double pop(void);

double it;

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;

        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("error zero divisor\n");
            }
            break;
        // 习题4-3 支持取模
        case '%':
            op2 = pop();
            if (op2 != 0.0)
            {
                push((int)pop() % (int)op2);
            }
            else
            {
                printf("error zero divisor\n");
            }
            break;
        // 习题4-5 支持math中的部分函数
        case SIN:
            push(sin(pop()));
            break;
        case EXP:
            push(exp(pop()));
            break;
        case POW:
            op2 = pop();
            push(pow(pop(), op2));
            break;

        case '\n':
            // 习题4-6 存放最近打印的值 增加处理变量的命令 这个没理解
            it = pop();
            printf("\t%.8g\n", it);
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
}

int sp = 0;
double val[MAXOP];

void push(double f)
{
    if (sp < MAXOP)
    {
        val[sp++] = f;
    }
    else
    {
        printf("error : stack full , can't push %g \n", f);
    }
}
double pop(void)
{
    if (sp > 0)
    {
        return val[--sp];
    }
    else
    {
        printf("error: stack empty\n");
    }
}
// 习题4-4
/*
    打印栈顶元素
*/
void print_stack_top()
{
    if (sp > 0)
    {
        printf("top:%g\n", val[sp - 1]);
    }
    else
    {
        printf("error: stack empty\n");
    }
}

double cur_stack_top;
void copy_stack_top()
{
    if (sp > 0)
    {
        cur_stack_top = val[sp - 1];
    }
    else
    {
        printf("error: stack empty\n");
    }
}
void exchange_stack_element()
{
    if (sp <= 1)
    {
        printf("not enough elements\n");
    }
    else
    {
        double t = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = t;
    }
}
void clear_stack()
{
    for (int i = 0; i < sp; i++)
    {
        val[i] = 0.0;
    }
    sp = 0;
}
//----------------
int getch(void);
void ungetch(int);

int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
        ;
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
    {
        // 4-5 增加特殊函数sin exp pow
        if (isalpha(c))
        {
            s[0] = tolower(s[0]);
            int i = 0;
            while (isalpha(s[++i] = getch()))
            {
                s[i] = tolower(s[i]);

                s[i + 1] = '\0';
                if (strcmp(s, "sin") == 0)
                {
                    return SIN;
                }
                else if (strcmp(s, "exp") == 0)
                {
                    return EXP;
                }
                else if (strcmp(s, "pow") == 0)
                {
                    return POW;
                }
            }
        }
        return c;
    }
    i = 0;
    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }
    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
        {
            ;
        }
    }
    s[i] = '\0';
    if (c != EOF)
    {
        ungetch(c);
    }
    return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

// 4-8 只能压回一个字符,修改getch 和ungetch ,只要把缓冲区大小改成1 不就只能压回一个字符?

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
// 4-7 编写一个函数ungets(s) 将s 压回到输入中.ungets 函数需要使用bug和bufp吗,能否仅使用ungetch?

void ungets(char s[])
{
    int len = strlen(s);
    if (len > BUFSIZE - bufp)
    {
        printf("ungets: too many characters\n");
    }
    else
    {
        for (; len > 0; len--)
        {
            ungetch(s[len - 1]);
        }
    }
}

// 4-9 这俩函数 处理EOF的时候会被认为成数字 -1 ,如果读取到这个 EOF时可以在压到缓冲区时,替换为别的字符来代替

// 4-10 读取整行之后可以直接遍历这个字符串进行处理
int getline(char s[])
{
    int max_size = BUFSIZE;
    if (s == NULL || max_size == 0)
    {
        return -1; // Invalid argument
    }

    size_t pos = 0;
    int c;

    while ((c = getchar()) != EOF && c != '\n')
    {
        if (pos + 1 < max_size)
        {
            s[pos++] = (char)c;
        }
        else
        {
            // Buffer overflow condition
            s[pos] = '\0'; // Null-terminate the string
            return -1;     // Indicate buffer overflow
        }
    }

    if (c == EOF && pos == 0)
    {
        return -1; // No input read
    }

    s[pos] = '\0'; // Null-terminate the string
    return pos;    // Return the number of characters read
}