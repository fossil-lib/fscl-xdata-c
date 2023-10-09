
#include "trilobite/xdata/set.h"
#include <stdio.h>

int main() {
    // Create a TriloSet instance with INTEGER_TYPE
    TriloSet* set = trilo_xdata_set_create(INTEGER_TYPE);

    // Insert data elements into the TriloSet
    trilo_xdata_set_insert(set, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_set_insert(set, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_set_insert(set, trilo_xdata_tofu_create_from_integer(30));

    // Print the size of the TriloSet
    printf("Size of the set: %zu\n", trilo_xdata_set_size(set));

    // Print the TriloSet
    printf("Set elements:\n");
    for (size_t i = 0; i < trilo_xdata_set_size(set); i++) {
        TriloTofu* tofu = trilo_xdata_set_getter(set, i);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
    } // end for

    // Check if the TriloSet is not empty
    printf("Is set not empty? %s\n", trilo_xdata_set_not_empty(set) ? "true" : "false");

    // Remove an element from the TriloSet
    TriloTofu* removedTofu = trilo_xdata_set_getter(set, 1);
    TofuError removalResult = trilo_xdata_set_remove(set, *removedTofu);
    printf("Removal result: %s\n", removalResult == TRILO_XDATA_TYPE_SUCCESS ? "success" : "failure");

    // Print the updated TriloSet
    printf("Updated set elements:\n");
    for (size_t i = 0; i < trilo_xdata_set_size(set); i++) {
        TriloTofu* tofu = trilo_xdata_set_getter(set, i);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
    } // end for

    // Check if the TriloSet contains a specific element
    TriloTofu targetTofu = trilo_xdata_tofu_create_from_integer(30);
    printf("Does the set contain the element %d? %s\n", trilo_xdata_tofu_get_integer(targetTofu),
           trilo_xdata_set_contains(set, targetTofu) ? "true" : "false");

    // Destroy the TriloSet
    trilo_xdata_set_destroy(set);

    return 0;
} // end of func
