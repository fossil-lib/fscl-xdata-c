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
    cdlist* dlist = tscl_dlist_create(INTEGER_TYPE);

    // Check if the doubly linked list is created with the expected values
    TEST_ASSERT_NOT_NULL_PTR(dlist);
    TEST_ASSERT_NULL_PTR(dlist->head);
    TEST_ASSERT_NULL_PTR(dlist->tail);
    TEST_ASSERT_EQUAL(INTEGER_TYPE, dlist->list_type);

    tscl_dlist_erase(dlist);

    // Check if the doubly linked list is erased
    TEST_ASSERT_NULL_PTR(dlist->head);
    TEST_ASSERT_NULL_PTR(dlist->tail);
    TEST_ASSERT_NULL_PTR(dlist);
}

XTEST_CASE(test_dlist_insert_and_size) {
    cdlist* dlist = tscl_dlist_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_dlist_insert(dlist, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_dlist_insert(dlist, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_dlist_insert(dlist, element3));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(3, tscl_dlist_size(dlist));

    tscl_dlist_erase(dlist);
}

XTEST_CASE(test_dlist_remove) {
    cdlist* dlist = tscl_dlist_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_dlist_insert(dlist, element1);
    tscl_dlist_insert(dlist, element2);
    tscl_dlist_insert(dlist, element3);

    // Remove an element
    ctofu removedElement;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_dlist_remove(dlist, &removedElement));

    // Check if the removed element is correct
    TEST_ASSERT_EQUAL_INT(42, removedElement.data.integer_type);

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, tscl_dlist_size(dlist));

    tscl_dlist_erase(dlist);
}

XTEST_CASE(test_dlist_reverse_forward) {
    cdlist* dlist = tscl_dlist_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_dlist_insert(dlist, element1);
    tscl_dlist_insert(dlist, element2);
    tscl_dlist_insert(dlist, element3);

    // Reverse the doubly linked list forward
    tscl_dlist_reverse_forward(dlist);

    // Check if the elements are in reverse order
    ctofu* retrievedElement = tscl_dlist_getter(dlist, element3);
    TEST_ASSERT_NOT_NULL_PTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(42, retrievedElement->data.integer_type);

    retrievedElement = tscl_dlist_getter(dlist, element2);
    TEST_ASSERT_NOT_NULL_PTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(10, retrievedElement->data.integer_type);

    retrievedElement = tscl_dlist_getter(dlist, element1);
    TEST_ASSERT_NOT_NULL_PTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(5, retrievedElement->data.integer_type);

    tscl_dlist_erase(dlist);
}

XTEST_CASE(test_dlist_reverse_backward) {
    cdlist* dlist = tscl_dlist_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_dlist_insert(dlist, element1);
    tscl_dlist_insert(dlist, element2);
    tscl_dlist_insert(dlist, element3);

    // Reverse the doubly linked list backward
    tscl_dlist_reverse_backward(dlist);

    // Check if the elements are in reverse order
    ctofu* retrievedElement = tscl_dlist_getter(dlist, element3);
    TEST_ASSERT_NOT_NULL_PTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(42, retrievedElement->data.integer_type);

    retrievedElement = tscl_dlist_getter(dlist, element2);
    TEST_ASSERT_NOT_NULL_PTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(10, retrievedElement->data.integer_type);

    retrievedElement = tscl_dlist_getter(dlist, element1);
    TEST_ASSERT_NOT_NULL_PTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(5, retrievedElement->data.integer_type);

    tscl_dlist_erase(dlist);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_dlist_group) {
    XTEST_NOTE("Running all test cases for dlist:");

    XTEST_RUN_UNIT(test_dlist_create_and_erase,  runner);
    XTEST_RUN_UNIT(test_dlist_insert_and_size,   runner);
    XTEST_RUN_UNIT(test_dlist_remove,            runner);
    XTEST_RUN_UNIT(test_dlist_reverse_forward,   runner);
    XTEST_RUN_UNIT(test_dlist_reverse_backward,  runner);
} // end of func
