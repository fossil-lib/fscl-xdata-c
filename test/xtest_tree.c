/*
   under:   trilobite stdlib
   author:  Michael Gene Brockus (Dreamer)
   gmail:   <michaelbrockus@gmail.com>
   website: <https://trilobite.code.blog>
*/
#include "trilobite/xdata/tree.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case for creating and destroying a tree
XTEST_CASE(xdata_let_tree_create_and_destroy_tree) {
    TriloTree* tree = trilo_xdata_tree_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(tree);

    trilo_xdata_tree_destroy(tree);
}

// Test case for inserting and searching for a node in the tree
XTEST_CASE(xdata_let_tree_insert_and_search_tree) {
    TriloTree* tree = trilo_xdata_tree_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(tree);

    TriloTofu data_to_insert = trilo_xdata_tofu_create_from_integer(42);

    // Insert a node into the tree
    TofuError insert_result = trilo_xdata_tree_insert(tree, data_to_insert);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, insert_result);

    // Search for the inserted node
    TofuError search_result = trilo_xdata_tree_search(tree, data_to_insert);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, search_result);

    trilo_xdata_tree_destroy(tree);
}

// Test case for inserting and deleting a node in the tree
XTEST_CASE(xdata_let_tree_insert_and_delete_tree) {
    TriloTree* tree = trilo_xdata_tree_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(tree);

    TriloTofu data_to_insert = trilo_xdata_tofu_create_from_integer(42);

    // Insert a node into the tree
    TofuError insert_result = trilo_xdata_tree_insert(tree, data_to_insert);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, insert_result);

    // Delete the inserted node
    TofuError delete_result = trilo_xdata_tree_remove(tree, data_to_insert);
    XASSERT_BOOL_EQUAL(TRILO_XDATA_TYPE_SUCCESS, delete_result);

    trilo_xdata_tree_destroy(tree);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_tree_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for tree:");

    XTEST_RUN_UNIT(xdata_let_tree_create_and_destroy_tree, runner);
    XTEST_RUN_UNIT(xdata_let_tree_insert_and_search_tree,  runner);
    XTEST_RUN_UNIT(xdata_let_tree_insert_and_delete_tree,  runner);
} // end of func
