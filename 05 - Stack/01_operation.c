#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    int *array;
};

int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct stack *ptr, int value){
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else{
        ptr->top++;
        ptr->array[ptr->top] = value;
    }
}

void pop(struct stack *ptr){
    if (isEmpty(ptr))
    {
        printf("Stack underflow.\n");
    }
    else{
        int value = ptr->array[ptr->top];
        ptr->top--;
        printf("Popped element: %d\n", value);
    }
}

int peek(struct stack *ptr, int i){
    int arrInd = ptr->top - i + 1;
    if (arrInd < 0)
    {
        printf("Invalid position\n");
    }
    else
    {
        return ptr->array[arrInd];
    }
} 

int stachTop(struct stack *ptr){
    if (isEmpty(ptr)){
        printf("Stack is empty.\n");
        return -1;
    }
    else{
        return ptr->array[ptr->top];
    }
}

int stackBottom(struct stack *ptr){
    if (isEmpty(ptr)){
        printf("Stack is empty.\n");   
        return -1;
    } 
    else{
        return ptr->array[0];
    }
}

int main()
{
    printf("Stack Operations\n");

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));  

    s->size = 10; 
    s->top = -1;
    s->array = (int *)malloc(s->size * sizeof(int)); 

    push(s, 10);
    push(s, 20); 
    push(s, 22); 
    push(s, 2); 
    push(s, 15); 

    pop(s);

    for (int j = 1; j <= s->top + 1; j++)
    {
        printf("The value at position %d is %d \n", j, peek(s, j));
    }

    printf("The top element is %d\n", stachTop(s));
    printf("The bottom element is %d\n", stackBottom(s));

    free(s->array);
    free(s); 

    return 0;
}



