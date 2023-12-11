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
    // Example usage of the cvector structure
    cvector intVector = vector_create(INTEGER_TYPE);
    cvector stringVector = vector_create(STRING_TYPE);

    vector_push_back(&intVector, tofu_create_from_integer(42));
    vector_push_back(&intVector, tofu_create_from_integer(23));

    vector_push_back(&stringVector, tofu_create_from_string("Hello"));
    vector_push_back(&stringVector, tofu_create_from_string("World"));

    printf("Int Vector elements: ");
    vector_print(&intVector);

    printf("String Vector elements: ");
    vector_print(&stringVector);

    printf("Int Vector is%s nullptr\n", vector_is_cnullptr(&intVector) ? "" : " not");
    printf("String Vector is%s nullptr\n", vector_is_cnullptr(&stringVector) ? "" : " not");

    printf("Int Vector is%s empty\n", vector_is_empty(&intVector) ? "" : " not");
    printf("String Vector is%s empty\n", vector_is_empty(&stringVector) ? "" : " not");

    printf("Int Vector size: %zu\n", vector_size(&intVector));
    printf("String Vector size: %zu\n", vector_size(&stringVector));

    printf("Searching for 'World' in String Vector: %d\n", vector_search(&stringVector, tofu_create_from_string("World")));

    printf("Reversing Int Vector...\n");
    vector_reverse(&intVector);
    printf("Int Vector elements after reverse: ");
    vector_print(&intVector);

    // Cleanup
    vector_erase(&intVector);
    vector_erase(&stringVector);

    return 0;
} // end of func
