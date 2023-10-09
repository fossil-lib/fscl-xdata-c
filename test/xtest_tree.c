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

XTEST_CASE(xdata_let_tree_create_and_destroy) {
    TriloTree* tree = trilo_xdata_tree_create(INTEGER_TYPE);
    XASSERT_PTR_NOT_NULL(tree);
    trilo_xdata_tree_destroy(tree);
}

XTEST_CASE(xdata_let_tree_insert_and_search) {
    TriloTree* tree = trilo_xdata_tree_create(INTEGER_TYPE);

    // Insert values into the tree
    trilo_xdata_tree_insert(tree, 10);
    trilo_xdata_tree_insert(tree, 5);
    trilo_xdata_tree_insert(tree, 15);

    // Search for values in the tree
    XASSERT_BOOL_TRUE(trilo_xdata_tree_search(tree, 10));
    XASSERT_BOOL_TRUE(trilo_xdata_tree_search(tree, 5));
    XASSERT_BOOL_TRUE(trilo_xdata_tree_search(tree, 15));
    XASSERT_BOOL_FALSE(trilo_xdata_tree_search(tree, 7)); // Value not in the tree

    trilo_xdata_tree_destroy(tree);
}

XTEST_CASE(xdata_let_tree_remove) {
    TriloTree* tree = trilo_xdata_tree_create(INTEGER_TYPE);

    // Insert values into the tree
    trilo_xdata_tree_insert(tree, 10);
    trilo_xdata_tree_insert(tree, 5);
    trilo_xdata_tree_insert(tree, 15);

    // Remove a value from the tree
    trilo_xdata_tree_remove(tree, 10);

    // Check if the value is removed
    XASSERT_BOOL_FALSE(trilo_xdata_tree_search(tree, 10));

    trilo_xdata_tree_destroy(tree);
}

XTEST_CASE(xdata_let_tree_size) {
    TriloTree* tree = trilo_xdata_tree_create(INTEGER_TYPE);

    // Insert values into the tree
    trilo_xdata_tree_insert(tree, 10);
    trilo_xdata_tree_insert(tree, 5);
    trilo_xdata_tree_insert(tree, 15);

    // Check the size of the tree
    XASSERT_INT_EQUAL(3, trilo_xdata_tree_size(tree));

    trilo_xdata_tree_destroy(tree);
}

XTEST_CASE(xdata_let_tree_contains) {
    TriloTree* tree = trilo_xdata_tree_create(INTEGER_TYPE);

    // Insert values into the tree
    trilo_xdata_tree_insert(tree, 10);
    trilo_xdata_tree_insert(tree, 5);
    trilo_xdata_tree_insert(tree, 15);

    // Check if values are present in the tree
    XASSERT_BOOL_TRUE(trilo_xdata_tree_contains(tree, 10));
    XASSERT_BOOL_TRUE(trilo_xdata_tree_contains(tree, 5));
    XASSERT_BOOL_TRUE(trilo_xdata_tree_contains(tree, 15));
    XASSERT_BOOL_FALSE(trilo_xdata_tree_contains(tree, 7)); // Value not in the tree

    trilo_xdata_tree_destroy(tree);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_tree_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for tree:");

    XTEST_RUN_UNIT(xdata_let_tree_contains,           runner);
    XTEST_RUN_UNIT(xdata_let_tree_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_tree_insert_and_search,  runner);
    XTEST_RUN_UNIT(xdata_let_tree_remove,             runner);
    XTEST_RUN_UNIT(xdata_let_tree_size,               runner);
} // end of func
