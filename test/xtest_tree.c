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
XTEST_CASE(test_tree_creation_and_deletion) {
    // Normal Case: Creating and deleting a tree with a valid type
    ctree* tree = tree_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(tree);
    TEST_ASSERT_EQUAL(INTEGER_TYPE, tree->tree_type);
    tree_erase(tree);

    // Edge Case: Creating a tree with an invalid type
    TEST_ASSERT_NULL_PTR(tree_create(INVALID_TYPE));
}

XTEST_CASE(test_tree_insert_and_search) {
    // Normal Case: Inserting and searching for elements
    ctree* tree = tree_create(INTEGER_TYPE);
    ctofu data = {.type = INTEGER_TYPE, .data.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tree_insert(tree, data));
    TEST_ASSERT_TRUE(tree_contains(tree, data));

    // Edge Case: Inserting into a NULL tree
    TEST_ASSERT_EQUAL(TOFU_WAS_NULLPTR, tree_insert(NULL, data));

    // Edge Case: Searching in an empty tree
    ctree* empty_tree = tree_create(INTEGER_TYPE);
    TEST_ASSERT_FALSE(tree_contains(empty_tree, data));

    tree_erase(tree);
    tree_erase(empty_tree);
}

XTEST_CASE(test_tree_remove) {
    // Normal Case: Removing an element
    ctree* tree = tree_create(INTEGER_TYPE);
    ctofu data = {.type = INTEGER_TYPE, .data.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tree_insert(tree, data));
    TEST_ASSERT_TRUE(tree_contains(tree, data));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tree_remove(tree, data));
    TEST_ASSERT_FALSE(tree_contains(tree, data));

    // Edge Case: Removing from a NULL tree
    TEST_ASSERT_EQUAL(TOFU_WAS_NULLPTR, tree_remove(NULL, data));

    // Edge Case: Removing from an empty tree
    ctree* empty_tree = tree_create(INTEGER_TYPE);
    TEST_ASSERT_EQUAL(TOFU_NOT_FOUND, tree_remove(empty_tree, data));

    tree_erase(tree);
    tree_erase(empty_tree);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_tree_group) {
    XTEST_NOTE("Running all test cases for tree:");

    XTEST_RUN_UNIT(test_tree_creation_and_deletion, runner);
    XTEST_RUN_UNIT(test_tree_insert_and_search,     runner);
    XTEST_RUN_UNIT(test_tree_remove,                runner);
} // end of func
