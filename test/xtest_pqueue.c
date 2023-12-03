/*  ----------------------------------------------------------------------------
    File: xtest_pqueue.c

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
#include "trilobite/xdata/pqueue.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case 1: Test cpqueue creation and destruction
XTEST_CASE(xdata_let_pqueue_create_and_destroy) {
    cpqueue* pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(pqueue);

    trilo_xdata_pqueue_destroy(pqueue);
    TEST_ASSERT_NULL_PTR(pqueue);
}

// Test case 2: Test cpqueue insertion and retrieval
XTEST_CASE(xdata_let_pqueue_insert_and_get) {
    cpqueue* pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(pqueue);

    ctofu tofu = trilo_xdata_tofu_create_from_integer(42);
    int priority = 2;
    ctofu_error result = trilo_xdata_pqueue_insert(pqueue, tofu, priority);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    ctofu* retrieved_tofu = trilo_xdata_pqueue_getter(pqueue, tofu, priority);
    TEST_ASSERT_NOT_NULL_PTR(retrieved_tofu);
    TEST_ASSERT_EQUAL_INT(42, trilo_xdata_tofu_get_integer(*retrieved_tofu));

    trilo_xdata_pqueue_destroy(pqueue);
}

// Test case 3: Test cpqueue removal
XTEST_CASE(xdata_let_pqueue_remove) {
    cpqueue* pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(pqueue);

    ctofu tofu = trilo_xdata_tofu_create_from_integer(42);
    int priority = 2;
    ctofu_error result = trilo_xdata_pqueue_insert(pqueue, tofu, priority);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_pqueue_remove(pqueue, tofu, priority);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    ctofu* retrieved_tofu = trilo_xdata_pqueue_getter(pqueue, tofu, priority);
    TEST_ASSERT_NULL_PTR(retrieved_tofu);

    trilo_xdata_pqueue_destroy(pqueue);
}

// Test case 4: Test cpqueue size
XTEST_CASE(xdata_let_pqueue_size) {
    cpqueue* pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(pqueue);

    ctofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    ctofu tofu2 = trilo_xdata_tofu_create_from_integer(2);
    ctofu tofu3 = trilo_xdata_tofu_create_from_integer(3);

    trilo_xdata_pqueue_insert(pqueue, tofu1, 1);
    trilo_xdata_pqueue_insert(pqueue, tofu2, 2);
    trilo_xdata_pqueue_insert(pqueue, tofu3, 1);

    size_t size = trilo_xdata_pqueue_size(pqueue);
    TEST_ASSERT_EQUAL_INT(3, size);

    trilo_xdata_pqueue_destroy(pqueue);
}

// Test case 5: Test cpqueue empty check
XTEST_CASE(xdata_let_pqueue_empty_check) {
    cpqueue* pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(pqueue);

    TEST_ASSERT_TRUE_BOOL(trilo_xdata_pqueue_is_empty(pqueue));
    TEST_ASSERT_FALSE_BOOL(trilo_xdata_pqueue_not_empty(pqueue));

    ctofu tofu = trilo_xdata_tofu_create_from_integer(42);
    trilo_xdata_pqueue_insert(pqueue, tofu, 1);

    TEST_ASSERT_FALSE_BOOL(trilo_xdata_pqueue_is_empty(pqueue));
    TEST_ASSERT_TRUE_BOOL(trilo_xdata_pqueue_not_empty(pqueue));

    trilo_xdata_pqueue_destroy(pqueue);
}

XTEST_CASE(xdata_let_pqueue_remove_edge_cases) {
    cpqueue* empty_pqueue = trilo_xdata_pqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(empty_pqueue);

    // Test removing elements from an empty priority queue
    ctofu tofu = trilo_xdata_tofu_create_from_integer(42);
    int priority = 1;
    ctofu_error result = trilo_xdata_pqueue_remove(empty_pqueue, tofu, priority);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_WAS_UNKNOWN, result);

    trilo_xdata_pqueue_destroy(empty_pqueue);

    // Test removing a large number of elements
    cpqueue* pqueue = trilo_xdata_pqueue_create(DOUBLE_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(pqueue);

    for (int i = 0; i < 1000; ++i) {
        ctofu data = trilo_xdata_tofu_create_from_double(i * 0.1);
        int priority = i % 5;  // Priorities 0, 1, 2, 3, 4
        trilo_xdata_pqueue_insert(pqueue, data, priority);
    }

    for (int i = 0; i < 1000; ++i) {
        ctofu data = trilo_xdata_tofu_create_from_double(i * 0.1);
        int priority = i % 5;  // Priorities 0, 1, 2, 3, 4
        result = trilo_xdata_pqueue_remove(pqueue, data, priority);
        TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);
    }

    trilo_xdata_pqueue_destroy(pqueue);
}

XTEST_CASE(xdata_let_pqueue_insert_and_get_edge_cases) {
    cpqueue* pqueue = trilo_xdata_pqueue_create(DOUBLE_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(pqueue);

    // Test inserting elements with different priorities
    for (int i = 0; i < 10; ++i) {
        ctofu data = trilo_xdata_tofu_create_from_double(i * 1.5);
        int priority = i % 3;  // Priorities 0, 1, 2
        trilo_xdata_pqueue_insert(pqueue, data, priority);
    }

    // Test inserting and retrieving a large number of elements
    for (int i = 0; i < 1000; ++i) {
        ctofu data = trilo_xdata_tofu_create_from_double(i * 0.1);
        int priority = i % 5;  // Priorities 0, 1, 2, 3, 4
        trilo_xdata_pqueue_insert(pqueue, data, priority);
    }

    trilo_xdata_pqueue_destroy(pqueue);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_pqueue_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for pqueue:");

    XTEST_RUN_UNIT(xdata_let_pqueue_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_pqueue_empty_check,        runner);
    XTEST_RUN_UNIT(xdata_let_pqueue_insert_and_get,     runner);
    XTEST_RUN_UNIT(xdata_let_pqueue_remove,             runner);
    XTEST_RUN_UNIT(xdata_let_pqueue_size,               runner);
    XTEST_RUN_UNIT(xdata_let_pqueue_size, runner);
    XTEST_RUN_UNIT(xdata_let_pqueue_insert_and_get_edge_cases, runner);
} // end of func
