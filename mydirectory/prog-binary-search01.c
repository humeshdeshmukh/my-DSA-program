/*write a c program to implement binary search algorithm*/
#include <stdio.h>
#define MAX 10

void binary_search(int *a, int size);

int main()
{
    int a[MAX];
    int i;

    printf("\n HUMESH DESHMUKH\n ROLL NO.34");
    printf("\nEnter %d elements in sorted order: ", MAX);
    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &a[i]);
    }

    binary_search(a, MAX);

    return 0;
}

void binary_search(int *a, int size)
{
    int data, low, high, mid;

    printf("\nEnter the element to be searched: ");
    scanf("%d", &data);

    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (a[mid] == data)
        {
            printf("\nSearch is successful!");
            printf("\nElement is present at position %d.\n", mid + 1);
            return;
        }
        else if (a[mid] < data)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    printf("\nElement not found.\n");
}
