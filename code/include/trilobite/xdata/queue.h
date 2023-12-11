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
#ifndef TRILOBITE_XDATA_QUEUE_H
#define TRILOBITE_XDATA_QUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Node structure for the queue
typedef struct cqueue_node {
    ctofu data;
    struct cqueue_node* next;
} cqueue_node;

// Queue structure
typedef struct cqueue {
    cqueue_node* front;
    cqueue_node* rear;
    enum ctofu_type queue_type;  // Type of the queue
} cqueue;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new cqueue instance with the specified list type.
 *
 * @param list_type The data type for the cqueue (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created cqueue instance.
 */
cqueue* queue_create(enum ctofu_type list_type);

/**
 * @brief Destroys the cqueue instance, freeing all associated memory.
 *
 * @param queue The cqueue instance to be destroyed.
 */
void queue_erase(cqueue* queue);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a ctofu data element into the cqueue.
 *
 * @param queue The cqueue where the data will be inserted.
 * @param data  The ctofu data element to be inserted.
 * @return A ctofu_error value indicating the result of the insertion.
 */
ctofu_error queue_insert(cqueue* queue, ctofu data);

/**
 * @brief Removes an element from the front of the cqueue.
 *
 * This function removes an element from the front of the cqueue if it's not empty.
 *
 * @param queue The cqueue from which the element will be removed.
 * @return A ctofu_error value indicating the result of the removal.
 */
ctofu_error queue_remove(cqueue* queue);

/**
 * @brief Searches for a ctofu data element in the cqueue.
 *
 * @param queue The cqueue to search within.
 * @param data  The ctofu data element to search for.
 * @return A ctofu_error value indicating the result of the search.
 */
ctofu_error queue_search(const cqueue* queue, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the cqueue.
 *
 * @param queue The cqueue for which the size will be determined.
 * @return The size of the cqueue.
 */
size_t queue_size(const cqueue* queue);

/**
 * @brief Getter function to retrieve a ctofu data element from the cqueue.
 *
 * @param queue The cqueue from which the data will be retrieved.
 * @param data  The ctofu data element to retrieve.
 * @return A pointer to the ctofu data element in the cqueue (or NULL if not found).
 */
ctofu* queue_getter(cqueue* queue, ctofu data);

/**
 * @brief Setter function to update a ctofu data element in the cqueue.
 *
 * @param queue The cqueue in which the data will be updated.
 * @param data  The ctofu data element to update.
 * @return A ctofu_error value indicating the result of the update.
 */
ctofu_error queue_setter(cqueue* queue, ctofu data);

/**
 * @brief Checks if the cqueue is not empty.
 *
 * @param queue The cqueue to check.
 * @return true if the cqueue is not empty, false otherwise.
 */
bool queue_not_empty(const cqueue* queue);

/**
 * @brief Checks if the cqueue is not a null pointer.
 *
 * @param queue The cqueue to check.
 * @return true if the cqueue is not a null pointer, false otherwise.
 */
bool queue_not_cnullptr(const cqueue* queue);

/**
 * @brief Checks if the cqueue is empty.
 *
 * @param queue The cqueue to check.
 * @return true if the cqueue is empty, false otherwise.
 */
bool queue_is_empty(const cqueue* queue);

/**
 * @brief Checks if the cqueue is a null pointer.
 *
 * @param queue The cqueue to check.
 * @return true if the cqueue is a null pointer, false otherwise.
 */
bool queue_is_cnullptr(const cqueue* queue);

#ifdef __cplusplus
}
#endif

#endif
