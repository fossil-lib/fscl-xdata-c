
#include "trilobite/xdata/dlist.h"
#include <stdio.h>

int main() {
    // Create a TriloDoublyList instance with INTEGER_TYPE
    TriloDoublyList* dlist = trilo_xdata_dlist_create(INTEGER_TYPE);

    // Insert data elements into the TriloDoublyList
    trilo_xdata_dlist_insert(dlist, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_dlist_insert(dlist, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_dlist_insert(dlist, trilo_xdata_tofu_create_from_integer(30));

    // Print the size of the TriloDoublyList
    printf("Size of the doubly list: %zu\n", trilo_xdata_dlist_size(dlist));

    // Print the TriloDoublyList elements in forward order
    printf("Doubly list elements in forward order:\n");
    TriloDoublyListNode* current = trilo_xdata_dlist_get_head(dlist);
    while (current != NULL) {
        TriloTofu* tofu = trilo_xdata_dlist_get_node_data(current);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
        current = trilo_xdata_dlist_get_next(current);
    } // end while

    // Reverse the TriloDoublyList in the forward direction
    trilo_xdata_dlist_reverse_forward(dlist);

    // Print the reversed TriloDoublyList elements
    printf("Reversed doubly list elements in forward order:\n");
    current = trilo_xdata_dlist_get_head(dlist);
    while (current != NULL) {
        TriloTofu* tofu = trilo_xdata_dlist_get_node_data(current);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
        current = trilo_xdata_dlist_get_next(current);
    } // end while

    // Check if the TriloDoublyList is not empty
    printf("Is doubly list not empty? %s\n", trilo_xdata_dlist_not_empty(dlist) ? "true" : "false");

    // Destroy the TriloDoublyList
    trilo_xdata_dlist_destroy(dlist);

    return 0;
} // end of func
