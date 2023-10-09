
#include "trilobite/xdata/flist.h"
#include <stdio.h>

int main() {
    // Create a TriloForwardList instance with INTEGER_TYPE
    TriloForwardList* flist = trilo_xdata_flist_create(INTEGER_TYPE);

    // Insert data elements into the TriloForwardList
    trilo_xdata_flist_insert(flist, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_flist_insert(flist, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_flist_insert(flist, trilo_xdata_tofu_create_from_integer(30));

    // Print the size of the TriloForwardList
    printf("Size of the forward list: %zu\n", trilo_xdata_flist_size(flist));

    // Print the TriloForwardList elements
    printf("Forward list elements:\n");
    TriloForwardListNode* current = trilo_xdata_flist_get_head(flist);
    while (current != NULL) {
        TriloTofu* tofu = trilo_xdata_flist_get_node_data(current);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
        current = trilo_xdata_flist_get_next(current);
    } // end while

    // Check if the TriloForwardList is not empty
    printf("Is forward list not empty? %s\n", trilo_xdata_flist_not_empty(flist) ? "true" : "false");

    // Reverse the TriloForwardList in the forward direction
    trilo_xdata_flist_reverse_forward(flist);

    // Print the reversed TriloForwardList elements
    printf("Reversed forward list elements:\n");
    current = trilo_xdata_flist_get_head(flist);
    while (current != NULL) {
        TriloTofu* tofu = trilo_xdata_flist_get_node_data(current);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
        current = trilo_xdata_flist_get_next(current);
    } // end while

    // Check if the TriloForwardList is not empty
    printf("Is forward list not empty? %s\n", trilo_xdata_flist_not_empty(flist) ? "true" : "false");

    // Destroy the TriloForwardList
    trilo_xdata_flist_destroy(flist);

    return 0;
} // end of func
