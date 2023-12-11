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
#ifndef TRILOBITE_XDATA_PQUEUE_H
#define TRILOBITE_XDATA_PQUEUE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

typedef struct cpqueue_node {
    ctofu data;
    int priority;
    struct cpqueue_node* next;
} cpqueue_node;

typedef struct cpqueue {
    cpqueue_node* front;
    enum ctofu_type queue_type;
} cpqueue;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new cpqueue instance with the specified queue type.
 *
 * @param queue_type The data type for the cpqueue (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created cpqueue instance.
 */
cpqueue* pqueue_create(enum ctofu_type queue_type);

/**
 * @brief Destroys the cpqueue instance, freeing all associated memory.
 *
 * @param pqueue The cpqueue instance to be destroyed.
 */
void pqueue_erase(cpqueue* pqueue);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a ctofu data element with a given priority into the cpqueue.
 *
 * @param pqueue   The cpqueue where the data will be inserted.
 * @param data     The ctofu data element to be inserted.
 * @param priority The priority of the data element.
 * @return A ctofu_error value indicating the result of the insertion.
 */
ctofu_error pqueue_insert(cpqueue* pqueue, ctofu data, int priority);

/**
 * @brief Removes a ctofu data element with a given priority from the cpqueue.
 *
 * @param pqueue   The cpqueue from which the data will be removed.
 * @param data     The ctofu data element to be removed.
 * @param priority The priority of the data element to remove.
 * @return A ctofu_error value indicating the result of the removal.
 */
ctofu_error pqueue_remove(cpqueue* pqueue, ctofu data, int priority);

/**
 * @brief Searches for a ctofu data element with a given priority in the cpqueue.
 *
 * @param pqueue   The cpqueue to search within.
 * @param data     The ctofu data element to search for.
 * @param priority The priority of the data element to search for.
 * @return A ctofu_error value indicating the result of the search.
 */
ctofu_error pqueue_search(const cpqueue* pqueue, ctofu data, int priority);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the cpqueue.
 *
 * @param pqueue The cpqueue for which the size will be determined.
 * @return The size of the cpqueue.
 */
size_t pqueue_size(const cpqueue* pqueue);

/**
 * @brief Getter function to retrieve a ctofu data element with a given priority from the cpqueue.
 *
 * @param pqueue   The cpqueue from which the data will be retrieved.
 * @param data     The ctofu data element to retrieve.
 * @param priority The priority of the data element to retrieve.
 * @return A pointer to the ctofu data element in the cpqueue (or NULL if not found).
 */
ctofu* pqueue_getter(cpqueue* pqueue, ctofu data, int priority);

/**
 * @brief Setter function to update a ctofu data element with a given priority in the cpqueue.
 *
 * @param pqueue   The cpqueue in which the data will be updated.
 * @param data     The ctofu data element to update.
 * @param priority The priority of the data element to update.
 * @return A ctofu_error value indicating the result of the update.
 */
ctofu_error pqueue_setter(cpqueue* pqueue, ctofu data, int priority);

/**
 * @brief Checks if the cpqueue is not empty.
 *
 * @param pqueue The cpqueue to check.
 * @return true if the cpqueue is not empty, false otherwise.
 */
bool pqueue_not_empty(const cpqueue* pqueue);

/**
 * @brief Checks if the cpqueue is not a null pointer.
 *
 * @param pqueue The cpqueue to check.
 * @return true if the cpqueue is not a null pointer, false otherwise.
 */
bool pqueue_not_cnullptr(const cpqueue* pqueue);

/**
 * @brief Checks if the cpqueue is empty.
 *
 * @param pqueue The cpqueue to check.
 * @return true if the cpqueue is empty, false otherwise.
 */
bool pqueue_is_empty(const cpqueue* pqueue);

/**
 * @brief Checks if the cpqueue is a null pointer.
 *
 * @param pqueue The cpqueue to check.
 * @return true if the cpqueue is a null pointer, false otherwise.
 */
bool pqueue_is_cnullptr(const cpqueue* pqueue);

#ifdef __cplusplus
}
#endif

#endif
