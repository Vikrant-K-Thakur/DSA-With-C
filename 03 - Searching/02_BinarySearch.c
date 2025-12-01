
#include <stdio.h>

int main()
{
    int arr[6];
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("Enter elements of array\n");
    for (int i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorted array: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    int value;
    printf("Enter the element to search: ");
    scanf("%d", &value);

    int low = 0, high = size - 1, mid;

    while (low <= high)
    {
        mid = (low + high) / 2;
        if (arr[mid] == value)
        {
            printf("Element found at index: %d\n", mid);
            return 0;
        }
        else if (arr[mid] < value)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return 0;
}
