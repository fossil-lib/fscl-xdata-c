/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/stack.h"
#include <stdio.h>
#include <stdlib.h>

// =======================
// CREATE and DELETE
// =======================

TriloStack* trilo_xdata_stack_create(enum DataType stack_type) {
    TriloStack* stack = (TriloStack*)malloc(sizeof(TriloStack));
    if (stack != NULL) {
        stack->top = NULL;
        stack->stack_type = stack_type;
    } // end if
    return stack;
} // end of func

void trilo_xdata_stack_destroy(TriloStack* stack) {
    if (stack != NULL) {
        while (stack->top != NULL) {
            TriloStackNode* temp = stack->top;
            stack->top = stack->top->next;
            free(temp);
        } // end while
        free(stack);
    } // end if
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================

TofuError trilo_xdata_stack_insert(TriloStack* stack, TriloTofu data) {
    if (stack == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloStackNode* newNode = (TriloStackNode*)malloc(sizeof(TriloStackNode));
    if (newNode == NULL) {
        return TRILO_XDATA_TYPE_WAS_BAD_MALLOC;
    } // end if

    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;

    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

TofuError trilo_xdata_stack_remove(TriloStack* stack, TriloTofu data) {
    if (stack == NULL || stack->top == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloStackNode* current = stack->top;
    TriloStackNode* prev = NULL;

    while (current != NULL) {
        if (trilo_xdata_tofu_compare(current->data, data) == 0) {
            if (prev != NULL) {
                prev->next = current->next;
            } else {
                stack->top = current->next;
            } // end if else
            free(current);
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if
        prev = current;
        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

TofuError trilo_xdata_stack_search(const TriloStack* stack, TriloTofu data) {
    if (stack == NULL || stack->top == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloStackNode* current = stack->top;

    while (current != NULL) {
        if (trilo_xdata_tofu_compare(current->data, data) == 0) {
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if
        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

// =======================
// UTILITY FUNCTIONS
// =======================

size_t trilo_xdata_stack_size(const TriloStack* stack) {
    if (stack == NULL) {
        return 0;
    } // end if

    size_t count = 0;
    TriloStackNode* current = stack->top;

    while (current != NULL) {
        count++;
        current = current->next;
    } // end while

    return count;
} // end of func

TriloTofu* trilo_xdata_stack_getter(TriloStack* stack, TriloTofu data) {
    if (stack == NULL || stack->top == NULL) {
        return NULL;
    } // end if

    TriloStackNode* current = stack->top;

    while (current != NULL) {
        if (trilo_xdata_tofu_compare(current->data, data) == 0) {
            return &(current->data);
        } // end if
        current = current->next;
    } // end while

    return NULL;
} // end of func

TofuError trilo_xdata_stack_setter(TriloStack* stack, TriloTofu data) {
    TriloTofu* existingData = trilo_xdata_stack_getter(stack, data);
    if (existingData != NULL) {
        *existingData = data;
        return TRILO_XDATA_TYPE_SUCCESS;
    } else {
        return TRILO_XDATA_TYPE_WAS_UNKNOWN;
    } // end if else
} // end of func

bool trilo_xdata_stack_not_empty(const TriloStack* stack) {
    return stack != NULL && stack->top != NULL;
} // end of func

bool trilo_xdata_stack_not_nullptr(const TriloStack* stack) {
    return stack != NULL;
} // end of func

bool trilo_xdata_stack_is_empty(const TriloStack* stack) {
    return stack == NULL || stack->top == NULL;
} // end of func

bool trilo_xdata_stack_is_nullptr(const TriloStack* stack) {
    return stack == NULL;
} // end of func

// This function returns a copy of the top element of the stack without removing it.
TriloTofu trilo_xdata_stack_top(TriloStack* stack) {
    TriloTofu empty_tofu; // Return an empty TriloTofu in case of errors

    if (stack == NULL || stack->top == NULL) {
        return empty_tofu; // Return an empty TriloTofu if the stack is empty or invalid
    } // end if

    // Copy the data from the top element
    return trilo_xdata_tofu_copy(stack->top->data);
} // end of func
