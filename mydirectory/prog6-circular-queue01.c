/*write a program of circular queue*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int a[MAX];
int front = -1;
int rear = -1;

void insertcq();
void deletecq();
void displaycq();

int main()
{
    int ch;
    while (1)
    {
        printf("\nCircular Queue Menu");
        printf("\n1. Insert element in queue");
        printf("\n2. Delete element in queue");
        printf("\n3. Display queue");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insertcq();
            break;
        case 2:
            deletecq();
            break;
        case 3:
            displaycq();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice\n");
        }
    }
    return 0;
}

void insertcq()
{
    int data, temp;
    temp = (rear + 1) % MAX;
    if (temp == front)
    {
        printf("\nQueue is full\n");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        rear = temp;
        printf("\nEnter the element for insertion in queue: ");
        scanf("%d", &data);
        a[rear] = data;
        printf("\nElement %d is inserted in the queue\n", data);
    }
}

void deletecq()
{
    int data;
    if (front == -1)
    {
        printf("\nQueue is underflow\n");
    }
    else
    {
        data = a[front];
        a[front] = -1;
        printf("\nElement deleted from queue is %d\n", data);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }
}

void displaycq()
{
    int i;
    if (front == -1)
    {
        printf("\nQueue is empty\n");
    }
    else
    {
        printf("\nCircular Queue elements are:\n");
        if (rear >= front)
        {
            for (i = front; i <= rear; i++)
            {
                printf("%d ", a[i]);
            }
        }
        else
        {
            for (i = front; i < MAX; i++)
            {
                printf("%d ", a[i]);
            }
            for (i = 0; i <= rear; i++)
            {
                printf("%d ", a[i]);
            }
        }
        printf("\n");
    }
}
