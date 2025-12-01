
#include <stdio.h>
#define min(a, b) ((a) < (b) ? (a) : (b))

int fibonacciSearch(int arr[], int n, int tar)
{
    int offset = -1;
    int fib1 = 1, fib2 = 0;
    int fib = fib1 + fib2;
    while (fib < n)
    {
        fib2 = fib1;
        fib1 = fib;
        fib = fib1 + fib2;
    }

    while (fib > 1)
    {
        int i = min(offset + fib2, n - 1);
        if (arr[i] < tar)
        {
            fib = fib1;
            fib1 = fib2;
            fib2 = fib - fib1;
            offset = i;
        }    
        else if (arr[i] > tar)
        {
            fib = fib2;
            fib1 = fib1 - fib2;
            fib2 = fib - fib1;
        }
        else
        {
            return i;
        }
    }
    if (fib1 && arr[offset + 1] == tar)
    {
        return offset + 1;
    }
    return -1;
}

int main()
{
    int arr[100];
    int n;
    int tar;
    printf("Fibonacci Search\n");
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter the array: \n");
    for (int i = 0; i < n; i++)
    {
        printf("Enter the %d element: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the target element: ");
    scanf("%d", &tar);

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
    printf("Sorted array (Bubble Sort): ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int index = fibonacciSearch(arr, n, tar);
    if (index >= 0)
    {
        printf("Found at index: %d", index);
    }
    else
    {
        printf("Not Found");
    }
}
