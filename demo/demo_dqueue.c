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
    // Create a double-ended queue for integers
    cdqueue* int_dqueue = tscl_dqueue_create(INTEGER_TYPE);

    // Insert elements into the double-ended queue
    tscl_dqueue_insert(int_dqueue, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 1});
    tscl_dqueue_insert(int_dqueue, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 2});
    tscl_dqueue_insert(int_dqueue, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 3});

    // Display the size of the double-ended queue
    printf("Queue Size: %zu\n", tscl_dqueue_size(int_dqueue));

    // Check if the double-ended queue is not empty
    if (tscl_dqueue_not_empty(int_dqueue)) {
        printf("The double-ended queue is not empty.\n");
    }

    // Search for an element in the double-ended queue
    ctofu searched_value;
    if (tscl_dqueue_search(int_dqueue, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 2}) == 0) {
        printf("Element found in the double-ended queue.\n");
        // Get the value associated with the element
        tscl_dqueue_getter(int_dqueue, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 2}, &searched_value);
        printf("Associated Value: %d\n", searched_value.data.integer_type);
    } else {
        printf("Element not found in the double-ended queue.\n");
    }

    // Remove elements from the double-ended queue
    ctofu removed_value;
    tscl_dqueue_remove(int_dqueue, &removed_value);
    printf("Removed Value: %d\n", removed_value.data.integer_type);

    // Display the size after removal
    printf("Queue Size After Removal: %zu\n", tscl_dqueue_size(int_dqueue));

    // Clean up
    tscl_dqueue_erase(int_dqueue);

    return 0;
} // end of func
