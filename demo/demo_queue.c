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
    cqueue* int_queue = queue_create(INTEGER_TYPE);

    // Insert integers into the queue using a for loop
    for (int i = 1; i <= 3; ++i) {
        ctofu data;
        tofu_create(INTEGER_TYPE, &(ctofu_data){.integer_type = i * 10}, &data);
        queue_insert(int_queue, data);
    }

    // Print the size of the queue
    printf("Queue size: %zu\n", queue_size(int_queue));

    // Print the elements of the queue using a for loop
    printf("Queue elements:\n");
    for (size_t i = 0; i < queue_size(int_queue); ++i) {
        ctofu current;
        queue_remove(int_queue, &current);
        printf("Element %zu: %d\n", i, current.data.integer_type);
    }

    // Check if the queue is empty
    if (queue_is_empty(int_queue)) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue is not empty.\n");
    }

    // Clean up the memory
    queue_erase(int_queue);

    return 0;
} // end of func
