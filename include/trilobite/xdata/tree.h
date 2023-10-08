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

// Define error constants for tuple operations
enum {
    TRILO_XDATA_TREE_TYPE_MISMATCH = -1,
    TRILO_XDATA_TREE_OUT_OF_RANGE  = -2
};

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

// Function to create a new TriloTree
TriloTree* trilo_xdata_tree_create(enum DataType tree_type);

// Function to destroy the TriloTree
void trilo_xdata_tree_destroy(TriloTree* tree);

// Function to check if the tree is empty
bool trilo_xdata_tree_is_empty(const TriloTree* tree);

// Function to insert a TriloTofu data into the tree
void trilo_xdata_tree_insert(TriloTree* tree, TriloTofu data);

// Function to remove a TriloTofu data from the tree
void trilo_xdata_tree_remove(TriloTree* tree, TriloTofu data);

// Function to search for a TriloTofu data in the tree
bool trilo_xdata_tree_search(const TriloTree* tree, TriloTofu data);

// Function to print the elements in the tree (in-order traversal)
void trilo_xdata_tree_print(const TriloTree* tree);

int trilo_xdata_tree_size(const TriloTree* tree);

#ifdef __cplusplus
}
#endif

#endif
