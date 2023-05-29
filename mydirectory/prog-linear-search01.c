/*write a c program to implement the linear search*/
#include <stdio.h>
#define MAX 10

void linear_search(int *a, int size);

int main()
{
    int a[MAX];
    int i;

    printf("\nEnter %d elements: ", MAX);
    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &a[i]);
    }

    linear_search(a, MAX);

    return 0;
}

void linear_search(int *a, int size)
{
    int item, i, flag = 0;

    printf("\nEnter the element to be searched: ");
    scanf("%d", &item);

    for (i = 0; i < size; i++)
    {
        if (a[i] == item)
        {
            printf("\nSEARCH IS SUCCESSFUL");
            printf("\nElement is present at position %d\n", i + 1);
            flag = 1;
            break;
        }
    }

    if (flag == 0)
    {
        printf("\nElement not found\n");
    }
}
