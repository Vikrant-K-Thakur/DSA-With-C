#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* ptr)
{
    while (ptr != NULL) {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int isEmpty(struct Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct Node *top)
{
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if (p == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


struct Node* push(struct Node *top, int x){
    if (isFull(top))
    {
        printf("Stack overflow\n");
    }
    else
    {
        struct Node* n = (struct Node*)malloc(sizeof(struct Node));
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

struct Node* pop(struct Node* *top){
    if (isEmpty(*top)){
        printf("Stack underflow\n");
    }
    else
    {
        struct Node* n = *top;
        *top = (*top)->next;
        int x = n->data;
        free(n);
        printf("Popped element: %d\n", x);
        return *top;
    } 
}

int peek(int pos, struct Node *top){
    struct Node* ptr = top;
    for (int i = 0; i < pos-1 && ptr !=NULL; i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else{
        printf("Not a valid position\n");
        return -1;
    }
}

int main() 
{
    struct Node* top = NULL;
    printf("Stack Operations using Linked List\n");
    printf("Pushing elements onto the stack:\n");
    top = push(top, 5);
    top = push(top, 10);
    top = push(top, 0);
    top = push(top, 1);

    // linkedListTraversal(top);
    // printf("After popping an element:\n");
    // top = pop(&top);
    // linkedListTraversal(top);

    printf("Peeking at position 2: %d\n", peek(2, top));
    printf("Peeking at position 5: %d\n", peek(5, top));
     
    return 0;
}