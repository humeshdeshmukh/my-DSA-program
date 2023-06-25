/* C program to implement BFS(breadth-first search) and DFS(depth-first search) algorithm */
#include <stdio.h>
int q[20], top = -1, front = -1, rear = -1, a[20][20], vis[20], stack[20];
int delete();
void add(int item);
void bfs(int s, int n);
void dfs(int s, int n);
void push(int item);
int pop();

int main()
{
    int n, i, s, ch, j;
    char c, dummy;
    printf("\n HUMESH DESHMUKH\n ROLL NO. 34");
    printf("\n ENTER THE NUMBER VERTICES ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf("ENTER 1 IF %d HAS A NODE WITH %d ELSE 0 ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("THE ADJACENCY MATRIX IS\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            printf(" %d", a[i][j]);
        }
        printf("\n");
    }

    do
    {
        for (i = 1; i <= n; i++)
            vis[i] = 0;
        printf("\nMENU");
        printf("\n1.B.F.S");
        printf("\n2.D.F.S");
        printf("\nENTER YOUR CHOICE");
        scanf("%d", &ch);
        printf("ENTER THE SOURCE VERTEX :");
        scanf("%d", &s);

        switch (ch)
        {
        case 1:
            bfs(s, n);
            break;
        case 2:
            dfs(s, n);
            break;
        }
        printf("DO U WANT TO CONTINUE(Y/N) ? ");
        scanf("%c", &dummy);
        scanf("%c", &c);
    } while ((c == 'y') || (c == 'Y'));
}

/*BFS(breadth-first search) code*/
void bfs(int s, int n)
{
    int p, i;
    add(s);
    vis[s] = 1;
    p = delete ();
    if (p != 0)
        printf(" %d", p);
    while (p != 0)
    {
        for (i = 1; i <= n; i++)
            if ((a[p][i] != 0) && (vis[i] == 0))
            {
                add(i);
                vis[i] = 1;
            }
        p = delete ();
        if (p != 0)
            printf(" %d ", p);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            bfs(i, n);
}

void add(int item)
{
    if (rear == 19)
        printf("QUEUE FULL");
    else
    {
        if (rear == -1)
        {
            q[++rear] = item;
            front++;
        }
        else
            q[++rear] = item;
    }
}
int delete()
{
    int k;
    if ((front > rear) || (front == -1))
        return (0);
    else
    {
        k = q[front++];
        return (k);
    }
}

/*DFS(depth-first search) code*/
void dfs(int s, int n)
{
    int i, k;
    push(s);
    vis[s] = 1;
    k = pop();
    if (k != 0)
        printf(" %d ", k);
    while (k != 0)
    {
        for (i = 1; i <= n; i++)
            if ((a[k][i] != 0) && (vis[i] == 0))
            {
                push(i);
                vis[i] = 1;
            }
        k = pop();
        if (k != 0)
            printf(" %d ", k);
    }
    for (i = 1; i <= n; i++)
        if (vis[i] == 0)
            dfs(i, n);
}
void push(int item)
{
    if (top == 19)
        printf("Stack overflow ");
    else
        stack[++top] = item;
}
int pop()
{
    int k;
    if (top == -1)
        return (0);
    else
    {
        k = stack[top--];
        return (k);
    }
}


/*Breadth-First Search (BFS) and Depth-First Search (DFS) are fundamental 
graph traversal algorithms used in computer science and graph theory. 
Let's explore these algorithms in more detail and discuss their properties and applications:

Breadth-First Search (BFS):
BFS explores a graph in a breadth-first manner,
 meaning it visits all the vertices at the same level before moving to the next level. 
 Starting from a given source vertex, BFS systematically visits adjacent vertices 
 before exploring deeper into the graph. It utilizes a queue data structure to keep 
 track of the vertices to be visited.

Theory: BFS guarantees that it visits all vertices at the minimum 
possible depth or level from the source. This property makes it particularly
 useful for finding the shortest path between two vertices in an unweighted graph. 
 Additionally, BFS can be employed for applications such as finding connected components,
  testing bipartiteness, and solving puzzles that require the shortest solution.

Depth-First Search (DFS):
DFS explores a graph by going as deep as possible before backtracking. 
It starts from a given source vertex, traverses one path until it reaches the end, 
and then backtracks to explore other paths. DFS employs a stack data structure
 to keep track of the vertices to be visited.

Theory: DFS is well-suited for detecting cycles in a graph, 
as it explores deeply connected regions thoroughly.
 It is also frequently used for topological sorting and finding connected components.
  Unlike BFS, DFS does not guarantee finding the shortest path between two vertices, 
  as it can get trapped in cycles. However, DFS is efficient when the search space
   is large and the objective is to explore as deeply as possible before backtracking.

Choosing between BFS and DFS depends on the nature of the problem and the 
characteristics of the graph:

BFS is preferred when the objective is to find the shortest path or
 the minimum number of edges between two vertices.
DFS is suitable for exploring deeply connected regions or when 
the search space is extensive and exploring deeply is desirable.
BFS requires more memory due to the queue data structure, whereas
 DFS requires memory for the stack. This can be a limitation in
  graphs with a large number of vertices.
BFS guarantees finding the shortest path, but it may explore 
more nodes than DFS in certain scenarios.
DFS may encounter infinite loops if the graph contains cycles,
 while BFS effectively avoids this issue.
In conclusion, both BFS and DFS possess unique strengths and are
 applicable to different problem domains and graph characteristics. 
 The selection between these algorithms depends on the specific
  requirements of the problem at hand.*/
