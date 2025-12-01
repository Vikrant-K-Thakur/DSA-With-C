#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100][100];
int top = -1;

// Push into stack
void push(char *str)
{
    top++;
    strcpy(stack[top], str);
}

// Pop from stack
char *pop()
{
    return stack[top--];
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char postfix[] = "abc*+de/-";

    for (int i = 0; postfix[i] != '\0'; i++)
    {
        char ch = postfix[i];

        if (!isOperator(ch))
        {
            // Operand → push as string
            char temp[2];
            temp[0] = ch;
            temp[1] = '\0';
            push(temp);
        }
        else
        {
            // Operator → pop 2 operands
            char op2[100], op1[100], expr[200];

            char *op2 = pop();
            char *op1 = pop();

            // Make new expression "(op1 ch op2)"
            sprintf(expr, "(%s%c%s)", op1, ch, op2);

            push(expr);
        }
    }

    printf("\nInfix: %s\n", stack[top]);
    return 0;
}