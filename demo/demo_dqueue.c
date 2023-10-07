
#include "trilobite/xdata/dqueue.h"
#include <stdio.h>

int main() {
    // Create a new TriloDQueue of integer type
    TriloDQueue* intDeque = trilo_xdata_dqueue_create(INTEGER_TYPE);

    // Check if the deque is empty
    if (trilo_xdata_dqueue_is_empty(intDeque)) {
        printf("Deque is empty.\n");
    } else {
        printf("Deque is not empty.\n");
    }

    // Insert elements at the front and rear of the deque
    trilo_xdata_dqueue_push_front(intDeque, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_dqueue_push_rear(intDeque, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_dqueue_push_front(intDeque, trilo_xdata_tofu_create_from_integer(5));
    trilo_xdata_dqueue_push_rear(intDeque, trilo_xdata_tofu_create_from_integer(30));

    // Print the contents of the deque forward and backward
    printf("Deque contents (forward): ");
    trilo_xdata_dqueue_print_forward(intDeque);
    printf("\n");

    printf("Deque contents (backward): ");
    trilo_xdata_dqueue_print_backward(intDeque);
    printf("\n");

    // Remove elements from the front and rear of the deque
    trilo_xdata_dqueue_pop_front(intDeque);
    trilo_xdata_dqueue_pop_rear(intDeque);

    // Print the deque after removals
    printf("Deque contents after removals (forward): ");
    trilo_xdata_dqueue_print_forward(intDeque);
    printf("\n");

    printf("Deque contents after removals (backward): ");
    trilo_xdata_dqueue_print_backward(intDeque);
    printf("\n");

    // Get the front and rear elements of the deque
    TriloTofu frontData = trilo_xdata_dqueue_front(intDeque);
    TriloTofu rearData = trilo_xdata_dqueue_rear(intDeque);
    printf("Front data: %d\n", trilo_xdata_tofu_get_integer(frontData));
    printf("Rear data: %d\n", trilo_xdata_tofu_get_integer(rearData));

    // Clean up and destroy the deque
    trilo_xdata_dqueue_destroy(intDeque);

    return 0;
} // end of func

