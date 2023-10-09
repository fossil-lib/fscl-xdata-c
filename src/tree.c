/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// =======================
// CREATE and DELETE
// =======================

// Function to create a new TriloTree
TriloTree* trilo_xdata_tree_create(enum DataType tree_type) {
    TriloTree* tree = (TriloTree*)malloc(sizeof(TriloTree));
    if (tree != NULL) {
        tree->root = NULL;
        tree->tree_type = tree_type;
    } // end if
    return tree;
} // end of func

// Helper function to destroy the tree recursively
void trilo_xdata_tree_destroy_recursive(TriloTreeNode* node) {
    if (node == NULL) {
        return;
    } // end if

    trilo_xdata_tree_destroy_recursive(node->left);
    trilo_xdata_tree_destroy_recursive(node->right);
    free(node);
} // end of func

// Function to destroy the TriloTree
void trilo_xdata_tree_destroy(TriloTree* tree) {
    if (tree != NULL) {
        trilo_xdata_tree_destroy_recursive(tree->root);
        free(tree);
    } // end if
} // end of func

// =======================
// ALGORITHM FUNCTIONS
// =======================

// Function to insert a TriloTofu data into the tree
TofuError trilo_xdata_tree_insert(TriloTree* tree, TriloTofu data) {
    if (tree == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloTreeNode* newNode = (TriloTreeNode*)malloc(sizeof(TriloTreeNode));
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
    TriloTreeNode* current = tree->root;
    while (1) {
        TofuError compareResult = trilo_xdata_tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            free(newNode); // Data already exists, don't insert it again
            return TRILO_XDATA_TYPE_SUCCESS;
        } else if (compareResult == TRILO_XDATA_TYPE_WAS_MISMATCH) {
            // Determine whether to go left or right based on the comparison result
            compareResult = trilo_xdata_tofu_compare(data, current->data);

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

// Function to remove a TriloTofu data from the tree
TofuError trilo_xdata_tree_remove(TriloTree* tree, TriloTofu data) {
    if (tree == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    if (tree->root == NULL) {
        return TRILO_XDATA_TYPE_SUCCESS; // Empty tree, nothing to remove
    } // end if

    TriloTreeNode* current = tree->root;
    TriloTreeNode* parent = NULL;
    TofuError compareResult;

    while (current != NULL) {
        compareResult = trilo_xdata_tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            // Node with the matching data found, perform removal
            if (parent == NULL) {
                // If the node to be removed is the root
                if (current->left == NULL && current->right == NULL) {
                    free(current);
                    tree->root = NULL;
                    return TRILO_XDATA_TYPE_SUCCESS;
                } else if (current->left == NULL) {
                    TriloTreeNode* temp = current->right;
                    free(current);
                    tree->root = temp;
                    return TRILO_XDATA_TYPE_SUCCESS;
                } else if (current->right == NULL) {
                    TriloTreeNode* temp = current->left;
                    free(current);
                    tree->root = temp;
                    return TRILO_XDATA_TYPE_SUCCESS;
                } else {
                    TriloTreeNode* minRight = current->right;
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
                    TriloTreeNode* temp = current->right;
                    free(current);
                    if (parent->left == current) {
                        parent->left = temp;
                    } else {
                        parent->right = temp;
                    }
                    return TRILO_XDATA_TYPE_SUCCESS;
                } else if (current->right == NULL) {
                    TriloTreeNode* temp = current->left;
                    free(current);
                    if (parent->left == current) {
                        parent->left = temp;
                    } else {
                        parent->right = temp;
                    }
                    return TRILO_XDATA_TYPE_SUCCESS;
                } else {
                    TriloTreeNode* minRight = current->right;
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
            compareResult = trilo_xdata_tofu_compare(data, current->data);

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

// Function to search for a TriloTofu data in the tree
TofuError trilo_xdata_tree_search(const TriloTree* tree, TriloTofu data) {
    if (tree == NULL) {
        return TRILO_XDATA_TYPE_WAS_NULLPTR;
    } // end if

    TriloTreeNode* current = tree->root;
    TofuError compareResult;

    while (current != NULL) {
        compareResult = trilo_xdata_tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            // Data found in the tree
            return TRILO_XDATA_TYPE_SUCCESS;
        } else if (compareResult == TRILO_XDATA_TYPE_WAS_MISMATCH) {
            // Determine whether to go left or right based on the comparison result
            compareResult = trilo_xdata_tofu_compare(data, current->data);

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
static void count_nodes(const TriloTreeNode* node, size_t* count) {
    if (node != NULL) {
        (*count)++;
        count_nodes(node->left, count);
        count_nodes(node->right, count);
    } // end if
} // end of func

// Function to get the size of the TriloTree
size_t trilo_xdata_tree_size(const TriloTree* tree) {
    if (tree == NULL || tree->root == NULL) {
        return 0;
    } // end if

    size_t count = 0;
    count_nodes(tree->root, &count);
    return count;
} // end of func

// Function to insert a TriloTofu data into the tree
TriloTofu* trilo_xdata_tree_getter(TriloTree* tree, TriloTofu data) {
    if (tree == NULL) {
        return NULL;
    } // end if

    TriloTreeNode* current = tree->root;
    TofuError compareResult;

    while (current != NULL) {
        compareResult = trilo_xdata_tofu_compare(current->data, data);

        if (compareResult == TRILO_XDATA_TYPE_SUCCESS) {
            // Data found in the tree, return a pointer to it
            return &(current->data);
        } else if (compareResult == TRILO_XDATA_TYPE_WAS_MISMATCH) {
            // Determine whether to go left or right based on the comparison result
            compareResult = trilo_xdata_tofu_compare(data, current->data);

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

// Function to insert a TriloTofu data into the tree
TofuError trilo_xdata_tree_setter(TriloTree* tree, TriloTofu data) {
    TriloTofu* existingData = trilo_xdata_tree_getter(tree, data);

    if (existingData != NULL) {
        // Data with the same value already exists, don't insert it again
        return TRILO_XDATA_TYPE_SUCCESS;
    } // end if

    return trilo_xdata_tree_insert(tree, data);
} // end of func

// Function to check if the tree is empty
bool trilo_xdata_tree_not_empty(const TriloTree* tree) {
    return tree != NULL && tree->root != NULL;
} // end of func

// Function to check if the tree is not null
bool trilo_xdata_tree_not_nullptr(const TriloTree* tree) {
    return tree != NULL;
} // end of func

// Function to check if the tree is empty
bool trilo_xdata_tree_is_empty(const TriloTree* tree) {
    return tree == NULL || tree->root == NULL;
} // end of func

// Function to check if the tree is null
bool trilo_xdata_tree_is_nullptr(const TriloTree* tree) {
    return tree == NULL;
} // end of func

// Function to check if a TriloTofu data is in the tree
bool trilo_xdata_tree_contains(const TriloTree* tree, TriloTofu data) {
    return trilo_xdata_tree_getter(tree, data) != NULL;
} // end of func
