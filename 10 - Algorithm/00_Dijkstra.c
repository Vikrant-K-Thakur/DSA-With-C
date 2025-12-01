#include <stdio.h>
#include <limits.h>

#define V 5 // number of vertices

int minDistance(int dist[], int visited[])
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < V; v++)
        if (!visited[v] && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }

    return min_index;
}

void dijkstra(int graph[V][V], int src)
{
    int dist[V];    // shortest distance from src
    int visited[V]; // visited vertices

    // initialize all distances as infinite and not visited
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0; // distance to itself is 0

    // find shortest path for all vertices
    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, visited);
        visited[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!visited[v] &&
                graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // print results
    printf("Vertex \t Distance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d \t %d\n", i, dist[i]);
}

int main()
{
    int graph[V][V] = {
        {0, 2, 0, 1, 0},
        {2, 0, 3, 2, 0},
        {0, 3, 0, 0, 7},
        {1, 2, 0, 0, 1},
        {0, 0, 7, 1, 0}};

    dijkstra(graph, 0); // run from vertex 0

    return 0;
}
