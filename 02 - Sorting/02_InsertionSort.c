#include <stdio.h>

void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int* A, int n){
    int key, j;
    // loop for passes
    for (int i = 0; i <= n - 1; i++)
    {
        key = A[i];
        j = i - 1;
        // loop for each pass
        while (j >= 0 && A[j] > key) // asce = A[j] > key for desc = A[j] < key
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = key;
    }
    
}

int main() 
{
    int arr[] = {11, 6, 19, 10, 2, 1};
    int n = 6;
    printArray(arr, n);
    insertionSort(arr, n);
    printArray(arr, n);

    return 0;
}