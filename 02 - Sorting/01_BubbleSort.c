#include <stdio.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void bubbleSort(int *arr, int n)
{
    int temp;
    for (int i = 0; i < n; i++) // for no. of passess
    {
        for (int j = 0; j < n - i - 1; j++) // for no. of comparisons
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void bubbleSortAdaptive(int *arr, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n; i++) // for no. of passess
    {
        printf("Working on pass number %d\n", i + 1);
        isSorted = 1;
        for (int j = 0; j < n - i - 1; j++) // for no. of comparisons
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                isSorted = 0;
            }
        }
        if (isSorted)
        {
            return;
        }
    }
}

int main()
{
    int arr[] = {11, 6, 19, 10, 2, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    printArray(arr, size);
    bubbleSort(arr, size);
    printArray(arr, size);

    return 0;
}
