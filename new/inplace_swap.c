// 不适用额外的空间 交换ab的值
#include <stdio.h>

void inplace_swap(int *x, int *y)
{
    *y = *x ^ *y;
    *x = *x ^ *y;
    *y = *x ^ *y;

    /*************************
     *          *x        *y
     *           a         b
     * 1->       a        a^b
     * 2->      a^a^b=b   a^b
     * 3->       b        b^(a^b)=a
     *
     */
}

void reverse_array(int a[], int cnt)
{
    int first, last;

    for (first = 0, last = cnt - 1; first < last; first++, last--)
    {
        inplace_swap(&a[first], &a[last]);
    }
}
void printArray(int arr[], int size)
{
    printf("[");
    for (int i = 0; i < size; i++)
    {
        printf("%d", arr[i]);
        if (i < size - 1)
        {
            printf(", ");
        }
    }
    printf("]\n");
}
int main()
{
    int a[] = {1, 2, 3, 4, 5};
    reverse_array(a, 5);
    printArray(a, sizeof(a) / sizeof(a[0]));
}