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
    // Create a cdlist instance with INTEGER_TYPE
    cdlist* dlist = dlist_create(INTEGER_TYPE);

    // Insert data elements into the cdlist
    dlist_insert(dlist, tofu_create_from_integer(10));
    dlist_insert(dlist, tofu_create_from_integer(20));
    dlist_insert(dlist, tofu_create_from_integer(30));

    // Print the size of the cdlist
    printf("Size of the doubly list: %zu\n", dlist_size(dlist));

    // Print the cdlist elements in forward order
    printf("Doubly list elements in forward order:\n");
    cdlist_node* current = dlist_get_head(dlist);
    while (current != NULL) {
        ctofu* tofu = dlist_get_node_data(current);
        printf("%d\n", tofu_get_integer(*tofu));
        current = dlist_get_next(current);
    } // end while

    // Reverse the cdlist in the forward direction
    dlist_reverse_forward(dlist);

    // Print the reversed cdlist elements
    printf("Reversed doubly list elements in forward order:\n");
    current = dlist_get_head(dlist);
    while (current != NULL) {
        ctofu* tofu = dlist_get_node_data(current);
        printf("%d\n", tofu_get_integer(*tofu));
        current = dlist_get_next(current);
    } // end while

    // Check if the cdlist is not empty
    printf("Is doubly list not empty? %s\n", dlist_not_empty(dlist) ? "true" : "false");

    // Destroy the cdlist
    dlist_erase(dlist);

    return 0;
} // end of func
