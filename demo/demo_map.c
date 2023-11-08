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
    TriloMap* map = trilo_xdata_map_create(STRING_TYPE);

    // Insert key-value pairs into the map
    TriloTofu key1 = trilo_xdata_tofu_create_from_string("name");
    TriloTofu value1 = trilo_xdata_tofu_create_from_string("John");
    trilo_xdata_map_insert(map, key1, value1);

    TriloTofu key2 = trilo_xdata_tofu_create_from_string("age");
    TriloTofu value2 = trilo_xdata_tofu_create_from_integer(30);
    trilo_xdata_map_insert(map, key2, value2);

    // Lookup values by key
    TriloTofu result;
    TofuError lookupResult = trilo_xdata_map_search(map, key1);
    if (lookupResult == TRILO_XDATA_TYPE_SUCCESS) {
        trilo_xdata_map_getter(map, key1, &result);
        printf("Name: %s\n", trilo_xdata_tofu_get_string(result));
    } // end if

    lookupResult = trilo_xdata_map_search(map, key2);
    if (lookupResult == TRILO_XDATA_TYPE_SUCCESS) {
        trilo_xdata_map_getter(map, key2, &result);
        printf("Age: %d\n", trilo_xdata_tofu_get_integer(result));
    } // end if

    // Remove a key-value pair
    trilo_xdata_map_remove(map, key1);

    // Check if a key exists
    if (trilo_xdata_map_contains(map, key1)) {
        printf("Key 'name' exists in the map.\n");
    } else {
        printf("Key 'name' does not exist in the map.\n");
    } // end if else

    // Get the number of key-value pairs in the map
    size_t mapSize = trilo_xdata_map_size(map);
    printf("Map size: %zu\n");

    // Destroy the map
    trilo_xdata_map_destroy(map);

    return 0;
}
