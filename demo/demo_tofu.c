
#include "trilobite/xdata/tofu.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Create TriloTofu instances from different data types
    TriloTofu intTofu = trilo_xdata_tofu_create_from_integer(42);
    TriloTofu doubleTofu = trilo_xdata_tofu_create_from_double(3.14159);
    TriloTofu stringTofu = trilo_xdata_tofu_create_from_string("Hello, World!");
    TriloTofu charTofu = trilo_xdata_tofu_create_from_char('A');
    TriloTofu boolTofu = trilo_xdata_tofu_create_from_boolean(true);

    // Print the data stored in each TriloTofu instance
    printf("Integer Value: %d\n", trilo_xdata_tofu_get_integer(intTofu));
    printf("Double Value: %lf\n", trilo_xdata_tofu_get_double(doubleTofu));
    printf("String Value: %s\n", trilo_xdata_tofu_get_string(stringTofu));
    printf("Character Value: %c\n", trilo_xdata_tofu_get_char(charTofu));
    printf("Boolean Value: %s\n", trilo_xdata_tofu_get_boolean(boolTofu) ? "true" : "false");

    // Create an array of TriloTofu instances and perform sorting and searching
    TriloTofu arr[] = {intTofu, doubleTofu, stringTofu, charTofu, boolTofu};
    size_t arrSize = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using insertion sort
    trilo_xdata_tofu_insertion_sort(arr, arrSize);

    // Print the sorted array
    printf("\nSorted Array:\n");
    for (size_t i = 0; i < arrSize; i++) {
        trilo_xdata_tofu_print(arr[i]);
    } // end for

    // Perform a binary search for a specific TriloTofu instance
    TriloTofu targetTofu = trilo_xdata_tofu_create_from_double(3.14159);
    int result = trilo_xdata_tofu_binary_search(arr, arrSize, targetTofu);
    if (result != -1) {
        printf("\nTarget Value Found at Index: %d\n", result);
    } else {
        printf("\nTarget Value Not Found\n");
    } // end if else

    return 0;
} // end of func
