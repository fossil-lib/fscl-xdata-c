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
XTEST_CASE(test_dlist_create_and_erase) {
    // Normal Case: Creating and erasing a doubly-linked list
    cdlist* dlist = dlist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dlist);
    dlist_erase(dlist);

    // Edge Case: Creating with an invalid type
    dlist = dlist_create(INVALID_TYPE);
    TEST_ASSERT_NULL_PTR(dlist);
}

XTEST_CASE(test_dlist_insert_and_remove) {
    // Normal Case: Inserting and removing elements from the doubly-linked list
    cdlist* dlist = dlist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dlist);

    ctofu data = {.data.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, dlist_insert(dlist, data));
    TEST_ASSERT_EQUAL(1, dlist_size(dlist));

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, dlist_remove(dlist, &data));
    TEST_ASSERT_EQUAL(0, dlist_size(dlist));

    dlist_erase(dlist);

    // Edge Case: Removing from an empty doubly-linked list
    TEST_ASSERT_EQUAL(CTOFU_ERROR_NOT_FOUND, dlist_remove(dlist, &data));
}

XTEST_CASE(test_dlist_search) {
    // Normal Case: Searching for an element in the doubly-linked list
    cdlist* dlist = dlist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dlist);

    ctofu data = {.data.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, dlist_insert(dlist, data));

    TEST_ASSERT_TRUE(dlist_not_cnullptr(dlist));
    TEST_ASSERT_TRUE(dlist_not_empty(dlist));
    TEST_ASSERT_FALSE(dlist_is_empty(dlist));
    TEST_ASSERT_FALSE(dlist_is_cnullptr(dlist));

    dlist_erase(dlist);

    // Edge Case: Searching in an empty doubly-linked list
    TEST_ASSERT_FALSE(dlist_not_cnullptr(dlist));
    TEST_ASSERT_FALSE(dlist_not_empty(dlist));
    TEST_ASSERT_TRUE(dlist_is_empty(dlist));
    TEST_ASSERT_TRUE(dlist_is_cnullptr(dlist));
}

XTEST_CASE(test_dlist_setter_and_getter) {
    // Normal Case: Setting and getting elements in the doubly-linked list
    cdlist* dlist = dlist_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(dlist);

    ctofu data1 = {.data.integer_type = 42};
    ctofu data2 = {.data.integer_type = 24};

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, dlist_insert(dlist, data1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, dlist_setter(dlist, data1));

    ctofu* retrieved_data = malloc(sizeof(ctofu));
    TEST_ASSERT_NOT_NULL_PTR(retrieved_data);
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, dlist_getter(dlist, data1, retrieved_data));
    TEST_ASSERT_EQUAL(data1.integer_type, retrieved_data->integer_type);

    free(retrieved_data);
    dlist_erase(dlist);

    // Edge Case: Getting from an empty doubly-linked list
    retrieved_data = malloc(sizeof(ctofu));
    TEST_ASSERT_NOT_NULL_PTR(retrieved_data);
    TEST_ASSERT_EQUAL(CTOFU_ERROR_NOT_FOUND, dlist_getter(dlist, data1, retrieved_data));
    free(retrieved_data);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_dlist_group) {
    XTEST_NOTE("Running all test cases for dlist:");

    XTEST_RUN_UNIT(test_dlist_create_and_erase,  runner);
    XTEST_RUN_UNIT(test_dlist_insert_and_remove, runner);
    XTEST_RUN_UNIT(test_dlist_search,            runner);
    XTEST_RUN_UNIT(test_dlist_setter_and_getter, runner);
} // end of func
