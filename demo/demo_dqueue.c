/*  ----------------------------------------------------------------------------
    File: demo_dqueue.c

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
#include "trilobite/xdata/dqueue.h"
#include <stdio.h>

int main() {
    // Create a doubly-ended queue for integers
    cdqueue* int_dqueue = dqueue_create(INTEGER_TYPE);

    // Insert integers into the front of the deque
    for (int i = 1; i <= 5; ++i) {
        ctofu data;
        tofu_create(INTEGER_TYPE, &(ctofu_data){.data.integer_type = i}, &data);
        dqueue_insert(int_dqueue, data);
    }

    // Print the size of the deque
    printf("Deque size: %zu\n", dqueue_size(int_dqueue));

    // Print the elements of the deque using a for loop
    printf("Deque elements:\n");
    for (size_t i = 0; i < dqueue_size(int_dqueue); ++i) {
        ctofu current = *dqueue_getter(int_dqueue, (ctofu){.type = INTEGER_TYPE, .data.integer_type = i + 1});
        printf("%d ", current.data.integer_type);
    }
    printf("\n");

    // Remove an element from the front of the deque
    ctofu removed_element;
    dqueue_remove(int_dqueue, &removed_element);

    // Print the updated size and elements of the deque
    printf("Updated Deque size: %zu\n", dqueue_size(int_dqueue));
    printf("Updated Deque elements:\n");
    for (size_t i = 0; i < dqueue_size(int_dqueue); ++i) {
        ctofu current = *dqueue_getter(int_dqueue, (ctofu){.type = INTEGER_TYPE, .data.integer_type = i + 1});
        printf("%d ", current.data.integer_type);
    }
    printf("\n");

    // Check if the deque is not empty
    if (dqueue_not_empty(int_dqueue)) {
        printf("Deque is not empty.\n");
    } else {
        printf("Deque is empty.\n");
    }

    // Clean up the memory
    dqueue_erase(int_dqueue);

    return 0;
} // end of func
