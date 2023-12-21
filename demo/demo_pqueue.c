/*  ----------------------------------------------------------------------------
    File: demo_pqueue.c

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
#include "trilobite/xdata/pqueue.h"
#include <stdio.h>

int main() {
    // Create a priority queue for integers
    cpqueue* int_pqueue = pqueue_create(INTEGER_TYPE);

    // Insert integers with priorities into the priority queue using a for loop
    for (int i = 1; i <= 3; ++i) {
        ctofu data;
        tofu_create(INTEGER_TYPE, &(ctofu_data){.integer_type = i * 10}, &data);
        pqueue_insert(int_pqueue, data, i);  // Priority: i
    }

    // Print the size of the priority queue
    printf("Priority Queue size: %zu\n", pqueue_size(int_pqueue));

    // Print the elements of the priority queue using a for loop
    printf("Priority Queue elements:\n");
    for (size_t i = 0; i < pqueue_size(int_pqueue); ++i) {
        ctofu current;
        int priority;
        pqueue_remove(int_pqueue, &current, &priority);
        printf("Element with Priority %d: %d\n", priority, current.data.integer_type);
    }

    // Check if the priority queue is empty
    if (pqueue_is_empty(int_pqueue)) {
        printf("Priority Queue is empty.\n");
    } else {
        printf("Priority Queue is not empty.\n");
    }

    // Clean up the memory
    pqueue_erase(int_pqueue);

    return 0;
} // end of func
