#include <stdio.h>
#define SIZE 10

int HT[SIZE];

// Function to initialize the hash table
void init()
{
    for (int i = 0; i < SIZE; i++)
        HT[i] = -1;
}

void insert(int key)
{
    int index = key % SIZE;
    if (HT[index] == -1)
    {
        HT[index] = key;
        printf("\nInserted %d at index %d", key, index);
    }
    else
    {
        int index1 = index;
        index = (index + 1) % SIZE;
        while (HT[index] != -1)
        {
            index = (index + 1) % SIZE;
        }
        HT[index] = key;
        printf("\nCollision at index %d -> inserted %d at index %d", index1, key, index);
    }
}

void search(int key)
{
    int index = key % SIZE;
    int count = 0;
    while (count < SIZE)
    {
        if (HT[index] == key)
        {
            printf("\nSearch %d: Found at index %d", key, index);
            return;
        }
        index = (index + 1) % SIZE;
        count++;
    }
    printf("\nSearch %d: Not found", key);
}

void delete1(int key)
{
    int index = key % SIZE;
    int count = 0;
    while (count < SIZE)
    {
        if (HT[index] == key)
        {
            HT[index] = -1;
            printf("\nDeleted %d from index %d", key, index);
            return;
        }
        index = (index + 1) % SIZE;
        count++;
    }
    printf("\nKey %d not found", key);
}

void display()
{
    printf("\n\nHash Table:\nIndex: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", i);
    printf("\nValue: ");
    for (int i = 0; i < SIZE; i++)
        printf("%d ", HT[i]);
}

int main()
{
    init();
    insert(5);
    insert(15);
    insert(25);
    insert(35);
    search(25);
    delete1(15);
    insert(45);
    display();

    return 0;
}