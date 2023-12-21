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
    // Create a doubly linked list for strings
    cdlist* string_dlist = dlist_create(STRING_TYPE);

    // Insert strings into the list
    for (int i = 1; i <= 5; ++i) {
        char str[10];
        sprintf(str, "Str%d", i);

        ctofu data;
        tofu_create(STRING_TYPE, &(ctofu_data){.string_type = str}, &data);

        dlist_insert(string_dlist, data);
    }

    // Print the size of the list
    printf("Doubly Linked List size: %zu\n", dlist_size(string_dlist));

    // Print the elements of the list using a for loop
    printf("Doubly Linked List elements:\n");
    for (size_t i = 0; i < dlist_size(string_dlist); ++i) {
        ctofu current = *dlist_getter(string_dlist, (ctofu){.type = INTEGER_TYPE, .data.integer_type = i + 1});
        printf("%s ", current.data.string_type);
    }
    printf("\n");

    // Reverse the list forward
    dlist_reverse_forward(string_dlist);

    // Print the reversed elements of the list
    printf("Reversed Doubly Linked List elements (forward):\n");
    for (size_t i = 0; i < dlist_size(string_dlist); ++i) {
        ctofu current = *dlist_getter(string_dlist, (ctofu){.type = INTEGER_TYPE, .data.integer_type = i + 1});
        printf("%s ", current.data.string_type);
    }
    printf("\n");

    // Reverse the list backward
    dlist_reverse_backward(string_dlist);

    // Print the reversed elements of the list
    printf("Reversed Doubly Linked List elements (backward):\n");
    for (size_t i = 0; i < dlist_size(string_dlist); ++i) {
        ctofu current = *dlist_getter(string_dlist, (ctofu){.type = INTEGER_TYPE, .data.integer_type = i + 1});
        printf("%s ", current.data.string_type);
    }
    printf("\n");

    // Check if the list is not empty
    if (dlist_not_empty(string_dlist)) {
        printf("Doubly Linked List is not empty.\n");
    } else {
        printf("Doubly Linked List is empty.\n");
    }

    // Clean up the memory
    dlist_erase(string_dlist);

    return 0;
} // end of func
