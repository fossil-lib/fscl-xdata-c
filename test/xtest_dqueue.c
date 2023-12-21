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

// Test case 1: Test cdqueue creation and destruction
XTEST_CASE(test_dqueue_create_and_erase) {
    // Normal Case: Creating and erasing a double-ended queue
    cdqueue* dqueue = dqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dqueue);
    dqueue_erase(dqueue);

    // Edge Case: Creating with an invalid type
    dqueue = dqueue_create(INVALID_TYPE);
    TEST_ASSERT_NULL_PTR(dqueue);
}

XTEST_CASE(test_dqueue_insert_and_remove) {
    // Normal Case: Inserting and removing elements from the double-ended queue
    cdqueue* dqueue = dqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dqueue);

    ctofu data = {.data.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, dqueue_insert(dqueue, data));
    TEST_ASSERT_EQUAL(1, dqueue_size(dqueue));

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, dqueue_remove(dqueue, &data));
    TEST_ASSERT_EQUAL(0, dqueue_size(dqueue));

    dqueue_erase(dqueue);

    // Edge Case: Removing from an empty double-ended queue
    TEST_ASSERT_EQUAL(TOFU_NOT_FOUND, dqueue_remove(dqueue, &data));
}

XTEST_CASE(test_dqueue_search) {
    // Normal Case: Searching for an element in the double-ended queue
    cdqueue* dqueue = dqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dqueue);

    ctofu data = {.data.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, dqueue_insert(dqueue, data));

    TEST_ASSERT_TRUE(dqueue_not_cnullptr(dqueue));
    TEST_ASSERT_TRUE(dqueue_not_empty(dqueue));
    TEST_ASSERT_FALSE(dqueue_is_empty(dqueue));
    TEST_ASSERT_FALSE(dqueue_is_cnullptr(dqueue));

    dqueue_erase(dqueue);

    // Edge Case: Searching in an empty double-ended queue
    TEST_ASSERT_FALSE(dqueue_not_cnullptr(dqueue));
    TEST_ASSERT_FALSE(dqueue_not_empty(dqueue));
    TEST_ASSERT_TRUE(dqueue_is_empty(dqueue));
    TEST_ASSERT_TRUE(dqueue_is_cnullptr(dqueue));
}

XTEST_CASE(test_dqueue_setter_and_getter) {
    // Normal Case: Setting and getting elements in the double-ended queue
    cdqueue* dqueue = dqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dqueue);

    ctofu data1 = {.data.integer_type = 42};
    ctofu data2 = {.data.integer_type = 24};

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, dqueue_insert(dqueue, data1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, dqueue_setter(dqueue, data1));

    // Use dqueue_getter for validation
    ctofu* retrieved_data = dqueue_getter(dqueue, data1);
    TEST_ASSERT_NOT_NULL_PTR(retrieved_data);
    TEST_ASSERT_EQUAL(data1.integer_type, retrieved_data->data.integer_type);

    free(retrieved_data);
    dqueue_erase(dqueue);

    // Edge Case: Getting from an empty double-ended queue
    retrieved_data = dqueue_getter(dqueue, data1);
    TEST_ASSERT_NULL_PTR(retrieved_data);
    free(retrieved_data);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_dqueue_group) {
    XTEST_NOTE("Running all test cases for dqueue:");

    XTEST_RUN_UNIT(test_dqueue_create_and_erase,  runner);
    XTEST_RUN_UNIT(test_dqueue_insert_and_remove, runner);
    XTEST_RUN_UNIT(test_dqueue_search,            runner);
    XTEST_RUN_UNIT(test_dqueue_setter_and_getter, runner);
} // end of func
