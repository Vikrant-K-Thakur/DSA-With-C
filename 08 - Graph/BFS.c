#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int f;
    int r;
    int size;
    int *arr;
};

int enqueue(struct queue *q, int value)
{
    if (q->r == q->size - 1)
    {
        // queue full
        return 0;
    }
    else
    {
        q->r++;
        q->arr[q->r] = value;
        return 1;
    }
}

int dequeue(struct queue *q)
{
    if (q->r == q->f)
    {
        // queue empty
        return -1;
    }
    else
    {
        q->f++;
        int value = q->arr[q->f];
        return value;
    }
}

void bfs(int start, int adj[5][5])
{
    int visited[5] = {0};

    struct queue q;
    q.f = q.r = -1;
    q.size = 5 + 5;
    q.arr = (int *)malloc(q.size * sizeof(int));
    if (q.arr == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        return;
    }

    enqueue(&q, start);
    visited[start] = 1;

    printf("BFS traversal (starting at %d): ", start);

    while (1)
    {
        int c = dequeue(&q);
        if (c == -1)
            break;

        printf("%d ", c);

        for (int i = 0; i < 5; i++)
        {
            if (adj[c][i] == 1 && !visited[i])
            {
                enqueue(&q, i);
                visited[i] = 1;
            }
        }
    }

    printf("\n");
    free(q.arr);
}

int main(void)
{
    int adj[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0}};

    bfs(0, adj);

    return 0;
}
