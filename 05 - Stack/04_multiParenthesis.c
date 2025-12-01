#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int size;
    int top;
    char *array;
};

int isEmpty(struct stack *ptr)
{
    return ptr->top == -1;
}

int isFull(struct stack *ptr)
{
    return ptr->top == ptr->size - 1;
}

void push(struct stack *ptr, char value)
{
    if (isFull(ptr))
    {
        printf("Stack Overflow\n");
    }
    else
    {
        ptr->top++;
        ptr->array[ptr->top] = value;
    }
}

char pop(struct stack *ptr)
{
    if (isEmpty(ptr))
    {
        printf("Stack Underflow\n");
        return '\0'; // return null character to indicate error
    }
    else
    {
        char value = ptr->array[ptr->top];
        ptr->top--;
        return value;
    }
}

int match(char a, char b)
{
    if (a == '(' && b == ')')
    {
        return 1;
    }
    if (a == '{' && b == '}')
    {
        return 1;
    }
    if (a == '[' && b == ']')
    {
        return 1;
    }
    return 0;
}

int parenthesisMatch(char *exp)
{
    // create and initialize stack
    struct stack *sp = (struct stack *)malloc(sizeof(struct stack));
    sp->size = 100;
    sp->top = -1;
    sp->array = (char *)malloc(sp->size * sizeof(char));
    int popped_char;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            push(sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
        {
            if (isEmpty(sp))
            {
                return 0; // unmatched closing parenthesis
            }
            popped_char = pop(sp);
            if (!match(popped_char, exp[i]))
            {
                return 0;
            }
        }
    }

    int result = isEmpty(sp); // if stack is empty, parentheses are balanced
    free(sp->array);
    free(sp);
    return result;
}

int main()
{
    char *exp = "{(a+b)*[c-d]/(e+f)}";
    if (parenthesisMatch(exp))
    {
        printf("The parenthesis is balanced\n");
    }
    else
    {
        printf("The parenthesis is not balanced\n");
    }

    return 0;
}
