#include <stdio.h>
#include <stdlib.h>

struct circularQueue
{
    int size;
    int f;
    int r;
    int *arr;
};


void enqueue(struct circularQueue *q, int val){
    if ((q -> r + 1) % q -> size == q -> f)
    {
        printf("Queue overflow \n");
    }
    else {
        q -> r = (q -> r + 1) % q -> size;
        q -> arr[q -> r] = val;
        printf("Element enqueue %d\n", val);
    }
}

int dequeue(struct circularQueue *q){
    int val = -1;
    if (q -> r == q -> f)
    {
        printf("Queue is empty");
    }
    else {
        q -> f = (q -> f + 1) % q -> size;
        val = q -> arr[q -> f];
        printf("Element dequeue %d\n", val);
    }
    return val;
}

int main() 
{
    struct circularQueue q;
    q.size = 3;
    q.f = q.r = 0;
    q.arr = (int *)malloc(q.size*sizeof(int));

    enqueue(&q, 1);
    enqueue(&q, 3);
    enqueue(&q, 2);

    dequeue(&q);
    dequeue(&q);
    dequeue(&q);

    return 0;
}