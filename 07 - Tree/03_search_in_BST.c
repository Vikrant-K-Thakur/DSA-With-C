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
    struct node *n;
    n = (struct node *)malloc(sizeof(struct node));
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

int isBST(struct node *root)
{
    static struct node *prev = NULL;
    if (root != NULL)
    {
        if (!isBST(root->left))
        {
            return 0;
        }
        if (prev != NULL && root->data <= prev->data)
        {
            return 0;
        }
        prev = root;
        return isBST(root->right);
    }
    else
    {
        return 1;
    }
}

struct node* search(struct node* root, int key){
    if (root == NULL)
    {
        return NULL;
    }
    if (root -> data == key)
    {
        return root;
    }
    else if (key < root -> data)
    {
        return search(root -> left, key);
    }
    else {
        return search( root-> right, key);
    }   
}

struct node* altsearch(struct node* root, int key){
    while (root != NULL)
    {
        if (root -> data == key)
        {
            return root;
        }
        else if (key < root -> data)
        {
            root = root -> left;
        }
        else {
            root = root -> right;
        }    
    }
    return NULL;
}

int main()
{
    /*
        Tree structure:
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

    // struct node* n = search(p, 3);
    struct node* n = altsearch(p, 3);
    if (n != NULL)
    {
        printf("Found %d\n", n -> data);
    }
    else
    {
        printf("Not found\n");
    }

    return 0;
}
