/*write a program of insertion short*/
#include <stdio.h>

void insertion(int *a, int n);

int main()
{
    int a[10];
    int i;
    printf("\n HUMESH DESHMUKH\n ROLL NO. 34\n");

    printf("\n Enter any 10 numbers");
    for (i = 0; i < 10; i++)
        scanf("%d", &a[i]);

    printf("\n Array before sorting\n");
    for (i = 0; i < 10; i++)
        printf(" %d", a[i]);

    insertion(a, 10);

    printf("\n Array after sorting\n");
    for (i = 0; i < 10; i++)
        printf("\t%d", a[i]);

    return 0;
}

void insertion(int *p, int n)
{
    int i, j, k, index, t;

    for (i = 1; i < n; i++)
    {
        index = p[i];
        j = i;

        while ((j > 0) && (p[j - 1] > index))
        {
            t = p[j];
            p[j] = p[j - 1];
            p[j - 1] = t;
            j--;
        }

        printf("\n");

        for (k = 0; k < n; k++)
            printf(" %d", p[k]);

        printf("\n");
    }
}
