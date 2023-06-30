/*write menu driven program of find max find sum insert display */
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} *p, *start;

void insert();
void display();
int findmax(struct node *);
int findsum(struct node *);

int main()
{
    int choice;
    start = NULL;

    while (1)
    {
        printf("\n 1. Insert in LL");
        printf("\n 2. Display LL");
        printf("\n 3. Largest element");
        printf("\n 4. Find sum");
        printf("\n 5. Exit");
        printf("\n Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert();
            break;
        case 2:
            display();
            break;
        case 3:
            printf("\n\n The largest element is %d", findmax(start));
            break;
        case 4:
            printf("\n\n The sum of elements is %d", findsum(start));
            break;
        case 5:
            exit(0);
        default:
            printf("\n Invalid choice");
        }
    }
}

void insert()
{
    p = (struct node *)malloc(sizeof(struct node));
    printf("\n Enter Data:");
    scanf("%d", &(p->data));

    if (start == NULL)
    {
        p->link = NULL;
        start = p;
    }
    else
    {
        p->link = start;
        start = p;
    }
}

void display()
{
    if (start == NULL)
    {
        printf("\n Empty LL");
    }
    else
    {
        p = start;
        while (p != NULL)
        {
            printf("\t %d", p->data);
            p = p->link;
        }
    }
}

int findmax(struct node *s)
{
    int max;

    if (s == NULL)
    {
        printf("\n\n\n Empty LL ");
        return (-1);
    }
    else
    {
        p = s;
        max = p->data;

        while (p != NULL)
        {
            if (p->data > max)
            {
                max = p->data;
            }
            p = p->link;
        }

        return max;
    }
}

int findsum(struct node *s)
{
    int sum;

    if (s == NULL)
    {
        printf("\n\n\n Empty LL");
        return (-1);
    }
    else
    {
        p = s;
        sum = 0;

        while (p != NULL)
        {
            sum = sum + p->data;
            p = p->link;
        }

        return sum;
    }
}
