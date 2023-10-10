
#include "trilobite/xdata/pqueue.h"
#include <stdio.h>

int main() {
    // Create a TriloPQueue instance with INTEGER_TYPE
    TriloPQueue* pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);

    // Insert data elements into the TriloPQueue with priorities
    trilo_xdata_pqueue_insert(pqueue, trilo_xdata_tofu_create_from_integer(10), 3);
    trilo_xdata_pqueue_insert(pqueue, trilo_xdata_tofu_create_from_integer(20), 1);
    trilo_xdata_pqueue_insert(pqueue, trilo_xdata_tofu_create_from_integer(30), 2);

    // Print the size of the TriloPQueue
    printf("Size of the priority queue: %zu\n", trilo_xdata_pqueue_size(pqueue));

    // Print the TriloPQueue elements
    printf("Priority queue elements:\n");
    for (int i = 1; i <= trilo_xdata_pqueue_size(pqueue); i++) {
        TriloTofu* tofu = trilo_xdata_pqueue_getter(pqueue, i, &i);
        printf("Priority %d: %d\n", i, trilo_xdata_tofu_get_integer(*tofu));
    } // end for

    // Check if the TriloPQueue is not empty
    printf("Is priority queue not empty? %s\n", trilo_xdata_pqueue_not_empty(pqueue) ? "true" : "false");

    // Remove an element from the TriloPQueue
    TriloTofu* removedTofu = trilo_xdata_pqueue_getter(pqueue, 2, NULL);
    TofuError removalResult = trilo_xdata_pqueue_remove(pqueue, *removedTofu, 2);
    printf("Removal result: %s\n", removalResult == TRILO_XDATA_TYPE_SUCCESS ? "success" : "failure");

    // Print the updated TriloPQueue
    printf("Updated priority queue elements:\n");
    for (int i = 1; i <= trilo_xdata_pqueue_size(pqueue); i++) {
        TriloTofu* tofu = trilo_xdata_pqueue_getter(pqueue, i, &i);
        printf("Priority %d: %d\n", i, trilo_xdata_tofu_get_integer(*tofu));
    } // end for

    // Check if the TriloPQueue is not empty
    printf("Is priority queue not empty? %s\n", trilo_xdata_pqueue_not_empty(pqueue) ? "true" : "false");

    // Destroy the TriloPQueue
    trilo_xdata_pqueue_destroy(pqueue);

    return 0;
} // end of func
