/*  ----------------------------------------------------------------------------
    File: xtest_flist.c

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
#include "trilobite/xdata/flist.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case 1: Test cflist creation and destruction
XTEST_CASE(xdata_let_flist_create_and_destroy) {
    cflist* flist = flist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(flist);

    flist_erase(flist);
    TEST_ASSERT_NULL_PTR(flist);
}

// Test case 2: Test cflist insertion and retrieval
XTEST_CASE(xdata_let_flist_insert_and_get) {
    cflist* flist = flist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(flist);

    ctofu tofu = tofu_create_from_integer(42);
    ctofu_error result = flist_insert(flist, tofu);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    ctofu* retrieved_tofu = flist_getter(flist, tofu);
    TEST_ASSERT_NOT_NULL_PTR(retrieved_tofu);
    TEST_ASSERT_EQUAL_INT(42, tofu_get_integer(*retrieved_tofu));

    flist_erase(flist);
}

// Test case 3: Test cflist removal
XTEST_CASE(xdata_let_flist_remove) {
    cflist* flist = flist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(flist);

    ctofu tofu = tofu_create_from_integer(42);
    ctofu_error result = flist_insert(flist, tofu);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    result = flist_remove(flist, tofu);
    TEST_ASSERT_EQUAL_BOOL(TRILO_XDATA_TYPE_SUCCESS, result);

    ctofu* retrieved_tofu = flist_getter(flist, tofu);
    TEST_ASSERT_NULL_PTR(retrieved_tofu);

    flist_erase(flist);
}

// Test case 4: Test cflist size
XTEST_CASE(xdata_let_flist_size) {
    cflist* flist = flist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(flist);

    ctofu tofu1 = tofu_create_from_integer(1);
    ctofu tofu2 = tofu_create_from_integer(2);
    ctofu tofu3 = tofu_create_from_integer(3);

    flist_insert(flist, tofu1);
    flist_insert(flist, tofu2);
    flist_insert(flist, tofu3);

    size_t size = flist_size(flist);
    TEST_ASSERT_EQUAL_INT(3, size);

    flist_erase(flist);
}

// Test case 5: Test cflist empty check
XTEST_CASE(xdata_let_flist_empty_check) {
    cflist* flist = flist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(flist);

    TEST_ASSERT_TRUE_BOOL(flist_is_empty(flist));
    TEST_ASSERT_FALSE_BOOL(flist_not_empty(flist));

    ctofu tofu = tofu_create_from_integer(42);
    flist_insert(flist, tofu);

    TEST_ASSERT_FALSE_BOOL(flist_is_empty(flist));
    TEST_ASSERT_TRUE_BOOL(flist_not_empty(flist));

    flist_erase(flist);
}

//
// XUNIT-TEST RUNNER
//
void xdata_test_flist_group(XUnitRunner *runner) {
    XTEST_NOTE("Running all test cases for flist:");

    XTEST_RUN_UNIT(xdata_let_flist_create_and_destroy, runner);
    XTEST_RUN_UNIT(xdata_let_flist_empty_check,        runner);
    XTEST_RUN_UNIT(xdata_let_flist_insert_and_get,     runner);
    XTEST_RUN_UNIT(xdata_let_flist_remove,             runner);
    XTEST_RUN_UNIT(xdata_let_flist_size,               runner);
} // end of func
