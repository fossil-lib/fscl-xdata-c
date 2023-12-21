/*  ----------------------------------------------------------------------------
    File: tree.c

    Description:
    This source file contains the code entry point for the Trilobite Stdlib project.
    It demonstrates the usage of various utilities and functions provided by the
    Trilobite Stdlib to enhance software development.

    Author: Michael Gene Brockus (Dreamer)
    Email: michaelbrockus@gmail.com
    Website: [Trilobite Coder Blog](https://trilobite.home.blog)

    Project: Trilobite Stdlib

    License: Apache License 2.0
    SPDX Identifier: Apache-2.0

    Licensed under the Apache License, Version 2.0 (the "License");
    you may not use this file except in compliance with the License.
    You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0.

    Unless required by applicable law or agreed to in writing, software distributed under the License
    is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
    or implied. See the License for the specific language governing permissions and limitations
    under the License.

    Please review the full text of the Apache License 2.0 for the complete terms and conditions.

    (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
    ----------------------------------------------------------------------------
*/
#include "trilobite/xdata/tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================
ctree* tree_create(ctofu_type tree) {
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
void tree_erase_recursive(ctree_node* node) {
    if (node == NULL) {
        return;
    }

    tree_erase_recursive(node->left);
    tree_erase_recursive(node->right);

    free(node);
}

void tree_erase(ctree* tree) {
    if (tree == NULL) {
        return;
    }

    // Recursively erase nodes starting from the root
    tree_erase_recursive(tree->root);

    free(tree);
}

// =======================
// ALGORITHM FUNCTIONS
// =======================

// Helper function to recursively insert a node
ctofu_error tree_insert_recursive(ctree_node** root, ctofu data) {
    if (*root == NULL) {
        *root = (ctree_node*)malloc(sizeof(ctree_node));
        if (*root == NULL) {
            // Handle memory allocation failure
            return TOFU_WAS_BAD_MALLOC;
        }

        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;

        return TOFU_SUCCESS;
    }

    int compare_result;
    ctofu_error comparison_error = tofu_compare(&data, &(*root)->data, &compare_result);
    if (comparison_error != TOFU_SUCCESS) {
        return comparison_error;
    }

    if (compare_result < 0) {
        return tree_insert_recursive(&(*root)->left, data);
    } else if (compare_result > 0) {
        return tree_insert_recursive(&(*root)->right, data);
    } else {
        return TOFU_WAS_MISMATCH; // Duplicate element
    }
}

ctofu_error tree_insert(ctree* tree, ctofu data) {
    if (tree == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    return tree_insert_recursive(&tree->root, data);
}

// Helper function to find the minimum node in a subtree
ctree_node* tree_find_min(ctree_node* node) {
    while (node->left != NULL) {
        node = node->left;
    }
    return node;
}

// Helper function to recursively remove a node
ctofu_error tree_remove_recursive(ctree_node** root, ctofu data) {
    if (*root == NULL) {
        return TOFU_NOT_FOUND; // Element not found
    }

    int compare_result;
    ctofu_error comparison_error = tofu_compare(&data, &(*root)->data, &compare_result);
    if (comparison_error != TOFU_SUCCESS) {
        return comparison_error;
    }

    if (compare_result < 0) {
        return tree_remove_recursive(&(*root)->left, data);
    } else if (compare_result > 0) {
        return tree_remove_recursive(&(*root)->right, data);
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
            ctree_node* temp = tree_find_min((*root)->right);
            (*root)->data = temp->data;
            return tree_remove_recursive(&(*root)->right, temp->data);
        }

        return TOFU_SUCCESS;
    }
}

ctofu_error tree_remove(ctree* tree, ctofu data) {
    if (tree == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    return tree_remove_recursive(&tree->root, data);
}

// Helper function to recursively search for a node
ctofu_error tree_search_recursive(const ctree_node* root, ctofu data) {
    if (root == NULL) {
        return TOFU_NOT_FOUND; // Element not found
    }

    int compare_result;
    ctofu_error comparison_error = tofu_compare(&data, &root->data, &compare_result);
    if (comparison_error != TOFU_SUCCESS) {
        return comparison_error;
    }

    if (compare_result == 0) {
        return TOFU_SUCCESS; // Element found
    } else if (compare_result < 0) {
        return tree_search_recursive(root->left, data);
    } else {
        return tree_search_recursive(root->right, data);
    }
}

ctofu_error tree_search(const ctree* tree, ctofu data) {
    if (tree == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    return tree_search_recursive(tree->root, data);
}

// =======================
// UTILITY FUNCTIONS
// =======================

size_t tree_size_recursive(const ctree_node* root) {
    if (root == NULL) {
        return 0;
    }

    return 1 + tree_size_recursive(root->left) + tree_size_recursive(root->right);
}

size_t tree_size(const ctree* tree) {
    if (tree == NULL) {
        return 0;
    }

    return tree_size_recursive(tree->root);
}

// Helper function to recursively get a pointer to a node's data
ctofu* tree_getter_recursive(const ctree_node* root, ctofu data) {
    if (root == NULL) {
        return NULL;
    }

    int compare_result;
    ctofu_error comparison_error = tofu_compare(&data, &root->data, &compare_result);
    if (comparison_error != TOFU_SUCCESS) {
        return NULL;
    }

    if (compare_result == 0) {
        return (ctofu*)&root->data;
    } else if (compare_result < 0) {
        return tree_getter_recursive(root->left, data);
    } else {
        return tree_getter_recursive(root->right, data);
    }
}

ctofu* tree_getter(const ctree* tree, ctofu data) {
    if (tree == NULL) {
        return NULL;
    }

    return tree_getter_recursive(tree->root, data);
}

// Helper function to recursively set the data of a node
ctofu_error tree_setter_recursive(ctree_node* root, ctofu data) {
    if (root == NULL) {
        return TOFU_NOT_FOUND; // Element not found
    }

    int compare_result;
    ctofu_error comparison_error = tofu_compare(&data, &root->data, &compare_result);
    if (comparison_error != TOFU_SUCCESS) {
        return comparison_error;
    }

    if (compare_result == 0) {
        root->data = data; // Update the element
        return TOFU_SUCCESS;
    } else if (compare_result < 0) {
        return tree_setter_recursive(root->left, data);
    } else {
        return tree_setter_recursive(root->right, data);
    }
}

ctofu_error tree_setter(ctree* tree, ctofu data) {
    if (tree == NULL) {
        return TOFU_WAS_NULLPTR;
    }

    return tree_setter_recursive(tree->root, data);
}

bool tree_not_empty(const ctree* tree) {
    return tree != NULL && tree->root != NULL;
}

bool tree_not_cnullptr(const ctree* tree) {
    return tree != NULL;
}

bool tree_is_empty(const ctree* tree) {
    return tree == NULL || tree->root == NULL;
}

bool tree_is_cnullptr(const ctree* tree) {
    return tree == NULL;
}

bool tree_contains_recursive(const ctree_node* root, ctofu data) {
    if (root == NULL) {
        return false;
    }

    int compare_result;
    ctofu_error comparison_error = tofu_compare(&data, &root->data, &compare_result);
    if (comparison_error != TOFU_SUCCESS) {
        return false;
    }

    if (compare_result == 0) {
        return true; // Element found
    } else if (compare_result < 0) {
        return tree_contains_recursive(root->left, data);
    } else {
        return tree_contains_recursive(root->right, data);
    }
}

bool tree_contains(const ctree* tree, ctofu data) {
    if (tree == NULL) {
        return false;
    }

    return tree_contains_recursive(tree->root, data);
}
