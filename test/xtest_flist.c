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
    cflist* flist = tscl_flist_create(INTEGER_TYPE);

    // Check if the linked list is created with the expected values
    TEST_ASSERT_NOT_NULL_PTR(flist);
    TEST_ASSERT_NULL_PTR(flist->head);
    TEST_ASSERT_EQUAL(INTEGER_TYPE, flist->list_type);

    tscl_flist_erase(flist);

    // Check if the linked list is erased
    TEST_ASSERT_NULL_PTR(flist->head);
    TEST_ASSERT_NULL_PTR(flist);
}

XTEST_CASE(test_flist_insert_and_size) {
    cflist* flist = tscl_flist_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_flist_insert(flist, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_flist_insert(flist, element2));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_flist_insert(flist, element3));

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(3, tscl_flist_size(flist));

    tscl_flist_erase(flist);
}

XTEST_CASE(test_flist_remove) {
    cflist* flist = tscl_flist_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_flist_insert(flist, element1);
    tscl_flist_insert(flist, element2);
    tscl_flist_insert(flist, element3);

    // Remove an element
    ctofu removedElement;
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, tscl_flist_remove(flist, &removedElement));

    // Check if the removed element is correct
    TEST_ASSERT_EQUAL_INT(42, removedElement.data.integer_type);

    // Check if the size is correct
    TEST_ASSERT_EQUAL_UINT(2, tscl_flist_size(flist));

    tscl_flist_erase(flist);
}

XTEST_CASE(test_flist_reverse_forward) {
    cflist* flist = tscl_flist_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_flist_insert(flist, element1);
    tscl_flist_insert(flist, element2);
    tscl_flist_insert(flist, element3);

    // Reverse the linked list forward
    tscl_flist_reverse_forward(flist);

    // Check if the elements are in reverse order
    ctofu* retrievedElement = tscl_flist_getter(flist, element3);
    TEST_ASSERT_NOT_NULL_PTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(42, retrievedElement->data.integer_type);

    retrievedElement = tscl_flist_getter(flist, element2);
    TEST_ASSERT_NOT_NULL_PTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(10, retrievedElement->data.integer_type);

    retrievedElement = tscl_flist_getter(flist, element1);
    TEST_ASSERT_NOT_NULL_PTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(5, retrievedElement->data.integer_type);

    tscl_flist_erase(flist);
}

XTEST_CASE(test_flist_reverse_backward) {
    cflist* flist = tscl_flist_create(INTEGER_TYPE);

    // Insert some elements
    ctofu element1 = { INTEGER_TYPE, { .integer_type = 42 } };
    ctofu element2 = { INTEGER_TYPE, { .integer_type = 10 } };
    ctofu element3 = { INTEGER_TYPE, { .integer_type = 5 } };

    tscl_flist_insert(flist, element1);
    tscl_flist_insert(flist, element2);
    tscl_flist_insert(flist, element3);

    // Reverse the linked list backward
    tscl_flist_reverse_backward(flist);

    // Check if the elements are in reverse order
    ctofu* retrievedElement = tscl_flist_getter(flist, element3);
    TEST_ASSERT_NOT_NULL_PTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(42, retrievedElement->data.integer_type);

    retrievedElement = tscl_flist_getter(flist, element2);
    TEST_ASSERT_NOT_NULL_PTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(10, retrievedElement->data.integer_type);

    retrievedElement = tscl_flist_getter(flist, element1);
    TEST_ASSERT_NOT_NULL_PTR(retrievedElement);
    TEST_ASSERT_EQUAL_INT(5, retrievedElement->data.integer_type);

    tscl_flist_erase(flist);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_flist_group) {
    XTEST_NOTE("Running all test cases for flist:");

    XTEST_RUN_UNIT(test_flist_create_and_erase, runner);
    XTEST_RUN_UNIT(test_flist_insert_and_size,  runner);
    XTEST_RUN_UNIT(test_flist_remove,           runner);
    XTEST_RUN_UNIT(test_flist_reverse_forward,  runner);
    XTEST_RUN_UNIT(test_flist_reverse_backward, runner);
} // end of func
