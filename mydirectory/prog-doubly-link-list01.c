/* write a menu driven program to insert delete display the doubly link list*/
#include <stdio.h>
#include <stdlib.h>

struct dnode
{
    struct dnode *llink;
    int data;
    struct dnode *rlink;
};

struct dnode *start, *p, *q;

void insert_dll();
void delete_dll();
void display_dll();

int main()
{
    int ch;
    start = NULL;
    printf("\n HUMESH DESHMUKH\n ROLL NO.34");

    while (1)
    {
        printf("\n1. Insert in dll");
        printf("\n2. Delete in dll ");
        printf("\n3. Display dll");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            insert_dll();
            break;
        case 2:
            delete_dll();
            break;
        case 3:
            display_dll();
            break;
        case 4:
            exit(0);
            break;
        default:
            printf("\nInvalid choice");
        }
    }
}

void insert_dll()
{
    p = (struct dnode *)malloc(sizeof(struct dnode));
    printf("\nEnter data: ");
    scanf("%d", &p->data);
    p->llink = NULL;
    p->rlink = NULL;

    if (start == NULL)
    {
        start = p;
    }
    else
    {
        p->rlink = start;
        start->llink = p;
        start = p;
    }

    printf("Data inserted successfully!\n");
}

void delete_dll()
{
    if (start == NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
        p = start;
        start = start->rlink;

        if (start != NULL)
        {
            start->llink = NULL;
        }

        free(p);
        printf("\nNode deleted successfully!");
    }
}

void display_dll()
{
    int choice;

    printf("\nTraversal path");
    printf("\n1. Forward direction");
    printf("\n2. Backward direction");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        p = start;
        printf("\nForward direction: ");
        while (p != NULL)
        {
            printf("\t%d", p->data);
            p = p->rlink;
        }
        break;

    case 2:
        p = start;
        if (p == NULL)
        {
            printf("\nEmpty list");
            break;
        }
        while (p->rlink != NULL)
        {
            p = p->rlink;
        }
        printf("\nBackward direction: ");
        while (p != NULL)
        {
            printf("\t%d", p->data);
            p = p->llink;
        }
        break;

    default:
        printf("\nInvalid choice");
    }
}
