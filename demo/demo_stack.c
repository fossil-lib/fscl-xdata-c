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
    cstack* int_stack = tscl_stack_create(INTEGER_TYPE);

    // Push elements onto the stack
    tscl_stack_insert(int_stack, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 10});
    tscl_stack_insert(int_stack, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 20});
    tscl_stack_insert(int_stack, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 30});

    // Display stack size
    printf("Stack Size: %zu\n", tscl_stack_size(int_stack));

    // Display and remove the top element from the stack
    ctofu top_element;
    if (tscl_stack_remove(int_stack, &top_element) == TOFU_SUCCESS) {
        printf("Top Element: %d\n", top_element.data.integer_type);
    }

    // Check if the stack is not empty
    if (tscl_stack_not_empty(int_stack)) {
        printf("The stack is not empty.\n");
    }

    // Clean up
    tscl_stack_erase(int_stack);

    return 0;
}
