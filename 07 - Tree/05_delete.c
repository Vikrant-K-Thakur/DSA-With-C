#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inorder(struct node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

/*
inorder - 1 3 4 5 6

    Initial BST:
           5
         / | \
         3    6
       / | \  |
      1     4
      |     |
*/

struct node *inOrderPredecessor(struct node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node *deleteNode(struct node *root, int value)
{
    struct node *iPre;

    if (root == NULL)
    {
        return NULL;
    }

    if (value < root->data)
    {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = deleteNode(root->right, value);
    }
    else
    {
        // Case 1: Node with no child
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }

        // Case 2: Node with one child
        else if (root->left == NULL)
        {
            struct node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // Case 3: Node with two children
        else
        {

            iPre = inOrderPredecessor(root);
            root->data = iPre->data;
            root->left = deleteNode(root->left, iPre->data);
        }
    }
    return root;
}

int main()
{
    /*
        Initial BST:
              5
             / \
            3   6
           / \
          1   4
    */

    struct node *p = createNode(5);
    struct node *p1 = createNode(3);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(1);
    struct node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;

    printf("Inorder before deletion:\n");
    inorder(p);
    printf("\n");

    p = deleteNode(p, 3); // Delete node with value 3

    printf("Inorder after deletion:\n");
    inorder(p);
    printf("\n");

    return 0;
}
