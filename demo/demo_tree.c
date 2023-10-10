
#include "trilobite/xdata/tree.h"
#include <stdio.h>

int main() {
    // Create a new TriloTree instance to hold integer values
    TriloTree* intTree = trilo_xdata_tree_create(INTEGER_TYPE);

    // Insert some integer values into the TriloTree
    trilo_xdata_tree_insert(intTree, trilo_xdata_tofu_create_from_integer(42));
    trilo_xdata_tree_insert(intTree, trilo_xdata_tofu_create_from_integer(10));
    trilo_xdata_tree_insert(intTree, trilo_xdata_tofu_create_from_integer(73));

    // Check if the TriloTree is not empty
    if (trilo_xdata_tree_not_empty(intTree)) {
        printf("The TriloTree is not empty.\n");
    } // end if

    // Get the size of the TriloTree
    size_t intTreeSize = trilo_xdata_tree_size(intTree);
    printf("Size of the TriloTree: %zu\n", intTreeSize);

    // Search for a specific integer value
    TriloTofu searchValue = trilo_xdata_tofu_create_from_integer(10);
    TofuError searchResult = trilo_xdata_tree_search(intTree, searchValue);
    if (searchResult == TRILO_XDATA_TYPE_SUCCESS) {
        printf("The value 10 is found in the TriloTree.\n");
    } else {
        printf("The value 10 is not found in the TriloTree.\n");
    } // end if else

    // Destroy the TriloTree to free memory
    trilo_xdata_tree_destroy(intTree);

    return 0;
} // end of func
