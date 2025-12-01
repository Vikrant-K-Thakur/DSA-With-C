#include <stdio.h>
#include <stdlib.h>

struct Node
{
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

int main() 
{
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate nodes in the heap
    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));

    // Link first and second nodes
    head->data = 1;
    head->next = second;
    
    // Link second and third nodes
    second->data = 2;
    second->next = third;

    // Terminate the list at the third node`
    third->data = 3;
    third->next = NULL;

    linkedListTraversal(head);
      
    
    return 0;
}

