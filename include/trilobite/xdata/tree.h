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
typedef struct TriloTreeNode {
    TriloTofu data;
    struct TriloTreeNode* left;
    struct TriloTreeNode* right;
} TriloTreeNode;

// Tree structure
typedef struct TriloTree {
    TriloTreeNode* root;
    enum DataType tree_type;  // Type of the tree
} TriloTree;

// =======================
// CREATE and DELETE
// =======================

/**
 * @brief Creates a new TriloTree instance with the specified list type.
 *
 * @param list_type The data type for the TriloTree (e.g., INTEGER_TYPE, DOUBLE_TYPE).
 * @return A pointer to the newly created TriloTree instance.
 */
TriloTree* trilo_xdata_tree_create(enum DataType list_type);

/**
 * @brief Destroys the TriloTree instance, freeing all associated memory.
 *
 * @param tree The TriloTree instance to be destroyed.
 */
void trilo_xdata_tree_destroy(TriloTree* tree);

// =======================
// ALGORITHM FUNCTIONS
// =======================

/**
 * @brief Inserts a TriloTofu data element into the TriloTree.
 *
 * @param tree The TriloTree where the data will be inserted.
 * @param data The TriloTofu data element to be inserted.
 * @return A TofuError value indicating the result of the insertion.
 */
TofuError trilo_xdata_tree_insert(TriloTree* tree, TriloTofu data);

/**
 * @brief Removes a TriloTofu data element from the TriloTree.
 *
 * @param tree The TriloTree from which the data will be removed.
 * @param data The TriloTofu data element to be removed.
 * @return A TofuError value indicating the result of the removal.
 */
TofuError trilo_xdata_tree_remove(TriloTree* tree, TriloTofu data);

/**
 * @brief Searches for a TriloTofu data element in the TriloTree.
 *
 * @param tree The TriloTree to search within.
 * @param data The TriloTofu data element to search for.
 * @return A TofuError value indicating the result of the search.
 */
TofuError trilo_xdata_tree_search(const TriloTree* tree, TriloTofu data);

// =======================
// UTILITY FUNCTIONS
// =======================

/**
 * @brief Gets the size of the TriloTree.
 *
 * @param tree The TriloTree for which the size will be determined.
 * @return The size of the TriloTree.
 */
size_t trilo_xdata_tree_size(const TriloTree* tree);

/**
 * @brief Getter function to retrieve a TriloTofu data element from the TriloTree.
 *
 * @param tree The TriloTree from which the data will be retrieved.
 * @param data The TriloTofu data element to retrieve.
 * @return A pointer to the TriloTofu data element in the TriloTree (or NULL if not found).
 */
TriloTofu* trilo_xdata_tree_getter(const TriloTree* tree, TriloTofu data);

/**
 * @brief Setter function to update a TriloTofu data element in the TriloTree.
 *
 * @param tree The TriloTree in which the data will be updated.
 * @param data The TriloTofu data element to update.
 * @return A TofuError value indicating the result of the update.
 */
TofuError trilo_xdata_tree_setter(TriloTree* tree, TriloTofu data);

/**
 * @brief Checks if the TriloTree is not empty.
 *
 * @param tree The TriloTree to check.
 * @return true if the TriloTree is not empty, false otherwise.
 */
bool trilo_xdata_tree_not_empty(const TriloTree* tree);

/**
 * @brief Checks if the TriloTree is not a null pointer.
 *
 * @param tree The TriloTree to check.
 * @return true if the TriloTree is not a null pointer, false otherwise.
 */
bool trilo_xdata_tree_not_nullptr(const TriloTree* tree);

/**
 * @brief Checks if the TriloTree is empty.
 *
 * @param tree The TriloTree to check.
 * @return true if the TriloTree is empty, false otherwise.
 */
bool trilo_xdata_tree_is_empty(const TriloTree* tree);

/**
 * @brief Checks if the TriloTree is a null pointer.
 *
 * @param tree The TriloTree to check.
 * @return true if the TriloTree is a null pointer, false otherwise.
 */
bool trilo_xdata_tree_is_nullptr(const TriloTree* tree);

/**
 * @brief Checks if a TriloTofu data element is present in the TriloTree.
 *
 * @param tree The TriloTree to check.
 * @param data The TriloTofu data element to search for.
 * @return true if the data element is present, false otherwise.
 */
bool trilo_xdata_tree_contains(const TriloTree* tree, TriloTofu data);

#ifdef __cplusplus
}
#endif

#endif
