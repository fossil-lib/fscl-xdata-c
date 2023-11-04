/*  ----------------------------------------------------------------------------
    File: xtest_dlist.c

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
#include "trilobite/xdata/dlist.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case 1: Test TriloDoublyList creation and destruction
XTEST_CASE(xdata_let_dlist_create_and_destroy) {
    TriloDoublyList* dlist = trilo_xdata_dlist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dlist);

    trilo_xdata_dlist_destroy(dlist);
    TEST_ASSERT_NULL_PTR(dlist);
}

// Test case 2: Test TriloDoublyList insertion and retrieval
XTEST_CASE(xdata_let_dlist_insert_and_get) {
    TriloDoublyList* dlist = trilo_xdata_dlist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dlist);

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    TofuError result = trilo_xdata_dlist_insert(dlist, tofu);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    TriloTofu* retrieved_tofu = trilo_xdata_dlist_getter(dlist, tofu);
    TEST_ASSERT_NOT_NULL_PTR(retrieved_tofu);
    TEST_ASSERT_EQUAL_INT(42, trilo_xdata_tofu_get_integer(*retrieved_tofu));

    trilo_xdata_dlist_destroy(dlist);
}

// Test case 3: Test TriloDoublyList removal
XTEST_CASE(xdata_let_dlist_remove) {
    TriloDoublyList* dlist = trilo_xdata_dlist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dlist);

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    TofuError result = trilo_xdata_dlist_insert(dlist, tofu);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = trilo_xdata_dlist_remove(dlist, tofu);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    TriloTofu* retrieved_tofu = trilo_xdata_dlist_getter(dlist, tofu);
    TEST_ASSERT_NULL_PTR(retrieved_tofu);

    trilo_xdata_dlist_destroy(dlist);
}

// Test case 4: Test TriloDoublyList size
XTEST_CASE(xdata_let_dlist_size) {
    TriloDoublyList* dlist = trilo_xdata_dlist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dlist);

    TriloTofu tofu1 = trilo_xdata_tofu_create_from_integer(1);
    TriloTofu tofu2 = trilo_xdata_tofu_create_from_integer(2);
    TriloTofu tofu3 = trilo_xdata_tofu_create_from_integer(3);

    trilo_xdata_dlist_insert(dlist, tofu1);
    trilo_xdata_dlist_insert(dlist, tofu2);
    trilo_xdata_dlist_insert(dlist, tofu3);

    size_t size = trilo_xdata_dlist_size(dlist);
    TEST_ASSERT_EQUAL_INT(3, size);

    trilo_xdata_dlist_destroy(dlist);
}

// Test case 5: Test TriloDoublyList empty check
XTEST_CASE(xdata_let_dlist_empty_check) {
    TriloDoublyList* dlist = trilo_xdata_dlist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dlist);

    TEST_ASSERT_TRUE_BOOL(trilo_xdata_dlist_is_empty(dlist));
    TEST_ASSERT_FALSE_BOOL(trilo_xdata_dlist_not_empty(dlist));

    TriloTofu tofu = trilo_xdata_tofu_create_from_integer(42);
    trilo_xdata_dlist_insert(dlist, tofu);

    TEST_ASSERT_FALSE_BOOL(trilo_xdata_dlist_is_empty(dlist));
    TEST_ASSERT_TRUE_BOOL(trilo_xdata_dlist_not_empty(dlist));

    trilo_xdata_dlist_destroy(dlist);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_dlist_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for dlist:");

    XTEST_RUN_UNIT(xdata_let_dlist_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_dlist_empty_check,        runner);
    XTEST_RUN_UNIT(xdata_let_dlist_insert_and_get,     runner);
    XTEST_RUN_UNIT(xdata_let_dlist_remove,             runner);
    XTEST_RUN_UNIT(xdata_let_dlist_size,               runner);
} // end of func
