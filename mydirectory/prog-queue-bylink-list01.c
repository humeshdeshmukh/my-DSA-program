/*write a menue driven program of queue by link list by c*/
#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 3

struct node
{
    int data;
    struct node *link;
};

struct node *start = NULL;
struct node *front = NULL;
struct node *rear = NULL;

void insertion();
void deletion();
void display();
int nodecount(struct node *s);

int main()
{
    int ch;
    printf("\n HUMESH DESHMUKH\n ROLL NO. 34");
    while (1)
    { 
        printf("\n MENUE OF LINKED QUEUE");
        printf("\n1. Insertion");
        printf("\n2. Deletion");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                insertion();
                break;
            case 2:
                deletion();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid Choice");
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
    return count;
}

void insertion()
{
    if (nodecount(start) == MAXSIZE)
    {
        printf("\nQueue is FULL");
    }
    else
    {
        struct node *p = (struct node*)malloc(sizeof(struct node));
        printf("\nEnter the item: ");
        scanf("%d", &p->data);
        p->link = NULL;

        if (start == NULL)
        {
            start = p;
            front = rear = start;
        }
        else
        {
            rear->link = p;
            rear = p;
        }
        printf("\nItem inserted successfully.");
    }
}

void deletion()
{
    if (start == NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        struct node *p = start;
        printf("\nDeleted element is: %d", p->data);
        start = p->link;
        free(p);

        if (start == NULL)
        {
            front = NULL;
            rear = NULL;
        }
    }
}

void display()
{
    if (start == NULL)
    {
        printf("\nQueue is empty");
    }
    else
    {
        printf("\nThe elements are: ");
        struct node *temp = start;
        while (temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->link;
        }
    }
}
