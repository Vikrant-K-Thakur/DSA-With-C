#include <stdio.h>

int adj[10][10], visited[10], stack[10];
int top = -1, n;

/*
    Initial BST:
          1
         / \
        3   2
         \  /
          4

stack = 
visited = 1 1 1 1
print = 1 3 4 2

*/


void dfs(int start)
{
    stack[++top] = start; // push start node
    visited[start] = 1;   // mark start visited

    while (top != -1)
    { // while stack not empty

        int node = stack[top--]; // pop element from stack
        printf("%d ", node);     // print the node

        // check all neighbors (in reverse order to match logic)
        for (int i = n; i >= 1; i--)
        {
            if (adj[node][i] == 1 && visited[i] == 0)
            {
                stack[++top] = i; // push neighbor
                visited[i] = 1;   // mark visited
            }
        }
    }
}

int main()
{

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);

    int start;
    printf("Enter starting node: ");
    scanf("%d", &start);

    dfs(start);

    return 0;
}