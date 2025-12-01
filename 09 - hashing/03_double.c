#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY   -1
#define DELETED -2

int table[TABLE_SIZE];

/* First hash function */
int h1(int key) {
    return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
}

/* Second hash function (must never return 0) */
int h2(int key) {
    return 7 - (key % 7);   // 7 is prime < TABLE_SIZE
}

/* Initialize table */
void init() {
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = EMPTY;
}

/* Insert using Double Hashing */
void insertDH(int key) {
    int idx1 = h1(key);
    int step = h2(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (idx1 + i * step) % TABLE_SIZE;

        if (table[pos] == EMPTY || table[pos] == DELETED) {
            table[pos] = key;
            printf("Inserted %d at index %d\n", key, pos);
            return;
        }
    }

    printf("Table FULL! Cannot insert %d\n", key);
}

/* Search using Double Hashing */
int searchDH(int key) {
    int idx1 = h1(key);
    int step = h2(key);

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (idx1 + i * step) % TABLE_SIZE;

        if (table[pos] == EMPTY)
            return -1;  // key definitely does NOT exist

        if (table[pos] == key)
            return pos;
    }

    return -1;
}

/* Delete key */
void deleteDH(int key) {
    int pos = searchDH(key);

    if (pos == -1) {
        printf("Key %d NOT found\n", key);
        return;
    }

    table[pos] = DELETED;
    printf("Deleted %d from index %d\n", key, pos);
}

/* Display table */
void displayDH() {
    printf("\nHash Table (Double Hashing):\n");
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
    int key, choice;

    while (1) {
        printf("=== Double Hashing Hash Table ===\n");
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
                insertDH(key);
                break;

            case 2:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteDH(key);
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int pos = searchDH(key);
                if (pos == -1)
                    printf("Key %d NOT found\n", key);
                else
                    printf("Key %d found at index %d\n", key, pos);
                break;

            case 4:
                displayDH();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
