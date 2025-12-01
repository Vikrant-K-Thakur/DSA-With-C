#include <stdio.h>

#define TABLE_SIZE 11
#define EMPTY -1
#define MAX_LOOP 20   // avoid infinite loops

int table1[TABLE_SIZE];
int table2[TABLE_SIZE];

/* Hash functions */
int h1(int key) { return key % TABLE_SIZE; }
int h2(int key) { return (key / TABLE_SIZE) % TABLE_SIZE; }

/* Initialize tables */
void init() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table1[i] = EMPTY;
        table2[i] = EMPTY;
    }
}

void insertCuckoo(int key) {
    int loop = 0;
    int pos, temp;

    while (loop < MAX_LOOP) {

        /* Try table 1 */
        pos = h1(key);
        if (table1[pos] == EMPTY) {
            table1[pos] = key;
            printf("Inserted %d in Table 1 at index %d\n", key, pos);
            return;
        }

        /* Evict key from Table 1 */
        temp = table1[pos];
        table1[pos] = key;
        key = temp;

        /* Try table 2 */
        pos = h2(key);
        if (table2[pos] == EMPTY) {
            table2[pos] = key;
            printf("Inserted %d in Table 2 at index %d\n", key, pos);
            return;
        }

        /* Evict key from Table 2 */
        temp = table2[pos];
        table2[pos] = key;
        key = temp;

        loop++;
    }

    printf("Cycle detected! Rehash needed for key %d\n", key);
}

/* Search key */
int searchCuckoo(int key) {
    int pos1 = h1(key);
    int pos2 = h2(key);

    if (table1[pos1] == key) return 1;
    if (table2[pos2] == key) return 2;

    return -1;
}

/* Display both tables */
void display() {
    printf("\nTable 1:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
        printf("[%d] %d\n", i, table1[i]);

    printf("\nTable 2:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
        printf("[%d] %d\n", i, table2[i]);

    printf("\n");
}

int main() {
    init();
    int choice, key;

    while (1) {
        printf("\n=== Cuckoo Hashing Menu ===\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insertCuckoo(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                int t = searchCuckoo(key);
                if (t == 1)
                    printf("Key %d found in Table 1 at position %d\n", key, h1(key));
                else if (t == 2)
                    printf("Key %d found in Table 2 at position %d\n", key, h2(key));
                else
                    printf("Key %d NOT found\n", key);
                break;

            case 3:
                display();
                break;

            case 4:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
