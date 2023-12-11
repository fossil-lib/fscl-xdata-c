/*  ----------------------------------------------------------------------------
    File: xtest_queue.c

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
#include "trilobite/xdata/queue.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case 1: Test cqueue creation and destruction
XTEST_CASE(xdata_let_queue_create_destroy) {
    cqueue* queue = queue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(queue);
    
    queue_erase(queue);
    // Ensure queue is successfully destroyed
}

XTEST_CASE(xdata_let_queue_insert) {
    cqueue* queue = queue_create(DOUBLE_TYPE);
    
    ctofu data = tofu_create_from_double(42.5);
    ctofu_error error = queue_insert(queue, data);
    
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, error);
    
    queue_erase(queue);
}

XTEST_CASE(xdata_let_queue_remove) {
    cqueue* queue = queue_create(STRING_TYPE);
    
    ctofu data = tofu_create_from_string("Hello");
    queue_insert(queue, data);
    
    ctofu_error error = queue_remove(queue);
    
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, error);
    
    queue_erase(queue);
}

XTEST_CASE(xdata_let_queue_search) {
    cqueue* queue = queue_create(CHAR_TYPE);
    
    ctofu data = tofu_create_from_char('A');
    queue_insert(queue, data);
    
    ctofu_error error = queue_search(queue, data);
    
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, error);
    
    queue_erase(queue);
}

XTEST_CASE(xdata_let_queue_insert_edge_cases) {
    cqueue* queue = queue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(queue);

    ctofu tofu1 = tofu_create_from_integer(1);
    ctofu tofu2 = tofu_create_from_double(2.5);
    ctofu tofu3 = tofu_create_from_string("Hello");

    ctofu_error error = queue_insert(queue, tofu1);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, error);

    error = queue_insert(queue, tofu2);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, error);

    error = queue_insert(queue, tofu3);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, error);

    // Test inserting a large number of elements
    for (int i = 0; i < 1000; ++i) {
        ctofu data = tofu_create_from_integer(i);
        error = queue_insert(queue, data);
        TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, error);
    }

    queue_erase(queue);
}

XTEST_CASE(xdata_let_queue_remove_edge_cases) {
    cqueue* empty_queue = queue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(empty_queue);

    // Test removing elements from an empty queue
    ctofu_error error = queue_remove(empty_queue);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_WAS_UNKNOWN, error);

    queue_erase(empty_queue);

    // Test removing a large number of elements
    cqueue* queue = queue_create(DOUBLE_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(queue);

    for (int i = 0; i < 1000; ++i) {
        ctofu data = tofu_create_from_double(i);
        queue_insert(queue, data);
    }

    for (int i = 0; i < 1000; ++i) {
        error = queue_remove(queue);
        TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, error);
    }

    queue_erase(queue);
}

XTEST_CASE(xdata_let_queue_search_edge_cases) {
    cqueue* empty_queue = queue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(empty_queue);

    ctofu tofu = tofu_create_from_integer(42);

    // Test searching for an element in an empty queue
    ctofu_error error = queue_search(empty_queue, tofu);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_WAS_UNKNOWN, error);

    queue_erase(empty_queue);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_queue_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for queue:");

    XTEST_RUN_UNIT(xdata_let_queue_create_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_queue_insert,         runner);
    XTEST_RUN_UNIT(xdata_let_queue_remove,         runner);
    XTEST_RUN_UNIT(xdata_let_queue_search,         runner);
    XTEST_RUN_UNIT(xdata_let_queue_insert_edge_cases, runner);
    XTEST_RUN_UNIT(xdata_let_queue_remove_edge_cases, runner);
    XTEST_RUN_UNIT(xdata_let_queue_search_edge_cases, runner);
} // end of func
