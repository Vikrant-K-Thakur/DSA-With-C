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

struct Node* deleteFirstNode(struct Node* head)
{
    struct Node *ptr = head;
    head = head->next; 
    free(ptr); 
    return head;
}

struct Node* deleteAtIndex(struct Node* head, int index){
    struct Node* p = head;
    struct Node* q = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    p->next = q->next; 
    free(q); 
    return head;
}

struct Node* deleteLastNode(struct Node* head){
    struct Node* p = head;
    struct Node* q = head->next;
    while (q->next != NULL)
    {
        p = p->next; 
        q = q->next;
    }
    p->next  = NULL; 
    free(q);
    return head;
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

    printf("Linked List before deletion:\n");
    linkedListTraversal(head);

    // head = deleteFirstNode(head);
    // head = deleteAtIndex(head, 1); 
    head = deleteLastNode(head); 

    printf("Linked List after deletion:\n");
    linkedListTraversal(head);
      
    return 0;
}