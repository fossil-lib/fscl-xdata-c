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

// Function to create a new ctree
ctree* tree_create(enum ctofu_type tree_type) {
    ctree* tree = (ctree*)malloc(sizeof(ctree));
    if (tree != NULL) {
        tree->root = NULL;
        tree->tree_type = tree_type;
    } // end if
    return tree;
} // end of func

// Helper function to destroy the tree recursively
void tree_erase_recursive(ctree_node* node) {
    if (node == NULL) {
        return;
    } // end if

    tree_erase_recursive(node->left);
    tree_erase_recursive(node->right);
    free(node);
} // end of func

// Function to destroy the ctree
void tree_erase(ctree* tree) {
    if (tree != NULL) {
        tree_erase_recursive(tree->root);
        free(tree);
    } // end if
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================

// Function to insert a ctofu data into the tree
ctofu_error tree_insert(ctree* tree, ctofu data) {
    if (tree == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    ctree_node* newNode = (ctree_node*)malloc(sizeof(ctree_node));
    if (newNode == NULL) {
        return TRILO_XDATA_TYPE_WAS_BAD_MALLOC;
    } // end if

    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    // If the tree is empty, set the new node as the root
    if (tree->root == NULL) {
        tree->root = newNode;
        return TRILO_XDATA_TYPE_SUCCESS;
    } // end if

    // Otherwise, insert the new node into the tree
    ctree_node* current = tree->root;
    while (1) {
        ctofu_error compareResult = tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            free(newNode); // Data already exists, don't insert it again
            return TRILO_XDATA_TYPE_SUCCESS;
        } else if (compareResult == TRILO_XDATA_TYPE_WAS_MISMATCH) {
            // Determine whether to go left or right based on the comparison result
            compareResult = tofu_compare(data, current->data);

            if (compareResult == TRILO_XDATA_TYPE_WAS_MISMATCH) {
                // Data with the same value already exists, don't insert it again
                free(newNode);
                return TRILO_XDATA_TYPE_SUCCESS;
            } else if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
                // Insert as left child
                if (current->left == NULL) {
                    current->left = newNode;
                    return TRILO_XDATA_TYPE_SUCCESS;
                }
                current = current->left;
            } else {
                // Insert as right child
                if (current->right == NULL) {
                    current->right = newNode;
                    return TRILO_XDATA_TYPE_SUCCESS;
                }
                current = current->right;
            }
        } else {
            free(newNode); // Invalid comparison result, don't insert the data
            return TRILO_XDATA_TYPE_WAS_UNKNOWN;
        } // end if else
    } // end while
} // end of func

// Function to remove a ctofu data from the tree
ctofu_error tree_remove(ctree* tree, ctofu data) {
    if (tree == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (tree->root == NULL) {
        return TRILO_XDATA_TYPE_SUCCESS; // Empty tree, nothing to remove
    } // end if

    ctree_node* current = tree->root;
    ctree_node* parent = NULL;
    ctofu_error compareResult;

    while (current != NULL) {
        compareResult = tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            // Node with the matching data found, perform removal
            if (parent == NULL) {
                // If the node to be removed is the root
                if (current->left == NULL && current->right == NULL) {
                    free(current);
                    tree->root = NULL;
                    return TRILO_XDATA_TYPE_SUCCESS;
                } else if (current->left == NULL) {
                    ctree_node* temp = current->right;
                    free(current);
                    tree->root = temp;
                    return TRILO_XDATA_TYPE_SUCCESS;
                } else if (current->right == NULL) {
                    ctree_node* temp = current->left;
                    free(current);
                    tree->root = temp;
                    return TRILO_XDATA_TYPE_SUCCESS;
                } else {
                    ctree_node* minRight = current->right;
                    while (minRight->left != NULL) {
                        minRight = minRight->left;
                    }
                    current->data = minRight->data;
                    data = minRight->data;
                    current = current->right;
                }
            } else {
                // If the node to be removed is not the root
                if (current->left == NULL && current->right == NULL) {
                    free(current);
                    if (parent->left == current) {
                        parent->left = NULL;
                    } else {
                        parent->right = NULL;
                    }
                    return TRILO_XDATA_TYPE_SUCCESS;
                } else if (current->left == NULL) {
                    ctree_node* temp = current->right;
                    free(current);
                    if (parent->left == current) {
                        parent->left = temp;
                    } else {
                        parent->right = temp;
                    }
                    return TRILO_XDATA_TYPE_SUCCESS;
                } else if (current->right == NULL) {
                    ctree_node* temp = current->left;
                    free(current);
                    if (parent->left == current) {
                        parent->left = temp;
                    } else {
                        parent->right = temp;
                    }
                    return TRILO_XDATA_TYPE_SUCCESS;
                } else {
                    ctree_node* minRight = current->right;
                    while (minRight->left != NULL) {
                        minRight = minRight->left;
                    }
                    current->data = minRight->data;
                    data = minRight->data;
                    current = current->right;
                    parent = current;
                }
            }
        } else if (compareResult == TRILO_XDATA_TYPE_WAS_MISMATCH) {
            // Determine whether to go left or right based on the comparison result
            compareResult = tofu_compare(data, current->data);

            if (compareResult == TRILO_XDATA_TYPE_WAS_MISMATCH) {
                // Data not found in the tree
                return TRILO_XDATA_TYPE_SUCCESS;
            } else if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
                parent = current;
                current = current->left;
            } else {
                parent = current;
                current = current->right;
            }
        } else {
            return TRILO_XDATA_TYPE_WAS_UNKNOWN; // Invalid comparison result
        } // end if else if's
    } // end while

    return TRILO_XDATA_TYPE_WAS_UNKNOWN; // Data not found in the tree
} // end of func

// Function to search for a ctofu data in the tree
ctofu_error tree_search(const ctree* tree, ctofu data) {
    if (tree == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    ctree_node* current = tree->root;
    ctofu_error compareResult;

    while (current != NULL) {
        compareResult = tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            // Data found in the tree
            return TRILO_XDATA_TYPE_SUCCESS;
        } else if (compareResult == TRILO_XDATA_TYPE_WAS_MISMATCH) {
            // Determine whether to go left or right based on the comparison result
            compareResult = tofu_compare(data, current->data);

            if (compareResult == TRILO_XDATA_TYPE_WAS_MISMATCH) {
                // Data not found in the tree
                return TRILO_XDATA_TYPE_SUCCESS;
            } else if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
                current = current->left;
            } else {
                current = current->right;
            } // end if else if's
        } else {
            return TRILO_XDATA_TYPE_WAS_UNKNOWN; // Invalid comparison result
        } // end if else
    } // end while

    return TRILO_XDATA_TYPE_WAS_UNKNOWN; // Data not found in the tree
} // end of func

// =======================
// UTILITY FUNCTIONS
// =======================

// Helper function to count nodes in the tree
static void count_nodes(const ctree_node* node, size_t* count) {
    if (node != NULL) {
        (*count)++;
        count_nodes(node->left, count);
        count_nodes(node->right, count);
    } // end if
} // end of func

// Function to get the size of the ctree
size_t tree_size(const ctree* tree) {
    if (tree == NULL || tree->root == NULL) {
        return 0;
    } // end if

    size_t count = 0;
    count_nodes(tree->root, &count);
    return count;
} // end of func

// Function to insert a ctofu data into the tree
ctofu* tree_getter(const ctree* tree, ctofu data) {
    if (tree == NULL) {
        return NULL;
    } // end if

    ctree_node* current = tree->root;
    ctofu_error compareResult;

    while (current != NULL) {
        compareResult = tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            // Data found in the tree, return a pointer to it
            return &(current->data);
        } else if (compareResult == TRILO_XDATA_TYPE_WAS_MISMATCH) {
            // Determine whether to go left or right based on the comparison result
            compareResult = tofu_compare(data, current->data);

            if (compareResult == TRILO_XDATA_TYPE_WAS_MISMATCH) {
                // Data not found in the tree
                return NULL;
            } else if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
                current = current->left;
            } else {
                current = current->right;
            }
        } else {
            return NULL; // Invalid comparison result
        } // end if else's
    } // end while

    return NULL; // Data not found in the tree
} // end of func

// Function to insert a ctofu data into the tree
ctofu_error tree_setter(ctree* tree, ctofu data) {
    ctofu* existingData = tree_getter(tree, data);

    if (existingData != NULL) {
        // Data with the same value already exists, don't insert it again
        return TRILO_XDATA_TYPE_SUCCESS;
    } // end if

    return tree_insert(tree, data);
} // end of func

// Function to check if the tree is empty
bool tree_not_empty(const ctree* tree) {
    return tree != NULL && tree->root != NULL;
} // end of func

// Function to check if the tree is not null
bool tree_not_cnullptr(const ctree* tree) {
    return tree != NULL;
} // end of func

// Function to check if the tree is empty
bool tree_is_empty(const ctree* tree) {
    return tree == NULL || tree->root == NULL;
} // end of func

// Function to check if the tree is null
bool tree_is_cnullptr(const ctree* tree) {
    return tree == NULL;
} // end of func

// Function to check if a ctofu data is in the tree
bool tree_contains(const ctree* tree, ctofu data) {
    return tree_getter(tree, data) != NULL;
} // end of func
