/*  ----------------------------------------------------------------------------
    File: stack.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include "trilobite/xdata/stack.h"
#include <stdio.h>
#include <stdlib.h>

// =======================
// CREATE and DELETE
// =======================

cstack* tscl_stack_create(ctofu_type stack_type) {
    cstack* new_stack = (cstack*)malloc(sizeof(cstack));
    if (new_stack == NULL) {
        return NULL; // Handle memory allocation failure
    }

    new_stack->stack_type = stack_type;
    new_stack->top = NULL;

    return new_stack;
}

void tscl_stack_erase(cstack* stack) {
    if (stack == NULL) {
        return;
    }

    while (tscl_stack_not_empty(stack)) {
        ctofu removedData;
        tscl_stack_remove(stack, &removedData);
    }

    free(stack);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error tscl_stack_insert(cstack* stack, ctofu data) {
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

ctofu_error tscl_stack_remove(cstack* stack, ctofu* data) {
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

ctofu_error tscl_stack_search(const cstack* stack, ctofu data) {
    if (stack == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cstack_node* current = stack->top;

    while (current != NULL) {
        if (tscl_tofu_compare(&current->data, &data, NULL) == 0) {
            return TOFU_SUCCESS; // Found
        }

        current = current->next;
    }

    return TOFU_NOT_FOUND; // Not found
}


// =======================
// UTILITY FUNCTIONS
// =======================
size_t tscl_stack_size(const cstack* stack) {
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

ctofu* tscl_stack_getter(cstack* stack, ctofu data) {
    if (stack == NULL) {
        return NULL;
    }

    cstack_node* current = stack->top;

    while (current != NULL) {
        if (tscl_tofu_compare(&current->data, &data, NULL) == 0) {
            return &current->data; // Found
        }

        current = current->next;
    }

    return NULL; // Not found
}

ctofu_error tscl_stack_setter(cstack* stack, ctofu data) {
    if (stack == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    cstack_node* current = stack->top;

    while (current != NULL) {
        if (tscl_tofu_compare(&current->data, &data, NULL) == 0) {
            // Found, update the data
            current->data = data;
            return TOFU_SUCCESS;
        }

        current = current->next;
    }

    return TOFU_NOT_FOUND; // Not found
}

bool tscl_stack_not_empty(const cstack* stack) {
    return stack != NULL && stack->top != NULL;
}

bool tscl_stack_not_cnullptr(const cstack* stack) {
    return stack != NULL;
}

bool tscl_stack_is_empty(const cstack* stack) {
    return stack == NULL || stack->top == NULL;
}

bool tscl_stack_is_cnullptr(const cstack* stack) {
    return stack == NULL;
}

ctofu tscl_stack_top(cstack* stack, ctofu default_value) {
    if (stack == NULL || stack->top == NULL) {
        return default_value; // Return default value if the stack is empty
    }

    return stack->top->data;
}
