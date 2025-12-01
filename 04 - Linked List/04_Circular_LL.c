#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

void linkedListTraversal(struct Node* head)
{
    struct Node* ptr = head;
    do
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = data;

    if (head == NULL) {
        ptr->next = ptr; // Points to itself
        return ptr;
    }

    struct Node* p = head;
    // Traverse to the last node
    while (p->next != head) {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;
    head = ptr;

    return head;
}



int main() 
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    head = (struct Node*)malloc(sizeof(struct Node));
    second = (struct Node*)malloc(sizeof(struct Node));
    third = (struct Node*)malloc(sizeof(struct Node));
    fourth = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;
    
    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;
    
    fourth->data = 4;
    fourth->next = head;

    printf("Circular Linked List before insertion:\n");
    linkedListTraversal(head);

    head = insertAtBeginning(head, 0);

    printf("Circular Linked List after insertion:\n");
    linkedListTraversal(head);
      
    
    return 0;
}