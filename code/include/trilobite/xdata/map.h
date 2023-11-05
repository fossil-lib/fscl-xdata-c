/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.home.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TRILOBITE_XDATA_MAP_H
#define TRILOBITE_XDATA_MAP_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Define a maximum number of key-value pairs that can be stored in the map
#define MAX_MAP_SIZE 100

// Define a structure to represent a TriloMap
typedef struct {
    TriloTofu keys[MAX_MAP_SIZE];
    TriloTofu values[MAX_MAP_SIZE];
    size_t size;
} TriloMap;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new TriloMap instance with the specified list type.
 *
 * @param list_type The data type for the TriloMap (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created TriloMap instance.
 */
TriloMap* trilo_xdata_map_create(enum DataType list_type);

/**
 * @brief Destroys the TriloMap instance, freeing all associated memory.
 *
 * @param map The TriloMap instance to be destroyed.
 */
void trilo_xdata_map_destroy(TriloMap* map);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a key-value pair into the TriloMap.
 *
 * @param map   The TriloMap where the key-value pair will be inserted.
 * @param key   The key in the key-value pair.
 * @param value The value in the key-value pair.
 * @return A TofuError value indicating the result of the insertion.
 */
TofuError trilo_xdata_map_insert(TriloMap* map, TriloTofu key, TriloTofu value);

/**
 * @brief Removes a key-value pair from the TriloMap by key.
 *
 * @param map The TriloMap from which the key-value pair will be removed.
 * @param key The key of the key-value pair to be removed.
 * @return A TofuError value indicating the result of the removal.
 */
TofuError trilo_xdata_map_remove(TriloMap* map, TriloTofu key);

/**
 * @brief Searches for a key in the TriloMap.
 *
 * @param map The TriloMap to search within.
 * @param key The key to search for.
 * @return A TofuError value indicating the result of the search.
 */
TofuError trilo_xdata_map_search(const TriloMap* map, TriloTofu key);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the TriloMap.
 *
 * @param map The TriloMap for which the size will be determined.
 * @return The size of the TriloMap.
 */
size_t trilo_xdata_map_size(const TriloMap* map);

/**
 * @brief Getter function to retrieve a value by key from the TriloMap.
 *
 * @param map  The TriloMap from which the value will be retrieved.
 * @param key  The key for which the value will be retrieved.
 * @param value A pointer to store the retrieved value.
 * @return A TofuError value indicating the result of the retrieval.
 */
TofuError trilo_xdata_map_getter(TriloMap* map, TriloTofu key, TriloTofu* value);

/**
 * @brief Setter function to update a value by key in the TriloMap.
 *
 * @param map   The TriloMap in which the value will be updated.
 * @param key   The key for which the value will be updated.
 * @param value The new value to set.
 * @return A TofuError value indicating the result of the update.
 */
TofuError trilo_xdata_map_setter(TriloMap* map, TriloTofu key, TriloTofu value);

/**
 * @brief Checks if the TriloMap is not empty.
 *
 * @param map The TriloMap to check.
 * @return true if the TriloMap is not empty, false otherwise.
 */
bool trilo_xdata_map_not_empty(const TriloMap* map);

/**
 * @brief Checks if the TriloMap is not a null pointer.
 *
 * @param map The TriloMap to check.
 * @return true if the TriloMap is not a null pointer, false otherwise.
 */
bool trilo_xdata_map_not_nullptr(const TriloMap* map);

/**
 * @brief Checks if the TriloMap is empty.
 *
 * @param map The TriloMap to check.
 * @return true if the TriloMap is empty, false otherwise.
 */
bool trilo_xdata_map_is_empty(const TriloMap* map);

/**
 * @brief Checks if the TriloMap is a null pointer.
 *
 * @param map The TriloMap to check.
 * @return true if the TriloMap is a null pointer, false otherwise.
 */
bool trilo_xdata_map_is_nullptr(const TriloMap* map);

/**
 * @brief Checks if a key exists in the TriloMap.
 *
 * @param map The TriloMap to check.
 * @param key The key to search for.
 * @return true if the key exists in the TriloMap, false otherwise.
 */
bool trilo_xdata_map_contains(const TriloMap* map, TriloTofu key);

#ifdef __cplusplus
}
#endif

#endif
