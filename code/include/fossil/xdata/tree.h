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

#include "fossil/xtofu/core.h"

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
ctree* fscl_tree_create(ctofu_type tree);
void fscl_tree_erase(ctree* tree);

// =======================
// ALGORITHM FUNCTIONS
// =======================
ctofu_error fscl_tree_insert(ctree* tree, ctofu data);
ctofu_error fscl_tree_remove(ctree* tree, ctofu data);
ctofu_error fscl_tree_search(const ctree* tree, ctofu data);

// =======================
// UTILITY FUNCTIONS
// =======================
size_t fscl_tree_size(const ctree* tree);
ctofu* fscl_tree_getter(const ctree* tree, ctofu data);
ctofu_error fscl_tree_setter(ctree* tree, ctofu data);
bool fscl_tree_not_empty(const ctree* tree);
bool fscl_tree_not_cnullptr(const ctree* tree);
bool fscl_tree_is_empty(const ctree* tree);
bool fscl_tree_is_cnullptr(const ctree* tree);
bool fscl_tree_contains(const ctree* tree, ctofu data);

#ifdef __cplusplus
}
#endif

#endif
