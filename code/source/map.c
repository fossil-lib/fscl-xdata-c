/*  ----------------------------------------------------------------------------
    File: map.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

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
#include <stdlib.h>
#include <string.h>

// Initialize a TriloMap
TriloMap* trilo_xdata_map_create(enum DataType list_type) {
    TriloMap* map = malloc(sizeof(TriloMap));
    if (map) {
        map->size = 0;
    } // end if
    return map;
} // end of func

// Destroy the TriloMap
void trilo_xdata_map_destroy(TriloMap* map) {
    if (map) {
        for (size_t i = 0; i < map->size; i++) {
            // No need to destroy the key and value
        } // end for
        free(map);
    } // end if
} // end of func

// Insert a key-value pair into the map
TofuError trilo_xdata_map_insert(TriloMap* map, TriloTofu key, TriloTofu value) {
    if (map && map->size < MAX_MAP_SIZE) {
        map->keys[map->size] = key;
        map->values[map->size] = value;
        map->size++;
        return TRILO_XDATA_TYPE_SUCCESS;
    } // end if
    return TRILO_XDATA_TYPE_WAS_BAD_RANGE; // Map is full
} // end of func

// Remove a key-value pair by key
TofuError trilo_xdata_map_remove(TriloMap* map, TriloTofu key) {
    if (map) {
        for (size_t i = 0; i < map->size; i++) {
            if (trilo_xdata_tofu_equal(key, map->keys[i])) {
                // No need to destroy the key and value
                // Shift elements to remove the key-value pair
                for (size_t j = i; j < map->size - 1; j++) {
                    map->keys[j] = map->keys[j + 1];
                    map->values[j] = map->values[j + 1];
                } // end for
                map->size--;
                return TRILO_XDATA_TYPE_SUCCESS;
            } // end if
        } // end for
    } // end if
    return TRILO_XDATA_TYPE_WAS_UNKNOWN; // Key not found
} // end of func

// Search for a key in the map
TofuError trilo_xdata_map_search(const TriloMap* map, TriloTofu key) {
    if (map) {
        for (size_t i = 0; i < map->size; i++) {
            if (trilo_xdata_tofu_equal(key, map->keys[i])) {
                return TRILO_XDATA_TYPE_SUCCESS;
            } // end if
        } // end for
    } // end if
    return TRILO_XDATA_TYPE_WAS_UNKNOWN; // Key not found
} // end of func

// Get the size of the map
size_t trilo_xdata_map_size(const TriloMap* map) {
    return map ? map->size : 0;
} // end of func

// Getter function to retrieve a key-value pair
TofuError trilo_xdata_map_getter(TriloMap* map, TriloTofu key, TriloTofu* value) {
    if (map) {
        for (size_t i = 0; i < map->size; i++) {
            if (trilo_xdata_tofu_equal(key, map->keys[i])) {
                *value = map->values[i];
                return TRILO_XDATA_TYPE_SUCCESS;
            } // end if
        } // end for
    } // end if
    return TRILO_XDATA_TYPE_WAS_UNKNOWN; // Key not found
} // end of func

// Setter function to update a key-value pair
TofuError trilo_xdata_map_setter(TriloMap* map, TriloTofu key, TriloTofu value) {
    if (map) {
        for (size_t i = 0; i < map->size; i++) {
            if (trilo_xdata_tofu_equal(key, map->keys[i])) {
                // No need to destroy the old value
                map->values[i] = value;
                return TRILO_XDATA_TYPE_SUCCESS;
            } // end if
        } // end for
    } // end if
    return TRILO_XDATA_TYPE_WAS_UNKNOWN; // Key not found
} // end of func

// Check if the map is not empty
bool trilo_xdata_map_not_empty(const TriloMap* map) {
    return map ? map->size > 0 : false;
} // end of func

// Check if the map is not a null pointer
bool trilo_xdata_map_not_nullptr(const TriloMap* map) {
    return map != NULL;
} // end of func

// Check if the map is empty
bool trilo_xdata_map_is_empty(const TriloMap* map) {
    return map ? map->size == 0 : true;
} // end of func

// Check if the map is a null pointer
bool trilo_xdata_map_is_nullptr(const TriloMap* map) {
    return map == NULL;
} // end of func

// Check if a key exists in the map
bool trilo_xdata_map_contains(const TriloMap* map, TriloTofu key) {
    if (map) {
        for (size_t i = 0; i < map->size; i++) {
            if (trilo_xdata_tofu_equal(key, map->keys[i])) {
                return true;
            } // end if
        } // end for
    } // end if
    return false;
} // end of func
