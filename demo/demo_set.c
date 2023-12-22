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
    // Create a set for integers
    cset* int_set = tscl_set_create(INTEGER_TYPE);

    // Insert elements into the set
    tscl_set_insert(int_set, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 10});
    tscl_set_insert(int_set, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 20});
    tscl_set_insert(int_set, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 30});

    // Display set size
    printf("Set Size: %zu\n", tscl_set_size(int_set));

    // Check if the set contains a specific element
    if (tscl_set_contains(int_set, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 20})) {
        printf("The set contains the element 20.\n");
    }

    // Remove an element from the set
    tscl_set_remove(int_set, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 20});

    // Display set size after removal
    printf("Set Size after removal: %zu\n", tscl_set_size(int_set));

    // Clean up
    tscl_set_erase(int_set);

    return 0;
} // end of func
