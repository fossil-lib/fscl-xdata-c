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
XTEST_CASE(test_flist_create_and_erase) {
    // Normal Case: Creating and erasing a forward list
    cflist* flist = flist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(flist);
    flist_erase(flist);

    // Edge Case: Creating with an invalid type
    flist = flist_create(INVALID_TYPE);
    TEST_ASSERT_NULL_PTR(flist);
}

XTEST_CASE(test_flist_insert_and_remove) {
    // Normal Case: Inserting and removing elements from the forward list
    cflist* flist = flist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(flist);

    ctofu data = {.type.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, flist_insert(flist, data));
    TEST_ASSERT_EQUAL(1, flist_size(flist));

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, flist_remove(flist, &data));
    TEST_ASSERT_EQUAL(0, flist_size(flist));

    flist_erase(flist);

    // Edge Case: Removing from an empty forward list
    TEST_ASSERT_EQUAL(TOFU_NOT_FOUND, flist_remove(flist, &data));
}

XTEST_CASE(test_flist_search) {
    // Normal Case: Searching for an element in the forward list
    cflist* flist = flist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(flist);

    ctofu data = {.type.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, flist_insert(flist, data));

    TEST_ASSERT_TRUE(flist_not_cnullptr(flist));
    TEST_ASSERT_TRUE(flist_not_empty(flist));
    TEST_ASSERT_FALSE(flist_is_empty(flist));
    TEST_ASSERT_FALSE(flist_is_cnullptr(flist));

    flist_erase(flist);

    // Edge Case: Searching in an empty forward list
    TEST_ASSERT_FALSE(flist_not_cnullptr(flist));
    TEST_ASSERT_FALSE(flist_not_empty(flist));
    TEST_ASSERT_TRUE(flist_is_empty(flist));
    TEST_ASSERT_TRUE(flist_is_cnullptr(flist));
}

XTEST_CASE(test_flist_setter_and_getter) {
    // Normal Case: Setting and getting elements in the forward list
    cflist* flist = flist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(flist);

    ctofu data1 = {.type.integer_type = 42};
    ctofu data2 = {.type.integer_type = 24};

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, flist_insert(flist, data1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, flist_setter(flist, data1));

    ctofu* retrieved_data = malloc(sizeof(ctofu));
    TEST_ASSERT_NOT_NULL_PTR(retrieved_data);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, flist_getter(flist, data1, retrieved_data));
    TEST_ASSERT_EQUAL(data1.type.integer_type, retrieved_data->integer_type);

    free(retrieved_data);
    flist_erase(flist);

    // Edge Case: Getting from an empty forward list
    retrieved_data = malloc(sizeof(ctofu));
    TEST_ASSERT_NOT_NULL_PTR(retrieved_data);
    TEST_ASSERT_EQUAL(CTOFU_ERROR_NOT_FOUND, flist_getter(flist, data1, retrieved_data));
    free(retrieved_data);
}

XTEST_CASE(test_flist_reverse_forward_and_backward) {
    // Normal Case: Reversing a forward list forward and backward
    cflist* flist = flist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(flist);

    ctofu data1 = {.type.integer_type = 42};
    ctofu data2 = {.type.integer_type = 24};

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, flist_insert(flist, data1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, flist_insert(flist, data2));

    // Reverse forward
    flist_reverse_forward(flist);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, flist_getter(flist, data1, &data1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, flist_getter(flist, data2, &data2));
    TEST_ASSERT_EQUAL(24, data1.type.integer_type);
    TEST_ASSERT_EQUAL(42, data2.type.integer_type);

    // Reverse backward
    flist_reverse_backward(flist);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, flist_getter(flist, data1, &data1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, flist_getter(flist, data2, &data2));
    TEST_ASSERT_EQUAL(42, data1.type.integer_type);
    TEST_ASSERT_EQUAL(24, data2.type.integer_type);

    flist_erase(flist);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_flist_group) {
    XTEST_NOTE("Running all test cases for flist:");

    XTEST_RUN_UNIT(test_flist_create_and_erase,  runner);
    XTEST_RUN_UNIT(test_flist_insert_and_remove, runner);
    XTEST_RUN_UNIT(test_flist_search,            runner);
    XTEST_RUN_UNIT(test_flist_setter_and_getter, runner);
    XTEST_RUN_UNIT(test_flist_reverse_forward_and_backward, runner);
} // end of func
