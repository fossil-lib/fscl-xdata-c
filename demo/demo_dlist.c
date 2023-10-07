
#include "trilobite/xdata/dlist.h"
#include <stdio.h>

int main() {
    // Create a doubly linked list
    TriloDoublyList* intDeque = trilo_xdata_dlist_create();

    // Add elements to the front and back of the deque
    trilo_xdata_dlist_push_front(intDeque, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_dlist_push_back(intDeque, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_dlist_push_front(intDeque, trilo_xdata_tofu_create_from_integer(5));
    trilo_xdata_dlist_push_back(intDeque, trilo_xdata_tofu_create_from_integer(30));

    // Print the deque from front to back
    printf("Deque contents (front to back): ");
    trilo_xdata_dlist_print(intDeque);
    printf("\n");

    // Remove elements from the front and back of the deque
    trilo_xdata_dlist_pop_front(intDeque);
    trilo_xdata_dlist_pop_back(intDeque);

    // Print the deque after removals
    printf("Deque contents after removals: ");
    trilo_xdata_dlist_print(intDeque);
    printf("\n");

    // Clean up and destroy the deque
    trilo_xdata_dlist_destroy(intDeque);

    return 0;
} // end of func
