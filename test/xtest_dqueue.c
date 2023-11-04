/*  ----------------------------------------------------------------------------
    File: xtest_dqueue.c

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
#include "trilobite/xdata/dqueue.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case 1: Test TriloDQueue creation and destruction
XTEST_CASE(xdata_let_dqueue_create_and_destroy) {
    TriloDQueue* dqueue = trilo_xdata_dqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dqueue);

    trilo_xdata_dqueue_destroy(dqueue);
    TEST_ASSERT_NULL_PTR(dqueue);
}

// Test case 2: Test TriloDQueue insertion and retrieval
XTEST_CASE(xdata_let_dqueue_insert_and_get) {
    TriloDQueue* dqueue = trilo_xdata_dqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dqueue);

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    TofuError result = trilo_xdata_dqueue_insert(dqueue, tofu);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    TriloTofu* retrieved_tofu = trilo_xdata_dqueue_getter(dqueue, tofu);
    TEST_ASSERT_NOT_NULL_PTR(retrieved_tofu);
    TEST_ASSERT_EQUAL_INT(42, trilo_xdata_tofu_get_integer(*retrieved_tofu));

    trilo_xdata_dqueue_destroy(dqueue);
}

// Test case 3: Test TriloDQueue removal
XTEST_CASE(xdata_let_dqueue_remove) {
    TriloDQueue* dqueue = trilo_xdata_dqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dqueue);

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    TofuError result = trilo_xdata_dqueue_insert(dqueue, tofu);
    TEST_ASSERT_EQUAL_INT(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_dqueue_remove(dqueue, tofu);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    TriloTofu* retrieved_tofu = trilo_xdata_dqueue_getter(dqueue, tofu);
    TEST_ASSERT_NULL_PTR(retrieved_tofu);

    trilo_xdata_dqueue_destroy(dqueue);
}

// Test case 4: Test TriloDQueue size
XTEST_CASE(xdata_let_dqueue_size) {
    TriloDQueue* dqueue = trilo_xdata_dqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dqueue);

    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu tofu3 = trilo_xdata_tofu_create_from_integer(3);

    trilo_xdata_dqueue_insert(dqueue, tofu1);
    trilo_xdata_dqueue_insert(dqueue, tofu2);
    trilo_xdata_dqueue_insert(dqueue, tofu3);

    size_t size = trilo_xdata_dqueue_size(dqueue);
    TEST_ASSERT_EQUAL_INT(3, size);

    trilo_xdata_dqueue_destroy(dqueue);
}

// Test case 5: Test TriloDQueue empty check
XTEST_CASE(xdata_let_dqueue_empty_check) {
    TriloDQueue* dqueue = trilo_xdata_dqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dqueue);

    TEST_ASSERT_TRUE_BOOL(trilo_xdata_dqueue_is_empty(dqueue));
    TEST_ASSERT_FALSE_BOOL(trilo_xdata_dqueue_not_empty(dqueue));

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    trilo_xdata_dqueue_insert(dqueue, tofu);

    TEST_ASSERT_FALSE_BOOL(trilo_xdata_dqueue_is_empty(dqueue));
    TEST_ASSERT_TRUE_BOOL(trilo_xdata_dqueue_not_empty(dqueue));

    trilo_xdata_dqueue_destroy(dqueue);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_dqueue_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for dqueue:");

    XTEST_RUN_UNIT(xdata_let_dqueue_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_dqueue_empty_check,        runner);
    XTEST_RUN_UNIT(xdata_let_dqueue_insert_and_get,     runner);
    XTEST_RUN_UNIT(xdata_let_dqueue_remove,             runner);
    XTEST_RUN_UNIT(xdata_let_dqueue_size,               runner);
} // end of func
