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
#ifndef TSCL_FLIST_H
#define TSCL_FLIST_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Node structure for the linked list
typedef struct cflist_node {
    ctofu data;
    struct cflist_node* next;
} cflist_node;

// Linked list structure
typedef struct cflist {
    cflist_node* head;
    enum ctofu_type list_type;  // Type of the linked list
} cflist;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new cflist instance with the specified list type.
 *
 * @param list_type The data type for the cflist (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created cflist instance.
 */
cflist* flist_create(enum ctofu_type list_type);

/**
 * @brief Destroys the cflist instance, freeing all associated memory.
 *
 * @param flist The cflist instance to be destroyed.
 */
void flist_erase(cflist* flist);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a ctofu data element into the cflist.
 *
 * @param flist The cflist where the data will be inserted.
 * @param data  The ctofu data element to be inserted.
 * @return A ctofu_error value indicating the result of the insertion.
 */
ctofu_error flist_insert(cflist* flist, ctofu data);

/**
 * @brief Removes a ctofu data element from the cflist.
 *
 * @param flist The cflist from which the data will be removed.
 * @param data  The ctofu data element to be removed.
 * @return A ctofu_error value indicating the result of the removal.
 */
ctofu_error flist_remove(cflist* flist, ctofu data);

/**
 * @brief Searches for a ctofu data element in the cflist.
 *
 * @param flist The cflist to search within.
 * @param data  The ctofu data element to search for.
 * @return A ctofu_error value indicating the result of the search.
 */
ctofu_error flist_search(const cflist* flist, ctofu data);

/**
 * @brief Reverses the cflist in the forward direction.
 *
 * @param flist The cflist to be reversed.
 */
void flist_reverse_forward(cflist* flist);

/**
 * @brief Reverses the cflist in the backward direction.
 *
 * @param flist The cflist to be reversed.
 */
void flist_reverse_backward(cflist* flist);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the cflist.
 *
 * @param flist The cflist for which the size will be determined.
 * @return The size of the cflist.
 */
size_t flist_size(const cflist* flist);

/**
 * @brief Getter function to retrieve a ctofu data element from the cflist.
 *
 * @param flist The cflist from which the data will be retrieved.
 * @param data  The ctofu data element to retrieve.
 * @return A pointer to the ctofu data element in the cflist (or NULL if not found).
 */
ctofu* flist_getter(cflist* flist, ctofu data);

/**
 * @brief Setter function to update a ctofu data element in the cflist.
 *
 * @param flist The cflist in which the data will be updated.
 * @param data  The ctofu data element to update.
 * @return A ctofu_error value indicating the result of the update.
 */
ctofu_error flist_setter(cflist* flist, ctofu data);

/**
 * @brief Checks if the cflist is not empty.
 *
 * @param flist The cflist to check.
 * @return true if the cflist is not empty, false otherwise.
 */
bool flist_not_empty(const cflist* flist);

/**
 * @brief Checks if the cflist is not a null pointer.
 *
 * @param flist The cflist to check.
 * @return true if the cflist is not a null pointer, false otherwise.
 */
bool flist_not_cnullptr(const cflist* flist);

/**
 * @brief Checks if the cflist is empty.
 *
 * @param flist The cflist to check.
 * @return true if the cflist is empty, false otherwise.
 */
bool flist_is_empty(const cflist* flist);

/**
 * @brief Checks if the cflist is a null pointer.
 *
 * @param flist The cflist to check.
 * @return true if the cflist is a null pointer, false otherwise.
 */
bool flist_is_cnullptr(const cflist* flist);

#ifdef __cplusplus
}
#endif

#endif
