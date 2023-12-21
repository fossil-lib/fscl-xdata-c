/*  ----------------------------------------------------------------------------
    File: demo_vector.c

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
#include "trilobite/xdata/vector.h"
#include <stdio.h>

int main() {
    // Create a vector for integers
    cvector int_vector = vector_create(INTEGER_TYPE);

    // Push some integers into the vector
    vector_push_back(&int_vector, (ctofu){.type = INTEGER_TYPE, .data = {.data.integer_type = 10}});
    vector_push_back(&int_vector, (ctofu){.type = INTEGER_TYPE, .data = {.data.integer_type = 20}});
    vector_push_back(&int_vector, (ctofu){.type = INTEGER_TYPE, .data = {.data.integer_type = 30}});

    // Print the size of the vector
    printf("Vector size: %zu\n", vector_size(&int_vector));

    // Print the elements of the vector
    printf("Vector elements:\n");
    for (size_t i = 0; i < vector_size(&int_vector); ++i) {
        printf("Element %zu: %d\n", i, vector_getter(&int_vector, i).data.integer_type);
    }

    // Search for a value in the vector
    ctofu search_key = (ctofu){.type = INTEGER_TYPE, .data = {.data.integer_type = 20}};
    int search_result = vector_search(&int_vector, search_key);
    if (search_result != -1) {
        printf("Value found at index %d in the vector!\n", search_result);
    } else {
        printf("Value not found in the vector.\n");
    }

    // Reverse the vector
    vector_reverse(&int_vector);

    // Print the reversed vector
    printf("\nReversed Vector:\n");
    for (size_t i = 0; i < vector_size(&int_vector); ++i) {
        printf("Element %zu: %d\n", i, vector_getter(&int_vector, i).data.integer_type);
    }

    // Clean up the memory
    vector_erase(&int_vector);

    return 0;
}  // end of func
