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
    cmap* int_map = map_create(INTEGER_TYPE);

    // Insert key-value pairs into the map
    for (int i = 1; i <= 3; ++i) {
        ctofu key, value;
        tofu_create(INTEGER_TYPE, &(ctofu_data){.integer_type = i}, &key);
        tofu_create(INTEGER_TYPE, &(ctofu_data){.integer_type = i * 10}, &value);
        map_insert(int_map, key, value);
    }

    // Print the size of the map
    printf("Map size: %zu\n", map_size(int_map));

    // Print the elements of the map using an iterator
    printf("Map elements:\n");
    ctofu_iterator iterator = map_iterator_start(int_map);
    while (map_iterator_has_next(iterator)) {
        ctofu_iterator current = map_iterator_next(iterator);
        printf("Key: %d, Value: %d\n", current.current_key, current.current_value);
    }

    // Check if the map is empty
    if (map_is_empty(int_map)) {
        printf("Map is empty.\n");
    } else {
        printf("Map is not empty.\n");
    }

    // Clean up the memory
    map_erase(int_map);

    return 0;
}
