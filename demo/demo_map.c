/*  ----------------------------------------------------------------------------
    File: demo_map.c

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
#include "trilobite/xdata/map.h"
#include <stdio.h>

int main() {
    // Create a map for integers
    cmap* int_map = tscl_map_create(INTEGER_TYPE);

    // Insert key-value pairs into the map
    tscl_map_insert(int_map, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 1}, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 10});
    tscl_map_insert(int_map, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 2}, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 20});
    tscl_map_insert(int_map, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 3}, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 30});

    // Display the size of the map
    printf("Map Size: %zu\n", tscl_map_size(int_map));

    // Check if the map is not empty
    if (tscl_map_not_empty(int_map)) {
        printf("The map is not empty.\n");
    }

    // Search for a key in the map
    ctofu searched_value;
    if (tscl_map_search(int_map, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 2}) == 0) {
        printf("Key found in the map.\n");
        // Get the value associated with the key
        tscl_map_getter(int_map, (ctofu){.type = INTEGER_TYPE, .data.integer_type = 2}, &searched_value);
        printf("Associated Value: %d\n", searched_value.data.integer_type);
    } else {
        printf("Key not found in the map.\n");
    }

    // Display the key-value pairs using an iterator
    ctofu_iterator iterator = tscl_map_iterator_start(int_map);
    while (tscl_map_iterator_has_next(iterator)) {
        ctofu key = *iterator.current_key;
        ctofu value = *iterator.current_value;
        printf("Key: %d, Value: %d\n", key.data.integer_type, value.data.integer_type);
        iterator = tscl_map_iterator_next(iterator);
    }

    // Clean up
    tscl_map_erase(int_map);

    return 0;
}
