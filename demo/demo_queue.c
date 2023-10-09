
#include "trilobite/xdata/queue.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Create a TriloQueue instance with INTEGER_TYPE
    TriloQueue* queue = trilo_xdata_queue_create(INTEGER_TYPE);

    // Insert data elements into the TriloQueue
    trilo_xdata_queue_insert(queue, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_queue_insert(queue, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_queue_insert(queue, trilo_xdata_tofu_create_from_integer(30));

    // Print the size of the TriloQueue
    printf("Size of the queue: %zu\n", trilo_xdata_queue_size(queue));

    // Print the TriloQueue elements
    printf("Queue elements:\n");
    for (size_t i = 0; i < trilo_xdata_queue_size(queue); i++) {
        TriloTofu* tofu = trilo_xdata_queue_getter(queue, i);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
    } // end for

    // Check if the TriloQueue is not empty
    printf("Is queue not empty? %s\n", trilo_xdata_queue_not_empty(queue) ? "true" : "false");

    // Remove an element from the TriloQueue
    TriloTofu* removedTofu = trilo_xdata_queue_getter(queue, 1);
    TofuError removalResult = trilo_xdata_queue_remove(queue, *removedTofu);
    printf("Removal result: %s\n", removalResult == TRILO_XDATA_TYPE_SUCCESS ? "success" : "failure");

    // Print the updated TriloQueue
    printf("Updated queue elements:\n");
    for (size_t i = 0; i < trilo_xdata_queue_size(queue); i++) {
        TriloTofu* tofu = trilo_xdata_queue_getter(queue, i);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
    } // end for

    // Check if the TriloQueue is not empty
    printf("Is queue not empty? %s\n", trilo_xdata_queue_not_empty(queue) ? "true" : "false");

    // Destroy the TriloQueue
    trilo_xdata_queue_destroy(queue);

    return 0;
} // end of func
