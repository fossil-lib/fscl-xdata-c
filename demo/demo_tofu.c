/*  ----------------------------------------------------------------------------
    File: demo_tofu.c

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
#include "trilobite/xdata/tofu.h"
#include <stdio.h>
#include <stdbool.h>

int main() {
    // Create an array of ctofu elements
    ctofu array[5];

    // Populate the array with some data
    tofu_create(INTEGER_TYPE, &(ctofu_data){.data.integer_type = 42}, &array[0]);
    tofu_create(DOUBLE_TYPE, &(ctofu_data){.double_type = 3.14}, &array[1]);
    tofu_create(STRING_TYPE, &(ctofu_data){.string_type = "Hello"}, &array[2]);
    tofu_create(BOOLEAN_TYPE, &(ctofu_data){.boolean_type = true}, &array[3]);
    tofu_create(NULLPTR_TYPE, NULL, &array[4]);

    // Print the original array
    printf("Original Array:\n");
    for (size_t i = 0; i < 5; ++i) {
        printf("Element %zu: ", i);
        print_ctofu_value(&array[i]);
        printf("\n");
    }

    // Sort the array using insertion sort
    tofu_sort_insertion(array, 5);

    // Print the sorted array
    printf("\nSorted Array:\n");
    for (size_t i = 0; i < 5; ++i) {
        printf("Element %zu: ", i);
        print_ctofu_value(&array[i]);
        printf("\n");
    }

    // Reverse the array
    tofu_reverse(array, 5);

    // Print the reversed array
    printf("\nReversed Array:\n");
    for (size_t i = 0; i < 5; ++i) {
        printf("Element %zu: ", i);
        print_ctofu_value(&array[i]);
        printf("\n");
    }

    // Search for a specific element in the array
    ctofu key;
    tofu_create(INTEGER_TYPE, &(ctofu_data){.data.integer_type = 42}, &key);
    size_t index = tofu_search_linear(array, 5, &key);

    // Print the result of the search
    printf("\nSearch Result:\n");
    if (index != -1) {
        printf("Element found at index %zu\n", index);
    } else {
        printf("Element not found\n");
    }

    // Clean up the memory
    for (size_t i = 0; i < 5; ++i) {
        tofu_erase(&array[i]);
    }

    return 0;
} // end of func
