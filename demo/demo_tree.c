
#include "trilobite/xdata/tree.h"
#include <stdio.h>

int main() {
    // Create an empty binary tree
    TriloTree* tree = trilo_xdata_tree_create(INTEGER_TYPE);

    // Insert some integer values into the tree
    trilo_xdata_tree_insert(tree, trilo_xdata_tofu_create_from_integer(50));
    trilo_xdata_tree_insert(tree, trilo_xdata_tofu_create_from_integer(30));
    trilo_xdata_tree_insert(tree, trilo_xdata_tofu_create_from_integer(70));
    trilo_xdata_tree_insert(tree, trilo_xdata_tofu_create_from_integer(20));
    trilo_xdata_tree_insert(tree, trilo_xdata_tofu_create_from_integer(40));
    trilo_xdata_tree_insert(tree, trilo_xdata_tofu_create_from_integer(60));
    trilo_xdata_tree_insert(tree, trilo_xdata_tofu_create_from_integer(80));

    // Print the tree using in-order traversal
    printf("In-order traversal: ");
    trilo_xdata_tree_in_order_traversal(tree, printInteger);
    printf("\n");

    // Print the tree using pre-order traversal
    printf("Pre-order traversal: ");
    trilo_xdata_tree_pre_order_traversal(tree, printInteger);
    printf("\n");

    // Print the tree using post-order traversal
    printf("Post-order traversal: ");
    trilo_xdata_tree_post_order_traversal(tree, printInteger);
    printf("\n");

    // Search for a value in the tree
    int searchValue = 40;
    TriloTofu result = trilo_xdata_tree_search(tree, trilo_xdata_tofu_create_from_integer(searchValue));

    if (result.type == INTEGER_TYPE) {
        printf("Found %d in the tree!\n", searchValue);
    } else {
        printf("%d not found in the tree.\n", searchValue);
    }

    // Clean up and destroy the tree
    trilo_xdata_tree_destroy(tree);

    return 0;
} // end of func
