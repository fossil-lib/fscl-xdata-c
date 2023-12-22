/*  ----------------------------------------------------------------------------
    File: demo_queue.c

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
#include "trilobite/xdata/queue.h"
#include <stdio.h>

int main() {
    // Create a queue for integers
    cqueue* int_queue = tscl_queue_create(INTEGER_TYPE);

    // Insert elements into the queue
    tscl_queue_insert(int_queue, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 10});
    tscl_queue_insert(int_queue, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 20});
    tscl_queue_insert(int_queue, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 30});

    // Display queue size
    printf("Queue Size: %zu\n", tscl_queue_size(int_queue));

    // Check if the queue is not empty
    if (tscl_queue_not_empty(int_queue)) {
        printf("The queue is not empty.\n");
    }

    // Remove an element from the queue
    ctofu removed_element;
    tscl_queue_remove(int_queue, &removed_element);

    // Display the removed element
    printf("Removed Element: %d\n", removed_element.data.integer_type);

    // Display updated queue size
    printf("Queue Size after removal: %zu\n", tscl_queue_size(int_queue));

    // Clean up
    tscl_queue_erase(int_queue);

    return 0;
} // end of func
