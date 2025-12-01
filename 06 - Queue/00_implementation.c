#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue *q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue *q)
{
    if (q->f == q->r)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
    {
        printf("Queue is overflow");
    }
    else
    {
        q->r = q->r + 1;
        q->arr[q->r] = val;
    }
}

void dequeue(struct queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("Queue is underflow");
    }
    else
    {
        q->f++;
        a = q->arr[q->f];
    }
}

int main()
{
    struct queue q;
    q.size = 100;
    q.f = q.r = -1;
    q.arr = (int *)malloc((q.size) * sizeof(int));

    enqueue(&q, 12);
    enqueue(&q, 1);
    enqueue(&q, 20);
    return 0;
}