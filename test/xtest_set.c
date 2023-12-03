/*  ----------------------------------------------------------------------------
    File: xtest_set.c

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
#include "trilobite/xdata/set.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case 1: Test cset creation and destruction
XTEST_CASE(xdata_let_set_create_and_destroy) {
    cset* set = trilo_xdata_set_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(set);

    trilo_xdata_set_destroy(set);
    TEST_ASSERT_NULL_PTR(set);
}

// Test case 2: Test cset insertion and removal
XTEST_CASE(xdata_let_set_insert_and_remove) {
    cset* set = trilo_xdata_set_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(set);

    ctofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    ctofu tofu2 = trilo_xdata_tofu_create_from_integer(2);
    ctofu tofu3 = trilo_xdata_tofu_create_from_integer(3);

    ctofu_error result = trilo_xdata_set_insert(set, tofu1);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_set_insert(set, tofu2);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_set_insert(set, tofu3);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_set_remove(set, tofu2);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    ctofu_error found_tofu2 = trilo_xdata_set_search(set, tofu2);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, found_tofu2);

    trilo_xdata_set_destroy(set);
}

// Test case 3: Test cset size
XTEST_CASE(xdata_let_set_size) {
    cset* set = trilo_xdata_set_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(set);

    ctofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    ctofu tofu2 = trilo_xdata_tofu_create_from_integer(2);

    trilo_xdata_set_insert(set, tofu1);
    trilo_xdata_set_insert(set, tofu2);

    size_t size = trilo_xdata_set_size(set);
    TEST_ASSERT_EQUAL_INT(2, size);

    trilo_xdata_set_destroy(set);
}

// Test case 4: Test cset empty check
XTEST_CASE(xdata_let_set_empty_check) {
    cset* set = trilo_xdata_set_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(set);

    TEST_ASSERT_TRUE_BOOL(trilo_xdata_set_is_empty(set));
    TEST_ASSERT_FALSE_BOOL(trilo_xdata_set_not_empty(set));

    ctofu tofu = trilo_xdata_tofu_create_from_integer(42);
    trilo_xdata_set_insert(set, tofu);

    TEST_ASSERT_FALSE_BOOL(trilo_xdata_set_is_empty(set));
    TEST_ASSERT_TRUE_BOOL(trilo_xdata_set_not_empty(set));

    trilo_xdata_set_destroy(set);
}

XTEST_CASE(xdata_let_set_insert_and_remove_edge_cases) {
    cset* set = trilo_xdata_set_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(set);

    ctofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    ctofu tofu2 = trilo_xdata_tofu_create_from_double(2.5);
    ctofu tofu3 = trilo_xdata_tofu_create_from_string("Hello");

    ctofu_error result = trilo_xdata_set_insert(set, tofu1);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_set_insert(set, tofu2);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_set_insert(set, tofu3);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    // Test removing an element that doesn't exist
    ctofu tofu_not_in_set = trilo_xdata_tofu_create_from_integer(999);
    result = trilo_xdata_set_remove(set, tofu_not_in_set);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_WAS_UNKNOWN, result);

    trilo_xdata_set_destroy(set);
}

XTEST_CASE(xdata_let_set_size_edge_cases) {
    cset* empty_set = trilo_xdata_set_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(empty_set);

    size_t size = trilo_xdata_set_size(empty_set);
    TEST_ASSERT_EQUAL_INT(0, size);

    trilo_xdata_set_destroy(empty_set);
}

XTEST_CASE(xdata_let_set_search_edge_cases) {
    cset* empty_set = trilo_xdata_set_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(empty_set);

    ctofu tofu = trilo_xdata_tofu_create_from_integer(42);

    // Test searching for an element in an empty set
    ctofu_error result = trilo_xdata_set_search(empty_set, tofu);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_WAS_UNKNOWN, result);

    trilo_xdata_set_destroy(empty_set);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_set_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for set:");

    XTEST_RUN_UNIT(xdata_let_set_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_set_empty_check,        runner);
    XTEST_RUN_UNIT(xdata_let_set_insert_and_remove,  runner);
    XTEST_RUN_UNIT(xdata_let_set_size,               runner);
    XTEST_RUN_UNIT(xdata_let_set_insert_and_remove_edge_cases, runner);
    XTEST_RUN_UNIT(xdata_let_set_size_edge_cases,              runner);
    XTEST_RUN_UNIT(xdata_let_set_search_edge_cases,            runner);
} // end of func
