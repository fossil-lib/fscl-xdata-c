/*  ----------------------------------------------------------------------------
    File: demo_stack.c

    Description:
    This demo file serves as a showcase of the Trilobite Stdlib in action. It provides
    example code snippets and usage scenarios to help users understand how to leverage
    the library's features and functions in their own projects.

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

int main() {
    // Create a TriloStack instance with INTEGER_TYPE
    TriloStack* stack = trilo_xdata_stack_create(INTEGER_TYPE);

    // Insert data elements into the TriloStack
    trilo_xdata_stack_insert(stack, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_stack_insert(stack, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_stack_insert(stack, trilo_xdata_tofu_create_from_integer(30));

    // Print the size of the TriloStack
    printf("Size of the stack: %zu\n", trilo_xdata_stack_size(stack));

    // Print the TriloStack
    printf("Stack elements:\n");
    for (size_t i = 0; i < trilo_xdata_stack_size(stack); i++) {
        TriloTofu* tofu = trilo_xdata_stack_getter(stack, i);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
    } // end for

    // Check if the TriloStack is not empty
    printf("Is stack not empty? %s\n", trilo_xdata_stack_not_empty(stack) ? "true" : "false");

    // Remove an element from the TriloStack
    TriloTofu* removedTofu = trilo_xdata_stack_getter(stack, 1);
    TofuError removalResult = trilo_xdata_stack_remove(stack, *removedTofu);
    printf("Removal result: %s\n", removalResult == TRILO_XDATA_TYPE_SUCCESS ? "success" : "failure");

    // Print the updated TriloStack
    printf("Updated stack elements:\n");
    for (size_t i = 0; i < trilo_xdata_stack_size(stack); i++) {
        TriloTofu* tofu = trilo_xdata_stack_getter(stack, i);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
    } // end for

    // Destroy the TriloStack
    trilo_xdata_stack_destroy(stack);

    return 0;
} // end of func
