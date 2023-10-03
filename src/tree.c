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

TriloTreeNode* trilo_xdata_tree_node_create(TriloTofu data) {
    TriloTreeNode* node = (TriloTreeNode*)malloc(sizeof(TriloTreeNode));
    if (node == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
} // end of func

TriloTree* trilo_xdata_tree_create(enum DataType tree_type) {
    TriloTree* tree = (TriloTree*)malloc(sizeof(TriloTree));
    if (tree == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    } // end if
    tree->root = NULL;
    tree->tree_type = tree_type;
    return tree;
} // end of func

void trilo_xdata_tree_destroy_helper(TriloTreeNode* node) {
    if (node == NULL) {
        return;
    } // end if
    trilo_xdata_tree_destroy_helper(node->left);
    trilo_xdata_tree_destroy_helper(node->right);
    free(node);
} // end of func

void trilo_xdata_tree_destroy(TriloTree* tree) {
    trilo_xdata_tree_destroy_helper(tree->root);
    free(tree);
} // end of func

bool trilo_xdata_tree_is_empty(const TriloTree* tree) {
    return tree->root == NULL;
} // end of func

TriloTreeNode* trilo_xdata_tree_insert_helper(TriloTreeNode* node, TriloTofu data) {
    if (node == NULL) {
        return trilo_xdata_tree_node_create(data);
    } // end if

    // Ensure the data type matches the tree type
    if (data.type != node->data.type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    if (data.type == INTEGER_TYPE) {
        if (data.data.integer_type < node->data.data.integer_type) {
            node->left = trilo_xdata_tree_insert_helper(node->left, data);
        } else if (data.data.integer_type > node->data.data.integer_type) {
            node->right = trilo_xdata_tree_insert_helper(node->right, data);
        }
    } else if (data.type == DOUBLE_TYPE) {
        if (data.data.double_type < node->data.data.double_type) {
            node->left = trilo_xdata_tree_insert_helper(node->left, data);
        } else if (data.data.double_type > node->data.data.double_type) {
            node->right = trilo_xdata_tree_insert_helper(node->right, data);
        }
    } else if (data.type == STRING_TYPE) {
        int cmp = strcmp(data.data.string_type, node->data.data.string_type);
        if (cmp < 0) {
            node->left = trilo_xdata_tree_insert_helper(node->left, data);
        } else if (cmp > 0) {
            node->right = trilo_xdata_tree_insert_helper(node->right, data);
        }
    } else if (data.type == CHAR_TYPE) {
        if (data.data.char_type < node->data.data.char_type) {
            node->left = trilo_xdata_tree_insert_helper(node->left, data);
        } else if (data.data.char_type > node->data.data.char_type) {
            node->right = trilo_xdata_tree_insert_helper(node->right, data);
        }
    } else if (data.type == BOOLEAN_TYPE) {
        if (data.data.boolean_type < node->data.data.boolean_type) {
            node->left = trilo_xdata_tree_insert_helper(node->left, data);
        } else if (data.data.boolean_type > node->data.data.boolean_type) {
            node->right = trilo_xdata_tree_insert_helper(node->right, data);
        }
    } // end if else if's

    return node;
} // end of func

void trilo_xdata_tree_insert(TriloTree* tree, TriloTofu data) {
    tree->root = trilo_xdata_tree_insert_helper(tree->root, data);
} // end of func

TriloTreeNode* trilo_xdata_tree_find_min(TriloTreeNode* node) {
    while (node->left != NULL) {
        node = node->left;
    } // end while
    return node;
} // end of func

TriloTreeNode* trilo_xdata_tree_remove_helper(TriloTreeNode* node, TriloTofu data) {
    if (node == NULL) {
        return node;
    } // end if

    // Ensure the data type matches the tree type
    if (data.type != node->data.type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    if (data.type == INTEGER_TYPE) {
        if (data.data.integer_type < node->data.data.integer_type) {
            node->left = trilo_xdata_tree_remove_helper(node->left, data);
        } else if (data.data.integer_type > node->data.data.integer_type) {
            node->right = trilo_xdata_tree_remove_helper(node->right, data);
        } else {
            // Node with only one child or no child
            if (node->left == NULL) {
                TriloTreeNode* temp = node->right;
                free(node);
                return temp;
            } else if (node->right == NULL) {
                TriloTreeNode* temp = node->left;
                free(node);
                return temp;
            }

            // Node with two children, get the inorder successor (smallest in the right subtree)
            TriloTreeNode* temp = trilo_xdata_tree_find_min(node->right);

            // Copy the inorder successor's data to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = trilo_xdata_tree_remove_helper(node->right, temp->data);
        }
    } else if (data.type == DOUBLE_TYPE) {
        if (data.data.double_type < node->data.data.double_type) {
            node->left = trilo_xdata_tree_remove_helper(node->left, data);
        } else if (data.data.double_type > node->data.data.double_type) {
            node->right = trilo_xdata_tree_remove_helper(node->right, data);
        } else {
            // Node with only one child or no child
            if (node->left == NULL) {
                TriloTreeNode* temp = node->right;
                free(node);
                return temp;
            } else if (node->right == NULL) {
                TriloTreeNode* temp = node->left;
                free(node);
                return temp;
            }

            // Node with two children, get the inorder successor (smallest in the right subtree)
            TriloTreeNode* temp = trilo_xdata_tree_find_min(node->right);

            // Copy the inorder successor's data to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = trilo_xdata_tree_remove_helper(node->right, temp->data);
        }
    } else if (data.type == STRING_TYPE) {
        int cmp = strcmp(data.data.string_type, node->data.data.string_type);
        if (cmp < 0) {
            node->left = trilo_xdata_tree_remove_helper(node->left, data);
        } else if (cmp > 0) {
            node->right = trilo_xdata_tree_remove_helper(node->right, data);
        } else {
            // Node with only one child or no child
            if (node->left == NULL) {
                TriloTreeNode* temp = node->right;
                free(node);
                return temp;
            } else if (node->right == NULL) {
                TriloTreeNode* temp = node->left;
                free(node);
                return temp;
            }

            // Node with two children, get the inorder successor (smallest in the right subtree)
            TriloTreeNode* temp = trilo_xdata_tree_find_min(node->right);

            // Copy the inorder successor's data to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = trilo_xdata_tree_remove_helper(node->right, temp->data);
        }
    } else if (data.type == CHAR_TYPE) {
        if (data.data.char_type < node->data.data.char_type) {
            node->left = trilo_xdata_tree_remove_helper(node->left, data);
        } else if (data.data.char_type > node->data.data.char_type) {
            node->right = trilo_xdata_tree_remove_helper(node->right, data);
        } else {
            // Node with only one child or no child
            if (node->left == NULL) {
                TriloTreeNode* temp = node->right;
                free(node);
                return temp;
            } else if (node->right == NULL) {
                TriloTreeNode* temp = node->left;
                free(node);
                return temp;
            }

            // Node with two children, get the inorder successor (smallest in the right subtree)
            TriloTreeNode* temp = trilo_xdata_tree_find_min(node->right);

            // Copy the inorder successor's data to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = trilo_xdata_tree_remove_helper(node->right, temp->data);
        }
    } else if (data.type == BOOLEAN_TYPE) {
        if (data.data.boolean_type < node->data.data.boolean_type) {
            node->left = trilo_xdata_tree_remove_helper(node->left, data);
        } else if (data.data.boolean_type > node->data.data.boolean_type) {
            node->right = trilo_xdata_tree_remove_helper(node->right, data);
        } else {
            // Node with only one child or no child
            if (node->left == NULL) {
                TriloTreeNode* temp = node->right;
                free(node);
                return temp;
            } else if (node->right == NULL) {
                TriloTreeNode* temp = node->left;
                free(node);
                return temp;
            }

            // Node with two children, get the inorder successor (smallest in the right subtree)
            TriloTreeNode* temp = trilo_xdata_tree_find_min(node->right);

            // Copy the inorder successor's data to this node
            node->data = temp->data;

            // Delete the inorder successor
            node->right = trilo_xdata_tree_remove_helper(node->right, temp->data);
        }
    } // end if else if's

    return node;
} // end of func

void trilo_xdata_tree_remove(TriloTree* tree, TriloTofu data) {
    tree->root = trilo_xdata_tree_remove_helper(tree->root, data);
} // end of func

bool trilo_xdata_tree_search_helper(const TriloTreeNode* node, TriloTofu data) {
    if (node == NULL) {
        return false;
    } // end if

    // Ensure the data type matches the tree type
    if (data.type != node->data.type) {
        fprintf(stderr, "Data type mismatch!\n");
        exit(EXIT_FAILURE);
    } // end if

    if (data.type == INTEGER_TYPE) {
        if (data.data.integer_type < node->data.data.integer_type) {
            return trilo_xdata_tree_search_helper(node->left, data);
        } else if (data.data.integer_type > node->data.data.integer_type) {
            return trilo_xdata_tree_search_helper(node->right, data);
        } else {
            return true;
        }
    } else if (data.type == DOUBLE_TYPE) {
        if (data.data.double_type < node->data.data.double_type) {
            return trilo_xdata_tree_search_helper(node->left, data);
        } else if (data.data.double_type > node->data.data.double_type) {
            return trilo_xdata_tree_search_helper(node->right, data);
        } else {
            return true;
        }
    } else if (data.type == STRING_TYPE) {
        int cmp = strcmp(data.data.string_type, node->data.data.string_type);
        if (cmp < 0) {
            return trilo_xdata_tree_search_helper(node->left, data);
        } else if (cmp > 0) {
            return trilo_xdata_tree_search_helper(node->right, data);
        } else {
            return true;
        }
    } else if (data.type == CHAR_TYPE) {
        if (data.data.char_type < node->data.data.char_type) {
            return trilo_xdata_tree_search_helper(node->left, data);
        } else if (data.data.char_type > node->data.data.char_type) {
            return trilo_xdata_tree_search_helper(node->right, data);
        } else {
            return true;
        }
    } else if (data.type == BOOLEAN_TYPE) {
        if (data.data.boolean_type < node->data.data.boolean_type) {
            return trilo_xdata_tree_search_helper(node->left, data);
        } else if (data.data.boolean_type > node->data.data.boolean_type) {
            return trilo_xdata_tree_search_helper(node->right, data);
        } else {
            return true;
        }
    } // end if else's

    return false; // Data not found
} // end of func

bool trilo_xdata_tree_search(const TriloTree* tree, TriloTofu data) {
    return trilo_xdata_tree_search_helper(tree->root, data);
} // end of func

void trilo_xdata_tree_inorder_traversal(const TriloTreeNode* node) {
    if (node == NULL) {
        return;
    } // end if

    trilo_xdata_tree_inorder_traversal(node->left);
    switch (node->data.type) {
        case INTEGER_TYPE:
            printf("%d -> ", node->data.data.integer_type);
            break;
        case DOUBLE_TYPE:
            printf("%lf -> ", node->data.data.double_type);
            break;
        case STRING_TYPE:
            printf("%s -> ", node->data.data.string_type);
            break;
        case CHAR_TYPE:
            printf("%c -> ", node->data.data.char_type);
            break;
        case BOOLEAN_TYPE:
            printf("%s -> ", node->data.data.boolean_type ? "true" : "false");
            break;
        default:
            printf("Unknown type\n");
            break;
    } // end switch
    trilo_xdata_tree_inorder_traversal(node->right);
} // end of func

void trilo_xdata_tree_print(const TriloTree* tree) {
    trilo_xdata_tree_inorder_traversal(tree->root);
    printf("NULL\n");
} // end of func
