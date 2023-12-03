/*  ----------------------------------------------------------------------------
    File: demo_set.c

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
#include "trilobite/xdata/set.h"
#include <stdio.h>

int main() {
    // Create a cset instance with INTEGER_TYPE
    cset* set = trilo_xdata_set_create(INTEGER_TYPE);

    // Insert data elements into the cset
    trilo_xdata_set_insert(set, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_set_insert(set, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_set_insert(set, trilo_xdata_tofu_create_from_integer(30));

    // Print the size of the cset
    printf("Size of the set: %zu\n", trilo_xdata_set_size(set));

    // Print the cset
    printf("Set elements:\n");
    for (size_t i = 0; i < trilo_xdata_set_size(set); i++) {
        ctofu* tofu = trilo_xdata_set_getter(set, i);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
    } // end for

    // Check if the cset is not empty
    printf("Is set not empty? %s\n", trilo_xdata_set_not_empty(set) ? "true" : "false");

    // Remove an element from the cset
    ctofu* removedTofu = trilo_xdata_set_getter(set, 1);
    ctofu_error removalResult = trilo_xdata_set_remove(set, *removedTofu);
    printf("Removal result: %s\n", removalResult == TRILO_XDATA_TYPE_SUCCESS ? "success" : "failure");

    // Print the updated cset
    printf("Updated set elements:\n");
    for (size_t i = 0; i < trilo_xdata_set_size(set); i++) {
        ctofu* tofu = trilo_xdata_set_getter(set, i);
        printf("%d\n", trilo_xdata_tofu_get_integer(*tofu));
    } // end for

    // Check if the cset contains a specific element
    ctofu targetTofu = trilo_xdata_tofu_create_from_integer(30);
    printf("Does the set contain the element %d? %s\n", trilo_xdata_tofu_get_integer(targetTofu),
           trilo_xdata_set_contains(set, targetTofu) ? "true" : "false");

    // Destroy the cset
    trilo_xdata_set_destroy(set);

    return 0;
} // end of func
