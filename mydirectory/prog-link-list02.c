#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};
struct node *start, *p;
void insert_ll();
void display_ll();
int main()
{
    int ch;
    start = NULL;
    printf("\n HUMESH DESHMUKH\n ROLL NO.34");
    while (1)
    {
        printf("\nMenu of linked list");
        printf("\n1. Insert element in linked list");
        printf("\n2. Display the linked list");
        printf("\n3. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_ll();
            break;
        case 2:
            display_ll();
            break;
        case 3:
            exit(0);
        default:
            printf("\nInvalid choice\n");
        }
    }

    return 0;
}

void insert_ll()
{
    p = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter the data: ");
    scanf("%d", &p->data);
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

void display_ll()
{
    if (start == NULL)
    {
        printf("\nLinked list is empty\n");
    }
    else
    {
        p = start;
        printf("\nLinked list elements are: ");
        while (p != NULL)
        {
            printf("%d ", p->data);
            p = p->link;
        }
        printf("\n");
    }
}
