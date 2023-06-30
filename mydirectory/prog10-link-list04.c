/*write stack program using link list*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* top;

void push();
void pop();
void display();

int main()
{
    int ch;
    top = NULL;

    while (1)
    {
        printf("\n1. Push element");
        printf("\n2. Pop the element");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                push();
                break;
            case 2:
                pop();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice");
        }
    }
}

void push()
{
    int data;
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    if (newNode == NULL)
    {
        printf("\nMemory allocation failed");
        return;
    }

    printf("\nEnter the value to be pushed into the stack: ");
    scanf("%d", &data);

    newNode->data = data;
    newNode->next = top;
    top = newNode;

    printf("\nElement pushed successfully");
}

void pop()
{
    if (top == NULL)
    {
        printf("\nStack is empty");
        return;
    }

    struct Node* temp = top;
    int data = temp->data;
    top = top->next;

    free(temp);

    printf("\nData popped from stack: %d", data);
}

void display()
{
    if (top == NULL)
    {
        printf("\nStack is empty");
        return;
    }

    struct Node* temp = top;

    printf("\nStack elements:");

    while (temp != NULL)
    {
        printf("\n%d", temp->data);
        temp = temp->next;
    }
}
