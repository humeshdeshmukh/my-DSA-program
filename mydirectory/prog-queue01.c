#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int queue[MAX]; // Global variable
int front, rear;

void insertq();
void deleteq();
void displayq();

int main()
{
    int ch;
    front = rear = -1;

    while (1)
    {
        printf("\n1. Insert in queue");
        printf("\n2. Delete from queue");
        printf("\n3. Display queue");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                insertq();
                break;
            case 2:
                deleteq();
                break;
            case 3:
                displayq();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
}

void insertq()
{
    int data;

    if (rear == MAX - 1)
    {
        printf("\nQueue is full");
    }
    else
    {
        printf("\nEnter the value to be inserted: ");
        scanf("%d", &data);
        rear = rear + 1;
        queue[rear] = data;
    }
}

void deleteq()
{
    int data;

    if (front == rear)
    {
        printf("\nQueue is empty");
        front = rear = -1;
    }
    else
    {
        front = front + 1;
        data = queue[front];
        printf("\nDeleted data: %d", data);
    }
}

void displayq()
{
    int i;

    if (front == rear)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nQueue elements:");

        for (i = front + 1; i <= rear; i++)
        {
            printf("\t%d", queue[i]);
        }
    }
}
