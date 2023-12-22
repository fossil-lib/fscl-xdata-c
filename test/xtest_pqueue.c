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
    cpqueue* pqueue = tscl_pqueue_create(INTEGER_TYPE);

    // Check if the priority queue is created with the expected values
    TEST_ASSERT_NOT_NULL_PTR(pqueue);
    TEST_ASSERT_NULL_PTR(pqueue->front);
    TEST_ASSERT_EQUAL(INTEGER_TYPE, pqueue->queue_type);

    tscl_pqueue_erase(pqueue);

    // Check if the priority queue is erased
    TEST_ASSERT_NULL_PTR(pqueue->front);
    TEST_ASSERT_NULL_PTR(pqueue);
}

XTEST_CASE(test_pqueue_insert_and_size) {
    cpqueue* pqueue = tscl_pqueue_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_pqueue_insert(pqueue, element1, 2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_pqueue_insert(pqueue, element2, 1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_pqueue_insert(pqueue, element3, 3));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(3, tscl_pqueue_size(pqueue));

    tscl_pqueue_erase(pqueue);
}

XTEST_CASE(test_pqueue_remove) {
    cpqueue* pqueue = tscl_pqueue_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_pqueue_insert(pqueue, element1, 2);
    tscl_pqueue_insert(pqueue, element2, 1);
    tscl_pqueue_insert(pqueue, element3, 3);

    // Remove an element
    ctofu removedElement;
    int removedPriority;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_pqueue_remove(pqueue, &removedElement, &removedPriority));

    // Check if the removed element and priority are correct
    TEST_ASSERT_EQUAL_INT(10, removedElement.data.integer_type);
    TEST_ASSERT_EQUAL_INT(1, removedPriority);

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, tscl_pqueue_size(pqueue));

    tscl_pqueue_erase(pqueue);
}

XTEST_CASE(test_pqueue_not_empty_and_is_empty) {
    cpqueue* pqueue = tscl_pqueue_create(INTEGER_TYPE);

    // Check initially not empty
    TEST_ASSERT_FALSE(tscl_pqueue_not_empty(pqueue));
    TEST_ASSERT_TRUE(tscl_pqueue_is_empty(pqueue));

    // Insert an element
    ctofu element = { INTEGER_TYPE, { .integer_type = 42 } };
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_pqueue_insert(pqueue, element, 2));

    // Check not empty after insertion
    TEST_ASSERT_TRUE(tscl_pqueue_not_empty(pqueue));
    TEST_ASSERT_FALSE(tscl_pqueue_is_empty(pqueue));

    // Remove the element
    ctofu removedElement;
    int removedPriority;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_pqueue_remove(pqueue, &removedElement, &removedPriority));

    // Check empty after removal
    TEST_ASSERT_FALSE(tscl_pqueue_not_empty(pqueue));
    TEST_ASSERT_TRUE(tscl_pqueue_is_empty(pqueue));

    tscl_pqueue_erase(pqueue);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_pqueue_group) {
    XTEST_NOTE("Running all test cases for pqueue:");

    XTEST_RUN_UNIT(test_pqueue_create_and_erase, runner);
    XTEST_RUN_UNIT(test_pqueue_insert_and_size,  runner);
    XTEST_RUN_UNIT(test_pqueue_remove,           runner);
    XTEST_RUN_UNIT(test_pqueue_not_empty_and_is_empty, runner);
} // end of func
