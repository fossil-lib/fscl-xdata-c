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
    // Create a cpqueue instance with INTEGER_TYPE
    cpqueue* pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);

    // Insert data elements into the cpqueue with priorities
    trilo_xdata_pqueue_insert(pqueue, trilo_xdata_tofu_create_from_integer(10), 3);
    trilo_xdata_pqueue_insert(pqueue, trilo_xdata_tofu_create_from_integer(20), 1);
    trilo_xdata_pqueue_insert(pqueue, trilo_xdata_tofu_create_from_integer(30), 2);

    // Print the size of the cpqueue
    printf("Size of the priority queue: %zu\n", trilo_xdata_pqueue_size(pqueue));

    // Print the cpqueue elements
    printf("Priority queue elements:\n");
    for (int i = 1; i <= trilo_xdata_pqueue_size(pqueue); i++) {
        ctofu* tofu = trilo_xdata_pqueue_getter(pqueue, i, &i);
        printf("Priority %d: %d\n", i, trilo_xdata_tofu_get_integer(*tofu));
    } // end for

    // Check if the cpqueue is not empty
    printf("Is priority queue not empty? %s\n", trilo_xdata_pqueue_not_empty(pqueue) ? "true" : "false");

    // Remove an element from the cpqueue
    ctofu* removedTofu = trilo_xdata_pqueue_getter(pqueue, 2, NULL);
    ctofu_error removalResult = trilo_xdata_pqueue_remove(pqueue, *removedTofu, 2);
    printf("Removal result: %s\n", removalResult == TRILO_XDATA_TYPE_SUCCESS ? "success" : "failure");

    // Print the updated cpqueue
    printf("Updated priority queue elements:\n");
    for (int i = 1; i <= trilo_xdata_pqueue_size(pqueue); i++) {
        ctofu* tofu = trilo_xdata_pqueue_getter(pqueue, i, &i);
        printf("Priority %d: %d\n", i, trilo_xdata_tofu_get_integer(*tofu));
    } // end for

    // Check if the cpqueue is not empty
    printf("Is priority queue not empty? %s\n", trilo_xdata_pqueue_not_empty(pqueue) ? "true" : "false");

    // Destroy the cpqueue
    trilo_xdata_pqueue_destroy(pqueue);

    return 0;
} // end of func
