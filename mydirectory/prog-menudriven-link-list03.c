/*write menu driven program of link list which content insert fist, insert last ,insert any pos,
delate first,delate last,delate any pos, node count,display*/
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *start, *p, *q, *m, *n;
void insert_first();
void insert_last();
void insert_anypos();
void delete_first();
void delete_last();
void delete_anypos();
int node_count();
void display();
int main()
{
    int ch;
    start = NULL;
    printf("\n HUMESH DESHMUKH\n ROLL NO.34");
    while (1)
    {
        printf("\n link list menue");
        printf("\n 1. insert in first position");
        printf("\n 2. insert in last position");
        printf("\n 3. insert any position");
        printf("\n 4. delate first position");
        printf("\n 5. delate last position");
        printf("\n 6. delate any position ");
        printf("\n 7. node_cout of link list ");
        printf("\n 8. display lisk list ");
        printf("\n  enter your choice :  ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            insert_first();
            break;
        case 2:
            insert_last();
            break;
        case 3:
            insert_anypos();
            break;
        case 4:
            delete_first();
            break;
        case 5:
            delete_last();
            break;
        case 6:
            delete_anypos();
            break;
        case 7:
            printf("\n Node count: %d\n", node_count());
            break;
        case 8:
            display();
            break;
        case 9:
            exit(0);
        default:
            printf("\n invalid choice ");
        }
    }
    return 0;
}

void insert_first()
{
    p = (struct node *)malloc(sizeof(struct node));
    printf("\n enter data");
    scanf("%d", &(p->data));
    if (start == NULL)
    {
        start = p;
        p->link = NULL;
        q = p;
    }
    else
    {
        p->link = start;
        start = p;
    }
}
void insert_last()
{
    p = (struct node *)malloc(sizeof(struct node));
    printf("\nEnter data: ");
    scanf("%d", &(p->data));
    p->link = NULL;
    if (start == NULL)
    {
        start = p;
    }
    else
    {
        q = start;
        while (q->link != NULL)
        {
            q = q->link;
        }
        q->link = p;
    }
}
void insert_anypos()
{
    int pos, count, i;

    printf("\nEnter position: ");
    scanf("%d", &pos);

    count = node_count(start);

    if (pos < 1 || pos > count + 1)
    {
        printf("\nInvalid position\n");
    }
    else
    {
        i = 1;
        m = start;
        p = (struct node *)malloc(sizeof(struct node));

        printf("\nEnter data: ");
        scanf("%d", &p->data);

        if (pos == 1)
        {
            p->link = start;
            start = p;
        }
        else
        {
            while (i < pos - 1)
            {
                m = m->link;
                i++;
            }

            n = m->link;
            m->link = p;
            p->link = n;
        }

        printf("\nElement inserted at position %d\n", pos);
    }
}

void delete_first()
{
    if (start == NULL)
    {
        printf("\n Empty linked list");
    }
    else
    {
        struct node *p = start;
        start = p->link;
        p->link = NULL;
        printf("\nDeleted data: %d", p->data);
        free(p);
    }
}
void delete_last()
{
    if (start == NULL)
    {
        printf("\nEmpty list");
    }
    else
    {
        struct node *p = start;
        struct node *q = NULL;

        if (p->link == NULL)
        {
            printf("\nDeleted data: %d", p->data);
            free(p);
            start = NULL;
        }
        else
        {
            while (p->link != NULL)
            {
                q = p;
                p = p->link;
            }

            q->link = NULL;
            printf("\nDeleted data: %d", p->data);
            free(p);
        }
    }
}
void delete_anypos()
{
    int i, pos, count;
    printf("\nEnter position: ");
    scanf("%d", &pos);
    count = node_count(start);
    if (pos < 1 || pos > count)
    {
        printf("\nInvalid position\n");
    }
    else if (pos == 1)
    {
        p = start;
        start = start->link;
        printf("\nDeleted data: %d\n", p->data);
        free(p);
    }
    else
    {
        i = 1;
        m = start;
        while (i < pos)
        {
            n = m;
            m = m->link;
            i++;
        }
        n->link = m->link;
        m->link = NULL;
        printf("\nDeleted data: %d\n", m->data);
        free(m);
    }
}

int node_count()
{
    int count = 0;
    p = start;
    while (p != NULL)
    {
        count++;
        p = p->link;
    }
    return count;
}
void display()
{
    if (start == NULL)
    {
        printf("\n linked list is empty");
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