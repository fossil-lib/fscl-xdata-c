
#include "trilobite/xdata/set.h"
#include <stdio.h>

int main() {
    // Create a set of integers
    TriloSet* intSet = trilo_xdata_set_create(INTEGER_TYPE);

    // Insert some integers into the set
    trilo_xdata_set_insert(intSet, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_set_insert(intSet, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_set_insert(intSet, trilo_xdata_tofu_create_from_integer(30));

    // Check if values exist in the set
    int searchValue = 20;
    if (trilo_xdata_set_contains(intSet, trilo_xdata_tofu_create_from_integer(searchValue))) {
        printf("%d exists in the set.\n", searchValue);
    } else {
        printf("%d does not exist in the set.\n", searchValue);
    }

    // Remove a value from the set
    trilo_xdata_set_remove(intSet, trilo_xdata_tofu_create_from_integer(20));

    // Check if the removed value still exists
    if (trilo_xdata_set_contains(intSet, trilo_xdata_tofu_create_from_integer(20))) {
        printf("%d exists in the set.\n", searchValue);
    } else {
        printf("%d does not exist in the set.\n", searchValue);
    }

    // Clean up and destroy the set
    trilo_xdata_set_destroy(intSet);

    return 0;
} // end of func
