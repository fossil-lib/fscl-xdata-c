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

cstack* stack_create(enum ctofu_type stack_type) {
    cstack* stack = (cstack*)malloc(sizeof(cstack));
    if (stack != NULL) {
        stack->top = NULL;
        stack->stack_type = stack_type;
    } // end if
    return stack;
} // end of func

void stack_erase(cstack* stack) {
    if (stack != NULL) {
        while (stack->top != NULL) {
            cstack_node* temp = stack->top;
            stack->top = stack->top->next;
            free(temp);
        } // end while
        free(stack);
    } // end if
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================

ctofu_error stack_insert(cstack* stack, ctofu data) {
    if (stack == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    cstack_node* newNode = (cstack_node*)malloc(sizeof(cstack_node));
    if (newNode == NULL) {
        return TRILO_XDATA_TYPE_WAS_BAD_MALLOC;
    } // end if

    newNode->data = data;
    newNode->next = stack->top;
    stack->top = newNode;

    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

ctofu_error stack_remove(cstack* stack, ctofu data) {
    if (stack == NULL || stack->top == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    cstack_node* current = stack->top;
    cstack_node* prev = NULL;

    while (current != NULL) {
        if (tofu_compare(current->data, data) == 0) {
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

ctofu_error stack_search(const cstack* stack, ctofu data) {
    if (stack == NULL || stack->top == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    cstack_node* current = stack->top;

    while (current != NULL) {
        if (tofu_compare(current->data, data) == 0) {
            return TRILO_XDATA_TYPE_SUCCESS;
        } // end if
        current = current->next;
    } // end while

    return TRILO_XDATA_TYPE_SUCCESS;
} // end of func

// =======================
// UTILITY FUNCTIONS
// =======================

size_t stack_size(const cstack* stack) {
    if (stack == NULL) {
        return 0;
    } // end if

    size_t count = 0;
    cstack_node* current = stack->top;

    while (current != NULL) {
        count++;
        current = current->next;
    } // end while

    return count;
} // end of func

ctofu* stack_getter(cstack* stack, ctofu data) {
    if (stack == NULL || stack->top == NULL) {
        return NULL;
    } // end if

    cstack_node* current = stack->top;

    while (current != NULL) {
        if (tofu_compare(current->data, data) == 0) {
            return &(current->data);
        } // end if
        current = current->next;
    } // end while

    return NULL;
} // end of func

ctofu_error stack_setter(cstack* stack, ctofu data) {
    ctofu* existingData = stack_getter(stack, data);
    if (existingData != NULL) {
        *existingData = data;
        return TRILO_XDATA_TYPE_SUCCESS;
    } else {
        return TRILO_XDATA_TYPE_WAS_UNKNOWN;
    } // end if else
} // end of func

bool stack_not_empty(const cstack* stack) {
    return stack != NULL && stack->top != NULL;
} // end of func

bool stack_not_cnullptr(const cstack* stack) {
    return stack != NULL;
} // end of func

bool stack_is_empty(const cstack* stack) {
    return stack == NULL || stack->top == NULL;
} // end of func

bool stack_is_cnullptr(const cstack* stack) {
    return stack == NULL;
} // end of func

// This function returns a copy of the top element of the stack without removing it.
ctofu stack_top(cstack* stack) {
    if (stack == NULL || stack->top == NULL) {
        ctofu empty_tofu;
        empty_tofu.type = UNKNOWN_TYPE; // Set the data type to indicate an error
        return empty_tofu; // Return an empty ctofu if the stack is empty or invalid
    } // end if

    // Return the top element's data
    return stack->top->data;
} // end of func
