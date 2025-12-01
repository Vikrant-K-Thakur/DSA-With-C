#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

int table[TABLE_SIZE];

/* Hash function */
int hash(int key) {
    return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
}

/* Initialize table */
void init() {
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = EMPTY;
}

/* Insert using Quadratic Probing */
void insertQP(int key) {
    int idx = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (idx + i * i) % TABLE_SIZE;

        if (table[pos] == EMPTY || table[pos] == DELETED) {
            table[pos] = key;
            printf("Inserted %d at index %d\n", key, pos);
            return;
        }
    }

    printf("Table Full! Cannot insert %d\n", key);
}

/* Search using Quadratic Probing */
int searchQP(int key) {
    int idx = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (idx + i * i) % TABLE_SIZE;

        if (table[pos] == EMPTY)
            return -1;  // key definitely not found

        if (table[pos] == key)
            return pos;
    }

    return -1;
}

/* Delete key */
void deleteQP(int key) {
    int pos = searchQP(key);

    if (pos == -1) {
        printf("Key %d NOT found\n", key);
        return;
    }

    table[pos] = DELETED;
    printf("Deleted %d from index %d\n", key, pos);
}

/* Display table */
void displayQP() {
    printf("\nHash Table (Quadratic Probing):\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (table[i] == EMPTY)
            printf("[%d] : EMPTY\n", i);
        else if (table[i] == DELETED)
            printf("[%d] : DELETED\n", i);
        else
            printf("[%d] : %d\n", i, table[i]);
    }
    printf("\n");
}

int main() {
    init();
    int choice, key;

    while (1) {
        printf("=== Quadratic Probing Hash Table ===\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insertQP(key);
                break;

            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteQP(key);
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int pos = searchQP(key);
                if (pos == -1)
                    printf("Key %d NOT found\n", key);
                else
                    printf("Key %d found at index %d\n", key, pos);
                break;

            case 4:
                displayQP();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
