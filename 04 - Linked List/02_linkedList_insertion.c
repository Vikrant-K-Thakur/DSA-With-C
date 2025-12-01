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

struct Node* insertAtBeginning(struct Node* head, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data; 
    return ptr;
}

struct Node* insertAtIndex(struct Node* head, int data, int index){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    int i = 0;
    while (i != index - 1) {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next; 
    p->next = ptr;
    return head;
}

struct Node* insertAtEnd(struct Node* head, int data){
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = head;
    while (p->next != NULL) {
        p = p->next;
    }

    ptr->data = data;
    ptr->next = NULL;
    p->next = ptr;
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

    printf("Linked List before insertion:\n");
    linkedListTraversal(head);
    // head = insertAtBeginning(head, 0);
    // head = insertAtIndex(head, 5, 2);
    head = insertAtEnd(head, 5);
    printf("Linked List after insertion:\n");
    linkedListTraversal(head);
      
    return 0;
}
