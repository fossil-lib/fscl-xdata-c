/*  ----------------------------------------------------------------------------
    File: demo_dlist.c

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
#include "trilobite/xdata/dlist.h"
#include <stdio.h>

int main() {
    // Create a doubly linked list for integers
    cdlist* int_dlist = tscl_dlist_create(INTEGER_TYPE);

    // Insert elements into the doubly linked list
    tscl_dlist_insert(int_dlist, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 1});
    tscl_dlist_insert(int_dlist, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 2});
    tscl_dlist_insert(int_dlist, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 3});

    // Display the size of the doubly linked list
    printf("List Size: %zu\n", tscl_dlist_size(int_dlist));

    // Check if the doubly linked list is not empty
    if (tscl_dlist_not_empty(int_dlist)) {
        printf("The doubly linked list is not empty.\n");
    }

    // Search for an element in the doubly linked list
    ctofu searched_value;
    if (tscl_dlist_search(int_dlist, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 2}) == 0) {
        printf("Element found in the doubly linked list.\n");
        // Get the value associated with the element
        tscl_dlist_getter(int_dlist, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 2}, &searched_value);
        printf("Associated Value: %d\n", searched_value.data.integer_type);
    } else {
        printf("Element not found in the doubly linked list.\n");
    }

    // Remove elements from the doubly linked list
    ctofu removed_value;
    tscl_dlist_remove(int_dlist, &removed_value);
    printf("Removed Value: %d\n", removed_value.data.integer_type);

    // Display the size after removal
    printf("List Size After Removal: %zu\n", tscl_dlist_size(int_dlist));

    // Clean up
    tscl_dlist_erase(int_dlist);

    return 0;
} // end of func
