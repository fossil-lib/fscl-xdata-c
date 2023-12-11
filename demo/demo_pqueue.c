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
    cpqueue* pqueue = pqueue_create(INTEGER_TYPE);

    // Insert data elements into the cpqueue with priorities
    pqueue_insert(pqueue, tofu_create_from_integer(10), 3);
    pqueue_insert(pqueue, tofu_create_from_integer(20), 1);
    pqueue_insert(pqueue, tofu_create_from_integer(30), 2);

    // Print the size of the cpqueue
    printf("Size of the priority queue: %zu\n", pqueue_size(pqueue));

    // Check if the cpqueue is not empty
    printf("Is priority queue not empty? %s\n", pqueue_not_empty(pqueue) ? "true" : "false");

    // Check if the cpqueue is not empty
    printf("Is priority queue not empty? %s\n", pqueue_not_empty(pqueue) ? "true" : "false");

    // Destroy the cpqueue
    pqueue_erase(pqueue);

    return 0;
} // end of func
