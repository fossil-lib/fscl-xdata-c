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
#ifndef TSCL_DQUEUE_H
#define TSCL_DQUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Node structure for the double-ended queue
typedef struct cdqueue_node {
    ctofu data;
    struct cdqueue_node* prev;
    struct cdqueue_node* next;
} cdqueue_node;

// Double-ended queue structure
typedef struct cdqueue {
    cdqueue_node* front;
    cdqueue_node* rear;
    enum ctofu_type list_type;  // Type of the deque
} cdqueue;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new cdqueue instance with the specified list type.
 *
 * @param list_type The data type for the cdqueue (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created cdqueue instance.
 */
cdqueue* dqueue_create(enum ctofu_type list_type);

/**
 * @brief Destroys the cdqueue instance, freeing all associated memory.
 *
 * @param dqueue The cdqueue instance to be destroyed.
 */
void dqueue_erase(cdqueue* dqueue);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a ctofu data element into the cdqueue.
 *
 * @param dqueue The cdqueue where the data will be inserted.
 * @param data   The ctofu data element to be inserted.
 * @return A ctofu_error value indicating the result of the insertion.
 */
ctofu_error dqueue_insert(cdqueue* dqueue, ctofu data);

/**
 * @brief Removes a ctofu data element from the cdqueue.
 *
 * @param dqueue The cdqueue from which the data will be removed.
 * @param data   The ctofu data element to be removed.
 * @return A ctofu_error value indicating the result of the removal.
 */
ctofu_error dqueue_remove(cdqueue* dqueue, ctofu data);

/**
 * @brief Searches for a ctofu data element in the cdqueue.
 *
 * @param dqueue The cdqueue to search within.
 * @param data   The ctofu data element to search for.
 * @return A ctofu_error value indicating the result of the search.
 */
ctofu_error dqueue_search(const cdqueue* dqueue, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the cdqueue.
 *
 * @param dqueue The cdqueue for which the size will be determined.
 * @return The size of the cdqueue.
 */
size_t dqueue_size(const cdqueue* dqueue);

/**
 * @brief Getter function to retrieve a ctofu data element from the cdqueue.
 *
 * @param dqueue The cdqueue from which the data will be retrieved.
 * @param data   The ctofu data element to retrieve.
 * @return A pointer to the ctofu data element in the cdqueue (or NULL if not found).
 */
ctofu* dqueue_getter(cdqueue* dqueue, ctofu data);

/**
 * @brief Setter function to update a ctofu data element in the cdqueue.
 *
 * @param dqueue The cdqueue in which the data will be updated.
 * @param data   The ctofu data element to update.
 * @return A ctofu_error value indicating the result of the update.
 */
ctofu_error dqueue_setter(cdqueue* dqueue, ctofu data);

/**
 * @brief Checks if the cdqueue is not empty.
 *
 * @param dqueue The cdqueue to check.
 * @return true if the cdqueue is not empty, false otherwise.
 */
bool dqueue_not_empty(const cdqueue* dqueue);

/**
 * @brief Checks if the cdqueue is not a null pointer.
 *
 * @param dqueue The cdqueue to check.
 * @return true if the cdqueue is not a null pointer, false otherwise.
 */
bool dqueue_not_cnullptr(const cdqueue* dqueue);

/**
 * @brief Checks if the cdqueue is empty.
 *
 * @param dqueue The cdqueue to check.
 * @return true if the cdqueue is empty, false otherwise.
 */
bool dqueue_is_empty(const cdqueue* dqueue);

/**
 * @brief Checks if the cdqueue is a null pointer.
 *
 * @param dqueue The cdqueue to check.
 * @return true if the cdqueue is a null pointer, false otherwise.
 */
bool dqueue_is_cnullptr(const cdqueue* dqueue);

#ifdef __cplusplus
}
#endif

#endif
