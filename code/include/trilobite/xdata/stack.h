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
#ifndef TRILOBITE_XDATA_STACK_H
#define TRILOBITE_XDATA_STACK_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Stack structure
typedef struct cstack_node {
    ctofu data; // Data stored in the stack node
    struct cstack_node* next; // Pointer to the next node
} cstack_node;

typedef struct cstack {
    enum ctofu_type stack_type; // Type of the stack
    cstack_node* top; // Pointer to the top node of the stack
} cstack;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new cstack instance with the specified list type.
 *
 * @param list_type The data type for the cstack (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created cstack instance.
 */
cstack* stack_create(enum ctofu_type list_type);

/**
 * @brief Destroys the cstack instance, freeing all associated memory.
 *
 * @param stack The cstack instance to be destroyed.
 */
void stack_erase(cstack* stack);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a ctofu data element into the cstack.
 *
 * @param stack The cstack where the data will be inserted.
 * @param data  The ctofu data element to be inserted.
 * @return A ctofu_error value indicating the result of the insertion.
 */
ctofu_error stack_insert(cstack* stack, ctofu data);

/**
 * @brief Removes a ctofu data element from the cstack.
 *
 * @param stack The cstack from which the data will be removed.
 * @param data  The ctofu data element to be removed.
 * @return A ctofu_error value indicating the result of the removal.
 */
ctofu_error stack_remove(cstack* stack, ctofu data);

/**
 * @brief Searches for a ctofu data element in the cstack.
 *
 * @param stack The cstack to search within.
 * @param data  The ctofu data element to search for.
 * @return A ctofu_error value indicating the result of the search.
 */
ctofu_error stack_search(const cstack* stack, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the cstack.
 *
 * @param stack The cstack for which the size will be determined.
 * @return The size of the cstack.
 */
size_t stack_size(const cstack* stack);

/**
 * @brief Getter function to retrieve a ctofu data element from the cstack.
 *
 * @param stack The cstack from which the data will be retrieved.
 * @param data  The ctofu data element to retrieve.
 * @return A pointer to the ctofu data element in the cstack (or NULL if not found).
 */
ctofu* stack_getter(cstack* stack, ctofu data);

/**
 * @brief Setter function to update a ctofu data element in the cstack.
 *
 * @param stack The cstack in which the data will be updated.
 * @param data  The ctofu data element to update.
 * @return A ctofu_error value indicating the result of the update.
 */
ctofu_error stack_setter(cstack* stack, ctofu data);

/**
 * @brief Checks if the cstack is not empty.
 *
 * @param stack The cstack to check.
 * @return true if the cstack is not empty, false otherwise.
 */
bool stack_not_empty(const cstack* stack);

/**
 * @brief Checks if the cstack is not a null pointer.
 *
 * @param stack The cstack to check.
 * @return true if the cstack is not a null pointer, false otherwise.
 */
bool stack_not_cnullptr(const cstack* stack);

/**
 * @brief Checks if the cstack is empty.
 *
 * @param stack The cstack to check.
 * @return true if the cstack is empty, false otherwise.
 */
bool stack_is_empty(const cstack* stack);

/**
 * @brief Checks if the cstack is a null pointer.
 *
 * @param stack The cstack to check.
 * @return true if the cstack is a null pointer, false otherwise.
 */
bool stack_is_cnullptr(const cstack* stack);

/**
 * @brief Gets the top element of the stack without removing it.
 *
 * This function returns a copy of the top element of the stack without removing it.
 *
 * @param stack The cstack instance to get the top element from.
 * @return A copy of the top element of the stack.
 */
ctofu stack_top(cstack* stack);

#ifdef __cplusplus
}
#endif

#endif
