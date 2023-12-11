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
    // Create a cdqueue instance with INTEGER_TYPE
    cdqueue* dqueue = dqueue_create(INTEGER_TYPE);

    // Insert data elements into the cdqueue
    dqueue_insert(dqueue, tofu_create_from_integer(10));
    dqueue_insert(dqueue, tofu_create_from_integer(20));
    dqueue_insert(dqueue, tofu_create_from_integer(30));

    // Print the size of the cdqueue
    printf("Size of the double-ended queue: %zu\n", dqueue_size(dqueue));

    // Print the cdqueue elements
    printf("Double-ended queue elements:\n");
    while (!dqueue_is_empty(dqueue)) {
        ctofu* tofu = dqueue_get_front(dqueue);
        printf("%d\n", tofu_get_integer(*tofu));
        dqueue_remove_front(dqueue);
    } // end while

    // Check if the cdqueue is not empty
    printf("Is double-ended queue not empty? %s\n", dqueue_not_empty(dqueue) ? "true" : "false");

    // Destroy the cdqueue
    dqueue_erase(dqueue);

    return 0;
} // end of func
