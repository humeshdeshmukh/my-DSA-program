#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node* start;

int findmax(struct Node* s);

int main()
{
    start = NULL; // Initializing the start pointer

    // Code to create the linked list...

    // Call the findmax function
    int maximum = findmax(start);

    printf("Largest number: %d\n", maximum);

    return 0;
}

int findmax(struct Node* s)
{
    if (s == NULL)
    {
        printf("Linked list is empty.\n");
        return -1; // Return a special value to indicate an error
    }

    struct Node* p = s;
    int max = p->data;

    while (p != NULL)
    {
        if (p->data > max)
        {
            max = p->data;
        }
        p = p->next;
    }

    return max;
}
