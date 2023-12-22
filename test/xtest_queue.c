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
XTEST_CASE(test_queue_create_and_erase) {
    cqueue* queue = tscl_queue_create(INTEGER_TYPE);

    // Check if the queue is created with the expected values
    TEST_ASSERT_NOT_NULL_PTR(queue);
    TEST_ASSERT_NULL_PTR(queue->front);
    TEST_ASSERT_NULL_PTR(queue->rear);
    TEST_ASSERT_EQUAL(INTEGER_TYPE, queue->queue_type);

    tscl_queue_erase(queue);

    // Check if the queue is erased
    TEST_ASSERT_NULL_PTR(queue->front);
    TEST_ASSERT_NULL_PTR(queue->rear);
    TEST_ASSERT_NULL_PTR(queue);
}

XTEST_CASE(test_queue_insert_and_size) {
    cqueue* queue = tscl_queue_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_queue_insert(queue, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_queue_insert(queue, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_queue_insert(queue, element3));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(3, tscl_queue_size(queue));

    tscl_queue_erase(queue);
}

XTEST_CASE(test_queue_remove) {
    cqueue* queue = tscl_queue_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_queue_insert(queue, element1);
    tscl_queue_insert(queue, element2);
    tscl_queue_insert(queue, element3);

    // Remove an element
    ctofu removedElement;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_queue_remove(queue, &removedElement));

    // Check if the removed element is correct
    TEST_ASSERT_EQUAL_INT(42, removedElement.data.integer_type);

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, tscl_queue_size(queue));

    tscl_queue_erase(queue);
}

XTEST_CASE(test_queue_not_empty_and_is_empty) {
    cqueue* queue = tscl_queue_create(INTEGER_TYPE);

    // Check initially not empty
    TEST_ASSERT_FALSE(tscl_queue_not_empty(queue));
    TEST_ASSERT_TRUE(tscl_queue_is_empty(queue));

    // Insert an element
    ctofu element = { INTEGER_TYPE, { .integer_type = 42 } };
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_queue_insert(queue, element));

    // Check not empty after insertion
    TEST_ASSERT_TRUE(tscl_queue_not_empty(queue));
    TEST_ASSERT_FALSE(tscl_queue_is_empty(queue));

    // Remove the element
    ctofu removedElement;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_queue_remove(queue, &removedElement));

    // Check empty after removal
    TEST_ASSERT_FALSE(tscl_queue_not_empty(queue));
    TEST_ASSERT_TRUE(tscl_queue_is_empty(queue));

    tscl_queue_erase(queue);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_queue_group) {
    XTEST_NOTE("Running all test cases for queue:");

    XTEST_RUN_UNIT(test_queue_create_and_erase, runner);
    XTEST_RUN_UNIT(test_queue_insert_and_size,  runner);
    XTEST_RUN_UNIT(test_queue_remove,                 runner);
    XTEST_RUN_UNIT(test_queue_not_empty_and_is_empty, runner);
} // end of func
