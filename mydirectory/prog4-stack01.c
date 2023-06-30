/*write a menue driven program of  stack  by c*/
#include <stdio.h>
#include <stdlib.h> 
#define MAX 5

void push();
void pop();
void display();

int stack[MAX];
int top;

int main()
{
    int ch;
    top = -1;
    printf("\n HUMESH DESHMUKH\n ROLL NO. 34");

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

    if (top == MAX - 1) 
    {
        printf("\nStack is full");
    }
    else
    {
        printf("\nEnter the value to be pushed into the stack: ");
        scanf("%d", &data);
        top = top + 1;
        stack[top] = data;
    }
}

void pop()
{
    int data;

    if (top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        data = stack[top];
        top = top - 1;
        printf("\nData popped from stack: %d", data);
    }
}

void display()
{
    int i;

    if (top == -1)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nStack elements:");
        for (i = top; i >= 0; i--) 
        {
            printf("\n%d", stack[i]);
        }
    }
}
