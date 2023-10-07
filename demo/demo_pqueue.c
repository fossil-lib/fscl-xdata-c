
#include "trilobite/xdata/pqueue.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Create a priority queue of integers
    TriloPQueue* intPQueue = trilo_xdata_pqueue_create(INTEGER_TYPE);

    // Enqueue integers with priorities into the priority queue
    trilo_xdata_pqueue_enqueue(intPQueue, trilo_xdata_tofu_create_from_integer(10), 3);  // Priority: 3
    trilo_xdata_pqueue_enqueue(intPQueue, trilo_xdata_tofu_create_from_integer(20), 1);  // Priority: 1
    trilo_xdata_pqueue_enqueue(intPQueue, trilo_xdata_tofu_create_from_integer(30), 2);  // Priority: 2

    // Check if the priority queue is empty
    if (trilo_xdata_pqueue_is_empty(intPQueue)) {
        printf("Priority queue is empty.\n");
    } else {
        printf("Priority queue is not empty.\n");
    }

    // Dequeue elements from the priority queue based on their priorities
    printf("Dequeued elements by priority: ");
    while (!trilo_xdata_pqueue_is_empty(intPQueue)) {
        TriloTofu data = trilo_xdata_pqueue_dequeue(intPQueue);
        int value = trilo_xdata_tofu_get_integer(data);
        printf("%d ", value);
    }
    printf("\n");

    // Check if the priority queue is empty again after dequeuing
    if (trilo_xdata_pqueue_is_empty(intPQueue)) {
        printf("Priority queue is empty.\n");
    } else {
        printf("Priority queue is not empty.\n");
    }

    // Clean up and destroy the priority queue
    trilo_xdata_pqueue_destroy(intPQueue);

    return 0;
} // end of func
