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
    // Create a vector of integers
    cvector int_vector = tscl_vector_create(INTEGER_TYPE);

    // Push some elements to the vector
    tscl_vector_push_back(&int_vector, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 42});
    tscl_vector_push_back(&int_vector, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 17});
    tscl_vector_push_back(&int_vector, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 91});

    // Display vector information
    printf("Vector Size: %zu\n", tscl_vector_size(&int_vector));
    printf("Is Vector Empty? %s\n", tscl_vector_is_empty(&int_vector) ? "Yes" : "No");

    // Display vector elements
    printf("Vector Elements: ");
    tscl_vector_peek(&int_vector);
    printf("\n");

    // Search for an element
    ctofu target_element = (ctofu){.type = INTEGER_TYPE, .data.integer_type = 17};
    int search_result = tscl_vector_search(&int_vector, target_element);
    printf("Index of %d in Vector: %d\n", target_element.data.integer_type, search_result);

    // Reverse the vector
    tscl_vector_reverse(&int_vector);

    // Display reversed vector elements
    printf("Reversed Vector Elements: ");
    tscl_vector_peek(&int_vector);
    printf("\n");

    // Clean up
    tscl_vector_erase(&int_vector);

    return 0;
} // end of func
