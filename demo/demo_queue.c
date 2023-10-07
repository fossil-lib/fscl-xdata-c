
#include "trilobite/xdata/queue.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Create a queue of integers
    TriloQueue* intQueue = trilo_xdata_queue_create(INTEGER_TYPE);

    // Enqueue some integers into the queue
    trilo_xdata_queue_enqueue(intQueue, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_queue_enqueue(intQueue, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_queue_enqueue(intQueue, trilo_xdata_tofu_create_from_integer(30));

    // Check if the queue is empty
    if (trilo_xdata_queue_is_empty(intQueue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    // Dequeue elements from the queue and print them
    printf("Dequeued elements: ");
    while (!trilo_xdata_queue_is_empty(intQueue)) {
        TriloTofu data = trilo_xdata_queue_dequeue(intQueue);
        int value = trilo_xdata_tofu_get_integer(data);
        printf("%d ", value);
    }
    printf("\n");

    // Check if the queue is empty again after dequeuing
    if (trilo_xdata_queue_is_empty(intQueue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    // Clean up and destroy the queue
    trilo_xdata_queue_destroy(intQueue);

    return 0;
} // end of func
