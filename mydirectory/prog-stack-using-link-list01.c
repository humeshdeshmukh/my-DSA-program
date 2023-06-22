/*write a  menue driven program of stack program using link list by c*/
#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

struct node
{
    int data;
    struct node *link;
};

struct node *top = NULL;

void push();
void pop();
void display();
int nodecount(struct node *s);

int main()
{
    int ch;
    printf("\n HUMESH DESHMUKH\n ROLL NO. 34");
    while (1)
    {
        printf("\n  Linked stack");
        printf("\n1. Push");
        printf("\n2. Pop");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\n\nEnter your choice: ");
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
            break;
        }
    }
    return 0;
}

int nodecount(struct node *s)
{
    int count = 0;
    struct node *q = s;
    while (q != NULL)
    {
        count++;
        q = q->link;
    }
    return (count);
}

void push()
{
    if (nodecount(top) == MAX_SIZE)
    {
        printf("\nStack is Full");
    }
    else
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        printf("\nEnter the item: ");
        scanf("%d", &(p->data));
        if (top == NULL)
        {
            p->link = NULL;
            top = p;
        }
        else
        {
            p->link = top;
            top = p;
        }
    }
}

void pop()
{
    if (top == NULL)
    {
        printf("\nStack is empty");
    }
    else
    {
        struct node *p = top;
        top = p->link;
        p->link = NULL;
        printf("\nThe deleted element is: %d", p->data);
        free(p);
    }
}

void display()
{
    if (top == NULL)
    {
        printf("\nStack is empty");
    }
    else
    {
        printf("\nThe elements are: ");
        struct node *p = top;
        while (p != NULL)
        {
            printf("\n %d", p->data);
            p = p->link;
        }
        printf("\n");
    }
}
