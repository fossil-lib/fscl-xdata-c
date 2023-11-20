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
#ifndef TRILOBITE_XDATA_VECTOR_H
#define TRILOBITE_XDATA_VECTOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

#define INITIAL_CAPACITY 10

typedef struct {
    TriloTofu* data;
    size_t size;
    size_t capacity;
    enum DataType expected_type;
} TriloVector;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new TriloVector instance.
 *
 * @param expected_type The expected data type for the vector.
 * @return A TriloVector instance with the specified expected data type.
 */
TriloVector trilo_xdata_vector_create(enum DataType expected_type);

/**
 * @brief Destroys a TriloVector instance and frees the associated memory.
 *
 * @param vector The TriloVector to be destroyed.
 */
void trilo_xdata_vector_destroy(TriloVector* vector);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Searches for a target TriloTofu instance in a TriloVector.
 *
 * @param vector The TriloVector to search in.
 * @param target The TriloTofu instance to search for.
 * @return The index of the target if found, or -1 if not found.
 */
int trilo_xdata_vector_search(const TriloVector* vector, TriloTofu target);

/**
 * @brief Reverses the order of elements in a TriloVector.
 *
 * @param vector The TriloVector to be reversed.
 */
void trilo_xdata_vector_reverse(TriloVector* vector);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Checks if a TriloVector is a nullptr.
 *
 * @param vector The TriloVector to check.
 * @return true if the TriloVector is a nullptr, false otherwise.
 */
bool trilo_xdata_vector_is_nullptr(const TriloVector* vector);

/**
 * @brief Checks if a TriloVector is not a nullptr.
 *
 * @param vector The TriloVector to check.
 * @return true if the TriloVector is not a nullptr, false otherwise.
 */
bool trilo_xdata_vector_not_nullptr(const TriloVector* vector);

/**
 * @brief Checks if a TriloVector is empty.
 *
 * @param vector The TriloVector to check.
 * @return true if the TriloVector is empty, false otherwise.
 */
bool trilo_xdata_vector_is_empty(const TriloVector* vector);

/**
 * @brief Checks if a TriloVector is not empty.
 *
 * @param vector The TriloVector to check.
 * @return true if the TriloVector is not empty, false otherwise.
 */
bool trilo_xdata_vector_not_empty(const TriloVector* vector);

/**
 * @brief Sets the element at a specific index in a TriloVector.
 *
 * @param vector The TriloVector to modify.
 * @param index The index at which to set the element.
 * @param element The TriloTofu element to set.
 */
void trilo_xdata_vector_setter(TriloVector* vector, size_t index, TriloTofu element);

/**
 * @brief Gets the element at a specific index in a TriloVector.
 *
 * @param vector The TriloVector to access.
 * @param index The index of the element to retrieve.
 * @return The TriloTofu element at the specified index.
 */
TriloTofu trilo_xdata_vector_getter(const TriloVector* vector, size_t index);

/**
 * @brief Gets the size of a TriloVector.
 *
 * @param vector The TriloVector to get the size of.
 * @return The size of the TriloVector.
 */
size_t trilo_xdata_vector_size(const TriloVector* vector);

/**
 * @brief Prints the elements of a TriloVector.
 *
 * @param vector The TriloVector to print.
 */
void trilo_xdata_vector_peek(const TriloVector* vector);

#ifdef __cplusplus
}
#endif

#endif
