/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/xdata/stack.h"
#include <stdio.h>
#include <stdlib.h>

// =======================
// CREATE and DELETE
// =======================

cstack* fscl_stack_create(ctofu_type stack_type) {
    cstack* new_stack = (cstack*)malloc(sizeof(cstack));
    if (new_stack == NULL) {
        return NULL; // Handle memory allocation failure
    }

    new_stack->stack_type = stack_type;
    new_stack->top = NULL;

    return new_stack;
}

void fscl_stack_erase(cstack* stack) {
    if (stack == NULL) {
        return;
    }

    while (fscl_stack_not_empty(stack)) {
        ctofu removedData;
        fscl_stack_remove(stack, &removedData);
    }

    free(stack);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_stack_insert(cstack* stack, ctofu data) {
    if (stack == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cstack_node* new_node = (cstack_node*)malloc(sizeof(cstack_node));
    if (new_node == NULL) {
        // Handle memory allocation failure
        return TOFU_WAS_BAD_MALLOC;
    }

    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;

    return TOFU_SUCCESS;
}

ctofu_error fscl_stack_remove(cstack* stack, ctofu* data) {
    if (stack == NULL || data == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    if (stack->top == NULL) {
        return TOFU_NOT_FOUND; // Stack is empty
    }

    cstack_node* temp = stack->top;
    stack->top = stack->top->next;

    *data = temp->data;
    free(temp);

    return TOFU_SUCCESS;
}

ctofu_error fscl_stack_search(const cstack* stack, ctofu data) {
    if (stack == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cstack_node* current = stack->top;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0) {
            return TOFU_SUCCESS; // Found
        }

        current = current->next;
    }

    return TOFU_NOT_FOUND; // Not found
}


// =======================
// UTILITY FUNCTIONS
// =======================
size_t fscl_stack_size(const cstack* stack) {
    if (stack == NULL) {
        return 0;
    }

    size_t size = 0;
    cstack_node* current = stack->top;

    while (current != NULL) {
        ++size;
        current = current->next;
    }

    return size;
}

ctofu* fscl_stack_getter(cstack* stack, ctofu data) {
    if (stack == NULL) {
        return NULL;
    }

    cstack_node* current = stack->top;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return NULL; // Not found
}

ctofu_error fscl_stack_setter(cstack* stack, ctofu data) {
    if (stack == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cstack_node* current = stack->top;

    while (current != NULL) {
        if (fscl_tofu_compare(&current->data, &data, NULL) == 0) {
            // Found, update the data
            current->data = data;
            return TOFU_SUCCESS;
        }

        current = current->next;
    }

    return TOFU_NOT_FOUND; // Not found
}

bool fscl_stack_not_empty(const cstack* stack) {
    return stack != NULL && stack->top != NULL;
}

bool fscl_stack_not_cnullptr(const cstack* stack) {
    return stack != NULL;
}

bool fscl_stack_is_empty(const cstack* stack) {
    return stack == NULL || stack->top == NULL;
}

bool fscl_stack_is_cnullptr(const cstack* stack) {
    return stack == NULL;
}

ctofu fscl_stack_top(cstack* stack, ctofu default_value) {
    if (stack == NULL || stack->top == NULL) {
        return default_value; // Return default value if the stack is empty
    }

    return stack->top->data;
}
