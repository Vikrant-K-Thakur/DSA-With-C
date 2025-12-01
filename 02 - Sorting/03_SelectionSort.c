#include <stdio.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int *A, int n)
{
    int minindex, temp;
    for (int i = 0; i < n; i++)
    {
        minindex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[minindex])
            {
                minindex = j;
            }
        }
        temp = A[i];
        A[i] = A[minindex];
        A[minindex] = temp;
    }
}

int main()
{
    int arr[] = {11, 6, 19, 10, 2, 1};
    int n = 6;

    printArray(arr, n);
    selectionSort(arr, n);
    printArray(arr, n);

    return 0;
}