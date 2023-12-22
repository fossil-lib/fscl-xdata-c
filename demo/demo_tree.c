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
    // Create a binary search tree
    ctree* binary_tree = tscl_tree_create(INTEGER_TYPE);

    // Insert elements into the tree
    tscl_tree_insert(binary_tree, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 50});
    tscl_tree_insert(binary_tree, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 30});
    tscl_tree_insert(binary_tree, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 70});
    tscl_tree_insert(binary_tree, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 20});
    tscl_tree_insert(binary_tree, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 40});
    tscl_tree_insert(binary_tree, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 60});
    tscl_tree_insert(binary_tree, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 80});

    // Display tree size
    printf("Tree Size: %zu\n", tscl_tree_size(binary_tree));

    // Search for an element in the tree
    ctofu search_result;
    if (tscl_tree_search(binary_tree, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 40}) == TOFU_SUCCESS) {
        printf("Element 40 is present in the tree.\n");
    } else {
        printf("Element 40 is not present in the tree.\n");
    }

    // Remove an element from the tree
    tscl_tree_remove(binary_tree, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 30});

    // Display tree size after removal
    printf("Tree Size after removal: %zu\n", tscl_tree_size(binary_tree));

    // Clean up
    tscl_tree_erase(binary_tree);

    return 0;
}
