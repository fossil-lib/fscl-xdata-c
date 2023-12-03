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
#ifndef TRILOBITE_XDATA_TREE_H
#define TRILOBITE_XDATA_TREE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "trilobite/xdata/tofu.h"

// Node structure for the binary search tree
typedef struct ctree_node {
    ctofu data;
    struct ctree_node* left;
    struct ctree_node* right;
} ctree_node;

// Tree structure
typedef struct ctree {
    ctree_node* root;
    enum ctofu_type tree_type;  // Type of the tree
} ctree;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new ctree instance with the specified list type.
 *
 * @param list_type The data type for the ctree (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created ctree instance.
 */
ctree* trilo_xdata_tree_create(enum ctofu_type list_type);

/**
 * @brief Destroys the ctree instance, freeing all associated memory.
 *
 * @param tree The ctree instance to be destroyed.
 */
void trilo_xdata_tree_destroy(ctree* tree);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a ctofu data element into the ctree.
 *
 * @param tree The ctree where the data will be inserted.
 * @param data The ctofu data element to be inserted.
 * @return A ctofu_error value indicating the result of the insertion.
 */
ctofu_error trilo_xdata_tree_insert(ctree* tree, ctofu data);

/**
 * @brief Removes a ctofu data element from the ctree.
 *
 * @param tree The ctree from which the data will be removed.
 * @param data The ctofu data element to be removed.
 * @return A ctofu_error value indicating the result of the removal.
 */
ctofu_error trilo_xdata_tree_remove(ctree* tree, ctofu data);

/**
 * @brief Searches for a ctofu data element in the ctree.
 *
 * @param tree The ctree to search within.
 * @param data The ctofu data element to search for.
 * @return A ctofu_error value indicating the result of the search.
 */
ctofu_error trilo_xdata_tree_search(const ctree* tree, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the ctree.
 *
 * @param tree The ctree for which the size will be determined.
 * @return The size of the ctree.
 */
size_t trilo_xdata_tree_size(const ctree* tree);

/**
 * @brief Getter function to retrieve a ctofu data element from the ctree.
 *
 * @param tree The ctree from which the data will be retrieved.
 * @param data The ctofu data element to retrieve.
 * @return A pointer to the ctofu data element in the ctree (or NULL if not found).
 */
ctofu* trilo_xdata_tree_getter(const ctree* tree, ctofu data);

/**
 * @brief Setter function to update a ctofu data element in the ctree.
 *
 * @param tree The ctree in which the data will be updated.
 * @param data The ctofu data element to update.
 * @return A ctofu_error value indicating the result of the update.
 */
ctofu_error trilo_xdata_tree_setter(ctree* tree, ctofu data);

/**
 * @brief Checks if the ctree is not empty.
 *
 * @param tree The ctree to check.
 * @return true if the ctree is not empty, false otherwise.
 */
bool trilo_xdata_tree_not_empty(const ctree* tree);

/**
 * @brief Checks if the ctree is not a null pointer.
 *
 * @param tree The ctree to check.
 * @return true if the ctree is not a null pointer, false otherwise.
 */
bool trilo_xdata_tree_not_nullptr(const ctree* tree);

/**
 * @brief Checks if the ctree is empty.
 *
 * @param tree The ctree to check.
 * @return true if the ctree is empty, false otherwise.
 */
bool trilo_xdata_tree_is_empty(const ctree* tree);

/**
 * @brief Checks if the ctree is a null pointer.
 *
 * @param tree The ctree to check.
 * @return true if the ctree is a null pointer, false otherwise.
 */
bool trilo_xdata_tree_is_nullptr(const ctree* tree);

/**
 * @brief Checks if a ctofu data element is present in the ctree.
 *
 * @param tree The ctree to check.
 * @param data The ctofu data element to search for.
 * @return true if the data element is present, false otherwise.
 */
bool trilo_xdata_tree_contains(const ctree* tree, ctofu data);

#ifdef __cplusplus
}
#endif

#endif
