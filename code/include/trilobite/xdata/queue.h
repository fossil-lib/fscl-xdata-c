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
typedef struct TriloQueueNode {
    TriloTofu data;
    struct TriloQueueNode* next;
} TriloQueueNode;

// Queue structure
typedef struct TriloQueue {
    TriloQueueNode* front;
    TriloQueueNode* rear;
    enum DataType queue_type;  // Type of the queue
} TriloQueue;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new TriloQueue instance with the specified list type.
 *
 * @param list_type The data type for the TriloQueue (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created TriloQueue instance.
 */
TriloQueue* trilo_xdata_queue_create(enum DataType list_type);

/**
 * @brief Destroys the TriloQueue instance, freeing all associated memory.
 *
 * @param queue The TriloQueue instance to be destroyed.
 */
void trilo_xdata_queue_destroy(TriloQueue* queue);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a TriloTofu data element into the TriloQueue.
 *
 * @param queue The TriloQueue where the data will be inserted.
 * @param data  The TriloTofu data element to be inserted.
 * @return A TofuError value indicating the result of the insertion.
 */
TofuError trilo_xdata_queue_insert(TriloQueue* queue, TriloTofu data);

/**
 * @brief Removes an element from the front of the TriloQueue.
 *
 * This function removes an element from the front of the TriloQueue if it's not empty.
 *
 * @param queue The TriloQueue from which the element will be removed.
 * @return A TofuError value indicating the result of the removal.
 */
TofuError trilo_xdata_queue_remove(TriloQueue* queue);

/**
 * @brief Searches for a TriloTofu data element in the TriloQueue.
 *
 * @param queue The TriloQueue to search within.
 * @param data  The TriloTofu data element to search for.
 * @return A TofuError value indicating the result of the search.
 */
TofuError trilo_xdata_queue_search(const TriloQueue* queue, TriloTofu data);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the TriloQueue.
 *
 * @param queue The TriloQueue for which the size will be determined.
 * @return The size of the TriloQueue.
 */
size_t trilo_xdata_queue_size(const TriloQueue* queue);

/**
 * @brief Getter function to retrieve a TriloTofu data element from the TriloQueue.
 *
 * @param queue The TriloQueue from which the data will be retrieved.
 * @param data  The TriloTofu data element to retrieve.
 * @return A pointer to the TriloTofu data element in the TriloQueue (or NULL if not found).
 */
TriloTofu* trilo_xdata_queue_getter(TriloQueue* queue, TriloTofu data);

/**
 * @brief Setter function to update a TriloTofu data element in the TriloQueue.
 *
 * @param queue The TriloQueue in which the data will be updated.
 * @param data  The TriloTofu data element to update.
 * @return A TofuError value indicating the result of the update.
 */
TofuError trilo_xdata_queue_setter(TriloQueue* queue, TriloTofu data);

/**
 * @brief Checks if the TriloQueue is not empty.
 *
 * @param queue The TriloQueue to check.
 * @return true if the TriloQueue is not empty, false otherwise.
 */
bool trilo_xdata_queue_not_empty(const TriloQueue* queue);

/**
 * @brief Checks if the TriloQueue is not a null pointer.
 *
 * @param queue The TriloQueue to check.
 * @return true if the TriloQueue is not a null pointer, false otherwise.
 */
bool trilo_xdata_queue_not_nullptr(const TriloQueue* queue);

/**
 * @brief Checks if the TriloQueue is empty.
 *
 * @param queue The TriloQueue to check.
 * @return true if the TriloQueue is empty, false otherwise.
 */
bool trilo_xdata_queue_is_empty(const TriloQueue* queue);

/**
 * @brief Checks if the TriloQueue is a null pointer.
 *
 * @param queue The TriloQueue to check.
 * @return true if the TriloQueue is a null pointer, false otherwise.
 */
bool trilo_xdata_queue_is_nullptr(const TriloQueue* queue);

#ifdef __cplusplus
}
#endif

#endif
