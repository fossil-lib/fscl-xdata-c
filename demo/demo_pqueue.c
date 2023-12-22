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
    cpqueue* int_pqueue = tscl_pqueue_create(INTEGER_TYPE);

    // Insert elements with priorities into the priority queue
    tscl_pqueue_insert(int_pqueue, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 10}, 2);
    tscl_pqueue_insert(int_pqueue, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 20}, 1);
    tscl_pqueue_insert(int_pqueue, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 30}, 3);

    // Display priority queue size
    printf("Priority Queue Size: %zu\n", tscl_pqueue_size(int_pqueue));

    // Check if the priority queue is not empty
    if (tscl_pqueue_not_empty(int_pqueue)) {
        printf("The priority queue is not empty.\n");
    }

    // Remove an element with priority from the priority queue
    ctofu removed_element;
    int removed_priority;
    tscl_pqueue_remove(int_pqueue, &removed_element, &removed_priority);

    // Display the removed element and its priority
    printf("Removed Element: %d with Priority: %d\n", removed_element.data.integer_type, removed_priority);

    // Display updated priority queue size
    printf("Priority Queue Size after removal: %zu\n", tscl_pqueue_size(int_pqueue));

    // Clean up
    tscl_pqueue_erase(int_pqueue);

    return 0;
} // end of func
