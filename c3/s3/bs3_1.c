
#include <stdio.h>
int binsearch(int x, int v[], int n)
{
    int low, high, mid;
    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (x < v[mid])
            high = mid - 1;
        else if (x > v[mid])
            low = mid + 1;
        else /*找到了匹配的值 */
            return mid;
    }
    return -1; /*没有匹配的值*/
}

int binsearch_new(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while ((low <= high) && (v[(mid = (low + high) / 2)] != x))
    {
        if (x < v[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    if (v[mid] == x)
    {
        return mid;
    }
    return -1; /*没有匹配的值*/
}

int main()
{
    int arr[] = {9, 10, 23, 25, 53, 66};
    printf("bs1:%d", binsearch_new(10, arr, 6));
}
