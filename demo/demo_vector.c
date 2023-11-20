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
    // Example usage of the TriloVector structure
    TriloVector intVector = trilo_xdata_vector_create(INTEGER_TYPE);
    TriloVector stringVector = trilo_xdata_vector_create(STRING_TYPE);

    trilo_xdata_vector_push_back(&intVector, trilo_xdata_tofu_create_from_integer(42));
    trilo_xdata_vector_push_back(&intVector, trilo_xdata_tofu_create_from_integer(23));

    trilo_xdata_vector_push_back(&stringVector, trilo_xdata_tofu_create_from_string("Hello"));
    trilo_xdata_vector_push_back(&stringVector, trilo_xdata_tofu_create_from_string("World"));

    printf("Int Vector elements: ");
    trilo_xdata_vector_print(&intVector);

    printf("String Vector elements: ");
    trilo_xdata_vector_print(&stringVector);

    printf("Int Vector is%s nullptr\n", trilo_xdata_vector_is_nullptr(&intVector) ? "" : " not");
    printf("String Vector is%s nullptr\n", trilo_xdata_vector_is_nullptr(&stringVector) ? "" : " not");

    printf("Int Vector is%s empty\n", trilo_xdata_vector_is_empty(&intVector) ? "" : " not");
    printf("String Vector is%s empty\n", trilo_xdata_vector_is_empty(&stringVector) ? "" : " not");

    printf("Int Vector size: %zu\n", trilo_xdata_vector_size(&intVector));
    printf("String Vector size: %zu\n", trilo_xdata_vector_size(&stringVector));

    printf("Searching for 'World' in String Vector: %d\n", trilo_xdata_vector_search(&stringVector, trilo_xdata_tofu_create_from_string("World")));

    printf("Reversing Int Vector...\n");
    trilo_xdata_vector_reverse(&intVector);
    printf("Int Vector elements after reverse: ");
    trilo_xdata_vector_print(&intVector);

    // Cleanup
    trilo_xdata_vector_destroy(&intVector);
    trilo_xdata_vector_destroy(&stringVector);

    return 0;
} // end of func
