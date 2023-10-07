
#include "trilobite/xdata/array.h"
#include <stdio.h>

int main() {
    // Create an array of integers with a maximum capacity of 5 elements
    TriloArray* intArray = trilo_xdata_array_create(INTEGER_TYPE, 5);

    // Insert elements into the array
    trilo_xdata_array_insert(intArray, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_array_insert(intArray, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_array_insert(intArray, trilo_xdata_tofu_create_from_integer(30));
    trilo_xdata_array_insert(intArray, trilo_xdata_tofu_create_from_integer(40));
    trilo_xdata_array_insert(intArray, trilo_xdata_tofu_create_from_integer(50));

    // Print the array
    printf("Array contents: ");
    trilo_xdata_array_print(intArray);
    printf("\n");

    // Retrieve and print elements by index
    for (int i = 0; i < trilo_xdata_array_size(intArray); i++) {
        TriloTofu element = trilo_xdata_array_get(intArray, i);
        printf("Element at index %d: %d\n", i, trilo_xdata_tofu_get_integer(element));
    }

    // Clean up and destroy the array
    trilo_xdata_array_destroy(intArray);

    return 0;
} // end of func
