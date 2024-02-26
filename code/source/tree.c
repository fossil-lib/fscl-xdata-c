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
#include "fossil/xdata/tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================
ctree* fscl_tree_create(ctofu_type tree) {
    ctree* new_tree = (ctree*)malloc(sizeof(ctree));
    if (new_tree == NULL) {
        // Handle memory allocation failure
        return NULL;
    }

    new_tree->root = NULL;
    new_tree->tree = tree;

    return new_tree;
}

// Helper function to recursively erase nodes
void fscl_tree_erase_recursive(ctree_node* node) {
    if (node == NULL) {
        return;
    }

    fscl_tree_erase_recursive(node->left);
    fscl_tree_erase_recursive(node->right);

    free(node);
}

void fscl_tree_erase(ctree* tree) {
    if (tree == NULL) {
        return;
    }

    // Recursively erase nodes starting from the root
    fscl_tree_erase_recursive(tree->root);

    free(tree);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

// Helper function to find the minimum node in a subtree
ctree_node* fscl_tree_find_min(ctree_node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Helper function to recursively remove a node
ctofu_error fscl_tree_remove_recursive(ctree_node** root, ctofu data) {
    if (*root == NULL) {
        return fscl_tofu_error(TOFU_NOT_FOUND); // Element not found
    }

    int compare_result = fscl_tofu_compare(&data, &(*root)->data);

    if (compare_result < 0) {
        return fscl_tree_remove_recursive(&(*root)->left, data);
    } else if (compare_result > 0) {
        return fscl_tree_remove_recursive(&(*root)->right, data);
    } else {
        // Node with the key found

        // Case 1: Node with only one child or no child
        if ((*root)->left == NULL) {
            ctree_node* temp = *root;
            *root = (*root)->right;
            free(temp);
        } else if ((*root)->right == NULL) {
            ctree_node* temp = *root;
            *root = (*root)->left;
            free(temp);
        } else {
            // Case 3: Node with two children
            ctree_node* temp = fscl_tree_find_min((*root)->right);
            (*root)->data = temp->data;
            return fscl_tree_remove_recursive(&(*root)->right, temp->data);
        }

        return fscl_tofu_error(TOFU_SUCCESS);
    }
}

// Helper function to recursively insert a node
ctofu_error fscl_tree_insert_recursive(ctree_node** root, ctofu* data) {
    if (root == NULL || data == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    if (*root == NULL) {
        *root = (ctree_node*)malloc(sizeof(ctree_node));
        if (*root == NULL) {
            return fscl_tofu_error(TOFU_WAS_BAD_MALLOC);  // Handle memory allocation failure
        }

        (*root)->data = *data;
        (*root)->left = NULL;
        (*root)->right = NULL;

        return fscl_tofu_error(TOFU_SUCCESS);
    }

    int compare_result;
    ctofu_error comparison_error = fscl_tofu_compare(data, &(*root)->data);
    if (comparison_error != TOFU_SUCCESS) {
        return comparison_error;
    }

    if (compare_result < 0) {
        return fscl_tree_insert_recursive(&(*root)->left, data);
    } else if (compare_result > 0) {
        return fscl_tree_insert_recursive(&(*root)->right, data);
    } else {
        return fscl_tofu_error(TOFU_DUPLICATE_ELEMENT);  // Duplicate element
    }
}

ctofu_error fscl_tree_insert(ctree* tree, ctofu data) {
    if (tree == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    return fscl_tree_insert_recursive(&tree->root, &data);
}

ctofu_error fscl_tree_remove(ctree* tree, ctofu data) {
    if (tree == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    return fscl_tree_remove_recursive(&tree->root, data);
}

// Helper function to recursively search for a node
ctofu_error fscl_tree_search_recursive(ctree_node* root, ctofu data) {
    if (root == NULL) {
        return fscl_tofu_error(TOFU_NOT_FOUND); // Element not found
    }

    int compare_result = fscl_tofu_compare(&data, &root->data);

    if (compare_result == 0) {
        return fscl_tofu_error(TOFU_SUCCESS); // Element found
    } else if (compare_result < 0) {
        return fscl_tree_search_recursive(root->left, data);
    } else {
        return fscl_tree_search_recursive(root->right, data);
    }
}

ctofu_error fscl_tree_search(const ctree* tree, ctofu data) {
    if (tree == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    return fscl_tree_search_recursive(tree->root, data);
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t fscl_tree_size_recursive(ctree_node* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + fscl_tree_size_recursive(root->left) + fscl_tree_size_recursive(root->right);
}

size_t fscl_tree_size(const ctree* tree) {
    if (tree == NULL) {
        return 0;
    }

    return fscl_tree_size_recursive(tree->root);
}

// Helper function to recursively get a pointer to a node's data
ctofu* fscl_tree_getter_recursive(ctree_node* root, ctofu data) {
    if (root == NULL) {
        return NULL;
    }

    int compare_result = fscl_tofu_compare(&data, &root->data);

    if (compare_result == 0) {
        return (ctofu*)&root->data;
    } else if (compare_result < 0) {
        return fscl_tree_getter_recursive(root->left, data);
    } else {
        return fscl_tree_getter_recursive(root->right, data);
    }
}

ctofu* fscl_tree_getter(const ctree* tree, ctofu data) {
    if (tree == NULL) {
        return NULL;
    }

    return fscl_tree_getter_recursive(tree->root, data);
}

// Helper function to recursively set the data of a node
ctofu_error fscl_tree_setter_recursive(ctree_node* root, ctofu data) {
    if (root == NULL) {
        return fscl_tofu_error(TOFU_NOT_FOUND); // Element not found
    }

    int compare_result = fscl_tofu_compare(&data, &root->data);
    
    if (compare_result == 0) {
        root->data = data; // Update the element
        return fscl_tofu_error(TOFU_SUCCESS);
    } else if (compare_result < 0) {
        return fscl_tree_setter_recursive(root->left, data);
    } else {
        return fscl_tree_setter_recursive(root->right, data);
    }
}

ctofu_error fscl_tree_setter(ctree* tree, ctofu data) {
    if (tree == NULL) {
        return fscl_tofu_error(TOFU_WAS_NULLPTR);
    }

    return fscl_tree_setter_recursive(tree->root, data);
}

bool fscl_tree_not_empty(const ctree* tree) {
    return tree != NULL && tree->root != NULL;
}

bool fscl_tree_not_cnullptr(const ctree* tree) {
    return tree != NULL;
}

bool fscl_tree_is_empty(const ctree* tree) {
    return tree == NULL || tree->root == NULL;
}

bool fscl_tree_is_cnullptr(const ctree* tree) {
    return tree == NULL;
}

// Helper function to recursively check if the tree contains an element
bool fscl_tree_contains_recursive(ctree_node* root, ctofu data) {
    if (root == NULL) {
        return false;
    }

    int compare_result = fscl_tofu_compare(&data, &root->data);

    if (compare_result == 0) {
        return true; // Element found
    } else if (compare_result < 0) {
        return fscl_tree_contains_recursive(root->left, data);
    } else {
        return fscl_tree_contains_recursive(root->right, data);
    }
}

bool fscl_tree_contains(const ctree* tree, ctofu data) {
    if (tree == NULL) {
        return false;
    }

    return fscl_tree_contains_recursive(tree->root, data);
}
