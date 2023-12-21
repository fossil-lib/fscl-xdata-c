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

// Test case 1: Test cqueue creation and destruction
XTEST_CASE(test_queue_create_and_erase) {
    // Normal Case: Creating and erasing a queue
    cqueue* queue = queue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(queue);
    queue_erase(queue);

    // Edge Case: Creating with an invalid type
    queue = queue_create(INVALID_TYPE);
    TEST_ASSERT_NULL_PTR(queue);
}

XTEST_CASE(test_queue_insert_and_remove) {
    // Normal Case: Inserting and removing elements from the queue
    cqueue* queue = queue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(queue);

    ctofu element = {.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, queue_insert(queue, element));
    TEST_ASSERT_EQUAL(1, queue_size(queue));

    ctofu removed_element;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, queue_remove(queue, &removed_element));
    TEST_ASSERT_EQUAL(0, queue_size(queue));
    TEST_ASSERT_EQUAL(element.integer_type, removed_element.integer_type);

    queue_erase(queue);

    // Edge Case: Removing from an empty queue
    TEST_ASSERT_EQUAL(TOFU_NOT_FOUND, queue_remove(queue, &removed_element));
}

XTEST_CASE(test_queue_search) {
    // Normal Case: Searching for an element in the queue
    cqueue* queue = queue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(queue);

    ctofu element = {.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, queue_insert(queue, element));

    TEST_ASSERT_TRUE(queue_not_cnullptr(queue));
    TEST_ASSERT_TRUE(queue_not_empty(queue));
    TEST_ASSERT_FALSE(queue_is_empty(queue));
    TEST_ASSERT_FALSE(queue_is_cnullptr(queue));

    TEST_ASSERT_TRUE(queue_not_cnullptr(queue));
    TEST_ASSERT_TRUE(queue_not_empty(queue));
    TEST_ASSERT_FALSE(queue_is_empty(queue));
    TEST_ASSERT_FALSE(queue_is_cnullptr(queue));

    queue_erase(queue);

    // Edge Case: Searching in an empty queue
    TEST_ASSERT_FALSE(queue_not_cnullptr(queue));
    TEST_ASSERT_FALSE(queue_not_empty(queue));
    TEST_ASSERT_TRUE(queue_is_empty(queue));
    TEST_ASSERT_TRUE(queue_is_cnullptr(queue));
}

XTEST_CASE(test_queue_setter_and_getter) {
    // Normal Case: Setting and getting elements in the queue
    cqueue* queue = queue_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(queue);

    ctofu element1 = {.integer_type = 42};
    ctofu element2 = {.integer_type = 24};

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, queue_insert(queue, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, queue_setter(queue, element2));

    ctofu* retrieved_element = queue_getter(queue, element1);
    TEST_ASSERT_NOT_NULL_PTR(retrieved_element);
    TEST_ASSERT_EQUAL(element2.integer_type, retrieved_element->integer_type);

    queue_erase(queue);

    // Edge Case: Getting from an empty queue
    retrieved_element = queue_getter(queue, element1);
    TEST_ASSERT_NULL_PTR(retrieved_element);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_queue_group) {
    XTEST_NOTE("Running all test cases for queue:");

    XTEST_RUN_UNIT(test_queue_create_and_erase,  runner);
    XTEST_RUN_UNIT(test_queue_insert_and_remove, runner);
    XTEST_RUN_UNIT(test_queue_search,            runner);
    XTEST_RUN_UNIT(test_queue_setter_and_getter, runner);
} // end of func
