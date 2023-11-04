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
#include <stdbool.h>

int main() {
    // Create a TriloQueue instance with INTEGER_TYPE
    TriloQueue* queue = trilo_xdata_queue_create(INTEGER_TYPE);

    // Insert data elements into the TriloQueue
    trilo_xdata_queue_insert(queue, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_queue_insert(queue, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_queue_insert(queue, trilo_xdata_tofu_create_from_integer(30));

    // Print the size of the TriloQueue
    printf("Size of the queue: %zu\n", trilo_xdata_queue_size(queue));

    // Print the TriloQueue elements
    printf("Queue elements:\n");
    for (size_t i = 0; i < trilo_xdata_queue_size(queue); i++) {
        TriloTofu* tofu = trilo_xdata_queue_getter(queue, i);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
    } // end for

    // Check if the TriloQueue is not empty
    printf("Is queue not empty? %s\n", trilo_xdata_queue_not_empty(queue) ? "true" : "false");

    // Remove an element from the TriloQueue
    TriloTofu* removedTofu = trilo_xdata_queue_getter(queue, 1);
    TofuError removalResult = trilo_xdata_queue_remove(queue, *removedTofu);
    printf("Removal result: %s\n", removalResult == TRILO_XDATA_TYPE_SUCCESS ? "success" : "failure");

    // Print the updated TriloQueue
    printf("Updated queue elements:\n");
    for (size_t i = 0; i < trilo_xdata_queue_size(queue); i++) {
        TriloTofu* tofu = trilo_xdata_queue_getter(queue, i);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
    } // end for

    // Check if the TriloQueue is not empty
    printf("Is queue not empty? %s\n", trilo_xdata_queue_not_empty(queue) ? "true" : "false");

    // Destroy the TriloQueue
    trilo_xdata_queue_destroy(queue);

    return 0;
} // end of func
