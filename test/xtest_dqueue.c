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
XTEST_CASE(test_dqueue_create_and_erase) {
    cdqueue* dqueue = tscl_dqueue_create(INTEGER_TYPE);

    // Check if the deque is created with the expected values
    TEST_ASSERT_NOT_NULL_PTR(dqueue);
    TEST_ASSERT_NULL_PTR(dqueue->front);
    TEST_ASSERT_NULL_PTR(dqueue->rear);
    TEST_ASSERT_EQUAL(INTEGER_TYPE, dqueue->list_type);

    tscl_dqueue_erase(dqueue);

    // Check if the deque is erased
    TEST_ASSERT_NULL_PTR(dqueue->front);
    TEST_ASSERT_NULL_PTR(dqueue->rear);
    TEST_ASSERT_NULL_PTR(dqueue);
}

XTEST_CASE(test_dqueue_insert_and_size) {
    cdqueue* dqueue = tscl_dqueue_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_dqueue_insert(dqueue, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_dqueue_insert(dqueue, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_dqueue_insert(dqueue, element3));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(3, tscl_dqueue_size(dqueue));

    tscl_dqueue_erase(dqueue);
}

XTEST_CASE(test_dqueue_remove) {
    cdqueue* dqueue = tscl_dqueue_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_dqueue_insert(dqueue, element1);
    tscl_dqueue_insert(dqueue, element2);
    tscl_dqueue_insert(dqueue, element3);

    // Remove an element
    ctofu removedElement;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_dqueue_remove(dqueue, &removedElement));

    // Check if the removed element is correct
    TEST_ASSERT_EQUAL_INT(42, removedElement.data.integer_type);

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, tscl_dqueue_size(dqueue));

    tscl_dqueue_erase(dqueue);
}

XTEST_CASE(test_dqueue_getter_and_setter) {
    cdqueue* dqueue = tscl_dqueue_create(INTEGER_TYPE);

    // Insert an element
    ctofu element = { INTEGER_TYPE, { .integer_type = 42 } };
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_dqueue_insert(dqueue, element));

    // Get the value for an element
    ctofu* retrievedElement = tscl_dqueue_getter(dqueue, element);
    TEST_ASSERT_NOT_NULL_PTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(42, retrievedElement->data.integer_type);

    // Update the value for an element
    ctofu updatedElement = { INTEGER_TYPE, { .integer_type = 50 } };
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_dqueue_setter(dqueue, updatedElement));

    // Get the updated value for the element
    retrievedElement = tscl_dqueue_getter(dqueue, updatedElement);
    TEST_ASSERT_NOT_NULL_PTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(50, retrievedElement->data.integer_type);

    tscl_dqueue_erase(dqueue);
}

XTEST_CASE(test_dqueue_not_empty_and_is_empty) {
    cdqueue* dqueue = tscl_dqueue_create(INTEGER_TYPE);

    // Check initially not empty
    TEST_ASSERT_FALSE(tscl_dqueue_not_empty(dqueue));
    TEST_ASSERT_TRUE(tscl_dqueue_is_empty(dqueue));

    // Insert an element
    ctofu element = { INTEGER_TYPE, { .integer_type = 42 } };
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_dqueue_insert(dqueue, element));

    // Check not empty after insertion
    TEST_ASSERT_TRUE(tscl_dqueue_not_empty(dqueue));
    TEST_ASSERT_FALSE(tscl_dqueue_is_empty(dqueue));

    // Remove the element
    ctofu removedElement;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_dqueue_remove(dqueue, &removedElement));

    // Check empty after removal
    TEST_ASSERT_FALSE(tscl_dqueue_not_empty(dqueue));
    TEST_ASSERT_TRUE(tscl_dqueue_is_empty(dqueue));

    tscl_dqueue_erase(dqueue);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_dqueue_group) {
    XTEST_NOTE("Running all test cases for dqueue:");

    XTEST_RUN_UNIT(test_dqueue_create_and_erase, runner);
    XTEST_RUN_UNIT(test_dqueue_insert_and_size,  runner);
    XTEST_RUN_UNIT(test_dqueue_remove,                 runner);
    XTEST_RUN_UNIT(test_dqueue_getter_and_setter,      runner);
    XTEST_RUN_UNIT(test_dqueue_not_empty_and_is_empty, runner);
} // end of func
