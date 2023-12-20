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
#ifndef TSCL_VECTOR_H
#define TSCL_VECTOR_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

#define INITIAL_CAPACITY 10

typedef struct {
    ctofu* data;
    size_t size;
    size_t capacity;
    enum ctofu_type expected_type;
} cvector;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new cvector instance.
 *
 * @param expected_type The expected data type for the vector.
 * @return A cvector instance with the specified expected data type.
 */
cvector vector_create(enum ctofu_type expected_type);

/**
 * @brief Destroys a cvector instance and frees the associated memory.
 *
 * @param vector The cvector to be destroyed.
 */
void vector_erase(cvector* vector);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Adds a ctofu element to the end of a TriloXDataVector.
 *
 * @param vector The TriloXDataVector to which the element will be added.
 * @param element The ctofu element to add to the vector.
 */
void vector_push_back(cvector* vector, ctofu element);

/**
 * @brief Searches for a target ctofu instance in a cvector.
 *
 * @param vector The cvector to search in.
 * @param target The ctofu instance to search for.
 * @return The index of the target if found, or -1 if not found.
 */
int vector_search(const cvector* vector, ctofu target);

/**
 * @brief Reverses the order of elements in a cvector.
 *
 * @param vector The cvector to be reversed.
 */
void vector_reverse(cvector* vector);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Checks if a cvector is a nullptr.
 *
 * @param vector The cvector to check.
 * @return true if the cvector is a nullptr, false otherwise.
 */
bool vector_is_cnullptr(const cvector* vector);

/**
 * @brief Checks if a cvector is not a nullptr.
 *
 * @param vector The cvector to check.
 * @return true if the cvector is not a nullptr, false otherwise.
 */
bool vector_not_cnullptr(const cvector* vector);

/**
 * @brief Checks if a cvector is empty.
 *
 * @param vector The cvector to check.
 * @return true if the cvector is empty, false otherwise.
 */
bool vector_is_empty(const cvector* vector);

/**
 * @brief Checks if a cvector is not empty.
 *
 * @param vector The cvector to check.
 * @return true if the cvector is not empty, false otherwise.
 */
bool vector_not_empty(const cvector* vector);

/**
 * @brief Sets the element at a specific index in a cvector.
 *
 * @param vector The cvector to modify.
 * @param index The index at which to set the element.
 * @param element The ctofu element to set.
 */
void vector_setter(cvector* vector, size_t index, ctofu element);

/**
 * @brief Gets the element at a specific index in a cvector.
 *
 * @param vector The cvector to access.
 * @param index The index of the element to retrieve.
 * @return The ctofu element at the specified index.
 */
ctofu vector_getter(const cvector* vector, size_t index);

/**
 * @brief Gets the size of a cvector.
 *
 * @param vector The cvector to get the size of.
 * @return The size of the cvector.
 */
size_t vector_size(const cvector* vector);

/**
 * @brief Prints the elements of a cvector.
 *
 * @param vector The cvector to print.
 */
void vector_peek(const cvector* vector);

#ifdef __cplusplus
}
#endif

#endif
