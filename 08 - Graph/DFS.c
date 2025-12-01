#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int top;
    int *arr;
    int size;
};

void push(struct stack *s, int value)
{
    if (s->top == s->size - 1)
    {
        return;
    }
    s->top++;
    s->arr[s->top] = value;
}

int pop(struct stack *s)
{
    if (s->top == -1)
    {
        return -1;
    }
    int value = s->arr[s->top];
    s->top--;
    return value;
}

void dfs(int start, int adj[5][5])
{
    int visited[5] = {0};

    struct stack s;
    s.size = 10;
    s.arr = (int *)malloc(sizeof(int) * s.size);
    if (s.arr == NULL)
    {
        fprintf(stderr, "malloc failed\n");
        return;
    }
    s.top = -1;

    // push start
    push(&s, start);
    visited[start] = 1;

    printf("DFS traversal (starting at %d): ", start);

    while (s.top != -1)
    {
        int u = pop(&s);
        if (u == -1)
            break;

        printf("%d ", u);

        for (int v = 5 - 1; v >= 0; v--)
        {
            if (adj[u][v] == 1 && !visited[v])
            {
                push(&s, v);
                visited[v] = 1;
            }
        }
    }

    printf("\n");
}

int main(void)
{
    int adj[5][5] = {
        {0, 1, 1, 0, 0},
        {1, 0, 0, 1, 0},
        {1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0},
        {0, 0, 1, 0, 0}};

    dfs(0, adj);

    return 0;
}
