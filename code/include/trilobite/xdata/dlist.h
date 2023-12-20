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
#ifndef TSCL_DLIST_H
#define TSCL_DLIST_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Node structure for the doubly linked list
typedef struct cdlist_node {
    ctofu data;
    struct cdlist_node* prev;
    struct cdlist_node* next;
} cdlist_node;

// Doubly linked list structure
typedef struct cdlist {
    cdlist_node* head;
    cdlist_node* tail;
    enum ctofu_type list_type;  // Type of the linked list
} cdlist;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new cdlist instance with the specified list type.
 *
 * @param list_type The data type for the cdlist (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created cdlist instance.
 */
cdlist* dlist_create(enum ctofu_type list_type);

/**
 * @brief Destroys the cdlist instance, freeing all associated memory.
 *
 * @param dlist The cdlist instance to be destroyed.
 */
void dlist_erase(cdlist* dlist);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a ctofu data element into the cdlist.
 *
 * @param dlist The cdlist where the data will be inserted.
 * @param data   The ctofu data element to be inserted.
 * @return A ctofu_error value indicating the result of the insertion.
 */
ctofu_error dlist_insert(cdlist* dlist, ctofu data);

/**
 * @brief Removes a ctofu data element from the cdlist.
 *
 * @param dlist The cdlist from which the data will be removed.
 * @param data   The ctofu data element to be removed.
 * @return A ctofu_error value indicating the result of the removal.
 */
ctofu_error dlist_remove(cdlist* dlist, ctofu data);

/**
 * @brief Searches for a ctofu data element in the cdlist.
 *
 * @param dlist The cdlist to search within.
 * @param data   The ctofu data element to search for.
 * @return A ctofu_error value indicating the result of the search.
 */
ctofu_error dlist_search(const cdlist* dlist, ctofu data);

/**
 * @brief Reverses the cdlist in the forward direction.
 *
 * @param dlist The cdlist to be reversed.
 */
void dlist_reverse_forward(cdlist* dlist);

/**
 * @brief Reverses the cdlist in the backward direction.
 *
 * @param dlist The cdlist to be reversed.
 */
void dlist_reverse_backward(cdlist* dlist);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the cdlist.
 *
 * @param dlist The cdlist for which the size will be determined.
 * @return The size of the cdlist.
 */
size_t dlist_size(const cdlist* dlist);

/**
 * @brief Getter function to retrieve a ctofu data element from the cdlist.
 *
 * @param dlist The cdlist from which the data will be retrieved.
 * @param data   The ctofu data element to retrieve.
 * @return A pointer to the ctofu data element in the cdlist (or NULL if not found).
 */
ctofu* dlist_getter(cdlist* dlist, ctofu data);

/**
 * @brief Setter function to update a ctofu data element in the cdlist.
 *
 * @param dlist The cdlist in which the data will be updated.
 * @param data   The ctofu data element to update.
 * @return A ctofu_error value indicating the result of the update.
 */
ctofu_error dlist_setter(cdlist* dlist, ctofu data);

/**
 * @brief Checks if the cdlist is not empty.
 *
 * @param dlist The cdlist to check.
 * @return true if the cdlist is not empty, false otherwise.
 */
bool dlist_not_empty(const cdlist* dlist);

/**
 * @brief Checks if the cdlist is not a null pointer.
 *
 * @param dlist The cdlist to check.
 * @return true if the cdlist is not a null pointer, false otherwise.
 */
bool dlist_not_cnullptr(const cdlist* dlist);

/**
 * @brief Checks if the cdlist is empty.
 *
 * @param dlist The cdlist to check.
 * @return true if the cdlist is empty, false otherwise.
 */
bool dlist_is_empty(const cdlist* dlist);

/**
 * @brief Checks if the cdlist is a null pointer.
 *
 * @param dlist The cdlist to check.
 * @return true if the cdlist is a null pointer, false otherwise.
 */
bool dlist_is_cnullptr(const cdlist* dlist);

#ifdef __cplusplus
}
#endif

#endif
