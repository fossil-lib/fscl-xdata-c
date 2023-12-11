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
    // Create a new ctree instance to hold integer values
    ctree* intTree = tree_create(INTEGER_TYPE);

    // Insert some integer values into the ctree
    tree_insert(intTree, tofu_create_from_integer(42));
    tree_insert(intTree, tofu_create_from_integer(10));
    tree_insert(intTree, tofu_create_from_integer(73));

    // Check if the ctree is not empty
    if (tree_not_empty(intTree)) {
        printf("The ctree is not empty.\n");
    } // end if

    // Get the size of the ctree
    size_t intTreeSize = tree_size(intTree);
    printf("Size of the ctree: %zu\n", intTreeSize);

    // Search for a specific integer value
    ctofu searchValue = tofu_create_from_integer(10);
    ctofu_error searchResult = tree_search(intTree, searchValue);
    if (searchResult == TRILO_XDATA_TYPE_SUCCESS) {
        printf("The value 10 is found in the ctree.\n");
    } else {
        printf("The value 10 is not found in the ctree.\n");
    } // end if else

    // Destroy the ctree to free memory
    tree_erase(intTree);

    return 0;
} // end of func
