/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#include "fossil/xdata/map.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

cmap* fscl_map_create(ctofu_type list_type) {
    cmap* new_map = (cmap*)malloc(sizeof(cmap));
    if (new_map == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    new_map->size = 0;

    return new_map;
}

void fscl_map_erase(cmap* map) {
    if (map == NULL) {
        return;
    }

    free(map);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

ctofu_error fscl_map_insert(cmap* map, ctofu key, ctofu value) {
    if (map == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    if (map->size >= MAX_MAP_SIZE) {
        return TOFU_WAS_BAD_RANGE; // Map is full
    }

    // Check if the key already exists
    for (size_t i = 0; i < map->size; ++i) {
        if (fscl_tofu_compare(&map->keys[i], &key, NULL) == 0) {
            return TOFU_WAS_MISMATCH; // Duplicate key
        }
    }

    map->keys[map->size] = key;
    map->values[map->size] = value;
    map->size++;

    return TOFU_SUCCESS;
}

ctofu_error fscl_map_remove(cmap* map, ctofu key) {
    if (map == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    size_t index = MAX_MAP_SIZE;

    // Find the index of the key
    for (size_t i = 0; i < map->size; ++i) {
        if (fscl_tofu_compare(&map->keys[i], &key, NULL) == 0) {
            index = i;
            break;
        }
    }

    if (index == MAX_MAP_SIZE) {
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

ctofu_error fscl_map_search(const cmap* map, ctofu key) {
    if (map == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    for (size_t i = 0; i < map->size; ++i) {
        if (fscl_tofu_compare(&map->keys[i], &key, NULL) == 0) {
            return TOFU_SUCCESS; // Found
        }
    }

    return TOFU_NOT_FOUND; // Key not found
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t fscl_map_size(const cmap* map) {
    if (map == NULL) {
        return 0;
    }

    return map->size;
}

ctofu_error fscl_map_getter(cmap* map, ctofu key, ctofu* value) {
    if (map == NULL || value == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    for (size_t i = 0; i < map->size; ++i) {
        if (fscl_tofu_compare(&map->keys[i], &key, NULL) == 0) {
            *value = map->values[i];
            return TOFU_SUCCESS; // Found
        }
    }

    return TOFU_NOT_FOUND; // Key not found
}

ctofu_error fscl_map_setter(cmap* map, ctofu key, ctofu value) {
    if (map == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    for (size_t i = 0; i < map->size; ++i) {
        if (fscl_tofu_compare(&map->keys[i], &key, NULL) == 0) {
            // Found, update the value
            map->values[i] = value;
            return TOFU_SUCCESS;
        }
    }

    return TOFU_NOT_FOUND; // Key not found
}

bool fscl_map_not_empty(const cmap* map) {
    return map != NULL && map->size > 0;
}

bool fscl_map_not_cnullptr(const cmap* map) {
    return map != NULL;
}

bool fscl_map_is_empty(const cmap* map) {
    return map == NULL || map->size == 0;
}

bool fscl_map_is_cnullptr(const cmap* map) {
    return map == NULL;
}

bool fscl_map_contains(const cmap* map, ctofu key) {
    if (map == NULL) {
        return false;
    }

    for (size_t i = 0; i < map->size; ++i) {
        if (fscl_tofu_compare(&map->keys[i], &key, NULL) == 0) {
            return true; // Found
        }
    }

    return false; // Key not found
}

// =======================
// ITERATOR FUNCTIONS
// =======================
ctofu_iterator fscl_map_iterator_start(cmap* map) {
    ctofu_iterator iterator;
    iterator.current_key = map->keys;
    iterator.current_value = map->values;
    iterator.index = 0;

    return iterator;
}

ctofu_iterator fscl_map_iterator_end(cmap* map) {
    ctofu_iterator iterator;
    iterator.current_key = map->keys + map->size;
    iterator.current_value = map->values + map->size;
    iterator.index = map->size;

    return iterator;
}

ctofu_iterator fscl_map_iterator_next(ctofu_iterator iterator) {
    iterator.current_key++;
    iterator.current_value++;
    iterator.index++;

    return iterator;
}

bool fscl_map_iterator_has_next(ctofu_iterator iterator) {
    return iterator.index < MAX_MAP_SIZE;
}
