#include <stdio.h>

int adj[10][10], visited[10], queue[10]; // adjacency matrix, visited array, queue
int n, front = -1, rear = -1;            // n = number of nodes, queue pointers

void bfs(int start)
{
    int i;

    visited[start] = 1;    // mark starting node as visited. For example: visited[1] = 1
    queue[++rear] = start; // insert start node into queue. rear becomes 0, queue[0] = 1
    front++;               // front becomes 0 (first element of queue)

    // BFS processing loop (runs until queue becomes empty)
    while (front <= rear)
    {
        int node = queue[front++]; // remove element from queue. First time: node = 1, front = 1
        printf("%d ", node);       // print the node in BFS order

        // Explore all neighbors of current 'node'
        for (i = 1; i <= n; i++)
        {
            // Check if there is an edge AND the neighbor is not visited
            // Example: for node=1, adj[1][2] = 1 → so 2 is neighbor
            if (adj[node][i] == 1 && visited[i] == 0)
            {
                queue[++rear] = i; // add neighbor to queue (e.g., queue[1] = 2, queue[2] = 3)
                visited[i] = 1;    // mark neighbor as visited
            }
        }
    }
}

int main()
{

    /*
        Initial BST:
              1
             / \
            3   2
             \  /
               4
    */


    int i, j, start;

    printf("Enter number of nodes: ");
    scanf("%d", &n); // for our example, user enters 4

    printf("Enter adjacency matrix:\n");

    // read adjacency matrix from user
    // for example user enters:
    // 0 1 1 0
    // 1 0 0 1
    // 1 0 0 1
    // 0 1 1 0
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &adj[i][j]);

    printf("Enter starting node: ");
    scanf("%d", &start); // user enters 1

    bfs(start); // call BFS starting from node 1

    return 0;
}