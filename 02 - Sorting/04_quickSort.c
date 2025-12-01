#include <stdio.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int parition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot)
        {
            i++;
        }
        while (A[j] > pivot)
        {
            j--;
        }
        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }

    } while (i < j);

    temp = A[low];
    A[low] = A[j];
    A[j] = temp;

    return j;
}

void quickSort(int *A, int low, int high)
{
    int partitionindex;
    if (low < high)
    {
        partitionindex = parition(A, low, high);
        
        quickSort(A, low, partitionindex - 1);
        quickSort(A, partitionindex + 1, high);
    }
}

int main()
{
    int arr[] = {11, 6, 19, 10, 2, 1};
    int n = 6;

    printArray(arr, n);
    quickSort(arr, 0, n - 1);
    printArray(arr, n);

    return 0;
}