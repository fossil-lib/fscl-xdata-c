
#include "trilobite/xdata/dqueue.h"
#include <stdio.h>

int main() {
    // Create a TriloDQueue instance with INTEGER_TYPE
    TriloDQueue* dqueue = trilo_xdata_dqueue_create(INTEGER_TYPE);

    // Insert data elements into the TriloDQueue
    trilo_xdata_dqueue_insert(dqueue, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_dqueue_insert(dqueue, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_dqueue_insert(dqueue, trilo_xdata_tofu_create_from_integer(30));

    // Print the size of the TriloDQueue
    printf("Size of the double-ended queue: %zu\n", trilo_xdata_dqueue_size(dqueue));

    // Print the TriloDQueue elements
    printf("Double-ended queue elements:\n");
    while (!trilo_xdata_dqueue_is_empty(dqueue)) {
        TriloTofu* tofu = trilo_xdata_dqueue_get_front(dqueue);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
        trilo_xdata_dqueue_remove_front(dqueue);
    } // end while

    // Check if the TriloDQueue is not empty
    printf("Is double-ended queue not empty? %s\n", trilo_xdata_dqueue_not_empty(dqueue) ? "true" : "false");

    // Destroy the TriloDQueue
    trilo_xdata_dqueue_destroy(dqueue);

    return 0;
} // end of func
