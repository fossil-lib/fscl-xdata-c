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
#ifndef TRILOBITE_XDATA_SET_H
#define TRILOBITE_XDATA_SET_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Node structure for the set
typedef struct cset_node {
    ctofu data;
    struct cset_node* next;
} cset_node;

// Set structure
typedef struct cset {
    cset_node* head;
    enum ctofu_type set_type;  // Type of the set
} cset;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new cset instance with the specified list type.
 *
 * @param list_type The data type for the cset (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created cset instance.
 */
cset* set_create(enum ctofu_type list_type);

/**
 * @brief Destroys the cset instance, freeing all associated memory.
 *
 * @param set The cset instance to be destroyed.
 */
void set_erase(cset* set);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a ctofu data element into the cset.
 *
 * @param set  The cset where the data will be inserted.
 * @param data The ctofu data element to be inserted.
 * @return A ctofu_error value indicating the result of the insertion.
 */
ctofu_error set_insert(cset* set, ctofu data);

/**
 * @brief Removes a ctofu data element from the cset.
 *
 * @param set  The cset from which the data will be removed.
 * @param data The ctofu data element to be removed.
 * @return A ctofu_error value indicating the result of the removal.
 */
ctofu_error set_remove(cset* set, ctofu data);

/**
 * @brief Searches for a ctofu data element in the cset.
 *
 * @param set  The cset to search within.
 * @param data The ctofu data element to search for.
 * @return A ctofu_error value indicating the result of the search.
 */
ctofu_error set_search(const cset* set, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the cset.
 *
 * @param set The cset for which the size will be determined.
 * @return The size of the cset.
 */
size_t set_size(const cset* set);

/**
 * @brief Getter function to retrieve a ctofu data element from the cset.
 *
 * @param set  The cset from which the data will be retrieved.
 * @param data The ctofu data element to retrieve.
 * @return A pointer to the ctofu data element in the cset (or NULL if not found).
 */
ctofu* set_getter(cset* set, ctofu data);

/**
 * @brief Setter function to update a ctofu data element in the cset.
 *
 * @param set  The cset in which the data will be updated.
 * @param data The ctofu data element to update.
 * @return A ctofu_error value indicating the result of the update.
 */
ctofu_error set_setter(cset* set, ctofu data);

/**
 * @brief Checks if the cset is not empty.
 *
 * @param set The cset to check.
 * @return true if the cset is not empty, false otherwise.
 */
bool set_not_empty(const cset* set);

/**
 * @brief Checks if the cset is not a null pointer.
 *
 * @param set The cset to check.
 * @return true if the cset is not a null pointer, false otherwise.
 */
bool set_not_cnullptr(const cset* set);

/**
 * @brief Checks if the cset is empty.
 *
 * @param set The cset to check.
 * @return true if the cset is empty, false otherwise.
 */
bool set_is_empty(const cset* set);

/**
 * @brief Checks if the cset is a null pointer.
 *
 * @param set The cset to check.
 * @return true if the cset is a null pointer, false otherwise.
 */
bool set_is_cnullptr(const cset* set);

/**
 * @brief Checks if a ctofu data element is present in the cset.
 *
 * @param set  The cset to check.
 * @param data The ctofu data element to search for.
 * @return true if the data element is present, false otherwise.
 */
bool set_contains(const cset* set, ctofu data);

#ifdef __cplusplus
}
#endif

#endif
