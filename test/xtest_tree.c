/*  ----------------------------------------------------------------------------
    File: xtest_tree.c

    Description:
    This test file contains unit tests for the various functions and utilities provided
    by the Trilobite Stdlib. These tests ensure the correctness and reliability of the
    library's components and demonstrate their intended usage.

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
#include "trilobite/xdata/tree.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case for creating and destroying a tree
XTEST_CASE(xdata_let_tree_create_and_destroy_tree) {
    ctree* tree = trilo_xdata_tree_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(tree);

    trilo_xdata_tree_destroy(tree);
}

// Test case for inserting and searching for a node in the tree
XTEST_CASE(xdata_let_tree_insert_and_search_tree) {
    ctree* tree = trilo_xdata_tree_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(tree);

    ctofu data_to_insert = trilo_xdata_tofu_create_from_integer(42);

    // Insert a node into the tree
    ctofu_error insert_result = trilo_xdata_tree_insert(tree, data_to_insert);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, insert_result);

    // Search for the inserted node
    ctofu_error search_result = trilo_xdata_tree_search(tree, data_to_insert);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, search_result);

    trilo_xdata_tree_destroy(tree);
}

// Test case for inserting and deleting a node in the tree
XTEST_CASE(xdata_let_tree_insert_and_delete_tree) {
    ctree* tree = trilo_xdata_tree_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(tree);

    ctofu data_to_insert = trilo_xdata_tofu_create_from_integer(42);

    // Insert a node into the tree
    ctofu_error insert_result = trilo_xdata_tree_insert(tree, data_to_insert);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, insert_result);

    // Delete the inserted node
    ctofu_error delete_result = trilo_xdata_tree_remove(tree, data_to_insert);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, delete_result);

    trilo_xdata_tree_destroy(tree);
}

XTEST_CASE(xdata_let_tree_create_and_destroy_tree_with_types) {
    ctree* double_tree = trilo_xdata_tree_create(DOUBLE_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(double_tree);
    trilo_xdata_tree_destroy(double_tree);

    ctree* string_tree = trilo_xdata_tree_create(STRING_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(string_tree);
    trilo_xdata_tree_destroy(string_tree);

    ctree* bool_tree = trilo_xdata_tree_create(BOOLEAN_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(bool_tree);
    trilo_xdata_tree_destroy(bool_tree);

    // Test creating a tree with an invalid type
    ctree* invalid_tree = trilo_xdata_tree_create(INVALID_TYPE);
    TEST_ASSERT_NULL_PTR(invalid_tree);
}

XTEST_CASE(xdata_let_tree_insert_and_search_tree_edge_cases) {
    ctree* tree = trilo_xdata_tree_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(tree);

    // Test inserting nodes with various data types
    ctofu int_data = trilo_xdata_tofu_create_from_integer(42);
    ctofu double_data = trilo_xdata_tofu_create_from_double(3.14);
    ctofu string_data = trilo_xdata_tofu_create_from_string("Hello");

    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_tree_insert(tree, int_data));
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_tree_insert(tree, double_data));
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_tree_insert(tree, string_data));

    // Test searching for a node that doesn't exist
    ctofu not_found_data = trilo_xdata_tofu_create_from_integer(999);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_NOT_FOUND, trilo_xdata_tree_search(tree, not_found_data));

    trilo_xdata_tree_destroy(tree);
}

XTEST_CASE(xdata_let_tree_insert_and_delete_tree_edge_cases) {
    ctree* tree = trilo_xdata_tree_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(tree);

    // Test deleting a node that doesn't exist
    ctofu not_found_data = trilo_xdata_tofu_create_from_integer(999);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_NOT_FOUND, trilo_xdata_tree_remove(tree, not_found_data));

    // Test deleting the root node
    ctofu root_data = trilo_xdata_tofu_create_from_integer(42);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_tree_insert(tree, root_data));
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, trilo_xdata_tree_remove(tree, root_data));
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_NOT_FOUND, trilo_xdata_tree_search(tree, root_data));

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
    XTEST_RUN_UNIT(xdata_let_tree_create_and_destroy_tree_with_types, runner);
    XTEST_RUN_UNIT(xdata_let_tree_insert_and_search_tree_edge_cases,  runner);
    XTEST_RUN_UNIT(xdata_let_tree_insert_and_delete_tree_edge_cases,  runner);
} // end of func
