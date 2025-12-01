#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

/* Node for linked list (chain) */
typedef struct Node {
    int key;
    struct Node *next;
} Node;

/* Hash table: array of pointers to Node */
Node* table[TABLE_SIZE];

/* Simple hash function */
int hash(int key) {
    return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE; // safe for negative keys
}

/* Create a new node */
Node* create_node(int key) {
    Node* n = (Node*)malloc(sizeof(Node));
    n->key = key;
    n->next = NULL;
    return n;
}

/* Initialize table */
void init_table() {
    for (int i = 0; i < TABLE_SIZE; ++i) table[i] = NULL;
}

/* Insert (at head of chain) */
void insert_key(int key) {
    int idx = hash(key);
    // avoid duplicate insertion (optional)
    Node *cur = table[idx];
    while (cur != NULL) {
        if (cur->key == key) {
            printf("Key %d already exists at index %d. Not inserting duplicate.\n", key, idx);
            return;
        }
        cur = cur->next;
    }

    Node *n = create_node(key);
    n->next = table[idx];
    table[idx] = n;
    printf("Inserted %d at index %d\n", key, idx);
}

/* Search key: returns pointer to node or NULL */
Node* search_key(int key) {
    int idx = hash(key);
    Node *cur = table[idx];
    while (cur != NULL) {
        if (cur->key == key) return cur;
        cur = cur->next;
    }
    return NULL;
}

/* Delete key (if present) */
void delete_key(int key) {
    int idx = hash(key);
    Node *cur = table[idx], *prev = NULL;

    while (cur) {
        if (cur->key == key) {
            if (prev) prev->next = cur->next;
            else table[idx] = cur->next;
            free(cur);
            printf("Deleted %d from index %d\n", key, idx);
            return;
        }
        prev = cur;
        cur = cur->next;
    }
    printf("Key %d not found (cannot delete)\n", key);
}

/* Display whole table */
void display_table() {
    printf("\nHash Table (chaining):\n");
    for (int i = 0; i < TABLE_SIZE; ++i) {
        printf("[%2d] -> ", i);
        Node *cur = table[i];
        if (!cur) {
            printf("NULL\n");
            continue;
        }
        while (cur) {
            printf("%d -> ", cur->key);
            cur = cur->next;
        }
        printf("NULL\n");
    }
    printf("\n");
}

/* Free all nodes (cleanup) */
void free_table() {
    for (int i = 0; i < TABLE_SIZE; ++i) {
        Node *cur = table[i];
        while (cur) {
            Node *tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        table[i] = NULL;
    }
}

int main() {
    init_table();
    int choice, key;

    while (1) {
        printf("=== Hashing with Chaining (Menu) ===\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Choose an option: ");
        if (scanf("%d", &choice) != 1) {
            // handle invalid input
            printf("Invalid input. Exiting.\n");
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert_key(key);
                break;
            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                delete_key(key);
                break;
            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                if (search_key(key))
                    printf("Key %d found in table.\n", key);
                else
                    printf("Key %d NOT found.\n", key);
                break;
            case 4:
                display_table();
                break;
            case 5:
                free_table();
                printf("Exiting. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    free_table();
    return 0;
}
