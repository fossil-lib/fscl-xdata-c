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
XTEST_CASE(test_pqueue_create_and_erase) {
    // Normal Case: Creating and erasing a priority queue
    cpqueue* pqueue = pqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(pqueue);
    pqueue_erase(pqueue);

    // Edge Case: Creating with an invalid type
    pqueue = pqueue_create(INVALID_TYPE);
    TEST_ASSERT_NULL_PTR(pqueue);
}

XTEST_CASE(test_pqueue_insert_and_remove) {
    // Normal Case: Inserting and removing elements from the priority queue
    cpqueue* pqueue = pqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(pqueue);

    ctofu element = {.data.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, pqueue_insert(pqueue, element, 1));
    TEST_ASSERT_EQUAL(1, pqueue_size(pqueue));

    ctofu removed_element;
    int priority;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, pqueue_remove(pqueue, &removed_element, &priority));
    TEST_ASSERT_EQUAL(0, pqueue_size(pqueue));
    TEST_ASSERT_EQUAL(element.integer_type, removed_element.integer_type);

    pqueue_erase(pqueue);

    // Edge Case: Removing from an empty priority queue
    TEST_ASSERT_EQUAL(TOFU_NOT_FOUND, pqueue_remove(pqueue, &removed_element, &priority));
}

XTEST_CASE(test_pqueue_search) {
    // Normal Case: Searching for an element in the priority queue
    cpqueue* pqueue = pqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(pqueue);

    ctofu element = {.data.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, pqueue_insert(pqueue, element, 1));

    TEST_ASSERT_TRUE(pqueue_not_cnullptr(pqueue));
    TEST_ASSERT_TRUE(pqueue_not_empty(pqueue));
    TEST_ASSERT_FALSE(pqueue_is_empty(pqueue));
    TEST_ASSERT_FALSE(pqueue_is_cnullptr(pqueue));

    pqueue_erase(pqueue);

    // Edge Case: Searching in an empty priority queue
    TEST_ASSERT_FALSE(pqueue_not_cnullptr(pqueue));
    TEST_ASSERT_FALSE(pqueue_not_empty(pqueue));
    TEST_ASSERT_TRUE(pqueue_is_empty(pqueue));
    TEST_ASSERT_TRUE(pqueue_is_cnullptr(pqueue));
}

XTEST_CASE(test_pqueue_setter_and_getter) {
    // Normal Case: Setting and getting elements in the priority queue
    cpqueue* pqueue = pqueue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(pqueue);

    ctofu element1 = {.data.integer_type = 42};
    ctofu element2 = {.data.integer_type = 24};

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, pqueue_insert(pqueue, element1, 1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, pqueue_setter(pqueue, element2, 2));

    ctofu* retrieved_element = pqueue_getter(pqueue, element1, 1);
    TEST_ASSERT_NOT_NULL_PTR(retrieved_element);
    TEST_ASSERT_EQUAL(element2.data.integer_type, retrieved_->data.integer_type );

    pqueue_erase(pqueue);

    // Edge Case: Getting from an empty priority queue
    retrieved_element = pqueue_getter(pqueue, element1, 1);
    TEST_ASSERT_NULL_PTR(retrieved_element);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_pqueue_group) {
    XTEST_NOTE("Running all test cases for pqueue:");

    XTEST_RUN_UNIT(test_pqueue_create_and_erase,  runner);
    XTEST_RUN_UNIT(test_pqueue_insert_and_remove, runner);
    XTEST_RUN_UNIT(test_pqueue_search,            runner);
    XTEST_RUN_UNIT(test_pqueue_setter_and_getter, runner);
} // end of func
