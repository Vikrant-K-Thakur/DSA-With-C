#include <stdio.h>

int main() 
{
    // Declaring an array of integers

    // direct initialization
    // int arr1[] = {1, 2, 3, 4, 5};
    // int arr2[6]  = {6, 7, 8, 9, 10, 11};
    // int arr_size = sizeof(arr1) / sizeof(arr1[0]);
    //
    // // Printing the elements of the array
    // for (int i = 0; i < arr_size; i++) {
    //     printf("%d ", arr1[i]);
    // }
    // printf("\n");

    // taking input from the user
    int arr3[6];
    printf("Enter 6 integers: ");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &arr3[i]);
    }

    // Printing the elements of the user input array
    printf("You entered: ");
    for (int i = 0; i < 6; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");

    
    // Operating on arrays insert, delete.

    // insert ( on arr3 )
    // int insert_index, insert_value;
    // printf("Enter index to insert (0-5) and value: ");
    // scanf("%d %d", &insert_index, &insert_value);
    // if (insert_index >= 0 && insert_index < 6) {
    //     for (int i = 5; i > insert_index; i--) {
    //         arr3[i] = arr3[i - 1];
    //     }
    //     arr3[insert_index] = insert_value;
    // } else {
    //     printf("Invalid index!\n");
    // }
    //
    // // Printing the array after insertion
    // printf("Array after insertion: ");
    // for (int i = 0; i < 7; i++) {
    //     printf("%d ", arr3[i]);
    // }
    // printf("\n");

    // delete ( on arr3 )
    // int delete_index;
    // printf("Enter index: ");
    // scanf("%d",&delete_index);
    //
    // if (delete_index >= 0 && delete_index < 6) {
    //     for (int i = delete_index; i < 6 - 1; i++) {
    //         arr3[i] = arr3[i+1];
    //     }
    // } else {
    //     printf("Invalid index!\n");
    // }
    // // after deleting the element printing the array.
    // for (int i = 0; i < 5; i++)
    // {
    //     printf("%d ",arr3[i]);
    // }
    // printf("\n");

    return 0;
}