#include <stdio.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

// push
void push(int x)
{
    stack[++top] = x;
}

// pop
int pop()
{
    return stack[top--];
}

int main()
{
    char postfix[100];
    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        // Check if digit (0-9) manually
        if (ch >= '0' && ch <= '9')
        {
            int value = ch - '0'; // convert char → int
            push(value);
        }
        else
        {
            // operator
            int op2 = pop();
            int op1 = pop();
            int result;

            if (ch == '+')
                result = op1 + op2;
            else if (ch == '-')
                result = op1 - op2;
            else if (ch == '*')
                result = op1 * op2;
            else if (ch == '/')
                result = op1 / op2;

            push(result);
        }
    }

    printf("Result = %d\n", stack[top]);
    return 0;
}