#include <stdio.h>

#define TABLE_SIZE 10
#define EMPTY -1
#define DELETED -2

int table[TABLE_SIZE];

/* Hash function */
int hash(int key)
{
    return (key % TABLE_SIZE + TABLE_SIZE) % TABLE_SIZE;
}

/* Initialize table */
void init()
{
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = EMPTY;
}

/* Insert using Linear Probing */
void insertLP(int key)
{
    int idx = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int pos = (idx + i) % TABLE_SIZE;

        if (table[pos] == EMPTY || table[pos] == DELETED)
        {
            table[pos] = key;
            printf("Inserted %d at index %d\n", key, pos);
            return;
        }
    }
    printf("Table Full! Cannot insert %d\n", key);
}

/* Search key */
int searchLP(int key)
{
    int idx = hash(key);

    for (int i = 0; i < TABLE_SIZE; i++)
    {
        int pos = (idx + i) % TABLE_SIZE;

        if (table[pos] == EMPTY) // empty means key not present
            return -1;

        if (table[pos] == key)
            return pos;
    }
    return -1;
}

/* Delete key */
void deleteLP(int key)
{
    int pos = searchLP(key);

    if (pos == -1)
    {
        printf("Key %d not found!\n", key);
        return;
    }

    table[pos] = DELETED;
    printf("Deleted %d from index %d\n", key, pos);
}

/* Display table */
void displayLP()
{
    printf("\nHash Table (Linear Probing):\n");
    for (int i = 0; i < TABLE_SIZE; i++)
    {
        if (table[i] == EMPTY)
            printf("[%d] : EMPTY\n", i);
        else if (table[i] == DELETED)
            printf("[%d] : DELETED\n", i);
        else
            printf("[%d] : %d\n", i, table[i]);
    }
    printf("\n");
}

int main()
{
    init();

    int choice, key;

    while (1)
    {
        printf("=== Linear Probing Hash Table ===\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter key to insert: ");
            scanf("%d", &key);
            insertLP(key);
            break;
        case 2:
            printf("Enter key to delete: ");
            scanf("%d", &key);
            deleteLP(key);
            break;
        case 3:
            printf("Enter key to search: ");
            scanf("%d", &key);
            int pos = searchLP(key);
            if (pos == -1)
                printf("Key %d NOT found\n", key);
            else
                printf("Key %d found at index %d\n", key, pos);
            break;
        case 4:
            displayLP();
            break;
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
        }
    }
}
