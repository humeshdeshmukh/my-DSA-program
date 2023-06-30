/* write a c program to implement selection short*/
#include<stdio.h>
#define MAX 5

void selection_sort(int *a, int size);

int main()
{
    int arr[MAX];
    int i;
    printf("\n HUMESH DESHMUKH\n ROLL NO. 34\n");

    printf("Enter %d elements: ", MAX);
    for(i = 0; i < MAX; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nBefore sorting:\n");
    for(i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }

    selection_sort(arr, MAX);

    printf("\n\nAfter sorting:\n");
    for(i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}

void selection_sort(int *a, int size)
{
    int i, j, temp;

    for(i = 0; i < size - 1; i++)
    {
        for(j = i + 1; j < size; j++)
        {
            if(a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}
