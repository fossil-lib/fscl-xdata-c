
#include "trilobite/xdata/stack.h"
#include <stdio.h>

int main() {
    // Create a stack of integers
    TriloStack* intStack = trilo_xdata_stack_create(INTEGER_TYPE);

    // Push some integers onto the stack
    for (int i = 1; i <= 5; i++) {
        TriloTofu data = trilo_xdata_tofu_create_from_integer(i * 10);
        trilo_xdata_stack_push(intStack, data);
    }

    // Check if the stack is empty
    if (trilo_xdata_stack_is_empty(intStack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }

    // Pop elements from the stack and print them
    printf("Popped elements: ");
    while (!trilo_xdata_stack_is_empty(intStack)) {
        TriloTofu data = trilo_xdata_stack_pop(intStack);
        int value = trilo_xdata_tofu_get_integer(data);
        printf("%d ", value);
    }
    printf("\n");

    // Check if the stack is empty after popping
    if (trilo_xdata_stack_is_empty(intStack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }

    // Clean up and destroy the stack
    trilo_xdata_stack_destroy(intStack);

    return 0;
} // end of func
