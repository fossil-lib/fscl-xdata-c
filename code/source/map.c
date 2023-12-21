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

// =======================
// CREATE and DELETE
// =======================

cmap* map_create(ctofu_type list_type) {
    cmap* new_map = (cmap*)malloc(sizeof(cmap));
    if (new_map == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    new_map->size = 0;

    return new_map;
}

void map_erase(cmap* map) {
    if (map == NULL) {
        return;
    }

    free(map);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

ctofu_error map_insert(cmap* map, ctofu key, ctofu value) {
    if (map == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    if (map->size >= MAX_MAP_SIZE) {
        return TOFU_WAS_BAD_RANGE; // Map is full
    }

    // Check if the key already exists
    for (size_t i = 0; i < map->size; ++i) {
        if (tofu_compare(&map->keys[i], &key, NULL) == 0) {
            return TOFU_WAS_MISMATCH; // Duplicate key
        }
    }

    map->keys[map->size] = key;
    map->values[map->size] = value;
    map->size++;

    return TOFU_SUCCESS;
}

ctofu_error map_remove(cmap* map, ctofu key) {
    if (map == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    size_t index = SIZE_MAX;

    // Find the index of the key
    for (size_t i = 0; i < map->size; ++i) {
        if (tofu_compare(&map->keys[i], &key, NULL) == 0) {
            index = i;
            break;
        }
    }

    if (index == SIZE_MAX) {
        return TOFU_NOT_FOUND; // Key not found
    }

    // Shift elements to fill the gap
    for (size_t i = index; i < map->size - 1; ++i) {
        map->keys[i] = map->keys[i + 1];
        map->values[i] = map->values[i + 1];
    }

    map->size--;

    return TOFU_SUCCESS;
}

ctofu_error map_search(const cmap* map, ctofu key) {
    if (map == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    for (size_t i = 0; i < map->size; ++i) {
        if (tofu_compare(&map->keys[i], &key, NULL) == 0) {
            return TOFU_SUCCESS; // Found
        }
    }

    return TOFU_NOT_FOUND; // Key not found
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t map_size(const cmap* map) {
    if (map == NULL) {
        return 0;
    }

    return map->size;
}

ctofu_error map_getter(cmap* map, ctofu key, ctofu* value) {
    if (map == NULL || value == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    for (size_t i = 0; i < map->size; ++i) {
        if (tofu_compare(&map->keys[i], &key, NULL) == 0) {
            *value = map->values[i];
            return TOFU_SUCCESS; // Found
        }
    }

    return TOFU_NOT_FOUND; // Key not found
}

ctofu_error map_setter(cmap* map, ctofu key, ctofu value) {
    if (map == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    for (size_t i = 0; i < map->size; ++i) {
        if (tofu_compare(&map->keys[i], &key, NULL) == 0) {
            // Found, update the value
            map->values[i] = value;
            return TOFU_SUCCESS;
        }
    }

    return TOFU_NOT_FOUND; // Key not found
}

bool map_not_empty(const cmap* map) {
    return map != NULL && map->size > 0;
}

bool map_not_cnullptr(const cmap* map) {
    return map != NULL;
}

bool map_is_empty(const cmap* map) {
    return map == NULL || map->size == 0;
}

bool map_is_cnullptr(const cmap* map) {
    return map == NULL;
}

bool map_contains(const cmap* map, ctofu key) {
    if (map == NULL) {
        return false;
    }

    for (size_t i = 0; i < map->size; ++i) {
        if (tofu_compare(&map->keys[i], &key, NULL) == 0) {
            return true; // Found
        }
    }

    return false; // Key not found
}

// =======================
// ITERATOR FUNCTIONS
// =======================
ctofu_iterator map_iterator_start(cmap* map) {
    ctofu_iterator iterator;
    iterator.current_key = map->keys;
    iterator.current_value = map->values;
    iterator.index = 0;

    return iterator;
}

ctofu_iterator map_iterator_end(cmap* map) {
    ctofu_iterator iterator;
    iterator.current_key = map->keys + map->size;
    iterator.current_value = map->values + map->size;
    iterator.index = map->size;

    return iterator;
}

ctofu_iterator map_iterator_next(ctofu_iterator iterator) {
    iterator.current_key++;
    iterator.current_value++;
    iterator.index++;

    return iterator;
}

bool map_iterator_has_next(ctofu_iterator iterator) {
    return iterator.index < MAX_MAP_SIZE;
}
