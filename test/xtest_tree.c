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
#include "fossil/xdata/tree.h" // lib source code

#include <fossil/xtest.h>   // basic test tools
#include <fossil/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//
XTEST_CASE(test_tree_create_and_erase) {
    ctree* tree = fscl_tree_create(TOFU_INT_TYPE);
    
    // Check if the tree is created with the expected values
    TEST_ASSERT_NOT_CNULLPTR(tree);
    TEST_ASSERT_CNULLPTR(tree->root);
    TEST_ASSERT_EQUAL(TOFU_INT_TYPE, tree->tree);

    fscl_tree_erase(tree);

    // Check if the tree is erased
    TEST_ASSERT_CNULLPTR(tree->root);
    TEST_ASSERT_CNULLPTR(tree);
}

XTEST_CASE(test_tree_insert_and_search) {
    ctree* tree = fscl_tree_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tree_insert(tree, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tree_insert(tree, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tree_insert(tree, element3));

    // Search for elements
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tree_search(tree, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tree_search(tree, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tree_search(tree, element3));

    // Search for non-existing element
    ctofu nonExistingElement = { TOFU_INT_TYPE, { .int_type = 100 } };
    TEST_ASSERT_EQUAL(TOFU_NOT_FOUND, fscl_tree_search(tree, nonExistingElement));

    fscl_tree_erase(tree);
}

XTEST_CASE(test_tree_remove) {
    ctree* tree = fscl_tree_create(TOFU_INT_TYPE);

    // Insert some elements
    ctofu element1 = { TOFU_INT_TYPE, { .int_type = 42 } };
    ctofu element2 = { TOFU_INT_TYPE, { .int_type = 10 } };
    ctofu element3 = { TOFU_INT_TYPE, { .int_type = 5 } };

    fscl_tree_insert(tree, element1);
    fscl_tree_insert(tree, element2);
    fscl_tree_insert(tree, element3);

    // Remove an element
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tree_remove(tree, element2));

    // Search for removed and remaining elements
    TEST_ASSERT_EQUAL(TOFU_NOT_FOUND, fscl_tree_search(tree, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tree_search(tree, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, fscl_tree_search(tree, element3));

    fscl_tree_erase(tree);
}

//
// XUNIT-TEST RUNNER
//
XTEST_DEFINE_POOL(xdata_test_tree_group) {
    XTEST_NOTE("Running all test cases for tree:");

    XTEST_RUN_UNIT(test_tree_create_and_erase);
    XTEST_RUN_UNIT(test_tree_insert_and_search);
    XTEST_RUN_UNIT(test_tree_remove);
} // end of func
