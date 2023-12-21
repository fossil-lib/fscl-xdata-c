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
    // Create a singly linked list for integers
    cflist* int_flist = flist_create(INTEGER_TYPE);

    // Insert integers into the linked list
    for (int i = 1; i <= 5; ++i) {
        ctofu data;
        tofu_create(INTEGER_TYPE, &(ctofu_data){.data.integer_type = i}, &data);
        flist_insert(int_flist, data);
    }

    // Print the size of the linked list
    printf("Linked List size: %zu\n", flist_size(int_flist));

    // Print the elements of the linked list using a for loop
    printf("Linked List elements:\n");
    for (size_t i = 0; i < flist_size(int_flist); ++i) {
        ctofu current = *flist_getter(int_flist, (ctofu){.type = INTEGER_TYPE, .data.integer_type = i + 1});
        printf("%d ", current.data.integer_type);
    }
    printf("\n");

    // Reverse the linked list forward and print the reversed elements
    flist_reverse_forward(int_flist);
    printf("Reversed Linked List elements (forward):\n");
    for (size_t i = 0; i < flist_size(int_flist); ++i) {
        ctofu current = *flist_getter(int_flist, (ctofu){.type = INTEGER_TYPE, .data.integer_type = i + 1});
        printf("%d ", current.data.integer_type);
    }
    printf("\n");

    // Reverse the linked list backward and print the reversed elements
    flist_reverse_backward(int_flist);
    printf("Reversed Linked List elements (backward):\n");
    for (size_t i = 0; i < flist_size(int_flist); ++i) {
        ctofu current = *flist_getter(int_flist, (ctofu){.type = INTEGER_TYPE, .data.integer_type = i + 1});
        printf("%d ", current.data.integer_type);
    }
    printf("\n");

    // Check if the linked list is empty
    if (flist_is_empty(int_flist)) {
        printf("Linked List is empty.\n");
    } else {
        printf("Linked List is not empty.\n");
    }

    // Clean up the memory
    flist_erase(int_flist);

    return 0;
} // end of func
