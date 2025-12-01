#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node *left, *right;
};

// Create new node
struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

// Stack for Non-Recursive Traversals
struct Stack
{
    struct Node *arr[100];
    int top;
};

void push(struct Stack *s, struct Node *node)
{
    if (node != NULL)
        s->arr[++(s->top)] = node;
}

struct Node *pop(struct Stack *s)
{
    if (s->top == -1)
        return NULL;
    return s->arr[(s->top)--];
}

int isEmpty(struct Stack *s)
{
    return (s->top == -1);
}

// Non-Recursive Traversals
void inorderNonRecursive(struct Node *root)
{
    struct Stack s;
    s.top = -1;
    struct Node *curr = root;

    while (curr != NULL || !isEmpty(&s))
    {
        while (curr != NULL)
        {
            push(&s, curr);
            curr = curr->left;
        }
        curr = pop(&s);
        if (curr == NULL)
            break;
        printf("%d ", curr->data);
        curr = curr->right;
    }
}

void preorderNonRecursive(struct Node *root)
{
    if (root == NULL)
        return;
    struct Stack s;
    s.top = -1;
    push(&s, root);

    while (!isEmpty(&s))
    {
        struct Node *node = pop(&s); 
        if (node == NULL)
            continue;
        printf("%d ", node->data);

        if (node->right)
            push(&s, node->right);
        if (node->left)
            push(&s, node->left);
    }
}

void postorderNonRecursive(struct Node *root)
{
    if (root == NULL)
        return;
    struct Stack s1, s2;
    s1.top = -1;
    s2.top = -1;

    push(&s1, root);
    while (!isEmpty(&s1))
    {
        struct Node *node = pop(&s1);
        if (node == NULL)
            continue;
        push(&s2, node);

        if (node->left)
            push(&s1, node->left);
        if (node->right)
            push(&s1, node->right);
    }
    while (!isEmpty(&s2))
    {
        struct Node *node = pop(&s2);
        if (node == NULL)
            continue;
        printf("%d ", node->data);
    }
}

int main()
{
    /* Hard-coded tree:
             50
            /  \
          30    70
         / \   / \
       20 40 60  80
    */
    struct Node *root = NULL;
    root = newNode(50);
    root->left = newNode(30);
    root->right = newNode(70);
    root->left->left = newNode(20);
    root->left->right = newNode(40);
    root->right->left = newNode(60);
    root->right->right = newNode(80);

    printf("Non-Recursive Inorder: ");
    inorderNonRecursive(root);
    printf("\n");

    printf("Non-Recursive Preorder: ");
    preorderNonRecursive(root);
    printf("\n");

    printf("Non-Recursive Postorder: ");
    postorderNonRecursive(root);
    printf("\n");

    return 0;
}
