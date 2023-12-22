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
    // Create a linked list for integers
    cflist* int_list = tscl_flist_create(INTEGER_TYPE);

    // Insert elements into the linked list
    tscl_flist_insert(int_list, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 1});
    tscl_flist_insert(int_list, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 2});
    tscl_flist_insert(int_list, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 3});

    // Display the size of the linked list
    printf("List Size: %zu\n", tscl_flist_size(int_list));

    // Check if the linked list is not empty
    if (tscl_flist_not_empty(int_list)) {
        printf("The linked list is not empty.\n");
    }

    // Search for an element in the linked list
    ctofu searched_value;
    if (tscl_flist_search(int_list, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 2}) == 0) {
        printf("Element found in the linked list.\n");
        // Get the value associated with the element
        tscl_flist_getter(int_list, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 2}, &searched_value);
        printf("Associated Value: %d\n", searched_value.data.integer_type);
    } else {
        printf("Element not found in the linked list.\n");
    }

    // Reverse the linked list and display it
    printf("Linked List Before Reversal:\n");
    cflist_node* current_node = int_list->head;
    while (current_node != NULL) {
        printf("%d -> ", current_node->data.data.integer_type);
        current_node = current_node->next;
    }
    printf("NULL\n");

    // Reverse the linked list
    tscl_flist_reverse_forward(int_list);

    // Display the reversed linked list
    printf("Linked List After Forward Reversal:\n");
    current_node = int_list->head;
    while (current_node != NULL) {
        printf("%d -> ", current_node->data.data.integer_type);
        current_node = current_node->next;
    }
    printf("NULL\n");

    // Clean up
    tscl_flist_erase(int_list);

    return 0;
} // end of func
