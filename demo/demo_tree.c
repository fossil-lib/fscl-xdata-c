/*  ----------------------------------------------------------------------------
    File: demo_tree.c

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
#include "trilobite/xdata/tree.h"
#include <stdio.h>

int main() {
    // Create a binary search tree for integers
    ctree* int_tree = tree_create(INTEGER_TYPE);

    // Insert integers into the tree using a for loop
    int values[] = {50, 30, 70, 20, 40};

    for (size_t i = 0; i < sizeof(values) / sizeof(values[0]); ++i) {
        ctofu data;
        tofu_create(INTEGER_TYPE, &(ctofu_data){.integer_type = values[i]}, &data);
        tree_insert(int_tree, data);
    }

    // Print the size of the tree
    printf("Tree size: %zu\n", tree_size(int_tree));

    // Search for a value in the tree
    ctofu search_key;
    tofu_create(INTEGER_TYPE, &(ctofu_data){.integer_type = 30}, &search_key);

    ctofu_error search_result = tree_search(int_tree, search_key);
    if (search_result == TOFU_SUCCESS) {
        printf("Value found in the tree!\n");
    } else {
        printf("Value not found in the tree.\n");
    }

    // Clean up the memory
    tree_erase(int_tree);
    tofu_erase(&search_key);

    return 0;
} // end of func
