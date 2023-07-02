/*write  queue program using link list*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front;
struct Node *rear;

void insertq();
void deleteq();
void displayq();

int main()
{
    int ch;
    front = rear = NULL;

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
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("\nMemory allocation failed");
        return;
    }

    printf("\nEnter the value to be inserted: ");
    scanf("%d", &data);

    newNode->data = data;
    newNode->next = NULL;

    if (rear == NULL) // Empty queue
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    printf("\nElement inserted successfully");
}

void deleteq()
{
    if (front == NULL)
    {
        printf("\nQueue is empty");
        return;
    }

    struct Node *temp = front;
    int data = temp->data;
    front = front->next;

    free(temp);

    if (front == NULL) // Last element deleted
    {
        rear = NULL;
    }

    printf("\nDeleted data: %d", data);
}

void displayq()
{
    if (front == NULL)
    {
        printf("\nQueue is empty");
        return;
    }

    struct Node *temp = front;

    printf("\nQueue elements:");

    while (temp != NULL)
    {
        printf("\t%d", temp->data);
        temp = temp->next;
    }
}
