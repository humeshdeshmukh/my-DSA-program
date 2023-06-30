/*creation of  node */
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *link;
};

int main()
{
    struct node *p, *q, *r ,*start;

    p = (struct node *)malloc(sizeof(struct node));
    q = (struct node *)malloc(sizeof(struct node));
    r = (struct node *)malloc(sizeof(struct node));
    
    p->data = 10;
    q->data = 15;
    r->data = 20;
    
    p->link = q;
    q->link = r;
    r->link = NULL;
    
    start = p;
    
    printf("%d\n", p->data);
    printf("%d\n", q->data);
    printf("%d\n", r->data);

    return 0;
}
