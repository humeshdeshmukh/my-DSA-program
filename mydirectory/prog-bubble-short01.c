/*write a c program of bubble short*/
#include <stdio.h>
#define MAX 5

void bubbleSort(int *p, int size);

int main()
{
    int i;
    int arr[MAX];
    printf("\nEnter %d elements: ", MAX);
    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nArray before sorting: ");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }
    bubbleSort(arr, MAX);
    printf("\nArray after sorting: ");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void bubbleSort(int *p, int size)
{
    int i, j, temp;
    for (i = 0; i < size - 1; i++)
    {
        for (j = 0; j < size - i - 1; j++)
        {
            if (p[j] > p[j + 1])
            {
                temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
