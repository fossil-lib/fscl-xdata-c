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
XTEST_CASE(test_tree_create_and_erase) {
    ctree* tree = tscl_tree_create(INTEGER_TYPE);
    
    // Check if the tree is created with the expected values
    TEST_ASSERT_NOT_NULL_PTR(tree);
    TEST_ASSERT_NULL_PTR(tree->root);
    TEST_ASSERT_EQUAL(INTEGER_TYPE, tree->tree);

    tscl_tree_erase(tree);

    // Check if the tree is erased
    TEST_ASSERT_NULL_PTR(tree->root);
    TEST_ASSERT_NULL_PTR(tree);
}

XTEST_CASE(test_tree_insert_and_search) {
    ctree* tree = tscl_tree_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tree_insert(tree, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tree_insert(tree, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tree_insert(tree, element3));

    // Search for elements
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tree_search(tree, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tree_search(tree, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tree_search(tree, element3));

    // Search for non-existing element
    ctofu nonExistingElement = { INTEGER_TYPE, { .integer_type = 100 } };
    TEST_ASSERT_EQUAL(TOFU_NOT_FOUND, tscl_tree_search(tree, nonExistingElement));

    tscl_tree_erase(tree);
}

XTEST_CASE(test_tree_remove) {
    ctree* tree = tscl_tree_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_tree_insert(tree, element1);
    tscl_tree_insert(tree, element2);
    tscl_tree_insert(tree, element3);

    // Remove an element
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tree_remove(tree, element2));

    // Search for removed and remaining elements
    TEST_ASSERT_EQUAL(TOFU_NOT_FOUND, tscl_tree_search(tree, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tree_search(tree, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_tree_search(tree, element3));

    tscl_tree_erase(tree);
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
