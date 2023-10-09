/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
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
TriloTofu* trilo_xdata_tree_getter(TriloTree* tree, TriloTofu data);

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
