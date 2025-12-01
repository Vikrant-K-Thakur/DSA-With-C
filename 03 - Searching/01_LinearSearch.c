
#include <stdio.h>
int main() 
{
    int arr[6];
    printf("Enter elements of array\n");
    for (int i = 0; i < 6; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
 
    int value;
    printf("Enter the element to search: ");
    scanf("%d", &value);

    for (int i = 0; i < 6; i++)
    {
        if (arr[i] == value)
        {
            printf("Element found at index: %d\n", i);
            break;
        }
        if (i == 5)
        {
            printf("Element not found in the array.\n");
        }
    }

    return 0;
}

