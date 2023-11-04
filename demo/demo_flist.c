/*  ----------------------------------------------------------------------------
    File: demo_flist.c

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
#include "trilobite/xdata/flist.h"
#include <stdio.h>

int main() {
    // Create a TriloForwardList instance with INTEGER_TYPE
    TriloForwardList* flist = trilo_xdata_flist_create(INTEGER_TYPE);

    // Insert data elements into the TriloForwardList
    trilo_xdata_flist_insert(flist, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_flist_insert(flist, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_flist_insert(flist, trilo_xdata_tofu_create_from_integer(30));

    // Print the size of the TriloForwardList
    printf("Size of the forward list: %zu\n", trilo_xdata_flist_size(flist));

    // Print the TriloForwardList elements
    printf("Forward list elements:\n");
    TriloForwardListNode* current = trilo_xdata_flist_get_head(flist);
    while (current != NULL) {
        TriloTofu* tofu = trilo_xdata_flist_get_node_data(current);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
        current = trilo_xdata_flist_get_next(current);
    } // end while

    // Check if the TriloForwardList is not empty
    printf("Is forward list not empty? %s\n", trilo_xdata_flist_not_empty(flist) ? "true" : "false");

    // Reverse the TriloForwardList in the forward direction
    trilo_xdata_flist_reverse_forward(flist);

    // Print the reversed TriloForwardList elements
    printf("Reversed forward list elements:\n");
    current = trilo_xdata_flist_get_head(flist);
    while (current != NULL) {
        TriloTofu* tofu = trilo_xdata_flist_get_node_data(current);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
        current = trilo_xdata_flist_get_next(current);
    } // end while

    // Check if the TriloForwardList is not empty
    printf("Is forward list not empty? %s\n", trilo_xdata_flist_not_empty(flist) ? "true" : "false");

    // Destroy the TriloForwardList
    trilo_xdata_flist_destroy(flist);

    return 0;
} // end of func
