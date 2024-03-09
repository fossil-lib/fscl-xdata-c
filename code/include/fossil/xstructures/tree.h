/*
==============================================================================
Author: Michael Gene Brockus (Dreamer)
Email: michaelbrockus@gmail.com
Organization: Fossil Logic
Description: 
    This file is part of the Fossil Logic project, where innovation meets
    excellence in software development. Michael Gene Brockus, also known as
    "Dreamer," is a dedicated contributor to this project. For any inquiries,
    feel free to contact Michael at michaelbrockus@gmail.com.
==============================================================================
*/
#ifndef fscl_tree_H
#define fscl_tree_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "fossil/xtofu.h"

// Node structure for the binary search tree
typedef struct ctree_node {
    ctofu data;
    struct ctree_node* left;
    struct ctree_node* right;
} ctree_node;

// Tree structure
typedef struct {
    ctree_node* root;
    ctofu_type tree; // Type of the tree
} ctree;

// =======================
// CREATE and DELETE
// =======================
/**
 * Create a new tree with the specified data type.
 *
 * @param tree The type of data the tree will store.
 * @return     The created tree.
 */
ctree* fscl_tree_create(ctofu_type tree);

/**
 * Erase the contents of the tree and free allocated memory.
 *
 * @param tree The tree to erase.
 */
void fscl_tree_erase(ctree* tree);

// =======================
// ALGORITHM FUNCTIONS
// =======================
/**
 * Insert data into the tree.
 *
 * @param tree The tree to insert data into.
 * @param data The data to insert.
 * @return     The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tree_insert(ctree* tree, ctofu data);

/**
 * Remove data from the tree.
 *
 * @param tree The tree to remove data from.
 * @param data The data to remove.
 * @return     The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tree_remove(ctree* tree, ctofu data);

/**
 * Search for data in the tree.
 *
 * @param tree The tree to search.
 * @param data The data to search for.
 * @return     The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tree_search(const ctree* tree, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================
/**
 * Get the size of the tree.
 *
 * @param tree The tree for which to get the size.
 * @return     The size of the tree.
 */
size_t fscl_tree_size(const ctree* tree);

/**
 * Get the data from the tree matching the specified data.
 *
 * @param tree The tree from which to get the data.
 * @param data The data to search for.
 * @return     A pointer to the matching data, or NULL if not found.
 */
ctofu* fscl_tree_getter(const ctree* tree, ctofu data);

/**
 * Set data in the tree.
 *
 * @param tree The tree in which to set the data.
 * @param data The data to set.
 * @return     The error code indicating the success or failure of the operation.
 */
ctofu_error fscl_tree_setter(ctree* tree, ctofu data);

/**
 * Check if the tree is not empty.
 *
 * @param tree The tree to check.
 * @return     True if the tree is not empty, false otherwise.
 */
bool fscl_tree_not_empty(const ctree* tree);

/**
 * Check if the tree is not a null pointer.
 *
 * @param tree The tree to check.
 * @return     True if the tree is not a null pointer, false otherwise.
 */
bool fscl_tree_not_cnullptr(const ctree* tree);

/**
 * Check if the tree is empty.
 *
 * @param tree The tree to check.
 * @return     True if the tree is empty, false otherwise.
 */
bool fscl_tree_is_empty(const ctree* tree);

/**
 * Check if the tree is a null pointer.
 *
 * @param tree The tree to check.
 * @return     True if the tree is a null pointer, false otherwise.
 */
bool fscl_tree_is_cnullptr(const ctree* tree);

/**
 * Check if the tree contains the specified data.
 *
 * @param tree The tree to check.
 * @param data The data to check for.
 * @return     True if the tree contains the data, false otherwise.
 */
bool fscl_tree_contains(const ctree* tree, ctofu data);

#ifdef __cplusplus
}
#endif

#endif
