#include <stdio.h>

void quicksort(int a[], int lower, int upper);
int split(int a[], int lower, int upper);

void quicksort(int a[], int lower, int upper)
{
    int i;
    if (upper > lower)
    {
        i = split(a, lower, upper);
        quicksort(a, lower, i - 1);
        quicksort(a, i + 1, upper);
    }
}

int split(int a[], int lower, int upper)
{
    int i, p, q, t;
    p = lower + 1;
    q = upper;
    i = a[lower];
    while (q >= p)
    {
        while (a[p] < i)
            p++;
        while (a[q] > i)
            q--;
        if (q > p)
        {
            t = a[p];
            a[p] = a[q];
            a[q] = t;
        }
    }
    t = a[lower];
    a[lower] = a[q];
    a[q] = t;
    return q;
}

int main()
{
    int n, i;

    printf("\n Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements of the array:\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("\nArray before sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    quicksort(a, 0, n - 1);

    printf("\nArray after sorting: ");
    for (i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
