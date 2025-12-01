#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *left;
    struct node *right;
    int height;
};

int getHeight(struct node *n)
{
    if (n == NULL)
        return 0;
    return n->height;
}

int maxInt(int a, int b)
{
    return (a > b) ? a : b;
}

struct node *createNode(int key)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

int getBalanceFactor(struct node *n)
{
    if (n == NULL)
        return 0;
    return getHeight(n->left) - getHeight(n->right);
}

/*

 BEFORE ROTATION  AFTER RIGHT ROTATION

        y                x
       / \              / \
      x   T3           T1   y
     / \                   / \
    T1  T2                T2  T3

*/

struct node *rightRotate(struct node *y)
{
    //  before intialization
    struct node *x = y->left;
    struct node *T2 = x->right;

    // after rotation
    x->right = y;
    y->left = T2;

    y->height = 1 + maxInt(getHeight(y->left), getHeight(y->right));
    x->height = 1 + maxInt(getHeight(x->left), getHeight(x->right));

    return x;
}

/*

BEFORE ROTATION    AFTER LEFT ROTATION
      x                    y
     / \                  / \
    T1  y                x   T3
       / \              / \
      T2  T3           T1  T2

*/

struct node *leftRotate(struct node *x)
{
    struct node *y = x->right;
    struct node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + maxInt(getHeight(x->left), getHeight(x->right));
    y->height = 1 + maxInt(getHeight(y->left), getHeight(y->right));

    return y;
}

struct node *insert(struct node *node, int key)
{
    // simple insertion of node
    if (node == NULL)
        return createNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    else
        return node;

    // update height
    node->height = 1 + maxInt(getHeight(node->left), getHeight(node->right));
    // check the balance factor
    int bf = getBalanceFactor(node);

    // Balancing cases

    /*
            node
             / 
        node->left   
           / 
          key   
    */
    // left left case
    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    /*
        Initial BST:
           node
             \
          node->right
               \
               key
    */    
    // right right case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    // left right case
    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // right left case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        preorder(root->left);
        preorder(root->right);
    }
}

void freeTree(struct node *root)
{
    if (root == NULL)
        return;
    freeTree(root->left);
    freeTree(root->right);
    free(root);
}

int main(void)
{
    struct node *root = NULL;

    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 10);
    // root = insert(root, 4);
    // root = insert(root, 5);

    printf("Preorder traversal of the AVL tree:\n");
    preorder(root);
    printf("\n");

    freeTree(root);
    return 0;
}
