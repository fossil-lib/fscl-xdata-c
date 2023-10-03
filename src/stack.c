/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/stack.h"
#include <stdio.h>
#include <stdlib.h>

TriloStack* trilo_xdata_stack_create(enum DataType stack_type) {
    TriloStack* stack = (TriloStack*)malloc(sizeof(TriloStack));
    if (stack == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    stack->stack_type = stack_type;
    stack->top = NULL;
    return stack;
} // end of func

void trilo_xdata_stack_destroy(TriloStack* stack) {
    if (stack == NULL) {
        return;
    } // end if

    while (!trilo_xdata_stack_is_empty(stack)) {
        trilo_xdata_stack_pop(stack);
    } // end while

    free(stack);
} // end of func

void trilo_xdata_stack_push(TriloStack* stack, TriloTofu data) {
    if (data.type != stack->stack_type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloStackNode* newNode = (TriloStackNode*)malloc(sizeof(TriloStackNode));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;
} // end of func

TriloTofu trilo_xdata_stack_pop(TriloStack* stack) {
    if (trilo_xdata_stack_is_empty(stack)) {
        fprintf(stderr, "Stack underflow!\n");
        exit(EXIT_FAILURE);
    } // end if

    TriloStackNode* topNode = stack->top;
    TriloTofu data = topNode->data;
    stack->top = topNode->next;
    free(topNode);
    return data;
} // end of func

TriloTofu trilo_xdata_stack_peek(const TriloStack* stack) {
    if (trilo_xdata_stack_is_empty(stack)) {
        fprintf(stderr, "Stack is empty!\n");
        exit(EXIT_FAILURE);
    } // end if

    return stack->top->data;
} // end of func

bool trilo_xdata_stack_is_empty(const TriloStack* stack) {
    return stack->top == NULL;
} // end of func

size_t trilo_xdata_stack_size(const TriloStack* stack) {
    size_t size = 0;
    TriloStackNode* current = stack->top;
    while (current != NULL) {
        size++;
        current = current->next;
    } // end while
    return size;
} // end of func