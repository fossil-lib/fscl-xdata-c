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
#ifndef fscl_map_H
#define fscl_map_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xtofu.h"

// Define a maximum number of key-value pairs that can be stored in the map
#define MAX_MAP_SIZE 100

// Define a structure to represent a cmap
typedef struct {
    ctofu keys[MAX_MAP_SIZE];
    ctofu values[MAX_MAP_SIZE];
    size_t size;
} cmap;

// =======================
// CREATE and DELETE
// =======================
/**
 * Create a new map with the specified data type.
 *
 * @param list_type The type of data the map will store.
 * @return          The created map.
 */
cmap* fscl_map_create(ctofu_type list_type);

/**
 * Erase the contents of the map and free allocated memory.
 *
 * @param map The map to erase.
 */
void fscl_map_erase(cmap* map);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Insert key-value pair into the map.
 *
 * @param map   The map to insert data into.
 * @param key   The key of the data.
 * @param value The value of the data.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_map_insert(cmap* map, ctofu key, ctofu value);

/**
 * Remove key-value pair from the map.
 *
 * @param map The map to remove data from.
 * @param key The key of the data.
 * @return    The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_map_remove(cmap* map, ctofu key);

/**
 * Search for key in the map.
 *
 * @param map The map to search.
 * @param key The key to search for.
 * @return    The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_map_search(cmap* map, ctofu key);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the map.
 *
 * @param map The map for which to get the size.
 * @return    The size of the map.
 */
size_t fscl_map_size(cmap* map);

/**
 * Get the value from the map matching the specified key.
 *
 * @param map   The map from which to get the value.
 * @param key   The key to search for.
 * @param value A pointer to store the matching value.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_map_getter(cmap* map, ctofu key, ctofu* value);

/**
 * Set value in the map with the specified key.
 *
 * @param map   The map in which to set the value.
 * @param key   The key of the data.
 * @param value The value to set.
 * @return      The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_map_setter(cmap* map, ctofu key, ctofu value);

/**
 * Check if the map is not empty.
 *
 * @param map The map to check.
 * @return    True if the map is not empty, false otherwise.
 */
bool fscl_map_not_empty(cmap* map);

/**
 * Check if the map is not a null pointer.
 *
 * @param map The map to check.
 * @return    True if the map is not a null pointer, false otherwise.
 */
bool fscl_map_not_cnullptr(cmap* map);

/**
 * Check if the map is empty.
 *
 * @param map The map to check.
 * @return    True if the map is empty, false otherwise.
 */
bool fscl_map_is_empty(cmap* map);

/**
 * Check if the map is a null pointer.
 *
 * @param map The map to check.
 * @return    True if the map is a null pointer, false otherwise.
 */
bool fscl_map_is_cnullptr(cmap* map);

/**
 * Check if the map contains the specified key.
 *
 * @param map The map to check.
 * @param key The key to search for.
 * @return    True if the map contains the key, false otherwise.
 */
bool fscl_map_contains(cmap* map, ctofu key);

// =======================
// ITERATOR FUNCTIONS
// =======================
/**
 * Get the iterator pointing to the start of the map.
 *
 * @param map The map for which to get the iterator.
 * @return    The iterator pointing to the start of the map.
 */
ctofu_iterator fscl_map_iterator_start(cmap* map);

/**
 * Get the iterator pointing to the end of the map.
 *
 * @param map The map for which to get the iterator.
 * @return    The iterator pointing to the end of the map.
 */
ctofu_iterator fscl_map_iterator_end(cmap* map);

/**
 * Get the next iterator in the sequence.
 *
 * @param iterator The current iterator.
 * @return         The next iterator in the sequence.
 */
ctofu_iterator fscl_map_iterator_next(ctofu_iterator iterator);

/**
 * Check if there is a next iterator in the sequence.
 *
 * @param iterator The current iterator.
 * @return         True if there is a next iterator, false otherwise.
 */
bool fscl_map_iterator_has_next(ctofu_iterator iterator);

#ifdef __cplusplus
}
#endif

#endif
