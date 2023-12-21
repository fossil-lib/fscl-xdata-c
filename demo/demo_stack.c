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
    // Create a stack for integers
    cstack* int_stack = stack_create(INTEGER_TYPE);

    // Push integers onto the stack using a for loop
    for (int i = 1; i <= 5; ++i) {
        ctofu data;
        tofu_create(INTEGER_TYPE, &(ctofu_data){.data.integer_type = i * 10}, &data);
        stack_insert(int_stack, data);
    }

    // Print the size of the stack
    printf("Stack size: %zu\n", stack_size(int_stack));

    // Print the elements of the stack using a for loop
    printf("Stack elements:\n");
    for (size_t i = 0; i < stack_size(int_stack); ++i) {
        ctofu current = stack_top(int_stack, (ctofu){.type = INVALID_TYPE});
        printf("Element %zu: %d\n", i, current.data.integer_type);
        stack_remove(int_stack, NULL);  // Remove the top element
    }

    // Check if the stack is empty
    if (stack_is_empty(int_stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack is not empty.\n");
    }

    // Clean up the memory
    stack_erase(int_stack);

    return 0;
} // end of func
