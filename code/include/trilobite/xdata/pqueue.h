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

typedef struct TriloPQueueNode {
    TriloTofu data;
    int priority;
    struct TriloPQueueNode* next;
} TriloPQueueNode;

typedef struct TriloPQueue {
    TriloPQueueNode* front;
    enum DataType queue_type;
} TriloPQueue;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new TriloPQueue instance with the specified queue type.
 *
 * @param queue_type The data type for the TriloPQueue (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created TriloPQueue instance.
 */
TriloPQueue* trilo_xdata_pqueue_create(enum DataType queue_type);

/**
 * @brief Destroys the TriloPQueue instance, freeing all associated memory.
 *
 * @param pqueue The TriloPQueue instance to be destroyed.
 */
void trilo_xdata_pqueue_destroy(TriloPQueue* pqueue);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a TriloTofu data element with a given priority into the TriloPQueue.
 *
 * @param pqueue   The TriloPQueue where the data will be inserted.
 * @param data     The TriloTofu data element to be inserted.
 * @param priority The priority of the data element.
 * @return A TofuError value indicating the result of the insertion.
 */
TofuError trilo_xdata_pqueue_insert(TriloPQueue* pqueue, TriloTofu data, int priority);

/**
 * @brief Removes a TriloTofu data element with a given priority from the TriloPQueue.
 *
 * @param pqueue   The TriloPQueue from which the data will be removed.
 * @param data     The TriloTofu data element to be removed.
 * @param priority The priority of the data element to remove.
 * @return A TofuError value indicating the result of the removal.
 */
TofuError trilo_xdata_pqueue_remove(TriloPQueue* pqueue, TriloTofu data, int priority);

/**
 * @brief Searches for a TriloTofu data element with a given priority in the TriloPQueue.
 *
 * @param pqueue   The TriloPQueue to search within.
 * @param data     The TriloTofu data element to search for.
 * @param priority The priority of the data element to search for.
 * @return A TofuError value indicating the result of the search.
 */
TofuError trilo_xdata_pqueue_search(const TriloPQueue* pqueue, TriloTofu data, int priority);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the TriloPQueue.
 *
 * @param pqueue The TriloPQueue for which the size will be determined.
 * @return The size of the TriloPQueue.
 */
size_t trilo_xdata_pqueue_size(const TriloPQueue* pqueue);

/**
 * @brief Getter function to retrieve a TriloTofu data element with a given priority from the TriloPQueue.
 *
 * @param pqueue   The TriloPQueue from which the data will be retrieved.
 * @param data     The TriloTofu data element to retrieve.
 * @param priority The priority of the data element to retrieve.
 * @return A pointer to the TriloTofu data element in the TriloPQueue (or NULL if not found).
 */
TriloTofu* trilo_xdata_pqueue_getter(TriloPQueue* pqueue, TriloTofu data, int priority);

/**
 * @brief Setter function to update a TriloTofu data element with a given priority in the TriloPQueue.
 *
 * @param pqueue   The TriloPQueue in which the data will be updated.
 * @param data     The TriloTofu data element to update.
 * @param priority The priority of the data element to update.
 * @return A TofuError value indicating the result of the update.
 */
TofuError trilo_xdata_pqueue_setter(TriloPQueue* pqueue, TriloTofu data, int priority);

/**
 * @brief Checks if the TriloPQueue is not empty.
 *
 * @param pqueue The TriloPQueue to check.
 * @return true if the TriloPQueue is not empty, false otherwise.
 */
bool trilo_xdata_pqueue_not_empty(const TriloPQueue* pqueue);

/**
 * @brief Checks if the TriloPQueue is not a null pointer.
 *
 * @param pqueue The TriloPQueue to check.
 * @return true if the TriloPQueue is not a null pointer, false otherwise.
 */
bool trilo_xdata_pqueue_not_nullptr(const TriloPQueue* pqueue);

/**
 * @brief Checks if the TriloPQueue is empty.
 *
 * @param pqueue The TriloPQueue to check.
 * @return true if the TriloPQueue is empty, false otherwise.
 */
bool trilo_xdata_pqueue_is_empty(const TriloPQueue* pqueue);

/**
 * @brief Checks if the TriloPQueue is a null pointer.
 *
 * @param pqueue The TriloPQueue to check.
 * @return true if the TriloPQueue is a null pointer, false otherwise.
 */
bool trilo_xdata_pqueue_is_nullptr(const TriloPQueue* pqueue);

#ifdef __cplusplus
}
#endif

#endif
