/* write menu driven program of insert delate and display in circular link list*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

struct node *start = NULL;

void insert_cll();
void delete_cll();
void display_cll();

int main()
{
    int ch;
    printf("\n HUMESH DESHMUKH\n ROLL NO.34");

    while (1)
    {
        printf("\nMenu of Circular Linked List");
        printf("\n1. Insert in Circular Linked List");
        printf("\n2. Delete from Circular Linked List");
        printf("\n3. Display Circular Linked List");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_cll();
            break;
        case 2:
            delete_cll();
            break;
        case 3:
            display_cll();
            break;
        case 4:
            exit(0);
        default:
            printf("\nInvalid choice");
        }
    }
}

void insert_cll()
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &p->data);

    if (start == NULL)
    {
        start = p;
        p->link = start;
    }
    else
    {
        p->link = start->link;
        start->link = p;
        start = p;
    }

    printf("Data inserted successfully!");
}

void delete_cll()
{
    struct node *p;

    if (start == NULL)
    {
        printf("\nEmpty circular linked list");
        return;
    }

    if (start == start->link)
    {
        p = start;
        start = NULL;
    }
    else
    {
        p = start->link;
        start->link = p->link;
    }

    p->link = NULL;
    printf("\nDeleted data: %d", p->data);
    free(p);
}

void display_cll()
{
    struct node *p;

    if (start == NULL)
    {
        printf("\nEmpty circular linked list");
        return;
    }

    p = start;
    printf("\nCircular Linked List: ");

    do
    {
        printf("%d ", p->data);
        p = p->link;
    } while (p != start);

    printf("\n");
}
