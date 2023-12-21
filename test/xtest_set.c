/*  ----------------------------------------------------------------------------
    File: xtest_set.c

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
#include "trilobite/xdata/set.h" // lib source code

#include <trilobite/xtest.h>   // basic test tools
#include <trilobite/xassert.h> // extra asserts

//
// XUNIT TEST CASES
//

// Test case 1: Test cset creation and destruction
XTEST_CASE(test_set_create_and_erase) {
    // Normal Case: Creating and erasing a set
    cset* set = set_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(set);
    set_erase(set);

    // Edge Case: Creating with an invalid type
    set = set_create(INVALID_TYPE);
    TEST_ASSERT_NULL_PTR(set);
}

XTEST_CASE(test_set_insert_and_remove) {
    // Normal Case: Inserting and removing elements from the set
    cset* set = set_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(set);

    ctofu element = {.data.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, set_insert(set, element));
    TEST_ASSERT_EQUAL(1, set_size(set));

    TEST_ASSERT_EQUAL(TOFU_SUCCESS, set_remove(set, element));
    TEST_ASSERT_EQUAL(0, set_size(set));

    set_erase(set);

    // Edge Case: Removing from an empty set
    TEST_ASSERT_EQUAL(CTOFU_ERROR_NOT_FOUND, set_remove(set, element));
}

XTEST_CASE(test_set_search) {
    // Normal Case: Searching for an element in the set
    cset* set = set_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(set);

    ctofu element = {.data.integer_type = 42};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, set_insert(set, element));

    TEST_ASSERT_TRUE(set_contains(set, element));

    set_erase(set);

    // Edge Case: Searching in an empty set
    TEST_ASSERT_FALSE(set_contains(set, element));
}

XTEST_CASE(test_set_iterator) {
    // Normal Case: Iterating through the set
    cset* set = set_create(INTEGER_TYPE);
    TEST_ASSERT_NOT_NULL_PTR(set);

    ctofu element1 = {.data.integer_type = 42};
    ctofu element2 = {.data.integer_type = 24};
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, set_insert(set, element1));
    TEST_ASSERT_EQUAL(TOFU_SUCCESS, set_insert(set, element2));

    ctofu_iterator iterator = set_iterator_start(set);
    TEST_ASSERT_TRUE(set_iterator_has_next(iterator));
    TEST_ASSERT_EQUAL(element1.integer_type, iterator.current->data.integer_type);

    iterator = set_iterator_next(iterator);
    TEST_ASSERT_TRUE(set_iterator_has_next(iterator));
    TEST_ASSERT_EQUAL(element2.integer_type, iterator.current->data.integer_type);

    iterator = set_iterator_next(iterator);
    TEST_ASSERT_FALSE(set_iterator_has_next(iterator));

    set_erase(set);
}

//
// XUNIT-TEST RUNNER
//
XTEST_GROUP_DEFINE(xdata_test_set_group) {
    XTEST_NOTE("Running all test cases for set:");

    XTEST_RUN_UNIT(test_set_create_and_erase,  runner);
    XTEST_RUN_UNIT(test_set_insert_and_remove, runner);
    XTEST_RUN_UNIT(test_set_search,            runner);
    XTEST_RUN_UNIT(test_set_iterator,          runner);
} // end of func
