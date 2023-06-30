/*write a user define fuction to convert circular link list( struct node *s)
into the convert a single link list into the circular link list*/

/*To convert a singly linked list into a circular linked list,
you can traverse the list and update the link of the last node to point back to the first node.
Here's an example of a user-defined function to perform this conversion:*/
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
};

void convertToCircular(struct node *start);

int main()
{
    struct node *start, *p, *q;
    int n, data;

    // Create a singly linked list
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Invalid number of nodes. Program terminated.");
        return 0;
    }

    // Create the first node
    start = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for node 1: ");
    scanf("%d", &(start->data));
    start->link = NULL;

    p = start;

    // Create the remaining nodes
    for (int i = 2; i <= n; i++)
    {
        q = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &(q->data));
        q->link = NULL;
        p->link = q;
        p = q;
    }

    // Convert the singly linked list to circular linked list
    convertToCircular(start);

    printf("Circular linked list created successfully.\n");

    // Print the circular linked list
    printf("Circular Linked List:\n");
    p = start;
    do
    {
        printf("%d ", p->data);
        p = p->link;
    } while (p != start);

    return 0;
}

void convertToCircular(struct node *start)
{
    struct node *p = start;
    while (p->link != NULL)
    {
        p = p->link;
    }
    p->link = start; // Update the link of the last node to the first node
}
