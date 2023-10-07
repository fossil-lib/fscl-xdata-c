
#include "trilobite/xdata/tlist.h"
#include <stdio.h>

int main() {
    // Create a ternary linked list for integers
    TriloTernaryList* intTernaryList = trilo_xdata_tlist_create(INTEGER_TYPE);

    // Insert integer elements into the list
    trilo_xdata_tlist_insert(intTernaryList, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_tlist_insert(intTernaryList, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_tlist_insert(intTernaryList, trilo_xdata_tofu_create_from_integer(30));

    // Print the list
    printf("Ternary List contents:\n");
    trilo_xdata_tlist_print(intTernaryList);

    // Clean up and destroy the list
    trilo_xdata_tlist_destroy(intTernaryList);

    return 0;
} // end of func
